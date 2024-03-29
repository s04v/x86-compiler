#include <iostream>
#include <vector>

#include "frontend/parser.tab.h"
#include "frontend/Ast.h"

#include "backend/Emitter.h"
#include "backend/Reg.h"
#include "backend/Compiler.h"
#include "backend/scope/Scope.h"
#include "utils/int2str.h"
#include "utils/error.h"

#include "backend/Label.h"

#include "backend/SizeType.h"

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

    Backend::Compiler compiler;
    compiler.start(*root);
    compiler.createASM();

    system("nasm -felf32 output.asm");
    system("ld -m elf_i386 output.o");
    system("./a.out");

    return 0;
}
