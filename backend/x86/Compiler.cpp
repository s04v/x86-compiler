#include "../../frontend/Ast.h"
#include "../../utils/error.h"
#include "../../utils/int2str.h"
#include "AsmValue.h"
#include "Compiler.h"
#include "SizeType.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace x86 {

#define cast(type, var) \
    dynamic_cast<type>(var)


Compiler::Compiler()
{
    scope.init();
    initBuildInFunctions();
    typeSystem.currentScope = &scope;
    data = "section .data\n";
}

AsmValue* Compiler::gen(Constant &constant)
{
    if(constant.type == ConstType::NUMBER)
    {
        AsmValue* val = new AsmValue(AsmOp::CONSTANT);
        val->imm = stoi(constant.val);
        return val;
    } else if(constant.type == ConstType::STRING)
    {
        AsmValue* val = new AsmValue(AsmOp::STRING);
        val->val = saveString(constant.val);
        return val;
    }
}

AsmValue* Compiler::gen(Id& id)
{
    if(!scope.table.exists(id.name))
        symbolNotDefined(id.line, id.name);

    Symbol sym = scope.table.get(id.name);
    AsmValue* mem = new AsmValue(AsmOp::MEMORY);
    mem->index = x86::EBP;
    mem->offset = sym.offset;
    mem->memSize= sym.sizeType;

    if(id.prefix != 0)
    {
        AsmValue* constant = new AsmValue(AsmOp::CONSTANT);
        constant->imm = 1;

        if(id.prefix == Prefix::INC) {
            code += emit.add(mem,constant);
        } else if(id.prefix  == Prefix::DEC){
            code += emit.sub(mem,constant);
        }
    }

    AsmValue* r = new AsmValue(AsmOp::REGISTER);
    r->index = reg.alloc32();
    r->val = reg.getName(r->index);
    code += emit.mov(r, mem);

    if(id.postfix != 0)
    {
        AsmValue* constant = new AsmValue(AsmOp::CONSTANT);
        constant->imm = 1;

        if(id.postfix == Postfix::INC) {
            code += emit.add(mem,constant);
        } else {
            code += emit.sub(mem,constant);
        }
    }

    delete mem;
    return r;
}

AsmValue* Compiler::gen(Call& call)
{
    AsmValue* val;

    Function function = scope.funcTable.get(call.name);

    unsigned int callArgsCount = 0;
    int argIndex = 0;
    reverse(call.args->begin(), call.args->end());
    for(auto item : *(call.args))
    {
        SizeType passedType = item->getType(typeSystem);
        SizeType definedType = function.argsTypes[argIndex++];
        if(!typeSystem.isCorrect(definedType, passedType))
        {
            invalidArgType(call.line, typeSystem.getTypeName(definedType));
        }

        AsmValue* arg = item->gen(*this);

        switch(arg->type)
        {
            case AsmOp::CONSTANT:
                code += emit.push(arg);
                break;
            case AsmOp::STRING:
                code += emit.push(arg);
                break;
            case AsmOp::MEMORY:
                code += emit.push(arg);
                break;
            case AsmOp::REGISTER:
                code += emit.push(arg);
                reg.free(arg->index);
                break;
            default:
                break;
        }

        callArgsCount++;
    }

    if(callArgsCount < function.argsCount)
    {
        tooFewArguments(call.line, call.name.c_str());
    }
    else if(callArgsCount > function.argsCount)
    {
        tooManyArguments(call.line, call.name.c_str());
    }
    code += "call " + call.name + "\n";

    AsmValue* edx = new AsmValue(AsmOp::REGISTER);
    edx->index = 12;

    return edx;
}

AsmValue* Compiler::gen(Expr &expr)
{
    AsmValue* op1, *op2;

    AsmValue* v1 = expr.left->gen(*this);
    if(v1->type == AsmOp::CONSTANT || v1->type == AsmOp::MEMORY)
        if(!isForCondition) // TODO: fix
            op1 = loadOp(v1);
         else
            op1= v1;
    else
        op1 = v1;

    AsmValue* v2 = expr.right->gen(*this);
    op2 = v2;

    // check types
    SizeType exprType = typeSystem.getType(expr);

    switch (expr.exprType) {
    case ExprType::ADD:
        code += emit.add(op1, op2);
        break;
    case ExprType::SUB:
        code += emit.sub(op1, op2);
        break;
    case ExprType::MUL: {
        if(op1->type == AsmOp::REGISTER && op2->type == AsmOp::REGISTER )
        {
            code += emit.imul(op1,op2);
            break;
        }

        AsmValue* result = new AsmValue(AsmOp::REGISTER);
        result->index = reg.alloc32();

        code += emit.imul(result, op1, op2);

        reg.free(op1->index);
        op1 = result;

        break;
    }
    case ExprType::DIV:
    case ExprType::MOD:
        // TODO:
        //        code += emit.div(op1, op2);
        break;
    case ExprType::EQ:
    case ExprType::NEQ:
    case ExprType::LT:
    case ExprType::LTEQ:
    case ExprType::GT:
    case ExprType::GTEQ: {
        code += emit.cmp(op1, op2);

        string labelName = label.create();
        op1->val = labelName;
        op1->type = AsmOp::STRING; // TODO: change type

        switch(expr.exprType)
        {
        case ExprType::EQ:
            if(isForCondition) { code += emit.je(op1); break; }
            code += emit.jne(op1); break;
        case ExprType::NEQ:
            if(isForCondition) { code += emit.jne(op1); break; }
            code += emit.je(op1); break;
        case ExprType::LT:
            if(isForCondition) { code += emit.jl(op1); break; }
            code += emit.jge(op1); break;
        case ExprType::LTEQ:
            if(isForCondition) { code += emit.jle(op1); break; }
            code += emit.jg(op1); break;
        case ExprType::GT:
            if(isForCondition) { code += emit.jg(op1); break; }
            code += emit.jle(op1); break;
        case ExprType::GTEQ:
            if(isForCondition) { code += emit.jge(op1); break; }
            code += emit.jl(op1); break;
        }

        break;
    }
    default:
        break;
    }

    if(v2->type == AsmOp::REGISTER)
        reg.free(v2->index);
    return op1;
}

