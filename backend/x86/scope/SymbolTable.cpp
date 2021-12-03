#include <string>
#include <map>
#include "SymbolTable.h"
#include "Symbol.h"
#include "../../../utils/error.h"

using namespace std;

namespace x86 {

SymbolTable::SymbolTable() {}



bool SymbolTable::exists(string name)
{
    if(table.find(name) == table.end() )
        return 0;
    return 1;
}


Symbol SymbolTable::get(string name)
{
    if(!exists(name))
        exitError("Variable name is undefined");
    return table[name];
}

void SymbolTable::addVar(string name, int size)
{
    if(exists(name))
        exitError("Variable name is defined");
    Symbol sym(name, size, SymbolType::VAR);
//    sym.name = name;
//    sym.sizeType = size;
//    sym.type = SymbolType::VAR;

    table.insert(pair<string, Symbol>(name,sym));
}

}
