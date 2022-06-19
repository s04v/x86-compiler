#pragma once

#include <map>
#include <vector>
#include <string>

#include "../SizeType.h"

using namespace std;

namespace x86 {

class Function {
public:
    int argsCount;
    vector<SizeType> argsTypes;
    SizeType returnType;

    Function(): argsCount(0) {}
};

class FunctionTable {
    map<string, Function> functions;
public:
    FunctionTable();
    bool exists(string name);
    void addFunc(string name, int argsCount, vector<SizeType> argsTypes, SizeType returnType);
    Function get(string name);

};

}
