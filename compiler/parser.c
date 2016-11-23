/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#include "tree.h"

#line 70 "parser.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.h".  */
#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    VOID = 258,
    LABELS = 259,
    TYPES = 260,
    VARS = 261,
    FUNCTIONS = 262,
    VAR = 263,
    GOTO = 264,
    RETURN = 265,
    IF = 266,
    WHILE = 267,
    ELSE = 268,
    IDENTIFIER = 269,
    OPEN_PAREN = 270,
    OPEN_BRACKET = 271,
    CLOSE_PAREN = 272,
    CLOSE_BRACKET = 273,
    EQUAL = 274,
    ASSIGN = 275,
    DIFFERENT = 276,
    LESS_OR_EQUAL = 277,
    LESS = 278,
    GREATER_OR_EQUAL = 279,
    GREATER = 280,
    PLUS = 281,
    MINUS = 282,
    MULTIPLY = 283,
    DIV = 284,
    AND = 285,
    OR = 286,
    CLOSE_BRACE = 287,
    OPEN_BRACE = 288,
    COLON = 289,
    COMMA = 290,
    NOT = 291,
    SEMI_COLON = 292,
    INTEGER = 293,
    UNFINISHED_COMMENT = 294,
    LEXICAL_ERROR = 295,
    END_OF_FILE = 296
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 5 "parser.y" /* yacc.c:355  */

  char *strval;
  int intval;
  TreeNode* nodeval;
  List* listval;

#line 159 "parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 176 "parser.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   173

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  179

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    35,    35,    38,    39,    42,    47,    52,    53,    55,
      55,    57,    58,    64,    64,    66,    70,    76,    76,    78,
      79,    81,    82,    84,    85,    87,    88,    90,    91,    97,
     101,   103,   104,   110,   110,   112,   116,   121,   125,   130,
     134,   135,   137,   138,   140,   144,   150,   151,   152,   152,
     153,   153,   154,   156,   161,   163,   165,   166,   168,   170,
     171,   177,   181,   186,   191,   193,   194,   199,   199,   199,
     200,   200,   201,   203,   203,   203,   205,   209,   215,   216,
     222,   222,   222,   224,   228,   233,   237,   242,   242,   242,
     244,   244,   245,   245,   246,   248,   249,   251,   252,   258,
     259
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VOID", "LABELS", "TYPES", "VARS",
  "FUNCTIONS", "VAR", "GOTO", "RETURN", "IF", "WHILE", "ELSE",
  "IDENTIFIER", "OPEN_PAREN", "OPEN_BRACKET", "CLOSE_PAREN",
  "CLOSE_BRACKET", "EQUAL", "ASSIGN", "DIFFERENT", "LESS_OR_EQUAL", "LESS",
  "GREATER_OR_EQUAL", "GREATER", "PLUS", "MINUS", "MULTIPLY", "DIV", "AND",
  "OR", "CLOSE_BRACE", "OPEN_BRACE", "COLON", "COMMA", "NOT", "SEMI_COLON",
  "INTEGER", "UNFINISHED_COMMENT", "LEXICAL_ERROR", "END_OF_FILE",
  "$accept", "program", "function", "function_declaration", "block",
  "labels", "types", "types_assigLoop", "variables", "variablesLoop",
  "functions", "functionLoop", "body", "statementLoop", "type",
  "bracketLoop", "formal_parameters", "formal_parameterLoop",
  "formal_parameter", "expression_parameter", "function_parameter",
  "statement", "variable", "varBracketLoop", "unlabeled_statement",
  "assignment", "function_call_statement", "goto", "return", "compound",
  "unlabeled_statementLoop", "conditional", "repetitive",
  "empty_statement", "expression", "relational_operator", "plus_or_minus",
  "simple_expression", "additiveLoop", "additive_operator", "term",
  "multiplicativeLoop", "multiplicative_operator", "factor",
  "function_call", "identifier_list", "expression_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
# endif

