#include <iostream>
#include <string>
#include <vector>
#include "Compiler.h"
#include "../../frontend/Ast.h"
#include "../../utils/int2str.h"
#include "AsmValue.h"

using namespace std;

namespace x86 {

#define cast(type, var) \
    dynamic_cast<type>(var)


Compiler::Compiler()
{
    scope.init();
}

AsmValue* Compiler::gen(Constant &constant)
{
    AsmValue* val = new AsmValue(AsmOp::CONSTANT);
    val->imm = stoi(constant.val);

    return val;
}

AsmValue* Compiler::gen(Expr &expr)
{
    AsmValue* op1, *op2;

    AsmValue* v1 = expr.left->gen(*this);
    op1 = loadOp(v1);

    AsmValue* v2 = expr.right->gen(*this);
    op2 = v2;

    switch (expr.exprType) {
    case ExprType::ADD:
        code += emit.add(op1, op2);
        break;
    default:
        break;
    }

    //TODO:: reg.free(r2->index);
    return op1;
}

AsmValue* Compiler::gen(VarDef& var)
{
    if(scope.table.exists(var.left))
    {
        cout << "var exists" << endl;
        exit(-1);
    }

    scope.table.addVar(var.left, SizeType::U32);

    // TODO:
    AsmValue* mem = new AsmValue(AsmOp::MEMORY);
    mem->index = x86::EBP;

    AsmValue* val =  var.right->gen(*this);
    code += emit.mov(mem,val);
}

AsmValue* Compiler::gen(FuncDef& func)
{
    cout << "enter function" << endl;
    for(auto& stmts : *(func.stmts)) {
        stmts->gen(*this);
    }
}

void Compiler::start(vector<Stmt*> v){
    for(auto stmt : v)
    {
        stmt->gen(*this);
    }
}


AsmValue* Compiler::loadOp(AsmValue* val)
{
    switch(val->type)
    {
        case AsmOp::CONSTANT:
            //TODO: Check type size
            AsmValue* r = new AsmValue(AsmOp::REGISTER);
            r->index = reg.alloc32();
            r->name = reg.getName(r->index);
            code += emit.mov(r, val);
            return r;
        // case OpType::CALL;
    }
}


}
