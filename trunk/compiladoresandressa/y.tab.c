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
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TK_ID = 258,
     TK_CONST_INTEIRO = 259,
     TK_CONST_REAL = 260,
     TK_CONST_BOOL_V = 261,
     TK_CONST_BOOL_F = 262,
     TK_CONST_CARACTER = 263,
     TK_CONST_STRING = 264,
     TK_INTEIRO = 265,
     TK_STRING = 266,
     TK_REAL = 267,
     TK_BOOLEAN = 268,
     TK_CARACTER = 269,
     TK_VAZIO = 270,
     TK_ATRIBUICAO = 271,
     TK_INICIO_BLOCO = 272,
     TK_FIM_BLOCO = 273,
     TK_PRINCIPAL = 274,
     TK_SE = 275,
     TK_SENAO = 276,
     TK_PARA = 277,
     TK_ATE = 278,
     TK_FACA = 279,
     TK_ENQUANTO = 280,
     TK_RETORNO = 281,
     TK_ENTRADA = 282,
     TK_SAIDA = 283,
     TK_SWITCH = 284,
     TK_PADRAO = 285,
     TK_CASO = 286,
     TK_OU = 287,
     TK_E = 288,
     TK_NEGACAO = 289,
     TK_CMP_MAIOR = 290,
     TK_CMP_MENOR = 291,
     TK_CMP_MAIOR_IGUAL = 292,
     TK_CMP_MENOR_IGUAL = 293,
     TK_CMP_IGUALDADE = 294,
     TK_CMP_DIFERENCA = 295,
     TK_MAIS = 296,
     TK_MENOS = 297,
     TK_VEZES = 298,
     TK_DIV = 299,
     TK_POR_VALOR = 300,
     TK_POR_REFERENCIA = 301,
     TK_PROTOTIPO = 302
   };
#endif
/* Tokens.  */
#define TK_ID 258
#define TK_CONST_INTEIRO 259
#define TK_CONST_REAL 260
#define TK_CONST_BOOL_V 261
#define TK_CONST_BOOL_F 262
#define TK_CONST_CARACTER 263
#define TK_CONST_STRING 264
#define TK_INTEIRO 265
#define TK_STRING 266
#define TK_REAL 267
#define TK_BOOLEAN 268
#define TK_CARACTER 269
#define TK_VAZIO 270
#define TK_ATRIBUICAO 271
#define TK_INICIO_BLOCO 272
#define TK_FIM_BLOCO 273
#define TK_PRINCIPAL 274
#define TK_SE 275
#define TK_SENAO 276
#define TK_PARA 277
#define TK_ATE 278
#define TK_FACA 279
#define TK_ENQUANTO 280
#define TK_RETORNO 281
#define TK_ENTRADA 282
#define TK_SAIDA 283
#define TK_SWITCH 284
#define TK_PADRAO 285
#define TK_CASO 286
#define TK_OU 287
#define TK_E 288
#define TK_NEGACAO 289
#define TK_CMP_MAIOR 290
#define TK_CMP_MENOR 291
#define TK_CMP_MAIOR_IGUAL 292
#define TK_CMP_MENOR_IGUAL 293
#define TK_CMP_IGUALDADE 294
#define TK_CMP_DIFERENCA 295
#define TK_MAIS 296
#define TK_MENOS 297
#define TK_VEZES 298
#define TK_DIV 299
#define TK_POR_VALOR 300
#define TK_POR_REFERENCIA 301
#define TK_PROTOTIPO 302




/* Copy the first part of user declarations.  */
#line 10 "aia.y"

#include <iostream>
#include <string>

#define MAX_VAR 1024
#define MAX_OPERADORES 81
#define MAX_FUNCOES 1024
#define MAX_PARAM 1024

using namespace std;

typedef struct _tipo
{
	string tipo_base;
	int ndim;
	struct
	{
		int inicio, fim;
	} dim[2];
} tipo;

typedef struct _atributos
{
	string v, c;
	tipo t;
	string p;
} atributos;

typedef struct _tipo_oper
{
	string operador, op1, op2, resultado;
} tipo_oper;

typedef struct _simbolo_var
{
	string nome;
	tipo t;
} simbolo_var;

typedef struct _param
{
	string nome;
	bool referencia;
	tipo t;
} param;

typedef struct _simbolo_funcao
{
	string nome;
	tipo retorno;
	int nparam;
	param parametro[MAX_PARAM];
	string lista_parametros;
} simbolo_funcao;

struct _ntemp
{
	int i, r, c, s, b;
} ntemp = {0, 0, 0, 0, 0};

struct _ntemp_global
{
	int i, r, c, s, b;
} ntemp_global = {0, 0, 0, 0, 0};


simbolo_var TS_varlocal[MAX_VAR];
simbolo_var TS_varglobal[MAX_VAR];
simbolo_funcao TS_funcao[MAX_FUNCOES];

int nrotulos = 0;
int nvarlocal = 0;
int nvarglobal = 0;
int nparams = 0;
int nfuncao = 0;
int ir = 0;

string inic;
atributos variavelSwitch;

tipo_oper tipo_operador[MAX_OPERADORES] = {	{"+", "I", "I", "I"},
						{"+", "I", "R", "R"},
						{"+", "R", "R", "R"},
						{"+", "R", "I", "R"},
						{"+", "C", "C", "S"},
						{"+", "S", "C", "S"},
						{"+", "S", "S", "S"},
						{"+", "C", "I", "C"},

						{"-", "I", "I", "I"},
						{"-", "I", "R", "R"},
						{"-", "R", "R", "R"},
						{"-", "R", "I", "R"},

						{"*", "I", "I", "I"},
						{"*", "I", "R", "R"},
						{"*", "R", "I", "R"},
						{"*", "R", "R", "R"},

						{"/", "I", "I", "I"},
						{"/", "I", "R", "R"},
						{"/", "R", "I", "R"},
						{"/", "R", "R", "R"},

						{"==", "I", "I", "B"},
						{"==", "I", "R", "B"},
						{"==", "R", "I", "B"},
						{"==", "R", "R", "B"},
						{"==", "C", "C", "B"},
						{"==", "C", "S", "B"},
						{"==", "S", "C", "B"},
						{"==", "S", "S", "B"},
						{"==", "S", "S", "B"},

						{"!=", "I", "I", "B"},
						{"!=", "I", "R", "B"},
						{"!=", "R", "I", "B"},
						{"!=", "R", "R", "B"},
						{"!=", "C", "C", "B"},
						{"!=", "C", "S", "B"},
						{"!=", "S", "C", "B"},
						{"!=", "S", "S", "B"},
						{"!=", "S", "S", "B"},

						{">", "I", "I", "B"},
						{">", "I", "R", "B"},
						{">", "R", "I", "B"},
						{">", "R", "R", "B"},
						{">", "C", "C", "B"},
						{">", "C", "S", "B"},
						{">", "S", "C", "B"},
						{">", "S", "S", "B"},
						{">", "S", "S", "B"},

						{"<", "I", "I", "B"},
						{"<", "I", "R", "B"},
						{"<", "R", "I", "B"},
						{"<", "R", "R", "B"},
						{"<", "C", "C", "B"},
						{"<", "C", "S", "B"},
						{"<", "S", "C", "B"},
						{"<", "S", "S", "B"},
						{"<", "S", "S", "B"},

						{">=", "I", "I", "B"},
						{">=", "I", "R", "B"},
						{">=", "R", "I", "B"},
						{">=", "R", "R", "B"},
						{">=", "C", "C", "B"},
						{">=", "C", "S", "B"},
						{">=", "S", "C", "B"},
						{">=", "S", "S", "B"},
						{">=", "S", "S", "B"},

						{"<=", "I", "I", "B"},
						{"<=", "I", "R", "B"},
						{"<=", "R", "I", "B"},
						{"<=", "R", "R", "B"},
						{"<=", "C", "C", "B"},
						{"<=", "C", "S", "B"},
						{"<=", "S", "C", "B"},
						{"<=", "S", "S", "B"},
						{"<=", "S", "S", "B"},

						{"=", "I", "I", "I"},
						{"=", "R", "I", "R"},
						{"=", "R", "R", "R"},
						{"=", "C", "C", "C"},
						{"=", "S", "C", "S"},
						{"=", "S", "S", "S"},
						{"=", "B", "B", "B"}
					  };


void yyerror(const char*);
int yylex();
int yyparse();

