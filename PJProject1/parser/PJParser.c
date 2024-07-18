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
#line 7 "PJParser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <util/general.h>
#include <util/symtab.h>
#include <math.h>

#define SYMTABLE_SIZE 100
#define SYMTAB_VALUE_FIELD  "value"

/* delete or comment out the line below after you have a good grasp of Project 1. It will turn off all printf statements that print the grammar rules */ 
//#define PROJECT1
/*********************EXTERNAL DECLARATIONS***********************/

EXTERN(void,yyerror,(char*));
EXTERN(int,yylex,(void));

char *fileName;

extern int yylineno;
extern char *yytext;
extern FILE *yyin;

SymTable globalSymtab;

static int getValue(char *name);
static void setValue(char *name, int value);

#line 102 "PJParser.c"

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

#include "PJParser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_AND = 3,                      /* T_AND  */
  YYSYMBOL_T_ELSE = 4,                     /* T_ELSE  */
  YYSYMBOL_T_FLOAT = 5,                    /* T_FLOAT  */
  YYSYMBOL_T_FOR = 6,                      /* T_FOR  */
  YYSYMBOL_T_IF = 7,                       /* T_IF  */
  YYSYMBOL_T_LONGINT = 8,                  /* T_LONGINT  */
  YYSYMBOL_T_BOOLEAN = 9,                  /* T_BOOLEAN  */
  YYSYMBOL_T_PROGRAM = 10,                 /* T_PROGRAM  */
  YYSYMBOL_T_FUNCTION = 11,                /* T_FUNCTION  */
  YYSYMBOL_T_NOT = 12,                     /* T_NOT  */
  YYSYMBOL_T_OR = 13,                      /* T_OR  */
  YYSYMBOL_T_READ = 14,                    /* T_READ  */
  YYSYMBOL_T_WHILE = 15,                   /* T_WHILE  */
  YYSYMBOL_T_WRITE = 16,                   /* T_WRITE  */
  YYSYMBOL_T_WRITELN = 17,                 /* T_WRITELN  */
  YYSYMBOL_T_BEGIN = 18,                   /* T_BEGIN  */
  YYSYMBOL_T_END = 19,                     /* T_END  */
  YYSYMBOL_T_VAR = 20,                     /* T_VAR  */
  YYSYMBOL_T_DO = 21,                      /* T_DO  */
  YYSYMBOL_T_ARRAY = 22,                   /* T_ARRAY  */
  YYSYMBOL_T_EXIT = 23,                    /* T_EXIT  */
  YYSYMBOL_T_THEN = 24,                    /* T_THEN  */
  YYSYMBOL_T_LE = 25,                      /* T_LE  */
  YYSYMBOL_T_LT = 26,                      /* T_LT  */
  YYSYMBOL_T_GE = 27,                      /* T_GE  */
  YYSYMBOL_T_GT = 28,                      /* T_GT  */
  YYSYMBOL_T_EQ = 29,                      /* T_EQ  */
  YYSYMBOL_T_NE = 30,                      /* T_NE  */
  YYSYMBOL_T_ASSIGN = 31,                  /* T_ASSIGN  */
  YYSYMBOL_T_COMMA = 32,                   /* T_COMMA  */
  YYSYMBOL_T_SEMICOLON = 33,               /* T_SEMICOLON  */
  YYSYMBOL_T_COLON = 34,                   /* T_COLON  */
  YYSYMBOL_T_LBRACKET = 35,                /* T_LBRACKET  */
  YYSYMBOL_T_RBRACKET = 36,                /* T_RBRACKET  */
  YYSYMBOL_T_LPAREN = 37,                  /* T_LPAREN  */
  YYSYMBOL_T_RPAREN = 38,                  /* T_RPAREN  */
  YYSYMBOL_T_PLUS = 39,                    /* T_PLUS  */
  YYSYMBOL_T_TIMES = 40,                   /* T_TIMES  */
  YYSYMBOL_T_IDENTIFIER = 41,              /* T_IDENTIFIER  */
  YYSYMBOL_T_DIV = 42,                     /* T_DIV  */
  YYSYMBOL_T_STRING = 43,                  /* T_STRING  */
  YYSYMBOL_T_INTNUM = 44,                  /* T_INTNUM  */
  YYSYMBOL_T_FLOATNUM = 45,                /* T_FLOATNUM  */
  YYSYMBOL_T_MINUS = 46,                   /* T_MINUS  */
  YYSYMBOL_T_DOT = 47,                     /* T_DOT  */
  YYSYMBOL_T_DOTDOT = 48,                  /* T_DOTDOT  */
  YYSYMBOL_T_OF = 49,                      /* T_OF  */
  YYSYMBOL_T_TRUE = 50,                    /* T_TRUE  */
  YYSYMBOL_T_FALSE = 51,                   /* T_FALSE  */
  YYSYMBOL_YYACCEPT = 52,                  /* $accept  */
  YYSYMBOL_Program = 53,                   /* Program  */
  YYSYMBOL_ProgramHeadAndProcedures = 54,  /* ProgramHeadAndProcedures  */
  YYSYMBOL_ProgramHead = 55,               /* ProgramHead  */
  YYSYMBOL_Decls = 56,                     /* Decls  */
  YYSYMBOL_DeclList = 57,                  /* DeclList  */
  YYSYMBOL_IdentifierList = 58,            /* IdentifierList  */
  YYSYMBOL_Type = 59,                      /* Type  */
  YYSYMBOL_StandardType = 60,              /* StandardType  */
  YYSYMBOL_ArrayType = 61,                 /* ArrayType  */
  YYSYMBOL_Dim = 62,                       /* Dim  */
  YYSYMBOL_Procedures = 63,                /* Procedures  */
  YYSYMBOL_ProcedureDecl = 64,             /* ProcedureDecl  */
  YYSYMBOL_ProcedureHead = 65,             /* ProcedureHead  */
  YYSYMBOL_FunctionDecl = 66,              /* FunctionDecl  */
  YYSYMBOL_ProcedureBody = 67,             /* ProcedureBody  */
  YYSYMBOL_Statement = 68,                 /* Statement  */
  YYSYMBOL_Assignment = 69,                /* Assignment  */
  YYSYMBOL_IfStatement = 70,               /* IfStatement  */
  YYSYMBOL_TestAndThen = 71,               /* TestAndThen  */
  YYSYMBOL_Test = 72,                      /* Test  */
  YYSYMBOL_WhileStatement = 73,            /* WhileStatement  */
  YYSYMBOL_WhileExpr = 74,                 /* WhileExpr  */
  YYSYMBOL_WhileToken = 75,                /* WhileToken  */
  YYSYMBOL_IOStatement = 76,               /* IOStatement  */
  YYSYMBOL_OutputFormat = 77,              /* OutputFormat  */
  YYSYMBOL_WriteToken = 78,                /* WriteToken  */
  YYSYMBOL_ExitStatement = 79,             /* ExitStatement  */
  YYSYMBOL_CompoundStatement = 80,         /* CompoundStatement  */
  YYSYMBOL_StatementList = 81,             /* StatementList  */
  YYSYMBOL_Expr = 82,                      /* Expr  */
  YYSYMBOL_AddExpr = 83,                   /* AddExpr  */
  YYSYMBOL_MulExpr = 84,                   /* MulExpr  */
  YYSYMBOL_Factor = 85,                    /* Factor  */
  YYSYMBOL_Variable = 86,                  /* Variable  */
  YYSYMBOL_Constant = 87                   /* Constant  */
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
typedef yytype_uint8 yy_state_t;

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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   168

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  155

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   306


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   113,   113,   121,   129,   138,   145,   152,   158,   166,
     172,   179,   185,   193,   199,   205,   213,   219,   227,   235,
     242,   249,   257,   265,   273,   281,   287,   293,   299,   305,
     311,   319,   329,   335,   343,   351,   359,   367,   375,   383,
     394,   429,   467,   475,   483,   490,   498,   506,   514,   520,
     529,   536,   548,   560,   572,   584,   596,   610,   617,   629,
     636,   645,   652,   659,   666,   681,   688,   695,   702,   708,
     719,   726,   732,   741,   748,   755,   762,   769
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "T_AND", "T_ELSE",
  "T_FLOAT", "T_FOR", "T_IF", "T_LONGINT", "T_BOOLEAN", "T_PROGRAM",
  "T_FUNCTION", "T_NOT", "T_OR", "T_READ", "T_WHILE", "T_WRITE",
  "T_WRITELN", "T_BEGIN", "T_END", "T_VAR", "T_DO", "T_ARRAY", "T_EXIT",
  "T_THEN", "T_LE", "T_LT", "T_GE", "T_GT", "T_EQ", "T_NE", "T_ASSIGN",
  "T_COMMA", "T_SEMICOLON", "T_COLON", "T_LBRACKET", "T_RBRACKET",
  "T_LPAREN", "T_RPAREN", "T_PLUS", "T_TIMES", "T_IDENTIFIER", "T_DIV",
  "T_STRING", "T_INTNUM", "T_FLOATNUM", "T_MINUS", "T_DOT", "T_DOTDOT",
  "T_OF", "T_TRUE", "T_FALSE", "$accept", "Program",
  "ProgramHeadAndProcedures", "ProgramHead", "Decls", "DeclList",
  "IdentifierList", "Type", "StandardType", "ArrayType", "Dim",
  "Procedures", "ProcedureDecl", "ProcedureHead", "FunctionDecl",
  "ProcedureBody", "Statement", "Assignment", "IfStatement", "TestAndThen",
  "Test", "WhileStatement", "WhileExpr", "WhileToken", "IOStatement",
  "OutputFormat", "WriteToken", "ExitStatement", "CompoundStatement",
  "StatementList", "Expr", "AddExpr", "MulExpr", "Factor", "Variable",
  "Constant", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-93)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -4,   -17,    30,     9,   -93,     0,   -93,     3,   -10,    29,
      16,    43,    11,   -93,   -93,   -93,    17,    28,   -93,   -93,
     -93,   -93,    43,   -93,    23,   -93,   -93,   -11,    31,   -93,
      24,   -93,     9,    16,    33,   -93,    43,    43,   -21,   -93,
     -93,    32,   -93,   -93,    65,    51,   129,    10,     1,   -93,
     -93,   -93,    38,    43,    43,    60,   129,    27,   -93,     3,
      43,    48,   -93,    53,   -93,   -93,    33,    13,   -93,    75,
      52,   -93,     3,     3,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    54,    81,    95,     3,
      57,   119,   -93,   129,     4,   -93,    25,    55,    20,   -93,
     -93,   -93,   -93,    10,    10,    10,    10,    10,    10,     1,
       1,     1,   -93,   -93,   -93,   -93,   -93,    43,   -93,   -93,
      68,    59,    76,   -93,   -93,   -93,    93,    20,   -93,    94,
      97,   -93,   -93,   107,   -93,   -93,   -93,   -93,   105,    84,
     -93,   -93,   -93,    91,   -25,    96,    84,    92,   -93,   106,
       4,   101,   -93,     4,   -93
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,    20,     0,     1,     0,     0,     3,
       6,     0,     0,    38,    44,    45,     0,    70,    49,    25,
      26,    27,     0,    28,     0,    29,    30,     0,     0,     2,
       0,    19,     0,     6,     0,     4,     0,     0,    70,    75,
      73,     0,    76,    77,    33,     0,    35,    50,    57,    61,
      65,    66,     0,     0,     0,     0,    37,     0,    47,     0,
       0,     0,    21,     0,    22,     9,     5,     0,    67,     0,
       0,    74,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      43,    43,    48,    31,     0,    24,     0,     0,     0,    69,
      68,    32,    34,    53,    54,    55,    56,    51,    52,    58,
      59,    60,    64,    62,    63,    39,    46,     0,    71,    36,
       0,     0,     0,    15,    13,    14,     0,     0,    10,     0,
       0,    11,    12,     0,    42,    41,    40,    23,     0,     0,
       7,    72,     8,     0,     0,     0,     0,     0,    18,     0,
       0,     0,    16,     0,    17
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -93,   -93,   -93,   -93,   118,   -93,   100,    40,   -92,   -93,
       6,   -93,   -93,   -93,   -93,   -93,    26,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,    77,   -93,   -93,     2,   -93,
     -22,    86,    36,   -33,    -6,   -93
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     4,    35,    66,    67,   130,   131,   132,
     144,     9,    31,    32,    33,    62,    18,    19,    20,    44,
      45,    21,    55,    22,    23,   121,    24,    25,    26,    27,
      46,    47,    48,    49,    50,    51
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      56,    28,   126,    68,    83,     8,     1,   146,    58,   123,
      11,   147,   124,   125,    54,    69,    70,    12,    13,    14,
      15,     7,    59,    80,     5,   123,    16,     7,   124,   125,
       6,    87,    88,    10,    63,    91,    34,    29,    93,    36,
      30,    84,   129,    85,    17,    97,    86,    98,    52,    81,
     112,   113,   114,    28,    53,    36,    82,    97,   152,   127,
      57,   154,    60,    54,    37,    61,    28,    28,    38,    72,
      90,    39,    40,    41,    65,    73,    71,    42,    43,    17,
      37,    89,    94,    28,    38,    92,    95,    39,    40,    41,
     100,   120,   115,    42,    43,   133,   128,   135,   101,   102,
      74,    75,    76,    77,    78,    79,    74,    75,    76,    77,
      78,    79,   134,    99,   136,   119,   109,   110,   111,   116,
      74,    75,    76,    77,    78,    79,   137,   117,   143,   139,
     140,   118,    74,    75,    76,    77,    78,    79,   142,   145,
     148,   150,   151,   141,    74,    75,    76,    77,    78,    79,
     153,    64,   149,   120,    74,    75,    76,    77,    78,    79,
     103,   104,   105,   106,   107,   108,    96,   138,   122
};

