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
#line 8 "spell.y"

#include <iostream>
#include <string>
#include <vector>
#include "SymTable.h"
#include "AST.h"
#include "Value.h"
using namespace std;

extern int yylex();
extern int yylineno;
SymTableManager tableManager;
string currentType;
string currentClass;
SymbolInfo* currentFunction = nullptr;
void yyerror(const char *s);
int errorCount = 0;


#line 91 "spell.tab.c"

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

#include "spell.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_DUEL_KW = 3,                    /* DUEL_KW  */
  YYSYMBOL_HOUSE_KW = 4,                   /* HOUSE_KW  */
  YYSYMBOL_FIELD_KW = 5,                   /* FIELD_KW  */
  YYSYMBOL_CHARM_KW = 6,                   /* CHARM_KW  */
  YYSYMBOL_SPELL_KW = 7,                   /* SPELL_KW  */
  YYSYMBOL_PARCHMENT_KW = 8,               /* PARCHMENT_KW  */
  YYSYMBOL_SUMMON_KW = 9,                  /* SUMMON_KW  */
  YYSYMBOL_IF_KW = 10,                     /* IF_KW  */
  YYSYMBOL_WHILE_KW = 11,                  /* WHILE_KW  */
  YYSYMBOL_ELSE_KW = 12,                   /* ELSE_KW  */
  YYSYMBOL_RETURN_KW = 13,                 /* RETURN_KW  */
  YYSYMBOL_PRINT_KW = 14,                  /* PRINT_KW  */
  YYSYMBOL_TYPE_INT = 15,                  /* TYPE_INT  */
  YYSYMBOL_TYPE_FLOAT = 16,                /* TYPE_FLOAT  */
  YYSYMBOL_TYPE_STRING = 17,               /* TYPE_STRING  */
  YYSYMBOL_TYPE_BOOL = 18,                 /* TYPE_BOOL  */
  YYSYMBOL_ID = 19,                        /* ID  */
  YYSYMBOL_INT_LITERAL = 20,               /* INT_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 21,             /* FLOAT_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 22,            /* STRING_LITERAL  */
  YYSYMBOL_TRUE_LITERAL = 23,              /* TRUE_LITERAL  */
  YYSYMBOL_FALSE_LITERAL = 24,             /* FALSE_LITERAL  */
  YYSYMBOL_ASSIGN_OP = 25,                 /* ASSIGN_OP  */
  YYSYMBOL_ACCESS_OP = 26,                 /* ACCESS_OP  */
  YYSYMBOL_OR = 27,                        /* OR  */
  YYSYMBOL_AND = 28,                       /* AND  */
  YYSYMBOL_EQUAL = 29,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 30,                 /* NOT_EQUAL  */
  YYSYMBOL_31_ = 31,                       /* '<'  */
  YYSYMBOL_LESS_EQUAL = 32,                /* LESS_EQUAL  */
  YYSYMBOL_33_ = 33,                       /* '>'  */
  YYSYMBOL_GREATER_EQUAL = 34,             /* GREATER_EQUAL  */
  YYSYMBOL_35_ = 35,                       /* '+'  */
  YYSYMBOL_36_ = 36,                       /* '-'  */
  YYSYMBOL_37_ = 37,                       /* '*'  */
  YYSYMBOL_38_ = 38,                       /* '/'  */
  YYSYMBOL_39_ = 39,                       /* '%'  */
  YYSYMBOL_NOT = 40,                       /* NOT  */
  YYSYMBOL_UMINUS = 41,                    /* UMINUS  */
  YYSYMBOL_42_ = 42,                       /* ':'  */
  YYSYMBOL_43_ = 43,                       /* ';'  */
  YYSYMBOL_44_ = 44,                       /* '{'  */
  YYSYMBOL_45_ = 45,                       /* '}'  */
  YYSYMBOL_46_ = 46,                       /* '('  */
  YYSYMBOL_47_ = 47,                       /* ')'  */
  YYSYMBOL_48_ = 48,                       /* ','  */
  YYSYMBOL_YYACCEPT = 49,                  /* $accept  */
  YYSYMBOL_program = 50,                   /* program  */
  YYSYMBOL_def_globale = 51,               /* def_globale  */
  YYSYMBOL_def_globala = 52,               /* def_globala  */
  YYSYMBOL_global_decl = 53,               /* global_decl  */
  YYSYMBOL_duel = 54,                      /* duel  */
  YYSYMBOL_55_1 = 55,                      /* $@1  */
  YYSYMBOL_bloc_fara_decl = 56,            /* bloc_fara_decl  */
  YYSYMBOL_lista_st_fara_decl = 57,        /* lista_st_fara_decl  */
  YYSYMBOL_st_fara_decl = 58,              /* st_fara_decl  */
  YYSYMBOL_func_def = 59,                  /* func_def  */
  YYSYMBOL_60_2 = 60,                      /* $@2  */
  YYSYMBOL_61_3 = 61,                      /* $@3  */
  YYSYMBOL_func_body = 62,                 /* func_body  */
  YYSYMBOL_parchment_opt = 63,             /* parchment_opt  */
  YYSYMBOL_local_decl_list_opt = 64,       /* local_decl_list_opt  */
  YYSYMBOL_local_decl_list = 65,           /* local_decl_list  */
  YYSYMBOL_local_decl = 66,                /* local_decl  */
  YYSYMBOL_class_def = 67,                 /* class_def  */
  YYSYMBOL_68_4 = 68,                      /* $@4  */
  YYSYMBOL_class_members_opt = 69,         /* class_members_opt  */
  YYSYMBOL_class_member = 70,              /* class_member  */
  YYSYMBOL_71_5 = 71,                      /* $@5  */
  YYSYMBOL_72_6 = 72,                      /* $@6  */
  YYSYMBOL_if_st = 73,                     /* if_st  */
  YYSYMBOL_while_st = 74,                  /* while_st  */
  YYSYMBOL_return_st = 75,                 /* return_st  */
  YYSYMBOL_print_st = 76,                  /* print_st  */
  YYSYMBOL_assign_st = 77,                 /* assign_st  */
  YYSYMBOL_lvalue = 78,                    /* lvalue  */
  YYSYMBOL_call_expr = 79,                 /* call_expr  */
  YYSYMBOL_call_st = 80,                   /* call_st  */
  YYSYMBOL_new_obj = 81,                   /* new_obj  */
  YYSYMBOL_expr_bool = 82,                 /* expr_bool  */
  YYSYMBOL_expr = 83,                      /* expr  */
  YYSYMBOL_literal = 84,                   /* literal  */
  YYSYMBOL_type = 85,                      /* type  */
  YYSYMBOL_params_opt = 86,                /* params_opt  */
  YYSYMBOL_params = 87,                    /* params  */
  YYSYMBOL_param = 88,                     /* param  */
  YYSYMBOL_args_opt = 89,                  /* args_opt  */
  YYSYMBOL_args = 90,                      /* args  */
  YYSYMBOL_ret_type = 91                   /* ret_type  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   183

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  180

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


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
       2,     2,     2,     2,     2,     2,     2,    39,     2,     2,
      46,    47,    37,    35,    48,    36,     2,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    42,    43,
      31,     2,    33,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,    45,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    32,    34,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    71,    71,    75,    76,    79,    80,    81,    84,    95,
     117,   116,   134,   137,   144,   149,   150,   151,   152,   153,
     154,   158,   168,   157,   184,   188,   188,   191,   192,   195,
     196,   199,   209,   232,   231,   243,   244,   247,   254,   272,
     253,   291,   298,   306,   315,   329,   339,   357,   369,   408,
     444,   509,   512,   527,   529,   540,   551,   559,   567,   574,
     581,   592,   603,   612,   616,   626,   630,   666,   670,   675,
     685,   696,   706,   716,   726,   739,   740,   741,   742,   743,
     747,   748,   749,   750,   751,   762,   763,   766,   767,   770,
     783,   784,   787,   792,   799
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
  "\"end of file\"", "error", "\"invalid token\"", "DUEL_KW", "HOUSE_KW",
  "FIELD_KW", "CHARM_KW", "SPELL_KW", "PARCHMENT_KW", "SUMMON_KW", "IF_KW",
  "WHILE_KW", "ELSE_KW", "RETURN_KW", "PRINT_KW", "TYPE_INT", "TYPE_FLOAT",
  "TYPE_STRING", "TYPE_BOOL", "ID", "INT_LITERAL", "FLOAT_LITERAL",
  "STRING_LITERAL", "TRUE_LITERAL", "FALSE_LITERAL", "ASSIGN_OP",
  "ACCESS_OP", "OR", "AND", "EQUAL", "NOT_EQUAL", "'<'", "LESS_EQUAL",
  "'>'", "GREATER_EQUAL", "'+'", "'-'", "'*'", "'/'", "'%'", "NOT",
  "UMINUS", "':'", "';'", "'{'", "'}'", "'('", "')'", "','", "$accept",
  "program", "def_globale", "def_globala", "global_decl", "duel", "$@1",
  "bloc_fara_decl", "lista_st_fara_decl", "st_fara_decl", "func_def",
  "$@2", "$@3", "func_body", "parchment_opt", "local_decl_list_opt",
  "local_decl_list", "local_decl", "class_def", "$@4", "class_members_opt",
  "class_member", "$@5", "$@6", "if_st", "while_st", "return_st",
  "print_st", "assign_st", "lvalue", "call_expr", "call_st", "new_obj",
  "expr_bool", "expr", "literal", "type", "params_opt", "params", "param",
  "args_opt", "args", "ret_type", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-111)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -111,    27,    91,  -111,  -111,    30,    35,    33,  -111,  -111,
    -111,  -111,  -111,    43,  -111,  -111,   133,  -111,  -111,    45,
      44,  -111,  -111,  -111,  -111,  -111,    59,    -3,  -111,    77,
      57,  -111,    46,    53,     0,    58,   -20,  -111,  -111,  -111,
    -111,  -111,  -111,  -111,    84,    75,  -111,    -2,    78,    74,
      87,  -111,   103,    -1,  -111,  -111,  -111,  -111,  -111,    57,
       0,  -111,  -111,    76,  -111,     0,     0,     0,    73,    95,
       0,   117,     0,     0,  -111,   119,   125,  -111,  -111,   133,
     116,    77,    99,   140,  -111,   -15,    57,    57,    57,    57,
      57,  -111,   -10,     3,  -111,     0,     0,  -111,    57,    57,
      57,    57,    57,    57,    20,   114,    34,   115,   113,    80,
     121,  -111,  -111,   133,  -111,  -111,     0,   114,  -111,    14,
      14,  -111,  -111,  -111,    43,    43,   136,  -111,   118,   118,
     118,   118,   118,   118,   122,     0,  -111,     0,  -111,   133,
     120,  -111,   123,   124,   156,  -111,  -111,   126,    34,   127,
      77,   161,  -111,  -111,    43,  -111,  -111,   128,   130,  -111,
    -111,   116,   153,    72,  -111,   134,   132,   153,  -111,  -111,
     123,   133,  -111,  -111,  -111,    63,    57,  -111,   104,  -111
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     1,    10,     0,     0,     0,     3,     7,
       2,     6,     5,     0,    33,    21,     0,    14,    11,     0,
       0,    80,    81,    82,    83,    84,     0,     0,    36,    86,
       0,     8,     0,     0,     0,     0,    47,    12,    13,    18,
      19,    20,    15,    16,     0,     0,    17,     0,     0,     0,
      85,    87,     0,    64,    75,    76,    77,    78,    79,     0,
       0,    65,    67,     0,    63,     0,     0,     0,     0,    53,
       0,     0,    91,     0,    51,     0,     0,    34,    35,     0,
       0,     0,     0,     0,    69,     0,     0,     0,     0,     0,
       0,     9,     0,     0,    62,     0,     0,    44,     0,     0,
       0,     0,     0,     0,     0,    48,    92,     0,    90,     0,
       0,    38,    89,     0,    22,    88,    91,    66,    68,    73,
      74,    70,    71,    72,     0,     0,    59,    58,    56,    57,
      60,    54,    61,    55,     0,    91,    49,     0,    46,     0,
       0,    94,     0,     0,    41,    43,    45,     0,    93,     0,
      86,    26,    23,    52,     0,    50,    37,     0,     0,    14,
      42,     0,    28,     0,    39,     0,     0,    27,    30,    24,
       0,     0,    25,    29,    40,     0,     0,    31,     0,    32
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -111,  -111,  -111,  -111,  -111,  -111,  -111,  -110,    19,  -111,
    -111,  -111,  -111,     9,  -111,  -111,  -111,    13,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,
     -26,  -111,  -111,   -32,   -30,  -111,   -74,    31,  -111,   101,
     -61,  -111,    22
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     8,     9,    10,    13,    18,    27,    38,
      11,    20,   142,   152,   159,   166,   167,   168,    12,    19,
      47,    78,   140,   170,    39,    40,    41,    42,    43,    44,
      61,    46,    62,   106,    69,    64,    26,    49,    50,    51,
     107,   108,   114
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      63,    45,    68,    75,    76,   112,    71,    32,    33,    52,
      34,    35,    95,    96,   144,   145,    36,    95,    96,    53,
      54,    55,    56,    57,    58,    83,    72,     3,    85,    84,
      95,    96,   118,    92,    93,    94,    59,   124,   104,   141,
      67,   109,    37,    77,   160,    72,    60,    95,    96,    14,
     125,    88,    89,    90,    15,   143,   119,   120,   121,   122,
     123,    95,    96,   126,   127,   149,    52,   134,   128,   129,
     130,   131,   132,   133,   147,    16,    53,    54,    55,    56,
      57,    58,    32,    33,    30,    34,    35,    17,   176,    28,
      29,    36,    65,    59,     4,     5,    48,   175,     6,    66,
      95,    96,    31,    60,    70,   148,   177,    95,    96,    73,
       7,    86,    87,    88,    89,    90,    97,   169,    74,    91,
      79,    80,    82,   138,    98,    99,   100,   101,   102,   103,
      86,    87,    88,    89,    90,    81,   105,    45,   110,    86,
      87,    88,    89,    90,   111,   116,   178,   179,    21,    22,
      23,    24,    25,    86,    87,    88,    89,    90,   113,   117,
     135,   137,   136,   139,    96,   146,   150,   151,   154,   158,
     156,   153,   165,   155,   162,   161,   171,   172,   163,   174,
     173,   157,   115,   164
};

static const yytype_uint8 yycheck[] =
{
      30,    27,    34,     5,     6,    79,    26,    10,    11,     9,
      13,    14,    27,    28,   124,   125,    19,    27,    28,    19,
      20,    21,    22,    23,    24,    26,    46,     0,    60,    59,
      27,    28,    47,    65,    66,    67,    36,    47,    70,   113,
      40,    73,    45,    45,   154,    46,    46,    27,    28,    19,
      47,    37,    38,    39,    19,   116,    86,    87,    88,    89,
      90,    27,    28,    95,    96,   139,     9,    47,    98,    99,
     100,   101,   102,   103,   135,    42,    19,    20,    21,    22,
      23,    24,    10,    11,    25,    13,    14,    44,    25,    44,
      46,    19,    46,    36,     3,     4,    19,   171,     7,    46,
      27,    28,    43,    46,    46,   137,    43,    27,    28,    25,
      19,    35,    36,    37,    38,    39,    43,    45,    43,    43,
      42,    47,    19,    43,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    48,    19,   163,    19,    35,
      36,    37,    38,    39,    19,    46,   176,    43,    15,    16,
      17,    18,    19,    35,    36,    37,    38,    39,    42,    19,
      46,    48,    47,    42,    28,    43,    46,    44,    12,     8,
      43,    47,    19,    47,    44,    47,    42,    45,   159,   170,
     167,   150,    81,   161
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    50,    51,     0,     3,     4,     7,    19,    52,    53,
      54,    59,    67,    55,    19,    19,    42,    44,    56,    68,
      60,    15,    16,    17,    18,    19,    85,    57,    44,    46,
      25,    43,    10,    11,    13,    14,    19,    45,    58,    73,
      74,    75,    76,    77,    78,    79,    80,    69,    19,    86,
      87,    88,     9,    19,    20,    21,    22,    23,    24,    36,
      46,    79,    81,    83,    84,    46,    46,    40,    82,    83,
      46,    26,    46,    25,    43,     5,     6,    45,    70,    42,
      47,    48,    19,    26,    83,    82,    35,    36,    37,    38,
      39,    43,    82,    82,    82,    27,    28,    43,    29,    30,
      31,    32,    33,    34,    82,    19,    82,    89,    90,    82,
      19,    19,    85,    42,    91,    88,    46,    19,    47,    83,
      83,    83,    83,    83,    47,    47,    82,    82,    83,    83,
      83,    83,    83,    83,    47,    46,    47,    48,    43,    42,
      71,    85,    61,    89,    56,    56,    43,    89,    82,    85,
      46,    44,    62,    47,    12,    47,    43,    86,     8,    63,
      56,    47,    44,    57,    91,    19,    64,    65,    66,    45,
      72,    42,    45,    66,    62,    85,    25,    43,    83,    43
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    52,    52,    53,    53,
      55,    54,    56,    57,    57,    58,    58,    58,    58,    58,
      58,    60,    61,    59,    62,    63,    63,    64,    64,    65,
      65,    66,    66,    68,    67,    69,    69,    70,    71,    72,
      70,    73,    73,    74,    75,    76,    77,    78,    78,    79,
      79,    80,    81,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    84,    84,    84,    84,    84,
      85,    85,    85,    85,    85,    86,    86,    87,    87,    88,
      89,    89,    90,    90,    91
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     1,     1,     1,     4,     6,
       0,     3,     3,     2,     0,     1,     1,     1,     1,     1,
       1,     0,     0,     9,     4,     4,     0,     1,     0,     2,
       1,     4,     6,     0,     6,     2,     0,     5,     0,     0,
       9,     5,     7,     5,     3,     5,     4,     1,     3,     4,
       6,     2,     5,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     1,     1,     1,     3,     1,     3,     2,
       3,     3,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     3,     3,
       1,     0,     1,     3,     2
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
  case 8: /* global_decl: ID ':' type ';'  */
