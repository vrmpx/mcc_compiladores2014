/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_Void = 258,
     T_Bool = 259,
     T_Int = 260,
     T_Double = 261,
     T_String = 262,
     T_Class = 263,
     T_LessEqual = 264,
     T_GreaterEqual = 265,
     T_Equal = 266,
     T_NotEqual = 267,
     T_Dims = 268,
     T_And = 269,
     T_Or = 270,
     T_Null = 271,
     T_Extends = 272,
     T_This = 273,
     T_Interface = 274,
     T_Implements = 275,
     T_While = 276,
     T_For = 277,
     T_If = 278,
     T_Else = 279,
     T_Return = 280,
     T_Break = 281,
     T_New = 282,
     T_NewArray = 283,
     T_Print = 284,
     T_ReadInteger = 285,
     T_ReadLine = 286,
     T_Identifier = 287,
     T_StringConstant = 288,
     T_IntConstant = 289,
     T_DoubleConstant = 290,
     T_BoolConstant = 291
   };
#endif
/* Tokens.  */
#define T_Void 258
#define T_Bool 259
#define T_Int 260
#define T_Double 261
#define T_String 262
#define T_Class 263
#define T_LessEqual 264
#define T_GreaterEqual 265
#define T_Equal 266
#define T_NotEqual 267
#define T_Dims 268
#define T_And 269
#define T_Or 270
#define T_Null 271
#define T_Extends 272
#define T_This 273
#define T_Interface 274
#define T_Implements 275
#define T_While 276
#define T_For 277
#define T_If 278
#define T_Else 279
#define T_Return 280
#define T_Break 281
#define T_New 282
#define T_NewArray 283
#define T_Print 284
#define T_ReadInteger 285
#define T_ReadLine 286
#define T_Identifier 287
#define T_StringConstant 288
#define T_IntConstant 289
#define T_DoubleConstant 290
#define T_BoolConstant 291




/* Copy the first part of user declarations.  */
#line 11 "parser.y"


/* Just like lex, the text within this first region delimited by %{ and %}
 * is assumed to be C/C++ code and will be copied verbatim to the y.tab.c
 * file ahead of the definitions of the yyparse() function. Add other header
 * file inclusions or C++ variable declarations/prototypes that are needed
 * by your code here.
 */
#include "scanner.h" // for yylex
#include "parser.h"
#include "errors.h"

