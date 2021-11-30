#pragma once 
#include <map>
#include <string>
#include "Symbol.h"
#include "../../../ast/SizeType.h"

using namespace std;
namespace x86 {

class SymbolTable {
    map<string, Symbol> table;
    map<int,int> test;
public:
    SymbolTable();

    void addVar(string name, SizeType size);
    Symbol get(string name);
    bool exists(string name);
};
}
