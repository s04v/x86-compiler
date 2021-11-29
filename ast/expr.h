#pragma once 

#include "exprOp.h"

struct Expr_t{
    enum Type {
        MUL,
        DIV,
        MOD,
        ADD,
        SUB,

        LT,
        GT,
        LTEQ,
        GTEQ,
        EQ,
        NEQ,

        AND_AND,
        OR_OR,

    };
};

typedef Expr_t::Type ExprType;


class Expr : public ExprOp {
public:
    ExprType exprType;
    ExprOp* left;
    ExprOp* right;

    Expr() {};
    Expr(ExprType t, ExprOp* l, ExprOp* r) : exprType(t), left(l), right(r) {};

    virtual ~Expr() = default;
};