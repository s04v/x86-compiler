#pragma once 

#include <string>
#include <vector>
#include "Stmt.h"
#include "VarDef.h"
#include "FuncArg.h"


using namespace std;

class FuncDef : public Stmt {
public:
    string name;
    VarType returnType;
    vector<FuncArg*>* args;
    vector<Stmt*>* stmts;

    FuncDef(string n, VarType r, vector<FuncArg*>* a, vector<Stmt*>* s) : name(n), returnType(r), args(a), stmts(s) {}
};