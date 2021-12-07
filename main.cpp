#include <iostream>
#include <vector>

#include "frontend/parser.tab.h"
#include "frontend/Ast.h"

#include "backend/x86/Emitter.h"
#include "backend/x86/Reg.h"
#include "backend/x86/Compiler.h"
#include "backend/x86/scope/Scope.h"
#include "utils/int2str.h"


using namespace std;

extern FILE* yyin;
extern vector<Stmt*>* root;

int main(int argc,char* argv[])
{
   
    yyin = fopen(argv[1], "r");
    if( !yyin ) {
        std::cout << "File not found" << std::endl;
        exit(1);
    }

    yyparse();

    x86::Compiler compiler;

    compiler.start(*root);
    compiler.createASM();
    cout << compiler.code << endl;


    return 0;
}
