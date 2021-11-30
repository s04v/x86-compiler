#pragma once 

#include <string>
#include "ExprOp.h"
#include "Operand.h" 
#include "SizeType.h"

using namespace std;


class VarDef : public Stmt {
public:
    SizeType sizeType;
    string left;
    ExprOp* right;

    VarDef();
    VarDef(SizeType t, string l, ExprOp* r) : sizeType(t), left(l), right(r) {} ;
};