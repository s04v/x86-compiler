#pragma once 

#include <vector>
#include <string>
#include "Operand.h"
#include "ExprOp.h"
#include "Id.h"

using namespace std;

class Call : public Operand {
public:
    Operand* name; // ID
    vector<ExprOp*>* args;

    Call(Operand* n, vector<ExprOp*>* a) : name(n), args(a) {};
};