#line 85 "spell.y"
            {   SymbolInfo* s = new SymbolInfo(*(yyvsp[-3].str_val), *(yyvsp[-1].str_val), KIND_VAR); /*creeaza o variabila cu numele dolar 1 si tipul.. 3*/
             
               if(!tableManager.currentScope->addSymbol(s)){ /*incercam sa o adaugam in tabel */
                    yyerror(("Error: Variable " + *(yyvsp[-3].str_val) + " is already defined.").c_str()); 
                }
                 else if( tableManager.classExists(*(yyvsp[-1].str_val)) ) 
                    tableManager.ensureObjectFields(s);
                
              delete (yyvsp[-3].str_val); delete (yyvsp[-1].str_val);
            }
#line 1303 "spell.tab.c"
    break;

  case 9: /* global_decl: ID ':' type ASSIGN_OP expr ';'  */
#line 96 "spell.y"
            {      
                if(*(yyvsp[-3].str_val) != (yyvsp[-1].node_val)->exprType && (yyvsp[-1].node_val)->exprType != "error")
                      yyerror(("Type mismatch in initialization of " + *(yyvsp[-5].str_val) +". Declared: " + *(yyvsp[-3].str_val) + " but got: " +  (yyvsp[-1].node_val)->exprType).c_str());

                  SymbolInfo* s = new SymbolInfo(*(yyvsp[-5].str_val), *(yyvsp[-3].str_val), KIND_VAR);
                  if((yyvsp[-1].node_val)->tip == NK_LITERAL) 
                       s->value= (yyvsp[-1].node_val)->lit.to_str();
                  else s->value = "<uninitialized>";

                 if(!tableManager.currentScope->addSymbol(s)){
                   yyerror(("Error: Variable " + *(yyvsp[-5].str_val) + " is already defined.").c_str());
                 } 
                  else if(tableManager.classExists(*(yyvsp[-3].str_val))) 
                          tableManager.ensureObjectFields(s);
                 
             delete (yyvsp[-5].str_val); delete (yyvsp[-3].str_val); delete (yyvsp[-1].node_val);
            }