bool existe_funcao(string nome);
void inclui_funcao(string nome, tipo retorno, string lista_parametros);
bool existe_param(string nome);
void inclui_param(string nome, bool referencia, tipo t);
bool busca_funcao(string nome, tipo *tr);
bool compara_parametros(string nome, string parametros);
bool compara_resultado(string resultado);
void erro(string msg);
string inttostr(int n);
int strtoint(string s);
void tipo_resultado(string operador, atributos op1, atributos op2, atributos &resultado);
string gera_temp(string tipo);
string gera_rotulo();
void gera_codigo_operador(atributos &ss, atributos &s1, atributos &s2, atributos &s3);
bool busca_varglobal (string nome, tipo *t);
bool pode_inserir_varglobal (string nome);
string gera_decl_temp(string tipo, string tipo_base, int &n);
string gera_varglobal_temp();
string gera_varlocal_temp();
string parte_vetor(tipo t);
string quebra_codigo_lista(string vetorid, string lsttemp , string lstcodtemp);
string quebra_codigo_parametro(string nometemp, string vetorid, string lsttemp, string lstcodtemp, string tiporet);
void insere_varglobal (string nome, tipo t);
bool busca_varlocal (string nome, tipo *t);
bool busca_varparam(string nome, tipo *t);
bool pode_inserir_varlocal (string nome);
void insere_varlocal (string nome, tipo t);

#define YYSTYPE atributos



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 410 "y.tab.c"

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
# if YYENABLE_NLS
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
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   275

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNRULES -- Number of states.  */
#define YYNSTATES  207

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      49,    50,     2,     2,    51,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    48,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    52,     2,    53,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,     2,    55,     2,     2,     2,     2,
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
      45,    46,    47
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,    10,    14,    15,    22,    23,    25,
      26,    30,    32,    36,    40,    41,    46,    50,    52,    54,
      56,    58,    60,    64,    71,    72,    75,    80,    84,    85,
      91,    96,    99,   104,   109,   110,   116,   120,   123,   124,
     127,   129,   131,   134,   136,   139,   142,   145,   150,   155,
     158,   161,   168,   176,   179,   180,   184,   187,   193,   199,
     207,   211,   213,   214,   218,   220,   224,   228,   230,   234,
     238,   242,   246,   250,   254,   256,   260,   264,   266,   270,
     274,   276,   279,   282,   285,   287,   289,   293,   298,   303,
     311,   315,   317,   319,   321,   323,   325,   327,   329,   333,
     335,   338,   339,   346,   348,   350,   352
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      57,     0,    -1,    58,    -1,    64,    59,    68,    96,    -1,
      59,    60,    48,    -1,    -1,    47,    98,     3,    49,    61,
      50,    -1,    -1,    62,    -1,    -1,    62,    51,    63,    -1,
      63,    -1,    66,    99,     3,    -1,    65,    48,    64,    -1,
      -1,    65,    51,     3,    67,    -1,    66,     3,    67,    -1,
      10,    -1,    12,    -1,    13,    -1,    14,    -1,    11,    -1,
      52,     4,    53,    -1,    52,     4,    53,    52,     4,    53,
      -1,    -1,    19,    69,    -1,    17,    70,    74,    18,    -1,
      71,    48,    70,    -1,    -1,    71,    51,     3,    67,    72,
      -1,    66,     3,    67,    72,    -1,    16,    87,    -1,    16,
      54,    95,    55,    -1,    16,    54,    73,    55,    -1,    -1,
      73,    51,    54,    95,    55,    -1,    54,    95,    55,    -1,
      74,    75,    -1,    -1,    86,    48,    -1,    80,    -1,    83,
      -1,    79,    48,    -1,    84,    -1,    78,    48,    -1,    76,
      48,    -1,    77,    48,    -1,    27,    49,    93,    50,    -1,
      28,    49,    87,    50,    -1,    26,    87,    -1,    26,    48,
      -1,    24,    85,    25,    49,    87,    50,    -1,    29,    49,
       3,    50,    17,    81,    18,    -1,    81,    82,    -1,    -1,
      31,    94,    85,    -1,    30,    85,    -1,    22,     4,    23,
       4,    85,    -1,    20,    49,    87,    50,    85,    -1,    20,
      49,    87,    50,    85,    21,    85,    -1,    17,    74,    18,
      -1,    87,    -1,    -1,    87,    16,    88,    -1,    88,    -1,
      88,    32,    89,    -1,    88,    33,    89,    -1,    89,    -1,
      89,    35,    90,    -1,    89,    36,    90,    -1,    89,    37,
      90,    -1,    89,    38,    90,    -1,    89,    39,    90,    -1,
      89,    40,    90,    -1,    90,    -1,    90,    41,    91,    -1,
      90,    42,    91,    -1,    91,    -1,    91,    43,    92,    -1,
      91,    44,    92,    -1,    92,    -1,    41,    93,    -1,    42,
      93,    -1,    34,    93,    -1,    93,    -1,     3,    -1,     3,
      49,    50,    -1,     3,    49,    95,    50,    -1,     3,    52,
      87,    53,    -1,     3,    52,    87,    53,    52,    87,    53,
      -1,    49,    87,    50,    -1,    94,    -1,     4,    -1,     5,
      -1,     6,    -1,     7,    -1,     8,    -1,     9,    -1,    95,
      51,    87,    -1,    87,    -1,    96,    97,    -1,    -1,    98,
       3,    49,    61,    50,    69,    -1,    66,    -1,    15,    -1,
      45,    -1,    46,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   236,   236,   242,   248,   253,   258,   274,   277,   282,
     285,   290,   297,   318,   323,   328,   337,   348,   354,   360,
     367,   373,   381,   387,   394,   401,   407,   413,   414,   417,
     431,   461,   467,   472,   474,   480,   481,   484,   489,   494,
     495,   496,   497,   498,   499,   500,   501,   504,   510,   523,
     528,   531,   548,   559,   564,   569,   592,   600,   620,   635,
     656,   662,   663,   666,   672,   675,   679,   683,   686,   690,
     694,   698,   702,   706,   710,   713,   717,   721,   724,   728,
     732,   735,   736,   737,   738,   741,   749,   757,   776,   805,
     843,   849,   852,   856,   860,   865,   870,   874,   880,   886,
     894,   899,   904,   938,   943,   949,   953
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_ID", "TK_CONST_INTEIRO",
  "TK_CONST_REAL", "TK_CONST_BOOL_V", "TK_CONST_BOOL_F",
  "TK_CONST_CARACTER", "TK_CONST_STRING", "TK_INTEIRO", "TK_STRING",
  "TK_REAL", "TK_BOOLEAN", "TK_CARACTER", "TK_VAZIO", "TK_ATRIBUICAO",
  "TK_INICIO_BLOCO", "TK_FIM_BLOCO", "TK_PRINCIPAL", "TK_SE", "TK_SENAO",
  "TK_PARA", "TK_ATE", "TK_FACA", "TK_ENQUANTO", "TK_RETORNO",
  "TK_ENTRADA", "TK_SAIDA", "TK_SWITCH", "TK_PADRAO", "TK_CASO", "TK_OU",
  "TK_E", "TK_NEGACAO", "TK_CMP_MAIOR", "TK_CMP_MENOR",
  "TK_CMP_MAIOR_IGUAL", "TK_CMP_MENOR_IGUAL", "TK_CMP_IGUALDADE",
  "TK_CMP_DIFERENCA", "TK_MAIS", "TK_MENOS", "TK_VEZES", "TK_DIV",
  "TK_POR_VALOR", "TK_POR_REFERENCIA", "TK_PROTOTIPO", "';'", "'('", "')'",
  "','", "'['", "']'", "'{'", "'}'", "$accept", "SL", "S", "PROTOTIPOS",
  "PROTOTIPO", "PARAMETROS", "LISTAPARAMETROS", "PARAMETRO",
  "VARS_GLOBAIS", "VAR_GLOBAL", "TIPO", "ARRAY", "BLOCO_PRIN", "CORPO",
  "VARS_LOCAIS", "VAR_LOCAL", "INICIO", "LST_LST_E", "COMANDOS", "COMANDO",
  "CMD_READ", "CMD_WRITE", "CMD_RETURN", "CMD_WHILE", "CMD_SWITCH",
  "CASES", "CASE", "CMD_FOR", "CMD_IF", "BLOCO", "CMD_E", "E", "E1", "E2",
  "E3", "E4", "E5", "F", "CTE", "LST_E", "FUNCOES", "FUNCAO",
  "TIPORETORNO", "TIPO_PASSAGEM", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,    59,    40,
      41,    44,    91,    93,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    58,    59,    59,    60,    60,    61,    61,
      62,    62,    63,    64,    64,    65,    65,    66,    66,    66,
      66,    66,    67,    67,    67,    68,    69,    70,    70,    71,
      71,    72,    72,    72,    72,    73,    73,    74,    74,    75,
      75,    75,    75,    75,    75,    75,    75,    76,    77,    78,
      78,    79,    80,    81,    81,    82,    82,    83,    84,    84,
      85,    86,    86,    87,    87,    88,    88,    88,    89,    89,
      89,    89,    89,    89,    89,    90,    90,    90,    91,    91,
      91,    92,    92,    92,    92,    93,    93,    93,    93,    93,
      93,    93,    94,    94,    94,    94,    94,    94,    95,    95,
      96,    96,    97,    98,    98,    99,    99
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     4,     3,     0,     6,     0,     1,     0,
       3,     1,     3,     3,     0,     4,     3,     1,     1,     1,
       1,     1,     3,     6,     0,     2,     4,     3,     0,     5,
       4,     2,     4,     4,     0,     5,     3,     2,     0,     2,
       1,     1,     2,     1,     2,     2,     2,     4,     4,     2,
       2,     6,     7,     2,     0,     3,     2,     5,     5,     7,
       3,     1,     0,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     2,     2,     2,     1,     1,     3,     4,     4,     7,
       3,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       2,     0,     6,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      14,    17,    21,    18,    19,    20,     0,     2,     5,     0,
       0,     1,     7,    14,     0,    24,     0,     0,     0,   101,
      13,    24,     0,    16,    28,    25,   104,   103,     0,     4,
       3,    15,     0,     0,    38,     0,     0,   100,     0,    22,
      24,    62,    28,     0,     9,     0,     0,    34,    85,    92,
      93,    94,    95,    96,    97,    26,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    37,     0,     0,
       0,     0,    40,    41,    43,     0,    61,    64,    67,    74,
      77,    80,    84,    91,    27,    24,     0,     8,    11,     0,
       9,     0,     0,    30,     0,     0,     0,     0,    38,     0,
      50,    49,     0,     0,     0,    83,    81,    82,     0,    45,
      46,    44,    42,    39,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    34,     6,     0,
     105,   106,     0,     0,    23,     0,    31,    86,    99,     0,
       0,     0,     0,    62,     0,     0,     0,     0,    90,    63,
      65,    66,    68,    69,    70,    71,    72,    73,    75,    76,
      78,    79,    29,    10,    12,     0,     0,     0,     0,    87,
       0,    88,     0,     0,    60,     0,    47,    48,     0,   102,
       0,     0,    33,    32,    98,     0,    58,    57,     0,    54,
      36,     0,     0,     0,    51,     0,     0,    89,    59,    52,
       0,     0,    53,    35,    56,     0,    55
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,    12,    18,    86,    87,    88,     8,     9,
      89,    23,    19,    25,    34,    35,    93,   167,    41,    67,
      68,    69,    70,    71,    72,   195,   202,    73,    74,    99,
      75,   138,    77,    78,    79,    80,    81,    82,    83,   139,
      30,    37,    28,   132
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -134
static const yytype_int16 yypact[] =
{
     135,  -134,  -134,  -134,  -134,  -134,    19,  -134,  -134,   -19,
      21,  -134,    12,   135,    27,    -2,    67,   157,    45,  -134,
    -134,    -2,   103,  -134,   135,  -134,  -134,  -134,   106,  -134,
     157,  -134,    74,   117,  -134,   -10,    79,  -134,   139,    91,
      -2,   132,   135,   148,   135,   104,   151,   141,    59,  -134,
    -134,  -134,  -134,  -134,  -134,  -134,   115,   161,   172,    82,
     149,   153,   155,   187,   187,   187,   226,  -134,   152,   162,
     163,   164,  -134,  -134,  -134,   189,   193,    16,   140,    22,
      30,  -134,  -134,  -134,  -134,    -2,   188,   190,  -134,    55,
     135,   186,     3,  -134,    72,   226,   226,   217,  -134,   218,
    -134,   193,   187,   226,   239,  -134,  -134,  -134,    -3,  -134,
    -134,  -134,  -134,  -134,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   141,  -134,   135,
    -134,  -134,   241,   195,  -134,    63,   193,  -134,   193,    68,
     -13,     6,   242,   179,   198,   199,    10,   200,  -134,    16,
     140,   140,    22,    22,    22,    22,    22,    22,    30,    30,
    -134,  -134,  -134,  -134,  -134,    67,   226,   -12,    41,  -134,
     226,   196,   172,   172,  -134,   226,  -134,  -134,   234,  -134,
      43,   201,  -134,  -134,   193,   226,   231,  -134,    11,  -134,
    -134,   226,   -11,   172,  -134,     5,    44,  -134,  -134,  -134,
     172,   210,  -134,  -134,  -134,   172,  -134
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -134,  -134,  -134,  -134,  -134,   166,  -134,   124,   244,  -134,
       4,   -20,  -134,    89,   216,  -134,   134,  -134,   165,  -134,
    -134,  -134,  -134,  -134,  -134,  -134,  -134,  -134,  -134,   -90,
    -134,   -41,   145,    17,   105,     2,    37,   -49,    61,  -133,
    -134,  -134,   235,  -134
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      76,    31,   168,   114,    10,   114,    48,    49,    50,    51,
      52,    53,    54,   114,   105,   106,   107,    10,   101,    11,
      47,    27,   114,   199,    15,   108,   114,   114,    33,    13,
      21,    16,    14,   180,    27,   200,   201,    63,    42,   181,
     171,    43,   197,   182,    64,    65,    33,   148,   115,   116,
      22,   136,    66,   145,   140,   141,   172,   135,   196,    17,
     177,   194,   146,   123,   124,   127,    48,    49,    50,    51,
      52,    53,    54,   125,   126,    48,    49,    50,    51,    52,
      53,    54,   186,   187,    24,    48,    49,    50,    51,    52,
      53,    54,   170,    29,   170,   170,   183,    63,   190,   203,
     130,   131,    76,   198,    64,    65,    63,    32,    94,    36,
     204,    95,    66,    64,    65,   206,    63,   166,   169,   170,
      40,    66,   137,    64,    65,   158,   159,    39,    44,   184,
     100,    66,   150,   151,   188,    48,    49,    50,    51,    52,
      53,    54,    45,    46,   192,     1,     2,     3,     4,     5,
      55,    85,    56,    90,    57,    91,    58,    92,    59,    60,
      61,    62,   160,   161,    96,    97,    63,     1,     2,     3,
       4,     5,    26,    64,    65,   117,   118,   119,   120,   121,
     122,    66,    48,    49,    50,    51,    52,    53,    54,    98,
      48,    49,    50,    51,    52,    53,    54,   174,   102,    56,
     109,    57,   103,    58,   104,    59,    60,    61,    62,   114,
     110,   111,   112,    63,    49,    50,    51,    52,    53,    54,
      64,    65,   152,   153,   154,   155,   156,   157,    66,    48,
      49,    50,    51,    52,    53,    54,    66,   113,   128,   134,
     142,   129,   147,   144,   164,   165,   173,   175,   185,   176,
     178,   189,   193,   163,   179,   191,   133,    20,    84,   149,
      63,   162,   205,   143,     0,    38,     0,    64,    65,     0,
       0,     0,     0,     0,     0,    66
};

