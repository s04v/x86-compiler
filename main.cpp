#include <iostream>
#include "frontend/parser.tab.h"

int main()
{
    return yyparse();
}
