#pragma once

#include <string>
#include "SizeType.h"
using namespace std;

namespace Backend {

struct AsmOpType_t {
    enum Type {
        REGISTER = 1,
        MEMORY,
        CONSTANT,
        STRING,
        LABEL
    };
};

typedef AsmOpType_t::Type AsmOp;


class AsmValue{
public:
    AsmOp type;
    int imm;
    string val;
    int index; // register index
    SizeType memSize;
    int offset = 0;

    AsmValue() {}
    AsmValue(AsmOp t) : type(t) {}
};

}




