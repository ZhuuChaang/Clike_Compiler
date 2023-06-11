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
#line 7 "parser.y"


#include "ast.hpp"


void yyerror(const char *s) {
    std::printf("Error: %s\n", s);
    std::exit(1); 
}

int yylex(void);

extern "C" int yywrap() {return 1;}

Program* Root;


#line 89 "parser.cpp"

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

#include "parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CHAR = 3,                       /* CHAR  */
  YYSYMBOL_DOUBLE = 4,                     /* DOUBLE  */
  YYSYMBOL_FLOAT = 5,                      /* FLOAT  */
  YYSYMBOL_INT = 6,                        /* INT  */
  YYSYMBOL_SHORT = 7,                      /* SHORT  */
  YYSYMBOL_LONG = 8,                       /* LONG  */
  YYSYMBOL_VOID = 9,                       /* VOID  */
  YYSYMBOL_ENUM = 10,                      /* ENUM  */
  YYSYMBOL_UNION = 11,                     /* UNION  */
  YYSYMBOL_STRUCT = 12,                    /* STRUCT  */
  YYSYMBOL_TRUE = 13,                      /* TRUE  */
  YYSYMBOL_FALSE = 14,                     /* FALSE  */
  YYSYMBOL_FOR = 15,                       /* FOR  */
  YYSYMBOL_DO = 16,                        /* DO  */
  YYSYMBOL_WHILE = 17,                     /* WHILE  */
  YYSYMBOL_BREAK = 18,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 19,                  /* CONTINUE  */
  YYSYMBOL_IF = 20,                        /* IF  */
  YYSYMBOL_ELSE = 21,                      /* ELSE  */
  YYSYMBOL_GOTO = 22,                      /* GOTO  */
  YYSYMBOL_SWITCH = 23,                    /* SWITCH  */
  YYSYMBOL_CASE = 24,                      /* CASE  */
  YYSYMBOL_DEFAULT = 25,                   /* DEFAULT  */
  YYSYMBOL_RETURN = 26,                    /* RETURN  */
  YYSYMBOL_STATIC = 27,                    /* STATIC  */
  YYSYMBOL_CONST = 28,                     /* CONST  */
  YYSYMBOL_SIZEOF = 29,                    /* SIZEOF  */
  YYSYMBOL_TYPEDEF = 30,                   /* TYPEDEF  */
  YYSYMBOL_CONDITION = 31,                 /* CONDITION  */
  YYSYMBOL_DOT = 32,                       /* DOT  */
  YYSYMBOL_ARROW = 33,                     /* ARROW  */
  YYSYMBOL_SEMICOLON = 34,                 /* SEMICOLON  */
  YYSYMBOL_COLON = 35,                     /* COLON  */
  YYSYMBOL_LPAREN = 36,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 37,                    /* RPAREN  */
  YYSYMBOL_LBRACKET = 38,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 39,                  /* RBRACKET  */
  YYSYMBOL_LBRACE = 40,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 41,                    /* RBRACE  */
  YYSYMBOL_PTRDEC = 42,                    /* PTRDEC  */
  YYSYMBOL_ARRAYTAG = 43,                  /* ARRAYTAG  */
  YYSYMBOL_ADD = 44,                       /* ADD  */
  YYSYMBOL_SUB = 45,                       /* SUB  */
  YYSYMBOL_MUL = 46,                       /* MUL  */
  YYSYMBOL_DIV = 47,                       /* DIV  */
  YYSYMBOL_MOD = 48,                       /* MOD  */
  YYSYMBOL_INC = 49,                       /* INC  */
  YYSYMBOL_DEC = 50,                       /* DEC  */
  YYSYMBOL_EQ = 51,                        /* EQ  */
  YYSYMBOL_NE = 52,                        /* NE  */
  YYSYMBOL_GT = 53,                        /* GT  */
  YYSYMBOL_LT = 54,                        /* LT  */
  YYSYMBOL_GE = 55,                        /* GE  */
  YYSYMBOL_LE = 56,                        /* LE  */
  YYSYMBOL_AND = 57,                       /* AND  */
  YYSYMBOL_OR = 58,                        /* OR  */
  YYSYMBOL_NOT = 59,                       /* NOT  */
  YYSYMBOL_BAND = 60,                      /* BAND  */
  YYSYMBOL_BOR = 61,                       /* BOR  */
  YYSYMBOL_BXOR = 62,                      /* BXOR  */
  YYSYMBOL_BNOT = 63,                      /* BNOT  */
  YYSYMBOL_SHL = 64,                       /* SHL  */
  YYSYMBOL_SHR = 65,                       /* SHR  */
  YYSYMBOL_ASSIGN = 66,                    /* ASSIGN  */
  YYSYMBOL_ADDAS = 67,                     /* ADDAS  */
  YYSYMBOL_SUBAS = 68,                     /* SUBAS  */
  YYSYMBOL_MULAS = 69,                     /* MULAS  */
  YYSYMBOL_DIVAS = 70,                     /* DIVAS  */
  YYSYMBOL_MODAS = 71,                     /* MODAS  */
  YYSYMBOL_BANDAS = 72,                    /* BANDAS  */
  YYSYMBOL_BORAS = 73,                     /* BORAS  */
  YYSYMBOL_BXORAS = 74,                    /* BXORAS  */
  YYSYMBOL_SHLAS = 75,                     /* SHLAS  */
  YYSYMBOL_SHRAS = 76,                     /* SHRAS  */
  YYSYMBOL_COMMA = 77,                     /* COMMA  */
  YYSYMBOL_INTEGER_VAR = 78,               /* INTEGER_VAR  */
  YYSYMBOL_REAL_VAR = 79,                  /* REAL_VAR  */
  YYSYMBOL_STRING_VAR = 80,                /* STRING_VAR  */
  YYSYMBOL_CHAR_VAR = 81,                  /* CHAR_VAR  */
  YYSYMBOL_IDENTIFER = 82,                 /* IDENTIFER  */
  YYSYMBOL_FUNC_CALL_ARG_LIST = 83,        /* FUNC_CALL_ARG_LIST  */
  YYSYMBOL_UMINUS = 84,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 85,                  /* $accept  */
  YYSYMBOL_PROGRAM = 86,                   /* PROGRAM  */
  YYSYMBOL_GlobalSTMT = 87,                /* GlobalSTMT  */
  YYSYMBOL_TYPE = 88,                      /* TYPE  */
  YYSYMBOL__TYPE = 89,                     /* _TYPE  */
  YYSYMBOL_FieldTYPE = 90,                 /* FieldTYPE  */
  YYSYMBOL_BuiltinTYPE = 91,               /* BuiltinTYPE  */
  YYSYMBOL_ARRAY = 92,                     /* ARRAY  */
  YYSYMBOL_FunDECL = 93,                   /* FunDECL  */
  YYSYMBOL_FunDEF = 94,                    /* FunDEF  */
  YYSYMBOL_ArgLIST = 95,                   /* ArgLIST  */
  YYSYMBOL__ArgLIST = 96,                  /* _ArgLIST  */
  YYSYMBOL_FieldDECL = 97,                 /* FieldDECL  */
  YYSYMBOL_VarDEF = 98,                    /* VarDEF  */
  YYSYMBOL_SUVarDEF = 99,                  /* SUVarDEF  */
  YYSYMBOL_IdList = 100,                   /* IdList  */
  YYSYMBOL_InitIDLIST = 101,               /* InitIDLIST  */
  YYSYMBOL_Init = 102,                     /* Init  */
  YYSYMBOL_EnmLIST = 103,                  /* EnmLIST  */
  YYSYMBOL__EnmLIST = 104,                 /* _EnmLIST  */
  YYSYMBOL_Enm = 105,                      /* Enm  */
  YYSYMBOL_TypeDEF = 106,                  /* TypeDEF  */
  YYSYMBOL_SCOPE = 107,                    /* SCOPE  */
  YYSYMBOL_CtrlFLOW = 108,                 /* CtrlFLOW  */
  YYSYMBOL_CtrlSCOPE = 109,                /* CtrlSCOPE  */
  YYSYMBOL_IfFLOW = 110,                   /* IfFLOW  */
  YYSYMBOL_ElseFLOW = 111,                 /* ElseFLOW  */
  YYSYMBOL_ElseifFLOW = 112,               /* ElseifFLOW  */
  YYSYMBOL_ForFLOW = 113,                  /* ForFLOW  */
  YYSYMBOL_WhileFLOW = 114,                /* WhileFLOW  */
  YYSYMBOL_DowhileFLOW = 115,              /* DowhileFLOW  */
  YYSYMBOL_SwitchFLOW = 116,               /* SwitchFLOW  */
  YYSYMBOL_CaseLIST = 117,                 /* CaseLIST  */
  YYSYMBOL_CaseSTMT = 118,                 /* CaseSTMT  */
  YYSYMBOL_CtrlSTMT = 119,                 /* CtrlSTMT  */
  YYSYMBOL_STMT = 120,                     /* STMT  */
  YYSYMBOL_ReturnSTMT = 121,               /* ReturnSTMT  */
  YYSYMBOL_SUSTMT = 122,                   /* SUSTMT  */
  YYSYMBOL_EXPR = 123,                     /* EXPR  */
  YYSYMBOL_SUFOP = 124,                    /* SUFOP  */
  YYSYMBOL_FUNCALL = 125,                  /* FUNCALL  */
  YYSYMBOL_CallArgLIST = 126,              /* CallArgLIST  */
  YYSYMBOL__CallArgLIST = 127,             /* _CallArgLIST  */
  YYSYMBOL_CONSTANT = 128                  /* CONSTANT  */
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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1570

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  85
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  154
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  273

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   339


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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   140,   140,   145,   146,   147,   148,   149,   150,   154,
     159,   160,   161,   162,   163,   164,   165,   166,   170,   171,
     172,   175,   176,   177,   178,   179,   180,   181,   189,   194,
     197,   200,   201,   202,   205,   206,   210,   213,   216,   220,
     221,   225,   226,   229,   230,   234,   235,   236,   239,   240,
     243,   244,   248,   252,   256,   257,   258,   259,   260,   263,
     265,   266,   269,   270,   271,   274,   275,   279,   280,   283,
     284,   287,   291,   294,   295,   299,   300,   301,   302,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   318,
     319,   320,   321,   322,   323,   324,   325,   328,   329,   332,
     333,   334,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   366,   367,   368,   369,   370,
     371,   372,   373,   375,   376,   377,   378,   379,   380,   381,
     382,   395,   396,   431,   435,   436,   437,   440,   441,   444,
     445,   446,   447,   448,   449
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
  "\"end of file\"", "error", "\"invalid token\"", "CHAR", "DOUBLE",
  "FLOAT", "INT", "SHORT", "LONG", "VOID", "ENUM", "UNION", "STRUCT",
  "TRUE", "FALSE", "FOR", "DO", "WHILE", "BREAK", "CONTINUE", "IF", "ELSE",
  "GOTO", "SWITCH", "CASE", "DEFAULT", "RETURN", "STATIC", "CONST",
  "SIZEOF", "TYPEDEF", "CONDITION", "DOT", "ARROW", "SEMICOLON", "COLON",
  "LPAREN", "RPAREN", "LBRACKET", "RBRACKET", "LBRACE", "RBRACE", "PTRDEC",
  "ARRAYTAG", "ADD", "SUB", "MUL", "DIV", "MOD", "INC", "DEC", "EQ", "NE",
  "GT", "LT", "GE", "LE", "AND", "OR", "NOT", "BAND", "BOR", "BXOR",
  "BNOT", "SHL", "SHR", "ASSIGN", "ADDAS", "SUBAS", "MULAS", "DIVAS",
  "MODAS", "BANDAS", "BORAS", "BXORAS", "SHLAS", "SHRAS", "COMMA",
  "INTEGER_VAR", "REAL_VAR", "STRING_VAR", "CHAR_VAR", "IDENTIFER",
  "FUNC_CALL_ARG_LIST", "UMINUS", "$accept", "PROGRAM", "GlobalSTMT",
  "TYPE", "_TYPE", "FieldTYPE", "BuiltinTYPE", "ARRAY", "FunDECL",
  "FunDEF", "ArgLIST", "_ArgLIST", "FieldDECL", "VarDEF", "SUVarDEF",
  "IdList", "InitIDLIST", "Init", "EnmLIST", "_EnmLIST", "Enm", "TypeDEF",
  "SCOPE", "CtrlFLOW", "CtrlSCOPE", "IfFLOW", "ElseFLOW", "ElseifFLOW",
  "ForFLOW", "WhileFLOW", "DowhileFLOW", "SwitchFLOW", "CaseLIST",
  "CaseSTMT", "CtrlSTMT", "STMT", "ReturnSTMT", "SUSTMT", "EXPR", "SUFOP",
  "FUNCALL", "CallArgLIST", "_CallArgLIST", "CONSTANT", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-245)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-149)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -245,    10,   110,  -245,  -245,  -245,  -245,  -245,  -245,  -245,
    -245,   -60,   -50,   -42,    73,  -245,   -24,     0,    36,  -245,
    -245,  -245,  -245,  -245,  -245,    31,    34,    46,   -10,  -245,
     -30,   -23,  -245,  -245,    19,  -245,  -245,    55,    73,    73,
     108,    73,   576,  -245,    61,  -245,    79,   105,    77,    80,
      74,   124,    57,   122,  -245,    82,   125,    84,  -245,  -245,
     129,   564,   576,   576,   576,   576,   576,   576,   576,   576,
    -245,  -245,  -245,  -245,   130,  1276,  -245,  -245,   106,  -245,
      95,  -245,    55,  -245,    97,  -245,  -245,   141,  -245,    99,
     -16,    73,   564,   -29,   140,   700,   -12,   -12,   -12,   -12,
     -12,   -12,   -12,   -12,   576,   576,    96,    98,   576,   576,
     576,   576,   576,   576,  -245,  -245,   576,   576,   576,   576,
     576,   576,   576,   576,   576,   576,   576,   576,   576,   576,
    -245,  -245,   102,   100,  -245,  -245,  -245,  -245,   101,   144,
     736,   576,  -245,   628,   148,   113,   772,  -245,  -245,   808,
     194,   194,   -12,   -12,   -12,  1480,  1480,  1505,  1505,  1505,
    1505,  1380,  1346,  1455,  1405,  1430,   103,   103,  1276,  -245,
     343,   118,  -245,  -245,   -12,  -245,   576,   576,  -245,   160,
     158,   161,   163,   169,   157,  -245,    61,  -245,  -245,  -245,
    -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,   844,   664,
    1312,   576,  -245,   191,   576,   576,   576,  -245,   880,  -245,
     916,   263,   179,   952,   988,  1024,  -245,   576,   184,   185,
    -245,  -245,  -245,  -245,  -245,  -245,  -245,  1060,   576,    -7,
      -6,   181,  1096,  -245,  -245,  -245,  1132,  -245,  -245,  -245,
    -245,  -245,   576,   188,   202,    32,  1168,  -245,   -11,  -245,
     576,   189,  -245,  -245,   104,   192,  -245,  -245,  1204,  -245,
    -245,  -245,   576,  -245,   423,  1240,   503,   195,   158,   196,
    -245,  -245,  -245
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       8,     0,     2,     1,    21,    22,    23,    24,    25,    26,
      27,     0,     0,     0,     0,    14,     0,     9,    11,    10,
       3,     4,     7,     6,     5,    17,    16,    15,     0,    11,
      43,     0,    42,    12,     0,    13,    36,    47,   101,   101,
       0,    33,     0,    37,     0,    28,    50,     0,     0,    46,
       0,     0,     0,     0,    52,     0,     0,     0,   149,   150,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     152,   153,   154,   151,   103,    44,   104,   105,    43,    41,
       0,    20,     0,    40,    38,   100,    19,     0,    18,    32,
       0,     0,     0,   103,     0,     0,   131,   132,   129,   125,
     126,   127,   130,   128,   146,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   141,   142,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     133,    51,    45,     0,    99,    29,    96,    30,     0,     0,
       0,     0,   134,   145,     0,     0,     0,   140,   139,     0,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,    39,
       0,    31,   136,   135,   138,   143,     0,     0,   102,     0,
       0,     0,     0,     0,     0,    53,     0,    94,    93,    92,
      91,    89,    54,    55,    57,    56,    58,    95,     0,   144,
     137,     0,    88,     0,     0,     0,     0,    97,     0,    90,
       0,     0,     0,     0,     0,     0,    98,     0,     0,     0,
      59,    86,    85,    84,    83,    79,    87,     0,     0,     0,
       0,     0,     0,    80,    81,    82,     0,    70,    69,    61,
      66,    74,     0,     0,    64,     0,     0,    71,     0,    60,
       0,     0,    72,    73,     0,     0,    63,    62,     0,    96,
      67,    68,     0,    96,    78,     0,    76,     0,     0,     0,
      77,    65,    75
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -245,  -245,  -245,    -2,  -245,    -1,  -245,  -245,  -245,  -245,
    -245,  -245,     1,     2,   -22,  -245,  -245,   187,  -245,  -245,
     152,     3,   -88,    35,  -213,  -245,  -245,  -245,  -245,  -245,
    -245,  -245,  -245,  -245,  -245,  -244,    37,   208,   -17,  -245,
    -245,  -245,  -245,  -245
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    50,    17,    29,    19,    35,    20,    21,
      56,    57,   187,   188,    51,    84,    31,    32,    47,    48,
      49,   189,   190,   191,   203,   192,   249,   244,   193,   194,
     195,   196,   245,   253,   211,   170,   197,    52,   198,   130,
      76,   144,   145,    77
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      16,    18,   137,    22,    23,    24,    41,   104,   -14,   255,
       3,    43,    28,   -14,   -14,   264,   238,   240,   135,   266,
     106,   107,    25,   256,   136,    75,   108,   237,   239,   202,
      87,    87,    26,   202,   202,   257,    42,   114,   115,    55,
      27,   261,    33,    34,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   -14,    44,   271,   250,   251,    30,    94,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      36,    37,    40,   252,    38,   140,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    39,   143,   146,   138,
     139,   149,   150,   151,   152,   153,   154,    45,    86,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,   224,   174,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,   106,   107,    46,   260,    15,
      14,   108,    54,    78,   202,    80,    81,   109,   110,   111,
     112,   113,   114,   115,    82,    15,    83,   -49,    85,   199,
     200,    91,    90,    88,    89,    92,   104,   208,   186,    18,
      58,    59,    42,   131,   133,   134,   -35,   141,   147,   -48,
     148,   172,   169,   171,   210,   175,    60,   213,   214,   215,
     176,   207,    15,    61,   227,   -34,   201,   204,   202,   205,
     232,    62,    63,    64,    15,   206,    65,    66,   212,   186,
      18,   236,   221,   222,   223,   228,    67,    68,   233,   234,
      69,   241,   247,   248,   259,   246,   106,   107,   262,   270,
     272,    79,   108,   258,   132,    70,    71,    72,    73,    74,
     111,   112,   113,   114,   115,   265,   225,    53,   226,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   186,    18,   186,    18,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    58,    59,   179,   180,
     181,   218,   219,   182,     0,     0,   183,     0,     0,   184,
       0,     0,    60,    14,     0,     0,     0,     0,     0,    61,
       0,     0,     0,   136,   220,     0,     0,    62,    63,    64,
       0,     0,    65,    66,     0,     0,     0,     0,     0,     0,
       0,     0,    67,    68,     0,     0,    69,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    70,    71,    72,    73,    93,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    58,    59,   179,   180,
     181,     0,     0,   182,     0,     0,   183,     0,     0,   184,
       0,     0,    60,    14,     0,     0,     0,     0,     0,    61,
       0,     0,     0,   136,   185,     0,     0,    62,    63,    64,
       0,     0,    65,    66,     0,     0,     0,     0,     0,     0,
       0,     0,    67,    68,     0,     0,    69,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    70,    71,    72,    73,    93,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    58,    59,   179,   180,
     181,   267,     0,   182,     0,     0,   183,     0,     0,   184,
       0,     0,    60,    14,     0,     0,     0,     0,     0,    61,
       0,     0,     0,   136,     0,     0,     0,    62,    63,    64,
       0,     0,    65,    66,     0,     0,     0,     0,     0,     0,
       0,     0,    67,    68,     0,     0,    69,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    70,    71,    72,    73,    93,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    58,    59,   179,   180,
     181,   269,     0,   182,     0,     0,   183,     0,     0,   184,
       0,     0,    60,    14,     0,     0,     0,     0,     0,    61,
       0,     0,     0,   136,     0,     0,     0,    62,    63,    64,
       0,     0,    65,    66,     0,     0,     0,     0,     0,     0,
       0,     0,    67,    68,     0,     0,    69,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    58,    59,     0,
       0,    70,    71,    72,    73,    93,     0,     0,     0,    58,
      59,     0,     0,    60,     0,     0,     0,     0,     0,     0,
      61,     0,     0,     0,     0,    60,     0,     0,    62,    63,
      64,     0,    61,    65,    66,     0,     0,     0,     0,     0,
      62,    63,    64,    67,    68,    65,    66,    69,     0,     0,
       0,     0,     0,     0,     0,    67,    68,     0,     0,    69,
       0,     0,    70,    71,    72,    73,    93,     0,     0,     0,
       0,     0,     0,     0,    70,    71,    72,    73,    74,   105,
     106,   107,     0,     0,     0,     0,   108,     0,     0,     0,
       0,     0,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,     0,   124,   125,
     126,     0,   127,   128,   129,   105,   106,   107,     0,     0,
       0,     0,   108,     0,     0,  -148,     0,     0,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,     0,   124,   125,   126,     0,   127,   128,
     129,   105,   106,   107,     0,     0,     0,   142,   108,     0,
       0,  -147,     0,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,     0,
     124,   125,   126,     0,   127,   128,   129,   105,   106,   107,
       0,     0,     0,   173,   108,     0,     0,     0,     0,     0,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,     0,   124,   125,   126,     0,
     127,   128,   129,   105,   106,   107,     0,   177,     0,     0,
     108,     0,     0,     0,     0,     0,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,     0,   124,   125,   126,     0,   127,   128,   129,   105,
     106,   107,     0,     0,     0,     0,   108,   178,     0,     0,
       0,     0,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,     0,   124,   125,
     126,     0,   127,   128,   129,   105,   106,   107,   209,     0,
       0,     0,   108,     0,     0,     0,     0,     0,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,     0,   124,   125,   126,     0,   127,   128,
     129,   105,   106,   107,   216,     0,     0,     0,   108,     0,
       0,     0,     0,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,     0,
     124,   125,   126,     0,   127,   128,   129,   105,   106,   107,
     217,     0,     0,     0,   108,     0,     0,     0,     0,     0,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,     0,   124,   125,   126,     0,
     127,   128,   129,   105,   106,   107,     0,     0,     0,   229,
     108,     0,     0,     0,     0,     0,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,     0,   124,   125,   126,     0,   127,   128,   129,   105,
     106,   107,     0,     0,     0,   230,   108,     0,     0,     0,
       0,     0,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,     0,   124,   125,
     126,     0,   127,   128,   129,   105,   106,   107,     0,     0,
       0,   231,   108,     0,     0,     0,     0,     0,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,     0,   124,   125,   126,     0,   127,   128,
     129,   105,   106,   107,   235,     0,     0,     0,   108,     0,
       0,     0,     0,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,     0,
     124,   125,   126,     0,   127,   128,   129,   105,   106,   107,
     242,     0,     0,     0,   108,     0,     0,     0,     0,     0,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,     0,   124,   125,   126,     0,
     127,   128,   129,   105,   106,   107,     0,     0,     0,   243,
     108,     0,     0,     0,     0,     0,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,     0,   124,   125,   126,     0,   127,   128,   129,   105,
     106,   107,     0,     0,     0,   254,   108,     0,     0,     0,
       0,     0,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,     0,   124,   125,
     126,     0,   127,   128,   129,   105,   106,   107,     0,   263,
       0,     0,   108,     0,     0,     0,     0,     0,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,     0,   124,   125,   126,     0,   127,   128,
     129,   105,   106,   107,     0,     0,     0,   268,   108,     0,
       0,     0,     0,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,     0,
     124,   125,   126,     0,   127,   128,   129,   105,   106,   107,
       0,     0,     0,     0,   108,     0,     0,     0,     0,     0,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,     0,   124,   125,   126,     0,
     127,   128,   129,   105,   106,   107,     0,     0,     0,     0,
     108,     0,     0,     0,     0,     0,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,     0,   124,   125,   126,     0,   127,   128,   106,   107,
       0,     0,     0,     0,   108,     0,     0,     0,     0,     0,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,     0,     0,   124,   125,   126,     0,
     127,   128,   106,   107,     0,     0,     0,     0,   108,     0,
       0,     0,     0,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   106,   107,     0,
     124,   125,   126,   108,   127,   128,     0,     0,     0,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   106,   107,     0,   124,     0,   126,   108,   127,
     128,     0,     0,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   106,   107,     0,
     124,     0,     0,   108,   127,   128,     0,     0,     0,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   106,   107,     0,     0,     0,     0,   108,   127,
     128,     0,     0,     0,   109,   110,   111,   112,   113,   114,
     115,     0,     0,   118,   119,   120,   121,   106,   107,     0,
       0,     0,     0,   108,   127,   128,     0,     0,     0,   109,
     110,   111,   112,   113,   114,   115,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   127,
     128
};

