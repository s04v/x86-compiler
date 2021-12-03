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
    Constant* c1 = new Constant(ConstType::NUMBER, "10");
    Constant* c2 = new Constant(ConstType::NUMBER, "20");
    
    Constant* c3 = new Constant(ConstType::NUMBER, "30");
    Constant* c4 = new Constant(ConstType::NUMBER, "40");


    Expr* expr2 = new Expr();
    expr2->left = c3;
    expr2->left->type = ExprOpType::OPERAND;

    expr2->right = c4;
    expr2->right->type = ExprOpType::OPERAND;
    expr2->exprType = ExprType::SUB;

    Expr* expr = new Expr();
    expr->left = c1;
    expr->left->type = ExprOpType::OPERAND;

    expr->right = c2;
    expr->right->type = ExprOpType::OPERAND;

    expr->exprType = ExprType::ADD;

    VarDef* stmt = new VarDef(SizeType::U32, "foo", expr);

    Stmt* func = new FuncDef("main", SizeType::U32, new vector<FuncArg*>(), new vector<Stmt*>());

    compiler.start(*root);
    cout << compiler.code << endl;


    return 0;
}
