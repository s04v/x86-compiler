#include <iostream>
#include <vector>
#include "frontend/parser.tab.h"
#include "ast/stmt.h"
#include "ast/if.h"


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
    cout << root->size();
    return 0;
}