void yyerror(char *msg); // standard error-handling routine



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 41 "parser.y"
{
    int integerConstant;
    bool boolConstant;
    char *stringConstant;
    double doubleConstant;
    char identifier[MaxIdentLen+1]; // +1 for terminating null
    Decl *decl;
    List<Decl*> *declList;
    VarDecl *varDecl;
    FnDecl *fnDecl;
    ClassDecl *classDecl;
    InterfaceDecl *interfaceDecl;
    VarDecl *var;
    List<VarDecl*> *varList;
    Type *type;
    StmtBlock *stmtBlock;
    List<Identifier*> *identifierList;
    NamedType *namedType;
    List<NamedType*> *namedTypeList;
    List<Stmt*> *stmtList;
    Stmt *stmt;
    Expr *expr;
    List<Expr*> *exprList;
    IfStmt *ifStmt;
    WhileStmt *whileStmt;
    ForStmt *forStmt;
    ReturnStmt *returnStmt;
    BreakStmt *breakStmt;
    PrintStmt *printStmt;
    LValue *lvalue;
}
/* Line 193 of yacc.c.  */
#line 216 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 241 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   411

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNRULES -- Number of states.  */
#define YYNSTATES  190

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,     2,     2,    48,     2,     2,
      39,    40,    46,    44,    38,    45,    52,    47,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    37,
      49,    43,    50,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    53,     2,    54,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,    42,     2,     2,     2,     2,
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
      35,    36
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    16,    18,
      21,    25,    29,    31,    33,    35,    37,    39,    41,    44,
      51,    58,    60,    61,    69,    72,    73,    76,    80,    81,
      84,    85,    87,    89,    95,    98,    99,   106,   113,   118,
     121,   123,   126,   128,   130,   132,   134,   136,   138,   140,
     143,   144,   150,   157,   163,   173,   176,   182,   185,   191,
     195,   197,   199,   200,   204,   206,   208,   210,   212,   216,
     220,   224,   228,   232,   236,   239,   243,   247,   251,   255,
     259,   263,   267,   271,   274,   278,   282,   285,   287,   291,
     296,   301,   308,   310,   311,   313,   315,   317,   319
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      56,     0,    -1,    57,    -1,    57,    58,    -1,    58,    -1,
      59,    -1,    63,    -1,    65,    -1,    70,    -1,    60,    37,
      -1,    62,    32,    37,    -1,    61,    38,    60,    -1,    60,
      -1,     5,    -1,     6,    -1,     4,    -1,     7,    -1,    32,
      -1,    62,    13,    -1,    62,    32,    39,    64,    40,    73,
      -1,     3,    32,    39,    64,    40,    73,    -1,    61,    -1,
      -1,     8,    32,    66,    67,    41,    68,    42,    -1,    17,
      32,    -1,    -1,    20,    32,    -1,    67,    38,    32,    -1,
      -1,    68,    69,    -1,    -1,    59,    -1,    63,    -1,    19,
      32,    41,    71,    42,    -1,    71,    72,    -1,    -1,    62,
      32,    39,    64,    40,    37,    -1,     3,    32,    39,    64,
      40,    37,    -1,    41,    61,    74,    42,    -1,    74,    75,
      -1,    75,    -1,    85,    37,    -1,    77,    -1,    78,    -1,
      79,    -1,    81,    -1,    80,    -1,    82,    -1,    73,    -1,
      24,    75,    -1,    -1,    23,    39,    85,    40,    75,    -1,
      23,    39,    85,    40,    75,    76,    -1,    21,    39,    85,
      40,    75,    -1,    22,    39,    84,    37,    85,    37,    84,
      40,    75,    -1,    25,    37,    -1,    25,    39,    84,    40,
      37,    -1,    26,    37,    -1,    29,    39,    83,    40,    37,
      -1,    83,    38,    85,    -1,    85,    -1,    85,    -1,    -1,
      86,    43,    85,    -1,    89,    -1,    86,    -1,    18,    -1,
      87,    -1,    39,    85,    40,    -1,    85,    44,    85,    -1,
      85,    45,    85,    -1,    85,    46,    85,    -1,    85,    47,
      85,    -1,    85,    48,    85,    -1,    45,    85,    -1,    85,
      49,    85,    -1,    85,     9,    85,    -1,    85,    50,    85,
      -1,    85,    10,    85,    -1,    85,    11,    85,    -1,    85,
      12,    85,    -1,    85,    14,    85,    -1,    85,    15,    85,
      -1,    51,    85,    -1,    30,    39,    40,    -1,    31,    39,
      40,    -1,    27,    32,    -1,    32,    -1,    85,    52,    32,
      -1,    85,    53,    85,    54,    -1,    32,    39,    88,    40,
      -1,    85,    52,    32,    39,    88,    40,    -1,    83,    -1,
      -1,    34,    -1,    35,    -1,    36,    -1,    33,    -1,    16,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   145,   145,   157,   158,   161,   162,   163,   164,   167,
     170,   173,   174,   177,   178,   179,   180,   181,   182,   186,
     187,   191,   192,   195,   198,   199,   202,   203,   204,   208,
     209,   212,   213,   216,   218,   219,   222,   223,   226,   229,
     230,   234,   235,   236,   237,   238,   239,   240,   241,   244,
     245,   248,   249,   252,   255,   258,   259,   262,   265,   268,
     269,   272,   273,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   304,   305,   306,
     309,   310,   313,   314,   317,   318,   319,   320,   321
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_Void", "T_Bool", "T_Int", "T_Double",
  "T_String", "T_Class", "T_LessEqual", "T_GreaterEqual", "T_Equal",
  "T_NotEqual", "T_Dims", "T_And", "T_Or", "T_Null", "T_Extends", "T_This",
  "T_Interface", "T_Implements", "T_While", "T_For", "T_If", "T_Else",
  "T_Return", "T_Break", "T_New", "T_NewArray", "T_Print", "T_ReadInteger",
  "T_ReadLine", "T_Identifier", "T_StringConstant", "T_IntConstant",
  "T_DoubleConstant", "T_BoolConstant", "';'", "','", "'('", "')'", "'{'",
  "'}'", "'='", "'+'", "'-'", "'*'", "'/'", "'%'", "'<'", "'>'", "'!'",
  "'.'", "'['", "']'", "$accept", "Program", "DeclList", "Decl",
  "VariableDecl", "Variable", "VarPlus", "Type", "FunctionDecl", "Formals",
  "ClassDecl", "Extends0", "Implements0", "FieldS", "Field",
  "InterfaceDecl", "Prototype0", "Prototype", "StmtBlock", "StmtPlus",
  "Stmt", "ElseStmt0", "IfStmt", "WhileStmt", "ForStmt", "ReturnStmt",
  "BreakStmt", "PrintStmt", "ExprPlus", "Expr0", "Expr", "LValue", "Call",
  "Actuals", "Constant", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,    59,    44,    40,
      41,   123,   125,    61,    43,    45,    42,    47,    37,    60,
      62,    33,    46,    91,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    57,    57,    58,    58,    58,    58,    59,
      60,    61,    61,    62,    62,    62,    62,    62,    62,    63,
      63,    64,    64,    65,    66,    66,    67,    67,    67,    68,
      68,    69,    69,    70,    71,    71,    72,    72,    73,    74,
      74,    75,    75,    75,    75,    75,    75,    75,    75,    76,
      76,    77,    77,    78,    79,    80,    80,    81,    82,    83,
      83,    84,    84,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    86,    86,    86,
      87,    87,    88,    88,    89,    89,    89,    89,    89
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     2,
       3,     3,     1,     1,     1,     1,     1,     1,     2,     6,
       6,     1,     0,     7,     2,     0,     2,     3,     0,     2,
       0,     1,     1,     5,     2,     0,     6,     6,     4,     2,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     2,
       0,     5,     6,     5,     9,     2,     5,     2,     5,     3,
       1,     1,     0,     3,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     3,     3,     2,     1,     3,     4,
       4,     6,     1,     0,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    15,    13,    14,    16,     0,     0,    17,     0,
       2,     4,     5,     0,     0,     6,     7,     8,     0,    25,
       0,     1,     3,     9,    18,     0,    22,     0,    28,    35,
      10,    22,    12,    21,     0,     0,    24,     0,     0,     0,
       0,     0,     0,     0,    26,     0,    30,     0,    33,     0,
      34,     0,    11,     0,    20,    27,     0,     0,     0,    19,
       0,    23,    31,    32,    29,    22,    22,    98,    66,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    87,    97,
      94,    95,    96,     0,     0,     0,    48,     0,    40,    42,
      43,    44,    46,    45,    47,     0,    65,    67,    64,     0,
       0,     0,    62,     0,    55,    62,    57,    86,     0,     0,
       0,    93,     0,    74,    83,    38,    39,     0,     0,     0,
       0,     0,     0,    41,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    61,     0,
       0,     0,    60,    84,    85,    92,     0,    68,    76,    78,
      79,    80,    81,    82,    69,    70,    71,    72,    73,    75,
      77,    88,     0,    63,    37,    36,     0,     0,     0,     0,
       0,     0,    90,    93,    89,    53,     0,    50,    56,    59,
      58,     0,    62,     0,    52,    91,     0,    49,     0,    54
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    10,    11,    12,    32,    33,    34,    15,    35,
      16,    28,    38,    56,    64,    17,    39,    50,    86,    87,
      88,   184,    89,    90,    91,    92,    93,    94,   145,   137,
      95,    96,    97,   146,    98
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -101
static const yytype_int16 yypact[] =
{
     379,   -16,  -101,  -101,  -101,  -101,    -5,    20,  -101,    54,
     379,  -101,  -101,    18,    -7,  -101,  -101,  -101,    19,    45,
      24,  -101,  -101,  -101,  -101,   -26,   229,    34,    47,  -101,
    -101,   229,  -101,    30,    -4,    35,  -101,    46,   -31,    27,
      40,   229,    49,    42,  -101,    52,  -101,    55,  -101,    28,
    -101,    42,  -101,   229,  -101,  -101,   224,    50,    51,  -101,
     246,  -101,  -101,  -101,  -101,   229,   229,  -101,  -101,    60,
      63,    64,   -22,    67,    73,    74,    78,    79,    80,  -101,
    -101,  -101,  -101,   330,   330,   330,  -101,   277,  -101,  -101,
    -101,  -101,  -101,  -101,  -101,    83,    81,  -101,  -101,    82,
      85,   330,   330,   330,  -101,   330,  -101,  -101,   330,    86,
      94,   330,   128,   205,   205,  -101,  -101,   330,   330,   330,
     330,   330,   330,  -101,   330,   330,   330,   330,   330,   330,
     330,    89,   330,   330,   104,   107,   139,   108,   205,   150,
     106,    23,   205,  -101,  -101,   109,   112,  -101,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,    84,    62,   205,  -101,  -101,   308,   330,   308,   118,
     330,   119,  -101,   330,  -101,  -101,   195,   133,  -101,   205,
    -101,   123,   330,   308,  -101,  -101,   126,  -101,   308,  -101
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -101,  -101,  -101,   148,   111,     8,   116,    14,   114,    -9,
    -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,   -39,  -101,
     -87,  -101,  -101,  -101,  -101,  -101,  -101,  -101,    93,  -100,
     -82,  -101,  -101,    -2,  -101
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
     116,   112,   113,   114,    54,   140,    24,    45,    13,    24,
      46,    30,    59,    31,    14,   104,    18,   105,    13,   136,
     138,   139,    40,   138,    14,    25,   142,    19,    42,   142,
      47,     2,     3,     4,     5,   148,   149,   150,   151,   152,
     153,    24,   154,   155,   156,   157,   158,   159,   160,    52,
     162,   163,    20,    49,    21,    23,    99,   100,    26,     8,
      58,   170,    27,   171,    13,    29,    36,    37,    41,    48,
      14,   117,   118,   119,   120,    43,   121,   122,    44,   175,
      51,   177,   186,    53,    55,   176,    30,    57,   179,    65,
      66,   142,   117,   118,   119,   120,   187,   121,   122,   101,
     138,   189,   102,   103,   106,   107,   124,   125,   126,   127,
     128,   129,   130,   108,   131,   132,   174,   109,   110,   111,
     123,   161,   134,   173,   133,   135,   143,   124,   125,   126,
     127,   128,   129,   130,   144,   131,   132,   117,   118,   119,
     120,   164,   121,   122,   165,   167,   169,   170,   117,   118,
     119,   120,   172,   121,   122,   178,   180,   183,    22,   117,
     118,   119,   120,   185,   121,   122,   188,    62,   147,    60,
      63,   181,   124,   125,   126,   127,   128,   129,   130,   166,
     131,   132,     0,   124,   125,   126,   127,   128,   129,   130,
     168,   131,   132,     0,   124,   125,   126,   127,   128,   129,
     130,   141,   131,   132,   117,   118,   119,   120,     0,   121,
     122,     0,     0,     0,   117,   118,   119,   120,     0,   121,
     122,     0,     0,     0,     0,     0,     0,     1,     2,     3,
       4,     5,   182,     2,     3,     4,     5,     0,     0,   124,
     125,   126,   127,   128,   129,   130,     0,   131,   132,   124,
     125,   126,   127,   128,   129,   130,     8,   131,   132,     0,
       0,     8,    67,     0,    68,     0,    61,    69,    70,    71,
       0,    72,    73,    74,     0,    75,    76,    77,    78,    79,
      80,    81,    82,     0,    41,    83,     0,    53,     0,     0,
       0,    84,     0,    67,     0,    68,     0,    85,    69,    70,
      71,     0,    72,    73,    74,     0,    75,    76,    77,    78,
      79,    80,    81,    82,     0,     0,    83,     0,    53,   115,
       0,     0,    84,     0,    67,     0,    68,     0,    85,    69,
      70,    71,     0,    72,    73,    74,     0,    75,    76,    77,
      78,    79,    80,    81,    82,     0,    67,    83,    68,    53,
       0,     0,     0,    84,     0,     0,     0,    74,     0,    85,
      76,    77,    78,    79,    80,    81,    82,     0,     0,    83,
       0,     0,     0,     0,     0,    84,     0,     0,     0,     0,
       0,    85,     1,     2,     3,     4,     5,     6,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     8
};

