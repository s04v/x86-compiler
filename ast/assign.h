#pragma once 

#include <string>
#include "exprOp.h"
#include "stmt.h"
#include "operand.h" 

using namespace std;

struct AssignOperation_t {
    enum Type {
        ASSIGN,
        MUL_ASSIGN,
        DIV_ASSIGN,
        MOD_ASSIGN,
        ADD_ASSIGN,
        SUB_ASSIGN,
        AND_ASSIGN,
        OR_ASSIGN
    };
};

typedef AssignOperation_t::Type AssignOperation;

class Assign : public Stmt{
public:
    AssignOperation type;
    Operand* left;
    ExprOp* right;

    Assign(AssignOperation t, Operand* l, ExprOp* r) : type(t), left(l),right(r) {};
};