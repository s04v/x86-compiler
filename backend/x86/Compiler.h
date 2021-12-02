#pragma once 
#ifndef _COMPILER_
#define _COMPILER_

#include <string>
//#include "../../frontend/Ast.h"
#include "Emitter.h"
#include "Reg.h"
#include "AsmValue.h"

using namespace std;

class ExprOp;
class Expr;
class Operand;
class Constant;

namespace x86 {

class Compiler {
private:
    Emitter emit;
    Register reg;
    int resultOfExpr;
public:
    string code = "";

    AsmValue* gen(Constant& constant);
    AsmValue* gen(Expr& expr);
    int genOp(Operand* op);
    int loadOp(Operand* op);


};
}
#endif
