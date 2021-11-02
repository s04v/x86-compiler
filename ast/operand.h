#pragma once

#include "exprOp.h"
#include <string>
#include <iostream>
using namespace std;

struct OpType_t {
    enum Type {
        NONE,
        CONSTANT,
        ID,
        CALL,
        ARRAY,
        MEMBER_t
    };
};

typedef OpType_t::Type OpType;

struct Prefix_mod {
    enum Type {
        NONE,
        MUL,
        ADD,
        SUB,
        NOT,
        AND,
        INC,
        DEC
    };
};

typedef Prefix_mod::Type Prefix;

struct Postfix_mod {
    enum Type {
        NONE,
        INC,
        DEC
    };
};

typedef Postfix_mod::Type Postfix;


class Operand : public ExprOp{
public:
    OpType opType;
    Prefix prefix;
    Postfix postfix;

    Operand () {}


    virtual ~Operand() = default;
};