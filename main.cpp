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
   
    /*yyin = fopen(argv[1], "r");
    if( !yyin ) {
        std::cout << "File not found" << std::endl;
        exit(1);
    }

    yyparse();*/

    x86::Compiler compiler;
    Constant* c1 = new Constant(ConstType::NUMBER, "10");
    Constant* c2 = new Constant(ConstType::NUMBER, "20");
    
    Constant* c3 = new Constant(ConstType::NUMBER, "10");
    Constant* c4 = new Constant(ConstType::NUMBER, "20");


    Expr* expr2 = new Expr();
    expr2->left = c3;
    expr2->left->type = ExprOpType::OPERAND;

    expr2->right = c4;
    expr2->right->type = ExprOpType::OPERAND;
    expr2->exprType = ExprType::SUB;

    Expr* expr = new Expr();
    expr->left = c1;
    expr->left->type = ExprOpType::OPERAND;

    expr->right = expr2;
    expr->right->type = ExprOpType::EXPR;
    expr->exprType = ExprType::ADD;


    compiler.gen(*expr);
    cout << compiler.code << endl;

    /*x86::Scope scope;
    scope.init();
    scope.table.addVar("foo2",SizeType::U32);

    scope.extend();
    scope.table.addVar("foo",SizeType::U32);
    scope.table.addVar("bar",SizeType::U32);

    cout << scope.table.get("foo").name << endl;
    cout << scope.table.get("foo2").name << endl;
    scope.pop();
    cout << scope.table.get("foo").name << endl;*/

    // x86::Emitter emit;
    // x86::Register reg;

    // int dest =  reg.alloc32();
    // int src =  reg.alloc32();

    // cout << emit.mov_reg_reg(dest,src);
    // cout << emit.mov_reg_imm(10,4);    
    // cout << emit.mov_reg_mem(0,1,-4);
    // cout << emit.mov_reg_mem(0,1,4);
    // cout << emit.add_reg_reg(2,0);
    // cout << emit.add_reg_imm(10,4);    
    // cout << emit.add_reg_mem(0,1);    
    // cout << emit.sub_reg_reg(2,0);
    // cout << emit.sub_reg_imm(10,4);    
    // cout << emit.sub_reg_mem(0,1);
    // cout << emit.sub_mem_reg(0,1);    
    // cout << emit.sub_mem_imm(0,200);   
    // cout << emit.idiv_mem(0);
    // cout << emit.leave();






    return 0;
}
