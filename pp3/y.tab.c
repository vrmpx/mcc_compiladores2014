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
     T_Default = 287,
     T_Case = 288,
     T_Identifier = 289,
     T_StringConstant = 290,
     T_IntConstant = 291,
     T_DoubleConstant = 292,
     T_BoolConstant = 293,
     T_UnaryMinus = 294,
     T_Lower_Than_Else = 295
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
#define T_Default 287
#define T_Case 288
#define T_Identifier 289
#define T_StringConstant 290
#define T_IntConstant 291
#define T_DoubleConstant 292
#define T_BoolConstant 293
#define T_UnaryMinus 294
#define T_Lower_Than_Else 295




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
    int            integerConstant;
    bool           boolConstant;
    char*          stringConstant;
    double         doubleConstant;
    char           identifier[MaxIdentLen+1]; // +1 for terminating null
    Decl*          decl;
    FnDecl*        fnDecl;
    List< Decl* >*      declList;
    Type*               varType;
    VarDecl*            varDecl;
    InterfaceDecl*      interfaceDecl;
    List< Decl* >*      prototypeList;
    List< VarDecl* >*   varDeclList;
    StmtBlock*          stmtBlock;
    Stmt*               stmt;
    List< Stmt* >*      stmtList;
    Expr*               expr;
    List< Expr* >*      exprList;
    Call*               call;
    WhileStmt*          whileStmt;
    ForStmt*            forStmt;
    ReturnStmt*         returnStmt;
    IfStmt*             ifStmt;
    PrintStmt*          printStmt;
    ClassDecl*          classDecl;
    List< NamedType* >* interfaceList;
    NamedType*          namedType;

}
/* Line 193 of yacc.c.  */
#line 223 "y.tab.c"
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
#line 248 "y.tab.c"

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
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   490

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNRULES -- Number of states.  */
#define YYNSTATES  197

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,     2,     2,     2,    46,     2,     2,
      54,    55,    44,    42,    53,    43,    49,    45,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    52,
      40,    39,    41,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    50,     2,    58,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    56,     2,    57,     2,     2,     2,     2,
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
      35,    36,    37,    38,    48,    51
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    16,    18,
      21,    24,    28,    30,    32,    34,    36,    38,    40,    43,
      49,    55,    58,    60,    61,    69,    72,    73,    76,    77,
      81,    83,    86,    87,    89,    91,    97,   100,   101,   108,
     115,   120,   123,   124,   127,   128,   131,   133,   135,   137,
     139,   142,   144,   146,   152,   160,   166,   176,   178,   179,
     183,   189,   193,   195,   199,   201,   203,   205,   207,   211,
     215,   219,   223,   227,   231,   234,   238,   242,   246,   250,
     254,   258,   262,   266,   269,   273,   277,   282,   289,   291,
     295,   300,   305,   312,   314,   315,   317,   319,   321,   323
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      60,     0,    -1,    61,    -1,    61,    62,    -1,    62,    -1,
      63,    -1,    76,    -1,    70,    -1,    68,    -1,    64,    52,
      -1,    66,    34,    -1,    65,    53,    64,    -1,    64,    -1,
       5,    -1,     6,    -1,     4,    -1,     7,    -1,    34,    -1,
      66,    13,    -1,    66,    34,    54,    69,    55,    -1,     3,
      34,    54,    69,    55,    -1,    67,    79,    -1,    65,    -1,
      -1,     8,    34,    71,    72,    56,    74,    57,    -1,    17,
      34,    -1,    -1,    20,    73,    -1,    -1,    73,    53,    34,
      -1,    34,    -1,    75,    74,    -1,    -1,    63,    -1,    68,
      -1,    19,    34,    56,    77,    57,    -1,    78,    77,    -1,
      -1,    66,    34,    54,    69,    55,    52,    -1,     3,    34,
      54,    69,    55,    52,    -1,    56,    80,    81,    57,    -1,
      80,    63,    -1,    -1,    82,    81,    -1,    -1,    86,    52,
      -1,    79,    -1,    83,    -1,    84,    -1,    85,    -1,    26,
      52,    -1,    87,    -1,    88,    -1,    23,    54,    90,    55,
      82,    -1,    23,    54,    90,    55,    82,    24,    82,    -1,
      21,    54,    90,    55,    82,    -1,    22,    54,    86,    52,
      90,    52,    86,    55,    82,    -1,    90,    -1,    -1,    25,
      86,    52,    -1,    29,    54,    89,    55,    52,    -1,    89,
      53,    90,    -1,    90,    -1,    91,    39,    90,    -1,    94,
      -1,    91,    -1,    18,    -1,    92,    -1,    54,    90,    55,
      -1,    90,    42,    90,    -1,    90,    43,    90,    -1,    90,
      44,    90,    -1,    90,    45,    90,    -1,    90,    46,    90,
      -1,    43,    90,    -1,    90,    40,    90,    -1,    90,     9,
      90,    -1,    90,    41,    90,    -1,    90,    10,    90,    -1,
      90,    11,    90,    -1,    90,    12,    90,    -1,    90,    14,
      90,    -1,    90,    15,    90,    -1,    47,    90,    -1,    30,
      54,    55,    -1,    31,    54,    55,    -1,    27,    54,    34,
      55,    -1,    28,    54,    90,    53,    66,    55,    -1,    34,
      -1,    90,    49,    34,    -1,    90,    50,    90,    58,    -1,
      34,    54,    93,    55,    -1,    90,    49,    34,    54,    93,
      55,    -1,    89,    -1,    -1,    36,    -1,    37,    -1,    38,
      -1,    35,    -1,    16,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   160,   160,   172,   173,   176,   177,   178,   179,   182,
     185,   191,   192,   195,   196,   197,   198,   199,   203,   206,
     210,   216,   219,   220,   223,   228,   229,   232,   233,   237,
     238,   241,   242,   245,   246,   249,   255,   256,   259,   263,
     266,   269,   270,   273,   274,   278,   279,   280,   281,   282,
     283,   284,   285,   289,   290,   293,   295,   298,   299,   302,
     305,   308,   309,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   335,   339,   343,   344,
     345,   348,   351,   357,   358,   361,   362,   363,   364,   365
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
  "T_ReadLine", "T_Default", "T_Case", "T_Identifier", "T_StringConstant",
  "T_IntConstant", "T_DoubleConstant", "T_BoolConstant", "'='", "'<'",
  "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "T_UnaryMinus", "'.'",
  "'['", "T_Lower_Than_Else", "';'", "','", "'('", "')'", "'{'", "'}'",
  "']'", "$accept", "Program", "DecP", "Declaration", "VariableDecl",
  "Variable", "VarPC", "Type", "FunctionHead", "FunctionDecl", "Formals",
  "ClassDecl", "Extends01", "Implements01", "IdentifierPC", "FieldA",
  "Field", "InterfaceDecl", "PrototypeA", "Prototype", "StmtBlock",
  "VariableDeclA", "StmtA", "Stmt", "IfStmt", "WhileStmt", "ForStmt",
  "Expr01", "ReturnStmt", "PrintStmt", "ExprPC", "Expr", "LValue", "Call",
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,    61,
      60,    62,    43,    45,    42,    47,    37,    33,   294,    46,
      91,   295,    59,    44,    40,    41,   123,   125,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    61,    61,    62,    62,    62,    62,    63,
      64,    65,    65,    66,    66,    66,    66,    66,    66,    67,
      67,    68,    69,    69,    70,    71,    71,    72,    72,    73,
      73,    74,    74,    75,    75,    76,    77,    77,    78,    78,
      79,    80,    80,    81,    81,    82,    82,    82,    82,    82,
      82,    82,    82,    83,    83,    84,    85,    86,    86,    87,
      88,    89,    89,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    91,    91,
      91,    92,    92,    93,    93,    94,    94,    94,    94,    94
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     2,
       2,     3,     1,     1,     1,     1,     1,     1,     2,     5,
       5,     2,     1,     0,     7,     2,     0,     2,     0,     3,
       1,     2,     0,     1,     1,     5,     2,     0,     6,     6,
       4,     2,     0,     2,     0,     2,     1,     1,     1,     1,
       2,     1,     1,     5,     7,     5,     9,     1,     0,     3,
       5,     3,     1,     3,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     3,     3,     4,     6,     1,     3,
       4,     4,     6,     1,     0,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    15,    13,    14,    16,     0,     0,    17,     0,
       2,     4,     5,     0,     0,     0,     8,     7,     6,     0,
      26,     0,     1,     3,     9,    18,    10,    42,    21,    23,
       0,    28,    37,    23,    44,    12,    22,     0,     0,    25,
       0,     0,     0,     0,     0,    37,     0,    99,    66,     0,
       0,     0,    58,     0,     0,     0,     0,     0,     0,    88,
      98,    95,    96,    97,     0,     0,     0,    41,    46,     0,
      44,    47,    48,    49,     0,    51,    52,    57,    65,    67,
      64,     0,    10,    20,    30,    27,    32,     0,     0,    35,
      36,    19,     0,    58,     0,    88,     0,    50,     0,     0,
       0,     0,     0,    94,    74,    83,     0,    40,    43,    45,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,     0,    33,    34,
       0,    32,    23,    23,     0,     0,     0,    59,     0,     0,
       0,    62,    84,    85,    93,     0,    68,    76,    78,    79,
      80,    81,    82,    75,    77,    69,    70,    71,    72,    73,
      89,     0,    63,    29,    24,    31,     0,     0,    58,     0,
      58,    86,     0,     0,     0,    91,    94,    90,     0,     0,
      55,     0,    53,     0,    61,    60,     0,    39,    38,    58,
      58,    87,    92,     0,    54,    58,    56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    10,    11,    12,    13,    36,    37,    15,    16,
      38,    17,    31,    41,    85,   130,   131,    18,    44,    45,
      68,    34,    69,    70,    71,    72,    73,    74,    75,    76,
     144,    77,    78,    79,   145,    80
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -160
static const yytype_int16 yypact[] =
{
      77,   -10,  -160,  -160,  -160,  -160,    -6,    -4,  -160,    17,
      77,  -160,  -160,   -18,     5,   -13,  -160,  -160,  -160,    21,
      59,    23,  -160,  -160,  -160,  -160,    34,  -160,  -160,    93,
      55,    70,    16,    93,   114,  -160,    50,    13,    49,  -160,
      71,    51,    72,    74,    52,    16,    58,  -160,  -160,    80,
      92,   106,   436,    81,   108,   109,   110,   111,   113,    -5,
    -160,  -160,  -160,  -160,   436,   436,   436,  -160,  -160,    69,
     369,  -160,  -160,  -160,    95,  -160,  -160,   292,   130,  -160,
    -160,    93,  -160,  -160,  -160,   118,    88,   123,   126,  -160,
    -160,  -160,   436,   436,   436,   127,   131,  -160,   148,   436,
     436,   136,   137,   436,   -36,   -36,   164,  -160,  -160,  -160,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   165,   436,   436,  -160,   169,  -160,  -160,
     154,    88,    93,    93,   186,   160,   206,  -160,   167,   228,
     -28,   292,  -160,  -160,   170,   178,  -160,    28,    28,   315,
     315,   334,   273,    28,    28,    79,    79,   -36,   -36,   -36,
     171,   144,   292,  -160,  -160,  -160,   179,   189,   406,   436,
     406,  -160,    93,   436,   172,  -160,   436,  -160,   193,   201,
    -160,   248,   230,    -9,   292,  -160,   209,  -160,  -160,   436,
     406,  -160,  -160,   210,  -160,   406,  -160
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -160,  -160,  -160,   256,   -19,   -17,  -160,     0,  -160,   -83,
     -31,  -160,  -160,  -160,  -160,   145,  -160,  -160,   222,  -160,
     260,  -160,   216,  -159,  -160,  -160,  -160,   -51,  -160,  -160,
     180,   -59,  -160,  -160,   103,  -160
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -59
static const yytype_int16 yytable[] =
{
      14,    96,    46,   129,    25,   104,   105,   106,   -17,   180,
      14,   182,    35,   123,   124,    67,    35,    22,    25,    42,
       2,     3,     4,     5,    19,   173,    25,   174,    20,   -17,
      21,   194,    43,   134,    24,   136,   196,   -59,   -59,    26,
     139,   141,   135,    27,   141,    43,   191,    82,   129,   103,
       8,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   126,   161,   162,   128,   -59,   -59,
     118,   119,   120,   121,   122,    29,    30,   123,   124,    32,
       1,     2,     3,     4,     5,     6,    14,    25,    33,    39,
      40,     1,     2,     3,     4,     5,     7,     2,     3,     4,
       5,   166,   167,    81,    83,    84,    87,    86,    88,    89,
     181,     8,   128,    91,   184,    35,    35,   141,     2,     3,
       4,     5,     8,   120,   121,   122,   107,     8,   123,   124,
      47,    14,    48,    97,    92,    49,    50,    51,   193,    52,
      53,    54,    55,    56,    57,    58,    93,   109,    59,    60,
      61,    62,    63,   110,   111,   112,   113,    64,   114,   115,
      94,    65,    98,    99,   100,   101,   -58,   102,    66,   125,
      27,   127,   183,   110,   111,   112,   113,   132,   114,   115,
     133,   103,   138,   137,   116,   117,   118,   119,   120,   121,
     122,   142,   143,   123,   124,   110,   111,   112,   113,   160,
     114,   115,   177,   163,   116,   117,   118,   119,   120,   121,
     122,   164,   169,   123,   124,   110,   111,   112,   113,   146,
     114,   115,   171,   173,   185,   176,   116,   117,   118,   119,
     120,   121,   122,   175,   178,   123,   124,   110,   111,   112,
     113,   168,   114,   115,   179,   187,   116,   117,   118,   119,
     120,   121,   122,   188,   190,   123,   124,   110,   111,   112,
     113,   170,   114,   115,   192,   195,    23,    90,   116,   117,
     118,   119,   120,   121,   122,    28,   165,   123,   124,   186,
     140,   172,   110,   111,   112,   113,   108,   114,   116,   117,
     118,   119,   120,   121,   122,     0,     0,   123,   124,     0,
     189,   110,   111,   112,   113,     0,   114,   115,     0,     0,
       0,     0,     0,   116,   117,   118,   119,   120,   121,   122,
       0,     0,   123,   124,   110,   111,   -59,   -59,     0,     0,
       0,     0,   116,   117,   118,   119,   120,   121,   122,     0,
       0,   123,   124,   110,   111,   112,   113,     0,     0,     0,
       0,     0,     0,     0,     0,   116,   117,   118,   119,   120,
     121,   122,     0,     0,   123,   124,     0,     0,     0,     0,
       0,     0,     0,     0,   116,   117,   118,   119,   120,   121,
     122,     0,     0,   123,   124,    47,     0,    48,     0,     0,
      49,    50,    51,     0,    52,    53,    54,    55,    56,    57,
      58,     0,     0,    95,    60,    61,    62,    63,     0,     0,
       0,     0,    64,     0,     0,     0,    65,     0,     0,     0,
       0,   -58,    47,    66,    48,    27,     0,    49,    50,    51,
       0,    52,    53,    54,    55,    56,    57,    58,     0,     0,
      95,    60,    61,    62,    63,     0,     0,     0,     0,    64,
       0,     0,    47,    65,    48,     0,     0,     0,     0,     0,
      66,     0,    27,    54,    55,     0,    57,    58,     0,     0,
      95,    60,    61,    62,    63,     0,     0,     0,     0,    64,
       0,     0,     0,    65,     0,     0,     0,     0,     0,     0,
      66
};

static const yytype_int16 yycheck[] =
{
       0,    52,    33,    86,    13,    64,    65,    66,    13,   168,
      10,   170,    29,    49,    50,    34,    33,     0,    13,     3,
       4,     5,     6,     7,    34,    53,    13,    55,    34,    34,
      34,   190,    32,    92,    52,    94,   195,     9,    10,    34,
      99,   100,    93,    56,   103,    45,    55,    34,   131,    54,
      34,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,    81,   124,   125,    86,    40,    41,
      42,    43,    44,    45,    46,    54,    17,    49,    50,    56,
       3,     4,     5,     6,     7,     8,    86,    13,    54,    34,
      20,     3,     4,     5,     6,     7,    19,     4,     5,     6,
       7,   132,   133,    53,    55,    34,    34,    56,    34,    57,
     169,    34,   131,    55,   173,   132,   133,   176,     4,     5,
       6,     7,    34,    44,    45,    46,    57,    34,    49,    50,
      16,   131,    18,    52,    54,    21,    22,    23,   189,    25,
      26,    27,    28,    29,    30,    31,    54,    52,    34,    35,
      36,    37,    38,     9,    10,    11,    12,    43,    14,    15,
      54,    47,    54,    54,    54,    54,    52,    54,    54,    39,
      56,    53,   172,     9,    10,    11,    12,    54,    14,    15,
      54,    54,    34,    52,    40,    41,    42,    43,    44,    45,
      46,    55,    55,    49,    50,     9,    10,    11,    12,    34,
      14,    15,    58,    34,    40,    41,    42,    43,    44,    45,
      46,    57,    52,    49,    50,     9,    10,    11,    12,    55,
      14,    15,    55,    53,    52,    54,    40,    41,    42,    43,
      44,    45,    46,    55,    55,    49,    50,     9,    10,    11,
      12,    55,    14,    15,    55,    52,    40,    41,    42,    43,
      44,    45,    46,    52,    24,    49,    50,     9,    10,    11,
      12,    55,    14,    15,    55,    55,    10,    45,    40,    41,
      42,    43,    44,    45,    46,    15,   131,    49,    50,   176,
     100,    53,     9,    10,    11,    12,    70,    14,    40,    41,
      42,    43,    44,    45,    46,    -1,    -1,    49,    50,    -1,
      52,     9,    10,    11,    12,    -1,    14,    15,    -1,    -1,
      -1,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      -1,    -1,    49,    50,     9,    10,    11,    12,    -1,    -1,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    -1,
      -1,    49,    50,     9,    10,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    41,    42,    43,    44,
      45,    46,    -1,    -1,    49,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,    49,    50,    16,    -1,    18,    -1,    -1,
      21,    22,    23,    -1,    25,    26,    27,    28,    29,    30,
      31,    -1,    -1,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    43,    -1,    -1,    -1,    47,    -1,    -1,    -1,
      -1,    52,    16,    54,    18,    56,    -1,    21,    22,    23,
      -1,    25,    26,    27,    28,    29,    30,    31,    -1,    -1,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    43,
      -1,    -1,    16,    47,    18,    -1,    -1,    -1,    -1,    -1,
      54,    -1,    56,    27,    28,    -1,    30,    31,    -1,    -1,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    43,
      -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      54
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    19,    34,    60,
      61,    62,    63,    64,    66,    67,    68,    70,    76,    34,
      34,    34,     0,    62,    52,    13,    34,    56,    79,    54,
      17,    71,    56,    54,    80,    64,    65,    66,    69,    34,
      20,    72,     3,    66,    77,    78,    69,    16,    18,    21,
      22,    23,    25,    26,    27,    28,    29,    30,    31,    34,
      35,    36,    37,    38,    43,    47,    54,    63,    79,    81,
      82,    83,    84,    85,    86,    87,    88,    90,    91,    92,
      94,    53,    34,    55,    34,    73,    56,    34,    34,    57,
      77,    55,    54,    54,    54,    34,    86,    52,    54,    54,
      54,    54,    54,    54,    90,    90,    90,    57,    81,    52,
       9,    10,    11,    12,    14,    15,    40,    41,    42,    43,
      44,    45,    46,    49,    50,    39,    64,    53,    63,    68,
      74,    75,    54,    54,    90,    86,    90,    52,    34,    90,
      89,    90,    55,    55,    89,    93,    55,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      34,    90,    90,    34,    57,    74,    69,    69,    55,    52,
      55,    55,    53,    53,    55,    55,    54,    58,    55,    55,
      82,    90,    82,    66,    90,    52,    93,    52,    52,    52,
      24,    55,    55,    86,    82,    55,    82
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
#line 160 "parser.y"
    { 
                                      (yylsp[(1) - (1)]); 
                                      /* pp2: The @1 is needed to convince 
                                       * yacc to set up yylloc. You can remove 
                                       * it once you have other uses of @n*/
                                      Program *program = new Program((yyvsp[(1) - (1)].declList));
                                      // if no errors, advance to next phase
                                      if(ReportError::NumErrors() == 0) 
                                        program->Check();
                                }
    break;

  case 3:
#line 172 "parser.y"
    { ((yyval.declList)=(yyvsp[(1) - (2)].declList))->Append((yyvsp[(2) - (2)].decl)); }
    break;

  case 4:
#line 173 "parser.y"
    { ((yyval.declList) = new List<Decl*>)->Append((yyvsp[(1) - (1)].decl)); }
    break;

  case 5:
#line 176 "parser.y"
    { (yyval.decl) = (yyvsp[(1) - (1)].varDecl); }
    break;

  case 6:
#line 177 "parser.y"
    { (yyval.decl) = (yyvsp[(1) - (1)].interfaceDecl); }
    break;

  case 7:
#line 178 "parser.y"
    { (yyval.decl) = (yyvsp[(1) - (1)].classDecl); }
    break;

  case 8:
#line 179 "parser.y"
    { (yyval.decl) = (yyvsp[(1) - (1)].fnDecl); }
    break;

  case 9:
#line 182 "parser.y"
    { (yyval.varDecl) = (yyvsp[(1) - (2)].varDecl); }
    break;

  case 10:
#line 185 "parser.y"
    { 
                                    Identifier *varName = new Identifier((yylsp[(2) - (2)]), (yyvsp[(2) - (2)].identifier));
                                    (yyval.varDecl) = new VarDecl( varName, (yyvsp[(1) - (2)].varType) );
                                  }
    break;

  case 11:
#line 191 "parser.y"
    { ((yyval.varDeclList) = (yyvsp[(1) - (3)].varDeclList))->Append((yyvsp[(3) - (3)].varDecl)); }
    break;

  case 12:
#line 192 "parser.y"
    { ((yyval.varDeclList) = new List<VarDecl *>) -> Append((yyvsp[(1) - (1)].varDecl)); }
    break;

  case 13:
#line 195 "parser.y"
    { (yyval.varType) = Type::intType; }
    break;

  case 14:
#line 196 "parser.y"
    { (yyval.varType) = Type::doubleType; }
    break;

  case 15:
#line 197 "parser.y"
    { (yyval.varType) = Type::boolType; }
    break;

  case 16:
#line 198 "parser.y"
    { (yyval.varType) = Type::stringType; }
    break;

  case 17:
#line 199 "parser.y"
    {
                                Identifier *id = new Identifier((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].identifier));
                                (yyval.varType) = new NamedType(id);
                              }
    break;

  case 18:
#line 203 "parser.y"
    { (yyval.varType) = new ArrayType((yylsp[(1) - (2)]), (yyvsp[(1) - (2)].varType)); }
    break;

  case 19:
#line 206 "parser.y"
    {
                                                                    Identifier *id = new Identifier((yylsp[(2) - (5)]), (yyvsp[(2) - (5)].identifier));
                                                                    (yyval.fnDecl) = new FnDecl(id, (yyvsp[(1) - (5)].varType), (yyvsp[(4) - (5)].varDeclList));
                                                                }
    break;

  case 20:
#line 210 "parser.y"
    {
                                                                    Identifier *id = new Identifier((yylsp[(2) - (5)]), (yyvsp[(2) - (5)].identifier));
                                                                    (yyval.fnDecl) = new FnDecl(id, Type::voidType, (yyvsp[(4) - (5)].varDeclList));
                                                                }
    break;

  case 21:
#line 216 "parser.y"
    { ((yyval.fnDecl)=(yyvsp[(1) - (2)].fnDecl))->SetFunctionBody((yyvsp[(2) - (2)].stmtBlock)); }
    break;

  case 22:
#line 219 "parser.y"
    { (yyval.varDeclList) = (yyvsp[(1) - (1)].varDeclList); }
    break;

  case 23:
#line 220 "parser.y"
    { (yyval.varDeclList) = new List<VarDecl *>; }
    break;

  case 24:
#line 223 "parser.y"
    {
                                                                                Identifier *id = new Identifier((yylsp[(2) - (7)]), (yyvsp[(2) - (7)].identifier));
                                                                                (yyval.classDecl) = new ClassDecl(id, (yyvsp[(3) - (7)].namedType), (yyvsp[(4) - (7)].interfaceList), (yyvsp[(6) - (7)].declList));
                                                                            }
    break;

  case 25:
#line 228 "parser.y"
    { Identifier *id = new Identifier((yylsp[(2) - (2)]),(yyvsp[(2) - (2)].identifier)); (yyval.namedType) = new NamedType(id); }
    break;

  case 26:
#line 229 "parser.y"
    { (yyval.namedType) = NULL; }
    break;

  case 27:
#line 232 "parser.y"
    { (yyval.interfaceList) = (yyvsp[(2) - (2)].interfaceList); }
    break;

  case 28:
#line 233 "parser.y"
    { (yyval.interfaceList) = new List<NamedType *>();}
    break;

  case 29:
#line 237 "parser.y"
    { ((yyval.interfaceList) = (yyvsp[(1) - (3)].interfaceList))->Append(new NamedType(new Identifier((yylsp[(3) - (3)]), (yyvsp[(3) - (3)].identifier)))); }
    break;

  case 30:
#line 238 "parser.y"
    { ((yyval.interfaceList) = new List<NamedType*>)->Append(new NamedType(new Identifier((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].identifier)))); }
    break;

  case 31:
#line 241 "parser.y"
    { ((yyval.declList) = (yyvsp[(2) - (2)].declList))->InsertAt((yyvsp[(1) - (2)].decl), 0); }
    break;

  case 32:
#line 242 "parser.y"
    { (yyval.declList) = new List< Decl* >(); }
    break;

  case 33:
#line 245 "parser.y"
    { (yyval.decl) = (yyvsp[(1) - (1)].varDecl); }
    break;

  case 34:
#line 246 "parser.y"
    { (yyval.decl) = (yyvsp[(1) - (1)].fnDecl); }
    break;

  case 35:
#line 249 "parser.y"
    {
                                                                  Identifier *id = new Identifier((yylsp[(2) - (5)]), (yyvsp[(2) - (5)].identifier));
                                                                  (yyval.interfaceDecl) = new InterfaceDecl (id, (yyvsp[(4) - (5)].prototypeList));
                                                               }
    break;

  case 36:
#line 255 "parser.y"
    { ((yyval.prototypeList) = (yyvsp[(2) - (2)].prototypeList))->InsertAt((yyvsp[(1) - (2)].decl), 0); }
    break;

  case 37:
#line 256 "parser.y"
    { (yyval.prototypeList) = new List< Decl* >(); }
    break;

  case 38:
#line 259 "parser.y"
    {
                                                                  Identifier *id = new Identifier((yylsp[(2) - (6)]), (yyvsp[(2) - (6)].identifier));
                                                                  (yyval.decl) = new FnDecl(id, (yyvsp[(1) - (6)].varType), (yyvsp[(4) - (6)].varDeclList));
                                                           }
    break;

  case 39:
#line 263 "parser.y"
    { (yyval.decl) = new FnDecl(new Identifier((yylsp[(2) - (6)]),(yyvsp[(2) - (6)].identifier)), Type::voidType, (yyvsp[(4) - (6)].varDeclList)); }
    break;

  case 40:
#line 266 "parser.y"
    {  (yyval.stmtBlock) = new StmtBlock((yyvsp[(2) - (4)].varDeclList), (yyvsp[(3) - (4)].stmtList)); }
    break;

  case 41:
#line 269 "parser.y"
    { ((yyval.varDeclList) = (yyvsp[(1) - (2)].varDeclList))->Append((yyvsp[(2) - (2)].varDecl)); }
    break;

  case 42:
#line 270 "parser.y"
    { (yyval.varDeclList) = new List< VarDecl* >(); }
    break;

  case 43:
#line 273 "parser.y"
    { ((yyval.stmtList) = (yyvsp[(2) - (2)].stmtList))->InsertAt((yyvsp[(1) - (2)].stmt), 0); }
    break;

  case 44:
#line 274 "parser.y"
    { (yyval.stmtList) = new List< Stmt* >(); }
    break;

  case 45:
#line 278 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (2)].expr); }
    break;

  case 46:
#line 279 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmtBlock); }
    break;

  case 47:
