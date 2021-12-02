#pragma once 
#include <map>
#include <string>
#include "Symbol.h"
#include "../../../frontend/Ast.h"

using namespace std;
namespace x86 {

class SymbolTable {
    map<string, Symbol> table;
    map<int,int> test;
public:
    SymbolTable();

    bool exists(string name);
    void addVar(string name, SizeType size);
    Symbol get(string name);
};
}
