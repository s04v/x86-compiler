#pragma once

#include "SizeType.h"
#include "scope/Scope.h"

using namespace std;

class ExprOp;
class Expr;
class Operand;
class Id;
class Constant;
class Call;

namespace x86 {

class TypeSystem {
    // possibleCast[to][from]
    bool possibleCast[11][11] =
    {
        //  bool u8 i8 u16 i16 u32 i32 string_t, number_t number void
/*bool*/   { 1,  1, 1, 1,  1,  1,  1,  0,        1,       1,     0 },
/*u8*/     { 1,  1, 1, 1,  1,  1,  1,  0,        1,       1,     0 },
/*i8*/     { 1,  1, 1, 1,  1,  1,  1,  0,        1,       1,     0 },
/*u16*/    { 1,  1, 1, 1,  1,  1,  1,  0,        1,       1,     0 },
/*i16*/    { 1,  1, 1, 1,  1,  1,  1,  0,        1,       1,     0 },
/*u32*/    { 1,  1, 1, 1,  1,  1,  1,  0,        1,       1,     0 },
/*i8*/     { 1,  1, 1, 1,  1,  1,  1,  0,        1,       1,     0 },
/*string*/ { 0,  0, 0, 0,  0,  0,  0,  1,        0,       0,     0 },
/*number_t*/ { 1,  1, 1, 1,  1,  1,  1,  0,        1,       1,     0 },
/*number*/ { 1,  1, 1, 1,  1,  1,  1,  0,        1,       1,     0 },
/*void*/   { 0,  0, 0, 0,  0,  0,  0,  0,        0,       0,     0 },
    };

public:
    Scope* currentScope;

    TypeSystem();

    SizeType getType(Constant& constant);
    SizeType getType(Id& id);
    SizeType getType(Call& call);
    SizeType getType(Expr& expr);
    SizeType getType(ExprOp& exprOp);

    bool isCorrect(SizeType left, SizeType right);
    bool isCorrect(SizeType type, Constant& constant);
    bool isCorrect(SizeType type, Id& id);
    bool isCorrect(SizeType type, Call& call);
    bool isCorrect(SizeType type, Expr& expr);
    bool isCorrect(SizeType type, ExprOp& exprOp);

    char* getTypeName(SizeType type);
};

}
