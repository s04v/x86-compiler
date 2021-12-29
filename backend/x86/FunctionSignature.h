#pragma once

#include <string>

#include "SizeType.h"


using namespace std;

class Call;

namespace x86 {

class FunctionSignature
{
    string sign;
public:
    FunctionSignature(string name) : sign(name) { }
    FunctionSignature(Call& call);

    void setArgType(SizeType type);
    void setReturnType(SizeType type);
    string get();

    bool equals(FunctionSignature func);
};

}

