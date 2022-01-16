/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"


    #include <iostream>
    #include <vector>
    #include "Ast.h"
#include "../backend/x86/SizeType.h"


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


#line 101 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
#line 32 "parser.y"

    #include <string>
    #include <vector>
    #include "Ast.h"
    #include "../backend/x86/SizeType.h"


#line 152 "parser.tab.c"

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
#line 59 "parser.y"

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

#line 258 "parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   138

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  118

#define YYUNDEFTOK  2
#define YYMAXUTOK   323


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   112,   112,   114,   115,   116,   118,   120,   122,   124,
     125,   126,   128,   130,   131,   132,   134,   135,   136,   137,
     139,   141,   142,   143,   144,   145,   146,   147,   148,   150,
     151,   153,   154,   156,   157,   159,   160,   162,   163,   165,
     166,   167,   168,   170,   171,   173,   174,   176,   177,   179,
     180,   181,   183,   184,   186,   187,   188,   189,   190,   191,
     192,   194,   195,   197,   198,   199,   200,   202,   203,   204,
     206,   207,   208,   209,   211,   212,   213,   214,   215,   216,
     217,   218,   219
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "NUMBER", "STRING", "CHAR",
  "PTR_T", "INC", "DEC", "LPAREN", "RPAREN", "LBRACKET", "RBRACKET",
  "LBRACE", "RBRACE", "COMMA", "DOT", "AT", "QUESTION", "SEMI", "COLON",
  "NOT", "MUL", "DIV", "MOD", "AND", "OR", "ADD", "SUB", "XOR", "EQ",
  "NEQ", "LT", "GT", "LTEQ", "GTEQ", "AND_AND", "OR_OR", "ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "OR_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "OTHER", "SPACE", "BOOL", "U8",
  "I8", "U16", "I16", "U32", "I32", "STRING_T", "VOID", "IMPORT", "STRUCT",
  "VAR", "FUNC", "RETURN", "IF", "ELSE", "FOR", "BREAK", "CONTINUE",
  "$accept", "program", "definition", "variable_def", "function_def",
  "def_arg", "def_args_list", "if_stmt", "stmt_block", "stmt",
  "assign_stmt", "assignment_operator", "or_or_expr", "and_and_expr",
  "equal_expr", "equal_op", "compare_expr", "compare_op", "add_expr",
  "add_op", "mul_expr", "mul_op", "unary_expr", "unary_operator",
  "operand_expr", "postfix_expr", "args_expr_list", "primary_expr", "type", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323
};
# endif

