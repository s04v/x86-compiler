#pragma once

#include <string>
#include "VarDef.h"

using namespace std;


class FuncArg {
public:
    string name;
    VarType type;

    FuncArg(string n, VarType t) : name(n), type(t) {};
};