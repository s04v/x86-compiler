#pragma once 

#include <string>
#include "../../ast/expr.h"
#include "../../ast/exprOp.h"
#include "../../ast/operand.h"
#include "emitter.h"
#include "reg.h"

using namespace std;

namespace x86 {

class Compiler {
private:
    Emitter emit;
    Register reg;

    int resultOfExpr;
public:
    string code = "";

    int genExpr(Expr* expr);
    int genOp(Operand* op);
    int loadOp(Operand* op);


};
}