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
#line 30 "parser.y"

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


#line 66 "parser.tab.h"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    NUMBER = 259,
    STRING = 260,
    CHAR = 261,
    PTR_T = 262,
    INC = 263,
    DEC = 264,
    LPAREN = 265,
    RPAREN = 266,
    LBRACKET = 267,
    RBRACKET = 268,
    LBRACE = 269,
    RBRACE = 270,
    COMMA = 271,
    DOT = 272,
    AT = 273,
    QUESTION = 274,
    SEMI = 275,
    COLON = 276,
    NOT = 277,
    MUL = 278,
    DIV = 279,
    MOD = 280,
    AND = 281,
    OR = 282,
    ADD = 283,
    SUB = 284,
    XOR = 285,
    EQ = 286,
    NEQ = 287,
    LT = 288,
    GT = 289,
    LTEQ = 290,
    GTEQ = 291,
    AND_AND = 292,
    OR_OR = 293,
    ASSIGN = 294,
    ADD_ASSIGN = 295,
    SUB_ASSIGN = 296,
    OR_ASSIGN = 297,
    AND_ASSIGN = 298,
    XOR_ASSIGN = 299,
    MUL_ASSIGN = 300,
    DIV_ASSIGN = 301,
    MOD_ASSIGN = 302,
    OTHER = 303,
    SPACE = 304,
    BOOL = 305,
    U8 = 306,
    I8 = 307,
    U16 = 308,
    I16 = 309,
    U32 = 310,
    I32 = 311,
    STRING_T = 312,
    VOID = 313,
    IMPORT = 314,
    STRUCT = 315,
    VAR = 316,
    FUNC = 317,
    RETURN = 318,
    IF = 319,
    ELSE = 320,
    FOR = 321,
    BREAK = 322,
    CONTINUE = 323
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 66 "parser.y"

    string* val;

    VarType varType;
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

#line 172 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
