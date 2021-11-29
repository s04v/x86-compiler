#include "compiler.h"
#include "../../ast/expr.h"
#include "../../ast/constant.h"
#include "../../ast/operand.h"
#include "../../ast/exprOp.h"

#include "../../utils/int2str.h"
#include <string>

using namespace std;

namespace x86 {

#define cast(type, var) \
    dynamic_cast<type>(var)

int Compiler::genExpr(Expr *expr)
{
    int l, r;

    if(expr->left->type == ExprOpType::OPERAND)
    {
        l = loadOp(cast(Operand*,expr->left));
    } else 
    {
        l = genExpr(cast(Expr*, expr->left));
    }

    if(expr->right->type == ExprOpType::OPERAND)
    {
        r = loadOp(dynamic_cast<Operand*>(expr->right));
    } else 
    {
        r = genExpr(dynamic_cast<Expr*>(expr->left));
    }

    switch (expr->exprType)
    {
    case ExprType::ADD:
        code += emit.add_reg_reg(l,r);
        break;
    default:
        break;
    }

    reg.free(r);
    return l;
}

int Compiler::genOp(Operand* op)
{
    int r = reg.alloc32();

    if(op->opType == OpType::CONSTANT)
    {
        Constant* imm = dynamic_cast<Constant*>(op);
        code += emit.mov_reg_imm(r, stoi(imm->val));
        
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
            code += emit.mov_reg_imm(r, stoi(c->val));  
            return r;
        case OpType::ID:
            break;
        // case OpType::CALL;
    }
}


}