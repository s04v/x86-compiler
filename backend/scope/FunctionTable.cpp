#include <map>
#include <vector>
#include <string>

#include "FunctionTable.h"
#include "../SizeType.h"
#include "../../utils/error.h"

using namespace std;

namespace x86 {

FunctionTable::FunctionTable() {}

bool FunctionTable::exists(string name)
{
    if(functions.find(name) == functions.end() )
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
    if(!exists(name))
        errorReport("Function is undefined");
    return functions[name];
}

}
