%{

    #include <iostream>
    #include <vector>
    #include "Ast.h"
    #include "../backend/SizeType.h"


    using namespace std;

    #define YYERROR_VERBOSE 1
    //#define DEBUG

    extern FILE *yyin;
    extern int yylineno;

    vector<Stmt*>* root;

    int yylex(void);
    extern "C" {
        int yywrap(void) {
            return 1;
        }

    }

    void yyerror(const char *str) {
        cout << "Parsing error: " << str << " on line " << yylineno << endl;
        exit(1);
    }

    #define YY_ACTION_USER \
        yyloc->first_line = yyloc->last_line = yylineno; \

%}
%locations

%code requires {
    #include <string>
    #include <vector>
    #include "Ast.h"
    #include "../backend/SizeType.h"

}
%token ID NUMBER STRING CHAR
%token INC DEC
%token LPAREN RPAREN // ( )
%token LBRACE RBRACE // { }

%token COMMA DOT QUESTION SEMI COLON
%token MUL DIV OR ADD SUB
%token EQ NEQ LT GT LTEQ GTEQ
%token ASSIGN

%token OTHER SPACE

%token BOOL U8 I8 U16 I16 U32 I32 STRING_T VOID
%token IMPORT STRUCT VAR FUNC RETURN IF ELSE FOR
%left ADD SUB
%left MUL DIV

%union {
    string* val;

    SizeType sizeType;
    Prefix prefix;
    ExprType exprType;

    Constant* constant;
    Operand* operand;
    Expr* expr;
    ExprOp* exprOp;

    Assign* assign;
    VarDef* varDef;
    If* ifType;
    For* forType;
    FuncArg* funcArg;
    FuncDef* funcDef;
    Return* returnStmt;
    Stmt* stmt;


    vector<ExprOp*>* exprVec;
    vector<Stmt*>* stmtVec;
    vector<FuncArg*>* argVec;
}

%type <assignOp> assignment_operator
%type <assign> assign_stmt
%type <varDef> variable_def
%type <ifType> if_stmt
%type <forType> for_stmt

%type <funcArg> def_arg
%type <argVec> def_args_list
%type <funcDef> function_def
%type <returnStmt> return_stmt

%type <stmt> stmt
%type <stmtVec> definition stmt_block

%type <operand> unary_expr operand_expr postfix_expr primary_expr
%type <exprOp> equal_expr and_and_expr compare_expr add_expr mul_expr
%type <exprType> mul_op add_op compare_op equal_op

%type <exprVec> args_expr_list


%type <prefix> unary_operator
%type <val> ID CHAR NUMBER STRING
%type <sizeType> type

%start program

%%

program: definition { root = $1; }

definition: { $$ = new vector<Stmt*>(); }
    | definition variable_def  { $2->stmtType = StmtType::VAR_DEF; $1->push_back($2); $2->line = @2.first_line;}
    | definition function_def { $2->stmtType = StmtType::FUNC_DEF; $1->push_back($2); $2->line = @2.first_line;}

variable_def: VAR ID COLON type ASSIGN equal_expr SEMI { $$ = new VarDef($4, *$2, $6); }

function_def: FUNC ID LPAREN def_args_list RPAREN COLON type LBRACE stmt_block RBRACE { $$ = new FuncDef(*$2, $7, $4, $9);  }

def_arg: ID COLON type  { $$ = new FuncArg(*$1, $3); }

def_args_list: { $$ = new vector<FuncArg*>(); }
    | def_arg { $$ = new vector<FuncArg*>(); $$->push_back($1); }
    | def_args_list COMMA def_arg { $1->push_back($3); }

stmt_block: { $$ = new vector<Stmt*>();  }
    | stmt { $$ = new vector<Stmt*>(); $$->push_back($1); $1->line = @1.first_line;}
    | stmt_block stmt { $1->push_back($2); $2->line = @2.first_line;}

stmt: equal_expr SEMI { $1->stmtType = StmtType::EXPR; $$ = $1; }
    | assign_stmt SEMI { $1->stmtType = StmtType::ASSIGN; $$ = $1; }
    | variable_def { $1->stmtType = StmtType::VAR_DEF, $$ = $1; }
    | if_stmt { $1->stmtType = StmtType::IF, $$ = $1; }
    | for_stmt { $1->stmtType = StmtType::FOR, $$ = $1; }
    | return_stmt { $1->stmtType = StmtType::RETURN; $$ = $1; }

return_stmt: RETURN equal_expr SEMI { $$ = new Return($2); }

if_stmt: IF equal_expr LBRACE stmt_block RBRACE { $$ = new If($2, $4);}

for_stmt: FOR variable_def equal_expr SEMI equal_expr LBRACE stmt_block RBRACE { $$ = new For($2, $3, $5, $7); }

assign_stmt: ID ASSIGN equal_expr { $$ = new Assign(*$1, $3);}

equal_expr: compare_expr { $$ = $1; $$->line = @1.first_line; }
    | equal_expr equal_op compare_expr { $$ = new Expr($2, $1, $3); $$->line = @1.first_line; }

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
    | mul_expr mul_op mul_expr { $$ = new Expr($2, $1, $3); }
    | LPAREN equal_expr RPAREN { $$ = $2; }

mul_op: MUL { $$ = ExprType::MUL; }
    | DIV { $$ = ExprType::DIV; }

unary_expr: operand_expr { $$ = $1; }
    | unary_operator unary_expr  { $2->prefix = $1; $$ = $2;}

unary_operator: INC { $$ = Prefix::INC; }
    | DEC { $$ = Prefix::DEC; }

operand_expr: primary_expr { $$ = $1; }
    | postfix_expr { $$ = $1; }

postfix_expr: ID { $$ = new Id(*$1); }
    | ID LPAREN args_expr_list RPAREN { $$ = new Call(*$1, $3); }
    | postfix_expr INC { $1->postfix = Postfix::INC; }
    | postfix_expr DEC { $1->postfix = Postfix::DEC; }

args_expr_list: { $$ = new vector<ExprOp*>();  }
    | equal_expr { $$ = new vector<ExprOp*>(); $$->push_back($1); }
    | args_expr_list COMMA equal_expr { $1->push_back($3); }

primary_expr: CHAR { $$ = new Constant(ConstType::CHAR, *$1); }
    | NUMBER { $$ = new Constant(ConstType::NUMBER, *$1); }
    | STRING { $$ = new Constant(ConstType::STRING, *$1); }

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

