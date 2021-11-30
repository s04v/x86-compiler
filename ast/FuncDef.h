#pragma once 

#include <string>
#include <vector>
#include "Stmt.h"
#include "VarDef.h"
#include "FuncArg.h"
#include "SizeType.h"


using namespace std;

class FuncDef : public Stmt {
public:
    string name;
    SizeType returnType;
    vector<FuncArg*>* args;
    vector<Stmt*>* stmts;

    FuncDef(string n, SizeType r, vector<FuncArg*>* a, vector<Stmt*>* s) : name(n), returnType(r), args(a), stmts(s) {}
};