/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "myParser.y"

    // C code
    #include<stdio.h>
    #include"scanner.h"
    #include"myAST.h"
    
    extern int yylineno;
    struct decl *parser_result = 0;
    int yyerror(char *msg);

#line 82 "parser.c"

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

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PLUS = 3,                       /* PLUS  */
  YYSYMBOL_MULT = 4,                       /* MULT  */
  YYSYMBOL_MINUS = 5,                      /* MINUS  */
  YYSYMBOL_DIV = 6,                        /* DIV  */
  YYSYMBOL_O_PAREN = 7,                    /* O_PAREN  */
  YYSYMBOL_C_PAREN = 8,                    /* C_PAREN  */
  YYSYMBOL_SEMICOLON = 9,                  /* SEMICOLON  */
  YYSYMBOL_LESS = 10,                      /* LESS  */
  YYSYMBOL_LESS_EQUALS = 11,               /* LESS_EQUALS  */
  YYSYMBOL_GREATER = 12,                   /* GREATER  */
  YYSYMBOL_GREATER_EQUALS = 13,            /* GREATER_EQUALS  */
  YYSYMBOL_EQUALS = 14,                    /* EQUALS  */
  YYSYMBOL_EQUALS_EQUALS = 15,             /* EQUALS_EQUALS  */
  YYSYMBOL_NOT_EQUALS = 16,                /* NOT_EQUALS  */
  YYSYMBOL_COMMA = 17,                     /* COMMA  */
  YYSYMBOL_O_BRACE = 18,                   /* O_BRACE  */
  YYSYMBOL_C_BRACE = 19,                   /* C_BRACE  */
  YYSYMBOL_O_BRACK = 20,                   /* O_BRACK  */
  YYSYMBOL_C_BRACK = 21,                   /* C_BRACK  */
  YYSYMBOL_IF = 22,                        /* IF  */
  YYSYMBOL_WHILE = 23,                     /* WHILE  */
  YYSYMBOL_ELSE = 24,                      /* ELSE  */
  YYSYMBOL_INT = 25,                       /* INT  */
  YYSYMBOL_RETURN = 26,                    /* RETURN  */
  YYSYMBOL_VOID = 27,                      /* VOID  */
  YYSYMBOL_NUM = 28,                       /* NUM  */
  YYSYMBOL_ID = 29,                        /* ID  */
  YYSYMBOL_ERROR = 30,                     /* ERROR  */
  YYSYMBOL_YYACCEPT = 31,                  /* $accept  */
  YYSYMBOL_prog = 32,                      /* prog  */
  YYSYMBOL_decList = 33,                   /* decList  */
  YYSYMBOL_dec = 34,                       /* dec  */
  YYSYMBOL_varDec = 35,                    /* varDec  */
  YYSYMBOL_type = 36,                      /* type  */
  YYSYMBOL_funcDec = 37,                   /* funcDec  */
  YYSYMBOL_params = 38,                    /* params  */
  YYSYMBOL_paramList = 39,                 /* paramList  */
  YYSYMBOL_param = 40,                     /* param  */
  YYSYMBOL_compStmt = 41,                  /* compStmt  */
  YYSYMBOL_localDecs = 42,                 /* localDecs  */
  YYSYMBOL_stmtList = 43,                  /* stmtList  */
  YYSYMBOL_stmt = 44,                      /* stmt  */
  YYSYMBOL_expStmt = 45,                   /* expStmt  */
  YYSYMBOL_selecStmt = 46,                 /* selecStmt  */
  YYSYMBOL_iterStmt = 47,                  /* iterStmt  */
  YYSYMBOL_returnStmt = 48,                /* returnStmt  */
  YYSYMBOL_exp = 49,                       /* exp  */
  YYSYMBOL_var = 50,                       /* var  */
  YYSYMBOL_simpExp = 51,                   /* simpExp  */
  YYSYMBOL_relateOp = 52,                  /* relateOp  */
  YYSYMBOL_addExp = 53,                    /* addExp  */
  YYSYMBOL_addOp = 54,                     /* addOp  */
  YYSYMBOL_term = 55,                      /* term  */
  YYSYMBOL_mulOp = 56,                     /* mulOp  */
  YYSYMBOL_fact = 57,                      /* fact  */
  YYSYMBOL_call = 58,                      /* call  */
  YYSYMBOL_args = 59,                      /* args  */
  YYSYMBOL_argList = 60                    /* argList  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   102

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  104

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   285


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    55,    55,    58,    58,    60,    62,    65,    67,    70,
      72,    76,    79,    79,    81,    83,    86,    88,    91,    93,
      96,    98,   100,   102,   104,   106,   108,   110,   113,   115,
     117,   120,   123,   125,   128,   130,   132,   135,   137,   140,
     142,   145,   147,   149,   151,   153,   155,   158,   160,   163,
     165,   168,   170,   173,   175,   178,   180,   182,   184,   187,
     190,   190,   192,   194
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "PLUS", "MULT",
  "MINUS", "DIV", "O_PAREN", "C_PAREN", "SEMICOLON", "LESS", "LESS_EQUALS",
  "GREATER", "GREATER_EQUALS", "EQUALS", "EQUALS_EQUALS", "NOT_EQUALS",
  "COMMA", "O_BRACE", "C_BRACE", "O_BRACK", "C_BRACK", "IF", "WHILE",
  "ELSE", "INT", "RETURN", "VOID", "NUM", "ID", "ERROR", "$accept", "prog",
  "decList", "dec", "varDec", "type", "funcDec", "params", "paramList",
  "param", "compStmt", "localDecs", "stmtList", "stmt", "expStmt",
  "selecStmt", "iterStmt", "returnStmt", "exp", "var", "simpExp",
  "relateOp", "addExp", "addOp", "term", "mulOp", "fact", "call", "args",
  "argList", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-65)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-14)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      44,   -65,   -65,     9,    44,   -65,   -65,   -15,   -65,   -65,
     -65,    -4,    47,   -65,   -11,    14,    15,    40,    39,   -65,
      36,    43,    55,    44,    70,    62,   -65,   -65,   -65,   -65,
     -65,    13,    30,   -65,    78,    80,     1,   -65,    -1,   -65,
      57,    24,   -65,    81,   -65,   -65,   -65,   -65,    11,   -65,
      65,    45,   -65,   -65,    83,    30,    30,   -65,    84,    30,
      30,    -2,   -65,   -65,   -65,    30,    30,   -65,   -65,   -65,
     -65,   -65,   -65,   -65,   -65,    30,    30,   -65,   -65,    30,
     -65,    86,    87,   -65,   -65,    88,    71,    68,   -65,   -65,
     -65,    79,    45,   -65,    38,    38,   -65,    30,   -65,    73,
     -65,   -65,    38,   -65
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     9,    10,     0,     2,     4,     5,     0,     6,     1,
       3,     0,     0,     7,     0,    10,     0,     0,    12,    15,
       0,    16,     0,     0,     0,     0,    21,    11,    14,     8,
      17,     0,     0,    19,     0,     0,     0,    58,    37,    20,
       0,     0,    23,     0,    25,    26,    27,    28,    56,    36,
      40,    48,    52,    57,     0,     0,     0,    32,     0,    61,
       0,     0,    18,    22,    24,     0,     0,    49,    50,    42,
      41,    43,    44,    45,    46,     0,     0,    53,    54,     0,
      55,     0,     0,    33,    63,     0,    60,     0,    35,    34,
      56,    39,    47,    51,     0,     0,    59,     0,    38,    29,
      31,    62,     0,    30
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -65,   -65,   -65,    94,    61,   -10,   -65,   -65,   -65,    76,
     -65,   -65,   -65,   -40,   -65,   -65,   -65,   -65,   -32,   -64,
     -65,   -65,    25,   -65,    26,   -65,    22,   -65,   -65,   -65
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,     6,     7,     8,    17,    18,    19,
      27,    31,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    75,    50,    76,    51,    79,    52,    53,    85,    86
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      54,    63,    16,    12,    58,    13,    59,    13,    32,     9,
      57,    90,    90,    16,    11,    90,    14,    20,    14,    60,
      32,    40,   -13,    81,    82,    65,    66,    84,    87,    37,
      38,    32,    33,    88,    89,    34,    35,    32,     1,    36,
       2,    37,    38,    62,    21,    32,    34,    35,    22,    77,
      36,    78,    37,    38,    99,   100,    23,    24,    37,    38,
      34,    35,   103,    25,    36,   101,    37,    38,    67,     1,
      68,     2,     1,    26,    15,    69,    70,    71,    72,    29,
      73,    74,    67,    30,    68,    55,    61,    56,    97,    98,
      64,    80,    39,    83,    94,    95,    96,   102,    10,    28,
      91,    93,    92
};

static const yytype_int8 yycheck[] =
{
      32,    41,    12,     7,    36,     9,     7,     9,     7,     0,
       9,    75,    76,    23,    29,    79,    20,    28,    20,    20,
       7,    31,     8,    55,    56,    14,    15,    59,    60,    28,
      29,     7,    19,    65,    66,    22,    23,     7,    25,    26,
      27,    28,    29,    19,    29,     7,    22,    23,     8,     4,
      26,     6,    28,    29,    94,    95,    17,    21,    28,    29,
      22,    23,   102,    20,    26,    97,    28,    29,     3,    25,
       5,    27,    25,    18,    27,    10,    11,    12,    13,     9,
      15,    16,     3,    21,     5,     7,    29,     7,    17,    21,
       9,     8,    31,     9,     8,     8,     8,    24,     4,    23,
      75,    79,    76
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    25,    27,    32,    33,    34,    35,    36,    37,     0,
      34,    29,     7,     9,    20,    27,    36,    38,    39,    40,
      28,    29,     8,    17,    21,    20,    18,    41,    40,     9,
      21,    42,     7,    19,    22,    23,    26,    28,    29,    35,
      36,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      53,    55,    57,    58,    49,     7,     7,     9,    49,     7,
      20,    29,    19,    44,     9,    14,    15,     3,     5,    10,
      11,    12,    13,    15,    16,    52,    54,     4,     6,    56,
       8,    49,    49,     9,    49,    59,    60,    49,    49,    49,
      50,    53,    55,    57,     8,     8,     8,    17,    21,    44,
      44,    49,    24,    44
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    31,    32,    33,    33,    34,    34,    35,    35,    36,
      36,    37,    38,    38,    39,    39,    40,    40,    41,    41,
      42,    42,    43,    43,    44,    44,    44,    44,    45,    46,
      46,    47,    48,    48,    49,    49,    49,    50,    50,    51,
      51,    52,    52,    52,    52,    52,    52,    53,    53,    54,
      54,    55,    55,    56,    56,    57,    57,    57,    57,    58,
      59,    59,    60,    60
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     6,     1,
       1,     6,     1,     1,     3,     1,     2,     4,     4,     3,
       2,     0,     2,     1,     2,     1,     1,     1,     1,     5,
       7,     5,     2,     3,     3,     3,     1,     1,     4,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     4,
       1,     0,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
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
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
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
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
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


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* prog: decList  */
#line 56 "myParser.y"
        {parser_result = (yyvsp[0].decl);}
