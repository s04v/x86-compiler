#pragma once 
#ifndef _COMPILER_
#define _COMPILER_

#include <string>
#include <vector>
#include "Emitter.h"
#include "Reg.h"
#include "AsmValue.h"
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

namespace x86 {

class Compiler {
private:
    Emitter emit;
    Register reg;
    Scope scope;
    int resultOfExpr;
public:
    string code = "";

    Compiler();
    AsmValue* gen(Constant& constant);
    AsmValue* gen(Id& id);
    AsmValue* gen(Expr& expr);
    AsmValue* gen(VarDef& var);
    AsmValue* gen(FuncDef& func);

    void start(vector<Stmt*> v);
    int genOp(Operand* op);
    AsmValue* loadOp(AsmValue* op);


};
}
#endif
