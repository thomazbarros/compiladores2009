#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif
#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define yyclearin (yychar=(-1))
#define yyerrok (yyerrflag=0)
#define YYRECOVERING (yyerrflag!=0)
#define YYPREFIX "yy"
#line 2 "trabalho.y"

#include <string>
#include <iostream>
#include "simbolos.cpp"

using namespace std;

#define YYSTYPE atributo

atributo vazio={"","",""};

#line 24 "y.tab.c"
#define TK_ID 257
#define TK_NUM 258
#define TK_REAL 259
#define TK_CHAR 260
#define TK_STRING 261
#define TK_BOOL 262
#define TK_VAR_INT 263
#define TK_VAR_REAL 264
#define TK_VAR_CHAR 265
#define TK_VAR_STRING 266
#define TK_VAR_BOOL 267
#define TK_VAR_VOID 268
#define TK_OP_SOMA 269
#define TK_OP_SUB 270
#define TK_OP_MULT 271
#define TK_OP_DIV 272
#define TK_OP_REST 273
#define TK_OP_DIVINT 274
#define TK_AT_IGUAL 275
#define TK_CMP_IGUAL 276
#define TK_CMP_DIF 277
#define TK_CMP_MAIOR 278
#define TK_CMP_MAIORIG 279
#define TK_CMP_MENOR 280
#define TK_CMP_MENORIG 281
#define TK_LOG_E 282
#define TK_LOG_OU 283
#define TK_LOG_NOT 284
#define TK_FUNC_PRINC 285
#define TK_FUNC_IF 286
#define TK_FUNC_ELSE 287
#define TK_FUNC_FOR 288
#define TK_FUNC_START 289
#define TK_FUNC_END 290
#define TK_FUNC_WHILE 291
#define TK_FUNC_FUNC 292
#define TK_FUNC_PROT 293
#define TK_FUNC_RETURN 294
#define TK_FUNC_ENT 295
#define TK_FUNC_SAIDA 296
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    1,    2,    2,    5,    6,    6,    6,    8,    8,
    8,    8,    8,    9,   10,    7,    7,   11,   12,   12,
    3,    3,   14,   15,   15,   18,   18,   19,   19,   20,
   21,   21,   16,   16,   17,   17,   22,   22,   22,   22,
   22,   22,   22,   22,   28,   29,   30,   30,   32,   33,
   33,   27,   27,   23,   23,   23,   24,   24,   25,   26,
   34,   35,   35,   35,   35,   35,   35,    4,   36,   31,
   31,   31,   37,   37,   37,   37,   37,   38,   38,   38,
   38,   39,   39,   40,   40,   40,   40,   40,   40,   13,
   13,   13,   13,   13,
};
short yylen[] = {                                         2,
    4,    0,    3,    0,    2,    1,    1,    1,    1,    1,
    1,    1,    1,    4,    7,    4,    2,    1,    2,    0,
    2,    0,    6,    4,    3,    2,    2,    3,    1,    3,
    1,    0,    3,    0,    2,    0,    1,    1,    1,    1,
    1,    1,    1,    2,    3,    3,    4,    3,    1,    3,
    1,    3,    2,    4,    7,   10,    7,   11,   13,    7,
    1,    1,    1,    1,    1,    1,    1,    6,    0,    3,
    3,    1,    3,    3,    3,    3,    1,    3,    3,    2,
    1,    3,    1,    1,    4,    7,    3,    1,    1,    1,
    1,    1,    1,    1,
};
short yydefred[] = {                                      2,
    0,    0,    9,   10,   11,   12,   13,    0,    0,    0,
    0,    7,    8,    0,    0,    0,    0,   18,    5,    0,
    0,    0,    0,    0,    0,    0,    1,   21,    3,    0,
    0,    0,   27,   26,    0,    0,   69,   91,   90,   93,
   94,   92,   19,    0,    0,    0,    0,   25,    0,    0,
    0,    0,   16,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   37,   38,   39,   40,   41,   42,
   43,    0,    0,   31,    0,   24,    0,    0,    0,   33,
    0,    0,    0,    0,    0,    0,    0,   53,    0,   89,
   88,    0,    0,    0,   81,    0,    0,    0,   23,   35,
   44,    0,   30,   28,    0,   15,    0,    0,    0,    0,
    0,    0,    0,   80,    0,    0,    0,   52,    0,    0,
    0,    0,    0,    0,   62,   63,   64,   65,   66,   67,
    0,   45,   46,   48,    0,    0,   68,   54,    0,    0,
    0,    0,    0,   87,    0,    0,    0,    0,    0,    0,
   79,   78,   82,    0,   47,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   55,    0,
    0,    0,   60,    0,    0,    0,    0,   86,    0,    0,
    0,   56,    0,    0,   58,    0,    0,   59,
};
short yydgoto[] = {                                       1,
    2,    8,   15,   27,   46,   10,   19,   11,   12,   13,
   20,   31,   90,   16,   24,   47,   63,   25,   50,   51,
   75,   64,   65,   66,   67,   68,   69,   70,   71,   91,
  109,   73,  136,  110,  131,   52,   93,   94,   95,   96,
};
short yysindex[] = {                                      0,
    0, -210,    0,    0,    0,    0,    0, -282,  -26, -218,
  -41,    0,    0,  -64, -223, -282, -210,    0,    0, -209,
 -190, -179, -175, -201,   50, -191,    0,    0,    0, -187,
   56,    9,    0,    0, -210,   63,    0,    0,    0,    0,
    0,    0,    0, -218,   15,   53, -114,    0,   80,   87,
   86, -210,    0, -122, -210,  -89,   97,   98,   99,  -40,
 -117,  -28, -148, -114,    0,    0,    0,    0,    0,    0,
    0,   85,  106,    0, -107,    0, -210, -114,   59,    0,
  -28,  -28,  -28, -102,  -28,   65,   75,    0,  -28,    0,
    0,  -58, -163, -166,    0,  -71,  101,  -56,    0,    0,
    0,  -34,    0,    0, -128,    0,  -54,  -80, -143,  123,
 -100,  127,  -28,    0,  -27,  -28,  -28,    0,  -28,  -28,
  -28,  -28,   75,   75,    0,    0,    0,    0,    0,    0,
   75,    0,    0,    0, -143,   -3,    0,    0,  -87, -113,
  -79, -111,  -78,    0, -163, -163, -166, -166, -166, -166,
    0,    0,    0,  -28,    0,  -28,  -28, -114,  125, -114,
   93, -143,  -22,  -75, -105,  -62, -103,  -28,    0,  -82,
  -52,  190,    0,  -72,  -28,  -38,   21,    0,  -15, -114,
  222,    0,  -18,   -1,    0, -114,   11,    0,
};
short yyrindex[] = {                                      0,
    0, -249,    0,    0,    0,    0,    0,   19,    0,    0,
   66,    0,    0,    0,    0,   19, -249,    0,    0,  -19,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -26,    0,    0,    0, -137,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   74,    0,   49,    0,   84,    0,
  301, -137,    0,    0, -137,  303,    0,    0,    0,    0,
    0,    0,    0,   49,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   49,    0,    0,
    0,    0,    0,    0,    0,  -12,    0,    0,    0,    0,
    0,    0,  -24,  -33,    0,   20,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  304,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    5,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -17,   55,   26,   36,   42,   48,
    0,    0,    0,    0,    0,    0,    0,   49,    0,   49,
    4,   43,    0,    0,    0,    0,    0,    0,    0,    0,
 -125,    0,    0,    0,    0,    0,    0,    0,    0,   49,
    0,    0,    0,    0,    0,   49,    0,    0,
};
short yygindex[] = {                                      0,
    0,  327,  330,    0,   14,    0,  305,   16,    0,    0,
    0,    0,  317,    0,    0,   39,  -55,    0,  271,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -13,
  278,    0,    0,  265,    0,    0,   17,    2,  -65,  220,
};
#define YYTABLESIZE 453
short yytable[] = {                                      89,
  118,   82,  133,  157,  138,   89,  134,   77,  100,   14,
   77,   89,  139,  144,  161,    9,   72,  170,   88,   72,
  178,  114,  105,   70,   20,   77,   70,   49,   84,   23,
    9,   84,   17,   72,   72,    4,  169,  155,   18,   20,
  154,   70,    4,  182,   85,   51,   84,   85,   51,   21,
   72,   49,    3,    4,    5,    6,    7,  151,  152,   77,
   83,   26,   85,   83,   72,   30,   73,   32,   72,   73,
   38,   39,   40,   41,   42,   70,   74,   33,   83,   74,
   84,   34,   75,   50,   73,   75,   50,   35,   76,   36,
   78,   76,   49,   80,   74,   71,   85,   37,   71,   44,
   75,   45,  165,   48,  167,   54,   76,  119,  120,  121,
  122,   55,   83,   71,   89,  123,  124,   74,   73,   34,
  147,  148,  149,  150,  183,  116,  117,   76,   74,   77,
  187,   57,  145,  146,   75,   79,   83,   84,   85,   97,
   76,   99,   56,  101,   72,  102,   72,   71,   34,  103,
   34,  106,   34,   34,  111,  113,   34,   34,   34,  132,
   57,  137,   57,  140,   57,   57,   72,  142,   57,   57,
   57,   57,   72,   58,  141,  158,   59,  160,  159,   60,
   61,   62,  166,  168,  171,   81,  173,  156,  116,  117,
  116,  117,  175,  116,  117,  172,  116,  117,    3,    4,
    5,    6,    7,   22,  125,  126,  127,  128,  129,  130,
  116,  117,  116,  117,  116,  117,   86,   38,   39,   40,
   41,   42,   86,   38,   39,   40,   41,   42,   86,   38,
   39,   40,   41,   42,  176,   77,   77,   77,   77,   77,
   77,  116,  117,   87,   72,   72,  116,  117,  177,   87,
  180,   70,   70,  116,  117,   87,   84,   84,   84,   84,
   84,   84,  184,   84,   84,   84,   84,   84,   84,   84,
   84,  185,   85,   85,   85,   85,   85,   85,  181,   85,
   85,   85,   85,   85,   85,   85,   85,  186,   83,   83,
   83,   83,   83,   83,   73,   73,   73,   73,   73,   73,
  188,   83,   83,   22,   74,   74,   74,   74,   74,   74,
   75,   75,   75,   75,   75,   75,   76,   76,   76,   76,
   76,   76,    6,   71,   71,    3,    4,    5,    6,    7,
   14,   86,   38,   39,   40,   41,   42,   92,   36,   98,
   32,   29,   49,   29,   61,   28,   43,  104,   53,  112,
  153,    0,    0,    0,    0,    0,    0,    0,  107,  108,
    0,    0,    0,    0,    0,    0,  115,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  135,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  143,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  162,    0,  163,  164,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  174,    0,    0,    0,    0,
    0,    0,  179,
};
short yycheck[] = {                                      40,
   59,   91,   59,   91,   59,   40,   41,   41,   64,  292,
   44,   40,   93,   41,   93,    2,   41,   93,   59,   44,
   93,   87,   78,   41,   44,   59,   44,   40,   41,   14,
   17,   44,   59,   47,   59,  285,   59,   41,  257,   59,
   44,   59,  292,   59,   41,   41,   59,   44,   44,   91,
   64,   36,  263,  264,  265,  266,  267,  123,  124,   93,
   41,  285,   59,   44,   78,  275,   41,  258,   93,   44,
  258,  259,  260,  261,  262,   93,   41,  257,   59,   44,
   93,  257,   41,   41,   59,   44,   44,  289,   41,   40,
   52,   44,   77,   55,   59,   41,   93,  289,   44,   44,
   59,   93,  158,   41,  160,   91,   59,  271,  272,  273,
  274,   59,   93,   59,   40,  282,  283,   38,   93,  257,
  119,  120,  121,  122,  180,  269,  270,   41,   93,   44,
  186,  257,  116,  117,   93,  258,   40,   40,   40,  257,
   93,  290,  257,   59,  158,   40,  160,   93,  286,  257,
  288,   93,  290,  291,  257,   91,  294,  295,  296,   59,
  286,  290,  288,   41,  290,  291,  180,   41,  294,  295,
  296,  286,  186,  288,  275,  289,  291,  289,  258,  294,
  295,  296,   58,   91,  290,  275,  290,  275,  269,  270,
  269,  270,  275,  269,  270,  258,  269,  270,  263,  264,
  265,  266,  267,  268,  276,  277,  278,  279,  280,  281,
  269,  270,  269,  270,  269,  270,  257,  258,  259,  260,
  261,  262,  257,  258,  259,  260,  261,  262,  257,  258,
  259,  260,  261,  262,  287,  269,  270,  271,  272,  273,
  274,  269,  270,  284,  269,  270,  269,  270,   59,  284,
  289,  269,  270,  269,  270,  284,  269,  270,  271,  272,
  273,  274,   41,  276,  277,  278,  279,  280,  281,  282,
  283,  290,  269,  270,  271,  272,  273,  274,  258,  276,
  277,  278,  279,  280,  281,  282,  283,  289,  269,  270,
  271,  272,  273,  274,  269,  270,  271,  272,  273,  274,
  290,  282,  283,  285,  269,  270,  271,  272,  273,  274,
  269,  270,  271,  272,  273,  274,  269,  270,  271,  272,
  273,  274,  257,  269,  270,  263,  264,  265,  266,  267,
  257,  257,  258,  259,  260,  261,  262,   60,  290,   62,
  257,   41,   40,   17,   41,   16,   30,   77,   44,   85,
  131,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   81,   82,
   -1,   -1,   -1,   -1,   -1,   -1,   89,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  102,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  113,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  154,   -1,  156,  157,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  168,   -1,   -1,   -1,   -1,
   -1,   -1,  175,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 296
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,"'&'",0,"'('","')'",0,0,"','",0,0,0,0,0,0,0,0,0,0,0,0,0,"':'","';'",0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"TK_ID","TK_NUM","TK_REAL","TK_CHAR","TK_STRING","TK_BOOL","TK_VAR_INT",
"TK_VAR_REAL","TK_VAR_CHAR","TK_VAR_STRING","TK_VAR_BOOL","TK_VAR_VOID",
"TK_OP_SOMA","TK_OP_SUB","TK_OP_MULT","TK_OP_DIV","TK_OP_REST","TK_OP_DIVINT",
"TK_AT_IGUAL","TK_CMP_IGUAL","TK_CMP_DIF","TK_CMP_MAIOR","TK_CMP_MAIORIG",
"TK_CMP_MENOR","TK_CMP_MENORIG","TK_LOG_E","TK_LOG_OU","TK_LOG_NOT",
"TK_FUNC_PRINC","TK_FUNC_IF","TK_FUNC_ELSE","TK_FUNC_FOR","TK_FUNC_START",
"TK_FUNC_END","TK_FUNC_WHILE","TK_FUNC_FUNC","TK_FUNC_PROT","TK_FUNC_RETURN",
"TK_FUNC_ENT","TK_FUNC_SAIDA",
};
char *yyrule[] = {
"$accept : PROGRAMA",
"PROGRAMA : AUX_PROGRAMA VAR_GLOBAL FUNCOES PRINCIPAL",
"AUX_PROGRAMA :",
"VAR_GLOBAL : VAR ';' VAR_GLOBAL",
"VAR_GLOBAL :",
"VAR : TIPO LISTA_ID",
"TIPO : TIPO_SIMPLES",
"TIPO : VETOR",
"TIPO : MATRIZ",
"TIPO_SIMPLES : TK_VAR_INT",
"TIPO_SIMPLES : TK_VAR_REAL",
"TIPO_SIMPLES : TK_VAR_CHAR",
"TIPO_SIMPLES : TK_VAR_STRING",
"TIPO_SIMPLES : TK_VAR_BOOL",
"VETOR : TIPO_SIMPLES '[' TK_NUM ']'",
"MATRIZ : TIPO_SIMPLES '[' TK_NUM ']' '[' TK_NUM ']'",
"LISTA_ID : AUX_LISTA_ID AT ',' LISTA_ID",
"LISTA_ID : AUX_LISTA_ID AT",
"AUX_LISTA_ID : TK_ID",
"AT : TK_AT_IGUAL G",
"AT :",
"FUNCOES : FUNC FUNCOES",
"FUNCOES :",
"FUNC : TK_FUNC_FUNC CABECALHO_F TK_FUNC_START VAR_LOCAL COMANDOS TK_FUNC_END",
"CABECALHO_F : AUX_CABECALHO '(' PARAMETROS_F ')'",
"CABECALHO_F : AUX_CABECALHO '(' ')'",
"AUX_CABECALHO : TIPO_SIMPLES TK_ID",
"AUX_CABECALHO : TK_VAR_VOID TK_ID",
"PARAMETROS_F : PARAM_F ',' PARAMETROS_F",
"PARAMETROS_F : PARAM_F",
"PARAM_F : TIPO_SIMPLES REF TK_ID",
"REF : '&'",
"REF :",
"VAR_LOCAL : VAR ';' VAR_LOCAL",
"VAR_LOCAL :",
"COMANDOS : CMD COMANDOS",
"COMANDOS :",
"CMD : CMD_ATRIB",
"CMD : CMD_IF",
"CMD : CMD_FOR",
"CMD : CMD_WHILE",
"CMD : CMD_RETURN",
"CMD : CMD_ENTRADA",
"CMD : CMD_SAIDA",
"CMD : CMD_FUNC ';'",
"CMD_ENTRADA : TK_FUNC_ENT TK_ID ';'",
"CMD_SAIDA : TK_FUNC_SAIDA E ';'",
"CMD_FUNC : AUX_CMD_FUNC '(' PARAMETROS_C ')'",
"CMD_FUNC : AUX_CMD_FUNC '(' ')'",
"AUX_CMD_FUNC : TK_ID",
"PARAMETROS_C : PARAMETROS_C ',' E",
"PARAMETROS_C : E",
"CMD_RETURN : TK_FUNC_RETURN E ';'",
"CMD_RETURN : TK_FUNC_RETURN ';'",
"CMD_ATRIB : TK_ID TK_AT_IGUAL E ';'",
"CMD_ATRIB : TK_ID '[' E ']' TK_AT_IGUAL E ';'",
"CMD_ATRIB : TK_ID '[' E ']' '[' E ']' TK_AT_IGUAL E ';'",
"CMD_IF : TK_FUNC_IF '(' VERIFICA ')' TK_FUNC_START COMANDOS TK_FUNC_END",
"CMD_IF : TK_FUNC_IF '(' VERIFICA ')' TK_FUNC_START COMANDOS TK_FUNC_END TK_FUNC_ELSE TK_FUNC_START COMANDOS TK_FUNC_END",
"CMD_FOR : TK_FUNC_FOR '(' TK_ID TK_AT_IGUAL TK_NUM ':' TK_NUM ';' TK_NUM ')' TK_FUNC_START COMANDOS TK_FUNC_END",
"CMD_WHILE : TK_FUNC_WHILE '(' VERIFICA ')' TK_FUNC_START COMANDOS TK_FUNC_END",
"VERIFICA : E",
"CMP : TK_CMP_IGUAL",
"CMP : TK_CMP_DIF",
"CMP : TK_CMP_MAIOR",
"CMP : TK_CMP_MAIORIG",
"CMP : TK_CMP_MENOR",
"CMP : TK_CMP_MENORIG",
"PRINCIPAL : TK_FUNC_PRINC TK_FUNC_START AUX_PRINCIPAL VAR_LOCAL COMANDOS TK_FUNC_END",
"AUX_PRINCIPAL :",
"E : E TK_OP_SOMA T",
"E : E TK_OP_SUB T",
"E : T",
"T : T TK_OP_MULT V",
"T : T TK_OP_DIV V",
"T : T TK_OP_REST V",
"T : T TK_OP_DIVINT V",
"T : V",
"V : V TK_LOG_OU X",
"V : V TK_LOG_E X",
"V : TK_LOG_NOT X",
"V : X",
"X : F CMP F",
"X : F",
"F : TK_ID",
"F : TK_ID '[' E ']'",
"F : TK_ID '[' E ']' '[' E ']'",
"F : '(' E ')'",
"F : CMD_FUNC",
"F : G",
"G : TK_REAL",
"G : TK_NUM",
"G : TK_BOOL",
"G : TK_CHAR",
"G : TK_STRING",
};
#endif
#ifndef YYSTYPE
typedef int YYSTYPE;
#endif
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH 500
#endif
#endif
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short yyss[YYSTACKSIZE];
YYSTYPE yyvs[YYSTACKSIZE];
#define yystacksize YYSTACKSIZE
#line 522 "trabalho.y"
#include "lex.yy.c"

