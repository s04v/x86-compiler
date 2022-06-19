%{
    #include <string>
    #include <iostream>
    #include "parser.tab.h"

    using namespace std;

    #define YY_USER_ACTION                                             \
      yylloc.first_line = yylloc.last_line;                            \
      yylloc.first_column = yylloc.last_column;                        \
      if (yylloc.last_line == yylineno)                                \
        yylloc.last_column += yyleng;                                  \
      else {                                                           \
        yylloc.last_line = yylineno;                                   \
        yylloc.last_column = yytext + yyleng - strrchr(yytext, '\n');  \
      }
%}
%option yylineno

%%
\n\r|\r\n|\n|\r         { }
[ \t]+                  { }

[0-9]*                  yylval.val = new string(yytext); return NUMBER; 
L?\"(\\.|[^\\"\n])*\"	yylval.val = new string(yytext); return STRING;
'([^\r^\n^']|\\0)'      yylval.val = new string(yytext); return CHAR;

":"                     yylval.val = new string(yytext); return COLON;
";"                     yylval.val = new string(yytext); return SEMI;
"."                     yylval.val = new string(yytext); return DOT;
"?"                     yylval.val = new string(yytext); return QUESTION;
","                     yylval.val = new string(yytext); return COMMA;

"("                     yylval.val = new string(yytext); return LPAREN;
")"                     yylval.val = new string(yytext); return RPAREN;
"{"                     yylval.val = new string(yytext); return LBRACE;
"}"                     yylval.val = new string(yytext); return RBRACE;

"+"                     yylval.val = new string(yytext); return ADD;
"-"                     yylval.val = new string(yytext); return SUB;
"*"                     yylval.val = new string(yytext); return MUL;
"/"                     yylval.val = new string(yytext); return DIV;

"=="                    yylval.val = new string(yytext); return EQ;
"!="                    yylval.val = new string(yytext); return NEQ;
"<"                     yylval.val = new string(yytext); return LT;
">"                     yylval.val = new string(yytext); return GT;
"<="                    yylval.val = new string(yytext); return LTEQ;
">="                    yylval.val = new string(yytext); return GTEQ;

"="                     yylval.val = new string(yytext); return ASSIGN;
"++"                    yylval.val = new string(yytext); return INC;
"--"                    yylval.val = new string(yytext); return DEC;

"bool"                  yylval.val = new string(yytext); return BOOL;
"u8"                    yylval.val = new string(yytext); return U8;
"i8"                    yylval.val = new string(yytext); return I8;
"u16"                   yylval.val = new string(yytext); return U16;
"i16"                   yylval.val = new string(yytext); return I16;
"u32"                   yylval.val = new string(yytext); return U32;
"i32"                   yylval.val = new string(yytext); return I32;
"string"                yylval.val = new string(yytext); return STRING_T;
"void"                  yylval.val = new string(yytext); return VOID;

"import "               yylval.val = new string(yytext); return IMPORT;
"struct"                yylval.val = new string(yytext); return STRUCT;
"var"                   yylval.val = new string(yytext); return VAR;
"func"                  yylval.val = new string(yytext); return FUNC;
"return"                yylval.val = new string(yytext); return RETURN;
"if "                   yylval.val = new string(yytext); return IF;
"for "                  yylval.val = new string(yytext); return FOR;

[_a-zA-Z][_a-zA-Z0-9]*  yylval.val = new string(yytext); return ID;
.                       yylval.val = new string(yytext); return OTHER;

%%