static const yytype_int16 yycheck[] =
{
       2,     2,    90,     2,     2,     2,    36,    36,    37,    20,
       0,    34,    14,    42,    43,   259,   229,   230,    34,   263,
      32,    33,    82,    34,    40,    42,    38,    34,    34,    40,
      52,    53,    82,    40,    40,   248,    66,    49,    50,    41,
      82,   254,    42,    43,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    82,    77,   268,    24,    25,    82,    61,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      34,    40,    82,    41,    40,    92,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    40,   104,   105,    91,
      92,   108,   109,   110,   111,   112,   113,    78,    41,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,   211,   141,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    32,    33,    82,    34,    82,
      30,    38,    34,    82,    40,    66,    41,    44,    45,    46,
      47,    48,    49,    50,    77,    82,    82,    77,    34,   176,
     177,    77,    37,    41,    82,    36,    36,   184,   170,   170,
      13,    14,    66,    78,    77,    34,    77,    37,    82,    77,
      82,    37,    82,    82,   201,    37,    29,   204,   205,   206,
      77,    34,    82,    36,   211,    77,    36,    36,    40,    36,
     217,    44,    45,    46,    82,    36,    49,    50,    17,   211,
     211,   228,   211,   211,   211,    36,    59,    60,    34,    34,
      63,    40,    34,    21,    35,   242,    32,    33,    36,    34,
      34,    44,    38,   250,    82,    78,    79,    80,    81,    82,
      46,    47,    48,    49,    50,   262,   211,    39,   211,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   264,   264,   266,   266,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    -1,    -1,    23,    -1,    -1,    26,
      -1,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    36,
      -1,    -1,    -1,    40,    41,    -1,    -1,    44,    45,    46,
      -1,    -1,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,    -1,    20,    -1,    -1,    23,    -1,    -1,    26,
      -1,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    36,
      -1,    -1,    -1,    40,    41,    -1,    -1,    44,    45,    46,
      -1,    -1,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    -1,    20,    -1,    -1,    23,    -1,    -1,    26,
      -1,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    36,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    44,    45,    46,
      -1,    -1,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    -1,    20,    -1,    -1,    23,    -1,    -1,    26,
      -1,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    36,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    44,    45,    46,
      -1,    -1,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60,    -1,    -1,    63,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    78,    79,    80,    81,    82,    -1,    -1,    -1,    13,
      14,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    -1,    -1,    -1,    -1,    29,    -1,    -1,    44,    45,
      46,    -1,    36,    49,    50,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    59,    60,    49,    50,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,    63,
      -1,    -1,    78,    79,    80,    81,    82,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,    31,
      32,    33,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    -1,    60,    61,
      62,    -1,    64,    65,    66,    31,    32,    33,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    77,    -1,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    -1,    60,    61,    62,    -1,    64,    65,
      66,    31,    32,    33,    -1,    -1,    -1,    37,    38,    -1,
      -1,    77,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      60,    61,    62,    -1,    64,    65,    66,    31,    32,    33,
      -1,    -1,    -1,    37,    38,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    -1,    60,    61,    62,    -1,
      64,    65,    66,    31,    32,    33,    -1,    35,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    -1,    60,    61,    62,    -1,    64,    65,    66,    31,
      32,    33,    -1,    -1,    -1,    -1,    38,    39,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    -1,    60,    61,
      62,    -1,    64,    65,    66,    31,    32,    33,    34,    -1,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    -1,    60,    61,    62,    -1,    64,    65,
      66,    31,    32,    33,    34,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      60,    61,    62,    -1,    64,    65,    66,    31,    32,    33,
      34,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    -1,    60,    61,    62,    -1,
      64,    65,    66,    31,    32,    33,    -1,    -1,    -1,    37,
      38,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    -1,    60,    61,    62,    -1,    64,    65,    66,    31,
      32,    33,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    -1,    60,    61,
      62,    -1,    64,    65,    66,    31,    32,    33,    -1,    -1,
      -1,    37,    38,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    -1,    60,    61,    62,    -1,    64,    65,
      66,    31,    32,    33,    34,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      60,    61,    62,    -1,    64,    65,    66,    31,    32,    33,
      34,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    -1,    60,    61,    62,    -1,
      64,    65,    66,    31,    32,    33,    -1,    -1,    -1,    37,
      38,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    -1,    60,    61,    62,    -1,    64,    65,    66,    31,
      32,    33,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    -1,    60,    61,
      62,    -1,    64,    65,    66,    31,    32,    33,    -1,    35,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    -1,    60,    61,    62,    -1,    64,    65,
      66,    31,    32,    33,    -1,    -1,    -1,    37,    38,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      60,    61,    62,    -1,    64,    65,    66,    31,    32,    33,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    -1,    60,    61,    62,    -1,
      64,    65,    66,    31,    32,    33,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    -1,    60,    61,    62,    -1,    64,    65,    32,    33,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    -1,    -1,    60,    61,    62,    -1,
      64,    65,    32,    33,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    32,    33,    -1,
      60,    61,    62,    38,    64,    65,    -1,    -1,    -1,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    32,    33,    -1,    60,    -1,    62,    38,    64,
      65,    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    32,    33,    -1,
      60,    -1,    -1,    38,    64,    65,    -1,    -1,    -1,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    32,    33,    -1,    -1,    -1,    -1,    38,    64,
      65,    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    -1,    -1,    53,    54,    55,    56,    32,    33,    -1,
      -1,    -1,    -1,    38,    64,    65,    -1,    -1,    -1,    44,
      45,    46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,
      65
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    86,    87,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    30,    82,    88,    89,    90,    91,
      93,    94,    97,    98,   106,    82,    82,    82,    88,    90,
      82,   101,   102,    42,    43,    92,    34,    40,    40,    40,
      82,    36,    66,    34,    77,    78,    82,   103,   104,   105,
      88,    99,   122,   122,    34,    88,    95,    96,    13,    14,
      29,    36,    44,    45,    46,    49,    50,    59,    60,    63,
      78,    79,    80,    81,    82,   123,   125,   128,    82,   102,
      66,    41,    77,    82,   100,    34,    41,    99,    41,    82,
      37,    77,    36,    82,    88,   123,   123,   123,   123,   123,
     123,   123,   123,   123,    36,    31,    32,    33,    38,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    60,    61,    62,    64,    65,    66,
     124,    78,   105,    77,    34,    34,    40,   107,    88,    88,
     123,    37,    37,   123,   126,   127,   123,    82,    82,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,    82,
     120,    82,    37,    37,   123,    37,    77,    35,    39,    15,
      16,    17,    20,    23,    26,    41,    88,    97,    98,   106,
     107,   108,   110,   113,   114,   115,   116,   121,   123,   123,
     123,    36,    40,   109,    36,    36,    36,    34,   123,    34,
     123,   119,    17,   123,   123,   123,    34,    34,    18,    19,
      41,    97,    98,   106,   107,   108,   121,   123,    36,    37,
      37,    37,   123,    34,    34,    34,   123,    34,   109,    34,
     109,    40,    34,    37,   112,   117,   123,    34,    21,   111,
      24,    25,    41,   118,    37,    20,    34,   109,   123,    35,
      34,   109,    36,    35,   120,   123,   120,    18,    37,    18,
      34,   109,    34
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    85,    86,    87,    87,    87,    87,    87,    87,    88,
      89,    89,    89,    89,    89,    89,    89,    89,    90,    90,
      90,    91,    91,    91,    91,    91,    91,    91,    92,    93,
      94,    95,    95,    95,    96,    96,    97,    98,    99,   100,
     100,   101,   101,   102,   102,   103,   103,   103,   104,   104,
     105,   105,   106,   107,   108,   108,   108,   108,   108,   109,
     110,   110,   111,   111,   111,   112,   112,   113,   113,   114,
     114,   115,   116,   117,   117,   118,   118,   118,   118,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   120,
     120,   120,   120,   120,   120,   120,   120,   121,   121,   122,
     122,   122,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   124,   124,   125,   126,   126,   126,   127,   127,   128,
     128,   128,   128,   128,   128
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     2,     2,     0,     1,
       1,     1,     2,     2,     1,     2,     2,     2,     5,     5,
       5,     1,     1,     1,     1,     1,     1,     1,     2,     6,
       6,     4,     2,     0,     4,     2,     2,     3,     2,     3,
       1,     3,     1,     1,     3,     3,     1,     0,     3,     1,
       1,     3,     4,     3,     1,     1,     1,     1,     1,     3,
       7,     5,     2,     2,     0,     7,     0,     9,     9,     5,
       5,     7,     7,     2,     0,     6,     4,     5,     3,     2,
       3,     3,     3,     2,     2,     2,     2,     2,     0,     2,
       3,     2,     2,     2,     2,     2,     0,     2,     3,     3,
       2,     0,     4,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     3,     4,     4,     5,     4,     3,
       3,     1,     1,     4,     3,     1,     0,     3,     1,     1,
       1,     1,     1,     1,     1
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
  case 2: /* PROGRAM: GlobalSTMT  */
#line 140 "parser.y"
                        {(yyval.AST_PROG_value)=new Program((yyvsp[0].AST_GSTMT_value)); Root=(yyval.AST_PROG_value);}
#line 1663 "parser.cpp"
    break;

  case 3: /* GlobalSTMT: GlobalSTMT FunDECL  */
#line 145 "parser.y"
                                    {(yyval.AST_GSTMT_value)=(yyvsp[-1].AST_GSTMT_value);(yyval.AST_GSTMT_value)->Addstmt((yyvsp[0].AST_BSTMT_value));}
#line 1669 "parser.cpp"
    break;

  case 4: /* GlobalSTMT: GlobalSTMT FunDEF  */
#line 146 "parser.y"
                                    {(yyval.AST_GSTMT_value)=(yyvsp[-1].AST_GSTMT_value);(yyval.AST_GSTMT_value)->Addstmt((yyvsp[0].AST_BSTMT_value));}
#line 1675 "parser.cpp"
    break;

  case 5: /* GlobalSTMT: GlobalSTMT TypeDEF  */
#line 147 "parser.y"
                                    {(yyval.AST_GSTMT_value)=(yyvsp[-1].AST_GSTMT_value);(yyval.AST_GSTMT_value)->Addstmt((yyvsp[0].AST_BSTMT_value));}
#line 1681 "parser.cpp"
    break;

  case 6: /* GlobalSTMT: GlobalSTMT VarDEF  */
#line 148 "parser.y"
                                    {(yyval.AST_GSTMT_value)=(yyvsp[-1].AST_GSTMT_value);(yyval.AST_GSTMT_value)->Addstmt((yyvsp[0].AST_BSTMT_value));}
#line 1687 "parser.cpp"
    break;

  case 7: /* GlobalSTMT: GlobalSTMT FieldDECL  */
#line 149 "parser.y"
                                    {(yyval.AST_GSTMT_value)=(yyvsp[-1].AST_GSTMT_value);(yyval.AST_GSTMT_value)->Addstmt((yyvsp[0].AST_BSTMT_value));}
#line 1693 "parser.cpp"
    break;

  case 8: /* GlobalSTMT: %empty  */
#line 150 "parser.y"
                                    {(yyval.AST_GSTMT_value)=new Globalstmt();}
#line 1699 "parser.cpp"
    break;

  case 9: /* TYPE: _TYPE  */
#line 154 "parser.y"
                            {(yyval.AST_TYPE_value)=(yyvsp[0].AST_TYPE_value);}
#line 1705 "parser.cpp"
    break;

  case 10: /* _TYPE: BuiltinTYPE  */
#line 159 "parser.y"
                                {(yyval.AST_TYPE_value)=(yyvsp[0].AST_BUILTinTYPE_value);}
#line 1711 "parser.cpp"
    break;

  case 11: /* _TYPE: FieldTYPE  */
#line 160 "parser.y"
                                {(yyval.AST_TYPE_value)=(yyvsp[0].AST_TYPE_value);}
#line 1717 "parser.cpp"
    break;

  case 12: /* _TYPE: _TYPE PTRDEC  */
#line 161 "parser.y"
                                 {(yyval.AST_TYPE_value)=new Pointertype((yyvsp[-1].AST_TYPE_value));}
#line 1723 "parser.cpp"
    break;

  case 13: /* _TYPE: _TYPE ARRAY  */
#line 162 "parser.y"
                                {(yyval.AST_TYPE_value)=new Arraytype((yyvsp[-1].AST_TYPE_value),(yyvsp[0].INT_value));}
#line 1729 "parser.cpp"
    break;

  case 14: /* _TYPE: IDENTIFER  */
#line 163 "parser.y"
                                {(yyval.AST_TYPE_value)=new Definedtype(*(yyvsp[0].IDENTIFER_value));}
#line 1735 "parser.cpp"
    break;

  case 15: /* _TYPE: STRUCT IDENTIFER  */
#line 164 "parser.y"
                                {(yyval.AST_TYPE_value)=new Definedtype(*(yyvsp[0].IDENTIFER_value));}
#line 1741 "parser.cpp"
    break;

  case 16: /* _TYPE: UNION IDENTIFER  */
#line 165 "parser.y"
                                {(yyval.AST_TYPE_value)=new Definedtype(*(yyvsp[0].IDENTIFER_value));}
#line 1747 "parser.cpp"
    break;

  case 17: /* _TYPE: ENUM IDENTIFER  */
#line 166 "parser.y"
                                {(yyval.AST_TYPE_value)=new Definedtype(*(yyvsp[0].IDENTIFER_value));}
#line 1753 "parser.cpp"
    break;

  case 18: /* FieldTYPE: STRUCT IDENTIFER LBRACE SUSTMT RBRACE  */
#line 170 "parser.y"
                                                    {(yyval.AST_TYPE_value)=new Structtype(*(yyvsp[-3].IDENTIFER_value),(yyvsp[-1].AST_SUDECLIST_value));}
#line 1759 "parser.cpp"
    break;

  case 19: /* FieldTYPE: UNION IDENTIFER LBRACE SUSTMT RBRACE  */
#line 171 "parser.y"
                                                    {(yyval.AST_TYPE_value)=new Uniontype(*(yyvsp[-3].IDENTIFER_value),(yyvsp[-1].AST_SUDECLIST_value));}
#line 1765 "parser.cpp"
    break;

  case 20: /* FieldTYPE: ENUM IDENTIFER LBRACE EnmLIST RBRACE  */
#line 172 "parser.y"
                                                    {(yyval.AST_TYPE_value)=new Enumtype(*(yyvsp[-3].IDENTIFER_value),*(yyvsp[-1].AST_ENUMLIST_value));}
#line 1771 "parser.cpp"
    break;

  case 21: /* BuiltinTYPE: CHAR  */
#line 175 "parser.y"
                    {(yyval.AST_BUILTinTYPE_value)=new Builtintype();(yyval.AST_BUILTinTYPE_value)->set_char();}
#line 1777 "parser.cpp"
    break;

  case 22: /* BuiltinTYPE: DOUBLE  */
#line 176 "parser.y"
                    {(yyval.AST_BUILTinTYPE_value)=new Builtintype();(yyval.AST_BUILTinTYPE_value)->set_double();}
#line 1783 "parser.cpp"
    break;

  case 23: /* BuiltinTYPE: FLOAT  */
#line 177 "parser.y"
                    {(yyval.AST_BUILTinTYPE_value)=new Builtintype();(yyval.AST_BUILTinTYPE_value)->set_float();}
#line 1789 "parser.cpp"
    break;

  case 24: /* BuiltinTYPE: INT  */
#line 178 "parser.y"
                    {(yyval.AST_BUILTinTYPE_value)=new Builtintype();(yyval.AST_BUILTinTYPE_value)->set_int();}
#line 1795 "parser.cpp"
    break;

  case 25: /* BuiltinTYPE: SHORT  */
#line 179 "parser.y"
                    {(yyval.AST_BUILTinTYPE_value)=new Builtintype();(yyval.AST_BUILTinTYPE_value)->set_short();}
#line 1801 "parser.cpp"
    break;

  case 26: /* BuiltinTYPE: LONG  */
#line 180 "parser.y"
                    {(yyval.AST_BUILTinTYPE_value)=new Builtintype();(yyval.AST_BUILTinTYPE_value)->set_long();}
#line 1807 "parser.cpp"
    break;

  case 27: /* BuiltinTYPE: VOID  */
#line 181 "parser.y"
                    {(yyval.AST_BUILTinTYPE_value)=new Builtintype();(yyval.AST_BUILTinTYPE_value)->set_void();}
#line 1813 "parser.cpp"
    break;

  case 28: /* ARRAY: ARRAYTAG INTEGER_VAR  */
#line 189 "parser.y"
                                 {(yyval.INT_value)=(yyvsp[0].INT_value);}
#line 1819 "parser.cpp"
    break;

  case 29: /* FunDECL: TYPE IDENTIFER LPAREN ArgLIST RPAREN SEMICOLON  */
#line 194 "parser.y"
                                                            {(yyval.AST_BSTMT_value)=new Fundeclare((yyvsp[-5].AST_TYPE_value),*(yyvsp[-4].IDENTIFER_value),(yyvsp[-2].AST_FUNARGLIST_value));}
#line 1825 "parser.cpp"
    break;

  case 30: /* FunDEF: TYPE IDENTIFER LPAREN ArgLIST RPAREN SCOPE  */
#line 197 "parser.y"
                                                       {(yyval.AST_BSTMT_value) = new Fundefine((yyvsp[-5].AST_TYPE_value),*(yyvsp[-4].IDENTIFER_value),(yyvsp[-2].AST_FUNARGLIST_value),(yyvsp[0].AST_SCOPE_value));(yyvsp[0].AST_SCOPE_value)->setfun();}
#line 1831 "parser.cpp"
    break;

  case 31: /* ArgLIST: _ArgLIST COMMA TYPE IDENTIFER  */
#line 200 "parser.y"
                                                {(yyval.AST_FUNARGLIST_value)=(yyvsp[-3].AST_FUNARGLIST_value); (yyval.AST_FUNARGLIST_value)->push_back(new funArg((yyvsp[-1].AST_TYPE_value),*(yyvsp[0].IDENTIFER_value)));}
#line 1837 "parser.cpp"
    break;

  case 32: /* ArgLIST: TYPE IDENTIFER  */
#line 201 "parser.y"
                                            {(yyval.AST_FUNARGLIST_value)=new funArgList();(yyval.AST_FUNARGLIST_value)->push_back(new funArg((yyvsp[-1].AST_TYPE_value),*(yyvsp[0].IDENTIFER_value)));}
#line 1843 "parser.cpp"
    break;

  case 33: /* ArgLIST: %empty  */
#line 202 "parser.y"
                                            {(yyval.AST_FUNARGLIST_value)=new funArgList();}
#line 1849 "parser.cpp"
    break;

  case 34: /* _ArgLIST: _ArgLIST COMMA TYPE IDENTIFER  */
#line 205 "parser.y"
                                                {(yyval.AST_FUNARGLIST_value)=(yyvsp[-3].AST_FUNARGLIST_value); (yyval.AST_FUNARGLIST_value)->push_back(new funArg((yyvsp[-1].AST_TYPE_value),*(yyvsp[0].IDENTIFER_value)));}
#line 1855 "parser.cpp"
    break;

  case 35: /* _ArgLIST: TYPE IDENTIFER  */
#line 206 "parser.y"
                                              {(yyval.AST_FUNARGLIST_value)=new funArgList();(yyval.AST_FUNARGLIST_value)->push_back(new funArg((yyvsp[-1].AST_TYPE_value),*(yyvsp[0].IDENTIFER_value)));}
#line 1861 "parser.cpp"
    break;

  case 36: /* FieldDECL: FieldTYPE SEMICOLON  */
#line 210 "parser.y"
                                    {(yyval.AST_BSTMT_value)=new Fielddeclare((yyvsp[-1].AST_TYPE_value));}
#line 1867 "parser.cpp"
    break;

  case 37: /* VarDEF: TYPE InitIDLIST SEMICOLON  */
#line 213 "parser.y"
                                        {(yyval.AST_BSTMT_value)=new Vardefine((yyvsp[-2].AST_TYPE_value),(yyvsp[-1].AST_IIDLIST_value));}
#line 1873 "parser.cpp"
    break;

  case 38: /* SUVarDEF: TYPE IdList  */
#line 216 "parser.y"
                          {(yyval.AST_SUDEC_value)=new SUmemdec((yyvsp[-1].AST_TYPE_value),(yyvsp[0].AST_IDLIST_value));}
#line 1879 "parser.cpp"
    break;

  case 39: /* IdList: IdList COMMA IDENTIFER  */
#line 220 "parser.y"
                                    {(yyval.AST_IDLIST_value)=(yyvsp[-2].AST_IDLIST_value); (yyval.AST_IDLIST_value)->push_back(*(yyvsp[0].IDENTIFER_value));}
#line 1885 "parser.cpp"
    break;

  case 40: /* IdList: IDENTIFER  */
#line 221 "parser.y"
                                    {(yyval.AST_IDLIST_value)=new IdentifierList(); (yyval.AST_IDLIST_value)->push_back(*(yyvsp[0].IDENTIFER_value));}
#line 1891 "parser.cpp"
    break;

  case 41: /* InitIDLIST: InitIDLIST COMMA Init  */
#line 225 "parser.y"
                                   {(yyval.AST_IIDLIST_value)=(yyvsp[-2].AST_IIDLIST_value);(yyval.AST_IIDLIST_value)->push_back((yyvsp[0].AST_IID_value));}
#line 1897 "parser.cpp"
    break;

  case 42: /* InitIDLIST: Init  */
#line 226 "parser.y"
                                   {(yyval.AST_IIDLIST_value)=new InitIDList();(yyval.AST_IIDLIST_value)->push_back((yyvsp[0].AST_IID_value));}
#line 1903 "parser.cpp"
    break;

  case 43: /* Init: IDENTIFER  */
#line 229 "parser.y"
                                    {(yyval.AST_IID_value)=new InitID(*(yyvsp[0].IDENTIFER_value));}
#line 1909 "parser.cpp"
    break;

  case 44: /* Init: IDENTIFER ASSIGN EXPR  */
#line 230 "parser.y"
                                    {(yyval.AST_IID_value)=new InitID(*(yyvsp[-2].IDENTIFER_value),(yyvsp[0].AST_EXPR_value));}
#line 1915 "parser.cpp"
    break;

  case 45: /* EnmLIST: _EnmLIST COMMA Enm  */
#line 234 "parser.y"
                                {(yyvsp[-2].AST_ENUMLIST_value)->push_back((yyvsp[0].AST_ENUM_value));(yyval.AST_ENUMLIST_value)=(yyvsp[-2].AST_ENUMLIST_value);}
#line 1921 "parser.cpp"
    break;

  case 46: /* EnmLIST: Enm  */
#line 235 "parser.y"
                                {(yyval.AST_ENUMLIST_value)=new Enumlist();(yyval.AST_ENUMLIST_value)->push_back((yyvsp[0].AST_ENUM_value));}
#line 1927 "parser.cpp"
    break;

  case 47: /* EnmLIST: %empty  */
#line 236 "parser.y"
                                {(yyval.AST_ENUMLIST_value)=new Enumlist();}
#line 1933 "parser.cpp"
    break;

  case 48: /* _EnmLIST: _EnmLIST COMMA Enm  */
#line 239 "parser.y"
                                {(yyvsp[-2].AST_ENUMLIST_value)->push_back((yyvsp[0].AST_ENUM_value));(yyval.AST_ENUMLIST_value)=(yyvsp[-2].AST_ENUMLIST_value);}
#line 1939 "parser.cpp"
    break;

  case 49: /* _EnmLIST: Enm  */
#line 240 "parser.y"
                                {(yyval.AST_ENUMLIST_value)=new Enumlist();(yyval.AST_ENUMLIST_value)->push_back((yyvsp[0].AST_ENUM_value));}
#line 1945 "parser.cpp"
    break;

  case 50: /* Enm: IDENTIFER  */
#line 243 "parser.y"
                                            {(yyval.AST_ENUM_value)=new Enum(*(yyvsp[0].IDENTIFER_value));}
#line 1951 "parser.cpp"
    break;

  case 51: /* Enm: IDENTIFER ASSIGN INTEGER_VAR  */
#line 244 "parser.y"
                                            {(yyval.AST_ENUM_value)=new Enum(*(yyvsp[-2].IDENTIFER_value),(yyvsp[0].INT_value));}
#line 1957 "parser.cpp"
    break;

  case 52: /* TypeDEF: TYPEDEF TYPE IDENTIFER SEMICOLON  */
#line 248 "parser.y"
                                                {(yyval.AST_BSTMT_value)=new TypeDefine(new Definedtype((yyvsp[-2].AST_TYPE_value),*(yyvsp[-1].IDENTIFER_value)));}
#line 1963 "parser.cpp"
    break;

  case 53: /* SCOPE: LBRACE STMT RBRACE  */
#line 252 "parser.y"
                                {(yyval.AST_SCOPE_value)=new Scope((yyvsp[-1].AST_STMT_value));}
#line 1969 "parser.cpp"
    break;

  case 54: /* CtrlFLOW: IfFLOW  */
#line 256 "parser.y"
                            {(yyval.AST_BSTMT_value)=(yyvsp[0].AST_BSTMT_value);}
#line 1975 "parser.cpp"
    break;

  case 55: /* CtrlFLOW: ForFLOW  */
#line 257 "parser.y"
                            {(yyval.AST_BSTMT_value)=(yyvsp[0].AST_BSTMT_value);}
#line 1981 "parser.cpp"
    break;

  case 56: /* CtrlFLOW: DowhileFLOW  */
#line 258 "parser.y"
                            {(yyval.AST_BSTMT_value)=(yyvsp[0].AST_BSTMT_value);}
#line 1987 "parser.cpp"
    break;

  case 57: /* CtrlFLOW: WhileFLOW  */
#line 259 "parser.y"
                            {(yyval.AST_BSTMT_value)=(yyvsp[0].AST_BSTMT_value);}
#line 1993 "parser.cpp"
    break;

  case 58: /* CtrlFLOW: SwitchFLOW  */
#line 260 "parser.y"
                            {(yyval.AST_BSTMT_value)=(yyvsp[0].AST_BSTMT_value);}
#line 1999 "parser.cpp"
    break;

  case 59: /* CtrlSCOPE: LBRACE CtrlSTMT RBRACE  */
#line 263 "parser.y"
                                    {(yyval.AST_SCOPE_value)=new Scope((yyvsp[-1].AST_STMT_value));}
#line 2005 "parser.cpp"
    break;

  case 60: /* IfFLOW: IF LPAREN EXPR RPAREN CtrlSCOPE ElseifFLOW ElseFLOW  */
#line 265 "parser.y"
                                                                {(yyval.AST_BSTMT_value)=new Ifflow((yyvsp[-4].AST_EXPR_value),(yyvsp[-2].AST_SCOPE_value),(yyvsp[-1].AST_ELIF_value),(yyvsp[0].AST_ELSE_value));}
#line 2011 "parser.cpp"
    break;

  case 61: /* IfFLOW: IF LPAREN EXPR RPAREN SEMICOLON  */
#line 266 "parser.y"
                                                                {(yyval.AST_BSTMT_value)=new Ifflow((yyvsp[-2].AST_EXPR_value));}
#line 2017 "parser.cpp"
    break;

  case 62: /* ElseFLOW: ELSE CtrlSCOPE  */
#line 269 "parser.y"
                                  {(yyval.AST_ELSE_value)=new Elseflow((yyvsp[0].AST_SCOPE_value));}
#line 2023 "parser.cpp"
    break;

  case 63: /* ElseFLOW: ELSE SEMICOLON  */
#line 270 "parser.y"
                                  {(yyval.AST_ELSE_value)=new Elseflow();}
#line 2029 "parser.cpp"
    break;

  case 64: /* ElseFLOW: %empty  */
#line 271 "parser.y"
                                  {(yyval.AST_ELSE_value)=new Elseflow();}
#line 2035 "parser.cpp"
    break;

  case 65: /* ElseifFLOW: ElseifFLOW ELSE IF LPAREN EXPR RPAREN CtrlSCOPE  */
#line 274 "parser.y"
                                                            {(yyval.AST_ELIF_value)=(yyvsp[-6].AST_ELIF_value);(yyval.AST_ELIF_value)->Addelseif((yyvsp[-2].AST_EXPR_value),(yyvsp[0].AST_SCOPE_value));}
#line 2041 "parser.cpp"
    break;

  case 66: /* ElseifFLOW: %empty  */
#line 275 "parser.y"
                                                            {(yyval.AST_ELIF_value)=new Elseifflow();}
#line 2047 "parser.cpp"
    break;

  case 67: /* ForFLOW: FOR LPAREN EXPR SEMICOLON EXPR SEMICOLON EXPR RPAREN SEMICOLON  */
#line 279 "parser.y"
                                                                                {(yyval.AST_BSTMT_value)=new Forflow((yyvsp[-6].AST_EXPR_value),(yyvsp[-4].AST_EXPR_value),(yyvsp[-2].AST_EXPR_value));}
#line 2053 "parser.cpp"
    break;

  case 68: /* ForFLOW: FOR LPAREN EXPR SEMICOLON EXPR SEMICOLON EXPR RPAREN CtrlSCOPE  */
#line 280 "parser.y"
                                                                                {(yyval.AST_BSTMT_value)=new Forflow((yyvsp[-6].AST_EXPR_value),(yyvsp[-4].AST_EXPR_value),(yyvsp[-2].AST_EXPR_value),(yyvsp[0].AST_SCOPE_value));}
#line 2059 "parser.cpp"
    break;

  case 69: /* WhileFLOW: WHILE LPAREN EXPR RPAREN CtrlSCOPE  */
#line 283 "parser.y"
                                                    {(yyval.AST_BSTMT_value)=new Whileflow((yyvsp[-2].AST_EXPR_value),(yyvsp[0].AST_SCOPE_value));}
#line 2065 "parser.cpp"
    break;

  case 70: /* WhileFLOW: WHILE LPAREN EXPR RPAREN SEMICOLON  */
#line 284 "parser.y"
                                                    {(yyval.AST_BSTMT_value)=new Whileflow((yyvsp[-2].AST_EXPR_value));}
#line 2071 "parser.cpp"
    break;

  case 71: /* DowhileFLOW: DO CtrlSCOPE WHILE LPAREN EXPR RPAREN SEMICOLON  */
#line 287 "parser.y"
                                                                {(yyval.AST_BSTMT_value)=new Dowhileflow((yyvsp[-2].AST_EXPR_value),(yyvsp[-5].AST_SCOPE_value));}
#line 2077 "parser.cpp"
    break;

  case 72: /* SwitchFLOW: SWITCH LPAREN EXPR RPAREN LBRACE CaseLIST RBRACE  */
#line 291 "parser.y"
                                                                {(yyval.AST_BSTMT_value)=new Switchflow((yyvsp[-4].AST_EXPR_value),(yyvsp[-1].AST_CASELIST_value));}
#line 2083 "parser.cpp"
    break;

  case 73: /* CaseLIST: CaseLIST CaseSTMT  */
#line 294 "parser.y"
                                {(yyval.AST_CASELIST_value)->push_back((yyvsp[0].AST_CASE_value));}
#line 2089 "parser.cpp"
    break;

  case 74: /* CaseLIST: %empty  */
#line 295 "parser.y"
                                {(yyval.AST_CASELIST_value)=new Caselist();}
#line 2095 "parser.cpp"
    break;

  case 75: /* CaseSTMT: CASE EXPR COLON STMT BREAK SEMICOLON  */
#line 299 "parser.y"
                                                    {(yyval.AST_CASE_value)=new Case((yyvsp[-4].AST_EXPR_value),(yyvsp[-2].AST_STMT_value));(yyval.AST_CASE_value)->set_break();}
#line 2101 "parser.cpp"
    break;

  case 76: /* CaseSTMT: CASE EXPR COLON STMT  */
#line 300 "parser.y"
                                                    {(yyval.AST_CASE_value)=new Case((yyvsp[-2].AST_EXPR_value),(yyvsp[0].AST_STMT_value));}
#line 2107 "parser.cpp"
    break;

  case 77: /* CaseSTMT: DEFAULT COLON STMT BREAK SEMICOLON  */
#line 301 "parser.y"
                                                    {(yyval.AST_CASE_value)=new Case((yyvsp[-2].AST_STMT_value));(yyval.AST_CASE_value)->set_break();(yyval.AST_CASE_value)->set_default();}
#line 2113 "parser.cpp"
    break;

  case 78: /* CaseSTMT: DEFAULT COLON STMT  */
#line 302 "parser.y"
                                                    {(yyval.AST_CASE_value)=new Case((yyvsp[0].AST_STMT_value));(yyval.AST_CASE_value)->set_default();}
#line 2119 "parser.cpp"
    break;

  case 79: /* CtrlSTMT: CtrlSTMT CtrlFLOW  */
#line 305 "parser.y"
                                            {(yyval.AST_STMT_value)=(yyvsp[-1].AST_STMT_value); (yyval.AST_STMT_value)->Addstmt((yyvsp[0].AST_BSTMT_value));}
#line 2125 "parser.cpp"
    break;

  case 80: /* CtrlSTMT: CtrlSTMT BREAK SEMICOLON  */
#line 306 "parser.y"
                                            {(yyval.AST_STMT_value)=(yyvsp[-2].AST_STMT_value); (yyval.AST_STMT_value)->Addstmt(new Breakstmt());}
#line 2131 "parser.cpp"
    break;

  case 81: /* CtrlSTMT: CtrlSTMT CONTINUE SEMICOLON  */
#line 307 "parser.y"
                                            {(yyval.AST_STMT_value)=(yyvsp[-2].AST_STMT_value); (yyval.AST_STMT_value)->Addstmt(new Continuestmt());}
#line 2137 "parser.cpp"
    break;

  case 82: /* CtrlSTMT: CtrlSTMT EXPR SEMICOLON  */
#line 308 "parser.y"
                                            {(yyval.AST_STMT_value)=(yyvsp[-2].AST_STMT_value); (yyval.AST_STMT_value)->Addstmt(new Exprstmt((yyvsp[-1].AST_EXPR_value)));}
#line 2143 "parser.cpp"
    break;

  case 83: /* CtrlSTMT: CtrlSTMT SCOPE  */
#line 309 "parser.y"
                                            {(yyval.AST_STMT_value)=(yyvsp[-1].AST_STMT_value); (yyval.AST_STMT_value)->Addstmt((yyvsp[0].AST_SCOPE_value));}
#line 2149 "parser.cpp"
    break;

  case 84: /* CtrlSTMT: CtrlSTMT TypeDEF  */
#line 310 "parser.y"
                                            {(yyval.AST_STMT_value)=(yyvsp[-1].AST_STMT_value); (yyval.AST_STMT_value)->Addstmt((yyvsp[0].AST_BSTMT_value));}
#line 2155 "parser.cpp"
    break;

  case 85: /* CtrlSTMT: CtrlSTMT VarDEF  */
#line 311 "parser.y"
                                            {(yyval.AST_STMT_value)=(yyvsp[-1].AST_STMT_value); (yyval.AST_STMT_value)->Addstmt((yyvsp[0].AST_BSTMT_value));}
#line 2161 "parser.cpp"
    break;

  case 86: /* CtrlSTMT: CtrlSTMT FieldDECL  */
#line 312 "parser.y"
                                            {(yyval.AST_STMT_value)=(yyvsp[-1].AST_STMT_value); (yyval.AST_STMT_value)->Addstmt((yyvsp[0].AST_BSTMT_value));}
#line 2167 "parser.cpp"
    break;

  case 87: /* CtrlSTMT: CtrlSTMT ReturnSTMT  */
#line 313 "parser.y"
                                            {(yyval.AST_STMT_value)=(yyvsp[-1].AST_STMT_value); (yyval.AST_STMT_value)->Addstmt((yyvsp[0].AST_BSTMT_value));}
#line 2173 "parser.cpp"
    break;

  case 88: /* CtrlSTMT: %empty  */
#line 314 "parser.y"
                                            {(yyval.AST_STMT_value)=new Stmt();}
#line 2179 "parser.cpp"
    break;

  case 89: /* STMT: STMT CtrlFLOW  */
#line 318 "parser.y"
                                    {(yyval.AST_STMT_value)=(yyvsp[-1].AST_STMT_value); (yyval.AST_STMT_value)->Addstmt((yyvsp[0].AST_BSTMT_value));}
#line 2185 "parser.cpp"
    break;

  case 90: /* STMT: STMT EXPR SEMICOLON  */
#line 319 "parser.y"
                                    {(yyval.AST_STMT_value)=(yyvsp[-2].AST_STMT_value); (yyval.AST_STMT_value)->Addstmt(new Exprstmt((yyvsp[-1].AST_EXPR_value)));}
#line 2191 "parser.cpp"
    break;

  case 91: /* STMT: STMT SCOPE  */
#line 320 "parser.y"
                                    {(yyval.AST_STMT_value)=(yyvsp[-1].AST_STMT_value); (yyval.AST_STMT_value)->Addstmt((yyvsp[0].AST_SCOPE_value));}
#line 2197 "parser.cpp"
    break;

  case 92: /* STMT: STMT TypeDEF  */
#line 321 "parser.y"
                                    {(yyval.AST_STMT_value)=(yyvsp[-1].AST_STMT_value); (yyval.AST_STMT_value)->Addstmt((yyvsp[0].AST_BSTMT_value));}
#line 2203 "parser.cpp"
    break;

  case 93: /* STMT: STMT VarDEF  */
#line 322 "parser.y"
                                    {(yyval.AST_STMT_value)=(yyvsp[-1].AST_STMT_value); (yyval.AST_STMT_value)->Addstmt((yyvsp[0].AST_BSTMT_value));}
#line 2209 "parser.cpp"
    break;

  case 94: /* STMT: STMT FieldDECL  */
#line 323 "parser.y"
                                    {(yyval.AST_STMT_value)=(yyvsp[-1].AST_STMT_value); (yyval.AST_STMT_value)->Addstmt((yyvsp[0].AST_BSTMT_value));}
#line 2215 "parser.cpp"
    break;

  case 95: /* STMT: STMT ReturnSTMT  */
#line 324 "parser.y"
                                    {(yyval.AST_STMT_value)=(yyvsp[-1].AST_STMT_value); (yyval.AST_STMT_value)->Addstmt((yyvsp[0].AST_BSTMT_value));}
#line 2221 "parser.cpp"
    break;

  case 96: /* STMT: %empty  */
#line 325 "parser.y"
                                    {(yyval.AST_STMT_value)=new Stmt();}
#line 2227 "parser.cpp"
    break;

  case 97: /* ReturnSTMT: RETURN SEMICOLON  */
#line 328 "parser.y"
                                    {(yyval.AST_BSTMT_value)=new Returnstmt();}
#line 2233 "parser.cpp"
    break;

  case 98: /* ReturnSTMT: RETURN EXPR SEMICOLON  */
#line 329 "parser.y"
                                    {(yyval.AST_BSTMT_value)=new Returnstmt((yyvsp[-1].AST_EXPR_value));}
#line 2239 "parser.cpp"
    break;

  case 99: /* SUSTMT: SUSTMT SUVarDEF SEMICOLON  */
#line 332 "parser.y"
                                        {(yyval.AST_SUDECLIST_value)=(yyvsp[-2].AST_SUDECLIST_value);(yyval.AST_SUDECLIST_value)->push_back((yyvsp[-1].AST_SUDEC_value));}
#line 2245 "parser.cpp"
    break;

  case 100: /* SUSTMT: SUVarDEF SEMICOLON  */
#line 333 "parser.y"
                                        {(yyval.AST_SUDECLIST_value)=new SUdecllist(); (yyval.AST_SUDECLIST_value)->push_back((yyvsp[-1].AST_SUDEC_value));}
#line 2251 "parser.cpp"
    break;

  case 101: /* SUSTMT: %empty  */
#line 334 "parser.y"
                                        {(yyval.AST_SUDECLIST_value)=new SUdecllist(); }
#line 2257 "parser.cpp"
    break;

  case 102: /* EXPR: EXPR LBRACKET EXPR RBRACKET  */
#line 342 "parser.y"
                                                      {(yyval.AST_EXPR_value) = new Subscript((yyvsp[-3].AST_EXPR_value), (yyvsp[-1].AST_EXPR_value));}
#line 2263 "parser.cpp"
    break;

  case 103: /* EXPR: IDENTIFER  */
#line 343 "parser.y"
                                            {(yyval.AST_EXPR_value) = new Variable(*((yyvsp[0].IDENTIFER_value)));}
#line 2269 "parser.cpp"
    break;

  case 104: /* EXPR: FUNCALL  */
#line 344 "parser.y"
                                            {(yyval.AST_EXPR_value) = (yyvsp[0].AST_FUNCALL_value);}
#line 2275 "parser.cpp"
    break;

  case 105: /* EXPR: CONSTANT  */
#line 345 "parser.y"
                                            {(yyval.AST_EXPR_value) = (yyvsp[0].AST_CONSTANT_value);}
#line 2281 "parser.cpp"
    break;

  case 106: /* EXPR: EXPR ADD EXPR  */
#line 346 "parser.y"
                                            {(yyval.AST_EXPR_value) = new BinopExpr((yyvsp[-1].token), (yyvsp[-2].AST_EXPR_value), (yyvsp[0].AST_EXPR_value));}
#line 2287 "parser.cpp"
    break;

  case 107: /* EXPR: EXPR SUB EXPR  */
#line 347 "parser.y"
                                            {(yyval.AST_EXPR_value) = new BinopExpr((yyvsp[-1].token), (yyvsp[-2].AST_EXPR_value), (yyvsp[0].AST_EXPR_value));}
#line 2293 "parser.cpp"
    break;

  case 108: /* EXPR: EXPR MUL EXPR  */
#line 348 "parser.y"
                                            {(yyval.AST_EXPR_value) = new BinopExpr((yyvsp[-1].token), (yyvsp[-2].AST_EXPR_value), (yyvsp[0].AST_EXPR_value));}
#line 2299 "parser.cpp"
    break;

  case 109: /* EXPR: EXPR DIV EXPR  */
#line 349 "parser.y"
                                            {(yyval.AST_EXPR_value) = new BinopExpr((yyvsp[-1].token), (yyvsp[-2].AST_EXPR_value), (yyvsp[0].AST_EXPR_value));}
#line 2305 "parser.cpp"
    break;

  case 110: /* EXPR: EXPR MOD EXPR  */
#line 350 "parser.y"
                                            {(yyval.AST_EXPR_value) = new BinopExpr((yyvsp[-1].token), (yyvsp[-2].AST_EXPR_value), (yyvsp[0].AST_EXPR_value));}
#line 2311 "parser.cpp"
    break;

  case 111: /* EXPR: EXPR EQ EXPR  */
#line 351 "parser.y"
                                            {(yyval.AST_EXPR_value) = new BinopExpr((yyvsp[-1].token), (yyvsp[-2].AST_EXPR_value), (yyvsp[0].AST_EXPR_value));}
#line 2317 "parser.cpp"
    break;

  case 112: /* EXPR: EXPR NE EXPR  */
#line 352 "parser.y"
                                            {(yyval.AST_EXPR_value) = new BinopExpr((yyvsp[-1].token), (yyvsp[-2].AST_EXPR_value), (yyvsp[0].AST_EXPR_value));}
#line 2323 "parser.cpp"
    break;

  case 113: /* EXPR: EXPR GT EXPR  */
#line 353 "parser.y"
                                            {(yyval.AST_EXPR_value) = new BinopExpr((yyvsp[-1].token), (yyvsp[-2].AST_EXPR_value), (yyvsp[0].AST_EXPR_value));}
#line 2329 "parser.cpp"
    break;

  case 114: /* EXPR: EXPR LT EXPR  */
#line 354 "parser.y"
                                            {(yyval.AST_EXPR_value) = new BinopExpr((yyvsp[-1].token), (yyvsp[-2].AST_EXPR_value), (yyvsp[0].AST_EXPR_value));}
#line 2335 "parser.cpp"
    break;

  case 115: /* EXPR: EXPR GE EXPR  */
#line 355 "parser.y"
                                            {(yyval.AST_EXPR_value) = new BinopExpr((yyvsp[-1].token), (yyvsp[-2].AST_EXPR_value), (yyvsp[0].AST_EXPR_value));}
#line 2341 "parser.cpp"
    break;

  case 116: /* EXPR: EXPR LE EXPR  */
#line 356 "parser.y"
                                            {(yyval.AST_EXPR_value) = new BinopExpr((yyvsp[-1].token), (yyvsp[-2].AST_EXPR_value), (yyvsp[0].AST_EXPR_value));}
#line 2347 "parser.cpp"
    break;

  case 117: /* EXPR: EXPR AND EXPR  */
#line 357 "parser.y"
                                            {(yyval.AST_EXPR_value) = new BinopExpr((yyvsp[-1].token), (yyvsp[-2].AST_EXPR_value), (yyvsp[0].AST_EXPR_value));}
#line 2353 "parser.cpp"
    break;

  case 118: /* EXPR: EXPR OR EXPR  */
#line 358 "parser.y"
                                            {(yyval.AST_EXPR_value) = new BinopExpr((yyvsp[-1].token), (yyvsp[-2].AST_EXPR_value), (yyvsp[0].AST_EXPR_value));}
#line 2359 "parser.cpp"
    break;

  case 119: /* EXPR: EXPR BAND EXPR  */
#line 359 "parser.y"
                                            {(yyval.AST_EXPR_value) = new BinopExpr((yyvsp[-1].token), (yyvsp[-2].AST_EXPR_value), (yyvsp[0].AST_EXPR_value));}
#line 2365 "parser.cpp"
    break;

  case 120: /* EXPR: EXPR BOR EXPR  */
#line 360 "parser.y"
                                            {(yyval.AST_EXPR_value) = new BinopExpr((yyvsp[-1].token), (yyvsp[-2].AST_EXPR_value), (yyvsp[0].AST_EXPR_value));}
#line 2371 "parser.cpp"
    break;

  case 121: /* EXPR: EXPR BXOR EXPR  */
#line 361 "parser.y"
                                            {(yyval.AST_EXPR_value) = new BinopExpr((yyvsp[-1].token), (yyvsp[-2].AST_EXPR_value), (yyvsp[0].AST_EXPR_value));}
#line 2377 "parser.cpp"
    break;

  case 122: /* EXPR: EXPR SHL EXPR  */
#line 362 "parser.y"
                                            {(yyval.AST_EXPR_value) = new BinopExpr((yyvsp[-1].token), (yyvsp[-2].AST_EXPR_value), (yyvsp[0].AST_EXPR_value));}
#line 2383 "parser.cpp"
    break;

  case 123: /* EXPR: EXPR SHR EXPR  */
#line 363 "parser.y"
                                            {(yyval.AST_EXPR_value) = new BinopExpr((yyvsp[-1].token), (yyvsp[-2].AST_EXPR_value), (yyvsp[0].AST_EXPR_value));}
#line 2389 "parser.cpp"
    break;

  case 124: /* EXPR: EXPR ASSIGN EXPR  */
#line 364 "parser.y"
                                            {(yyval.AST_EXPR_value) = new BinopExpr((yyvsp[-1].token), (yyvsp[-2].AST_EXPR_value), (yyvsp[0].AST_EXPR_value));}
#line 2395 "parser.cpp"
    break;

  case 125: /* EXPR: INC EXPR  */
#line 366 "parser.y"
                                                       {(yyval.AST_EXPR_value) = new UnaopExpr((yyvsp[-1].token), (yyvsp[0].AST_EXPR_value));}
#line 2401 "parser.cpp"
    break;

  case 126: /* EXPR: DEC EXPR  */
#line 367 "parser.y"
                                                      {(yyval.AST_EXPR_value) = new UnaopExpr((yyvsp[-1].token), (yyvsp[0].AST_EXPR_value));}
#line 2407 "parser.cpp"
    break;

  case 127: /* EXPR: NOT EXPR  */
#line 368 "parser.y"
                                          {(yyval.AST_EXPR_value) = new UnaopExpr((yyvsp[-1].token), (yyvsp[0].AST_EXPR_value));}
#line 2413 "parser.cpp"
    break;

  case 128: /* EXPR: BNOT EXPR  */
#line 369 "parser.y"
                                           {(yyval.AST_EXPR_value) = new UnaopExpr((yyvsp[-1].token), (yyvsp[0].AST_EXPR_value));}
#line 2419 "parser.cpp"
    break;

  case 129: /* EXPR: MUL EXPR  */
#line 370 "parser.y"
                                                      {(yyval.AST_EXPR_value) = new UnaopExpr((yyvsp[-1].token), (yyvsp[0].AST_EXPR_value));}
#line 2425 "parser.cpp"
    break;

  case 130: /* EXPR: BAND EXPR  */
#line 371 "parser.y"
                                                       {(yyval.AST_EXPR_value) = new UnaopExpr((yyvsp[-1].token), (yyvsp[0].AST_EXPR_value));}
#line 2431 "parser.cpp"
    break;

  case 131: /* EXPR: ADD EXPR  */
#line 372 "parser.y"
                                                      {(yyval.AST_EXPR_value) = new UnaopExpr((yyvsp[-1].token), (yyvsp[0].AST_EXPR_value));}
#line 2437 "parser.cpp"
    break;

  case 132: /* EXPR: SUB EXPR  */
#line 373 "parser.y"
                                                      {(yyval.AST_EXPR_value) = new UnaopExpr((yyvsp[-1].token), (yyvsp[0].AST_EXPR_value));}
#line 2443 "parser.cpp"
    break;

  case 133: /* EXPR: EXPR SUFOP  */
#line 375 "parser.y"
                                            {(yyval.AST_EXPR_value) = new SufopExpr((yyvsp[0].int_value), (yyvsp[-1].AST_EXPR_value));}
#line 2449 "parser.cpp"
    break;

  case 134: /* EXPR: LPAREN EXPR RPAREN  */
#line 376 "parser.y"
                                            {(yyval.AST_EXPR_value) = (yyvsp[-1].AST_EXPR_value);}
#line 2455 "parser.cpp"
    break;

  case 135: /* EXPR: SIZEOF LPAREN EXPR RPAREN  */
#line 377 "parser.y"
                                            {(yyval.AST_EXPR_value) = new SizeofExpr((yyvsp[-1].AST_EXPR_value));}
#line 2461 "parser.cpp"
    break;

  case 136: /* EXPR: SIZEOF LPAREN TYPE RPAREN  */
#line 378 "parser.y"
                                            {(yyval.AST_EXPR_value) = new SizeofType((yyvsp[-1].AST_TYPE_value));}
#line 2467 "parser.cpp"
    break;

  case 137: /* EXPR: EXPR CONDITION EXPR COLON EXPR  */
#line 379 "parser.y"
                                             {(yyval.AST_EXPR_value) = new TernaryCondition((yyvsp[-4].AST_EXPR_value), (yyvsp[-2].AST_EXPR_value), (yyvsp[0].AST_EXPR_value));}
#line 2473 "parser.cpp"
    break;

  case 138: /* EXPR: LPAREN TYPE RPAREN EXPR  */
#line 380 "parser.y"
                                                         {(yyval.AST_EXPR_value) = new TypeCast((yyvsp[-2].AST_TYPE_value), (yyvsp[0].AST_EXPR_value));}
#line 2479 "parser.cpp"
    break;

  case 139: /* EXPR: EXPR ARROW IDENTIFER  */
#line 381 "parser.y"
                                            {(yyval.AST_EXPR_value) = new MemAccessPtr((yyvsp[-2].AST_EXPR_value), *(yyvsp[0].IDENTIFER_value));}
#line 2485 "parser.cpp"
    break;

  case 140: /* EXPR: EXPR DOT IDENTIFER  */
#line 382 "parser.y"
                                            {(yyval.AST_EXPR_value) = new MemAccessObj((yyvsp[-2].AST_EXPR_value), *(yyvsp[0].IDENTIFER_value));}
#line 2491 "parser.cpp"
    break;

  case 141: /* SUFOP: INC  */
#line 395 "parser.y"
                     {(yyval.int_value) = (yyvsp[0].token);}
#line 2497 "parser.cpp"
    break;

  case 142: /* SUFOP: DEC  */
#line 396 "parser.y"
                    {(yyval.int_value) = (yyvsp[0].token);}
#line 2503 "parser.cpp"
    break;

  case 143: /* FUNCALL: IDENTIFER LPAREN CallArgLIST RPAREN  */
#line 432 "parser.y"
                {(yyval.AST_FUNCALL_value) = new FuncCall(*((yyvsp[-3].IDENTIFER_value)), (yyvsp[-1].AST_CALLARGLIST_value));}
#line 2509 "parser.cpp"
    break;

  case 144: /* CallArgLIST: _CallArgLIST COMMA EXPR  */
#line 435 "parser.y"
                                            {(yyval.AST_CALLARGLIST_value) = (yyvsp[-2].AST_CALLARGLIST_value); (yyval.AST_CALLARGLIST_value)->push_back((yyvsp[0].AST_EXPR_value));}
#line 2515 "parser.cpp"
    break;

  case 145: /* CallArgLIST: EXPR  */
#line 436 "parser.y"
                                            {(yyval.AST_CALLARGLIST_value) = new CallArgList(); (yyval.AST_CALLARGLIST_value)->push_back((yyvsp[0].AST_EXPR_value));}
#line 2521 "parser.cpp"
    break;

  case 146: /* CallArgLIST: %empty  */
#line 437 "parser.y"
                                            {(yyval.AST_CALLARGLIST_value) = new CallArgList();}
#line 2527 "parser.cpp"
    break;

  case 147: /* _CallArgLIST: _CallArgLIST COMMA EXPR  */
#line 440 "parser.y"
                                            {(yyval.AST_CALLARGLIST_value) = (yyvsp[-2].AST_CALLARGLIST_value); (yyval.AST_CALLARGLIST_value)->push_back((yyvsp[0].AST_EXPR_value));}
#line 2533 "parser.cpp"
    break;

  case 148: /* _CallArgLIST: EXPR  */
#line 441 "parser.y"
                                            {(yyval.AST_CALLARGLIST_value) = new CallArgList(); (yyval.AST_CALLARGLIST_value)->push_back((yyvsp[0].AST_EXPR_value));}
#line 2539 "parser.cpp"
    break;

  case 149: /* CONSTANT: TRUE  */
#line 444 "parser.y"
                            {enum Csttype t=cstty_bool; (yyval.AST_CONSTANT_value)=new Constant(true,t);}
#line 2545 "parser.cpp"
    break;

  case 150: /* CONSTANT: FALSE  */
#line 445 "parser.y"
                            {enum Csttype t=cstty_bool; (yyval.AST_CONSTANT_value)=new Constant(false,t);}
#line 2551 "parser.cpp"
    break;

  case 151: /* CONSTANT: CHAR_VAR  */
#line 446 "parser.y"
                            {enum Csttype t=cstty_char; (yyval.AST_CONSTANT_value)=new Constant((yyvsp[0].CHAR_value),t);}
#line 2557 "parser.cpp"
    break;

  case 152: /* CONSTANT: INTEGER_VAR  */
#line 447 "parser.y"
                            {enum Csttype t=cstty_int; (yyval.AST_CONSTANT_value)=new Constant((yyvsp[0].INT_value),t);}
#line 2563 "parser.cpp"
    break;

  case 153: /* CONSTANT: REAL_VAR  */
#line 448 "parser.y"
                            {enum Csttype t=cstty_real; (yyval.AST_CONSTANT_value)=new Constant((yyvsp[0].REAL_value),t);}
#line 2569 "parser.cpp"
    break;

  case 154: /* CONSTANT: STRING_VAR  */
#line 449 "parser.y"
                            {enum Csttype t=cstty_str; (yyval.AST_CONSTANT_value)=new Constant(*((yyvsp[0].STRING_value)),t);}
#line 2575 "parser.cpp"
    break;


#line 2579 "parser.cpp"

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

#line 453 "parser.y"
