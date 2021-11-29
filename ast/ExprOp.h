#pragma once 

#include "Stmt.h"

struct ExprOp_t {
    enum Type {
        OPERAND,
        EXPR
    };
};

typedef ExprOp_t::Type ExprOpType;

class ExprOp : public Stmt{
public:
    ExprOpType type;

    ExprOp() {}
    
    virtual ~ExprOp() = default;
};