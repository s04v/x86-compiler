#pragma once

enum OpType{
    NONE,
    CONSTANT_T,
    ID_T,
    CALL_T,
    ARRAY_T,
    MEMBER_t
};

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


class Operand {
public:
    OpType opType;
    Prefix prefix;
    Postfix postfix;
    
    virtual ~Operand() = default;
};