static const yytype_int16 yycheck[] =
{
      87,    83,    84,    85,    43,   105,    13,    38,     0,    13,
      41,    37,    51,    39,     0,    37,    32,    39,    10,   101,
     102,   103,    31,   105,    10,    32,   108,    32,    32,   111,
       3,     4,     5,     6,     7,   117,   118,   119,   120,   121,
     122,    13,   124,   125,   126,   127,   128,   129,   130,    41,
     132,   133,    32,    39,     0,    37,    65,    66,    39,    32,
      32,    38,    17,    40,    56,    41,    32,    20,    38,    42,
      56,     9,    10,    11,    12,    40,    14,    15,    32,   166,
      40,   168,   182,    41,    32,   167,    37,    32,   170,    39,
      39,   173,     9,    10,    11,    12,   183,    14,    15,    39,
     182,   188,    39,    39,    37,    32,    44,    45,    46,    47,
      48,    49,    50,    39,    52,    53,    54,    39,    39,    39,
      37,    32,    40,    39,    43,    40,    40,    44,    45,    46,
      47,    48,    49,    50,    40,    52,    53,     9,    10,    11,
      12,    37,    14,    15,    37,    37,    40,    38,     9,    10,
      11,    12,    40,    14,    15,    37,    37,    24,    10,     9,
      10,    11,    12,    40,    14,    15,    40,    56,    40,    53,
      56,   173,    44,    45,    46,    47,    48,    49,    50,    40,
      52,    53,    -1,    44,    45,    46,    47,    48,    49,    50,
      40,    52,    53,    -1,    44,    45,    46,    47,    48,    49,
      50,   108,    52,    53,     9,    10,    11,    12,    -1,    14,
      15,    -1,    -1,    -1,     9,    10,    11,    12,    -1,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,    37,     4,     5,     6,     7,    -1,    -1,    44,
      45,    46,    47,    48,    49,    50,    -1,    52,    53,    44,
      45,    46,    47,    48,    49,    50,    32,    52,    53,    -1,
      -1,    32,    16,    -1,    18,    -1,    42,    21,    22,    23,
      -1,    25,    26,    27,    -1,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    38,    39,    -1,    41,    -1,    -1,
      -1,    45,    -1,    16,    -1,    18,    -1,    51,    21,    22,
      23,    -1,    25,    26,    27,    -1,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    -1,    41,    42,
      -1,    -1,    45,    -1,    16,    -1,    18,    -1,    51,    21,
      22,    23,    -1,    25,    26,    27,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    16,    39,    18,    41,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    27,    -1,    51,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,
      -1,    51,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    19,    32,    56,
      57,    58,    59,    60,    62,    63,    65,    70,    32,    32,
      32,     0,    58,    37,    13,    32,    39,    17,    66,    41,
      37,    39,    60,    61,    62,    64,    32,    20,    67,    71,
      64,    38,    32,    40,    32,    38,    41,     3,    42,    62,
      72,    40,    60,    41,    73,    32,    68,    32,    32,    73,
      61,    42,    59,    63,    69,    39,    39,    16,    18,    21,
      22,    23,    25,    26,    27,    29,    30,    31,    32,    33,
      34,    35,    36,    39,    45,    51,    73,    74,    75,    77,
      78,    79,    80,    81,    82,    85,    86,    87,    89,    64,
      64,    39,    39,    39,    37,    39,    37,    32,    39,    39,
      39,    39,    85,    85,    85,    42,    75,     9,    10,    11,
      12,    14,    15,    37,    44,    45,    46,    47,    48,    49,
      50,    52,    53,    43,    40,    40,    85,    84,    85,    85,
      84,    83,    85,    40,    40,    83,    88,    40,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    32,    85,    85,    37,    37,    40,    37,    40,    40,
      38,    40,    40,    39,    54,    75,    85,    75,    37,    85,
      37,    88,    37,    24,    76,    40,    84,    75,    40,    75
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;
#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 0;
#endif

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
	YYSTACK_RELOCATE (yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 145 "parser.y"
    { 
                                      (yylsp[(1) - (1)]); 
                                      /* pp2: The @1 is needed to convince 
                                       * yacc to set up yylloc. You can remove 
                                       * it once you have other uses of @n*/
                                      Program *program = new Program((yyvsp[(1) - (1)].declList));
                                      // if no errors, advance to next phase
                                      if (ReportError::NumErrors() == 0) 
                                          program->Print(0);
                                    }
    break;

  case 3:
#line 157 "parser.y"
    { ((yyval.declList)=(yyvsp[(1) - (2)].declList))->Append((yyvsp[(2) - (2)].decl)); }
    break;

  case 4:
#line 158 "parser.y"
    { ((yyval.declList) = new List<Decl*>)->Append((yyvsp[(1) - (1)].decl)); }
    break;

  case 5:
#line 161 "parser.y"
    {(yyval.decl) = (yyvsp[(1) - (1)].varDecl);}
    break;

  case 6:
#line 162 "parser.y"
    {(yyval.decl) = (yyvsp[(1) - (1)].fnDecl);}
    break;

  case 7:
#line 163 "parser.y"
    {(yyval.decl) = (yyvsp[(1) - (1)].classDecl);}
    break;

  case 8:
#line 164 "parser.y"
    {(yyval.decl) = (yyvsp[(1) - (1)].interfaceDecl);}
    break;

  case 9:
#line 167 "parser.y"
    {(yyval.varDecl) = (yyvsp[(1) - (2)].var);}
    break;

  case 10:
#line 170 "parser.y"
    {Identifier *id = new Identifier((yylsp[(2) - (3)]), (yyvsp[(2) - (3)].identifier)); (yyval.var) = new VarDecl(id, (yyvsp[(1) - (3)].type));}
    break;

  case 11:
#line 173 "parser.y"
    {((yyval.varList) = (yyvsp[(1) - (3)].varList))->Append((yyvsp[(3) - (3)].var));}
    break;

  case 12:
#line 174 "parser.y"
    {((yyval.varList) = new List<VarDecl*>)->Append((yyvsp[(1) - (1)].var));}
    break;

  case 13:
#line 177 "parser.y"
    {(yyval.type) = new Type(*Type::intType);}
    break;

  case 14:
#line 178 "parser.y"
    {(yyval.type) = new Type(*Type::doubleType);}
    break;

  case 15:
#line 179 "parser.y"
    {(yyval.type) = new Type(*Type::boolType);}
    break;

  case 16:
#line 180 "parser.y"
    {(yyval.type) = new Type(*Type::stringType);}
    break;

  case 17:
#line 181 "parser.y"
    {(yyval.type) = new NamedType(new Identifier((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].identifier)));}
    break;

  case 18:
#line 182 "parser.y"
    {(yyval.type) = new ArrayType((yylsp[(1) - (2)]), (yyvsp[(1) - (2)].type));}
    break;

  case 19:
#line 186 "parser.y"
    {Identifier *id = new Identifier((yylsp[(2) - (6)]), (yyvsp[(2) - (6)].identifier)); (yyval.fnDecl) = new FnDecl(id, (yyvsp[(1) - (6)].type), (yyvsp[(4) - (6)].varList)); (yyval.fnDecl)->SetFunctionBody((yyvsp[(6) - (6)].stmtBlock));}
    break;

  case 20:
#line 187 "parser.y"
    {Identifier *id = new Identifier((yylsp[(2) - (6)]), (yyvsp[(2) - (6)].identifier)); Type *tvoid = new Type(*Type::voidType); (yyval.fnDecl) = new FnDecl(id, tvoid, (yyvsp[(4) - (6)].varList)); (yyval.fnDecl)->SetFunctionBody((yyvsp[(6) - (6)].stmtBlock));}
    break;

  case 21:
#line 191 "parser.y"
    {(yyval.varList) = (yyvsp[(1) - (1)].varList);}
    break;

  case 22:
#line 192 "parser.y"
    {(yyval.varList) = new List<VarDecl*>;}
    break;

  case 23:
#line 195 "parser.y"
    {Identifier *id = new Identifier((yylsp[(2) - (7)]), (yyvsp[(2) - (7)].identifier)); (yyval.classDecl) = new ClassDecl(id, (yyvsp[(3) - (7)].namedType), (yyvsp[(4) - (7)].namedTypeList), (yyvsp[(6) - (7)].declList));}
    break;

  case 24:
#line 198 "parser.y"
    {Identifier *id = new Identifier((yylsp[(2) - (2)]), (yyvsp[(2) - (2)].identifier)); (yyval.namedType) = new NamedType(id);}
    break;

  case 25:
#line 199 "parser.y"
    {(yyval.namedType) = NULL;}
    break;

  case 26:
#line 202 "parser.y"
    {Identifier *id = new Identifier((yylsp[(2) - (2)]), (yyvsp[(2) - (2)].identifier)); NamedType *nt = new NamedType(id); ((yyval.namedTypeList) = new List<NamedType*>)->Append(nt);}
    break;

  case 27:
#line 203 "parser.y"
    {Identifier *id = new Identifier((yylsp[(3) - (3)]), (yyvsp[(3) - (3)].identifier)); NamedType *nt = new NamedType(id); ((yyval.namedTypeList)=(yyvsp[(1) - (3)].namedTypeList))->Append(nt);}
    break;

  case 28:
#line 204 "parser.y"
    {(yyval.namedTypeList) = new List<NamedType*>;}
    break;

  case 29:
#line 208 "parser.y"
    {((yyval.declList) = (yyvsp[(1) - (2)].declList))->Append((yyvsp[(2) - (2)].decl));}
    break;

  case 30:
#line 209 "parser.y"
    {(yyval.declList) = new List<Decl*>;}
    break;

  case 31:
#line 212 "parser.y"
    {(yyval.decl) = (yyvsp[(1) - (1)].varDecl);}
    break;

  case 32:
#line 213 "parser.y"
    {(yyval.decl) = (yyvsp[(1) - (1)].fnDecl);}
    break;

  case 33:
#line 216 "parser.y"
    {Identifier *id = new Identifier((yylsp[(2) - (5)]), (yyvsp[(2) - (5)].identifier)); (yyval.interfaceDecl) = new InterfaceDecl(id, (yyvsp[(4) - (5)].declList));}
    break;

  case 34:
#line 218 "parser.y"
    {((yyval.declList) = (yyvsp[(1) - (2)].declList))->Append((yyvsp[(2) - (2)].decl));}
    break;

  case 35:
#line 219 "parser.y"
    {(yyval.declList) = new List<Decl*>;}
    break;

  case 36:
#line 222 "parser.y"
    {Identifier *id = new Identifier((yylsp[(2) - (6)]), (yyvsp[(2) - (6)].identifier)); (yyval.decl) = new FnDecl(id, (yyvsp[(1) - (6)].type), (yyvsp[(4) - (6)].varList));}
    break;

  case 37:
#line 223 "parser.y"
    {Identifier *id = new Identifier((yylsp[(2) - (6)]), (yyvsp[(2) - (6)].identifier)); Type *tp = new Type(*Type::voidType); (yyval.decl) = new FnDecl(id, tp, (yyvsp[(4) - (6)].varList));}
    break;

  case 38:
#line 226 "parser.y"
    {(yyval.stmtBlock) = new StmtBlock((yyvsp[(2) - (4)].varList), (yyvsp[(3) - (4)].stmtList));}
    break;

  case 39:
#line 229 "parser.y"
    {((yyval.stmtList) = (yyvsp[(1) - (2)].stmtList))->Append((yyvsp[(2) - (2)].stmt));}
    break;

  case 40:
#line 230 "parser.y"
    {((yyval.stmtList) = new List<Stmt*>)->Append((yyvsp[(1) - (1)].stmt));}
    break;

  case 41:
#line 234 "parser.y"
    {(yyval.stmt) = (yyvsp[(1) - (2)].expr);}
    break;

  case 42:
#line 235 "parser.y"
    {(yyval.stmt) = (yyvsp[(1) - (1)].ifStmt);}
    break;

  case 43:
#line 236 "parser.y"
    {(yyval.stmt) = (yyvsp[(1) - (1)].whileStmt);}
    break;

  case 44:
#line 237 "parser.y"
    {(yyval.stmt) = (yyvsp[(1) - (1)].forStmt);}
    break;

  case 45:
#line 238 "parser.y"
    {(yyval.stmt) = (yyvsp[(1) - (1)].breakStmt);}
    break;

  case 46:
#line 239 "parser.y"
    {(yyval.stmt) = (yyvsp[(1) - (1)].returnStmt);}
    break;

  case 47:
#line 240 "parser.y"
    {(yyval.stmt) = (yyvsp[(1) - (1)].printStmt);}
    break;

  case 48:
#line 241 "parser.y"
    {(yyval.stmt) = (yyvsp[(1) - (1)].stmtBlock);}
    break;

  case 49:
#line 244 "parser.y"
    {(yyval.stmt) = (yyvsp[(2) - (2)].stmt);}
    break;

  case 50:
#line 245 "parser.y"
    {(yyval.stmt) = NULL;}
    break;

  case 51:
#line 248 "parser.y"
    {(yyval.ifStmt) = new IfStmt((yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].stmt), NULL);}
    break;

  case 52:
#line 249 "parser.y"
    {(yyval.ifStmt) = new IfStmt((yyvsp[(3) - (6)].expr), (yyvsp[(5) - (6)].stmt), (yyvsp[(6) - (6)].stmt));}
    break;

  case 53:
#line 252 "parser.y"
    {(yyval.whileStmt) = new WhileStmt((yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].stmt));}
    break;

  case 54:
#line 255 "parser.y"
    {(yyval.forStmt) = new ForStmt((yyvsp[(3) - (9)].expr), (yyvsp[(5) - (9)].expr), (yyvsp[(7) - (9)].expr), (yyvsp[(9) - (9)].stmt));}
    break;

  case 55:
#line 258 "parser.y"
    {(yyval.returnStmt) = new ReturnStmt((yylsp[(1) - (2)]), NULL);}
    break;

  case 56:
#line 259 "parser.y"
    {(yyval.returnStmt) = new ReturnStmt((yylsp[(1) - (5)]), (yyvsp[(3) - (5)].expr));}
    break;

  case 57:
#line 262 "parser.y"
    {(yyval.breakStmt) = new BreakStmt((yylsp[(1) - (2)]));}
    break;

  case 58:
#line 265 "parser.y"
    {(yyval.printStmt) = new PrintStmt((yyvsp[(3) - (5)].exprList));}
    break;

  case 59:
#line 268 "parser.y"
    {((yyval.exprList) = (yyvsp[(1) - (3)].exprList))->Append((yyvsp[(3) - (3)].expr));}
    break;

  case 60:
#line 269 "parser.y"
    {((yyval.exprList) = new List<Expr*>)->Append((yyvsp[(1) - (1)].expr));}
    break;

  case 61:
#line 272 "parser.y"
    {(yyval.expr) = (yyvsp[(1) - (1)].expr);}
    break;

  case 62:
#line 273 "parser.y"
    {(yyval.expr) = new EmptyExpr;}
    break;

  case 63:
#line 277 "parser.y"
    {Operator *op = new Operator((yylsp[(2) - (3)]), "=");}
    break;

  case 64:
#line 278 "parser.y"
    {(yyval.expr) = (yyvsp[(1) - (1)].expr);}
    break;

  case 65:
#line 279 "parser.y"
    {(yyval.expr) = (yyvsp[(1) - (1)].lvalue);}
    break;

  case 66:
#line 280 "parser.y"
    {(yyval.expr) = new This((yylsp[(1) - (1)]));}
    break;

  case 67:
#line 281 "parser.y"
    {(yyval.expr) = (yyvsp[(1) - (1)].expr);}
    break;

  case 68:
#line 282 "parser.y"
    {(yyval.expr) = (yyvsp[(2) - (3)].expr);}
    break;

  case 69:
