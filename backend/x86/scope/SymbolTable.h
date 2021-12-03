#pragma once 
#include <map>
#include <string>
#include "Symbol.h"


using namespace std;
namespace x86 {

class SymbolTable {
    map<string, Symbol> table;
    map<int,int> test;
public:
    SymbolTable();

    bool exists(string name);
    void addVar(string name, int size);
    Symbol get(string name);
};
}
