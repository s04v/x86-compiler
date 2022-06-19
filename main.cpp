#include <iostream>
#include <vector>

#include "frontend/parser.tab.h"
#include "frontend/Ast.h"

#include "backend/x86/Emitter.h"
#include "backend/x86/Reg.h"
#include "backend/x86/Compiler.h"
#include "backend/x86/scope/Scope.h"
#include "utils/int2str.h"
#include "utils/error.h"

#include "backend/x86/Label.h"

#include "backend/x86/SizeType.h"

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
//    symbolNotDefined(1, "foo");

    yyparse();

    x86::Compiler compiler;
    compiler.start(*root);
    compiler.createASM();

    system("nasm -felf32 output.txt");
    system("ld -m elf_i386 output.o");
    system("./a.out");

    return 0;
}
