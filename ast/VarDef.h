#pragma once 

#include <string>
#include "ExprOp.h"
#include "Operand.h" 

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
        VOID
    };
};

typedef VarDef_t::Type VarType;

class VarDef : public Stmt {
public:
    VarType varType;
    string left;
    ExprOp* right;

    VarDef();
    VarDef(VarType t, string l, ExprOp* r) : varType(t), left(l), right(r) {} ;
};