#line 283 "parser.y"
    {Operator *op = new Operator((yylsp[(2) - (3)]), "+"); (yyval.expr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));}
    break;

  case 70:
#line 284 "parser.y"
    {Operator *op = new Operator((yylsp[(2) - (3)]), "-"); (yyval.expr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));}
    break;

  case 71:
#line 285 "parser.y"
    {Operator *op = new Operator((yylsp[(2) - (3)]), "*"); (yyval.expr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));}
    break;

  case 72:
#line 286 "parser.y"
    {Operator *op = new Operator((yylsp[(2) - (3)]), "/"); (yyval.expr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));}
    break;

  case 73:
#line 287 "parser.y"
    {Operator *op = new Operator((yylsp[(2) - (3)]), "%"); (yyval.expr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));}
    break;

  case 74:
#line 288 "parser.y"
    {Operator *op = new Operator((yylsp[(1) - (2)]), "-"); (yyval.expr) = new ArithmeticExpr(op, (yyvsp[(2) - (2)].expr));}
    break;

  case 75:
#line 289 "parser.y"
    {Operator *op = new Operator((yylsp[(2) - (3)]), "<"); (yyval.expr) = new RelationalExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));}
    break;

  case 76:
#line 290 "parser.y"
    {Operator *op = new Operator((yylsp[(2) - (3)]), "<="); (yyval.expr) = new RelationalExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));}
    break;

  case 77:
