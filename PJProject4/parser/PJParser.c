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
#include <util/dlink.h>
#include <util/string_utils.h>
#include <util/symtab_stack.h>
#include <codegen/codegen.h>
#include <codegen/codegen.h>
#include <codegen/reg.h>
#include <codegen/symfields.h>
#include <codegen/types.h>
#include "PJParserHeader.h"
  
#define SYMTABLE_SIZE 100

/*********************EXTERNAL DECLARATIONS***********************/

EXTERN(void,yyerror,(char*));
EXTERN(int,yylex,(void));

SymTable globalSymtab;
SymtabStack symStack;

static DList instList;
static DList dataList;
char *fileName;

int globalOffset = 0;
int localOffset = -4;
extern int yylineno;
extern char *yytext;
extern FILE *yyin;

#line 109 "PJParser.c"

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
  YYSYMBOL_IntConst = 63,                  /* IntConst  */
  YYSYMBOL_Procedures = 64,                /* Procedures  */
  YYSYMBOL_ProcedureDecl = 65,             /* ProcedureDecl  */
  YYSYMBOL_ProcedureHead = 66,             /* ProcedureHead  */
  YYSYMBOL_FunctionDecl = 67,              /* FunctionDecl  */
  YYSYMBOL_ProcedureBody = 68,             /* ProcedureBody  */
  YYSYMBOL_Statement = 69,                 /* Statement  */
  YYSYMBOL_Assignment = 70,                /* Assignment  */
  YYSYMBOL_IfStatement = 71,               /* IfStatement  */
  YYSYMBOL_TestAndThen = 72,               /* TestAndThen  */
  YYSYMBOL_Test = 73,                      /* Test  */
  YYSYMBOL_WhileStatement = 74,            /* WhileStatement  */
  YYSYMBOL_WhileExpr = 75,                 /* WhileExpr  */
  YYSYMBOL_WhileToken = 76,                /* WhileToken  */
  YYSYMBOL_IOStatement = 77,               /* IOStatement  */
  YYSYMBOL_OutputFormat = 78,              /* OutputFormat  */
  YYSYMBOL_WriteToken = 79,                /* WriteToken  */
  YYSYMBOL_ExitStatement = 80,             /* ExitStatement  */
  YYSYMBOL_CompoundStatement = 81,         /* CompoundStatement  */
  YYSYMBOL_StatementList = 82,             /* StatementList  */
  YYSYMBOL_Expr = 83,                      /* Expr  */
  YYSYMBOL_AddExpr = 84,                   /* AddExpr  */
  YYSYMBOL_MulExpr = 85,                   /* MulExpr  */
  YYSYMBOL_Factor = 86,                    /* Factor  */
  YYSYMBOL_Variable = 87,                  /* Variable  */
  YYSYMBOL_Constant = 88                   /* Constant  */
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
#define YYLAST   170

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  158

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
       0,   127,   127,   135,   141,   148,   149,   152,   159,   166,
     172,   182,   186,   192,   196,   200,   206,   210,   217,   224,
     228,   234,   239,   241,   243,   247,   253,   256,   257,   258,
     259,   260,   261,   264,   270,   274,   280,   286,   292,   298,
     304,   311,   315,   319,   325,   329,   334,   336,   340,   345,
     350,   351,   355,   359,   363,   367,   371,   375,   379,   385,
     389,   393,   397,   403,   405,   409,   413,   420,   424,   428,
     432,   437,   444,   454,   465,   479,   480,   485,   489,   493
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
  "IdentifierList", "Type", "StandardType", "ArrayType", "Dim", "IntConst",
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
static const yytype_int8 yypact[] =
{
      -4,   -17,    27,    12,   -93,     0,   -93,     3,     7,    25,
      37,    43,    11,   -93,   -93,   -93,    39,    42,   -93,   -93,
     -93,   -93,    43,   -93,    44,   -93,   -93,   -11,    16,   -93,
      41,   -93,    12,    37,    45,   -93,    43,    43,   -21,   -93,
     -93,    47,   -93,   -93,    81,    84,   125,    10,     1,   -93,
     -93,   -93,    69,    43,    43,    90,   125,    28,   -93,     3,
      43,    78,   -93,    80,   -93,   -93,    45,     5,   -93,    71,
      76,   -93,     3,     3,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    86,    77,    91,     3,
      88,   115,   -93,   125,     4,   -93,    36,    85,    20,   -93,
     -93,   -93,   -93,    10,    10,    10,    10,    10,    10,     1,
       1,     1,   -93,   -93,   -93,   -93,   -93,    43,   -93,   -93,
      92,    87,    96,   -93,   -93,   -93,   102,    20,   -93,   111,
     104,   -93,   -93,   103,   -93,   -93,   -93,   -93,   105,    46,
     -93,   -93,   -93,   -93,   118,   -25,    99,   -93,    46,   114,
      46,   112,     4,   -93,   116,   -93,     4,   -93
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,    22,     0,     1,     0,     0,     3,
       6,     0,     0,    40,    46,    47,     0,    72,    51,    27,
      28,    29,     0,    30,     0,    31,    32,     0,     0,     2,
       0,    21,     0,     6,     0,     4,     0,     0,    72,    77,
      75,     0,    78,    79,    35,     0,    37,    52,    59,    63,
      67,    68,     0,     0,     0,     0,    39,     0,    49,     0,
       0,     0,    23,     0,    24,     9,     5,     0,    69,     0,
       0,    76,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      45,    45,    50,    33,     0,    26,     0,     0,     0,    71,
      70,    34,    36,    55,    56,    57,    58,    53,    54,    60,
      61,    62,    66,    64,    65,    41,    48,     0,    73,    38,
       0,     0,     0,    15,    13,    14,     0,     0,    10,     0,
       0,    11,    12,     0,    44,    43,    42,    25,     0,     0,
       7,    74,     8,    20,     0,     0,     0,    19,     0,     0,
       0,     0,     0,    18,     0,    16,     0,    17
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -93,   -93,   -93,   -93,   131,   -93,   100,    40,   -92,   -93,
      21,    18,   -93,   -93,   -93,   -93,   -93,   -14,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,    79,   -93,   -93,     2,
     -93,   -22,    82,   -19,   -33,    -6,   -93
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     4,    35,    66,    67,   130,   131,   132,
     145,   146,     9,    31,    32,    33,    62,    18,    19,    20,
      44,    45,    21,    55,    22,    23,   121,    24,    25,    26,
      27,    46,    47,    48,    49,    50,    51
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      56,    28,   126,    68,    83,     8,     1,   148,    58,   123,
      11,   149,   124,   125,    54,    69,    70,    12,    13,    14,
      15,     7,    59,    80,     5,   123,    16,     6,   124,   125,
       7,    87,    88,    10,    63,    91,    30,    97,    93,    98,
      36,    84,   129,    85,    17,    92,    86,    60,    52,    81,
     112,   113,   114,    28,    29,    36,    82,    34,   101,   102,
     155,   109,   110,   111,   157,    37,    28,    28,    97,    38,
     127,    90,    39,    40,    41,   119,    53,    54,    42,    43,
      37,    57,    61,    28,    38,    72,    65,    39,    40,    41,
     143,    71,   144,    42,    43,   133,    74,    75,    76,    77,
      78,    79,    74,    75,    76,    77,    78,    79,    73,    99,
      17,    89,    94,    95,   100,   116,    74,    75,    76,    77,
      78,    79,   120,   117,   115,   135,   128,   118,    74,    75,
      76,    77,    78,    79,   136,   137,   134,   140,   142,   141,
      74,    75,    76,    77,    78,    79,   139,   150,   154,   120,
      74,    75,    76,    77,    78,    79,   103,   104,   105,   106,
     107,   108,   147,   152,    64,   156,    96,   138,   153,   151,
     122
};