#line 280 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].ifStmt); }
    break;

  case 48:
#line 281 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].whileStmt); }
    break;

  case 49:
#line 282 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].forStmt); }
    break;

  case 50:
#line 283 "parser.y"
    { (yyval.stmt) = new BreakStmt((yylsp[(1) - (2)])); }
    break;

  case 51:
#line 284 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].returnStmt); }
    break;

  case 52:
#line 285 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].printStmt); }
    break;

  case 53:
#line 289 "parser.y"
    { (yyval.ifStmt) = new IfStmt((yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].stmt), NULL); }
    break;

  case 54:
#line 290 "parser.y"
    { (yyval.ifStmt) = new IfStmt((yyvsp[(3) - (7)].expr), (yyvsp[(5) - (7)].stmt), (yyvsp[(7) - (7)].stmt)); }
    break;

  case 55:
#line 293 "parser.y"
    { (yyval.whileStmt) = new WhileStmt((yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].stmt)); }
    break;

  case 56:
#line 295 "parser.y"
    { (yyval.forStmt) = new ForStmt((yyvsp[(3) - (9)].expr), (yyvsp[(5) - (9)].expr), (yyvsp[(7) - (9)].expr), (yyvsp[(9) - (9)].stmt)); }
    break;

  case 57:
#line 298 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); }
    break;

  case 58:
#line 299 "parser.y"
    { (yyval.expr) = new EmptyExpr(); }
    break;

  case 59:
#line 302 "parser.y"
    { (yyval.returnStmt) = new ReturnStmt((yylsp[(1) - (3)]), (yyvsp[(2) - (3)].expr)); }
    break;

  case 60:
#line 305 "parser.y"
    { (yyval.printStmt) = new PrintStmt((yyvsp[(3) - (5)].exprList)); }
    break;

  case 61:
#line 308 "parser.y"
    {((yyval.exprList) = (yyvsp[(1) - (3)].exprList)) -> Append((yyvsp[(3) - (3)].expr));}
    break;

  case 62:
#line 309 "parser.y"
    { ((yyval.exprList) = new List<Expr *>) -> Append((yyvsp[(1) - (1)].expr)); }
    break;

  case 63:
#line 312 "parser.y"
    { (yyval.expr) = new AssignExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]), "="), (yyvsp[(3) - (3)].expr)); }
    break;

  case 64:
#line 313 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); }
    break;

  case 65:
#line 314 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); }
    break;

  case 66:
#line 315 "parser.y"
    { (yyval.expr) = new This((yylsp[(1) - (1)])); }
    break;

  case 67:
#line 316 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].call); }
    break;

  case 68:
#line 317 "parser.y"
    { (yyval.expr) = (yyvsp[(2) - (3)].expr); }
    break;

  case 69:
#line 318 "parser.y"
    { (yyval.expr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]), "+"), (yyvsp[(3) - (3)].expr)); }
    break;

  case 70:
#line 319 "parser.y"
    { (yyval.expr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]), "-"), (yyvsp[(3) - (3)].expr)); }
    break;

  case 71:
#line 320 "parser.y"
    { (yyval.expr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]), "*"), (yyvsp[(3) - (3)].expr)); }
    break;

  case 72:
#line 321 "parser.y"
    { (yyval.expr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]), "/"), (yyvsp[(3) - (3)].expr)); }
    break;

  case 73:
#line 322 "parser.y"
    { (yyval.expr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]), "%"), (yyvsp[(3) - (3)].expr)); }
    break;

  case 74:
#line 323 "parser.y"
    { (yyval.expr) = new ArithmeticExpr(new Operator((yylsp[(1) - (2)]), "-"), (yyvsp[(2) - (2)].expr)); }
    break;

  case 75:
#line 324 "parser.y"
    { (yyval.expr) = new RelationalExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]), "<"), (yyvsp[(3) - (3)].expr)); }
    break;

  case 76:
#line 325 "parser.y"
    { (yyval.expr) = new RelationalExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]), "<="), (yyvsp[(3) - (3)].expr)); }
    break;

  case 77:
#line 326 "parser.y"
    { (yyval.expr) = new RelationalExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]), ">"), (yyvsp[(3) - (3)].expr)); }
    break;

  case 78:
#line 327 "parser.y"
    { (yyval.expr) = new RelationalExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]), ">="), (yyvsp[(3) - (3)].expr)); }
    break;

  case 79:
#line 328 "parser.y"
    { (yyval.expr) = new EqualityExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]), "=="), (yyvsp[(3) - (3)].expr)); }
    break;

  case 80:
#line 329 "parser.y"
    { (yyval.expr) = new EqualityExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]), "!="), (yyvsp[(3) - (3)].expr)); }
    break;

  case 81:
#line 330 "parser.y"
    { (yyval.expr) = new LogicalExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]), "&&"), (yyvsp[(3) - (3)].expr)); }
    break;

  case 82:
#line 331 "parser.y"
    { (yyval.expr) = new LogicalExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]), "||"), (yyvsp[(3) - (3)].expr)); }
    break;

  case 83:
#line 332 "parser.y"
    { (yyval.expr) = new LogicalExpr(new Operator((yylsp[(1) - (2)]), "!"), (yyvsp[(2) - (2)].expr)); }
    break;

  case 84:
#line 333 "parser.y"
    { (yyval.expr) = new ReadIntegerExpr((yylsp[(1) - (3)])); }
    break;

  case 85:
#line 334 "parser.y"
    { (yyval.expr) = new ReadLineExpr((yylsp[(1) - (3)])); }
    break;

  case 86:
#line 335 "parser.y"
    { 
                                            NamedType* newt = new NamedType(new Identifier((yylsp[(3) - (4)]), (yyvsp[(3) - (4)].identifier)));
                                            (yyval.expr) = new NewExpr((yylsp[(1) - (4)]), newt);
                                          }
    break;

  case 87:
#line 339 "parser.y"
    { (yyval.expr) = new NewArrayExpr((yylsp[(1) - (6)]), (yyvsp[(3) - (6)].expr), (yyvsp[(5) - (6)].varType));  }
    break;

  case 88:
#line 343 "parser.y"
    { (yyval.expr) = new FieldAccess(NULL, new Identifier((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].identifier))); }
    break;

  case 89:
#line 344 "parser.y"
    { (yyval.expr) = new FieldAccess((yyvsp[(1) - (3)].expr), new Identifier((yylsp[(3) - (3)]), (yyvsp[(3) - (3)].identifier))); }
    break;

  case 90:
#line 345 "parser.y"
    { (yyval.expr) = new ArrayAccess((yylsp[(1) - (4)]), (yyvsp[(1) - (4)].expr), (yyvsp[(3) - (4)].expr)); }
    break;

  case 91:
#line 348 "parser.y"
    {
                                    (yyval.call) = new Call((yylsp[(1) - (4)]), NULL, new Identifier((yylsp[(1) - (4)]), (yyvsp[(1) - (4)].identifier)), (yyvsp[(3) - (4)].exprList));
                                  }
    break;

  case 92:
#line 351 "parser.y"
    {
                                    (yyval.call) = new Call((yylsp[(1) - (6)]), (yyvsp[(1) - (6)].expr), new Identifier((yylsp[(3) - (6)]), (yyvsp[(3) - (6)].identifier)), (yyvsp[(5) - (6)].exprList));
                                  }
    break;

  case 93:
#line 357 "parser.y"
    { (yyval.exprList) = (yyvsp[(1) - (1)].exprList); }
    break;

  case 94:
#line 358 "parser.y"
    { (yyval.exprList) = new List< Expr* >(); }
    break;

  case 95:
#line 361 "parser.y"
    { (yyval.expr) = new IntConstant((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].integerConstant)); }
    break;

  case 96:
#line 362 "parser.y"
    { (yyval.expr) = new DoubleConstant((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].doubleConstant)); }
    break;

  case 97:
#line 363 "parser.y"
    { (yyval.expr) = new BoolConstant((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].boolConstant)); }
    break;

  case 98:
#line 364 "parser.y"
    { (yyval.expr) = new StringConstant((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].stringConstant)); }
    break;

  case 99:
#line 365 "parser.y"
    { (yyval.expr) = new NullConstant((yylsp[(1) - (1)])); }
    break;


/* Line 1267 of yacc.c.  */
#line 2230 "y.tab.c"
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


#line 369 "parser.y"


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
   yydebug = false  ;
}