#line 1325 "spell.tab.c"
    break;

  case 10: /* $@1: %empty  */
#line 117 "spell.y"
    { 
        tableManager.enterScope("Global_Duel"); 
    }
#line 1333 "spell.tab.c"
    break;

  case 11: /* duel: DUEL_KW $@1 bloc_fara_decl  */
#line 121 "spell.y"
    { 
        for(ASTNode* n : *(yyvsp[0].node_list) ) 
           if(n)
            n->eval(tableManager);

        for(ASTNode* n : *(yyvsp[0].node_list) ) delete n;
        delete (yyvsp[0].node_list);

        tableManager.exitScope();
    }
#line 1348 "spell.tab.c"
    break;

  case 12: /* bloc_fara_decl: '{' lista_st_fara_decl '}'  */
#line 134 "spell.y"
                                            { (yyval.node_list) = (yyvsp[-1].node_list) ;}
#line 1354 "spell.tab.c"
    break;

  case 13: /* lista_st_fara_decl: lista_st_fara_decl st_fara_decl  */
#line 138 "spell.y"
                    {
                        (yyval.node_list)=(yyvsp[-1].node_list);
                        if( (yyvsp[0].node_val) != nullptr)
                           (yyval.node_list)->push_back((yyvsp[0].node_val));
                    }
