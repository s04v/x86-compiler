%{

    #include <iostream>
    #include <vector>
    #include "../ast/Stmt.h"
    
    using namespace std;

    #define YYERROR_VERBOSE 1
    #define DEBUG

    extern FILE *yyin;
    extern int yylineno;
    
    vector<Stmt*>* root;
 
    int yylex(void);
    extern "C" {
        int yywrap(void) {
            return 1;
        }
        void yyerror(const char *str) {
            cout << "Parser: " << str << " on line " << yylineno << endl;
            exit(1);
        }
    }

%}

%code requires {
    #include <string>
    #include <vector>
    #include "../ast/Operand.h"
    #include "../ast/Constant.h"
    #include "../ast/Id.h"
    #include "../ast/ExprOp.h"
    #include "../ast/Call.h"
    #include "../ast/Expr.h"
    #include "../ast/Stmt.h"
    #include "../ast/Assign.h"
    #include "../ast/VarDef.h"
    #include "../ast/If.h"
    #include "../ast/FuncArg.h"
    #include "../ast/FuncDef.h"
    #include "../ast/SizeType.h"


}
%token ID NUMBER STRING CHAR
%token PTR_T
%token INC DEC
%token LPAREN RPAREN // ( )
%token LBRACKET RBRACKET // [ ]
%token LBRACE RBRACE // { }

%token COMMA DOT AT QUESTION SEMI COLON
%token NOT MUL DIV MOD AND OR ADD SUB XOR
%token EQ NEQ LT GT LTEQ GTEQ AND_AND OR_OR
%token ASSIGN ADD_ASSIGN SUB_ASSIGN OR_ASSIGN AND_ASSIGN XOR_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN

%token OTHER SPACE


%token BOOL U8 I8 U16 I16 U32 I32 STRING_T VOID
%token IMPORT STRUCT VAR FUNC RETURN IF ELSE FOR BREAK CONTINUE


%union {
    string* val;

    SizeType sizeType;
    Prefix prefix;
    ExprType exprType;
    AssignOperation assignOp;

    Constant* constant;
    Operand* operand;
    Expr* expr;
    ExprOp* exprOp;

    Assign* assign;
    VarDef* varDef;
    If* ifType;
    FuncArg* funcArg;
    FuncDef* funcDef;
    Stmt* stmt;


    vector<ExprOp*>* exprVec;
    vector<Stmt*>* stmtVec;
    vector<FuncArg*>* argVec;
}

%type <assignOp> assignment_operator
%type <assign> assign_stmt
%type <varDef> variable_def
%type <ifType> if_stmt

%type <funcArg> def_arg
%type <argVec> def_args_list
%type <funcDef> function_def

%type <stmt> stmt
%type <stmtVec> definition stmt_block 

%type <operand> unary_expr operand_expr postfix_expr primary_expr
%type <exprOp> or_or_expr and_and_expr equal_expr compare_expr add_expr mul_expr
%type <exprType> mul_op add_op compare_op equal_op

%type <exprVec> args_expr_list


%type <prefix> unary_operator
%type <val> ID CHAR NUMBER STRING
%type <sizeType> type

%start program

%%

program: definition { root = $1; }

definition: { $$ = new vector<Stmt*>(); }
    | definition variable_def  { $2->stmtType = StmtType::VAR_DEF; $1->push_back($2); }
    | definition function_def { $2->stmtType = StmtType::FUNC_DEF; $1->push_back($2); }
    
variable_def: VAR ID COLON type ASSIGN or_or_expr SEMI { $$ = new VarDef($4, *$2, $6); }

function_def: FUNC ID LPAREN def_args_list RPAREN COLON type LBRACE stmt_block RBRACE { $$ = new FuncDef(*$2, $7, $4, $9); }

def_arg: ID COLON type  { $$ = new FuncArg(*$1, $3); }

def_args_list: { $$ = new vector<FuncArg*>(); }
    | def_arg { $$ = new vector<FuncArg*>(); $$->push_back($1); }
    | def_args_list COMMA def_arg { $1->push_back($3); }

if_stmt: IF or_or_expr LBRACE stmt_block RBRACE { $$ = new If($2, $4); }

stmt_block: { $$ = new vector<Stmt*>();  }
    | stmt { $$ = new vector<Stmt*>(); $$->push_back($1); }
    | stmt_block stmt { $1->push_back($2); }

