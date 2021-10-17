%{

    #include <iostream>

    using namespace std;
    #define YYERROR_VERBOSE 1
    #define YYSTYPE string
    #define DEBUG

    extern FILE *yyin;
    extern int yylineno;

    int  wrapRet = 1;

    int yylex(void);
    extern "C" {
        int yywrap( void ) {
            return wrapRet;
        }
    }
    void yyerror(const char *str) {
        cout << "Parser: " << str << " on line " << yylineno << endl;
        exit(1);
    }

    int main();

%}

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


%start input

%%

input: /* empty */
     | input  error
     | input program

;

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
    ;


primary_expr: ID { }
    | CHAR {}
    | NUMBER { }
    | STRING {};

    // '(' expr ')'
postfix_expr: ID {cout << "prim_expr " << endl;}
    | postfix_expr LBRACKET operand_expr RBRACKET {cout << "array " << endl;}
    | postfix_expr LPAREN args_expr_list RPAREN {cout << "func call " << endl;}
    | postfix_expr DOT ID {cout << "member " << endl;}
    | postfix_expr INC {cout << "inc " << endl;}
    | postfix_expr DEC {cout << "dec " << endl;} ;

args_expr_list: operand_expr {}
    | args_expr_list COMMA operand_expr {}

operand_expr: {}
    | primary_expr {}
    | postfix_expr {}

unary_operator: MUL
    | ADD
    | SUB
    | NOT
    | MUL
    | AND
    ;

unary_expr: operand_expr { }
    | INC unary_expr { cout << "pre inc " << endl; }
    | DEC unary_expr { cout << "pre dec " << endl; }
    | unary_operator unary_expr  {cout << "unary op " << endl;}

mul_expr: unary_expr {}
    | mul_expr MUL unary_expr {}
    | mul_expr DIV unary_expr {}
    | mul_expr MOD unary_expr {}

add_expr: mul_expr {}
    | mul_expr ADD mul_expr {}
    | mul_expr SUB mul_expr {}

relation_expr: add_expr {}
    | relation_expr LT add_expr {}
    | relation_expr GT add_expr {}
    | relation_expr LTEQ add_expr {}
    | relation_expr GTEQ add_expr {}

equal_expr: relation_expr {}
    | equal_expr EQ relation_expr {}
    | equal_expr NEQ relation_expr {}

//TODO: & | ^
and_and_expr: equal_expr{}
    | and_and_expr AND_AND equal_expr{}

or_or_expr: and_and_expr{}
    | or_or_expr AND_AND and_and_expr{}

ternary_expr: or_or_expr{}
    | or_or_expr QUESTION expr COLON ternary_expr


assignment_operator: ASSIGN
    | MUL_ASSIGN
    | DIV_ASSIGN
    | MOD_ASSIGN
    | ADD_ASSIGN
    | SUB_ASSIGN
    | AND_ASSIGN
    | OR_ASSIGN
    ;

assign_expr: ternary_expr {}
    | operand_expr assignment_operator ternary_expr {}

expr: assign_expr {}

expr_stmt: expr SEMI {}


// Variable
var_def_stmt: VAR ID COLON type ASSIGN ternary_expr SEMI {cout << "variable definition" << endl;}

//Function
func_def_stmt: FUNC ID LPAREN func_def_args_list RPAREN COLON type LBRACE func_stmt RBRACE { cout << "function definition" << endl;}

def_arg: ID COLON type {}

def_args_list: def_arg {}
      | def_args_list COMMA def_arg {}

func_def_args_list:
    | def_args_list {}

func_stmt:
    | var_def_stmt {}
    | expr_stmt {}

//Struct
struct_def_stmt: STRUCT ID LBRACE struct_def RBRACE { cout << "struct definition" << endl;}

struct_def: struct_field {}
        | struct_def {}

struct_field: ID COLON type SEMI {}

stmt0:
    var_def_stmt {}
    | func_def_stmt {}
    | struct_def_stmt {}


import_stmt: IMPORT AT ID SEMI {cout << "import stmt" << endl;}

program: import_stmt { }
    | stmt0 { cout << "stmt0" << endl; }
    | program {}






%%