static const yytype_uint8 yycheck[] =
{
      22,     7,    94,    36,     3,     3,    10,    32,    19,     5,
       7,    36,     8,     9,    35,    37,    37,    14,    15,    16,
      17,    18,    33,    13,    41,     5,    23,    18,     8,     9,
       0,    53,    54,    33,    32,    57,    20,    47,    60,    12,
      11,    40,    22,    42,    41,    32,    52,    34,    37,    39,
      83,    84,    85,    59,    37,    12,    46,    32,   150,    34,
      37,   153,    31,    35,    37,    41,    72,    73,    41,     4,
      43,    44,    45,    46,    41,    24,    44,    50,    51,    41,
      37,    21,    34,    89,    41,    59,    33,    44,    45,    46,
      38,    34,    38,    50,    51,   117,    41,    38,    72,    73,
      25,    26,    27,    28,    29,    30,    25,    26,    27,    28,
      29,    30,    44,    38,    38,    89,    80,    81,    82,    38,
      25,    26,    27,    28,    29,    30,    33,    32,    44,    35,
      33,    36,    25,    26,    27,    28,    29,    30,    33,    48,
      44,    49,    36,    36,    25,    26,    27,    28,    29,    30,
      49,    33,   146,    34,    25,    26,    27,    28,    29,    30,
      74,    75,    76,    77,    78,    79,    66,   127,    91
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    10,    53,    54,    55,    41,     0,    18,    80,    63,
      33,     7,    14,    15,    16,    17,    23,    41,    68,    69,
      70,    73,    75,    76,    78,    79,    80,    81,    86,    47,
      11,    64,    65,    66,    20,    56,    12,    37,    41,    44,
      45,    46,    50,    51,    71,    72,    82,    83,    84,    85,
      86,    87,    37,    37,    35,    74,    82,    37,    19,    33,
      31,    41,    67,    80,    56,    41,    57,    58,    85,    82,
      37,    44,     4,    24,    25,    26,    27,    28,    29,    30,
      13,    39,    46,     3,    40,    42,    86,    82,    82,    21,
      43,    82,    68,    82,    34,    33,    58,    32,    34,    38,
      38,    68,    68,    83,    83,    83,    83,    83,    83,    84,
      84,    84,    85,    85,    85,    38,    38,    32,    36,    68,
      34,    77,    77,     5,     8,     9,    60,    34,    41,    22,
      59,    60,    61,    82,    44,    38,    38,    33,    59,    35,
      33,    36,    33,    44,    62,    48,    32,    36,    44,    62,
      49,    36,    60,    49,    60
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    52,    53,    54,    55,    56,    56,    57,    57,    58,
      58,    59,    59,    60,    60,    60,    61,    61,    62,    63,
      63,    64,    65,    66,    67,    68,    68,    68,    68,    68,
      68,    69,    70,    70,    71,    72,    73,    74,    75,    76,
      76,    76,    77,    77,    78,    78,    79,    80,    81,    81,
      82,    82,    82,    82,    82,    82,    82,    83,    83,    83,
      83,    84,    84,    84,    84,    85,    85,    85,    85,    85,
      86,    86,    86,    87,    87,    87,    87,    87
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     4,     2,     0,     4,     5,     1,
       3,     1,     1,     1,     1,     1,     6,     8,     3,     2,
       0,     2,     2,     5,     2,     1,     1,     1,     1,     1,
       1,     3,     4,     2,     3,     1,     4,     1,     1,     4,
       5,     5,     2,     0,     1,     1,     4,     3,     3,     1,
       1,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       3,     1,     3,     3,     3,     1,     1,     2,     3,     3,
       1,     4,     6,     1,     2,     1,     1,     1
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
  case 2: /* Program: ProgramHeadAndProcedures CompoundStatement T_DOT  */
#line 114 "PJParser.y"
                {
		  #ifdef PROJECT1
		  printf("Program : ProgramHeadAndProcedures CompoundStatement T_DOT\n");		
		  #endif
          	}
#line 1290 "PJParser.c"
    break;

  case 3: /* ProgramHeadAndProcedures: ProgramHead Procedures  */
#line 122 "PJParser.y"
                {
		  #ifdef PROJECT1
		  printf("ProgramHeadAndProcedures : ProgramHead Procedure\n");		
		  #endif
		}
#line 1300 "PJParser.c"
    break;

  case 4: /* ProgramHead: T_PROGRAM T_IDENTIFIER T_SEMICOLON Decls  */
#line 130 "PJParser.y"
                {
		  #ifdef PROJECT1
		  printf("ProgramHead : T_PROGRAM T_IDENTIFIER T_SEMICOLON Decls \n");		
		  #endif
		}
#line 1310 "PJParser.c"
    break;

  case 5: /* Decls: T_VAR DeclList  */
#line 139 "PJParser.y"
                {
		  #ifdef PROJECT1
		  printf("Decls : T_VAR DeclList\n");		
		  #endif
		}
#line 1320 "PJParser.c"
    break;

  case 6: /* Decls: %empty  */
#line 145 "PJParser.y"
                {
		  #ifdef PROJECT1
		  printf("Decls : \n");		
		  #endif
		}
#line 1330 "PJParser.c"
    break;

  case 7: /* DeclList: IdentifierList T_COLON Type T_SEMICOLON  */
#line 153 "PJParser.y"
                {   
		  #ifdef PROJECT1
		  printf("DeclList : IdentifierList T_COLON Type T_SEMICOLON\n");		
		  #endif
		}
#line 1340 "PJParser.c"
    break;

  case 8: /* DeclList: DeclList IdentifierList T_COLON Type T_SEMICOLON  */
#line 159 "PJParser.y"
                {
		  #ifdef PROJECT1
		  printf("DeclList : DeclList IdentifierList T_COLON Type T_SEMICOLON\n");		
		  #endif
		}
#line 1350 "PJParser.c"
    break;

  case 9: /* IdentifierList: T_IDENTIFIER  */
#line 167 "PJParser.y"
                {
		  #ifdef PROJECT1
		  printf("IdentifierList : T_IDENTIFIER\n");		
		  #endif
		}
#line 1360 "PJParser.c"
    break;

  case 10: /* IdentifierList: IdentifierList T_COMMA T_IDENTIFIER  */
#line 173 "PJParser.y"
                {
		  #ifdef PROJECT1
		  printf("IdentifierList : IdentifierList T_COMMA T_IDENTIFIER\n");		
		  #endif
		}
#line 1370 "PJParser.c"
    break;

  case 11: /* Type: StandardType  */
#line 180 "PJParser.y"
                {
		  #ifdef PROJECT1
		  printf("Type : StandardType\n");		
		  #endif
		}
#line 1380 "PJParser.c"
    break;

  case 12: /* Type: ArrayType  */
#line 186 "PJParser.y"
                {
		  #ifdef PROJECT1
		  printf("Type : ArrayType\n");		
		  #endif
	 	}
#line 1390 "PJParser.c"
    break;

  case 13: /* StandardType: T_LONGINT  */
#line 194 "PJParser.y"
                {
		  #ifdef PROJECT1
		  printf("StandardType : T_LONGINT\n");		
		  #endif
		}
#line 1400 "PJParser.c"
    break;

  case 14: /* StandardType: T_BOOLEAN  */
#line 200 "PJParser.y"
                {
		  #ifdef PROJECT1
		  printf("StandardType : T_BOOLEAN\n");		
		  #endif
		}
#line 1410 "PJParser.c"
    break;

  case 15: /* StandardType: T_FLOAT  */
#line 206 "PJParser.y"
                {
		  #ifdef PROJECT1
		  printf("StandardType : T_FLOAT\n");		
		  #endif
		}
#line 1420 "PJParser.c"
    break;

  case 16: /* ArrayType: T_ARRAY T_LBRACKET Dim T_RBRACKET T_OF StandardType  */
#line 214 "PJParser.y"
                {
		  #ifdef PROJECT1
		  printf("ArrayType : T_ARRAY T_LBRACKET Dim T_RBRACKET T_OF StandardType\n");		
		  #endif
		}
#line 1430 "PJParser.c"
    break;

  case 17: /* ArrayType: T_ARRAY T_LBRACKET Dim T_COMMA Dim T_RBRACKET T_OF StandardType  */
#line 220 "PJParser.y"
                {
		  #ifdef PROJECT1
		  printf("ArrayType : T_ARRAY T_LBRACKET Dim T_COMMA Dim T_RBRACKET T_OF StandardType\n");		
		  #endif
		}
#line 1440 "PJParser.c"
    break;

  case 18: /* Dim: T_INTNUM T_DOTDOT T_INTNUM  */
#line 228 "PJParser.y"
                {
		  #ifdef PROJECT1
		  printf("Dim : T_INTNUM T_DOTDOT T_INTNUM\n");		
		  #endif
		}
#line 1450 "PJParser.c"
    break;

  case 19: /* Procedures: Procedures ProcedureDecl  */
#line 236 "PJParser.y"
                {
		  #ifdef PROJECT1
		  printf("Procedures : Procedures ProcedureDecl\n");		
		  #endif
		}
#line 1460 "PJParser.c"
    break;

  case 20: /* Procedures: %empty  */
#line 242 "PJParser.y"
                {
		  #ifdef PROJECT1
		  printf("Procedures :\n");		
		  #endif
		}
#line 1470 "PJParser.c"
    break;

  case 21: /* ProcedureDecl: ProcedureHead ProcedureBody  */
#line 250 "PJParser.y"
                {
		  #ifdef PROJECT1
		  printf("ProcedureDecl : ProcedureHead ProcedureBody\n");		
		  #endif
		}
#line 1480 "PJParser.c"
    break;

  case 22: /* ProcedureHead: FunctionDecl Decls  */
#line 258 "PJParser.y"
                {
		  #ifdef PROJECT1
		  printf("ProcedureHead : FunctionDecl Decls\n");		
		  #endif
		}
#line 1490 "PJParser.c"
    break;

  case 23: /* FunctionDecl: T_FUNCTION T_IDENTIFIER T_COLON StandardType T_SEMICOLON  */
#line 266 "PJParser.y"
                {
		  #ifdef PROJECT1
		  printf("FunctionDecl : T_FUNCTION T_IDENTIFIER T_COLON StandardType T_SEMICOLON\n");		
		  #endif
		}
#line 1500 "PJParser.c"
    break;

  case 24: /* ProcedureBody: CompoundStatement T_SEMICOLON  */
#line 274 "PJParser.y"
                {
		  #ifdef PROJECT1
		  printf("ProcedureBody : CompoundStatement T_SEMICOLON\n");		
		  #endif
		}
#line 1510 "PJParser.c"
    break;

  case 25: /* Statement: Assignment  */
#line 282 "PJParser.y"
                {
		  #ifdef PROJECT1
		  printf("Statement : Assignment\n");		
		  #endif
		}
#line 1520 "PJParser.c"
    break;

  case 26: /* Statement: IfStatement  */
#line 288 "PJParser.y"
                {
		  #ifdef PROJECT1
		  printf("Statement : IfStatement\n");		
		  #endif
		}
#line 1530 "PJParser.c"
    break;

  case 27: /* Statement: WhileStatement  */
#line 294 "PJParser.y"
                {
		  #ifdef PROJECT1
		  printf("Statement : WhileStatement\n");		
		  #endif
		}
#line 1540 "PJParser.c"
    break;

  case 28: /* Statement: IOStatement  */
#line 300 "PJParser.y"
                {
		  #ifdef PROJECT1
		  printf("Statement : IOStatement\n");		
		  #endif
		}
#line 1550 "PJParser.c"
    break;

  case 29: /* Statement: ExitStatement  */
#line 306 "PJParser.y"
                {
		  #ifdef PROJECT1
		  printf("Statement : ExitStatement\n");		
		  #endif
		}
#line 1560 "PJParser.c"
    break;

  case 30: /* Statement: CompoundStatement  */
#line 312 "PJParser.y"
                {
		  #ifdef PROJECT1
		  printf("Statement : CompoundStatement\n");		
		  #endif
		}
#line 1570 "PJParser.c"
    break;

  case 31: /* Assignment: Variable T_ASSIGN Expr  */
#line 320 "PJParser.y"
                { 
		  setValue((yyvsp[-2].name), (yyvsp[0].value)); //set value in symtable to not overwrite registers

		  #ifdef PROJECT1
		  printf("Assignment : Variable T_ASSIGN Expr\n");		
		  #endif
		}
#line 1582 "PJParser.c"
    break;

  case 32: /* IfStatement: T_IF TestAndThen T_ELSE Statement  */
#line 330 "PJParser.y"
                {
		  #ifdef PROJECT1
		  printf("IfStatement : T_IF TestAndThen T_ELSE Statement\n");		
		  #endif
		}
#line 1592 "PJParser.c"
    break;

  case 33: /* IfStatement: T_IF TestAndThen  */
#line 336 "PJParser.y"
                {
		  #ifdef PROJECT1
		  printf("IfStatement : T_IF TestAndThen\n");		
		  #endif
		}
#line 1602 "PJParser.c"
    break;

  case 34: /* TestAndThen: Test T_THEN Statement  */
#line 344 "PJParser.y"
                {
		  #ifdef PROJECT1
		  printf("TestAndThen : Test T_THEN Statement\n");		
		  #endif
	    	}
#line 1612 "PJParser.c"
    break;

  case 35: /* Test: Expr  */
#line 352 "PJParser.y"
                {
		  #ifdef PROJECT1
		  printf("Test : Expr \n");		
		  #endif
		}
#line 1622 "PJParser.c"
    break;

  case 36: /* WhileStatement: WhileToken WhileExpr T_DO Statement  */
#line 360 "PJParser.y"
                {
		  #ifdef PROJECT1
		  printf("WhileStatement : WhileToken WhileExpr T_DO Statement\n");		
		  #endif
		}
#line 1632 "PJParser.c"
    break;

  case 37: /* WhileExpr: Expr  */
#line 368 "PJParser.y"
                {
		  #ifdef PROJECT1
		  printf("WhileExpr : Expr \n");		
		  #endif
		}
#line 1642 "PJParser.c"
    break;

  case 38: /* WhileToken: T_WHILE  */
#line 376 "PJParser.y"
                {
		  #ifdef PROJECT1
		  printf("WhileToken : T_WHILE\n");		
		  #endif
		}
#line 1652 "PJParser.c"
    break;

  case 39: /* IOStatement: T_READ T_LPAREN Variable T_RPAREN  */
#line 384 "PJParser.y"
                { 
		  
		  int val; //integer to be read in
		  scanf("%d", &val);
		  setValue((yyvsp[-1].name), val); //set value in symtab to not overwrite other registers

		  #ifdef PROJECT1
		  printf("IOStatement : T_READ T_LPAREN Variable T_RPAREN\n");		
		  #endif
		}
#line 1667 "PJParser.c"
    break;

  case 40: /* IOStatement: WriteToken T_LPAREN Expr OutputFormat T_RPAREN  */
#line 395 "PJParser.y"
                { 


		  int digits = ceil((yyvsp[-2].value)/10); //how many digits are in the expr (for formatting)
		  int space = 0;
		  if ((yyvsp[-1].value) - digits > 0 && (yyvsp[-1].value) != 0){
			space = (yyvsp[-1].value) - digits; //formatting
		  }

		  if ((yyvsp[-2].value) < 0){
			space -= 1;
		  }

		  char format [space]; //fill with spaces 

		  for (int i = 0; i < space; i++){ //add extra spaces onto string
			format[i] = ' ';
		  }
		  
		  format[space] = '\0'; //setting the last value in char array to /0 so no junk values are printed

		
		  
			if ((yyvsp[-4].value))
				printf("%s%d\n", format, (yyvsp[-2].value));
			else
				printf("%s%d", format, (yyvsp[-2].value));
	
		  

		  #ifdef PROJECT1
		  printf("IOStatement : WriteToken T_LPAREN Expr OutputFormat T_RPAREN\n");		
		  #endif
		}
#line 1706 "PJParser.c"
    break;

  case 41: /* IOStatement: WriteToken T_LPAREN T_STRING OutputFormat T_RPAREN  */
#line 430 "PJParser.y"
                { 
		 
		  int size = strlen((yyvsp[-2].name));
		  int altSize = size - 2; 
		  int dif  = 0;

		  if((yyvsp[-1].value) - (size - 2) > 0){ //pascal disregards formatting if number of chars is greater then format value therefore only set if necessary
			altSize = (yyvsp[-1].value);
			dif = (yyvsp[-1].value) - (size - 2);
		  }

		  char format [dif];

		  char newstr [size - 2]; //size of string without back quotes
		  
		  for (int i = 0; i < dif; i++){ //format string 
			format[i] = ' ';
		  }
		  	format[dif] = '\0'; //setting the last value in char array to /0 so no junk values are printed

		  for (int i = 1; i < size - 1; i++){ //copy string without single quotes
			newstr[i-1] = (yyvsp[-2].name)[i];
		  }

		  newstr[size - 2] = '\0'; //setting the last value in char array to /0 so no junk values are printed

		  if ((yyvsp[-4].value))
		  	 printf("%s%s\n", format, newstr);
		  else
		  	printf("%s%s", format, newstr);

		  #ifdef PROJECT1
		  printf("IOStatement : WriteToken T_LPAREN T_STRING OutputFormat T_RPAREN\n");		
		  #endif
		}
#line 1746 "PJParser.c"
    break;

  case 42: /* OutputFormat: T_COLON T_INTNUM  */
#line 468 "PJParser.y"
                {
		  (yyval.value) = (yyvsp[0].value); //set value of output format to the amount of space allocated
		  #ifdef PROJECT1
		  printf("OutputFormat : T_COLON T_INTNUM\n");		
		  #endif
		}
#line 1757 "PJParser.c"
    break;

  case 43: /* OutputFormat: %empty  */
#line 475 "PJParser.y"
                {
		  (yyval.value) = 0;
		  #ifdef PROJECT1
		  printf("OutputFormat : \n");		
		  #endif
		}
#line 1768 "PJParser.c"
    break;

  case 44: /* WriteToken: T_WRITE  */
#line 484 "PJParser.y"
                {
		  (yyval.value) = 0; //setting T_Write to 0 in order to differentiate it from T_WriteLN
		  #ifdef PROJECT1
		  printf("WriteToken : T_WRITE\n");		
		  #endif
		}
#line 1779 "PJParser.c"
    break;

  case 45: /* WriteToken: T_WRITELN  */
#line 491 "PJParser.y"
                {
		  (yyval.value) = 1;
		  #ifdef PROJECT1
		  printf("WriteToken : T_WRITELN\n");		
		  #endif
		}
#line 1790 "PJParser.c"
    break;

  case 46: /* ExitStatement: T_EXIT T_LPAREN Expr T_RPAREN  */
#line 499 "PJParser.y"
                {
		  #ifdef PROJECT1
		  printf("ExitStatement : T_EXIT T_LPAREN Expr T_RPAREN\n");		
		  #endif
		}
#line 1800 "PJParser.c"
    break;

  case 47: /* CompoundStatement: T_BEGIN StatementList T_END  */
#line 507 "PJParser.y"
                {
		  #ifdef PROJECT1
		  printf("CompoundStatement : T_BEGIN StatementList T_END\n");		
		  #endif
		}
#line 1810 "PJParser.c"
    break;

  case 48: /* StatementList: StatementList T_SEMICOLON Statement  */
#line 515 "PJParser.y"
                {
		  #ifdef PROJECT1
		  printf("StatementList : StatementList T_SEMICOLON Statement\n");		
		  #endif
		}
#line 1820 "PJParser.c"
    break;

  case 49: /* StatementList: Statement  */
#line 521 "PJParser.y"
                {
		  #ifdef PROJECT1
		  printf("StatementList : Statement\n");		
		  #endif
		}
#line 1830 "PJParser.c"
    break;

  case 50: /* Expr: AddExpr  */
#line 530 "PJParser.y"
                {
		  (yyval.value) = (yyvsp[0].value);
		  #ifdef PROJECT1
		  printf("Expr : AddExpr\n");		
		  #endif
		}
#line 1841 "PJParser.c"
    break;

  case 51: /* Expr: Expr T_EQ AddExpr  */
#line 537 "PJParser.y"
                {
		  if((yyvsp[-2].value) == (yyvsp[0].value)){ //if eq true
			(yyval.value) = true;
		  }	
		  else{
			(yyval.value) = false;
		  }
		  #ifdef PROJECT1
		  printf("Expr : Expr T_EQ AddExpr\n");		
		  #endif
		}
#line 1857 "PJParser.c"
    break;

  case 52: /* Expr: Expr T_NE AddExpr  */
#line 549 "PJParser.y"
                {
		  if ((yyvsp[-2].value) != (yyvsp[0].value)){ //if ne true
			(yyval.value) = true;
		  }
		  else{
			(yyval.value)=false;
		  }
		  #ifdef PROJECT1
		  printf("Expr : Expr T_NE AddExpr\n");		
		  #endif
		}
#line 1873 "PJParser.c"
    break;

  case 53: /* Expr: Expr T_LE AddExpr  */
#line 561 "PJParser.y"
                {
		  if((yyvsp[-2].value) <= (yyvsp[0].value)){ //if le true
			(yyval.value) = true;
		  }
		  else{
			(yyval.value) = false;
		  }
		  #ifdef PROJECT1
		  printf("Expr : Expr T_LE AddExpr\n");		
		  #endif
		}
#line 1889 "PJParser.c"
    break;

  case 54: /* Expr: Expr T_LT AddExpr  */
#line 573 "PJParser.y"
                {
		  if((yyvsp[-2].value) < (yyvsp[0].value)){ //if lt true
			(yyval.value) = true;
		  }
		  else{
			(yyval.value) = false;
		  }
		  #ifdef PROJECT1
		  printf("Expr : Expr T_LT AddExpr\n");		
		  #endif
		}
#line 1905 "PJParser.c"
    break;

  case 55: /* Expr: Expr T_GE AddExpr  */
#line 585 "PJParser.y"
                {
		  if((yyvsp[-2].value) >= (yyvsp[0].value)){ //if ge true
			(yyval.value) = true;
		  }
		  else{
			(yyval.value) = false;
		  }
		  #ifdef PROJECT1
		  printf("Expr : Expr T_GE AddExpr\n");		
		  #endif
		}
#line 1921 "PJParser.c"
    break;

  case 56: /* Expr: Expr T_GT AddExpr  */
#line 597 "PJParser.y"
                {
		  if((yyvsp[-2].value) > (yyvsp[0].value)){ //if gt true
			(yyval.value) = true;
		  }
		  else{
			(yyval.value) = false;
		  }
		  #ifdef PROJECT1
		  printf("Expr : Expr T_GT AddExpr\n");		
		  #endif
		}
#line 1937 "PJParser.c"
    break;

  case 57: /* AddExpr: MulExpr  */
#line 611 "PJParser.y"
                {
		  (yyval.value) = (yyvsp[0].value);
		  #ifdef PROJECT1
		  printf("AddExpr : MulExpr\n");		
		  #endif
		}
#line 1948 "PJParser.c"
    break;

  case 58: /* AddExpr: AddExpr T_OR MulExpr  */
#line 618 "PJParser.y"
                {
		  if ((yyvsp[-2].value) == true || (yyvsp[0].value) == true){ //if either addepr or mulexpr or true then true
			(yyval.value) = true;
		  }
		  else{
			(yyval.value) = false;
		  }
		  #ifdef PROJECT1
		  printf("AddExpr : AddExpr T_OR MulExpr\n");		
		  #endif
		}
#line 1964 "PJParser.c"
    break;

  case 59: /* AddExpr: AddExpr T_PLUS MulExpr  */
#line 630 "PJParser.y"
                {
		  (yyval.value) = (yyvsp[-2].value) + (yyvsp[0].value); //add registers together 
		  #ifdef PROJECT1
		  printf("AddExpr : AddExpr T_PLUS MulExpr\n");		
		  #endif
		}
#line 1975 "PJParser.c"
    break;

  case 60: /* AddExpr: AddExpr T_MINUS MulExpr  */
#line 637 "PJParser.y"
                {
		  (yyval.value) = (yyvsp[-2].value) - (yyvsp[0].value); //subtract registers
		  #ifdef PROJECT1
		  printf("AddExpr : AddExpr T_MINUS MulExpr\n");		
		  #endif
		}
#line 1986 "PJParser.c"
    break;

  case 61: /* MulExpr: Factor  */
#line 646 "PJParser.y"
                {
		  (yyval.value) = (yyvsp[0].value);
		  #ifdef PROJECT1
		  printf("MulExpr : Factor\n");		
		  #endif
                }
#line 1997 "PJParser.c"
    break;

  case 62: /* MulExpr: MulExpr T_TIMES Factor  */
#line 653 "PJParser.y"
                {
		  (yyval.value) = (yyvsp[-2].value) * (yyvsp[0].value); //multiply registers
		  #ifdef PROJECT1
		  printf("MulExpr : MulExpr T_TIMES Factor\n");		
		  #endif
		}
#line 2008 "PJParser.c"
    break;

  case 63: /* MulExpr: MulExpr T_DIV Factor  */
#line 660 "PJParser.y"
                {
	      (yyval.value) = (yyvsp[-2].value) / (yyvsp[0].value); //divide registers
		  #ifdef PROJECT1
		  printf("MulExpr : MulExpr T_DIV Factor\n");		
		  #endif
		}
#line 2019 "PJParser.c"
    break;

  case 64: /* MulExpr: MulExpr T_AND Factor  */
#line 667 "PJParser.y"
                {
		  if ((yyvsp[-2].value) == true && (yyvsp[0].value) == true){ //if both registers are true then tru
			(yyval.value) = true;
		  }
		  else{
			(yyval.value) = false;
		  }
		  #ifdef PROJECT1
		  printf("MulExpr : MulExpr T_AND Factor\n");		
		  #endif
		}
#line 2035 "PJParser.c"
    break;

  case 65: /* Factor: Variable  */
#line 682 "PJParser.y"
                { 
		  (yyval.value) = getValue((yyvsp[0].name)); // get the value of the variable set in assignment 
		  #ifdef PROJECT1
		  printf("Factor : Variable\n");		
		  #endif
		}
#line 2046 "PJParser.c"
    break;

  case 66: /* Factor: Constant  */
#line 689 "PJParser.y"
                { 
		  (yyval.value) = (yyvsp[0].value); // set factor equal to whatever the constant was 
		  #ifdef PROJECT1
		  printf("Factor : Constant\n");		
		  #endif
		}
#line 2057 "PJParser.c"
    break;

  case 67: /* Factor: T_NOT Factor  */
#line 696 "PJParser.y"
                {
		  (yyval.value) = !(yyvsp[0].value);
		  #ifdef PROJECT1
		  printf("Factor : T_NOT Factor\n");		
		  #endif
		}
#line 2068 "PJParser.c"
    break;

  case 68: /* Factor: T_IDENTIFIER T_LPAREN T_RPAREN  */
#line 703 "PJParser.y"
                {					
		  #ifdef PROJECT1
		  printf("Factor : T_IDENTIFIER T_LPAREN T_RPAREN\n");		
		  #endif
		}
#line 2078 "PJParser.c"
    break;

  case 69: /* Factor: T_LPAREN Expr T_RPAREN  */
#line 709 "PJParser.y"
                {
		  (yyval.value) = ((yyvsp[-1].value));
		  #ifdef PROJECT1
		  printf("Factor : T_LPAREN Expr T_RPAREN\n");		
		  #endif
		}
#line 2089 "PJParser.c"
    break;

  case 70: /* Variable: T_IDENTIFIER  */
#line 720 "PJParser.y"
                {
		  (yyval.name) = (yyvsp[0].name); //set the name of the variable = to the string value
		  #ifdef PROJECT1
		  printf("Variable : T_IDENTIFIER\n");		
		  #endif
		}
#line 2100 "PJParser.c"
    break;

  case 71: /* Variable: T_IDENTIFIER T_LBRACKET Expr T_RBRACKET  */
#line 727 "PJParser.y"
                {
		  #ifdef PROJECT1
		  printf("Variable : T_IDENTIFIER T_LBRACKET Expr T_RBRACKET\n");		
		  #endif
               	}
#line 2110 "PJParser.c"
    break;

  case 72: /* Variable: T_IDENTIFIER T_LBRACKET Expr T_COMMA Expr T_RBRACKET  */
#line 733 "PJParser.y"
                {
		  #ifdef PROJECT1
		  printf("Variable  : T_IDENTIFIER T_LBRACKET Expr T_COMMA Expr T_RBRACKET\n");		
		  #endif
               	}
#line 2120 "PJParser.c"
    break;

  case 73: /* Constant: T_FLOATNUM  */
#line 742 "PJParser.y"
                { 
		  (yyval.value) = (yyvsp[0].value);
		  #ifdef PROJECT1
		  printf("Constant : T_FLOATNUM\n");		
		  #endif
		}
#line 2131 "PJParser.c"
    break;

  case 74: /* Constant: T_MINUS T_INTNUM  */
#line 749 "PJParser.y"
                {   
		  (yyval.value) = -(yyvsp[0].value); //negative values
		  #ifdef PROJECT1
		  printf("Constant : T_MINUS T_INTNUM\n");		
		  #endif
		}
#line 2142 "PJParser.c"
    break;

  case 75: /* Constant: T_INTNUM  */
#line 756 "PJParser.y"
                { 
		  (yyval.value) = (yyvsp[0].value);
		  #ifdef PROJECT1
		  printf("Constant : T_INTNUM\n");		
		  #endif
		}
#line 2153 "PJParser.c"
    break;

  case 76: /* Constant: T_TRUE  */
#line 763 "PJParser.y"
                { 
		  (yyval.value) = (yyvsp[0].boolean);
		  #ifdef PROJECT1
		  printf("Constant : T_TRUE\n");		
		  #endif
		}
#line 2164 "PJParser.c"
    break;

  case 77: /* Constant: T_FALSE  */
#line 770 "PJParser.y"
                { 
		  (yyval.value) = (yyvsp[0].boolean);
		  #ifdef PROJECT1
		  printf("Constant : T_FALSE\n");		
		  #endif
		}
#line 2175 "PJParser.c"
    break;


#line 2179 "PJParser.c"

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
      yyerror (YY_("syntax error"));
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

  return yyresult;
}