#line 1364 "spell.tab.c"
    break;

  case 14: /* lista_st_fara_decl: %empty  */
#line 144 "spell.y"
                   {
                    (yyval.node_list)= new vector<ASTNode*>();
                   }
#line 1372 "spell.tab.c"
    break;

  case 21: /* $@2: %empty  */
#line 158 "spell.y"
         {
            SymbolInfo* f = new SymbolInfo(*(yyvsp[0].str_val), "error", KIND_FUNC);
            f->returnType = "error";
            if(!tableManager.currentScope->addSymbol(f)){
                yyerror(("Error: Function " + *(yyvsp[0].str_val) + " is already defined.").c_str());
            }
            tableManager.enterScope("Func_" + *(yyvsp[0].str_val));
            currentFunction = f;
         }
#line 1386 "spell.tab.c"
    break;

  case 22: /* $@3: %empty  */
#line 168 "spell.y"
         {
            if(currentFunction != nullptr && (yyvsp[0].str_val) != nullptr){
                currentFunction->returnType = *(yyvsp[0].str_val);
                currentFunction->type = *(yyvsp[0].str_val);
            }
            delete (yyvsp[0].str_val);
         }
#line 1398 "spell.tab.c"
    break;

  case 23: /* func_def: SPELL_KW ID $@2 '(' params_opt ')' ret_type $@3 func_body  */
#line 176 "spell.y"
         { /*cand terminam functia, inchidem */
            currentFunction->body= (yyvsp[0].node_list);
            currentFunction->defScope= tableManager.currentScope;
            tableManager.exitScope();
            currentFunction= nullptr;
         }
#line 1409 "spell.tab.c"
    break;

  case 24: /* func_body: '{' parchment_opt lista_st_fara_decl '}'  */
#line 184 "spell.y"
                                                     { (yyval.node_list) = (yyvsp[-1].node_list); }
#line 1415 "spell.tab.c"
    break;

  case 31: /* local_decl: ID ':' type ';'  */
#line 200 "spell.y"
            {
               SymbolInfo* s = new SymbolInfo(*(yyvsp[-3].str_val), *(yyvsp[-1].str_val), KIND_VAR);
              if(!tableManager.currentScope->addSymbol(s)){
                  yyerror(("Error: Variable " + *(yyvsp[-3].str_val) + " is already defined.").c_str());
               } else if(tableManager.classExists(*(yyvsp[-1].str_val))) {
                  tableManager.ensureObjectFields(s);
               }
            delete (yyvsp[-3].str_val); delete (yyvsp[-1].str_val);
           }
#line 1429 "spell.tab.c"
    break;

  case 32: /* local_decl: ID ':' type ASSIGN_OP expr ';'  */
#line 210 "spell.y"
            {
              if(*(yyvsp[-3].str_val) !=  (yyvsp[-1].node_val)->exprType &&  (yyvsp[-1].node_val)->exprType != "error")
                        yyerror(("Type mismatch in initialization of " + *(yyvsp[-5].str_val) +". Declared: " + *(yyvsp[-3].str_val) + " but got: " +  (yyvsp[-1].node_val)->exprType).c_str());

              SymbolInfo* s = new SymbolInfo(*(yyvsp[-5].str_val), *(yyvsp[-3].str_val), KIND_VAR);

               if( (yyvsp[-1].node_val) && (yyvsp[-1].node_val)->tip == NK_LITERAL ) s->value = (yyvsp[-1].node_val)->lit.to_str();
                else s->value = "<uninitialized>";

              if(!tableManager.currentScope->addSymbol(s))
                  yyerror(("Error: Variable " + *(yyvsp[-5].str_val) + " is already defined.").c_str());
              else if(tableManager.classExists(*(yyvsp[-3].str_val))) {
                  tableManager.ensureObjectFields(s);
              }
                
             delete (yyvsp[-5].str_val); delete (yyvsp[-3].str_val); delete (yyvsp[-1].node_val);
            }
#line 1451 "spell.tab.c"
    break;

  case 33: /* $@4: %empty  */
#line 232 "spell.y"
            {   SymbolInfo* c = new SymbolInfo(*(yyvsp[0].str_val), "class", KIND_CLASS);
                if(!tableManager.currentScope->addSymbol(c)){
                    yyerror(("Error: Class " + *(yyvsp[0].str_val) + " is already defined.").c_str());
                }
                currentClass = *(yyvsp[0].str_val);
                tableManager.enterScope("Class_" + *(yyvsp[0].str_val)); 
            }
#line 1463 "spell.tab.c"
    break;

  case 34: /* class_def: HOUSE_KW ID $@4 '{' class_members_opt '}'  */
#line 240 "spell.y"
            { tableManager.exitScope(); currentClass.clear(); }
#line 1469 "spell.tab.c"
    break;

  case 37: /* class_member: FIELD_KW ID ':' type ';'  */
#line 248 "spell.y"
            {   SymbolInfo* s = new SymbolInfo(*(yyvsp[-3].str_val), *(yyvsp[-1].str_val), KIND_FIELD);
                if(!tableManager.currentScope->addSymbol(s)){
                    yyerror(("Error: Variable " + *(yyvsp[-3].str_val) + " is already defined.").c_str());
                }
            }
#line 1479 "spell.tab.c"
    break;

  case 38: /* $@5: %empty  */
#line 254 "spell.y"
             {
                SymbolInfo* m = new SymbolInfo(*(yyvsp[0].str_val), "error", KIND_FUNC);
                m->returnType = "error";

                if(!tableManager.currentScope->addSymbol(m)){
                    yyerror(("Error: Method " + *(yyvsp[0].str_val) + " is already defined.").c_str());
                }

                tableManager.enterScope("Method_" + *(yyvsp[0].str_val));
                currentFunction = m;
                if(!currentClass.empty()){
                    SymbolInfo* selfSym = new SymbolInfo("this", currentClass, KIND_VAR);
                    if(!tableManager.currentScope->addSymbol(selfSym)){
                        delete selfSym;
                    }
                }
             }
#line 1501 "spell.tab.c"
    break;

  case 39: /* $@6: %empty  */
#line 272 "spell.y"
             {
                if(currentFunction != nullptr && (yyvsp[0].str_val) != nullptr){
                    currentFunction->returnType = *(yyvsp[0].str_val);
                    currentFunction->type = *(yyvsp[0].str_val);
                }
                delete (yyvsp[0].str_val);
             }
#line 1513 "spell.tab.c"
    break;

  case 40: /* class_member: CHARM_KW ID $@5 '(' params_opt ')' ret_type $@6 func_body  */
#line 280 "spell.y"
             {
                currentFunction->body = (yyvsp[0].node_list);
                currentFunction->defScope = tableManager.currentScope;
                tableManager.exitScope();
                currentFunction = nullptr;
             }
#line 1524 "spell.tab.c"
    break;

  case 41: /* if_st: IF_KW '(' expr_bool ')' bloc_fara_decl  */
#line 292 "spell.y"
        {
            if((yyvsp[-2].node_val)->exprType != "bool" && (yyvsp[-2].node_val)->exprType != "error")
                yyerror("Condition must be bool");
            
            (yyval.node_val) = nullptr;
        }
#line 1535 "spell.tab.c"
    break;

  case 42: /* if_st: IF_KW '(' expr_bool ')' bloc_fara_decl ELSE_KW bloc_fara_decl  */