#line 1468 "parser.c"
    break;

  case 3: /* decList: decList dec  */
#line 58 "myParser.y"
                     {(yyval.decl) = (yyvsp[0].decl); (yyvsp[0].decl)->next = (yyvsp[-1].decl);}
#line 1474 "parser.c"
    break;

  case 4: /* decList: dec  */
#line 58 "myParser.y"
                                                    {(yyval.decl) = (yyvsp[0].decl);}
#line 1480 "parser.c"
    break;

  case 5: /* dec: varDec  */
#line 61 "myParser.y"
        {(yyval.decl) = (yyvsp[0].decl);}
#line 1486 "parser.c"
    break;

  case 6: /* dec: funcDec  */
#line 63 "myParser.y"
        {(yyval.decl) = (yyvsp[0].decl);}
#line 1492 "parser.c"
    break;

  case 7: /* varDec: type ID SEMICOLON  */
#line 66 "myParser.y"
        {(yyval.decl) = createDecl((yyvsp[-2].num), (yyvsp[-1].id), -1, 0, 0, yylineno);}
#line 1498 "parser.c"
    break;

  case 8: /* varDec: type ID O_BRACK NUM C_BRACK SEMICOLON  */
#line 68 "myParser.y"
        {(yyval.decl) = createDecl((yyvsp[-5].num), (yyvsp[-4].id), (yyvsp[-2].num), 0, 0, yylineno);}
