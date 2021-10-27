program: import
    | definition

definition: variable_def
    | struct_def
    | function_def
    
variable_decl: VAR ID COLON type ASSIGN ternary_expr SEMI

function_def: FUNC ID LPAREN func_def_args_list RPAREN COLON type LBRACE stmt RBRACE

def_arg: ID COLON type 

def_args_list: def_arg 
    | def_args_list COMMA def_arg 

func_def_args_list:
    | def_args_list 

stmt: expr
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
    | mul_expr ADD mul_expr
    | mul_expr SUB mul_expr

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
    | MUL
    | AND

operand_expr: 
    | primary_expr 
    | postfix_expr 

postfix_expr: ID {cout << "prim_expr " << endl;}
    | postfix_expr LBRACKET operand_expr RBRACKET {cout << "array " << endl;}
    | postfix_expr LPAREN args_expr_list RPAREN {cout << "func call " << endl;}
    | postfix_expr DOT postfix_expr {cout << "member " << endl;}
    | postfix_expr INC {cout << "inc " << endl;}
    | postfix_expr DEC {cout << "dec " << endl;} 

args_expr_list: 
    | operand_expr 
    | args_expr_list COMMA operand_expr

primary_expr: ID 
    | CHAR 
    | NUMBER 
    | STRING 
    | LPAREN ternary_expr RPAREN