#line 299 "spell.y"
        {
            if((yyvsp[-4].node_val)->exprType != "bool" && (yyvsp[-4].node_val)->exprType != "error")
                 yyerror("Condition must be bool");  
            (yyval.node_val) = nullptr;
        }
#line 1545 "spell.tab.c"
    break;

  case 43: /* while_st: WHILE_KW '(' expr_bool ')' bloc_fara_decl  */
#line 307 "spell.y"
         {
            if((yyvsp[-2].node_val)->exprType != "bool" && (yyvsp[-2].node_val)->exprType != "error")
                yyerror("Condition must be bool");
            
            (yyval.node_val) = nullptr;
         }
#line 1556 "spell.tab.c"
    break;

  case 44: /* return_st: RETURN_KW expr_bool ';'  */
#line 316 "spell.y"
        {
            if ( currentFunction != nullptr ) {
                if( (yyvsp[-1].node_val)->exprType != currentFunction->returnType) {
                    yyerror(("Return type mismatch. Expected " + currentFunction->returnType + " but got " + (yyvsp[-1].node_val)->exprType).c_str());
                }
            } 
            else {
                yyerror("Return statement outside of function/method");
            }
            (yyval.node_val) = nullptr;
        }
#line 1572 "spell.tab.c"
    break;

  case 45: /* print_st: PRINT_KW '(' expr_bool ')' ';'  */
#line 330 "spell.y"
        {
            if ((yyvsp[-2].node_val)->exprType== "void") {
                yyerror("Cannot print void expr.");
            }

            (yyval.node_val) = ASTNode::makePrint((yyvsp[-2].node_val));
        }
#line 1584 "spell.tab.c"
    break;

  case 46: /* assign_st: lvalue ASSIGN_OP expr_bool ';'  */
#line 340 "spell.y"
{
    if((yyvsp[-3].node_val)->exprType != "error" && (yyvsp[-1].node_val)->exprType != "error" && (yyvsp[-3].node_val)->exprType != (yyvsp[-1].node_val)->exprType){
        yyerror(("Cannot assign value of type " + (yyvsp[-1].node_val)->exprType + " to variable of type " + (yyvsp[-3].node_val)->exprType).c_str());
    }

    if((yyvsp[-3].node_val)->tip == NK_ID) 
       (yyval.node_val)= ASTNode::makeAssign((yyvsp[-3].node_val)->idName, (yyvsp[-1].node_val));
    else if((yyvsp[-3].node_val)->tip == NK_FIELD) 
            (yyval.node_val)= ASTNode::makeAssignField((yyvsp[-3].node_val)->objName, (yyvsp[-3].node_val)->fieldName, (yyvsp[-1].node_val));
    else {
      (yyval.node_val)= nullptr;
      delete (yyvsp[-1].node_val);
    }
   delete (yyvsp[-3].node_val);
}
#line 1604 "spell.tab.c"
    break;

  case 47: /* lvalue: ID  */
#line 358 "spell.y"
      {
        SymbolInfo* s = tableManager.currentScope->lookup(*(yyvsp[0].str_val));
        if( s == nullptr ) {
            yyerror(("Variable " + *(yyvsp[0].str_val) + " is not defined.").c_str());
           (yyval.node_val) = ASTNode::makeOther("error");
        }
        else 
             (yyval.node_val)=ASTNode::makeId(*(yyvsp[0].str_val), s->type);
        
        delete (yyvsp[0].str_val);
      }
#line 1620 "spell.tab.c"
    break;

  case 48: /* lvalue: ID ACCESS_OP ID  */
#line 370 "spell.y"
      {
        SymbolInfo* obj = tableManager.currentScope->lookup(*(yyvsp[-2].str_val));

        if(obj == nullptr){
            yyerror(("Object " + *(yyvsp[-2].str_val) + " not defined.").c_str());
             (yyval.node_val) = ASTNode::makeOther("error");
        }
        else 
        if(!tableManager.classExists(obj->type)) {
            yyerror(("Type " + obj->type + " is not a class, cannot access members.").c_str());
          (yyval.node_val)=ASTNode::makeOther("error");
        }
        else {
            SymTable* classScope = tableManager.findClassScope(obj->type);

            if(classScope == nullptr) {
                yyerror(("Class scope for " + obj->type + " not found.").c_str());
                 (yyval.node_val)=ASTNode::makeOther("error");
            }
            else {
                SymbolInfo* field = classScope->lookup(*(yyvsp[0].str_val));
                if(field == nullptr) {
                    yyerror(("Field " + *(yyvsp[0].str_val) + " not found in class " + obj->type).c_str());
                     (yyval.node_val)=ASTNode::makeOther("error");
                }
                else if(field->kind != KIND_FIELD) {
                    yyerror(("Member " + *(yyvsp[0].str_val) + " is not a field in class " + obj->type).c_str());
                     (yyval.node_val)=ASTNode::makeOther("error");
                }
                else {
                   (yyval.node_val) = ASTNode::makeFieldAccess(*(yyvsp[-2].str_val), *(yyvsp[0].str_val), field->type);
                }
            }
        } 
        delete (yyvsp[-2].str_val); delete (yyvsp[0].str_val);
      }
#line 1661 "spell.tab.c"
    break;

  case 49: /* call_expr: ID '(' args_opt ')'  */
#line 409 "spell.y"
        {
            SymbolInfo* f = tableManager.currentScope->lookup(*(yyvsp[-3].str_val));

            if( f == nullptr || f->kind != KIND_FUNC ) {
                yyerror(("Function " + *(yyvsp[-3].str_val) + " is not defined.").c_str());
                for(ASTNode* n: *(yyvsp[-1].node_list)) delete n;
                delete (yyvsp[-1].node_list);
                (yyval.node_val) = ASTNode::makeOther("error");
            }
            else {
                if(f->paramTypes.size() != (yyvsp[-1].node_list)->size()) {
                    yyerror(("Function " + *(yyvsp[-3].str_val) + " expects " + to_string(f->paramTypes.size()) + " arguments, but got " + to_string((yyvsp[-1].node_list)->size())).c_str());
                    for(ASTNode* n: *(yyvsp[-1].node_list)) delete n;
                    delete (yyvsp[-1].node_list);
                    (yyval.node_val) = ASTNode::makeOther("error");
                }
                else {
                    bool ok =true;
                    for ( size_t i =0; i < f->paramTypes.size(); i++) {
                        if(f->paramTypes[i] != (*(yyvsp[-1].node_list))[i]->exprType ) {
                          yyerror(( "Argument " + to_string(i+1) + " of function " + *(yyvsp[-3].str_val) +" type mismatch. Expected " + f->paramTypes[i] +", got " + (*(yyvsp[-1].node_list))[i]->exprType).c_str());

                            ok = false;
                        }
                    }
                  if (ok) (yyval.node_val) =ASTNode::makeCall(*(yyvsp[-3].str_val), (yyvsp[-1].node_list), f->returnType);
                    else {
                      for(ASTNode* n: *(yyvsp[-1].node_list)) delete n;
                      delete (yyvsp[-1].node_list);
                      (yyval.node_val) = ASTNode::makeOther("error");
                    }
                }
            }
              delete (yyvsp[-3].str_val);
        }