int yyparse();

void yyerror( const char* st )
{
	puts( st );
}

int main( int argc, char* argv[] )
{
	yyparse();
}




#line 426 "y.tab.c"
#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse()
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register char *yys;
    extern char *getenv();

    if (yys = getenv("YYDEBUG"))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if (yyn = yydefred[yystate]) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yyss + yystacksize - 1)
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;
#ifdef lint
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#ifdef lint
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yyss + yystacksize - 1)
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
case 1:
#line 26 "trabalho.y"
{
	yyval.c=yyvsp[-2].c+TEMP_CODIGO+yyvsp[-1].c+yyvsp[0].c;
	cout << yyval.c;
}
break;
case 2:
#line 34 "trabalho.y"
{
	ID_NOVO.func="";
}
break;
case 3:
#line 40 "trabalho.y"
{yyval.c=yyvsp[-2].c+yyvsp[0].c;}
break;
case 4:
#line 41 "trabalho.y"
{yyval.c="";}
break;
case 5:
#line 45 "trabalho.y"
{yyval.c=yyvsp[0].c;}
break;
case 6:
#line 50 "trabalho.y"
{
	ID_NOVO.tipo=yyvsp[0].v;
	ID_NOVO.n_dim=0;
	ID_NOVO.xsize=0;
	ID_NOVO.ysize=0;
}
break;
case 9:
#line 61 "trabalho.y"
{yyval=yyvsp[0];}
break;
case 10:
#line 62 "trabalho.y"
{yyval=yyvsp[0];}
break;
case 11:
#line 63 "trabalho.y"
{yyval=yyvsp[0];}
break;
case 12:
#line 64 "trabalho.y"
{yyval=yyvsp[0];}
break;
case 13:
#line 65 "trabalho.y"
{yyval=yyvsp[0];}
break;
case 14:
#line 70 "trabalho.y"
{
	ID_NOVO.tipo=yyvsp[-3].v;
	ID_NOVO.n_dim=1;
	ID_NOVO.xsize=strtoint(yyvsp[-1].v);
	ID_NOVO.ysize=0;
}
break;
case 15:
#line 80 "trabalho.y"
{
	ID_NOVO.tipo=yyvsp[-6].v;
	ID_NOVO.n_dim=2;
	ID_NOVO.xsize=strtoint(yyvsp[-4].v);
	ID_NOVO.ysize=strtoint(yyvsp[-1].v);
}
break;
case 16:
#line 90 "trabalho.y"
{
	string temp;
	insere_tipo_dimX (yyvsp[-3].v,ID_NOVO.tipo,ID_NOVO.n_dim,ID_NOVO.xsize,ID_NOVO.ysize,ID_NOVO.func);
	if (ID_NOVO.n_dim==0) temp=gera_codigo("VAR",ID_NOVO.tipo,yyvsp[-3].v);
	else if (ID_NOVO.n_dim==1) temp=gera_codigo("VAR",ID_NOVO.tipo+"[]",yyvsp[-3].v,inttostr(ID_NOVO.xsize));
	else if (ID_NOVO.n_dim==2) temp=gera_codigo("VAR",ID_NOVO.tipo+"[]",yyvsp[-3].v,inttostr(ID_NOVO.xsize*ID_NOVO.ysize));
	yyval.c=temp+yyvsp[-2].c+yyvsp[0].c;
}
break;
case 17:
#line 99 "trabalho.y"
{
	string temp;
	insere_tipo_dimX (yyvsp[-1].v,ID_NOVO.tipo,ID_NOVO.n_dim,ID_NOVO.xsize,ID_NOVO.ysize,ID_NOVO.func);
	if (ID_NOVO.n_dim==0) temp=gera_codigo("VAR",ID_NOVO.tipo,yyvsp[-1].v);
	else if (ID_NOVO.n_dim==1) temp=gera_codigo("VAR",ID_NOVO.tipo+"[]",yyvsp[-1].v,inttostr(ID_NOVO.xsize));
	else if (ID_NOVO.n_dim==2) temp=gera_codigo("VAR",ID_NOVO.tipo+"[]",yyvsp[-1].v,inttostr(ID_NOVO.xsize*ID_NOVO.ysize));
	yyval.c=temp+yyvsp[0].c;
}
break;
case 18:
#line 111 "trabalho.y"
{
	yyval=yyvsp[0];
	ID_NOVO.valor=yyvsp[0].v;
}
break;
case 19:
#line 119 "trabalho.y"
{
	yyvsp[-1].v=ID_NOVO.valor;
	yyvsp[-1].t=ID_NOVO.tipo;
	yyval.c=yyvsp[0].c+gera_atribuicao("=",yyvsp[-1],yyvsp[0],vazio);
}
break;
case 20:
#line 124 "trabalho.y"
{yyval.c="";}
break;
case 21:
#line 128 "trabalho.y"
{yyval.c=yyvsp[-1].c+yyvsp[0].c;}
break;
case 22:
#line 129 "trabalho.y"
{yyval.c="";}
break;
case 23:
#line 134 "trabalho.y"
{
	int i;
	yyval.c=yyvsp[-4].c+yyvsp[-2].c+yyvsp[-1].c;
	yyval.c+=gera_codigo("ENDFUNC");
	if (!ID_NOVO.retornou)
	{
		erro("A funcao \""+ID_NOVO.func+"\" NAO retorna valor algum.");
	}
}
break;
case 24:
#line 146 "trabalho.y"
{yyval.c=yyvsp[-3].c + yyvsp[-1].c;}
break;
case 25:
#line 147 "trabalho.y"
{yyval.c=yyvsp[-2].c;}
break;
case 26:
#line 152 "trabalho.y"
{
	ID_NOVO.func=yyvsp[0].v;
	ID_NOVO.func_tipo=yyvsp[-1].t;
	ID_NOVO.retornou=false;
	insere_funcao (yyvsp[0].v,yyvsp[-1].v);
	PARAM_POSITION=1;
	yyval.c=gera_codigo("FUNC",yyvsp[-1].v,yyvsp[0].v);
}
break;
case 27:
#line 161 "trabalho.y"
{
	ID_NOVO.func=yyvsp[0].v;
	ID_NOVO.func_tipo=yyvsp[-1].t;
	ID_NOVO.retornou=true;
	insere_funcao (yyvsp[0].v,yyvsp[-1].v);
	PARAM_POSITION=1;
	yyval.c=gera_codigo("FUNC",yyvsp[0].v);
}
break;
case 28:
#line 172 "trabalho.y"
{yyval.c=yyvsp[-2].c+yyvsp[0].c;}
break;
case 29:
#line 173 "trabalho.y"
{yyval.c=yyvsp[0].c;}
break;
case 30:
#line 178 "trabalho.y"
{
	ID_NOVO.tipo=yyvsp[-2].v;
	ID_NOVO.n_dim=0;
	ID_NOVO.xsize=0;
	ID_NOVO.ysize=0;
	insere_param (yyvsp[0].v,ID_NOVO.tipo,PARAM_POSITION);
	PARAM_POSITION++;
	insere_tipo_dimX (yyvsp[0].v,ID_NOVO.tipo,ID_NOVO.n_dim,ID_NOVO.xsize,ID_NOVO.ysize,ID_NOVO.func);
	yyval.c=gera_codigo("ARG"+yyvsp[-1].v,yyvsp[-2].v,yyvsp[0].v);
}
break;
case 31:
#line 191 "trabalho.y"
{yyval.v="&";}
break;
case 32:
#line 192 "trabalho.y"
{yyval.v="";}
break;
case 33:
#line 196 "trabalho.y"
{yyval.c=yyvsp[-2].c+yyvsp[0].c;}
break;
case 34:
#line 197 "trabalho.y"
{yyval.c="";}
break;
case 35:
#line 201 "trabalho.y"
{yyval.c=yyvsp[-1].c+yyvsp[0].c;}
break;
case 36:
#line 202 "trabalho.y"
{yyval.c="";}
break;
case 37:
#line 206 "trabalho.y"
{yyval.c=yyvsp[0].c;}
break;
case 38:
#line 207 "trabalho.y"
{yyval.c=yyvsp[0].c;}
break;
case 39:
#line 208 "trabalho.y"
{yyval.c=yyvsp[0].c;}
break;
case 40:
#line 209 "trabalho.y"
{yyval.c=yyvsp[0].c;}
break;
case 41:
#line 210 "trabalho.y"
{yyval.c=yyvsp[0].c;}
break;
case 42:
#line 211 "trabalho.y"
{yyval.c=yyvsp[0].c;}
break;
case 43:
#line 212 "trabalho.y"
{yyval.c=yyvsp[0].c;}
break;
case 44:
#line 213 "trabalho.y"
{yyval.c=yyvsp[-1].c;}
break;
case 45:
#line 218 "trabalho.y"
{
	yyvsp[-1].t=busca_tipo_dim0(yyvsp[-1].v);
	yyval.c=gera_codigo("CIN",yyvsp[-1].v);
}
break;
case 46:
#line 226 "trabalho.y"
{
	yyval.c=yyvsp[-1].c+gera_codigo("COUT",yyvsp[-1].v)+gera_codigo("ENDL");
}
break;
case 47:
#line 233 "trabalho.y"
{
	yyval.c=yyvsp[-1].c+gera_codigo("CALL",FUNC_CHAMA.nome,FUNC_CHAMA.retorno);
	acabou_param (FUNC_CHAMA.nome,PARAM_POSITION);
}
break;
case 48:
#line 238 "trabalho.y"
{
	yyval.c=gera_codigo("CALL",FUNC_CHAMA.nome,FUNC_CHAMA.retorno);
	acabou_param (FUNC_CHAMA.nome,PARAM_POSITION);
}
break;
case 49:
#line 246 "trabalho.y"
{
	FUNC_CHAMA.nome=yyvsp[0].v;
	FUNC_CHAMA.tipo=busca_funcao(yyvsp[0].v);
	if (FUNC_CHAMA.tipo!="void") FUNC_CHAMA.retorno=gera_temp(FUNC_CHAMA.tipo);
	else FUNC_CHAMA.retorno="";
	PARAM_POSITION=1;
}
break;
case 50:
#line 257 "trabalho.y"
{
	busca_param(yyvsp[0].t,FUNC_CHAMA.nome,PARAM_POSITION);
	PARAM_POSITION++;
	yyval.c=yyvsp[-2].c;
	yyval.c+=yyvsp[0].c+gera_codigo("PARAM",yyvsp[0].v);
}
break;
case 51:
#line 264 "trabalho.y"
{
	busca_param(yyvsp[0].t,FUNC_CHAMA.nome,PARAM_POSITION);
	PARAM_POSITION++;
	yyval.c=yyvsp[0].c+gera_codigo("PARAM",yyvsp[0].v);
}
break;
case 52:
#line 273 "trabalho.y"
{
	if (ID_NOVO.func_tipo!="void")
	{
		yyval.c=yyvsp[-1].c+gera_codigo("RETURN",yyvsp[-1].v);
		if (busca_tipo_operacao("=",ID_NOVO.func_tipo,yyvsp[-1].t)=="")
		{
			erro("A funcao \""+ID_NOVO.func+"\" que retorna \""+ID_NOVO.func_tipo+"\" nao pode retornar \""+yyvsp[-1].t+"\".",1);
		}
		ID_NOVO.retornou=true;
	}
	else
	{
		erro("A funcao \""+ID_NOVO.func+"\" eh do tipo void e nao pode retornar um valor.",1);
	}
}
break;
case 53:
#line 289 "trabalho.y"
{
	if (ID_NOVO.func_tipo=="void") yyval.c=gera_codigo("RETURN");
	else
	{
		erro("A funcao \""+ID_NOVO.func+"\" precisa retornar algum valor (\""+ID_NOVO.func_tipo+"\" esperado).",1);
	}
}
break;
case 54:
#line 300 "trabalho.y"
{
	yyvsp[-3].t=busca_tipo_dim0(yyvsp[-3].v);
	yyval.c=yyvsp[-1].c+gera_atribuicao("=",yyvsp[-3],yyvsp[-1],vazio);
}
break;
case 55:
#line 305 "trabalho.y"
{
	yyvsp[-6].t=busca_tipo_dim1(yyvsp[-6].v);
	yyval.c=yyvsp[-4].c+yyvsp[-1].c+gera_atribuicao("[]=",yyvsp[-6],yyvsp[-4],yyvsp[-1]);
}
break;
case 56:
#line 310 "trabalho.y"
{
	int ysize;
	yyvsp[-9].t=busca_tipo_dim2(yyvsp[-9].v,ysize);
	yyvsp[-8].v="*";
	yyvsp[-5].t="int";
	yyvsp[-5].v=inttostr(ysize);
	gera_operacao(yyvsp[-6],yyvsp[-7],yyvsp[-8],yyvsp[-5]);
	yyvsp[-8].v="+";
	gera_operacao(yyvsp[-3],yyvsp[-6],yyvsp[-8],yyvsp[-4]);
	yyval.c=yyvsp[-3].c+yyvsp[-1].c+gera_atribuicao("[]=",yyvsp[-9],yyvsp[-3],yyvsp[-1]);
}
break;
case 57:
#line 325 "trabalho.y"
{
	string L1=gera_label("BEGINIF");
	string L2=gera_label("ENDIF");
	yyval.c = yyvsp[-4].c + gera_codigo("IF",yyvsp[-4].v,L1) + gera_codigo("GOTO",L2) + gera_codigo("LABEL",L1) + yyvsp[-1].c + gera_codigo("LABEL",L2);
}
break;
case 58:
#line 331 "trabalho.y"
{
	string L1=gera_label("BEGINIF");
	string L2=gera_label("ENDIF");
	yyval.c = yyvsp[-8].c + gera_codigo("IF",yyvsp[-8].v,L1) + yyvsp[-1].c + gera_codigo("GOTO",L2) + gera_codigo("LABEL",L1) + yyvsp[-5].c + gera_codigo("LABEL",L2);
}
break;
case 59:
#line 340 "trabalho.y"
{
	string L1=gera_label("BEGINFOR");
	string L2=gera_label("ENDFOR");
	string valor = gera_temp("bool");
	
	yyvsp[-10].t=busca_tipo_dim0(yyvsp[-10].v);
	
	if (strtoint(yyvsp[-8].v) <= strtoint (yyvsp[-6].v)) yyval.c = gera_atribuicao("=",yyvsp[-10],yyvsp[-8],vazio) + gera_codigo("LABEL",L1) + gera_codigo(">=",valor,yyvsp[-10].v,yyvsp[-6].v) + gera_codigo("IF",valor,L2) + yyvsp[-1].c + gera_codigo("+",yyvsp[-10].v,yyvsp[-10].v,yyvsp[-4].v) + gera_codigo("GOTO",L1) + gera_codigo("LABEL",L2);
	
	else yyval.c = gera_atribuicao("=",yyvsp[-10],yyvsp[-8],vazio) + gera_codigo("LABEL",L1) + gera_codigo("<=",valor,yyvsp[-10].v,yyvsp[-6].v) + gera_codigo("IF",valor,L2) + yyvsp[-1].c + gera_codigo("-",yyvsp[-10].v,yyvsp[-10].v,yyvsp[-4].v) + gera_codigo("GOTO",L1) + gera_codigo("LABEL",L2);
}
break;
case 60:
#line 355 "trabalho.y"
{
	string L1=gera_label("BEGINWHILE");
	string L2=gera_label("GOWHILE");
	string L3=gera_label("ENDWHILE");
	
	yyval.c = yyvsp[-4].c + gera_codigo("LABEL", L1) + gera_codigo("IF",yyvsp[-4].v,L2) + gera_codigo("GOTO",L3) + gera_codigo("LABEL", L2) + yyvsp[-1].c + gera_codigo("GOTO", L1) + gera_codigo("LABEL", L3);
}
break;
case 61:
#line 366 "trabalho.y"
{
	if (yyvsp[0].t!="bool")
	{
		erro("A condicao do IF | WHILE deve ser do tipo bool e nao \""+yyvsp[0].t+"\".",1);
	}
	yyval=yyvsp[0];
}
break;
case 62:
#line 376 "trabalho.y"
{yyval=yyvsp[0];}
break;
case 63:
#line 377 "trabalho.y"
{yyval=yyvsp[0];}
break;
case 64:
#line 378 "trabalho.y"
{yyval=yyvsp[0];}
break;
case 65:
#line 379 "trabalho.y"
{yyval=yyvsp[0];}
break;
case 66:
#line 380 "trabalho.y"
{yyval=yyvsp[0];}
break;
case 67:
#line 381 "trabalho.y"
{yyval=yyvsp[0];}
break;
case 68:
#line 386 "trabalho.y"
{
	yyval.c=yyvsp[-3].c+yyvsp[-2].c+yyvsp[-1].c;
	yyval.c+=gera_codigo("RETURN","0")+gera_codigo("ENDFUNC");
}
break;
case 69:
#line 394 "trabalho.y"
{
	ID_NOVO.func="showTime";
	yyval.c=gera_codigo("FUNC","int","main");
}
break;
case 70:
#line 403 "trabalho.y"
{
	gera_operacao(yyval,yyvsp[-2],yyvsp[-1],yyvsp[0]);
}
break;
case 71:
#line 407 "trabalho.y"
{
	gera_operacao(yyval,yyvsp[-2],yyvsp[-1],yyvsp[0]);
}
break;
case 72:
#line 411 "trabalho.y"
{
	yyval=yyvsp[0];
}
break;
case 73:
#line 418 "trabalho.y"
{
	gera_operacao(yyval,yyvsp[-2],yyvsp[-1],yyvsp[0]);
}
break;
case 74:
#line 422 "trabalho.y"
{
	gera_operacao(yyval,yyvsp[-2],yyvsp[-1],yyvsp[0]);
}
break;
case 75:
#line 426 "trabalho.y"
{
	gera_operacao(yyval,yyvsp[-2],yyvsp[-1],yyvsp[0]);
}
break;
case 76:
#line 430 "trabalho.y"
{
	gera_operacao(yyval,yyvsp[-2],yyvsp[-1],yyvsp[0]);
}
break;
case 77:
#line 434 "trabalho.y"
{
	yyval=yyvsp[0];
}
break;
case 78:
#line 441 "trabalho.y"
{
	gera_operacao(yyval,yyvsp[-2],yyvsp[-1],yyvsp[0]);
}
break;
case 79:
#line 445 "trabalho.y"
{
	gera_operacao(yyval,yyvsp[-2],yyvsp[-1],yyvsp[0]);
}
break;
case 80:
#line 449 "trabalho.y"
{
	yyval.t=busca_tipo_operacao(yyvsp[-1].v,"",yyvsp[0].t);
	yyval.v=gera_temp(yyval.t);
	yyval.c=yyvsp[0].c+gera_codigo(yyvsp[-1].v,yyval.v,yyvsp[0].v);
}
break;
case 81:
#line 455 "trabalho.y"
{
	yyval=yyvsp[0];
}
break;
case 82:
#line 462 "trabalho.y"
{
	gera_operacao(yyval,yyvsp[-2],yyvsp[-1],yyvsp[0]);
}
break;
case 83:
#line 466 "trabalho.y"
{
	yyval=yyvsp[0];
}
break;
case 84:
#line 473 "trabalho.y"
{
	yyval.t=busca_tipo_dim0(yyvsp[0].v);
	yyval.v=yyvsp[0].v;
}
break;
case 85:
#line 478 "trabalho.y"
{
	yyvsp[-3].t=busca_tipo_dim1(yyvsp[-3].v);
	yyval.t=busca_tipo_dim1(yyvsp[-3].v);
	yyval.v=gera_temp(yyval.t);
	yyval.c=yyvsp[-1].c+gera_atribuicao("=[]",yyval,yyvsp[-3],yyvsp[-1]);
}
break;
case 86:
#line 485 "trabalho.y"
{
	int ysize;
	yyvsp[-6].t=busca_tipo_dim2(yyvsp[-6].v,ysize);
	yyval.t=busca_tipo_dim2(yyvsp[-6].v,ysize);
	yyval.v=gera_temp(yyval.t);
	yyvsp[-5].v="*";
	yyvsp[-2].t="int";
	yyvsp[-2].v=inttostr(ysize);
	gera_operacao(yyvsp[-3],yyvsp[-4],yyvsp[-5],yyvsp[-2]);
	yyvsp[-5].v="+";
	gera_operacao(yyvsp[0],yyvsp[-3],yyvsp[-5],yyvsp[-1]);
	yyval.c=yyvsp[0].c+gera_atribuicao("=[]",yyval,yyvsp[-6],yyvsp[0]);
}
break;
case 87:
#line 499 "trabalho.y"
{
	yyval=yyvsp[-1];
}
break;
case 88:
#line 503 "trabalho.y"
{
	yyval.v=FUNC_CHAMA.retorno;
	yyval.t=FUNC_CHAMA.tipo;
}
break;
case 89:
#line 508 "trabalho.y"
{
	yyval=yyvsp[0];
}
break;
case 90:
#line 514 "trabalho.y"
{yyval=yyvsp[0];}
break;
case 91:
#line 515 "trabalho.y"
{yyval=yyvsp[0];}
break;
case 92:
#line 516 "trabalho.y"
{yyval=yyvsp[0];}
break;
case 93:
#line 517 "trabalho.y"
{yyval=yyvsp[0];}
break;
case 94:
#line 518 "trabalho.y"
{yyval=yyvsp[0];}
break;
#line 1162 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yyss + yystacksize - 1)
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    return (1);
yyaccept:
    return (0);
}
