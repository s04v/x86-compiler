#pragma once 

#include <vector>
#include "Stmt.h"
#include "ExprOp.h"

using namespace std;

class If : public Stmt {
public:
    ExprOp* condition;
    vector<Stmt*>* stmts;
    
    If(ExprOp* c, vector<Stmt*>* s ) : condition(c), stmts(s) {};
};