#define YYPACT_NINF -114

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-114)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      68,    -5,    -5,    57,   -26,    96,  -114,  -114,  -114,  -114,
      83,    55,    69,    89,   103,  -114,     6,  -114,  -114,  -114,
      44,    89,  -114,   125,    96,  -114,    81,    96,  -114,    84,
     117,   118,    53,   119,    99,  -114,   120,  -114,  -114,  -114,
    -114,  -114,   115,   122,    89,   130,  -114,   124,   121,    89,
      88,    68,   106,   126,   107,   124,    90,   124,  -114,    68,
      15,  -114,   102,   127,  -114,   108,   124,   109,  -114,   133,
      75,   134,   135,    59,  -114,    58,  -114,    52,  -114,   128,
    -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,   114,
     136,   123,  -114,   116,  -114,   129,  -114,  -114,  -114,   131,
      -2,    85,   100,   100,   -10,   100,    58,   139,   113,  -114,
      21,  -114,  -114,   100,  -114,  -114,   138,  -114,  -114,  -114,
     100,    -2,  -114,  -114,    87,    91,  -114,  -114,  -114,  -114,
    -114,  -114,  -114,   100,   140,   141,  -114,  -114,    11,   142,
    -114,   100,  -114,  -114,   132,  -114,   145,  -114,  -114,  -114,
    -114,    87,    -2,  -114,  -114,  -114,    91,    -2,  -114,   137,
     137,  -114,   100,  -114,   146,  -114,  -114,    -2,  -114,    -2,
    -114,   150,  -114,  -114,  -114,  -114,  -114,   137,  -114
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     3,     4,     1,     2,
       0,     8,     0,     0,    97,    30,     0,    31,    33,    34,
       0,     0,     5,    10,     0,    97,     0,     0,    29,     0,
       0,     0,     0,     0,    14,    38,     0,    37,    32,    35,
      98,     7,     0,     9,     0,    18,    36,     0,     0,    13,
       0,     0,     0,    25,     0,     0,     0,     0,    19,    17,
       0,     6,     0,    26,    11,     0,     0,     0,    20,     0,
      75,     0,     0,    42,    21,     0,    64,     0,    24,     0,
      40,    46,    47,    48,    49,    41,    50,    51,    52,     0,
       0,     0,    12,     0,    15,     0,    73,    74,    56,     0,
       0,    65,    75,    75,    75,    75,     0,    43,    42,    59,
       0,    22,    23,    75,    54,    27,     0,    16,    55,    57,
      75,     0,    91,    90,    77,    84,    92,    67,    68,    70,
      69,    71,    72,    75,     0,     0,    96,    99,     0,     0,
      39,    75,    58,    60,     0,    28,     0,    94,    80,    81,
      82,    76,     0,    87,    88,    89,    83,     0,    66,     0,
       0,    95,    75,    44,     0,    53,    93,     0,    78,     0,
      85,    61,    63,   100,    45,    79,    86,     0,    62
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -114,  -114,    22,   157,  -114,  -114,  -114,  -114,  -114,  -114,
    -114,  -114,  -114,  -114,   -17,  -114,    72,  -114,   143,  -114,
    -114,    94,   -56,  -114,   -65,  -114,  -114,  -114,  -114,   -83,
    -114,  -114,  -114,  -114,  -102,  -114,  -114,    19,  -114,    14,
     -87,  -114,    17,  -113,   -55,    -7,  -114
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     6,    22,    23,    34,    43,    45,    49,
      52,    59,    61,    77,    54,    63,    11,    16,    17,    18,
      19,    78,   123,   107,    80,    81,    82,    83,    84,    85,
     110,    86,    87,    88,    99,   133,   100,   101,   151,   152,
     124,   156,   157,   125,   126,    20,   138
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
     134,   135,   137,   139,    79,    89,    26,   136,   147,     5,
     109,   144,   108,   120,    32,     9,    96,    97,   146,    79,
      89,    79,    89,    28,    69,    70,    71,    72,   161,    73,
      69,    70,    71,    72,   121,   108,   122,    50,    65,   164,
      67,   140,    56,    29,   170,   143,   162,    74,    75,    93,
      79,    89,    76,   142,    79,    89,   176,     8,    76,    21,
     173,    69,    70,    71,    72,   168,    73,    69,    70,    71,
      72,     1,   108,    58,   104,   105,   171,   172,    30,    31,
     175,    68,     2,    24,   111,    75,    12,    12,    31,    76,
      41,    13,    13,   106,   178,    76,    35,    14,    14,    37,
      15,    96,    97,    25,   127,    44,   128,   129,   130,   131,
     132,    10,    98,   148,   149,    36,    31,    27,   150,   153,
     154,   155,    57,    31,    66,    31,    96,    97,   104,   105,
      33,    39,    40,    42,    46,    47,    48,    51,    53,    60,
      90,    55,    62,    91,    64,    92,    94,    95,   113,   102,
     103,   114,   158,   117,   115,   141,   145,   159,   160,     7,
     163,   116,   166,   177,   174,   167,   118,     0,   119,   165,
      75,   112,    38,   169
};

