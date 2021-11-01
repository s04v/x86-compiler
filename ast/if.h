#pragma once 

#include <vector>
#include "stmt.h"
#include "expr.h"

using namespace std;

class If : public Stmt {
public:
    Expr* condition;
    vector<Stmt*> stmts;
    
}