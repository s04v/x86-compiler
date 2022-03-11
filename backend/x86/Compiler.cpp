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
        errorReport("Variable is not defined!");

    Symbol sym = scope.table.get(id.name);
    AsmValue* mem = new AsmValue(AsmOp::MEMORY);
    mem->index = x86::EBP;
    mem->offset = sym.offset;
    mem->memSize= sym.sizeType;

    AsmValue* r = new AsmValue(AsmOp::REGISTER);
    r->index = reg.alloc32();
    r->val = reg.getName(r->index);
    code += emit.mov(r, mem);

    if(id.postfix == Postfix::INC) {
        AsmValue* constant = new AsmValue(AsmOp::CONSTANT);
        constant->imm = 1;
        code += emit.add(r,constant);
    }

    delete mem;
    return r;
}

AsmValue* Compiler::gen(Call& call)
{
    AsmValue* val;

    reverse(call.args->begin(), call.args->end());
    for(auto item : *(call.args))
    {
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
    }

    // TODO: check if function exists
    code += "call " + call.name + "\n";

    // clean up stack
//    string argCount = to_string(call.args->size() * 4);
//    code += "add esp," + argCount + "\n";
    AsmValue* edx = new AsmValue(AsmOp::REGISTER);
    edx->index = 12;

    return edx;
}

AsmValue* Compiler::gen(Expr &expr)
{
    AsmValue* op1, *op2;

    AsmValue* v1 = expr.left->gen(*this);
    //std::cout << v1->type << std::endl;
    if(v1->type == AsmOp::CONSTANT || v1->type == AsmOp::MEMORY)
        if(!isForCondition) // TODO: fix
            op1 = loadOp(v1);
         else
            op1= v1;
    else
        op1 = v1;

    AsmValue* v2 = expr.right->gen(*this);
    op2 = v2;

    switch (expr.exprType) {
    case ExprType::ADD:
        code += emit.add(op1, op2);
        break;
    case ExprType::SUB:
        code += emit.sub(op1, op2);
        break;
    case ExprType::MUL:
        // TODO:
        //code += emit.imul(op1, op2);
        break;
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
            code += emit.jne(op1); break;
        case ExprType::NEQ:
            code += emit.je(op1); break;
        case ExprType::LT:
            if(isForCondition) { code += emit.jl(op1); break; }
            code += emit.jge(op1); break;
        case ExprType::LTEQ:
            if(isForCondition) { code += emit.jle(op1); break; }
            code += emit.jg(op1); break;
        case ExprType::GT:
            code += emit.jle(op1); break;
        case ExprType::GTEQ:
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
    {
        cout << "var exists" << endl;
        exit(-1);
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
    scope.init();
    code += func.name + ":\n";
    code += emit.funcStart();
    code += "sub esp, 16\n"; // TODO: fix this

    for(auto& arg : *(func.args)) {
        scope.table.addVar(arg->name, arg->type,'+');
    }

    for(auto& stmts : *(func.stmts)) {
        stmts->gen(*this);
    }

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
    asmVal->imm = 1;
    asmVal->type = AsmOp::CONSTANT;
    code += emit.add(init, asmVal);

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

    // add property label
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

void Compiler::start(vector<Stmt*> v){
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