static const yytype_int16 yycheck[] =
{
     102,   103,   104,   105,    60,    60,    13,    17,   121,    14,
      75,   113,    14,    15,    21,    41,    26,    27,   120,    75,
      75,    77,    77,    17,     9,    10,    11,    12,    17,    14,
       9,    10,    11,    12,    36,    14,    38,    44,    55,   141,
      57,   106,    49,    37,   157,   110,    35,    32,    33,    66,
     106,   106,    37,    32,   110,   110,   169,     0,    37,     4,
     162,     9,    10,    11,    12,   152,    14,     9,    10,    11,
      12,     3,    14,    51,    15,    16,   159,   160,    34,    35,
     167,    59,    14,    14,    32,    33,     3,     3,    35,    37,
      37,     8,     8,    34,   177,    37,    24,    14,    14,    27,
      17,    26,    27,    14,    19,     6,    21,    22,    23,    24,
      25,    15,    37,    26,    27,    34,    35,    14,    31,    28,
      29,    30,    34,    35,    34,    35,    26,    27,    15,    16,
       5,    14,    14,    14,    14,    20,    14,     7,    14,    33,
      38,    20,    16,    16,    37,    37,    37,    14,    20,    15,
      15,    37,   133,    37,    18,    16,    18,    17,    17,     2,
      18,    38,    17,    13,    18,   151,    37,    -1,    37,    37,
      33,    77,    29,   156
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    14,    43,    44,    14,    45,    45,     0,    41,
      15,    58,     3,     8,    14,    17,    59,    60,    61,    62,
      87,     4,    46,    47,    14,    14,    87,    14,    17,    37,
      34,    35,    87,     5,    48,    58,    34,    58,    60,    14,
      14,    37,    14,    49,     6,    50,    14,    20,    14,    51,
      87,     7,    52,    14,    56,    20,    87,    34,    44,    53,
      33,    54,    16,    57,    37,    56,    34,    56,    44,     9,
      10,    11,    12,    14,    32,    33,    37,    55,    63,    64,
      66,    67,    68,    69,    70,    71,    73,    74,    75,    86,
      38,    16,    37,    56,    37,    14,    26,    27,    37,    76,
      78,    79,    15,    15,    15,    16,    34,    65,    14,    66,
      72,    32,    63,    20,    37,    18,    38,    37,    37,    37,
      15,    36,    38,    64,    82,    85,    86,    19,    21,    22,
      23,    24,    25,    77,    76,    76,    17,    76,    88,    76,
      66,    16,    32,    66,    76,    18,    76,    85,    26,    27,
      31,    80,    81,    28,    29,    30,    83,    84,    79,    17,
      17,    17,    35,    18,    76,    37,    17,    81,    82,    84,
      85,    71,    71,    76,    18,    82,    85,    13,    71
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    46,    47,    47,    48,
      48,    49,    49,    50,    50,    51,    51,    52,    52,    53,
      53,    54,    54,    55,    55,    56,    56,    57,    57,    58,
      58,    59,    59,    60,    60,    61,    61,    62,    62,    63,
      63,    63,    64,    64,    65,    65,    66,    66,    66,    66,
      66,    66,    66,    67,    68,    69,    70,    70,    71,    72,
      72,    73,    73,    74,    75,    76,    76,    77,    77,    77,
      77,    77,    77,    78,    78,    78,    79,    79,    80,    80,
      81,    81,    81,    82,    82,    83,    83,    84,    84,    84,
      85,    85,    85,    85,    85,    86,    86,    87,    87,    88,
      88
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     3,     5,     3,     0,     2,
       0,     4,     5,     2,     0,     4,     5,     2,     0,     1,
       2,     2,     3,     2,     1,     1,     2,     3,     4,     3,
       2,     1,     3,     1,     1,     3,     4,     3,     3,     3,
       1,     1,     1,     2,     3,     4,     1,     1,     1,     1,
       1,     1,     1,     4,     2,     3,     2,     3,     3,     1,
       2,     5,     7,     5,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     3,     2,     2,     3,
       1,     1,     1,     2,     1,     2,     3,     1,     1,     1,
       1,     1,     1,     3,     2,     4,     3,     1,     3,     1,
       3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
#line 35 "parser.y" /* yacc.c:1646  */
    { createProgramNode((yyvsp[-1].nodeval)); return 0; }
#line 1389 "parser.c" /* yacc.c:1646  */
    break;

  case 3:
#line 38 "parser.y" /* yacc.c:1646  */
    { (yyval.nodeval) = createVoidFunctionNode((yyvsp[0].nodeval)); }
#line 1395 "parser.c" /* yacc.c:1646  */
    break;

  case 4:
#line 39 "parser.y" /* yacc.c:1646  */
    { (yyval.nodeval) = createFunctionNode((yyvsp[-1].strval), (yyvsp[0].nodeval)); }
#line 1401 "parser.c" /* yacc.c:1646  */
    break;

  case 5:
#line 43 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.nodeval) = createFuncDeclarationNode((yyvsp[-2].strval), (yyvsp[-1].listval), (yyvsp[0].nodeval));
                  }
