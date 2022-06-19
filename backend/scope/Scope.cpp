#include <stack>
#include "Scope.h"
#include "Symbol.h"
#include "SymbolTable.h"


using namespace std;

namespace Backend {

Scope::Scope() {}

void Scope::init()
{
    stackTables.push(table);

    SymbolTable newTable;
    table = newTable;
}

void Scope::extend()
{
    stackTables.push(table);
}

void Scope::pop()
{
    table = stackTables.top();
    stackTables.pop();
}

}
