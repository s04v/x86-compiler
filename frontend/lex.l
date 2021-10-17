%{
    #include <string>
    #include <iostream>

    using namespace std;

    #define YYSTYPE string
    #include "parser.tab.h"
%}

identifier      [_a-zA-Z][_a-zA-Z0-9]*
quote1          "\'"[^'\\]*"\'"
quote2          "\""[^"\\]*"\""
%%
\n\r|\r\n|\n|\r {
                    /* skip empty line */
                }
"#"             {
                    /* skip comment */
                }
[0-9]*           {
                    yylval = yytext;
                    return NUMBER;
                }
'([^\r^\n^']|\\0)' { yylval = yytext; return CHAR; } // fix thiss

":"                 yylval = yytext; return COLON;
";"                 yylval = yytext; return SEMI;
"."                 yylval = yytext; return DOT;
"@"                 yylval = yytext; return AT;
"?"                 yylval = yytext; return QUESTION;
","                 yylval = yytext; return COMMA;
"("                 yylval = yytext; return LPAREN;
")"                 yylval = yytext; return RPAREN;
"{"                 yylval = yytext; return LBRACE;
"}"                 yylval = yytext; return RBRACE;
"["                 yylval = yytext; return LBRACKET;
"]"                 yylval = yytext; return RBRACKET;
"+"                 yylval = yytext; return ADD;
"-"                 yylval = yytext; return SUB;
"*"                 yylval = yytext; return MUL;
"/"                 yylval = yytext; return DIV;
"!"                 yylval = yytext; return NOT;
"%"                 yylval = yytext; return MOD;
"&"                 yylval = yytext; return AND;
"|"                 yylval = yytext; return OR;

"^"                 yylval = yytext; return XOR;
"=="                yylval = yytext; return EQ;
"!"                 yylval = yytext; return NEQ;
"<"                 yylval = yytext; return LT;
">"                 yylval = yytext; return GT;
"<="                yylval = yytext; return LTEQ;
">="                yylval = yytext; return GTEQ;
"&&"                yylval = yytext; return AND_AND;
"||"                yylval = yytext; return OR_OR;

"="                 yylval = yytext; return ASSIGN;
"+="                yylval = yytext; return ADD_ASSIGN;
"-="                yylval = yytext; return SUB_ASSIGN;
"|="                yylval = yytext; return OR_ASSIGN;
"&="                yylval = yytext; return AND_ASSIGN;
"^="                yylval = yytext; return XOR_ASSIGN;
"*="                yylval = yytext; return MUL_ASSIGN;
"/="                yylval = yytext; return DIV_ASSIGN;
"%="                yylval = yytext; return MOD_ASSIGN;
"++"                yylval = yytext; return INC;
"--"                yylval = yytext; return DEC;

"bool"              yylval = yytext; return BOOL;
"u8"                yylval = yytext; return U8;
"i8"                yylval = yytext; return I8;
"u16"               yylval = yytext; return U16;
"i16"               yylval = yytext; return I16;
"u32"               yylval = yytext; return U32;
"i32"               yylval = yytext; return I32;
"string"            yylval = yytext; return STRING_T;

"import "           yylval = yytext; return DEC;
"struct"            yylval = yytext; return STRUCT;
"var "              yylval = yytext; return VAR;
"if "               yylval = yytext; return DEC;
"func "             yylval = yytext; return FUNC;
"else"              yylval = yytext; return DEC;
"for "              yylval = yytext; return DEC;
"break"             yylval = yytext; return DEC;
"continue"          yylval = yytext; return DEC;

{identifier}    {
                    yylval = yytext;
                    return ID;
                }

[ \t]+          { }
.               {
                    yylval = yytext;
                    return OTHER;
                }
%%

