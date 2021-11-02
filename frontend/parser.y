%{

    #include <iostream>

    using namespace std;

    #define YYERROR_VERBOSE 1
    #define DEBUG

    extern FILE *yyin;
    extern int yylineno;
    
    int yylex(void);
    extern "C" {
        int yywrap(void) {
            return 1;
        }
    }
    void yyerror(const char *str) {
        cout << "Parser: " << str << " on line " << yylineno << endl;
        exit(1);
    }

%}

%code requires {
    #include <string>
    #include <vector>
    #include "../ast/operand.h"
    #include "../ast/constant.h"
    #include "../ast/id.h"
    #include "../ast/exprOp.h"
    #include "../ast/call.h"
    #include "../ast/expr.h"

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
    Prefix prefix;
    ExprType exprType;

    vector<ExprOp*>* exprVec;
    Constant* constant;
    Operand* operand;
}


%type <operand> unary_expr operand_expr postfix_expr primary_expr  
%type <exprVec> args_expr_list


%type <exprType> mul_op add_op compare_op equal_op
%type <prefix> unary_operator
%type <val> ID CHAR NUMBER STRING


%start input

%%

input: 
     | input error
     | input program 

program: definition

definition: variable_def
    | function_def
    
variable_def: VAR ID COLON type ASSIGN ternary_expr SEMI

function_def: FUNC ID LPAREN func_def_args_list RPAREN COLON type LBRACE stmt_block RBRACE

def_arg: ID COLON type 

def_args_list: def_arg 
    | def_args_list COMMA def_arg 

func_def_args_list:
    | def_args_list 

stmt_block:
    | stmt_block stmt

stmt: expr SEMI
    | assign_stmt SEMI
    | variable_def
    | if_stmt
    

expr: ternary_expr 

assign_stmt: operand_expr assignment_operator ternary_expr

assignment_operator: ASSIGN
    | MUL_ASSIGN
    | DIV_ASSIGN
    | MOD_ASSIGN
    | ADD_ASSIGN
    | SUB_ASSIGN
    | AND_ASSIGN
    | OR_ASSIGN

if_stmt: IF or_or_expr LBRACE stmt_block RBRACE


ternary_expr: or_or_expr { $$ = $1; }
    | or_or_expr QUESTION expr COLON ternary_expr

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
    | mul_expr mod_op unary_expr { $$ = new Expr($2, $1, $3); }

mod_op: MUL { $$ = ExprType::MUL; } 
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


operand_expr: primary_expr 
    | postfix_expr { $$ = $1; }

postfix_expr: ID {  $$ = new Operand();
                    cout << "ID = " << *$1 << " or " << *yylval.val << endl; }
    | postfix_expr LBRACKET operand_expr RBRACKET {cout << "array " << endl; }
    | postfix_expr LPAREN args_expr_list RPAREN { $$ = new Call($1, $3); }
    | postfix_expr DOT postfix_expr {cout << "member " << endl; }
    | postfix_expr INC { $1->postfix = Postfix::INC; }
    | postfix_expr DEC { $1->postfix = Postfix::DEC; } 

args_expr_list: 
    | operand_expr { $$ = new vector<ExprOp*>(); $$->push_back($1); }
    | args_expr_list COMMA operand_expr { $1->push_back($3); }

primary_expr: CHAR { $$ = new Constant(ConstType::CHAR, *$1); }
    | NUMBER { $$ = new Constant(ConstType::NUMBER, *$1);}
    | STRING { $$ = new Constant(ConstType::STRING, *$1); }
    | LPAREN ternary_expr RPAREN 

type: BOOL
    | U8
    | I8
    | U16
    | I16
    | U32
    | I32
    | STRING_T
    | ID
    | VOID
    | type MUL
    | type LBRACKET RBRACKET
    

%%

