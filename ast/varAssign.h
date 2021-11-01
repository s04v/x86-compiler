#pragma once 

#include <string>
#include "exprOp.h"
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
    }
};

typedef AssignOperation_t::Type AssignOperation;

class VarAssign {
public:
    AssignOperation type;
    Operand* left;
    ExprOp* value;

    VarAssign(AssignOperation t, Operand* l, ExprOp* v);
}