#line 1409 "parser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 48 "parser.y" /* yacc.c:1646  */
    {
      (yyval.nodeval) = createBlockNode((yyvsp[-4].listval), (yyvsp[-3].listval), (yyvsp[-2].listval), (yyvsp[-1].listval), (yyvsp[0].listval));
     }
#line 1417 "parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 52 "parser.y" /* yacc.c:1646  */
    { (yyval.listval) = (yyvsp[-1].listval); }
#line 1423 "parser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 53 "parser.y" /* yacc.c:1646  */
    { (yyval.listval) = 0;}
#line 1429 "parser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 55 "parser.y" /* yacc.c:1646  */
    { (yyval.listval) = (yyvsp[0].listval); }
#line 1435 "parser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 55 "parser.y" /* yacc.c:1646  */
    { (yyval.listval) = 0; }
#line 1441 "parser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 57 "parser.y" /* yacc.c:1646  */
    { (yyval.listval) = createTypeList((yyvsp[-3].strval), (yyvsp[-1].nodeval)); }
#line 1447 "parser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 59 "parser.y" /* yacc.c:1646  */
    {
                insertTypeList((yyvsp[-4].listval), (yyvsp[-3].strval), (yyvsp[-1].nodeval));
                (yyval.listval) = (yyvsp[-4].listval);
               }
#line 1456 "parser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 64 "parser.y" /* yacc.c:1646  */
    { (yyval.listval) = (yyvsp[0].listval); }
#line 1462 "parser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 64 "parser.y" /* yacc.c:1646  */
    { (yyval.listval) = 0; }
#line 1468 "parser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 67 "parser.y" /* yacc.c:1646  */
    {
              (yyval.listval) = createVariableList((yyvsp[-3].listval), (yyvsp[-1].nodeval));
             }
#line 1476 "parser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 71 "parser.y" /* yacc.c:1646  */
    {
              insertVariableList((yyvsp[-4].listval), (yyvsp[-3].listval), (yyvsp[-1].nodeval));
              (yyval.listval) = (yyvsp[-4].listval);
             }
#line 1485 "parser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 76 "parser.y" /* yacc.c:1646  */
    { (yyval.listval) = (yyvsp[0].listval); }
#line 1491 "parser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 76 "parser.y" /* yacc.c:1646  */
    { (yyval.listval) = 0; }
#line 1497 "parser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 78 "parser.y" /* yacc.c:1646  */
    { (yyval.listval) = createFunctionList((yyvsp[0].nodeval)); }
#line 1503 "parser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 79 "parser.y" /* yacc.c:1646  */
    { insertFunctionList((yyvsp[-1].listval), (yyvsp[0].nodeval)); (yyval.listval) = (yyvsp[-1].listval); }
#line 1509 "parser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 81 "parser.y" /* yacc.c:1646  */
    { (yyval.listval) = 0; }
#line 1515 "parser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 82 "parser.y" /* yacc.c:1646  */
    { (yyval.listval) = (yyvsp[-1].listval); }
