#include <string>
#include <map>
#include "SymbolTable.h"
#include "Symbol.h"
#include "../SizeType.h"
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
        errorReport("Variable name is undefined");
    return table[name];
}

void SymbolTable::addVar(string name, SizeType size, char sign)
{
    if(exists(name))
        errorReport("Variable name is defined");

    int useOffset;
    if(sign == '+')
        useOffset = plusOffset;
    else
        useOffset = minusOffset;

    int offset;
    switch(size) {
    case SizeType::BOOL:
    case SizeType::I8:
    case SizeType::U8:
        offset = 1;
        break;
    case SizeType::I16:
    case SizeType::U16:
        offset = 2;
        break;
    case SizeType::I32:
    case SizeType::U32:
    case SizeType::STRING_T:
        offset = 4;
        break;
    }


    if(table.size() != 0 && useOffset != 0)
    {
        if(useOffset % offset == 0 && useOffset / offset > 0)
            offset = useOffset + offset;
        else
            offset = (useOffset / offset + 2) * offset;
    }


    if(sign == '+')
        plusOffset = offset;
    else
        minusOffset = offset;

    Symbol sym(name, size, SymbolType::VAR, (sign == '+' ? offset + 4 : -offset ));
    table.insert(pair<string, Symbol>(name,sym));
}


}
