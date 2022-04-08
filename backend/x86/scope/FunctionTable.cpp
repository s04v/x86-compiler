#include "FunctionTable.h"

#include <map>
#include <pair>
#include <vector>
#include <string>

#include "../SizeType.h"

using namespace std;

namespace x86 {
FunctionTable::FunctionTable() {}

bool FunctionTable::exists(string name)
{
    if(table.find(name) == table.end() )
        return 0;
    return 1;
}

void FunctionTable::addFunc(string name, int argsCount, vector<SizeType> argsTypes, SizeType returnType)
{
    Function function;
    function.argsCount = argsCount;
    function.argsTypes = argsTypes;
    function.returnType = returnType;

    functions.insert(pair<string, Function>(name, function));
}

Function FunctionTable::get(string name)
{

}

}