#define YYPACT_NINF (-76)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -76,    11,    -1,   -76,    12,    14,   -76,   -76,     4,    35,
      56,    46,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,
     -76,    13,    42,   -76,     7,    76,    56,    54,    46,    45,
     -76,   -76,   -76,   -76,   -76,    76,   -76,   -76,   -76,   -76,
     -76,     9,    21,    69,    34,   105,   102,   -76,    76,   -76,
     122,   -76,   -76,    56,   -76,    76,     3,   -76,    76,    76,
     -76,   -76,    76,   -76,   -76,   -76,   -76,    76,   -76,   -76,
      76,   -76,   -76,   -76,    76,   -76,   -76,   -76,    73,    58,
      37,   -76,    21,    69,    34,   105,   102,   -76,    68,   -76,
      76,    76,   -76,   -76,    -2,   -76,    63,    27,    77,    58,
      -9,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,    76,    68,    58,    28,   -76
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     2,     1,     0,     0,     4,     5,     0,     0,
       0,     9,    74,    75,    76,    77,    78,    79,    80,    81,
      82,     0,     0,    10,     0,     0,     0,     0,     0,    63,
      71,    72,    70,    59,    60,     0,    57,    54,    58,    55,
      56,     0,    29,    31,    33,    37,    43,    47,     0,    52,
      62,    61,     8,     0,    11,    67,     0,     6,     0,     0,
      35,    36,     0,    39,    40,    41,    42,     0,    45,    46,
       0,    49,    50,    51,     0,    53,    65,    66,     0,    68,
       0,    73,    30,    32,    34,    38,    44,    48,    13,    64,
       0,     0,    18,    19,     0,    14,     0,     0,    52,    69,
       0,     7,    15,    17,    16,    21,    25,    26,    28,    27,
      22,    23,    24,     0,    13,    20,     0,    12
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -76,   -76,   -76,    91,   -76,    75,   -76,   -76,     1,   -75,
     -76,   -76,   -25,    70,    62,   -76,    74,   -76,    71,   -76,
      65,   -76,   -39,   -76,   -72,   -76,   -76,   -76,   -14
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    92,     7,    23,    24,    93,    94,    95,
      96,   113,    97,    42,    43,    62,    44,    67,    45,    70,
      46,    74,    47,    48,    49,    50,    80,    51,    21
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      41,    29,    30,    31,    32,   114,    33,    34,    35,    75,
      56,     3,    52,   101,    81,     8,    98,     9,    27,   102,
      36,    37,    98,    28,    38,    10,    39,    40,    58,    57,
      79,    29,    30,    31,    32,    87,    33,    34,    35,    78,
      58,   102,    98,   117,    98,    11,    58,   104,    89,    22,
      36,    37,    25,    90,    38,    55,    39,    40,    59,     4,
       4,     5,    91,    26,    58,    99,   100,    63,    64,    65,
      66,    29,    30,    31,    32,    53,    33,    34,    35,    29,
      30,    31,    32,   103,    33,    34,    35,    88,   115,     4,
      36,    37,    91,     6,    38,    58,    39,    40,    36,    37,
      60,    61,    38,    54,    39,    40,    12,    13,    14,    15,
      16,    17,    18,    19,    20,   116,   105,   106,   107,   108,
     109,    83,   110,   111,   112,    71,    72,    73,    82,     4,
      76,    77,    91,    68,    69,    86,    84,     0,    85
};