static const yytype_int16 yycheck[] =
{
      41,    21,   135,    16,     0,    16,     3,     4,     5,     6,
       7,     8,     9,    16,    63,    64,    65,    13,    59,     0,
      40,    17,    16,    18,     3,    66,    16,    16,    24,    48,
       3,    19,    51,   166,    30,    30,    31,    34,    48,    51,
      53,    51,    53,    55,    41,    42,    42,    50,    32,    33,
      52,    92,    49,   102,    95,    96,    50,    54,   191,    47,
      50,    50,   103,    41,    42,    85,     3,     4,     5,     6,
       7,     8,     9,    43,    44,     3,     4,     5,     6,     7,
       8,     9,   172,   173,    17,     3,     4,     5,     6,     7,
       8,     9,    51,    48,    51,    51,    55,    34,    55,    55,
      45,    46,   143,   193,    41,    42,    34,     4,    49,     3,
     200,    52,    49,    41,    42,   205,    34,    54,    50,    51,
       3,    49,    50,    41,    42,   123,   124,    53,    49,   170,
      48,    49,   115,   116,   175,     3,     4,     5,     6,     7,
       8,     9,     3,    52,   185,    10,    11,    12,    13,    14,
      18,     3,    20,    49,    22,     4,    24,    16,    26,    27,
      28,    29,   125,   126,    49,     4,    34,    10,    11,    12,
      13,    14,    15,    41,    42,    35,    36,    37,    38,    39,
      40,    49,     3,     4,     5,     6,     7,     8,     9,    17,
       3,     4,     5,     6,     7,     8,     9,    18,    49,    20,
      48,    22,    49,    24,    49,    26,    27,    28,    29,    16,
      48,    48,    48,    34,     4,     5,     6,     7,     8,     9,
      41,    42,   117,   118,   119,   120,   121,   122,    49,     3,
       4,     5,     6,     7,     8,     9,    49,    48,    50,    53,
      23,    51,     3,    25,     3,    50,     4,    49,    52,    50,
      50,    17,    21,   129,   165,    54,    90,    13,    42,   114,
      34,   127,   201,    98,    -1,    30,    -1,    41,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    49
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,    11,    12,    13,    14,    57,    58,    64,    65,
      66,     0,    59,    48,    51,     3,    19,    47,    60,    68,
      64,     3,    52,    67,    17,    69,    15,    66,    98,    48,
      96,    67,     4,    66,    70,    71,     3,    97,    98,    53,
       3,    74,    48,    51,    49,     3,    52,    67,     3,     4,
       5,     6,     7,     8,     9,    18,    20,    22,    24,    26,
      27,    28,    29,    34,    41,    42,    49,    75,    76,    77,
      78,    79,    80,    83,    84,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    70,     3,    61,    62,    63,    66,
      49,     4,    16,    72,    49,    52,    49,     4,    17,    85,
      48,    87,    49,    49,    49,    93,    93,    93,    87,    48,
      48,    48,    48,    48,    16,    32,    33,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    67,    50,    51,
      45,    46,    99,    61,    53,    54,    87,    50,    87,    95,
      87,    87,    23,    74,    25,    93,    87,     3,    50,    88,
      89,    89,    90,    90,    90,    90,    90,    90,    91,    91,
      92,    92,    72,    63,     3,    50,    54,    73,    95,    50,
      51,    53,    50,     4,    18,    49,    50,    50,    50,    69,
      95,    51,    55,    55,    87,    52,    85,    85,    87,    17,
      55,    54,    87,    21,    50,    81,    95,    53,    85,    18,
      30,    31,    82,    55,    85,    94,    85
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
# if YYLTYPE_IS_TRIVIAL
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
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
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

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



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 237 "aia.y"
    {
			cout << "#include <string>\n#include <iostream>\n\nusing namespace std;\n\n" +  (yyvsp[(1) - (1)]).c << endl;
		}
    break;

  case 3:
#line 243 "aia.y"
    {
			(yyval).c = (yyvsp[(1) - (4)]).c + (yyvsp[(2) - (4)]).c + (yyvsp[(3) - (4)]).c + (yyvsp[(4) - (4)]).c;
		}
    break;

  case 4:
#line 249 "aia.y"
    {
			(yyval).c += (yyvsp[(2) - (3)]).c;
		}
    break;

  case 5:
#line 253 "aia.y"
    {
			(yyval).c = "";
		}
    break;

  case 6:
#line 259 "aia.y"
    {
			if((yyvsp[(2) - (6)]).c == "V"){
				(yyval).c = (yyvsp[(2) - (6)]).c + " " + (yyvsp[(3) - (6)]).v + "(" + (yyvsp[(5) - (6)]).c+ ");\n";
				inclui_funcao((yyvsp[(3) - (6)]).v,(yyvsp[(2) - (6)]).t, (yyvsp[(5) - (6)]).p);
				nfuncao++;
				nparams = 0;
			}
			else{
				(yyval).c =  "void " + (yyvsp[(3) - (6)]).v + "(" + (yyvsp[(5) - (6)]).c+ ", int &RI);\n";
				inclui_funcao((yyvsp[(3) - (6)]).v,(yyvsp[(2) - (6)]).t, (yyvsp[(5) - (6)]).p);
				nfuncao++;
				nparams = 0;

			}
		}
    break;

  case 8:
#line 278 "aia.y"
    {
			(yyval).p = "#" + (yyvsp[(1) - (1)]).t.tipo_base;
			(yyval).c = (yyvsp[(1) - (1)]).c;
		}
    break;

  case 10:
#line 286 "aia.y"
    {
			(yyval).p += "#" + (yyvsp[(3) - (3)]).t.tipo_base;
			(yyval).c = (yyvsp[(1) - (3)]).c + "," + (yyvsp[(3) - (3)]).c;
		}
    break;

  case 11:
#line 291 "aia.y"
    {
			(yyval).p = "#" + (yyvsp[(1) - (1)]).t.tipo_base;
			(yyval).c = (yyvsp[(1) - (1)]).c;
		}
    break;

  case 12:
#line 298 "aia.y"
    {
			nparams++;
			bool varbool;
			(yyval).t = (yyvsp[(1) - (3)]).t;
			(yyval).c = (yyvsp[(1) - (3)]).c + (yyvsp[(2) - (3)]).c + (yyvsp[(3) - (3)]).v;

			if ((yyvsp[(2) - (3)]).v == "&")
			{
				varbool = true;
			}
			else
			{
				varbool = false;
			}

			inclui_param((yyvsp[(3) - (3)]).v, varbool, (yyvsp[(1) - (3)]).t);
			(yyval).p = "#" + (yyvsp[(1) - (3)]).t.tipo_base;
		}
    break;

  case 13:
#line 319 "aia.y"
    {
			(yyval).c = gera_varglobal_temp(); + "\n" + (yyvsp[(3) - (3)]).c;
		}
    break;

  case 14:
#line 323 "aia.y"
    {
			(yyval).c = "";
		}
    break;

  case 15:
#line 329 "aia.y"
    {
			(yyval).t = (yyvsp[(1) - (4)]).t;
			(yyvsp[(3) - (4)]).t = (yyvsp[(1) - (4)]).t;
			(yyvsp[(1) - (4)]).t.ndim = (yyvsp[(4) - (4)]).t.ndim;
			(yyvsp[(1) - (4)]).t.dim[0].fim = (yyvsp[(4) - (4)]).t.dim[0].fim;
			(yyvsp[(1) - (4)]).t.dim[1].fim = (yyvsp[(4) - (4)]).t.dim[1].fim;
			insere_varglobal((yyvsp[(3) - (4)]).v , (yyvsp[(1) - (4)]).t);
		}
    break;

  case 16:
#line 338 "aia.y"
    {
			(yyval).t = (yyvsp[(1) - (3)]).t;
			(yyvsp[(2) - (3)]).t = (yyvsp[(1) - (3)]).t;
			(yyvsp[(1) - (3)]).t.ndim = (yyvsp[(3) - (3)]).t.ndim;
			(yyvsp[(1) - (3)]).t.dim[0].fim = (yyvsp[(3) - (3)]).t.dim[0].fim;
			(yyvsp[(1) - (3)]).t.dim[1].fim = (yyvsp[(3) - (3)]).t.dim[1].fim;
			insere_varglobal((yyvsp[(2) - (3)]).v , (yyvsp[(1) - (3)]).t);
		}
    break;

  case 17:
#line 349 "aia.y"
    {
			(yyval).t.tipo_base = "I";
			(yyval).c = "int";
			(yyval).v = (yyvsp[(1) - (1)]).v;
		}
    break;

  case 18:
#line 355 "aia.y"
    {
			(yyval).t.tipo_base= "R";
			(yyval).c = "float";
			(yyval).v = (yyvsp[(1) - (1)]).v;
		}
    break;

  case 19:
#line 361 "aia.y"
    {
			(yyval).t.tipo_base= "B";
			(yyval).c = "int";
			(yyval).v = (yyvsp[(1) - (1)]).v;
		}
    break;

  case 20:
#line 368 "aia.y"
    {
			(yyval).t.tipo_base = "C";
			(yyval).c = "char";
			(yyval).v = (yyvsp[(1) - (1)]).v;
		}
    break;

  case 21:
#line 374 "aia.y"
    {
			(yyval).t.tipo_base= "S";
			(yyval).c = "char *";
			(yyval).v = (yyvsp[(1) - (1)]).v;
		}
    break;

  case 22:
#line 382 "aia.y"
    {
			(yyval).t.ndim = 1;
			(yyval).t.dim[0].fim = atoi(((yyvsp[(3) - (3)]).v).c_str());
			(yyval).t.dim[1].fim = 0;
		}
    break;

  case 23:
#line 388 "aia.y"
    {
			(yyval).t.ndim = 2;
			(yyval).t.dim[0].fim = atoi(((yyvsp[(3) - (6)]).v).c_str());
			(yyval).t.dim[1].fim = atoi(((yyvsp[(5) - (6)]).v).c_str());
		}
    break;

  case 24:
#line 394 "aia.y"
    {
			(yyval).t.ndim = 0;
			(yyval).t.dim[0].fim = 0;
			(yyval).t.dim[1].fim = 0;
		}
    break;

  case 25:
#line 402 "aia.y"
    {
			(yyval).c = "int main ()\n" + (yyvsp[(2) - (2)]).c;
		}
    break;

  case 26:
#line 408 "aia.y"
    {
			(yyval).c = "{\n" + gera_varlocal_temp() +  (yyvsp[(3) - (4)]).c + "\n}\n";
		}
    break;

  case 29:
#line 418 "aia.y"
    {
			(yyval).t = (yyvsp[(1) - (5)]).t;
			(yyvsp[(3) - (5)]).t = (yyvsp[(1) - (5)]).t;
			(yyvsp[(1) - (5)]).t.ndim = (yyvsp[(4) - (5)]).t.ndim;
			(yyvsp[(1) - (5)]).t.dim[0].fim = (yyvsp[(4) - (5)]).t.dim[0].fim;
			(yyvsp[(1) - (5)]).t.dim[1].fim = (yyvsp[(4) - (5)]).t.dim[1].fim;
			insere_varlocal((yyvsp[(3) - (5)]).v , (yyvsp[(1) - (5)]).t);

			if((yyvsp[(5) - (5)]).v != "")
			{
				inic +=(yyvsp[(5) - (5)]).c + (yyvsp[(3) - (5)]).v + "=" + (yyvsp[(5) - (5)]).v + ";\n";
			}
		}
    break;

  case 30:
#line 432 "aia.y"
    {
			(yyval).t = (yyvsp[(1) - (4)]).t;
			(yyvsp[(2) - (4)]).t = (yyvsp[(1) - (4)]).t;
			(yyvsp[(1) - (4)]).t.ndim = (yyvsp[(3) - (4)]).t.ndim;
			(yyvsp[(1) - (4)]).t.dim[0].fim = (yyvsp[(3) - (4)]).t.dim[0].fim;
			(yyvsp[(1) - (4)]).t.dim[1].fim = (yyvsp[(3) - (4)]).t.dim[1].fim;

			insere_varlocal((yyvsp[(2) - (4)]).v , (yyvsp[(1) - (4)]).t);

			if ((yyvsp[(4) - (4)]).v != "")
			{
				if (((yyvsp[(4) - (4)]).v).c_str()[0] == '#')
				{
					inic += quebra_codigo_lista((yyvsp[(2) - (4)]).v, (yyvsp[(4) - (4)]).v , (yyvsp[(4) - (4)]).c);
				}
				else
				{
					inic += (yyvsp[(4) - (4)]).c;
					atributos ss, s1, s2, s3;
					s1 = (yyvsp[(2) - (4)]);
					s2.v = "=";
					s3 = (yyvsp[(4) - (4)]);
					gera_codigo_operador(ss, s1,s2 ,s3 );
					inic += ss.c;
				}
			}
		}
    break;

  case 31:
#line 462 "aia.y"
    {
			(yyval).v = (yyvsp[(2) - (2)]).v;
			(yyval).t = (yyvsp[(2) - (2)]).t;
			(yyval).c = (yyvsp[(2) - (2)]).c;
		}
    break;

  case 32:
#line 468 "aia.y"
    {
			(yyval).v = (yyvsp[(3) - (4)]).v;
			(yyval).c = (yyvsp[(3) - (4)]).c;
		}
    break;

  case 34:
#line 474 "aia.y"
    {
			(yyval).v = "";
			(yyval).c = "";
		}
    break;

  case 37:
#line 485 "aia.y"
    {
			(yyval).c = (yyvsp[(1) - (2)]).c + (yyvsp[(2) - (2)]).c;
		}
    break;

  case 38:
#line 489 "aia.y"
    {
			(yyval).c = "";
		}
    break;

  case 47:
#line 505 "aia.y"
    {
			(yyval).c = (yyvsp[(3) - (4)]).c + "cin >>" + (yyvsp[(3) - (4)]).v + " ;\n";
		}
    break;

  case 48:
#line 511 "aia.y"
    {
			if (((yyvsp[(3) - (4)]).t.ndim != 0) && ((yyvsp[(3) - (4)]).t.tipo_base == "S"))
			{
				(yyval).c = (yyvsp[(3) - (4)]).c + "cout << &" + (yyvsp[(3) - (4)]).v  + ";\n ";
			}
			else
			{
				(yyval).c = (yyvsp[(3) - (4)]).c + "cout << " + (yyvsp[(3) - (4)]).v  + ";\n ";
			}
		}
    break;

  case 49:
#line 524 "aia.y"
    {
			(yyval).c = (yyvsp[(2) - (2)]).c + "RI = " + (yyvsp[(2) - (2)]).v + ";\nreturn;\n";
			compara_resultado((yyvsp[(2) - (2)]).t.tipo_base);
		}
    break;

  case 51:
#line 532 "aia.y"
    {
			string rotulo = gera_rotulo();
			string teste = gera_temp("B");
			string codigo;
			codigo += rotulo + ": ";
			codigo += (yyvsp[(2) - (6)]).c;
			codigo += (yyvsp[(5) - (6)]).c;
			codigo += teste + " =" + (yyvsp[(5) - (6)]).v + ";\n";
			codigo += "if (" + teste + " ) \n";
			codigo += "goto " + rotulo + ";\n";
			(yyval).c = codigo;
		}
    break;

  case 52:
#line 549 "aia.y"
    {	
			//if (busca_varlocal ($3.v, &(variavelSwitch.t)));
			//else if (busca_varglobal ($3.v, &(variavelSwitch.t))) erro("nao variavel");
			//else erro("nao variavel");
			variavelSwitch = (yyvsp[(3) - (7)]);
			variavelSwitch.t.tipo_base = "I";
			(yyval).c = (yyvsp[(6) - (7)]).c;
		}
    break;

  case 53:
#line 560 "aia.y"
    {
			(yyval).c = (yyvsp[(1) - (2)]).c + (yyvsp[(2) - (2)]).c;
		}
    break;

  case 54:
#line 564 "aia.y"
    {
			(yyval).c = "";
		}
    break;

  case 55:
#line 570 "aia.y"
    {
			string codigo;
			string rotulo = gera_rotulo();
			string teste = gera_temp("B");

			atributos vteste;
			vteste.v = teste;
			vteste.t.tipo_base = "B";

			atributos sinal;
			sinal.v = "==";
			gera_codigo_operador(vteste,variavelSwitch, sinal ,(yyvsp[(2) - (3)]));
			codigo += vteste.c;
			codigo += teste +" =  ! " + teste + " ;\n";
			codigo += "if("  +  teste  +   ")\n";
			codigo += "goto " + rotulo + ";\n";
			codigo += (yyvsp[(3) - (3)]).c;
			codigo += rotulo + ": ;\n";

			(yyval).c = codigo;

		}
    break;

  case 56:
#line 593 "aia.y"
    {	
			(yyval).c = (yyvsp[(2) - (2)]).c;
		}
    break;

  case 57:
#line 601 "aia.y"
    {
			string inicio = gera_temp("I");
			string fim = gera_temp("I");
			string teste = gera_temp("I");
			string rotulo = gera_rotulo();
			string codigo;

			codigo = inicio + " = " + (yyvsp[(2) - (5)]).v +";\n";
			codigo += fim + " = " + (yyvsp[(4) - (5)]).v +";\n";
			codigo += rotulo + " : " + (yyvsp[(5) - (5)]).c;
			codigo += inicio + " = " + inicio + " + 1" + ";\n";
			codigo += teste + " = "+ inicio + " <= " + fim +";\n";
			codigo += "if(" + teste +")\n";
			codigo += "goto " + rotulo + ";\n";

			(yyval).c = codigo;
		}
    break;

  case 58:
#line 621 "aia.y"
    {
			string codigo;
			string rotulo = gera_rotulo();
			string teste = gera_temp("B");

			codigo += (yyvsp[(3) - (5)]).c;
			codigo += teste +" =  ! " + (yyvsp[(3) - (5)]).v + " ;\n";
			codigo += "if("  +  teste  +   ")\n";
			codigo += "goto " + rotulo + ";\n";
			codigo += (yyvsp[(5) - (5)]).c;
			codigo += rotulo + ": ;\n";

			(yyval).c = codigo;
		}
    break;

  case 59:
#line 636 "aia.y"
    {
			string codigo;
			string rotulo = gera_rotulo();
			string teste = gera_temp("B");
			string rotulo2 = gera_rotulo();

			codigo += (yyvsp[(3) - (7)]).c;
			codigo += teste +" =  ! " + (yyvsp[(3) - (7)]).v + " ;\n";
			codigo += "if("  +  teste  +   ")\n";
			codigo += "goto " + rotulo + ";\n";
			codigo += (yyvsp[(5) - (7)]).c;
			codigo += "goto " + rotulo2 + ";\n";
			codigo += rotulo + ": ;\n";
			codigo += (yyvsp[(7) - (7)]).c;
			codigo += rotulo2 + ": ;\n";

			(yyval).c = codigo;
		}
    break;

  case 60:
#line 657 "aia.y"
    {
			(yyval).c = (yyvsp[(2) - (3)]).c;
		}
    break;

  case 63:
#line 667 "aia.y"
    {
			(yyval).c = (yyvsp[(1) - (3)]).c;
			(yyvsp[(2) - (3)]).v = "=";
			gera_codigo_operador((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
		}
    break;

  case 65:
#line 676 "aia.y"
    {
			gera_codigo_operador((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
		}
    break;

  case 66:
#line 680 "aia.y"
    {
			gera_codigo_operador((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
		}
    break;

  case 68:
#line 687 "aia.y"
    {
			gera_codigo_operador((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
		}
    break;

  case 69:
#line 691 "aia.y"
    {
			gera_codigo_operador((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
		}
    break;

  case 70:
#line 695 "aia.y"
    {
			gera_codigo_operador((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
		}
    break;

  case 71:
#line 699 "aia.y"
    {
			gera_codigo_operador((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
		}
    break;

  case 72:
#line 703 "aia.y"
    {
			gera_codigo_operador((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
		}
    break;

  case 73:
#line 707 "aia.y"
    {
			gera_codigo_operador((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
		}
    break;

  case 75:
#line 714 "aia.y"
    {
			gera_codigo_operador((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
		}
    break;

  case 76:
#line 718 "aia.y"
    {
			gera_codigo_operador((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
		}
    break;

  case 78:
#line 725 "aia.y"
    {
			gera_codigo_operador((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
		}
    break;

  case 79:
#line 729 "aia.y"
    {
			gera_codigo_operador((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
		}
    break;

  case 85:
#line 742 "aia.y"
    {
			busca_varglobal((yyvsp[(1) - (1)]).v, & (yyvsp[(1) - (1)]).t);
			busca_varlocal((yyvsp[(1) - (1)]).v, & (yyvsp[(1) - (1)]).t);
			busca_varparam((yyvsp[(1) - (1)]).v, & (yyvsp[(1) - (1)]).t);

			(yyval).t = (yyvsp[(1) - (1)]).t;
		}
    break;

  case 86:
#line 750 "aia.y"
    {
			busca_funcao((yyvsp[(1) - (3)]).v, & (yyvsp[(1) - (3)]).t);
			(yyval) = (yyvsp[(1) - (3)]);
			(yyval).v = gera_temp((yyvsp[(1) - (3)]).t.tipo_base);
			(yyval).c = quebra_codigo_parametro((yyval).v, (yyvsp[(1) - (3)]).v,  "" , "", (yyvsp[(1) - (3)]).t.tipo_base);
			compara_parametros((yyvsp[(1) - (3)]).v, "");
		}
    break;

  case 87:
#line 758 "aia.y"
    {

			busca_funcao((yyvsp[(1) - (4)]).v, & (yyvsp[(1) - (4)]).t);
			(yyval) = (yyvsp[(1) - (4)]);

			if ((yyvsp[(1) - (4)]).t.tipo_base =="V")
			{
				(yyval).v = "";
			}
			else
			{
				(yyval).v = gera_temp((yyvsp[(1) - (4)]).t.tipo_base);
			}

			(yyval).c = quebra_codigo_parametro((yyval).v, (yyvsp[(1) - (4)]).v,  (yyvsp[(3) - (4)]).v , (yyvsp[(3) - (4)]).c, (yyvsp[(1) - (4)]).t.tipo_base);

			compara_parametros((yyvsp[(1) - (4)]).v, (yyvsp[(3) - (4)]).p);
		}
    break;

  case 88:
#line 777 "aia.y"
    {
			busca_varglobal((yyvsp[(1) - (4)]).v, & (yyvsp[(1) - (4)]).t);
			busca_varlocal((yyvsp[(1) - (4)]).v, & (yyvsp[(1) - (4)]).t);

			(yyval).t = (yyvsp[(1) - (4)]).t;

			(yyval).c = (yyvsp[(3) - (4)]).c;

			string aux ="";

			if ((yyvsp[(3) - (4)]).t.ndim !=0 )
			{
				(yyval).c += aux + " = " + (yyvsp[(3) - (4)]).v + ";\n";
				(yyvsp[(3) - (4)]).v = aux;
			}

			if ((yyvsp[(1) - (4)]).t.tipo_base == "S")
			{
				(yyval).c += aux + " = " + (yyvsp[(3) - (4)]).v + "* 256" + ";\n";
				(yyvsp[(3) - (4)]).v = aux;

				(yyval).v =  (yyvsp[(1) - (4)]).v + "[" + (yyvsp[(3) - (4)]).v + "]";
			}
			else
			{
				(yyval).v =  (yyvsp[(1) - (4)]).v + "[" + (yyvsp[(3) - (4)]).v + "]";
			}
		}
    break;

  case 89:
#line 806 "aia.y"
    {
			busca_varglobal((yyvsp[(1) - (7)]).v, & (yyvsp[(1) - (7)]).t);
			busca_varlocal((yyvsp[(1) - (7)]).v, & (yyvsp[(1) - (7)]).t);
			(yyval).t = (yyvsp[(1) - (7)]).t;

			string codigo;

			string i = gera_temp("I");
			codigo += i	+ " = " + (yyvsp[(3) - (7)]).v + ";\n";
			codigo += i + " = " + i + " * " + inttostr((yyvsp[(1) - (7)]).t.dim[1].fim ) + ";\n";

			atributos ss, s1, s2, s3;
			s1.v = i;
			s1.t.tipo_base = "I";
			s2.v = "+";
			s3 = (yyvsp[(6) - (7)]);
			gera_codigo_operador(ss,s1,s2,s3);

			codigo += ss.c;

			(yyval).c = (yyvsp[(3) - (7)]).c + (yyvsp[(6) - (7)]).c + codigo; 

			string aux = gera_temp((yyvsp[(3) - (7)]).t.tipo_base);

			if ((yyvsp[(1) - (7)]).t.tipo_base == "S")
			{
				(yyval).c += aux + " = " + ss.v + "* 256" + ";\n";
				(yyvsp[(3) - (7)]).v = aux;

				(yyval).v =  (yyvsp[(1) - (7)]).v + "[" + aux + "]";
			}
			else
			{
				(yyval).v =  (yyvsp[(1) - (7)]).v + "[" + ss.v + "]";
			}

		}
    break;

  case 90:
#line 844 "aia.y"
    {
			(yyval).t.tipo_base = (yyvsp[(2) - (3)]).t.tipo_base;
			(yyval).v = (yyvsp[(2) - (3)]).v;
			(yyval).c =  (yyvsp[(2) - (3)]).c;
		}
    break;

  case 92:
#line 853 "aia.y"
    {
			(yyval).t.tipo_base = "I";
		}
    break;

  case 93:
#line 857 "aia.y"
    {
			(yyval).t.tipo_base = "R";
		}
    break;

  case 94:
#line 861 "aia.y"
    {
			(yyval).v = inttostr(1);
			(yyval).t.tipo_base = "B";
		}
    break;

  case 95:
#line 866 "aia.y"
    {
			(yyval).v = inttostr(0);
			(yyval).t.tipo_base = "B";
		}
    break;

  case 96:
#line 871 "aia.y"
    {
			(yyval).t.tipo_base = "C";
		}
    break;

  case 97:
#line 875 "aia.y"
    {
			(yyval).t.tipo_base = "S";
		}
    break;

  case 98:
#line 881 "aia.y"
    {
			(yyval).v += "#" + (yyvsp[(3) - (3)]).v;
			(yyval).c += "#" + (yyvsp[(3) - (3)]).c;
			(yyval).p += "#" + (yyvsp[(3) - (3)]).t.tipo_base;
		}
    break;

  case 99:
#line 887 "aia.y"
    {
			(yyval).v = "#" + (yyvsp[(1) - (1)]).v;
			(yyval).c = "#" + (yyvsp[(1) - (1)]).c;
			(yyval).p += "#" + (yyvsp[(1) - (1)]).t.tipo_base;
		}
    break;

  case 100:
#line 895 "aia.y"
    {
			(yyval).c = (yyvsp[(1) - (2)]).c + (yyvsp[(2) - (2)]).c;
		}
    break;

  case 101:
#line 899 "aia.y"
    {
			(yyval).c = "";
		}
    break;

  case 102:
#line 905 "aia.y"
    {
			string retorno;
			string aux;

			if (nparams >= 1)
			{
				if ((yyvsp[(1) - (6)]).v == "vanus")
				{
					aux = "";
					(yyval).c = "void " + (yyvsp[(2) - (6)]).v + "(" + (yyvsp[(4) - (6)]).c + (yyvsp[(1) - (6)]).c + aux + ")\n" + (yyvsp[(6) - (6)]).c;
				}
				else
				{
					aux = " &RI";
					(yyval).c = "void " + (yyvsp[(2) - (6)]).v + "(" + (yyvsp[(4) - (6)]).c + "," + (yyvsp[(1) - (6)]).c + aux + ")\n" + (yyvsp[(6) - (6)]).c;
				}
				ir = ir + 1;
			}
			else
			{
				(yyval).c = "void " + (yyvsp[(2) - (6)]).v + "(" + (yyvsp[(1) - (6)]).c + aux  + ")\n" + (yyvsp[(6) - (6)]).c;
				ir = ir + 1;
			}

			if(busca_funcao((yyvsp[(2) - (6)]).v, &(yyvsp[(2) - (6)]).t) == false)
			{
				inclui_funcao((yyvsp[(2) - (6)]).v, (yyvsp[(1) - (6)]).t, (yyvsp[(4) - (6)]).p);
				nfuncao++;
				nparams = 0;
			}
		}
    break;

  case 103:
#line 939 "aia.y"
    {
			(yyval).t = (yyvsp[(1) - (1)]).t;
			(yyval).c = (yyvsp[(1) - (1)]).c;
		}
    break;

  case 104:
#line 944 "aia.y"
    {
			(yyval).t.tipo_base = "V";
		}
    break;

  case 105:
#line 950 "aia.y"
    {
			(yyval).c = " ";
		}
    break;

  case 106:
#line 954 "aia.y"
    {
			(yyval).c = " &";
		}
    break;


/* Line 1267 of yacc.c.  */
#line 2648 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


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
		      yytoken, &yylval);
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 959 "aia.y"


#include "lex.yy.c"


int main(int argc, char* argv[])
{
	yyparse();
}

string gera_temp(string tipo)
{
	char variavel[200];

	if (tipo == "I")
	{
		sprintf(variavel, "TI%d", ntemp.i++);
	}
	else if (tipo == "R")
	{
		sprintf(variavel, "TR%d", ntemp.r++);
	}
	else if (tipo == "C")
	{
		sprintf(variavel, "TC%d", ntemp.c++);
	}
	else if (tipo == "S")
	{
		sprintf(variavel, "TS%d", ntemp.s++);
	}
	else if (tipo == "B")
	{
		sprintf(variavel, "TB%d", ntemp.b++);
	}
	return variavel;
}

bool existe_funcao(string nome)
{
	int i;
	for (i = 0; i < nfuncao; i++)
	{
		if (TS_funcao[i].nome == nome)
		{
			return true;
		}

	}
	return false;

}
void inclui_funcao(string nome, tipo retorno, string lista_parametros)
{
	if(existe_funcao(nome))
	{
		erro("Funcao ja declarada.");
	}
	TS_funcao[nfuncao].nome = nome;
	TS_funcao[nfuncao].retorno = retorno;
	TS_funcao[nfuncao].lista_parametros = lista_parametros;

}

bool existe_param(string nome)
{
	int i;
	int j;

	for (i = 0; i < nfuncao; i++)
	{
		if (TS_funcao[i].nome == nome)
		{

			for (j = 0; j < TS_funcao[i].nparam; j++)
			{
				if (TS_funcao[i].parametro[j].nome == nome)
				{
					return true;
				}
			}

		}

	}
	return false;
}

void inclui_param(string nome, bool referencia, tipo t)
{
	int p;
	if(existe_param(nome))
	{
		erro("Parametro ja declarado.");
	}
	p = TS_funcao[nfuncao].nparam;
	TS_funcao[nfuncao].parametro[p].nome = nome;
	TS_funcao[nfuncao].parametro[p].referencia = referencia;
	TS_funcao[nfuncao].parametro[p].t = t;
	TS_funcao[nfuncao].nparam++;
}

bool busca_funcao(string nome, tipo *tr)
{
	int i;
	for(i = 0 ; i < nfuncao; i++)
	{
		if(TS_funcao[i].nome == nome)
		{
			if(tr != NULL)
			{
				*tr = TS_funcao[i].retorno;
			}
			
			return true;
		}
	}
	return false;
}

bool busca_varparam(string nome, tipo *t)
{
	if (nfuncao != 0)
	{
		int i, j;
		i = nfuncao - 1;
		for(j = 0 ; j < TS_funcao[i].nparam; j++)
		{
			if (TS_funcao[i].parametro[j].nome == nome )
			{
				if (t != NULL)
				{
					*t = TS_funcao[i].parametro[j].t;
				}
				return true;
			}
		}
		return false;
	}
}

bool pode_inserir_varlocal (string nome)
{
	if (nvarlocal > MAX_VAR)
	{
		erro("Numero de variaveis maximo atingido.");
	}
	if (busca_varlocal(nome, NULL) )
	{
		erro("Variavel ja definida.");
	}
	return true;
}

void insere_varlocal (string nome, tipo t)
{
	if (pode_inserir_varlocal(nome) )
	{
		TS_varlocal[nvarlocal].nome = nome;
		TS_varlocal[nvarlocal].t = t;
		nvarlocal++;
	}
	else
	{
		erro("Nao foi possivel declarar a variavel local" +  nome + ".");
	}
}

void yyerror (const char * st)
{
	printf("%s\n", st);
}

void erro(string msg)
{
	cout << msg << endl;
	exit(-1);
}

string inttostr(int n)
{
	char linha[20];
	sprintf(linha, "%d", n);
	return linha;
}

int strtoint(string s)
{
	int n;
	sscanf(s.c_str(), "%d", &n);
	return n;
}

void tipo_resultado(string operador, atributos op1, atributos op2, atributos &resultado)
{
	int i;
	for(i = 0; i < MAX_OPERADORES; i++)
	{
		if (tipo_operador[i].operador == operador && op1.t.tipo_base == tipo_operador[i].op1 && op2.t.tipo_base == tipo_operador[i].op2)
		{
					resultado.t.tipo_base = tipo_operador[i].resultado;
					return;
		}
	}
	resultado.t.tipo_base = "ERRO";
}

string gera_decl_temp(string tipo, string tipo_base, int &n)
{
	string c;
	int i;
	for (i = 0; i < n; i++)
	{
		if(tipo_base == "S")
		{
			c += tipo + " " + "T" + tipo_base +  inttostr(i) + "[256];\n";
		}
		else
		{
			c += tipo + " " + "T" + tipo_base +  inttostr(i) + ";\n";
		}
	}
	n = 0;
	return c;
}

string gera_varglobal_temp()
{
	int i, aux;
	string c;

	for (i = 0; i < nvarglobal; i++)
	{
		if (TS_varglobal[i].t.tipo_base == "B" || TS_varglobal[i].t.tipo_base == "I")
		{
			c += "int " + TS_varglobal[i].nome + parte_vetor(TS_varglobal[i].t) + ";\n";
		}
		else if (TS_varglobal[i].t.tipo_base == "S" )
		{
			c += "char " + TS_varglobal[i].nome + parte_vetor(TS_varglobal[i].t) + ";\n";
		}
		else if (TS_varglobal[i].t.tipo_base == "C" )
		{
			c+= "char " + TS_varglobal[i].nome +  parte_vetor(TS_varglobal[i].t) + ";\n";
		}
		else if (TS_varglobal[i].t.tipo_base == "R" )
		{
			c+= "float " + TS_varglobal[i].nome + parte_vetor(TS_varglobal[i].t) +";\n";
		}
		else
		{
			erro("Erro na gramatica");
		}
	}

	c += gera_decl_temp("int", "I", ntemp_global.i);
	c += gera_decl_temp("float", "R", ntemp_global.r);
	c += gera_decl_temp("int", "B", ntemp_global.b);

	aux = ntemp_global.s;
	c += gera_decl_temp("char", "S", ntemp_global.s);

	for (i = 0; i < aux; i++)
	{
		c += "TS" + inttostr(i) + "[255] = '\\0';\n";
	}
	
	return c;
}

bool compara_parametros(string nome, string parametros)
{
	int i;
	for(i = 0; i < nfuncao; i++)
	{
		if (TS_funcao[i].nome == nome && TS_funcao[i].lista_parametros == parametros)
		{
			return true;
		}
	}
	
	erro("Parametros invalidos.");
	return false;
}

bool compara_resultado(string resultado)
{
	if (TS_funcao[nfuncao - 1].retorno.tipo_base == resultado)
	{
		return true;
	}
	else
	{
		erro("Valor retornado invalido");
		cout << nvarlocal << endl;
	}
}

void gera_codigo_operador(atributos &ss, atributos &s1, atributos &s2, atributos &s3)
{
	tipo_resultado(s2.v,s1,s3,ss);
	if (ss.t.tipo_base == "ERRO")
	{
		if(s1.t.tipo_base == "")
		{
			erro("'" + s1.v + "'" + " nao foi declarada.");
		}
		else if (s3.t.tipo_base == "")
		{
			erro("'" + s3.v + "'" + " nao foi declarada.");
		}
		else
		{
			erro("O operador " + s2.v + " nao se aplica a " + s1.t.tipo_base + " e " + s3.t.tipo_base + ".");
		}
	}
	else
	{
		if (s2.v == "=")
		{
			if (s3.t.ndim != 0)
			{
				string aux = gera_temp(s3.t.tipo_base);
				ss.c = s1.c + s3.c + aux + " = " + s3.v + ";\n"+  s1.v + " = " + aux + ";\n";

				if (s1.t.tipo_base == "S")
				{
				        string aux = gera_temp(s1.t.tipo_base);
					ss.c = s1.c + s3.c;
					if (s1.t.ndim != 0)
					{
						ss.c += "strncpy(" + aux + ", &" + s3.v + ", 256);\n";
						ss.c += "strncpy(&" + s1.v+", " + aux + ", 256);\n";
					}
					else
					{
						ss.c += "strncpy(" + aux + ", &" + s3.v + ", 256);\n";
						ss.c += "strncpy(" + s1.v + "," + aux + ", 256);\n";
					}
				}
			}
			else
			{
				if (s3.t.tipo_base == "S")
				{
					string aux = gera_temp(s3.t.tipo_base);
					ss.c = s1.c + s3.c + "strncpy(" + aux + "," + s3.v + ", 256);\n";
					if (s1.t.ndim != 0)
					{
						ss.c += "strncpy(&" + s1.v + ", " + aux + ", 256);\n";
					}
					else
					{
						ss.c += "strncpy(" + s1.v + ", " + aux + ", 256);\n";
					}
				}
				else
				{
					ss.c = s1.c + s3.c + s1.v + " = " + s3.v + ";\n";
				}
			}
		}
		else
		{
			if ((s1.t.ndim != 0) && (s3.t.ndim != 0))
			{
				ss.v = gera_temp(ss.t.tipo_base);
				string aux1 = gera_temp(s3.t.tipo_base);
				string aux2 = gera_temp(s3.t.tipo_base);
				ss.c = s1.c + s3.c + aux1 + " = " + s1.v + ";\n" + aux2 + " = " + s3.v + ";\n"+ ss.v + " = " + aux1 + s2.v + aux2 + ";\n"; 
			}
			else if (s1.t.ndim != 0)
			{
				ss.v = gera_temp(ss.t.tipo_base);
				string aux1 = gera_temp(s1.t.tipo_base);
				ss.c = s1.c + s3.c + aux1 + " = " + s1.v + ";\n" + ss.v + " = " + aux1 + s2.v + s3.v + ";\n";
			}
			else if (s3.t.ndim != 0)
			{
				ss.v = gera_temp(ss.t.tipo_base);
				string aux1 = gera_temp(s3.t.tipo_base);
				ss.c = s1.c + s3.c + aux1 + " = " + s3.v + ";\n" + ss.v + " = " + s1.v + s2.v + aux1 + ";\n";
			}
			else
			{
				if (( s1.t.tipo_base == "S") || ( s3.t.tipo_base == "S"))
				{
					if (s2.v == "+")
					{
						ss.v = gera_temp(ss.t.tipo_base);
						ss.c = s1.c + s3.c + "strncpy(" + ss.v + "," + s1.v + ",256);\n" + "strcat(" + ss.v + "," + s3.v + ");\n";
						ss.t.tipo_base = "S";
					}
				}
				else
				{
					ss.v = gera_temp(ss.t.tipo_base);
					ss.c = s1.c + s3.c + ss.v + " = " + s1.v + s2.v + s3.v + ";\n";
				}
			}
		}
	}
}

bool busca_varglobal (string nome, tipo *t)
{
	int i;
	for(i = 0; i < nvarglobal; i++)
	{
		if(TS_varglobal[i].nome == nome)
		{
			if (t != NULL)
			{
				*t = TS_varglobal[i].t;
			}
			return true;
		}
	}
	return false;
}

bool pode_inserir_varglobal (string nome)
{
	if (nvarglobal > MAX_VAR)
	{
		erro("Numero de variaveis globais maximo atingido.");
	}
	
	if (busca_varglobal(nome, NULL))
	{
		erro("Variavel global ja definida.");
	}

	return true;
}

void insere_varglobal (string nome, tipo t)
{
	if (pode_inserir_varglobal(nome))
	{
		TS_varglobal[nvarglobal].nome = nome;
		TS_varglobal[nvarglobal].t = t;
		nvarglobal++;
	}
	else
	{
		erro("Nao foi possivel declarar a variavel global" +  nome + ".");
	}
}

bool busca_varlocal (string nome, tipo *t)
{
	int i;
	for(i = 0 ; i < nvarlocal; i++)
	{
		if(TS_varlocal[i].nome == nome)
		{
			if (t != NULL)
			{
				*t = TS_varlocal[i].t;
			}
			return true;
		}
	}
	return false;
}

string gera_rotulo()
{
	char rotulo[200];

	sprintf(rotulo,"ROT%d", nrotulos++);

	return rotulo;
}

string gera_varlocal_temp()
{
	int i, aux;
	string c;

	for (i = 0; i < nvarlocal; i++)
	{

		if (TS_varlocal[i].t.tipo_base == "B" || TS_varlocal[i].t.tipo_base == "I")
		{
			c += "int " + TS_varlocal[i].nome + parte_vetor(TS_varlocal[i].t) + ";\n";
		}
		else if (TS_varlocal[i].t.tipo_base == "S" )
		{
			c += "char " + TS_varlocal[i].nome + parte_vetor(TS_varlocal[i].t) + ";\n";
		}
		else if (TS_varlocal[i].t.tipo_base == "C" )
		{
			c+= "char " + TS_varlocal[i].nome + parte_vetor(TS_varlocal[i].t) + ";\n";
		}
		else if (TS_varlocal[i].t.tipo_base == "R" )
		{
			c+= "float " + TS_varlocal[i].nome + parte_vetor(TS_varlocal[i].t) + ";\n";
		}
		else
		{
			erro("Erro na gramatica");
		}

	}

	c += gera_decl_temp("int", "I", ntemp.i);
	c += gera_decl_temp("float", "R", ntemp.r);
	c += gera_decl_temp("int", "B", ntemp.b);
	
	aux = ntemp.s;
	c += gera_decl_temp("char", "S", ntemp.s);
	
	for (i = 0; i < aux; i++)
	{
		c += "TS" + inttostr(i) + "[255] = '\\0';\n";
	}
	
	nvarlocal = 0;
	
	c+= inic;
	inic = "";
	
	return c;
}

string parte_vetor(tipo t)
{
	string codigo;

	int ehString = 1;

	if(t.tipo_base == "S")
	{
		ehString = 256;
	}

	if (t.ndim == 0)
	{
		if(ehString == 1)
		{
			codigo = "";
		}
		else
		{
			codigo = "[256]";
		}
	}
	else if (t.ndim == 1)
	{
		codigo = "[" + inttostr(t.dim[0].fim * ehString) + "]";

	}
	else if (t.ndim == 2)
	{
		codigo = "[" + inttostr(t.dim[0].fim * t.dim[1].fim * ehString ) + "]";
	}
	return codigo;
}

string quebra_codigo_lista(string vetorid, string lsttemp , string lstcodtemp)
{
	string saida;
	string a;
	string b;

	int i = 0;
	int j = 0;
	int contador = 0;
	
	getchar();
	
	while(1)
	{
		a = "";
		b = "";
		
		while(lsttemp[i] != '#' && lsttemp[i] != '\0')
		{
			a += lsttemp[i];
			i++;
		}
		
		while(lstcodtemp[j] != '#' && lstcodtemp[j] != '\0')
		{
			b += lstcodtemp[j];
			j++;
		}

		if (a[0] != '\0' || b[0] != '\0')
		{
			saida += b  + vetorid + "[" + inttostr(contador)+ "]" + "=" + a + ";\n";
			contador++;
		}

		if (lstcodtemp[j] == '\0')
		{
			break;
		}
		i++;
		j++;

	}
	return saida;
}

string quebra_codigo_parametro(string nometemp, string vetorid, string lsttemp, string lstcodtemp, string tiporet)
{
	string saida;
	string a;
	string b;
	string lista;
	string lista_completa;

	int i = 0, j = 0, contador = 0;

	getchar();

	while(1)
	{
		a = "";
		b = "";

		while (lsttemp[i] != '#' && lsttemp[i] != '\0')
		{
			a += lsttemp[i];
			i++;
		}

		while (lstcodtemp[j] != '#' && lstcodtemp[j] != '\0')
		{
			b += lstcodtemp[j];
			j++;
		}

		if(a[0] != '\0' || b[0] != '\0')
		{
			saida += b;
			if (a != "")
			{
				lista += a + ", ";
			}
			contador++;
		}

		if (lstcodtemp[j] == '\0')
		{
			break;
		}
		i++;
		j++;
	}
	

	if(tiporet != "V")
	{
		lista_completa = vetorid + "(" + lista + nometemp + ");\n";
		saida+= lista_completa;
		return saida;
	}
	else
	{

		int len = lista.length();
		lista[len - 2] = ' ';
		string saida = vetorid + "("+  lista + ");\n";
		return saida;
	}

}

