#pragma once 

#include <string.h>
#include "operand.h"

using namespace std;

enum ConstType {
    NUMBER_C,
    STRINR_C,
    CHAR_C
};

class Constant : public Operand {
public:
    ConstType type;
    std::string val;

    Constant();
    Constant(ConstType t, std::string v);
    void toString();
};