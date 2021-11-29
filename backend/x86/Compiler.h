#pragma once 

#include <string>
#include "../../ast/Expr.h"
#include "../../ast/ExprOp.h"
#include "../../ast/Operand.h"
#include "Emitter.h"
#include "Reg.h"

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