#line 1521 "parser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 84 "parser.y" /* yacc.c:1646  */
    { insertStatementList((yyvsp[-1].listval), (yyvsp[0].nodeval)); (yyval.listval) = (yyvsp[-1].listval); }
#line 1527 "parser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 85 "parser.y" /* yacc.c:1646  */
    { (yyval.listval) = createStatementList((yyvsp[0].nodeval)); }
#line 1533 "parser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 87 "parser.y" /* yacc.c:1646  */
    { (yyval.nodeval) = createTypeNode((yyvsp[0].strval)); }
#line 1539 "parser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 88 "parser.y" /* yacc.c:1646  */
    {(yyval.nodeval) = createArrayTypeNode((yyvsp[-1].strval), (yyvsp[0].listval)); }
#line 1545 "parser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 90 "parser.y" /* yacc.c:1646  */
    { (yyval.listval) = createIntList((yyvsp[-1].intval)); }
#line 1551 "parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 92 "parser.y" /* yacc.c:1646  */
    {
            insertIntList((yyvsp[-3].listval), (yyvsp[-1].intval));
            (yyval.listval) = (yyvsp[-3].listval);
           }
#line 1560 "parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 98 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.listval) = (yyvsp[-1].listval);
                 }
#line 1568 "parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 101 "parser.y" /* yacc.c:1646  */
    { (yyval.listval) = 0; }
#line 1574 "parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 103 "parser.y" /* yacc.c:1646  */
    { (yyval.listval) = createFormalParamList((yyvsp[0].nodeval)); }
#line 1580 "parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 105 "parser.y" /* yacc.c:1646  */
    {
                      insertFormalParamList((yyvsp[-2].listval), (yyvsp[0].nodeval));
                      (yyval.listval) = (yyvsp[-2].listval);
                    }
#line 1589 "parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 110 "parser.y" /* yacc.c:1646  */
    { (yyval.nodeval) = (yyvsp[0].nodeval); }
#line 1595 "parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 110 "parser.y" /* yacc.c:1646  */
    { (yyval.nodeval) = (yyvsp[0].nodeval); }
#line 1601 "parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 113 "parser.y" /* yacc.c:1646  */
    {
                      (yyval.nodeval) = createExpParamNode(0, (yyvsp[-2].listval), (yyvsp[0].strval));
                    }
#line 1609 "parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 117 "parser.y" /* yacc.c:1646  */
    {
                      (yyval.nodeval) = createExpParamNode(1, (yyvsp[-2].listval), (yyvsp[0].strval));
                    }
#line 1617 "parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 122 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.nodeval) = createFuncParamNode((yyvsp[-2].strval), (yyvsp[-1].strval), (yyvsp[0].listval));
                  }
#line 1625 "parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 126 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.nodeval) = createFuncParamNode(0, (yyvsp[-1].strval), (yyvsp[0].listval));
                  }
#line 1633 "parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 131 "parser.y" /* yacc.c:1646  */
    {
          (yyval.nodeval) = createLabeledStatementNode((yyvsp[-2].strval), (yyvsp[0].nodeval));
         }
#line 1641 "parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 134 "parser.y" /* yacc.c:1646  */
    { (yyval.nodeval) = (yyvsp[0].nodeval); }
#line 1647 "parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 135 "parser.y" /* yacc.c:1646  */
    { (yyval.nodeval) = createCompoundNode((yyvsp[0].listval)); }
#line 1653 "parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 137 "parser.y" /* yacc.c:1646  */
    { (yyval.nodeval) = createVariableNode((yyvsp[0].strval)); }
#line 1659 "parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 138 "parser.y" /* yacc.c:1646  */
    { (yyval.nodeval) = createArrayVariableNode((yyvsp[-1].strval), (yyvsp[0].listval)); }
#line 1665 "parser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 141 "parser.y" /* yacc.c:1646  */
    {
                (yyval.listval) = createVarBracketList((yyvsp[-1].nodeval));
              }
#line 1673 "parser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 145 "parser.y" /* yacc.c:1646  */
    {
                insertVarBracketList((yyvsp[-3].listval), (yyvsp[-1].nodeval));
                (yyval.listval) = (yyvsp[-3].listval);
              }
