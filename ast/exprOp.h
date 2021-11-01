#pragma once 

struct ExprOp_t {
    enum Type {
        OPERAND,
        EXPR
    };
};

typedef ExprOp_t::Type ExprOpType;

class ExprOp {
public:
    ExprOpType type;
    ExprOp() {}
    
    virtual ~ExprOp() = default;
};