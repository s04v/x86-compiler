#pragma once 

#include <vector>
#include "stmt.h"
#include "exprOp.h"

using namespace std;

class If : public Stmt {
public:
    ExprOp* condition;
    vector<Stmt*>* stmts;
    
    If(ExprOp* c, vector<Stmt*>* s ) : condition(c), stmts(s) {};
};