#line 1701 "spell.tab.c"
    break;

  case 50: /* call_expr: ID ACCESS_OP ID '(' args_opt ')'  */
#line 445 "spell.y"
        {
            SymbolInfo* obj = tableManager.currentScope->lookup(*(yyvsp[-5].str_val));

            if(obj == nullptr) {
                yyerror(("Object " + *(yyvsp[-5].str_val) + " is not defined.").c_str());
                for(ASTNode* n : *(yyvsp[-1].node_list)) delete n;
                delete (yyvsp[-1].node_list);
                (yyval.node_val) = ASTNode::makeOther("error");
            }
            else if( !tableManager.classExists(obj->type) ) {
               yyerror(("Type " + obj->type + " is not a class, cannot access members.").c_str());
             for(ASTNode* n : *(yyvsp[-1].node_list)) delete n;
             delete (yyvsp[-1].node_list);
             (yyval.node_val) = ASTNode::makeOther("error");
           }
            else {
                SymTable* classScope = tableManager.findClassScope(obj->type);

                if(classScope == nullptr) {
                    yyerror(("Class scope for object " + *(yyvsp[-5].str_val) + " not found.").c_str());
                    for(ASTNode* n : *(yyvsp[-1].node_list)) delete n;
                    delete (yyvsp[-1].node_list);
                    (yyval.node_val) = ASTNode::makeOther("error");
                }
                else {
                    SymbolInfo* method = classScope->lookup(*(yyvsp[-3].str_val));

                    if(method == nullptr || method->kind != KIND_FUNC) {
                        yyerror(("Method " + *(yyvsp[-3].str_val) + " is not defined in class " + obj->type).c_str());
                        for(ASTNode* n : *(yyvsp[-1].node_list)) delete n;
                        delete (yyvsp[-1].node_list);
                        (yyval.node_val) = ASTNode::makeOther("error");
                    }
                    else {
                        
                        if(method->paramTypes.size() != (yyvsp[-1].node_list)->size()) {
                            yyerror(("Method " + *(yyvsp[-3].str_val) + " expects " + to_string(method->paramTypes.size()) + " arguments, but got " + to_string((yyvsp[-1].node_list)->size())).c_str());
                            for(ASTNode* n : *(yyvsp[-1].node_list)) delete n;
                            delete (yyvsp[-1].node_list);
                            (yyval.node_val) = ASTNode::makeOther("error");
                        }
                        else {
                            bool ok = true;
                            for (size_t i = 0; i < method->paramTypes.size(); i++) {
                                if(method->paramTypes[i] != (*(yyvsp[-1].node_list))[i]->exprType ){
                                   yyerror(( "Argument " + to_string(i+1) + " of method " + *(yyvsp[-3].str_val) +" type mismatch. Expected " + method->paramTypes[i] +", got " + (*(yyvsp[-1].node_list))[i]->exprType).c_str());

                                    ok = false;
                                }
                            }
                            if (ok) (yyval.node_val) = ASTNode::makeMethodCall(*(yyvsp[-5].str_val), *(yyvsp[-3].str_val), (yyvsp[-1].node_list), method->returnType);
                            else {
                              for(ASTNode* n : *(yyvsp[-1].node_list)) delete n;
                              delete (yyvsp[-1].node_list);
                              (yyval.node_val) = ASTNode::makeOther("error");
                            }
                        }
                    }
                }
            }
          delete (yyvsp[-5].str_val); delete (yyvsp[-3].str_val);
        }
#line 1768 "spell.tab.c"
    break;

  case 51: /* call_st: call_expr ';'  */
#line 509 "spell.y"
                        { (yyval.node_val) = nullptr; }
#line 1774 "spell.tab.c"
    break;

  case 52: /* new_obj: SUMMON_KW ID '(' args_opt ')'  */
#line 513 "spell.y"
     {
      if(!tableManager.classExists(*(yyvsp[-3].str_val))){
           yyerror(("Class " + *(yyvsp[-3].str_val) + " is not defined.").c_str());
          (yyval.node_val)=ASTNode::makeOther("error");
          for(ASTNode* n : *(yyvsp[-1].node_list)) delete n;
          delete (yyvsp[-1].node_list);
      } else 
        (yyval.node_val) = ASTNode::makeNew(*(yyvsp[-3].str_val), (yyvsp[-1].node_list));

    delete (yyvsp[-3].str_val);
}
#line 1790 "spell.tab.c"
    break;

  case 53: /* expr_bool: expr  */
#line 527 "spell.y"
                 { (yyval.node_val) = (yyvsp[0].node_val); }
#line 1796 "spell.tab.c"
    break;

  case 54: /* expr_bool: expr LESS_EQUAL expr  */
#line 530 "spell.y"
        { 
            if((yyvsp[-2].node_val)->exprType != (yyvsp[0].node_val)->exprType && (yyvsp[-2].node_val)->exprType != "error" && (yyvsp[0].node_val)->exprType != "error")
                yyerror(("<= requires same types, but got " + (yyvsp[-2].node_val)->exprType + " and " + (yyvsp[0].node_val)->exprType).c_str());

            if(((yyvsp[-2].node_val)->exprType != "int" && (yyvsp[-2].node_val)->exprType != "float") && (yyvsp[-2].node_val)->exprType != "error")
                yyerror("<= requires numeric operands");

            (yyval.node_val) = ASTNode::makeOp("<=", (yyvsp[-2].node_val), (yyvsp[0].node_val), "bool"); 
        }
#line 1810 "spell.tab.c"
    break;

  case 55: /* expr_bool: expr GREATER_EQUAL expr  */
#line 541 "spell.y"
       {  
            if((yyvsp[-2].node_val)->exprType != (yyvsp[0].node_val)->exprType && (yyvsp[-2].node_val)->exprType != "error" && (yyvsp[0].node_val)->exprType != "error")
                yyerror((">= requires same types, but got " + (yyvsp[-2].node_val)->exprType + " and " + (yyvsp[0].node_val)->exprType).c_str());

            if(((yyvsp[-2].node_val)->exprType != "int" && (yyvsp[-2].node_val)->exprType != "float") && (yyvsp[-2].node_val)->exprType != "error")
                yyerror(">= requires numeric operands");

            (yyval.node_val) =ASTNode::makeOp(">=", (yyvsp[-2].node_val), (yyvsp[0].node_val), "bool"); 
       }
#line 1824 "spell.tab.c"
    break;

  case 56: /* expr_bool: expr EQUAL expr  */
#line 552 "spell.y"
       {
            if((yyvsp[-2].node_val)->exprType != (yyvsp[0].node_val)->exprType && (yyvsp[-2].node_val)->exprType != "error" && (yyvsp[0].node_val)->exprType != "error")
                yyerror(("== requires same types, but got " + (yyvsp[-2].node_val)->exprType + " and " + (yyvsp[0].node_val)->exprType).c_str());

            (yyval.node_val) =ASTNode::makeOp("==", (yyvsp[-2].node_val), (yyvsp[0].node_val), "bool"); 
       }
#line 1835 "spell.tab.c"
    break;

  case 57: /* expr_bool: expr NOT_EQUAL expr  */
