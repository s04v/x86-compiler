#include <iostream>
#include "frontend/parser.tab.h"


using namespace std;

extern FILE* yyin;
int main(int argc,char* argv[])
{
   
    yyin = fopen(argv[1], "r");
    if( !yyin ) {
        std::cout << "File not found" << std::endl;
        exit(1);
    }

    yyparse();
    return 1;
}
