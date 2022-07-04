#pragma once 
#include <map>
#include <string>
#include "Symbol.h"


using namespace std;
namespace Backend {

class SymbolTable {
    map<string, Symbol> table;

public:
    int lastOffset;
    int plusOffset = 0;
    int minusOffset = 0;

    SymbolTable();
    bool exists(string name);
    void addVar(string name, SizeType size, char sign);
    Symbol get(string name);
};

}
