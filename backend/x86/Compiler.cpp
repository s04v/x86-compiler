#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

#include "Compiler.h"
#include "SizeType.h"
#include "AsmValue.h"
#include "../../frontend/Ast.h"
#include "../../utils/int2str.h"
#include "../../utils/error.h"

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

    return val;


}

AsmValue* Compiler::gen(Expr &expr)
{
    AsmValue* op1, *op2;

    AsmValue* v1 = expr.left->gen(*this);
    if(v1->type == AsmOp::CONSTANT || v1->type == AsmOp::MEMORY)
        op1 = loadOp(v1);
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
        //        code += emit.imul(op1, op2);
        break;
    case ExprType::DIV:
    case ExprType::MOD:
        // TODO:
        //        code += emit.div(op1, op2);
        break;
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

    scope.table.addVar(var.left, var.sizeType);
    Symbol sym = scope.table.get(var.left);

    AsmValue* mem = new AsmValue(AsmOp::MEMORY);
    mem->index = x86::EBP;
    mem->offset = sym.offset;
    mem->memSize = var.sizeType;

    AsmValue* value = var.right->gen(*this);

    code += emit.mov(mem, value);

    if(value->type == AsmOp::REGISTER)
        reg.free(value->index);
}

AsmValue* Compiler::gen(FuncDef& func)
{
    code += func.name + ":\n";
    code += emit.funcStart();

    for(auto& stmts : *(func.stmts)) {
        stmts->gen(*this);
    }
    code += emit.funcEnd();
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
