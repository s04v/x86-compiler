#include <iostream>
#include "frontend/parser.tab.h"

extern FILE* yyin;
int main(int argc,char* argv[])
{
    yyin = fopen(argv[1], "r");
    if( !yyin ) {
        std::cout << "File not found" << std::endl;
        return 1;
    }
    
    return yyparse();
}