#line 778 "PJParser.y"



/********************C ROUTINES *********************************/
void yyerror(char *s)
{
  fprintf(stderr,"%s: line %d, found %s: %s\n",fileName,yylineno,yytext,s);
}

int yywrap() {
	return 1;
}

static void initialize(char* inputFileName) {
	yyin = fopen(inputFileName,"r");
        if (yyin == NULL) {
          fprintf(stderr,"Error: Could not open file %s\n",inputFileName);
          exit(-1);
        }

	/* uncomment this section for Project 2
	char* dotChar = rindex(inputFileName,'.');
	int endIndex = strlen(inputFileName) - strlen(dotChar);
	char *outputFileName = nssave(2,substr(inputFileName,0,endIndex),".s");
	stdout = freopen(outputFileName,"w",stdout);
        if (stdout == NULL) {
          fprintf(stderr,"Error: Could not open file %s\n",outputFileName);
          exit(-1);
        }
	*/

	globalSymtab = SymInit(SYMTABLE_SIZE);
	SymInitField(globalSymtab,SYMTAB_VALUE_FIELD,(Generic)-1,NULL);	
}

static void finalize() {
    SymKillField(globalSymtab,SYMTAB_VALUE_FIELD);
    SymKill(globalSymtab);
    fclose(yyin);
    // fclose(stdout); //uncomment this line for Project 2
}

int main(int argc, char** argv)

{	
	fileName = argv[1];
	initialize(fileName);
	
	yyparse();
    
	finalize();
  
	return 0;
}

/**
 *
 * retrieve the value of a key
 *
 * @param name a C character string which is a key
 * @return the value of the key
 */
static int getValue(char *name)
{
  return (int)SymGetField(globalSymtab, name, SYMTAB_VALUE_FIELD); 
}

/**
 *
 * Set the value for a key
 *
 * @param name a C character string which is a key
 * @param value the value of the key
 */
static void setValue(char *name, int value)
{
  SymPutField(globalSymtab, name, SYMTAB_VALUE_FIELD, (Generic)value); 
}
/******************END OF C ROUTINES**********************/
