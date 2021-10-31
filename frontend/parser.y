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
    #include "../ast/ast.h"
    #include "../ast/operand.h"
    #include "../ast/constant.h"


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
    char cval;
    VarDef* varDef;
    FuncDef* funcDef;
    ASTNode* astNode;
    ASTNode* prog;
    Constant* constant;
    Operand* operand;
}

%type <varDef> var_def
%type <funcDef> func_def
%type <prog> program
%type <astNode> stmt0
%type <operand> primary_expr
%type <val> CHAR

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
    | variable_def
    | if_stmt

expr: ternary_expr 
    | assign_expr


assign_expr: operand_expr assignment_operator ternary_expr

assignment_operator: ASSIGN
    | MUL_ASSIGN
    | DIV_ASSIGN
    | MOD_ASSIGN
    | ADD_ASSIGN
    | SUB_ASSIGN
    | AND_ASSIGN
    | OR_ASSIGN

if_stmt: IF or_or_expr LBRACE stmt_block RBRACE


ternary_expr: or_or_expr
    | or_or_expr QUESTION expr COLON ternary_expr

or_or_expr: and_and_expr
    | or_or_expr AND_AND and_and_expr

and_and_expr: equal_expr
    | and_and_expr AND_AND equal_expr

equal_expr: relation_expr
    | equal_expr EQ relation_expr
    | equal_expr NEQ relation_expr

relation_expr: add_expr 
    | relation_expr LT add_expr 
    | relation_expr GT add_expr 
    | relation_expr LTEQ add_expr 
    | relation_expr GTEQ add_expr

add_expr: mul_expr 
    | add_expr ADD mul_expr
    | add_expr SUB mul_expr

mul_expr: unary_expr
    | mul_expr MUL unary_expr
    | mul_expr DIV unary_expr
    | mul_expr MOD unary_expr 

unary_expr: operand_expr 
    | INC unary_expr { cout << "pre inc " << endl; }
    | DEC unary_expr { cout << "pre dec " << endl; }
    | unary_operator unary_expr  { cout << "unary op " << endl; }

unary_operator: MUL
    | ADD
    | SUB
    | NOT
    | AND

operand_expr: primary_expr 
    | postfix_expr 

postfix_expr: ID {cout << "prim_expr " << endl;}
    | postfix_expr LBRACKET operand_expr RBRACKET {cout << "array " << endl;}
    | postfix_expr LPAREN args_expr_list RPAREN {cout << "func call " << endl;}
    | postfix_expr DOT postfix_expr {cout << "member " << endl;}
    | postfix_expr INC {cout << "post inc" << endl;}
    | postfix_expr DEC {cout << "post dec " << endl;} 

args_expr_list: 
    | operand_expr 
    | args_expr_list COMMA operand_expr

primary_expr: ID { }
    | CHAR { $$ = new Constant(ConstType::Char, *$1); }
    | NUMBER {}
    | STRING {}
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