AsmValue* Compiler::gen(VarDef& var)
{
    if(scope.table.exists(var.left))
        varAlreadyDeclared(var.line, var.left);

    SizeType exprType = var.right->getType(typeSystem);
    if(!typeSystem.isCorrect(var.sizeType, exprType))
    {
        invalidConversionFrom(var.line, typeSystem.getTypeName(exprType), typeSystem.getTypeName(var.sizeType));
    }


    scope.table.addVar(var.left, var.sizeType, '-');
    Symbol sym = scope.table.get(var.left);

    AsmValue* mem = new AsmValue(AsmOp::MEMORY);
    mem->index = x86::EBP;
    mem->offset = sym.offset;
    mem->memSize = var.sizeType;

    AsmValue* value = var.right->gen(*this);

    code += emit.mov(mem, value);

    if(value->type == AsmOp::REGISTER)
        reg.free(value->index);

    return mem;
}

AsmValue* Compiler::gen(Return& ret) {

    AsmValue* r = ret.value->gen(*this);
    AsmValue* edx = new AsmValue(AsmOp::REGISTER);
    edx->index = 12;
    code += emit.mov(edx, r);

    return edx;
}

AsmValue* Compiler::gen(FuncDef& func)
{
    if(scope.funcTable.exists(func.name))
        funcAlreadyDeclared(func.line, func.name.c_str());

    scope.init();
    code += func.name + ":\n";
    code += emit.funcStart();
    code += "sub esp, 16\n"; // TODO: fix this

    unsigned int argsCount = 0;
    vector<SizeType> argsType;
    for(auto& arg : *(func.args)) {
        argsCount++;
        argsType.push_back(arg->type);
        scope.table.addVar(arg->name, arg->type,'+');
    }

    for(auto& stmts : *(func.stmts)) {
        stmts->gen(*this);
    }

    Function function;
    scope.funcTable.addFunc(func.name, argsCount, argsType, func.returnType);

    code += emit.funcEnd();
    scope.pop();
}

AsmValue* Compiler::gen(For& forStmt)
{
    AsmValue* init = forStmt.init->gen(*this);
    AsmValue* asmVal = new AsmValue(AsmOp::STRING);

    string l1 = label.create();
    string l2 = label.create();

    asmVal->val = l1;
    code += emit.jmp(asmVal);
    code += l2 + ":\n";

    for(auto& stmts : *(forStmt.stmts)) {
        stmts->gen(*this);
    }

    // TODO: fix
    forStmt.expr->gen(*this);
//    asmVal->imm = 1;
//    asmVal->type = AsmOp::CONSTANT;
//    code += emit.add(init, asmVal);

    asmVal->type = AsmOp::STRING;
    asmVal->val = l1;
    code += l1 + ":\n";

    isForCondition = true;
    forStmt.condition->gen(*this);
    isForCondition = false;

    // skip label
    code.pop_back();
    code.pop_back();
    code.pop_back();
    code.pop_back();

    // add label
    code += l2 + "\n";

}

AsmValue* Compiler::gen(If& ifStmt)
{
    AsmValue* label = ifStmt.condition->gen(*this);

    for(auto& stmts : *(ifStmt.stmts)) {
        stmts->gen(*this);
    }

    code += label->val + ":\n";
}

void Compiler::initBuildInFunctions()
{
    vector<SizeType> argsType;

    //sys_srite
    argsType.push_back(SizeType::STRING_T);
    argsType.push_back(SizeType::U32);
    scope.funcTable.addFunc("sys_write", 2, argsType, SizeType::VOID);

}


void Compiler::start(vector<Stmt*> v)
{
    for(auto stmt : v)
    {
        stmt->gen(*this);
    }
}

AsmValue* Compiler::loadOp(AsmValue* val)
{
    AsmValue* r = new AsmValue(AsmOp::REGISTER);
    r->index = reg.alloc32();
    r->val = reg.getName(r->index);
    code += emit.mov(r, val);
    return r;
}


void Compiler::createASM()
{
    ofstream file;
    ifstream rt0;
    string buf;
    rt0.open("internal/rt0.s");
    file.open ("output.txt");
    while (getline (rt0, buf)) {
      file << buf << "\n";
    }
    rt0.close();
    file << code;
    file << "\n";
    file << data;
    file.close();
}

string Compiler::saveString(string src)
{
    string l = label.createString();
    //data += "\t";
    data += l;
    data += " db ";
    data += "\"" + src + "\"\n";
    return l;
}

}
