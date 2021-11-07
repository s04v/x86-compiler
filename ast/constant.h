#pragma once 

#include <string.h>
#include "operand.h"

using namespace std;

struct ConstType_t {
    enum Type {
        NUMBER,
        STRING,
        CHAR
    };
};

typedef ConstType_t::Type ConstType;

class Constant : public Operand {
public:
    ConstType type;
    std::string val;

    Constant() {};
    Constant(ConstType t, std::string v) : type(t), val(v) {};
};