#line 1504 "parser.c"
    break;

  case 9: /* type: INT  */
#line 71 "myParser.y"
        {(yyval.num) = Int;}
#line 1510 "parser.c"
    break;

  case 10: /* type: VOID  */
#line 73 "myParser.y"
        {(yyval.num) = Void;}
#line 1516 "parser.c"
    break;

  case 11: /* funcDec: type ID O_PAREN params C_PAREN compStmt  */
#line 77 "myParser.y"
        {(yyval.decl) = createDecl((yyvsp[-5].num), (yyvsp[-4].id), -1, (yyvsp[-2].param), (yyvsp[0].compStmt), yylineno);}
#line 1522 "parser.c"
    break;

  case 12: /* params: paramList  */
#line 79 "myParser.y"
                  {(yyval.param) = (yyvsp[0].param);}
#line 1528 "parser.c"
    break;

  case 13: /* params: VOID  */
#line 79 "myParser.y"
                                    {(yyval.param) = 0;}
#line 1534 "parser.c"
    break;

  case 14: /* paramList: paramList COMMA param  */
#line 82 "myParser.y"
        {(yyval.param) = (yyvsp[0].param); (yyvsp[0].param)->next = (yyvsp[-2].param);}
#line 1540 "parser.c"
    break;

  case 15: /* paramList: param  */
