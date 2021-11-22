#include <iostream>
#include <vector>
#include "frontend/parser.tab.h"
#include "ast/stmt.h"
#include "ast/if.h"
#include "backend/x86/emitter.h"
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

    Emitter emit;
    
    cout << emit.mov_reg_reg(2,0);
    cout << emit.mov_reg_imm(10,4);    
    cout << emit.mov_reg_mem(0,1,-4);
    cout << emit.mov_reg_mem(0,1,4);
    cout << emit.add_reg_reg(2,0);
    cout << emit.add_reg_imm(10,4);    
    cout << emit.add_reg_mem(0,1);    
    cout << emit.sub_reg_reg(2,0);
    cout << emit.sub_reg_imm(10,4);    
    cout << emit.sub_reg_mem(0,1);
    cout << emit.sub_mem_reg(0,1);    
    cout << emit.sub_mem_imm(0,200);   
    cout << emit.idiv_mem(0);
    cout << emit.leave();






    return 0;
}
