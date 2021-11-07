#pragma once

#include <string>
#include "varDef.h"

using namespace std;


class FuncArg {
public:
    string name;
    VarType type;

    FuncArg(string n, VarType t) : name(n), type(t) {};
};