#line 84 "myParser.y"
        {(yyval.param) = (yyvsp[0].param); (yyvsp[0].param)->next = 0;}
#line 1546 "parser.c"
    break;

  case 16: /* param: type ID  */
#line 87 "myParser.y"
        {(yyval.param) = createParam((yyvsp[-1].num), (yyvsp[0].id), 0, yylineno);}
#line 1552 "parser.c"
    break;

  case 17: /* param: type ID O_BRACK C_BRACK  */
#line 89 "myParser.y"
        {(yyval.param) = createParam((yyvsp[-3].num), (yyvsp[-2].id), 1, yylineno);}
#line 1558 "parser.c"
    break;

  case 18: /* compStmt: O_BRACE localDecs stmtList C_BRACE  */
#line 92 "myParser.y"
    {(yyval.compStmt) = createCompStmt((yyvsp[-2].decl), (yyvsp[-1].stmt));}
#line 1564 "parser.c"
    break;

  case 19: /* compStmt: O_BRACE localDecs C_BRACE  */
#line 93 "myParser.y"
                                {(yyval.compStmt) = createCompStmt((yyvsp[-1].decl), 0);}
#line 1570 "parser.c"
    break;

  case 20: /* localDecs: localDecs varDec  */
#line 97 "myParser.y"
        {(yyval.decl) = (yyvsp[0].decl); (yyvsp[0].decl)->next = (yyvsp[-1].decl);}
#line 1576 "parser.c"
    break;

  case 21: /* localDecs: %empty  */
#line 98 "myParser.y"
      {(yyval.decl) = 0;}
#line 1582 "parser.c"
    break;

  case 22: /* stmtList: stmtList stmt  */
#line 101 "myParser.y"
        {(yyval.stmt) = (yyvsp[0].stmt); (yyvsp[0].stmt)->next = (yyvsp[-1].stmt);}