#line 560 "spell.y"
       {
            if((yyvsp[-2].node_val)->exprType != (yyvsp[0].node_val)->exprType && (yyvsp[-2].node_val)->exprType != "error" && (yyvsp[0].node_val)->exprType != "error")
                yyerror(("!= requires same types, but got " + (yyvsp[-2].node_val)->exprType + " and " + (yyvsp[0].node_val)->exprType).c_str());

            (yyval.node_val) =ASTNode::makeOp("!=", (yyvsp[-2].node_val), (yyvsp[0].node_val), "bool"); 
       }
#line 1846 "spell.tab.c"
    break;

  case 58: /* expr_bool: expr_bool AND expr_bool  */
#line 568 "spell.y"
       { 
            if ((yyvsp[-2].node_val)->exprType != "bool" || (yyvsp[0].node_val)->exprType != "bool")
                yyerror("AND requires boolean operands");
            (yyval.node_val) =ASTNode::makeOp("AND", (yyvsp[-2].node_val), (yyvsp[0].node_val), "bool"); 
       }
#line 1856 "spell.tab.c"
    break;

  case 59: /* expr_bool: expr_bool OR expr_bool  */
#line 575 "spell.y"
       { 
            if ((yyvsp[-2].node_val)->exprType != "bool" || (yyvsp[0].node_val)->exprType != "bool")
                yyerror("OR requires boolean operands");
            (yyval.node_val)=ASTNode::makeOp("OR", (yyvsp[-2].node_val), (yyvsp[0].node_val), "bool"); 
       }
#line 1866 "spell.tab.c"
    break;

  case 60: /* expr_bool: expr '<' expr  */
#line 582 "spell.y"
       {  
            if((yyvsp[-2].node_val)->exprType != (yyvsp[0].node_val)->exprType && (yyvsp[-2].node_val)->exprType != "error" && (yyvsp[0].node_val)->exprType != "error")
                yyerror(("< requires same types, but got " + (yyvsp[-2].node_val)->exprType + " and " + (yyvsp[0].node_val)->exprType).c_str());

            if(((yyvsp[-2].node_val)->exprType != "int" && (yyvsp[-2].node_val)->exprType != "float") && (yyvsp[-2].node_val)->exprType != "error")
                yyerror("< requires numeric operands");

            (yyval.node_val) = ASTNode::makeOp("<", (yyvsp[-2].node_val), (yyvsp[0].node_val), "bool"); 
       }
#line 1880 "spell.tab.c"
    break;

  case 61: /* expr_bool: expr '>' expr  */
#line 593 "spell.y"
       { 
            if((yyvsp[-2].node_val)->exprType != (yyvsp[0].node_val)->exprType && (yyvsp[-2].node_val)->exprType != "error" && (yyvsp[0].node_val)->exprType != "error")
                yyerror(("> requires same types, but got " + (yyvsp[-2].node_val)->exprType + " and " + (yyvsp[0].node_val)->exprType).c_str());

            if(((yyvsp[-2].node_val)->exprType != "int" && (yyvsp[-2].node_val)->exprType!= "float") && (yyvsp[-2].node_val)->exprType != "error")
                yyerror("> requires numeric operands");

            (yyval.node_val)=ASTNode::makeOp(">", (yyvsp[-2].node_val), (yyvsp[0].node_val), "bool"); 
       }
#line 1894 "spell.tab.c"
    break;

  case 62: /* expr_bool: NOT expr_bool  */
#line 604 "spell.y"
       {
            if((yyvsp[0].node_val)->exprType != "bool")
                yyerror("NOT requires boolean operand");
            (yyval.node_val)=ASTNode::makeOp("NOT", (yyvsp[0].node_val), nullptr, "bool"); 
       }
#line 1904 "spell.tab.c"
    break;

  case 63: /* expr: literal  */
#line 613 "spell.y"
    {
        (yyval.node_val) = (yyvsp[0].node_val);
    }
#line 1912 "spell.tab.c"
    break;

  case 64: /* expr: ID  */
#line 617 "spell.y"
    {
        SymbolInfo* s = tableManager.currentScope->lookup(*(yyvsp[0].str_val));
        if (s == nullptr) {
            yyerror(("Variable " + *(yyvsp[0].str_val) + " is not declared.").c_str());
             (yyval.node_val) =ASTNode::makeOther("error");
        } else 
             (yyval.node_val) =ASTNode::makeId(*(yyvsp[0].str_val), s->type);
     delete (yyvsp[0].str_val); 
    }
#line 1926 "spell.tab.c"
    break;

  case 65: /* expr: call_expr  */
#line 627 "spell.y"
    {
        (yyval.node_val) = (yyvsp[0].node_val);
    }
#line 1934 "spell.tab.c"
    break;

  case 66: /* expr: ID ACCESS_OP ID  */
#line 631 "spell.y"
    {
        SymbolInfo* obj = tableManager.currentScope->lookup(*(yyvsp[-2].str_val));
        if(obj == nullptr){
            yyerror(("Object " + *(yyvsp[-2].str_val) + " not defined.").c_str());
            (yyval.node_val)=ASTNode::makeOther("error");

        }
        else if(!tableManager.classExists(obj->type)){
            yyerror(("Type " + obj->type + " is not a class, cannot access members.").c_str());
        (yyval.node_val) = ASTNode::makeOther("error");
        }
        else {
            SymTable* classScope = tableManager.findClassScope(obj->type);

            if(classScope == nullptr) {
                yyerror(("Class definition for object" + *(yyvsp[-2].str_val) + " not found.").c_str());
               (yyval.node_val) = ASTNode::makeOther("error");
            }
            else {
                SymbolInfo* field = classScope->lookup(*(yyvsp[0].str_val));
                if(field == nullptr) {
                    yyerror(("Field " + *(yyvsp[0].str_val) + " not found in class " + obj->type).c_str());
                    (yyval.node_val) = ASTNode::makeOther("error");
                }
                else if(field->kind != KIND_FIELD) {
                    yyerror(("Member " + *(yyvsp[0].str_val) + " is not a field in class " + obj->type).c_str());
                    (yyval.node_val)=ASTNode::makeOther("error");
                }
                else {
                   (yyval.node_val)=ASTNode::makeFieldAccess(*(yyvsp[-2].str_val), *(yyvsp[0].str_val), field->type);
                }
            }
        } 
     delete (yyvsp[-2].str_val); delete (yyvsp[0].str_val);
      }
#line 1974 "spell.tab.c"
    break;

  case 67: /* expr: new_obj  */
#line 667 "spell.y"
    {
        (yyval.node_val) = (yyvsp[0].node_val);
    }
#line 1982 "spell.tab.c"
    break;

  case 68: /* expr: '(' expr_bool ')'  */
#line 671 "spell.y"
    {
        (yyval.node_val) = (yyvsp[-1].node_val);
    }
#line 1990 "spell.tab.c"
    break;

  case 69: /* expr: '-' expr  */
#line 676 "spell.y"
   {
     if((yyvsp[0].node_val)->exprType != "int" && (yyvsp[0].node_val)->exprType != "float"){
         yyerror("Unary minus requires numeric type");
         (yyval.node_val) = ASTNode::makeOther("error");
        delete (yyvsp[0].node_val);
      } else 
          (yyval.node_val) = ASTNode::makeOp("UMINUS", (yyvsp[0].node_val), nullptr, (yyvsp[0].node_val)->exprType);
   }
#line 2003 "spell.tab.c"
    break;

  case 70: /* expr: expr '*' expr  */
