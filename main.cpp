#include <iostream>
#include "frontend/parser.tab.h"
#include "ast/operand.h"
#include "ast/constant.h"

extern FILE* yyin;
int main(int argc,char* argv[])
{
   
    yyin = fopen(argv[1], "r");
    if( !yyin ) {
        std::cout << "File not found" << std::endl;
        exit(1);
    }

    Operand* op = new Constant(ConstType::Number, "10");
    Constant* c = dynamic_cast<Constant*>(op);
    c->toString();

    //return yyparse();
    return 1;
}