#line 1682 "parser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 150 "parser.y" /* yacc.c:1646  */
    { (yyval.nodeval) = (yyvsp[0].nodeval); }
#line 1688 "parser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 151 "parser.y" /* yacc.c:1646  */
    { (yyval.nodeval) = (yyvsp[0].nodeval); }
#line 1694 "parser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 152 "parser.y" /* yacc.c:1646  */
    { (yyval.nodeval) = (yyvsp[0].nodeval); }
#line 1700 "parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 152 "parser.y" /* yacc.c:1646  */
    { (yyval.nodeval) = (yyvsp[0].nodeval); }
#line 1706 "parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 153 "parser.y" /* yacc.c:1646  */
    { (yyval.nodeval) = (yyvsp[0].nodeval); }
#line 1712 "parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 153 "parser.y" /* yacc.c:1646  */
    { (yyval.nodeval) = (yyvsp[0].nodeval); }
#line 1718 "parser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 154 "parser.y" /* yacc.c:1646  */
    { (yyval.nodeval) = (yyvsp[0].nodeval); }
#line 1724 "parser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 157 "parser.y" /* yacc.c:1646  */
    {
            (yyval.nodeval) = createAssignmentNode((yyvsp[-3].nodeval), (yyvsp[-1].nodeval));
          }
#line 1732 "parser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 161 "parser.y" /* yacc.c:1646  */
    { (yyval.nodeval) = (yyvsp[-1].nodeval); }
#line 1738 "parser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 163 "parser.y" /* yacc.c:1646  */
    { (yyval.nodeval) = createGotoNode((yyvsp[-1].strval)); }
#line 1744 "parser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 165 "parser.y" /* yacc.c:1646  */
    { (yyval.nodeval) = createReturnNode(); }
#line 1750 "parser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 166 "parser.y" /* yacc.c:1646  */
    { (yyval.nodeval) = createReturnValueNode((yyvsp[-1].nodeval)); }
#line 1756 "parser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 168 "parser.y" /* yacc.c:1646  */
    { (yyval.listval) = (yyvsp[-1].listval); }
#line 1762 "parser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 170 "parser.y" /* yacc.c:1646  */
    { (yyval.listval) = createUnlabeledStmList((yyvsp[0].nodeval)); }
#line 1768 "parser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 172 "parser.y" /* yacc.c:1646  */
    {
                        insertUnlabeledStmList((yyvsp[-1].listval), (yyvsp[0].nodeval));
                        (yyval.listval) = (yyvsp[-1].listval);
                       }
#line 1777 "parser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 178 "parser.y" /* yacc.c:1646  */
    {
            (yyval.nodeval) = createIfNode((yyvsp[-2].nodeval), (yyvsp[0].listval));
           }
#line 1785 "parser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 182 "parser.y" /* yacc.c:1646  */
    {
            (yyval.nodeval) = createIfElseNode((yyvsp[-4].nodeval), (yyvsp[-2].listval), (yyvsp[0].listval));
           }
#line 1793 "parser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 187 "parser.y" /* yacc.c:1646  */
    {
            (yyval.nodeval) = createWhileNode((yyvsp[-2].nodeval), (yyvsp[0].listval));
          }
#line 1801 "parser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 191 "parser.y" /* yacc.c:1646  */
    { (yyval.nodeval) = 0; }
#line 1807 "parser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 193 "parser.y" /* yacc.c:1646  */
    { (yyval.nodeval) = (yyvsp[0].nodeval); }
#line 1813 "parser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 195 "parser.y" /* yacc.c:1646  */
    {
            (yyval.nodeval) = createRelationalExpNode((yyvsp[-2].nodeval), (yyvsp[-1].intval), (yyvsp[0].nodeval));
          }
#line 1821 "parser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 199 "parser.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[0].intval); }
#line 1827 "parser.c" /* yacc.c:1646  */
    break;

  case 68:
#line 199 "parser.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[0].intval); }
#line 1833 "parser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 199 "parser.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[0].intval); }
#line 1839 "parser.c" /* yacc.c:1646  */
    break;

  case 70:
#line 200 "parser.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[0].intval); }
#line 1845 "parser.c" /* yacc.c:1646  */
    break;

  case 71:
#line 200 "parser.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[0].intval); }
#line 1851 "parser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 201 "parser.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[0].intval); }
#line 1857 "parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 203 "parser.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[0].intval); }
#line 1863 "parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 203 "parser.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[0].intval); }
#line 1869 "parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 203 "parser.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 1875 "parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 206 "parser.y" /* yacc.c:1646  */
    {
                  (yyval.nodeval) = createSimpleExpNode((yyvsp[-2].intval), (yyvsp[-1].nodeval), (yyvsp[0].listval));
                 }
#line 1883 "parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 210 "parser.y" /* yacc.c:1646  */
    {
                  (yyval.nodeval) = createSimpleExpNode((yyvsp[-1].intval), (yyvsp[0].nodeval), 0);
                 }
#line 1891 "parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 215 "parser.y" /* yacc.c:1646  */
    { (yyval.listval) = createAdditiveList((yyvsp[-1].intval), (yyvsp[0].nodeval)); }
#line 1897 "parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 217 "parser.y" /* yacc.c:1646  */
    {
              insertAdditiveList((yyvsp[-2].listval),(yyvsp[-1].intval),(yyvsp[0].nodeval));
              (yyval.listval) = (yyvsp[-2].listval);
            }
#line 1906 "parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 222 "parser.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[0].intval); }
#line 1912 "parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 222 "parser.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[0].intval); }
#line 1918 "parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 222 "parser.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[0].intval); }
#line 1924 "parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 225 "parser.y" /* yacc.c:1646  */
    {
      (yyval.nodeval) = createMultTermNode((yyvsp[-1].nodeval), (yyvsp[0].listval));
    }
#line 1932 "parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 229 "parser.y" /* yacc.c:1646  */
    {
      (yyval.nodeval) = createMultTermNode((yyvsp[0].nodeval), 0);
    }
#line 1940 "parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 234 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.listval) = createMultiplicativeList((yyvsp[-1].intval), (yyvsp[0].nodeval));
                  }
#line 1948 "parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 238 "parser.y" /* yacc.c:1646  */
    {
                    insertMultiplicativeList((yyvsp[-2].listval), (yyvsp[-1].intval), (yyvsp[0].nodeval));
                  }
#line 1956 "parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 242 "parser.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[0].intval); }
#line 1962 "parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 242 "parser.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[0].intval); }
#line 1968 "parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 242 "parser.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[0].intval); }
#line 1974 "parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 244 "parser.y" /* yacc.c:1646  */
    { (yyval.nodeval) = (yyvsp[0].nodeval); }
#line 1980 "parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 244 "parser.y" /* yacc.c:1646  */
    { (yyval.nodeval) = createIntNode((yyvsp[0].intval)); }
#line 1986 "parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 245 "parser.y" /* yacc.c:1646  */
    { (yyval.nodeval) = (yyvsp[0].nodeval); }
#line 1992 "parser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 245 "parser.y" /* yacc.c:1646  */
    { (yyval.nodeval) = (yyvsp[-1].nodeval); }
#line 1998 "parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 246 "parser.y" /* yacc.c:1646  */
    { (yyval.nodeval) = createNegationNode((yyvsp[0].nodeval)); }
#line 2004 "parser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 248 "parser.y" /* yacc.c:1646  */
    { (yyval.nodeval) = createCallNode((yyvsp[-3].strval), (yyvsp[-1].listval)); }
#line 2010 "parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 249 "parser.y" /* yacc.c:1646  */
    { (yyval.nodeval) = createCallNode((yyvsp[-2].strval), 0); }
#line 2016 "parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 251 "parser.y" /* yacc.c:1646  */
    { (yyval.listval) = createIdentifierList((yyvsp[0].strval)); }
#line 2022 "parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 253 "parser.y" /* yacc.c:1646  */
    {
                insertIdentifierList((yyvsp[-2].listval), (yyvsp[0].strval));
                (yyval.listval) = (yyvsp[-2].listval);
               }
#line 2031 "parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 258 "parser.y" /* yacc.c:1646  */
    { (yyval.listval) = createExpList((yyvsp[0].nodeval)); }
#line 2037 "parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 259 "parser.y" /* yacc.c:1646  */
    { insertExpList((yyvsp[-2].listval), (yyvsp[0].nodeval)); (yyval.listval) = (yyvsp[-2].listval); }
#line 2043 "parser.c" /* yacc.c:1646  */
    break;


#line 2047 "parser.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