#line 686 "spell.y"
   {
       if( (yyvsp[-2].node_val)->exprType != (yyvsp[0].node_val)->exprType ){
           yyerror(("Type mismatch: cannot multiply " + (yyvsp[-2].node_val)->exprType + " and " + (yyvsp[0].node_val)->exprType).c_str());
           (yyval.node_val) = ASTNode::makeOther("error");
        delete (yyvsp[-2].node_val); delete (yyvsp[0].node_val);
     } else 
        (yyval.node_val) = ASTNode::makeOp("*", (yyvsp[-2].node_val), (yyvsp[0].node_val), (yyvsp[-2].node_val)->exprType);

    }
#line 2017 "spell.tab.c"
    break;

  case 71: /* expr: expr '/' expr  */
#line 697 "spell.y"
   {
      if( (yyvsp[-2].node_val)->exprType != (yyvsp[0].node_val)->exprType ) {
          yyerror("Type mismatch in division");
          (yyval.node_val) =ASTNode::makeOther("error");
        delete (yyvsp[-2].node_val); delete (yyvsp[0].node_val);
      } else 
         (yyval.node_val) =ASTNode::makeOp("/", (yyvsp[-2].node_val), (yyvsp[0].node_val), (yyvsp[-2].node_val)->exprType);
   }
#line 2030 "spell.tab.c"
    break;

  case 72: /* expr: expr '%' expr  */
#line 707 "spell.y"
   {
    if( (yyvsp[-2].node_val)->exprType  != "int" || (yyvsp[0].node_val)->exprType != "int") {
        yyerror("Modulo requires int types");
         (yyval.node_val) =ASTNode::makeOther("error");
        delete (yyvsp[-2].node_val); delete (yyvsp[0].node_val);
    } else 
        (yyval.node_val) =ASTNode::makeOp("%", (yyvsp[-2].node_val), (yyvsp[0].node_val), (yyvsp[-2].node_val)->exprType);
   }
#line 2043 "spell.tab.c"
    break;

  case 73: /* expr: expr '+' expr  */
#line 717 "spell.y"
   {
       if( (yyvsp[-2].node_val)->exprType != (yyvsp[0].node_val)->exprType ){
           yyerror(("Type mismatch: cannot add " + (yyvsp[-2].node_val)->exprType + " and " + (yyvsp[0].node_val)->exprType).c_str());
           (yyval.node_val) =ASTNode::makeOther("error");
        delete (yyvsp[-2].node_val); delete (yyvsp[0].node_val);
      } else 
         (yyval.node_val) = ASTNode::makeOp( "+", (yyvsp[-2].node_val), (yyvsp[0].node_val), (yyvsp[-2].node_val)->exprType);
    }
#line 2056 "spell.tab.c"
    break;

  case 74: /* expr: expr '-' expr  */
#line 727 "spell.y"
  {
      if( (yyvsp[-2].node_val)->exprType != (yyvsp[0].node_val)->exprType ){
           yyerror(("Type mismatch: " + (yyvsp[-2].node_val)->exprType + " and " + (yyvsp[0].node_val)->exprType).c_str());
           (yyval.node_val) =ASTNode::makeOther("error");
        delete (yyvsp[-2].node_val); delete (yyvsp[0].node_val);
      } else 
         (yyval.node_val) = ASTNode::makeOp( "-", (yyvsp[-2].node_val), (yyvsp[0].node_val), (yyvsp[-2].node_val)->exprType);
  }
#line 2069 "spell.tab.c"
    break;

  case 75: /* literal: INT_LITERAL  */
#line 739 "spell.y"
                      { (yyval.node_val) = ASTNode::makeLiteral(Value::makeInt((yyvsp[0].int_val)));}
#line 2075 "spell.tab.c"
    break;

  case 76: /* literal: FLOAT_LITERAL  */
#line 740 "spell.y"
                        { (yyval.node_val) =ASTNode::makeLiteral(Value::makeFloat((yyvsp[0].float_val)));  }
#line 2081 "spell.tab.c"
    break;

  case 77: /* literal: STRING_LITERAL  */
#line 741 "spell.y"
                         { (yyval.node_val)=ASTNode::makeLiteral(Value::makeString(*(yyvsp[0].str_val))); delete (yyvsp[0].str_val); }
#line 2087 "spell.tab.c"
    break;

  case 78: /* literal: TRUE_LITERAL  */
#line 742 "spell.y"
                         { (yyval.node_val) = ASTNode::makeLiteral(Value::makeBool(true)); }
#line 2093 "spell.tab.c"
    break;

  case 79: /* literal: FALSE_LITERAL  */
#line 743 "spell.y"
                         { (yyval.node_val) = ASTNode::makeLiteral(Value::makeBool(false)); }
#line 2099 "spell.tab.c"
    break;

  case 84: /* type: ID  */
#line 752 "spell.y"
      {
        if(!tableManager.classExists(*(yyvsp[0].str_val))){
            yyerror("Type __ is not a defined class");
            (yyval.str_val) =new string("error");
          delete (yyvsp[0].str_val);
        }else
            (yyval.str_val) = (yyvsp[0].str_val); /*tipul e numele claseii */
      }
#line 2112 "spell.tab.c"
    break;

  case 89: /* param: ID ':' type  */
#line 771 "spell.y"
        {   SymbolInfo* s = new SymbolInfo(*(yyvsp[-2].str_val), *(yyvsp[0].str_val), KIND_PARAM);
            if(!tableManager.currentScope->addSymbol(s)){
                yyerror(("Error: Variable " + *(yyvsp[-2].str_val) + " is already defined.").c_str());
                }

            if(currentFunction != nullptr ){
                currentFunction->paramTypes.push_back(*(yyvsp[0].str_val));
                currentFunction->paramNames.push_back(*(yyvsp[-2].str_val));
            }
        }
#line 2127 "spell.tab.c"
    break;

  case 90: /* args_opt: args  */
#line 783 "spell.y"
                { (yyval.node_list) = (yyvsp[0].node_list); }
#line 2133 "spell.tab.c"
    break;

  case 91: /* args_opt: %empty  */
#line 784 "spell.y"
           { (yyval.node_list) = new vector<ASTNode*>(); }
#line 2139 "spell.tab.c"
    break;

  case 92: /* args: expr_bool  */
#line 788 "spell.y"
   {
     (yyval.node_list)=new vector<ASTNode*>();
     (yyval.node_list)->push_back((yyvsp[0].node_val));
  }
#line 2148 "spell.tab.c"
    break;

  case 93: /* args: args ',' expr_bool  */
#line 793 "spell.y"
  {
    (yyval.node_list) =(yyvsp[-2].node_list);
    (yyval.node_list)->push_back((yyvsp[0].node_val));
  }
#line 2157 "spell.tab.c"
    break;

  case 94: /* ret_type: ':' type  */
#line 799 "spell.y"
                    { (yyval.str_val) = (yyvsp[0].str_val); }
#line 2163 "spell.tab.c"
    break;


#line 2167 "spell.tab.c"

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

#line 802 "spell.y"


void yyerror(const char * s){
     cout << "error:" << s << " at line: "<< yylineno << endl;
     errorCount++;
}

int main(){
    yyparse();
    tableManager.printAll("tables.txt");
    return 0;
}
