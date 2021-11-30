#pragma once

#include <string>
#include "VarDef.h"
#include "SizeType.h"

using namespace std;


class FuncArg {
public:
    string name;
    SizeType type;

    FuncArg(string n, SizeType t) : name(n), type(t) {};
};