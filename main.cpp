#include <iostream>
#include <vector>

#include "frontend/parser.tab.h"
#include "ast/Stmt.h"
#include "ast/If.h"
#include "ast/Expr.h"
#include "ast/Constant.h"

#include "backend/x86/Emitter.h"
#include "backend/x86/Reg.h"
#include "backend/x86/Compiler.h"

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
    
    Operand* op1 = c1;
    op1->opType = OpType::CONSTANT;

    Operand* op2 = c2;
    op2->opType = OpType::CONSTANT;

    Expr* expr = new Expr();
    expr->left = op1;
    expr->left->type = ExprOpType::OPERAND;

    expr->right = op2;
    expr->right->type = ExprOpType::OPERAND;
    expr->exprType = ExprType::ADD;


    compiler.genExpr(expr);
    cout << compiler.code << endl;
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
