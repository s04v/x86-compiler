#include <iostream>
#include <string>
#include "Compiler.h"
#include "../../frontend/Ast.h"
#include "../../utils/int2str.h"
#include "AsmValue.h"

using namespace std;

namespace x86 {

#define cast(type, var) \
    dynamic_cast<type>(var)

AsmValue* Compiler::gen(Constant &constant)
{
    cout << "constant = " << constant.val << endl;
    AsmConstant* as = new AsmConstant(constant.val);

    return as;
}



AsmValue* Compiler::gen(Expr &expr)
{
    AsmRegister* r1, *r2;
    AsmValue* v1 = expr.left->accept(*this);
//    auto test = cast(AsmConstant*, v1);

    switch (v1->type) {
    case AsmOp::CONSTANT:
    {
        r1 = new AsmRegister();
        r1->index = reg.alloc32();
        r1->name = reg.getName(r1->index);
        AsmConstant* c = cast(AsmConstant*,v1);
        code += emit.mov(*r1, *c);
        delete c;
        break;
    }
    case AsmOp::MEMORY:
    {
        r1 = new AsmRegister();
        r1->index = reg.alloc32();
        r1->name = reg.getName(r1->index);
        AsmMemory* m = cast(AsmMemory*, v1);
        code += emit.mov(*r1,*m);
        delete m;
        break;
    }
    case AsmOp::REGISTER:
    {
        r1 = cast(AsmRegister*, v1);
        break;
    }
    default:
        break;
    }

    AsmValue* v2 = expr.right->accept(*this);
    switch (v2->type) {
    case AsmOp::CONSTANT:
    {
        r2 = new AsmRegister();
        r2->index = reg.alloc32();
        r2->name = reg.getName(r2->index);
        AsmConstant* c = cast(AsmConstant*,v2);
        code += emit.mov(*r2, *c);
        delete c;
        break;
    }
    case AsmOp::MEMORY:
    {
        r2 = new AsmRegister();
        r2->index = reg.alloc32();
        r2->name = reg.getName(r2->index);
        AsmMemory* m = cast(AsmMemory*, v2);
        code += emit.mov(*r2,*m);
        delete m;
        break;
    }
    case AsmOp::REGISTER:
    {
        r2 = cast(AsmRegister*, v2);
        break;
    }
    default:
        break;
    }

    switch (expr.exprType) {
    case ExprType::ADD:
        code += emit.add(*r1,*r2);
        break;
    case ExprType::SUB:
        code += emit.sub(*r1,*r2);
        break;
    case ExprType::MUL:
        code += emit.imul(*r1,*r2);
        break;
    default:
        break;
    }

    reg.free(r2->index);
    return r1;
}

int Compiler::genOp(Operand* op)
{
    int r = reg.alloc32();

    if(op->opType == OpType::CONSTANT)
    {
        Constant* imm = dynamic_cast<Constant*>(op);
//        code += emit.mov_reg_imm(r, stoi(imm->val));
        
        delete imm;
        return r;
    }
}

int Compiler::loadOp(Operand* op)
{
    int r;
    Constant* c;
    switch(op->opType)
    {
        case OpType::CONSTANT:
            //TODO: Check type size
            c = cast(Constant*, op);
            r = reg.alloc32();
//            code += emit.mov_reg_imm(r, stoi(c->val));
            return r;
        case OpType::ID:
            break;
        // case OpType::CALL;
    }
}


}
