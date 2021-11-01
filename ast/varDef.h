#pragma once 

#include <string>
#include "exprOp.h"
#include "operand.h" 

using namespace std;

struct VarDef_t {
    enum Type {     
        BOOL,
        U8,
        I8,
        U16,
        I16,
        U32,
        I32,
        STRING_T,
        ID,
        VOID
    }
};

typedef VarDef_t::Type VarType;

class VarDef : public Stmt {
public:
    VarType varType;
    Operand* left;
    ExprOp* value;

    VarDef();
    VarDef(VarType t, Operand* l, ExprOp* v);
}