static const yytype_int8 yycheck[] =
{
      25,     3,     4,     5,     6,    14,     8,     9,    10,    48,
      35,     0,    26,    15,    11,     3,    88,     3,    11,    94,
      22,    23,    94,    16,    26,    21,    28,    29,    37,    20,
      55,     3,     4,     5,     6,    74,     8,     9,    10,    53,
      37,   116,   114,    15,   116,    10,    37,    20,    11,     3,
      22,    23,    39,    16,    26,    10,    28,    29,    37,    61,
      61,    62,    64,    21,    37,    90,    91,    33,    34,    35,
      36,     3,     4,     5,     6,    21,     8,     9,    10,     3,
       4,     5,     6,    20,     8,     9,    10,    14,   113,    61,
      22,    23,    64,     2,    26,    37,    28,    29,    22,    23,
      31,    32,    26,    28,    28,    29,    50,    51,    52,    53,
      54,    55,    56,    57,    58,   114,    39,    40,    41,    42,
      43,    59,    45,    46,    47,    23,    24,    25,    58,    61,
       8,     9,    64,    28,    29,    70,    62,    -1,    67
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    70,    71,     0,    61,    62,    72,    73,     3,     3,
      21,    10,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    97,     3,    74,    75,    39,    21,    11,    16,     3,
       4,     5,     6,     8,     9,    10,    22,    23,    26,    28,
      29,    81,    82,    83,    85,    87,    89,    91,    92,    93,
      94,    96,    97,    21,    74,    10,    81,    20,    37,    37,
      31,    32,    84,    33,    34,    35,    36,    86,    28,    29,
      88,    23,    24,    25,    90,    91,     8,     9,    97,    81,
      95,    11,    82,    83,    85,    87,    89,    91,    14,    11,
      16,    64,    72,    76,    77,    78,    79,    81,    93,    81,
      81,    15,    78,    20,    20,    39,    40,    41,    42,    43,
      45,    46,    47,    80,    14,    81,    77,    15
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    69,    70,    71,    71,    71,    72,    73,    74,    75,
      75,    75,    76,    77,    77,    77,    78,    78,    78,    78,
      79,    80,    80,    80,    80,    80,    80,    80,    80,    81,
      81,    82,    82,    83,    83,    84,    84,    85,    85,    86,
      86,    86,    86,    87,    87,    88,    88,    89,    89,    90,
      90,    90,    91,    91,    92,    92,    92,    92,    92,    92,
      92,    93,    93,    94,    94,    94,    94,    95,    95,    95,
      96,    96,    96,    96,    97,    97,    97,    97,    97,    97,
      97,    97,    97
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     2,     7,    10,     3,     0,
       1,     3,     5,     0,     1,     2,     2,     2,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     3,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     2,     2,     0,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 112 "parser.y"
                    { root = (yyvsp[0].stmtVec);  }
#line 1533 "parser.tab.c"
    break;

  case 3:
#line 114 "parser.y"
            { (yyval.stmtVec) = new vector<Stmt*>(); }
#line 1539 "parser.tab.c"
    break;

  case 4:
#line 115 "parser.y"
                               { (yyvsp[0].varDef)->stmtType = StmtType::VAR_DEF; (yyvsp[-1].stmtVec)->push_back((yyvsp[0].varDef)); }
#line 1545 "parser.tab.c"
    break;

  case 5:
#line 116 "parser.y"
                              { (yyvsp[0].funcDef)->stmtType = StmtType::FUNC_DEF; (yyvsp[-1].stmtVec)->push_back((yyvsp[0].funcDef)); }
#line 1551 "parser.tab.c"
    break;

  case 6:
#line 118 "parser.y"
                                                       { (yyval.varDef) = new VarDef((yyvsp[-3].sizeType), *(yyvsp[-5].val), (yyvsp[-1].exprOp)); }
#line 1557 "parser.tab.c"
    break;

  case 7:
#line 120 "parser.y"
                                                                                      { (yyval.funcDef) = new FuncDef(*(yyvsp[-8].val), (yyvsp[-3].sizeType), (yyvsp[-6].argVec), (yyvsp[-1].stmtVec)); }
#line 1563 "parser.tab.c"
    break;

  case 8:
#line 122 "parser.y"
                        { (yyval.funcArg) = new FuncArg(*(yyvsp[-2].val), (yyvsp[0].sizeType)); }
#line 1569 "parser.tab.c"
    break;

  case 9:
#line 124 "parser.y"
               { (yyval.argVec) = new vector<FuncArg*>(); }
#line 1575 "parser.tab.c"
    break;

  case 10:
#line 125 "parser.y"
              { (yyval.argVec) = new vector<FuncArg*>(); (yyval.argVec)->push_back((yyvsp[0].funcArg)); }
#line 1581 "parser.tab.c"
    break;

  case 11:
#line 126 "parser.y"
                                  { (yyvsp[-2].argVec)->push_back((yyvsp[0].funcArg)); }
#line 1587 "parser.tab.c"
    break;

  case 12:
#line 128 "parser.y"
                                                { (yyval.ifType) = new If((yyvsp[-3].exprOp), (yyvsp[-1].stmtVec)); }
#line 1593 "parser.tab.c"
    break;

  case 13:
#line 130 "parser.y"
            { (yyval.stmtVec) = new vector<Stmt*>();  }
#line 1599 "parser.tab.c"
    break;

  case 14:
#line 131 "parser.y"
           { (yyval.stmtVec) = new vector<Stmt*>(); (yyval.stmtVec)->push_back((yyvsp[0].stmt)); }
#line 1605 "parser.tab.c"
    break;

  case 15:
#line 132 "parser.y"
                      { (yyvsp[-1].stmtVec)->push_back((yyvsp[0].stmt)); }
#line 1611 "parser.tab.c"
    break;

  case 16:
#line 134 "parser.y"
                      { (yyvsp[-1].exprOp)->stmtType = StmtType::EXPR; (yyval.stmt) = (yyvsp[-1].exprOp); }
#line 1617 "parser.tab.c"
    break;

  case 17:
#line 135 "parser.y"
                       { (yyvsp[-1].assign)->stmtType = StmtType::ASSIGN; (yyval.stmt) = (yyvsp[-1].assign); }
#line 1623 "parser.tab.c"
    break;

  case 18:
#line 136 "parser.y"
                   { (yyvsp[0].varDef)->stmtType = StmtType::VAR_DEF, (yyval.stmt) = (yyvsp[0].varDef); }
#line 1629 "parser.tab.c"
    break;

  case 19:
#line 137 "parser.y"
              { (yyvsp[0].ifType)->stmtType = StmtType::IF, (yyval.stmt) = (yyvsp[0].ifType); }
#line 1635 "parser.tab.c"
    break;

  case 20:
#line 139 "parser.y"
                                                         { (yyval.assign) = new Assign((yyvsp[-1].assignOp), (yyvsp[-2].operand), (yyvsp[0].exprOp));}
#line 1641 "parser.tab.c"
    break;

  case 21:
#line 141 "parser.y"
                            { (yyval.assignOp) = AssignOperation::ASSIGN; }
#line 1647 "parser.tab.c"
    break;

  case 22:
#line 142 "parser.y"
                 { (yyval.assignOp) = AssignOperation::MUL_ASSIGN; }
#line 1653 "parser.tab.c"
    break;

  case 23:
#line 143 "parser.y"
                 { (yyval.assignOp) = AssignOperation::DIV_ASSIGN; }
#line 1659 "parser.tab.c"
    break;

  case 24:
#line 144 "parser.y"
                 { (yyval.assignOp) = AssignOperation::MOD_ASSIGN; }
#line 1665 "parser.tab.c"
    break;

  case 25:
#line 145 "parser.y"
                 { (yyval.assignOp) = AssignOperation::ADD_ASSIGN; }
#line 1671 "parser.tab.c"
    break;

  case 26:
#line 146 "parser.y"
                 { (yyval.assignOp) = AssignOperation::SUB_ASSIGN; }
#line 1677 "parser.tab.c"
    break;

  case 27:
#line 147 "parser.y"
                 { (yyval.assignOp) = AssignOperation::AND_ASSIGN; }
#line 1683 "parser.tab.c"
    break;

  case 28:
#line 148 "parser.y"
                { (yyval.assignOp) = AssignOperation::OR_ASSIGN; }
#line 1689 "parser.tab.c"
    break;

  case 29:
#line 150 "parser.y"
                         { (yyval.exprOp) = (yyvsp[0].exprOp); }
#line 1695 "parser.tab.c"
    break;

  case 30:
#line 151 "parser.y"
                                      { (yyval.exprOp) = new Expr(ExprType::OR_OR, (yyvsp[-2].exprOp), (yyvsp[0].exprOp)); }
#line 1701 "parser.tab.c"
    break;

  case 31:
#line 153 "parser.y"
                         { (yyval.exprOp) = (yyvsp[0].exprOp); }
#line 1707 "parser.tab.c"
    break;

  case 32:
#line 154 "parser.y"
                                      { (yyval.exprOp) = new Expr(ExprType::AND_AND, (yyvsp[-2].exprOp), (yyvsp[0].exprOp)); }
#line 1713 "parser.tab.c"
    break;

  case 33:
#line 156 "parser.y"
                         { (yyval.exprOp) = (yyvsp[0].exprOp); }
#line 1719 "parser.tab.c"
    break;

  case 34:
#line 157 "parser.y"
                                       { (yyval.exprOp) = new Expr((yyvsp[-1].exprType), (yyvsp[-2].exprOp), (yyvsp[0].exprOp)); }
#line 1725 "parser.tab.c"
    break;

  case 35:
#line 159 "parser.y"
             { (yyval.exprType) = ExprType::EQ; }
#line 1731 "parser.tab.c"
    break;

  case 36:
#line 160 "parser.y"
          { (yyval.exprType) = ExprType::NEQ; }
#line 1737 "parser.tab.c"
    break;

  case 37:
#line 162 "parser.y"
                       { (yyval.exprOp) = (yyvsp[0].exprOp); }
#line 1743 "parser.tab.c"
    break;

  case 38:
#line 163 "parser.y"
                                       { (yyval.exprOp) = new Expr((yyvsp[-1].exprType), (yyvsp[-2].exprOp), (yyvsp[0].exprOp)); }
#line 1749 "parser.tab.c"
    break;

  case 39:
#line 165 "parser.y"
               { (yyval.exprType) = ExprType::LT; }
#line 1755 "parser.tab.c"
    break;

  case 40:
#line 166 "parser.y"
         { (yyval.exprType) = ExprType::GT; }
#line 1761 "parser.tab.c"
    break;

  case 41:
#line 167 "parser.y"
           { (yyval.exprType) = ExprType::LTEQ; }
#line 1767 "parser.tab.c"
    break;

  case 42:
#line 168 "parser.y"
           { (yyval.exprType) = ExprType::GTEQ; }
#line 1773 "parser.tab.c"
    break;

  case 43:
#line 170 "parser.y"
                   { (yyval.exprOp) = (yyvsp[0].exprOp); }
#line 1779 "parser.tab.c"
    break;

  case 44:
#line 171 "parser.y"
                                { (yyval.exprOp) = new Expr((yyvsp[-1].exprType), (yyvsp[-2].exprOp), (yyvsp[0].exprOp)); }
#line 1785 "parser.tab.c"
    break;

  case 45:
#line 173 "parser.y"
            { (yyval.exprType) = ExprType::ADD; }
#line 1791 "parser.tab.c"
    break;

  case 46:
#line 174 "parser.y"
          { (yyval.exprType) = ExprType::SUB; }
#line 1797 "parser.tab.c"
    break;

  case 47:
#line 176 "parser.y"
                     { (yyval.exprOp) = (yyvsp[0].operand); }
#line 1803 "parser.tab.c"
    break;

  case 48:
#line 177 "parser.y"
                                 { (yyval.exprOp) = new Expr((yyvsp[-1].exprType), (yyvsp[-2].exprOp), (yyvsp[0].operand)); }
#line 1809 "parser.tab.c"
    break;

  case 49:
#line 179 "parser.y"
            { (yyval.exprType) = ExprType::MUL; }
#line 1815 "parser.tab.c"
    break;

  case 50:
#line 180 "parser.y"
          { (yyval.exprType) = ExprType::DIV; }
#line 1821 "parser.tab.c"
    break;

  case 51:
#line 181 "parser.y"
          { (yyval.exprType) = ExprType::MOD; }
#line 1827 "parser.tab.c"
    break;

  case 52:
#line 183 "parser.y"
                         { (yyval.operand) = (yyvsp[0].operand); }
#line 1833 "parser.tab.c"
    break;

  case 53:
#line 184 "parser.y"
                                 { (yyvsp[0].operand)->prefix = (yyvsp[-1].prefix); (yyval.operand) = (yyvsp[0].operand);}
#line 1839 "parser.tab.c"
    break;

  case 54:
#line 186 "parser.y"
                    { (yyval.prefix) = Prefix::MUL; }
#line 1845 "parser.tab.c"
    break;

  case 55:
#line 187 "parser.y"
          { (yyval.prefix) = Prefix::ADD; }
#line 1851 "parser.tab.c"
    break;

  case 56:
#line 188 "parser.y"
          { (yyval.prefix) = Prefix::SUB; }
#line 1857 "parser.tab.c"
    break;

  case 57:
#line 189 "parser.y"
          { (yyval.prefix) = Prefix::NOT; }
#line 1863 "parser.tab.c"
    break;

  case 58:
#line 190 "parser.y"
          { (yyval.prefix) = Prefix::AND; }
#line 1869 "parser.tab.c"
    break;

  case 59:
#line 191 "parser.y"
          { (yyval.prefix) = Prefix::INC; }
#line 1875 "parser.tab.c"
    break;

  case 60:
#line 192 "parser.y"
          { (yyval.prefix) = Prefix::DEC; }
#line 1881 "parser.tab.c"
    break;

  case 61:
#line 194 "parser.y"
                           { (yyval.operand) = (yyvsp[0].operand); }
#line 1887 "parser.tab.c"
    break;

  case 62:
#line 195 "parser.y"
                   { (yyval.operand) = (yyvsp[0].operand); }
#line 1893 "parser.tab.c"
    break;

  case 63:
#line 197 "parser.y"
                 { (yyval.operand) = new Id(*(yyvsp[0].val)); }
#line 1899 "parser.tab.c"
    break;

  case 64:
#line 198 "parser.y"
                                      { (yyval.operand) = new Call(*(yyvsp[-3].val), (yyvsp[-1].exprVec)); }
#line 1905 "parser.tab.c"
    break;

  case 65:
#line 199 "parser.y"
                       { (yyvsp[-1].operand)->postfix = Postfix::INC; }
#line 1911 "parser.tab.c"
    break;

  case 66:
#line 200 "parser.y"
                       { (yyvsp[-1].operand)->postfix = Postfix::DEC; }
#line 1917 "parser.tab.c"
    break;

  case 67:
#line 202 "parser.y"
                { (yyval.exprVec) = new vector<ExprOp*>();  }
#line 1923 "parser.tab.c"
    break;

  case 68:
#line 203 "parser.y"
                 { (yyval.exprVec) = new vector<ExprOp*>(); (yyval.exprVec)->push_back((yyvsp[0].exprOp)); }
#line 1929 "parser.tab.c"
    break;

  case 69:
#line 204 "parser.y"
                                      { (yyvsp[-2].exprVec)->push_back((yyvsp[0].exprOp)); }
#line 1935 "parser.tab.c"
    break;

  case 70:
#line 206 "parser.y"
                   { (yyval.operand) = new Constant(ConstType::CHAR, *(yyvsp[0].val)); }
#line 1941 "parser.tab.c"
    break;

  case 71:
#line 207 "parser.y"
             { (yyval.operand) = new Constant(ConstType::NUMBER, *(yyvsp[0].val)); }
#line 1947 "parser.tab.c"
    break;

  case 72:
#line 208 "parser.y"
             { (yyval.operand) = new Constant(ConstType::STRING, *(yyvsp[0].val)); }
#line 1953 "parser.tab.c"
    break;

  case 74:
#line 211 "parser.y"
           { (yyval.sizeType) = SizeType::BOOL; }
#line 1959 "parser.tab.c"
    break;

  case 75:
#line 212 "parser.y"
         { (yyval.sizeType) = SizeType::U8; }
#line 1965 "parser.tab.c"
    break;

  case 76:
#line 213 "parser.y"
         { (yyval.sizeType) = SizeType::I8; }
#line 1971 "parser.tab.c"
    break;

  case 77:
#line 214 "parser.y"
          { (yyval.sizeType) = SizeType::U16; }
#line 1977 "parser.tab.c"
    break;

  case 78:
#line 215 "parser.y"
          { (yyval.sizeType) = SizeType::I16; }
#line 1983 "parser.tab.c"
    break;

  case 79:
#line 216 "parser.y"
          { (yyval.sizeType) = SizeType::U32; }
#line 1989 "parser.tab.c"
    break;

  case 80:
#line 217 "parser.y"
          { (yyval.sizeType) = SizeType::I32; }
#line 1995 "parser.tab.c"
    break;

  case 81:
#line 218 "parser.y"
               { (yyval.sizeType) = SizeType::STRING_T; }
#line 2001 "parser.tab.c"
    break;

  case 82:
#line 219 "parser.y"
           { (yyval.sizeType) = SizeType::VOID; }
#line 2007 "parser.tab.c"
    break;


#line 2011 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 220 "parser.y"