#line 291 "parser.y"
    {Operator *op = new Operator((yylsp[(2) - (3)]), ">"); (yyval.expr) = new RelationalExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));}
    break;

  case 78:
#line 292 "parser.y"
    {Operator *op = new Operator((yylsp[(2) - (3)]), ">="); (yyval.expr) = new RelationalExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));}
    break;

  case 79:
#line 293 "parser.y"
    {Operator *op = new Operator((yylsp[(2) - (3)]), "=="); (yyval.expr) = new EqualityExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));}
    break;

  case 80:
#line 294 "parser.y"
    {Operator *op = new Operator((yylsp[(2) - (3)]), "!="); (yyval.expr) = new EqualityExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));}
    break;

  case 81:
#line 295 "parser.y"
    {Operator *op = new Operator((yylsp[(2) - (3)]), "&&"); (yyval.expr) = new LogicalExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));}
    break;

  case 82:
#line 296 "parser.y"
    {Operator *op = new Operator((yylsp[(2) - (3)]), "||"); (yyval.expr) = new LogicalExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));}
    break;

  case 83:
#line 297 "parser.y"
    {Operator *op = new Operator((yylsp[(1) - (2)]), "!"); (yyval.expr) = new LogicalExpr(op, (yyvsp[(2) - (2)].expr));}
    break;

  case 84:
#line 298 "parser.y"
    {(yyval.expr) = new ReadIntegerExpr((yylsp[(1) - (3)]));}
    break;

  case 85:
#line 299 "parser.y"
    {(yyval.expr) = new ReadLineExpr((yylsp[(1) - (3)]));}
    break;

  case 86:
#line 300 "parser.y"
    {Identifier *id = new Identifier((yylsp[(2) - (2)]), (yyvsp[(2) - (2)].identifier)); NamedType *nt = new NamedType(id); (yyval.expr) = new NewExpr((yylsp[(1) - (2)]), nt);}
    break;

  case 87:
#line 304 "parser.y"
    {Identifier *id = new Identifier((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].identifier)); (yyval.lvalue) = new FieldAccess(NULL, id);}
    break;

  case 88:
#line 305 "parser.y"
    {Identifier *id = new Identifier((yylsp[(3) - (3)]), (yyvsp[(3) - (3)].identifier)); (yyval.lvalue) = new FieldAccess((yyvsp[(1) - (3)].expr), id);}
    break;

  case 89:
#line 306 "parser.y"
    {(yyval.lvalue) = new ArrayAccess((yylsp[(1) - (4)]), (yyvsp[(1) - (4)].expr), (yyvsp[(3) - (4)].expr));}
    break;

  case 90:
#line 309 "parser.y"
    {Identifier *id = new Identifier((yylsp[(1) - (4)]), (yyvsp[(1) - (4)].identifier)); (yyval.expr) = new Call((yylsp[(1) - (4)]), NULL, id, (yyvsp[(3) - (4)].exprList));}
    break;

  case 91:
#line 310 "parser.y"
    {Identifier *id = new Identifier((yylsp[(3) - (6)]), (yyvsp[(3) - (6)].identifier)); (yyval.expr) = new Call((yylsp[(2) - (6)]), (yyvsp[(1) - (6)].expr), id, (yyvsp[(5) - (6)].exprList));}
    break;

  case 92:
#line 313 "parser.y"
    {(yyval.exprList) = (yyvsp[(1) - (1)].exprList);}
    break;

  case 93:
#line 314 "parser.y"
    {(yyval.exprList) = new List<Expr*>;}
    break;

  case 94:
#line 317 "parser.y"
    {(yyval.expr) = new IntConstant((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].integerConstant));}
    break;

  case 95:
#line 318 "parser.y"
    {(yyval.expr) = new DoubleConstant((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].doubleConstant));}
    break;

  case 96:
#line 319 "parser.y"
    {(yyval.expr) = new BoolConstant((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].boolConstant));}
    break;

  case 97:
#line 320 "parser.y"
    {(yyval.expr) = new StringConstant((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].stringConstant));}
    break;

  case 98:
#line 321 "parser.y"
    {(yyval.expr) = new NullConstant((yylsp[(1) - (1)]));}
    break;


/* Line 1267 of yacc.c.  */
#line 2170 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[0] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 323 "parser.y"


/* The closing %% above marks the end of the Rules section and the beginning
 * of the User Subroutines section. All text from here to the end of the
 * file is copied verbatim to the end of the generated y.tab.c file.
 * This section is where you put definitions of helper functions.
 */

/* Function: InitParser
 * --------------------
 * This function will be called before any calls to yyparse().  It is designed
 * to give you an opportunity to do anything that must be done to initialize
 * the parser (set global variables, configure starting state, etc.). One
 * thing it already does for you is assign the value of the global variable
 * yydebug that controls whether yacc prints debugging information about
 * parser actions (shift/reduce) and contents of state stack during parser.
 * If set to false, no information is printed. Setting it to true will give
 * you a running trail that might be helpful when debugging your parser.
 * Please be sure the variable is set to false when submitting your final
 * version.
 */
void InitParser()
{
   PrintDebug("parser", "Initializing parser");
   yydebug = false;
}

