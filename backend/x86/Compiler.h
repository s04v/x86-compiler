#pragma once 
#ifndef _COMPILER_
#define _COMPILER_

#include <iostream>
#include <string>
#include <vector>
#include "Emitter.h"
#include "Reg.h"
#include "AsmValue.h"
#include "Label.h"
#include "scope/Scope.h"
#include "scope/SymbolTable.h"
#include "scope/Scope.h"

using namespace std;

class Stmt;
class FuncDef;
class VarDef;
class ExprOp;
class Expr;
class Operand;
class Id;
class Constant;
class Call;
class If;


namespace x86 {

class Compiler {
private:
    Emitter emit;
    Register reg;
    Scope scope;
    Label label;

    //TODO:
    int resultOfExpr;


    //section .data
public:
    string data = "";
    string code = "";

    Compiler();

    AsmValue* gen(Constant& constant);
    AsmValue* gen(Id& id);
    AsmValue* gen(Call& call);
    AsmValue* gen(Expr& expr);
    AsmValue* gen(VarDef& var);
    AsmValue* gen(FuncDef& func);
    AsmValue* gen(If& ifStmt);

    void start(vector<Stmt*> v);

    AsmValue* loadOp(AsmValue* op);

    string saveString(string src);
    void createASM();


    void printData() { cout << data << endl; }


};
}
#endif
