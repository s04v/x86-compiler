#pragma once 

#include <vector>
#include <string>
#include "operand.h"
#include "exprOp.h"
#include "id.h"

using namespace std;

class Call : public Operand {
public:
    Operand* name; // ID
    vector<ExprOp*>* args;

    Call(Operand* n, vector<ExprOp*>* a) : name(n), args(a) {};
};