#line 1588 "parser.c"
    break;

  case 23: /* stmtList: stmt  */
#line 102 "myParser.y"
           {(yyval.stmt) = (yyvsp[0].stmt); (yyvsp[0].stmt)->next = 0;}
#line 1594 "parser.c"
    break;

  case 24: /* stmt: expStmt SEMICOLON  */
#line 105 "myParser.y"
        {(yyval.stmt) = (yyvsp[-1].stmt);}
#line 1600 "parser.c"
    break;

  case 25: /* stmt: selecStmt  */
#line 107 "myParser.y"
        {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1606 "parser.c"
    break;

  case 26: /* stmt: iterStmt  */
#line 109 "myParser.y"
        {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1612 "parser.c"
    break;

  case 27: /* stmt: returnStmt  */
#line 111 "myParser.y"
        {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1618 "parser.c"
    break;

  case 28: /* expStmt: exp  */
#line 113 "myParser.y"
             {(yyval.stmt) = createStmt((yyvsp[0].expr),0,0,0,0,0,0,1,yylineno);}
#line 1624 "parser.c"
    break;

  case 29: /* selecStmt: IF O_PAREN exp C_PAREN stmt  */
#line 116 "myParser.y"
        {(yyval.stmt) = createStmt(0, (yyvsp[-2].expr), (yyvsp[0].stmt), 0,0,0,0,3,yylineno);}
#line 1630 "parser.c"
    break;

  case 30: /* selecStmt: IF O_PAREN exp C_PAREN stmt ELSE stmt  */
#line 118 "myParser.y"
        {(yyval.stmt) = createStmt(0, (yyvsp[-4].expr), (yyvsp[-2].stmt), (yyvsp[0].stmt),0,0,0,3,yylineno);}
#line 1636 "parser.c"
    break;

  case 31: /* iterStmt: WHILE O_PAREN exp C_PAREN stmt  */
#line 121 "myParser.y"
    {(yyval.stmt) = createStmt(0, 0, 0, 0,(yyvsp[-2].expr),(yyvsp[0].stmt),0,4,yylineno);}
#line 1642 "parser.c"
    break;

  case 32: /* returnStmt: RETURN SEMICOLON  */
#line 124 "myParser.y"
        {(yyval.stmt) = createStmt(0,0,0,0,0,0,0,5,yylineno);}
#line 1648 "parser.c"
    break;

  case 33: /* returnStmt: RETURN exp SEMICOLON  */
#line 126 "myParser.y"
        {(yyval.stmt) = createStmt(0, 0, 0, 0,0,0,(yyvsp[-1].expr),5,yylineno);}
#line 1654 "parser.c"
    break;

  case 34: /* exp: var EQUALS_EQUALS exp  */
#line 129 "myParser.y"
        {(yyval.expr) = createExpr(1, (yyvsp[-2].var), (yyvsp[0].expr), 0, yylineno);}
#line 1660 "parser.c"
    break;

  case 35: /* exp: var EQUALS exp  */
#line 131 "myParser.y"
        {(yyval.expr) = createExpr(2, (yyvsp[-2].var), (yyvsp[0].expr), 0, yylineno);}
#line 1666 "parser.c"
    break;

  case 36: /* exp: simpExp  */
#line 133 "myParser.y"
        {(yyval.expr) = createExpr(3, 0, 0, (yyvsp[0].simple_expr), yylineno);}
#line 1672 "parser.c"
    break;

  case 37: /* var: ID  */
#line 136 "myParser.y"
        {(yyval.var) = createVar((yyvsp[0].id), 0, yylineno);}
#line 1678 "parser.c"
    break;

  case 38: /* var: ID O_BRACK exp C_BRACK  */
#line 138 "myParser.y"
        {(yyval.var) = createVar((yyvsp[-3].id), (yyvsp[-1].expr), yylineno);}
#line 1684 "parser.c"
    break;

  case 39: /* simpExp: addExp relateOp addExp  */
#line 141 "myParser.y"
        {(yyval.simple_expr) = createSimpleExpr((yyvsp[-2].add_expr), (yyvsp[-1].num), (yyvsp[0].add_expr), yylineno);}
#line 1690 "parser.c"
    break;

  case 40: /* simpExp: addExp  */
#line 143 "myParser.y"
        {(yyval.simple_expr) = createSimpleExpr((yyvsp[0].add_expr), 0, 0, yylineno);}
#line 1696 "parser.c"
    break;

  case 41: /* relateOp: LESS_EQUALS  */
#line 146 "myParser.y"
        {(yyval.num) = Less_EQUALS;}
#line 1702 "parser.c"
    break;

  case 42: /* relateOp: LESS  */
#line 148 "myParser.y"
        {(yyval.num) = Less;}
#line 1708 "parser.c"
    break;

  case 43: /* relateOp: GREATER  */
#line 150 "myParser.y"
        {(yyval.num) = Greater;}
#line 1714 "parser.c"
    break;

  case 44: /* relateOp: GREATER_EQUALS  */
#line 152 "myParser.y"
        {(yyval.num) = Greater_EQUALS;}
#line 1720 "parser.c"
    break;

  case 45: /* relateOp: EQUALS_EQUALS  */
#line 154 "myParser.y"
        {(yyval.num) = Equals_EQUALS;}
#line 1726 "parser.c"
    break;

  case 46: /* relateOp: NOT_EQUALS  */
#line 156 "myParser.y"
       {(yyval.num) = Not_EQUALS;}
#line 1732 "parser.c"
    break;

  case 47: /* addExp: addExp addOp term  */
#line 159 "myParser.y"
        {(yyval.add_expr) = createAddExp((yyvsp[-2].add_expr), (yyvsp[-1].num), (yyvsp[0].term), yylineno);}
#line 1738 "parser.c"
    break;

  case 48: /* addExp: term  */
#line 161 "myParser.y"
        {(yyval.add_expr) = createAddExp(0, 0, (yyvsp[0].term), yylineno);}
#line 1744 "parser.c"
    break;

  case 49: /* addOp: PLUS  */
#line 164 "myParser.y"
        {(yyval.num) = AD;}
#line 1750 "parser.c"
    break;

  case 50: /* addOp: MINUS  */
#line 166 "myParser.y"
        {(yyval.num) = MIN;}
#line 1756 "parser.c"
    break;

  case 51: /* term: term mulOp fact  */
#line 169 "myParser.y"
        {(yyval.term) = createTerm((yyvsp[-2].term), (yyvsp[-1].num), (yyvsp[0].factor), yylineno);}
#line 1762 "parser.c"
    break;

  case 52: /* term: fact  */
#line 171 "myParser.y"
        {(yyval.term) = createTerm(0, 0, (yyvsp[0].factor), yylineno);}
#line 1768 "parser.c"
    break;

  case 53: /* mulOp: MULT  */
#line 174 "myParser.y"
        {(yyval.num) = MULPY;}
#line 1774 "parser.c"
    break;

  case 54: /* mulOp: DIV  */
#line 176 "myParser.y"
        {(yyval.num) = DIVIDE;}
#line 1780 "parser.c"
    break;

  case 55: /* fact: O_PAREN exp C_PAREN  */
#line 179 "myParser.y"
        {(yyval.factor) = createFact((yyvsp[-1].expr), 0, 0, 0, 1, yylineno);}
#line 1786 "parser.c"
    break;

  case 56: /* fact: var  */
#line 181 "myParser.y"
        {(yyval.factor) = createFact(0, (yyvsp[0].var), 0, 0, 2, yylineno);}
#line 1792 "parser.c"
    break;

  case 57: /* fact: call  */
#line 183 "myParser.y"
        {(yyval.factor) = createFact(0, 0, (yyvsp[0].call), 0, 3, yylineno);}
#line 1798 "parser.c"
    break;

  case 58: /* fact: NUM  */
#line 185 "myParser.y"
        {(yyval.factor) = createFact(0, 0, 0, (yyvsp[0].num), 4, yylineno);}
#line 1804 "parser.c"
    break;

  case 59: /* call: ID O_PAREN args C_PAREN  */
#line 188 "myParser.y"
    {(yyval.call) = createCall((yyvsp[-3].id), (yyvsp[-1].args), yylineno);}
#line 1810 "parser.c"
    break;

  case 60: /* args: argList  */
#line 190 "myParser.y"
              {(yyval.args) = createArgs((yyvsp[0].argsList), yylineno);}
#line 1816 "parser.c"
    break;

  case 61: /* args: %empty  */
#line 190 "myParser.y"
                                                {(yyval.args) = 0;}
#line 1822 "parser.c"
    break;

  case 62: /* argList: argList COMMA exp  */
#line 193 "myParser.y"
        {(yyval.argsList) = createArgsList((yyvsp[-2].argsList), (yyvsp[0].expr));}
#line 1828 "parser.c"
    break;

  case 63: /* argList: exp  */
#line 195 "myParser.y"
        {(yyval.argsList) = createArgsList(0, (yyvsp[0].expr));}
#line 1834 "parser.c"
    break;


#line 1838 "parser.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 199 "myParser.y"


// C code 

    // The grammar:
    // Prog -> DecList;
    // DecList -> DecList Dec | Dec
    // Dec -> VarDec | FuncDec
    // VarDec -> TypeID; | TypeID[NUM]
    // Type -> INT | VOID
    // FuncDec -> TypeID(Params)CompStmt
    // Params -> ParamList | VOID
    // ParamList -> ParamList,Param | Param
    // Param -> Type ID | Type ID[]
    // the bellow line may need to be checked
    // CompStmt -> {LocalDecs StmtList}
    // LocalDecs -> LocalDecs VarDecs | empty
    // StmtList -> StmtList Stmt | " "
    // Stmt -> ExpStmt | CompStmt | SelecStmt | IterStmt | ReturnStmt
    // ExpStmt -> Exp;
    // SelecStmt -> IF(Exp) Stmt | IF(Exp) Stmt ELSE Stmt
    // IterStmt -> WHILE(Exp) Stmt
    // ReturnStmt -> RETURN ; | RETURN Exp;
    // Exp -> Var = Exp | SimpExp
    // Var -> ID | ID[Exp] 
    // SimpExp -> AddExp RelateOp AddExp | AddExp
    // RelateOp -> LESS_EQUALS | LESS | GREATER | GREATER_EQUALS | EQUALS_EQUALS | NOT_EQUALS
    // AddExp -> AddExp AddOp Term | Term
    // AddOp -> PLUS | MINUS
    // Term -> Term MulOp Fact | Fact
    // MulOp -> MULT | DIV
    // Fact -> (Exp) | Var | Call | NUM
    // Call -> ID(Args)
    // Args -> ArgList | " "
    // ArgList -> ArgList, Exp | Exp 


int main(int argc, char **argv){
   /*

    if(argc > 1){
        yyin = fopen(argv[1], "r");
        if(!yyin){
            printf("error reading the file: %s\n", argv[1]);
            return 1;
        }
    }else {
        printf("usage: ./parser <filename>");
        return 1;
    }

    int result = yyparse();


    if(result == 0){
        printExpr(parser_result);
        printf("\nparsing successful");
    }else {
        printf("parsing failed");
    }

   */

    if(argc > 1){
        yyin = fopen(argv[1], "r");
        if(!yyin){
            printf("error reading the file: %s\n", argv[1]);
            return 1;
        }
    }else {
        printf("usage: ./parser <filename>");
        return 1;
    }

    int result = yyparse();

    if(result == 0){
        printf("pring the tree!\n");
        checkTree(parser_result);
        printTree(parser_result);
        printf("\nparsing successful\n");
    }else {
        printf("parsing failed");
    }

    return result;

}

int yyerror(char *msg){
    printf("parsing failed: %s\n", msg);
    return 1;
}
