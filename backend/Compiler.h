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
#include "TypeSystem.h"
#include "scope/Scope.h"
#include "scope/SymbolTable.h"
#include "scope/Scope.h"

using namespace std;

class Stmt;
class Return;
class FuncDef;
class VarDef;
class Assign;
class ExprOp;
class Expr;
class Operand;
class Id;
class Constant;
class Call;
class If;
class For;

namespace Backend {

class Compiler {
private:
    Emitter emit;
    Register regAllocator;
    Scope scope;
    Label label;
    TypeSystem typeSystem;

    string conditionalLabel;
    string preLable;

    bool isForCondition = 0;

    bool logicalOR = 0;
    bool logicalAND = 0;
public:
    string data = "";
    string code = "";

    Compiler();
    AsmValue* gen(Constant& constant);
    AsmValue* gen(Id& id);
    AsmValue* gen(Call& call);
    AsmValue* gen(Expr& expr);
    AsmValue* gen(VarDef& var);
    AsmValue* gen(Assign& var);
    AsmValue* gen(Return& ret);
    AsmValue* gen(FuncDef& func);
    AsmValue* gen(If& ifStmt);
    AsmValue* gen(For& forStmt);

    void initBuildInFunctions();

    AsmValue* loadOp(AsmValue* op);
    string saveString(string src);
    void createASM();
    void start(vector<Stmt*> v);
    void printData() { cout << data << endl; }
};
}
#endif