static const yytype_uint8 yycheck[] =
{
      22,     7,    94,    36,     3,     3,    10,    32,    19,     5,
       7,    36,     8,     9,    35,    37,    37,    14,    15,    16,
      17,    18,    33,    13,    41,     5,    23,     0,     8,     9,
      18,    53,    54,    33,    32,    57,    11,    32,    60,    34,
      12,    40,    22,    42,    41,    59,    52,    31,    37,    39,
      83,    84,    85,    59,    47,    12,    46,    20,    72,    73,
     152,    80,    81,    82,   156,    37,    72,    73,    32,    41,
      34,    43,    44,    45,    46,    89,    37,    35,    50,    51,
      37,    37,    41,    89,    41,     4,    41,    44,    45,    46,
      44,    44,    46,    50,    51,   117,    25,    26,    27,    28,
      29,    30,    25,    26,    27,    28,    29,    30,    24,    38,
      41,    21,    34,    33,    38,    38,    25,    26,    27,    28,
      29,    30,    34,    32,    38,    38,    41,    36,    25,    26,
      27,    28,    29,    30,    38,    33,    44,    33,    33,    36,
      25,    26,    27,    28,    29,    30,    35,    48,    36,    34,
      25,    26,    27,    28,    29,    30,    74,    75,    76,    77,
      78,    79,    44,    49,    33,    49,    66,   127,   150,   148,
      91
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    10,    53,    54,    55,    41,     0,    18,    81,    64,
      33,     7,    14,    15,    16,    17,    23,    41,    69,    70,
      71,    74,    76,    77,    79,    80,    81,    82,    87,    47,
      11,    65,    66,    67,    20,    56,    12,    37,    41,    44,
      45,    46,    50,    51,    72,    73,    83,    84,    85,    86,
      87,    88,    37,    37,    35,    75,    83,    37,    19,    33,
      31,    41,    68,    81,    56,    41,    57,    58,    86,    83,
      37,    44,     4,    24,    25,    26,    27,    28,    29,    30,
      13,    39,    46,     3,    40,    42,    87,    83,    83,    21,
      43,    83,    69,    83,    34,    33,    58,    32,    34,    38,
      38,    69,    69,    84,    84,    84,    84,    84,    84,    85,
      85,    85,    86,    86,    86,    38,    38,    32,    36,    69,
      34,    78,    78,     5,     8,     9,    60,    34,    41,    22,
      59,    60,    61,    83,    44,    38,    38,    33,    59,    35,
      33,    36,    33,    44,    46,    62,    63,    44,    32,    36,
      48,    62,    49,    63,    36,    60,    49,    60
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    52,    53,    54,    55,    56,    56,    57,    57,    58,
      58,    59,    59,    60,    60,    60,    61,    61,    62,    63,
      63,    64,    64,    65,    66,    67,    68,    69,    69,    69,
      69,    69,    69,    70,    71,    71,    72,    73,    74,    75,
      76,    77,    77,    77,    78,    78,    79,    79,    80,    81,
      82,    82,    83,    83,    83,    83,    83,    83,    83,    84,
      84,    84,    84,    85,    85,    85,    85,    86,    86,    86,
      86,    86,    87,    87,    87,    88,    88,    88,    88,    88
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     4,     2,     0,     4,     5,     1,
       3,     1,     1,     1,     1,     1,     6,     8,     3,     2,
       1,     2,     0,     2,     2,     5,     2,     1,     1,     1,
       1,     1,     1,     3,     4,     2,     3,     1,     4,     1,
       1,     4,     5,     5,     2,     0,     1,     1,     4,     3,
       3,     1,     1,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     3,     1,     3,     3,     3,     1,     1,     2,
       3,     3,     1,     4,     6,     1,     2,     1,     1,     1
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
#line 128 "PJParser.y"
                {
			emitProcedureExit(instList);
			emitDataPrologue(dataList);
			emitInstructions(instList);
		}
#line 1300 "PJParser.c"
    break;

  case 3: /* ProgramHeadAndProcedures: ProgramHead Procedures  */
#line 136 "PJParser.y"
                {
			emitProcedurePrologue(instList,(yyvsp[-1].name));
		}
#line 1308 "PJParser.c"
    break;

  case 4: /* ProgramHead: T_PROGRAM T_IDENTIFIER T_SEMICOLON Decls  */
#line 142 "PJParser.y"
                {
			(yyval.name) = "main";
		}
#line 1316 "PJParser.c"
    break;

  case 7: /* DeclList: IdentifierList T_COLON Type T_SEMICOLON  */
#line 153 "PJParser.y"
                {   
			
			dlinkApply2((yyvsp[-3].idList),(DLinkApply2Func)addIdToSymtab, (Generic)(yyvsp[-1].typeId), (Generic) symStack); //apply to specific symtable on stack
		
			dlinkFreeNodes((yyvsp[-3].idList));
		}
#line 1327 "PJParser.c"
    break;

  case 8: /* DeclList: DeclList IdentifierList T_COLON Type T_SEMICOLON  */
#line 160 "PJParser.y"
                {
			dlinkApply2((yyvsp[-3].idList),(DLinkApply2Func)addIdToSymtab, (Generic)(yyvsp[-1].typeId), (Generic) symStack);
			dlinkFreeNodes((yyvsp[-3].idList));
		}
#line 1336 "PJParser.c"
    break;

  case 9: /* IdentifierList: T_IDENTIFIER  */
#line 167 "PJParser.y"
                {
			int symTabIndex = SymIndex(currentSymtab(symStack),(yyvsp[0].name));		
			(yyval.idList) = dlinkListAlloc(NULL);
			dlinkAppend((yyval.idList),dlinkNodeAlloc((Generic)symTabIndex));
		}
#line 1346 "PJParser.c"
    break;

  case 10: /* IdentifierList: IdentifierList T_COMMA T_IDENTIFIER  */
#line 173 "PJParser.y"
                {
			int symTabIndex;
			
			symTabIndex = SymIndex(currentSymtab(symStack),(yyvsp[0].name));
		
			dlinkAppend((yyvsp[-2].idList),dlinkNodeAlloc((Generic)symTabIndex));
			(yyval.idList) = (yyvsp[-2].idList);
		}
#line 1359 "PJParser.c"
    break;

  case 11: /* Type: StandardType  */
#line 183 "PJParser.y"
                {
			(yyval.typeId) = (yyvsp[0].typeId);
		}
#line 1367 "PJParser.c"
    break;

  case 12: /* Type: ArrayType  */
#line 187 "PJParser.y"
                {
			(yyval.typeId) = (yyvsp[0].typeId);
	 	}
#line 1375 "PJParser.c"
    break;

  case 13: /* StandardType: T_LONGINT  */
#line 193 "PJParser.y"
                {
			(yyval.typeId) = INTEGER_TYPE;
		}
#line 1383 "PJParser.c"
    break;

  case 14: /* StandardType: T_BOOLEAN  */
#line 197 "PJParser.y"
                {
			(yyval.typeId) = INTEGER_TYPE;
		}
#line 1391 "PJParser.c"
    break;

  case 15: /* StandardType: T_FLOAT  */
#line 201 "PJParser.y"
                {
			//$$ = FLOAT_TYPE;
		}
#line 1399 "PJParser.c"
    break;

  case 16: /* ArrayType: T_ARRAY T_LBRACKET Dim T_RBRACKET T_OF StandardType  */
#line 207 "PJParser.y"
                {
			(yyval.typeId) = newArrayType(1, (yyvsp[-3].bounds).lowerBound, (yyvsp[-3].bounds).upperBound, 0, 0, (yyvsp[0].typeId));	
		}
#line 1407 "PJParser.c"
    break;

  case 17: /* ArrayType: T_ARRAY T_LBRACKET Dim T_COMMA Dim T_RBRACKET T_OF StandardType  */
#line 211 "PJParser.y"
                {
			(yyval.typeId) = newArrayType(1, (yyvsp[-5].bounds).lowerBound, (yyvsp[-5].bounds).upperBound, (yyvsp[-3].bounds).lowerBound, (yyvsp[-3].bounds).upperBound, (yyvsp[0].typeId));
		}
#line 1415 "PJParser.c"
    break;

  case 18: /* Dim: IntConst T_DOTDOT IntConst  */
#line 218 "PJParser.y"
                {
			(yyval.bounds).lowerBound = (yyvsp[-2].value);
			(yyval.bounds).upperBound = (yyvsp[0].value);
		}
#line 1424 "PJParser.c"
    break;

  case 19: /* IntConst: T_MINUS T_INTNUM  */
#line 225 "PJParser.y"
                {   
			(yyval.value) = -atoi((yyvsp[0].name)); 
		}
#line 1432 "PJParser.c"
    break;

  case 20: /* IntConst: T_INTNUM  */
#line 229 "PJParser.y"
                { 
			(yyval.value) = atoi((yyvsp[0].name)); 
		}
#line 1440 "PJParser.c"
    break;

  case 21: /* Procedures: Procedures ProcedureDecl  */
#line 234 "PJParser.y"
                                     {
			emitLocalExit(instList);
			emitProcedureExit(instList);
			endScope(symStack);
		}
#line 1450 "PJParser.c"
    break;

  case 23: /* ProcedureDecl: ProcedureHead ProcedureBody  */
#line 241 "PJParser.y"
                                           {
}
#line 1457 "PJParser.c"
    break;

  case 24: /* ProcedureHead: FunctionDecl Decls  */
#line 243 "PJParser.y"
                                  {
			  emitProcedurePrologue(instList, (yyvsp[-1].name));
			  emitLocalPrologue(instList);
}
#line 1466 "PJParser.c"
    break;

  case 25: /* FunctionDecl: T_FUNCTION T_IDENTIFIER T_COLON StandardType T_SEMICOLON  */
#line 247 "PJParser.y"
                                                                       {
			SymTable func = beginScope(symStack); //add symbol table to stack 
			SymInitField(func, SYMTAB_OFFSET_FIELD, (Generic) -1, NULL);
			(yyval.name) = (yyvsp[-3].name);
}
#line 1476 "PJParser.c"
    break;

  case 33: /* Assignment: Variable T_ASSIGN Expr  */
#line 265 "PJParser.y"
                { 
			emitAssignment(instList,(yyvsp[-2].regIndex),(yyvsp[0].regIndex));
		}
#line 1484 "PJParser.c"
    break;

  case 34: /* IfStatement: T_IF TestAndThen T_ELSE Statement  */
#line 271 "PJParser.y"
                {
			emitEndBranchTarget(instList,(yyvsp[-2].symIndex));
		}
#line 1492 "PJParser.c"
    break;

  case 35: /* IfStatement: T_IF TestAndThen  */
#line 275 "PJParser.y"
                {
			emitEndBranchTarget(instList,(yyvsp[0].symIndex));
		}
#line 1500 "PJParser.c"
    break;

  case 36: /* TestAndThen: Test T_THEN Statement  */
#line 281 "PJParser.y"
            {
		   	(yyval.symIndex) = emitThenBranch(instList,(yyvsp[-2].symIndex));
	    }
#line 1508 "PJParser.c"
    break;

  case 37: /* Test: Expr  */
#line 287 "PJParser.y"
                {
			(yyval.symIndex) = emitIfTest(instList,(yyvsp[0].regIndex));
		}
#line 1516 "PJParser.c"
    break;

  case 38: /* WhileStatement: WhileToken WhileExpr T_DO Statement  */
#line 293 "PJParser.y"
                {
			emitWhileLoopBackBranch(instList,(yyvsp[-3].symIndex),(yyvsp[-2].symIndex));
		}
#line 1524 "PJParser.c"
    break;

  case 39: /* WhileExpr: Expr  */
#line 299 "PJParser.y"
                {
			(yyval.symIndex) = emitWhileLoopTest(instList,(yyvsp[0].regIndex));
		}
#line 1532 "PJParser.c"
    break;

  case 40: /* WhileToken: T_WHILE  */
#line 305 "PJParser.y"
                {
			(yyval.symIndex) = emitWhileLoopLandingPad(instList);
		}
#line 1540 "PJParser.c"
    break;

  case 41: /* IOStatement: T_READ T_LPAREN Variable T_RPAREN  */
#line 312 "PJParser.y"
                { 
			emitReadVariable(instList,dataList,  (yyvsp[-1].regIndex));
		}
#line 1548 "PJParser.c"
    break;

  case 42: /* IOStatement: WriteToken T_LPAREN Expr OutputFormat T_RPAREN  */
#line 316 "PJParser.y"
                { 
			emitWriteExpression(instList, dataList, (yyvsp[-4].typeId), (yyvsp[-2].regIndex), (yyvsp[-1].name));
		}
#line 1556 "PJParser.c"
    break;

  case 43: /* IOStatement: WriteToken T_LPAREN T_STRING OutputFormat T_RPAREN  */
#line 320 "PJParser.y"
                { 
			emitWriteString(instList, dataList, (yyvsp[-4].typeId), (yyvsp[-2].name), (yyvsp[-1].name));
		}
#line 1564 "PJParser.c"
    break;

  case 44: /* OutputFormat: T_COLON T_INTNUM  */
#line 326 "PJParser.y"
                {
		   (yyval.name) = (yyvsp[0].name);
		}
#line 1572 "PJParser.c"
    break;

  case 45: /* OutputFormat: %empty  */
#line 329 "PJParser.y"
                {
		   (yyval.name) = NULL;
		}
#line 1580 "PJParser.c"
    break;

  case 46: /* WriteToken: T_WRITE  */
#line 335 "PJParser.y"
                {(yyval.typeId) = IS_WRITE;}
#line 1586 "PJParser.c"
    break;

  case 47: /* WriteToken: T_WRITELN  */
#line 337 "PJParser.y"
                {(yyval.typeId) = IS_WRITELN;}
#line 1592 "PJParser.c"
    break;

  case 48: /* ExitStatement: T_EXIT T_LPAREN Expr T_RPAREN  */
#line 340 "PJParser.y"
                                              {
			  emitExit(instList, (yyvsp[-1].regIndex));
		}
#line 1600 "PJParser.c"
    break;

  case 49: /* CompoundStatement: T_BEGIN StatementList T_END  */
#line 345 "PJParser.y"
                                               {
			
		}
#line 1608 "PJParser.c"
    break;

  case 52: /* Expr: AddExpr  */
#line 356 "PJParser.y"
                {
			(yyval.regIndex) = (yyvsp[0].regIndex); 
		}
#line 1616 "PJParser.c"
    break;

  case 53: /* Expr: Expr T_EQ AddExpr  */
#line 360 "PJParser.y"
                {
			(yyval.regIndex) = emitEqualExpression(instList,(yyvsp[-2].regIndex),(yyvsp[0].regIndex));
		}
#line 1624 "PJParser.c"
    break;

  case 54: /* Expr: Expr T_NE AddExpr  */
#line 364 "PJParser.y"
                {
			(yyval.regIndex) = emitNotEqualExpression(instList,(yyvsp[-2].regIndex),(yyvsp[0].regIndex));
		}
#line 1632 "PJParser.c"
    break;

  case 55: /* Expr: Expr T_LE AddExpr  */
#line 368 "PJParser.y"
                {
			(yyval.regIndex) = emitLessEqualExpression(instList,(yyvsp[-2].regIndex),(yyvsp[0].regIndex));
		}
#line 1640 "PJParser.c"
    break;

  case 56: /* Expr: Expr T_LT AddExpr  */
#line 372 "PJParser.y"
                {
			(yyval.regIndex) = emitLessThanExpression(instList,(yyvsp[-2].regIndex),(yyvsp[0].regIndex));
		}
#line 1648 "PJParser.c"
    break;

  case 57: /* Expr: Expr T_GE AddExpr  */
#line 376 "PJParser.y"
                {
			(yyval.regIndex) = emitGreaterEqualExpression(instList,(yyvsp[-2].regIndex),(yyvsp[0].regIndex));
		}
#line 1656 "PJParser.c"
    break;

  case 58: /* Expr: Expr T_GT AddExpr  */
#line 380 "PJParser.y"
                {
			(yyval.regIndex) = emitGreaterThanExpression(instList,(yyvsp[-2].regIndex),(yyvsp[0].regIndex));
		}
#line 1664 "PJParser.c"
    break;

  case 59: /* AddExpr: MulExpr  */
#line 386 "PJParser.y"
                {
			(yyval.regIndex) = (yyvsp[0].regIndex); 
		}
#line 1672 "PJParser.c"
    break;

  case 60: /* AddExpr: AddExpr T_OR MulExpr  */
#line 390 "PJParser.y"
                {
			(yyval.regIndex) = emitOrExpression(instList,(yyvsp[-2].regIndex),(yyvsp[0].regIndex));
		}
#line 1680 "PJParser.c"
    break;

  case 61: /* AddExpr: AddExpr T_PLUS MulExpr  */
#line 394 "PJParser.y"
                {
			(yyval.regIndex) = emitAddExpression(instList,(yyvsp[-2].regIndex),(yyvsp[0].regIndex));
		}
#line 1688 "PJParser.c"
    break;

  case 62: /* AddExpr: AddExpr T_MINUS MulExpr  */
#line 398 "PJParser.y"
                {
			(yyval.regIndex) = emitSubtractExpression(instList,(yyvsp[-2].regIndex),(yyvsp[0].regIndex));
		}
#line 1696 "PJParser.c"
    break;

  case 63: /* MulExpr: Factor  */
#line 404 "PJParser.y"
                {(yyval.regIndex) =(yyvsp[0].regIndex);}
#line 1702 "PJParser.c"
    break;

  case 64: /* MulExpr: MulExpr T_TIMES Factor  */
#line 406 "PJParser.y"
                {
			(yyval.regIndex) = emitMultiplyExpression(instList,(yyvsp[-2].regIndex),(yyvsp[0].regIndex));
		}
#line 1710 "PJParser.c"
    break;

  case 65: /* MulExpr: MulExpr T_DIV Factor  */
#line 410 "PJParser.y"
                {
			(yyval.regIndex) = emitDivideExpression(instList,(yyvsp[-2].regIndex),(yyvsp[0].regIndex));
		}
#line 1718 "PJParser.c"
    break;

  case 66: /* MulExpr: MulExpr T_AND Factor  */
#line 414 "PJParser.y"
                {
			(yyval.regIndex) = emitAndExpression(instList,(yyvsp[-2].regIndex),(yyvsp[0].regIndex));
		}
#line 1726 "PJParser.c"
    break;

  case 67: /* Factor: Variable  */
#line 421 "PJParser.y"
                { 
			(yyval.regIndex) = emitLoadVariable(instList, (yyvsp[0].regIndex));
		}
#line 1734 "PJParser.c"
    break;

  case 68: /* Factor: Constant  */
#line 425 "PJParser.y"
                { 
			(yyval.regIndex) = (yyvsp[0].regIndex);
		}
#line 1742 "PJParser.c"
    break;

  case 69: /* Factor: T_NOT Factor  */
#line 429 "PJParser.y"
                {
			(yyval.regIndex) = emitNotExpression(instList,(yyvsp[0].regIndex));
		}
#line 1750 "PJParser.c"
    break;

  case 70: /* Factor: T_IDENTIFIER T_LPAREN T_RPAREN  */
#line 432 "PJParser.y"
                                                {
			(yyval.regIndex) = emitCallFunction(instList,(yyvsp[-2].name)); //call function allocates a register 
			emitAfterFunctionAssignment(instList, (yyval.regIndex));

		}
#line 1760 "PJParser.c"
    break;

  case 71: /* Factor: T_LPAREN Expr T_RPAREN  */
#line 438 "PJParser.y"
                {
			(yyval.regIndex) = (yyvsp[-1].regIndex);
		}
#line 1768 "PJParser.c"
    break;

  case 72: /* Variable: T_IDENTIFIER  */
#line 445 "PJParser.y"
                {			int symIndex = SymQueryIndex(currentSymtab(symStack),(yyvsp[0].name));
					if(symIndex == -1){ //if sym query returns -1 then check global symtab
						symIndex = SymQueryIndex(lastSymtab(symStack),(yyvsp[0].name));
						(yyval.regIndex) = emitComputeVariableAddress(instList, symIndex, symStack, lastSymtab(symStack)); //should be global symtab
					}
					else{
						(yyval.regIndex) = emitComputeVariableAddress(instList, symIndex, symStack, currentSymtab(symStack));
					}
		}
#line 1782 "PJParser.c"
    break;

  case 73: /* Variable: T_IDENTIFIER T_LBRACKET Expr T_RBRACKET  */
#line 455 "PJParser.y"
                {
					int symIndex = SymQueryIndex(currentSymtab(symStack),(yyvsp[-3].name));
					if(symIndex == -1){  //if sym query returns -1 then check global symtab
						symIndex = SymQueryIndex(lastSymtab(symStack),(yyvsp[-3].name));
						(yyval.regIndex) = emitComputeArrayAddress(instList, symIndex,(yyvsp[-1].regIndex), symStack, lastSymtab(symStack));
					}
					else{
               			(yyval.regIndex) = emitComputeArrayAddress(instList, symIndex,(yyvsp[-1].regIndex), symStack, currentSymtab(symStack));
					}
				}
#line 1797 "PJParser.c"
    break;

  case 74: /* Variable: T_IDENTIFIER T_LBRACKET Expr T_COMMA Expr T_RBRACKET  */
#line 466 "PJParser.y"
                {
					int symIndex = SymQueryIndex(currentSymtab(symStack),(yyvsp[-5].name));
					if(symIndex == -1){  //if sym query returns -1 then check global symtab
						symIndex = SymQueryIndex(lastSymtab(symStack),(yyvsp[-5].name));
						(yyval.regIndex) = emitCompute2DArrayAddress(instList,symIndex,(yyvsp[-3].regIndex), (yyvsp[-1].regIndex), symStack, lastSymtab(symStack));	
					}
					else{
               			(yyval.regIndex) = emitCompute2DArrayAddress(instList, symIndex,(yyvsp[-3].regIndex), (yyvsp[-1].regIndex), symStack, lastSymtab(symStack));
					}
				}
#line 1812 "PJParser.c"
    break;

  case 76: /* Constant: T_MINUS T_INTNUM  */
#line 481 "PJParser.y"
                {   
			char *negstr = nssave(2, "-", (yyvsp[0].name));
			(yyval.regIndex) = emitLoadIntegerConstant(instList,negstr); 
		}
#line 1821 "PJParser.c"
    break;

  case 77: /* Constant: T_INTNUM  */
#line 486 "PJParser.y"
                { 
			(yyval.regIndex) = emitLoadIntegerConstant(instList,(yyvsp[0].name)); 
		}
#line 1829 "PJParser.c"
    break;

  case 78: /* Constant: T_TRUE  */
#line 490 "PJParser.y"
                { 
			(yyval.regIndex) = emitLoadIntegerConstant(instList,"1"); 
		}
#line 1837 "PJParser.c"
    break;

  case 79: /* Constant: T_FALSE  */
#line 494 "PJParser.y"
                { 
			(yyval.regIndex) = emitLoadIntegerConstant(instList,"0"); 
		}
#line 1845 "PJParser.c"
    break;


#line 1849 "PJParser.c"

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

#line 499 "PJParser.y"



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

	char* dotChar = rindex(inputFileName,'.');
	int endIndex = strlen(inputFileName) - strlen(dotChar);
	char *outputFileName = nssave(2,substr(inputFileName,0,endIndex),".s");
	stdout = freopen(outputFileName,"w",stdout);
        if (stdout == NULL) {
          fprintf(stderr,"Error: Could not open file %s\n",outputFileName);
          exit(-1);
        }

	symStack = symtabStackInit();
	globalSymtab = beginScope(symStack);
	SymInitField(globalSymtab,SYMTAB_OFFSET_FIELD,(Generic)-1,NULL);
	initRegisters();

	
	instList = dlinkListAlloc(NULL);
	dataList = dlinkListAlloc(NULL);

}

static void finalize() {

    fclose(stdin);
    fclose(stdout);
    
    SymKillField(globalSymtab,SYMTAB_OFFSET_FIELD);
    SymKill(globalSymtab);
 
    cleanupRegisters();
    
    dlinkFreeNodesAndAtoms(instList);
    dlinkFreeNodesAndAtoms(dataList);

}

int main(int argc, char** argv)

{	
	fileName = argv[1];
	initialize(fileName);
	
	yyparse();
    
	finalize();
  
	return 0;
}
/******************END OF C ROUTINES**********************/
