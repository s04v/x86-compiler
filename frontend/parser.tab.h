/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 38 "parser.y"

    #include <string>
    #include <vector>
    #include "Ast.h"
    #include "../backend/SizeType.h"


#line 56 "parser.tab.h"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    NUMBER = 259,
    STRING = 260,
    CHAR = 261,
    INC = 262,
    DEC = 263,
    LPAREN = 264,
    RPAREN = 265,
    LBRACE = 266,
    RBRACE = 267,
    COMMA = 268,
    DOT = 269,
    QUESTION = 270,
    SEMI = 271,
    COLON = 272,
    MUL = 273,
    DIV = 274,
    OR = 275,
    ADD = 276,
    SUB = 277,
    EQ = 278,
    NEQ = 279,
    LT = 280,
    GT = 281,
    LTEQ = 282,
    GTEQ = 283,
    ASSIGN = 284,
    OTHER = 285,
    SPACE = 286,
    BOOL = 287,
    U8 = 288,
    I8 = 289,
    U16 = 290,
    I16 = 291,
    U32 = 292,
    I32 = 293,
    STRING_T = 294,
    VOID = 295,
    IMPORT = 296,
    STRUCT = 297,
    VAR = 298,
    FUNC = 299,
    RETURN = 300,
    IF = 301,
    ELSE = 302,
    FOR = 303
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 62 "parser.y"

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

#line 143 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
