#pragma once 
#include <map>
#include <string>
#include "Symbol.h"


using namespace std;
namespace x86 {

class SymbolTable {
    map<string, Symbol> table;

public:
    int lastOffset;

    SymbolTable();

    bool exists(string name);
    void addVar(string name, SizeType size);
    Symbol get(string name);
};
}
