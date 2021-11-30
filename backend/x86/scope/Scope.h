#pragma once
#include <stack>
#include "Symbol.h"
#include "SymbolTable.h"


using namespace std;

namespace x86 {

class Scope {
    stack<SymbolTable> stackTables;
public:
    SymbolTable table;
    Scope();

    void init();
    void extend();
    void pop();

};
}