stmt: or_or_expr SEMI { $1->stmtType = StmtType::EXPR; $$ = $1; }
    | assign_stmt SEMI { $1->stmtType = StmtType::ASSIGN; $$ = $1; }
    | variable_def { $1->stmtType = StmtType::VAR_DEF, $$ = $1; }
    | if_stmt { $1->stmtType = StmtType::IF, $$ = $1; }

assign_stmt: operand_expr assignment_operator or_or_expr { $$ = new Assign($2, $1, $3);}

assignment_operator: ASSIGN { $$ = AssignOperation::ASSIGN; }
    | MUL_ASSIGN { $$ = AssignOperation::MUL_ASSIGN; }
    | DIV_ASSIGN { $$ = AssignOperation::DIV_ASSIGN; }
    | MOD_ASSIGN { $$ = AssignOperation::MOD_ASSIGN; }
    | ADD_ASSIGN { $$ = AssignOperation::ADD_ASSIGN; }
    | SUB_ASSIGN { $$ = AssignOperation::SUB_ASSIGN; }
    | AND_ASSIGN { $$ = AssignOperation::AND_ASSIGN; }
    | OR_ASSIGN { $$ = AssignOperation::OR_ASSIGN; }

or_or_expr: and_and_expr { $$ = $1; }
    | or_or_expr AND_AND and_and_expr { $$ = new Expr(ExprType::OR_OR, $1, $3); }

and_and_expr: equal_expr { $$ = $1; }
    | and_and_expr AND_AND equal_expr { $$ = new Expr(ExprType::AND_AND, $1, $3); }

equal_expr: compare_expr { $$ = $1; }
    | equal_expr equal_op compare_expr { $$ = new Expr($2, $1, $3); }

equal_op: EQ { $$ = ExprType::EQ; }
    | NEQ { $$ = ExprType::NEQ; }

compare_expr: add_expr { $$ = $1; }
    | compare_expr compare_op add_expr { $$ = new Expr($2, $1, $3); }

compare_op: LT { $$ = ExprType::LT; }
    | GT { $$ = ExprType::GT; }
    | LTEQ { $$ = ExprType::LTEQ; }
    | GTEQ { $$ = ExprType::GTEQ; }

add_expr: mul_expr { $$ = $1; }
    | add_expr add_op mul_expr  { $$ = new Expr($2, $1, $3); }

add_op: ADD { $$ = ExprType::ADD; } 
    | SUB { $$ = ExprType::SUB; } 
    
mul_expr: unary_expr { $$ = $1; }
    | mul_expr mul_op unary_expr { $$ = new Expr($2, $1, $3); }

mul_op: MUL { $$ = ExprType::MUL; } 
    | DIV { $$ = ExprType::DIV; }
    | MOD { $$ = ExprType::MOD; } 

unary_expr: operand_expr { $$ = $1; }
    | unary_operator unary_expr  { $2->prefix = $1; $$ = $2;}

unary_operator: MUL { $$ = Prefix::MUL; }
    | ADD { $$ = Prefix::ADD; }
    | SUB { $$ = Prefix::SUB; }
    | NOT { $$ = Prefix::NOT; }
    | AND { $$ = Prefix::AND; }
    | INC { $$ = Prefix::INC; }
    | DEC { $$ = Prefix::DEC; }

operand_expr: primary_expr { $$ = $1; } 
    | postfix_expr { $$ = $1; }

postfix_expr: ID { $$ = new Operand(); }
    | postfix_expr LPAREN args_expr_list RPAREN { $$ = new Call($1, $3); }
    | postfix_expr INC { $1->postfix = Postfix::INC; }
    | postfix_expr DEC { $1->postfix = Postfix::DEC; } 

args_expr_list: { $$ = new vector<ExprOp*>();  }
    | operand_expr { $$ = new vector<ExprOp*>(); $$->push_back($1); }
    | args_expr_list COMMA operand_expr { $1->push_back($3); }

primary_expr: CHAR { $$ = new Constant(ConstType::CHAR, *$1); }
    | NUMBER { $$ = new Constant(ConstType::NUMBER, *$1);}
    | STRING { $$ = new Constant(ConstType::STRING, *$1); }
    | LPAREN or_or_expr RPAREN 

type: BOOL { $$ = SizeType::BOOL; }
    | U8 { $$ = SizeType::U8; }
    | I8 { $$ = SizeType::I8; }
    | U16 { $$ = SizeType::U16; }
    | I16 { $$ = SizeType::I16; }
    | U32 { $$ = SizeType::U32; }
    | I32 { $$ = SizeType::I32; }
    | STRING_T { $$ = SizeType::STRING_T; }
    | VOID { $$ = SizeType::VOID; }
%%

