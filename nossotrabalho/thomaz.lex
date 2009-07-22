CARACTER [a-zA-Z_]
IDENTIFICADOR  {CARACTER}({CARACTER}|{CARACTER})*

ALGARISMO [0-9]
NATURAL {ALGARISMO}+
REAL {ALGARISMO}+("."{ALGARISMO}*)?

ID {CARACTER}({CARACTER}|{ALGARISMO})*

IDENTACAO [\t\n ]


SENTENCA		\"([^\"\n]|(\\\"))*\"


%%


{IDENTACAO} {}

"int"		{ yylval.valor = yytext; yylval.tipo.base = yytext; return TK_VAR_INT; }
"real"		{ yylval.valor = yytext; yylval.tipo.base = yytext; return TK_VAR_REAL; }
"char"		{ yylval.valor = yytext; yylval.tipo.base = yytext; return TK_VAR_CHAR; }
"string"	{ yylval.valor = yytext; yylval.tipo.base = yytext; return TK_VAR_STRING; }
"bool"		{ yylval.valor = yytext; yylval.tipo.base = yytext; return TK_VAR_BOOL; }
"void"		{ yylval.valor = yytext; yylval.tipo.base = yytext; return TK_VAR_VOID; }

"+"		{ yylval.valor = yytext; return TK_OP_SOMA; }
"-"		{ yylval.valor = yytext; return TK_OP_SUB; }
"*"		{ yylval.valor = yytext; return TK_OP_MULT; }
"/"		{ yylval.valor = yytext; return TK_OP_DIV; }
"%"		{ yylval.valor = yytext; return TK_OP_REST; }
"DIV"		{ yylval.valor = yytext; return TK_OP_DIVINT; }

"="		{ yylval.valor = yytext; return TK_AT_IGUAL; }

"=="		{ yylval.valor = yytext; return TK_CMP_IGUAL; }
"!="		{ yylval.valor = yytext; return TK_CMP_DIF; }
">"		{ yylval.valor = yytext; return TK_CMP_MAIOR; }
">="		{ yylval.valor = yytext; return TK_CMP_MAIORIG; }
"<"		{ yylval.valor = yytext; return TK_CMP_MENOR; }
"<="		{ yylval.valor = yytext; return TK_CMP_MENORIG; }

"!"		{ yylval.valor = yytext; return TK_LOG_NOT; }
"&&"		{ yylval.valor = yytext; return TK_LOG_E; }
"||"		{ yylval.valor = yytext; return TK_LOG_OU; }

"funcprincipal"	{ yylval.valor = yytext; return TK_FUNC_PRINC; }
"Se"	{ yylval.valor = yytext; return TK_FUNC_IF; }
"tbmpode"	{ yylval.valor = yytext; return TK_FUNC_ELSE; }
"atehquandotiver"	{ yylval.valor = yytext; return TK_FUNC_FOR; }
"enquantotiver"	{ yylval.valor = yytext; return TK_FUNC_WHILE; }
"["		{ yylval.valor = yytext; return TK_FUNC_START; }
"]"		{ yylval.valor = yytext; return TK_FUNC_END; }
"funcsecundaria"		{ yylval.valor = yytext; return TK_FUNC_FUNC; }
"prot"		{ yylval.valor = yytext; return TK_FUNC_PROT; }
"saidafunc"	{ yylval.valor = yytext; return TK_FUNC_RETURN; }
"ler"		{ yylval.valor = yytext; return TK_FUNC_ENT; }
"imprimir"	{ yylval.valor = yytext; return TK_FUNC_SAIDA; }
"imprimirpl"	{ yylval.valor = yytext; return TK_FUNC_SAIDA_PL; }

"verdade"		{ yylval.valor = yytext; yylval.tipo.base = "bool"; return TK_BOOL; }
"mentira"		{ yylval.valor = yytext; yylval.tipo.base = "bool"; return TK_BOOL; }

{IDENTIFICADOR}		{ yylval.valor = yytext; return TK_ID; }
{NATURAL}		{ yylval.valor = yytext; yylval.tipo.base = "int"; return TK_NUM; }
{REAL}		{ yylval.valor = yytext; yylval.tipo.base = "double"; return TK_REAL; }
{CARACTER}		{ yylval.valor = yytext; yylval.tipo.base = "char"; return TK_CHAR; }
{SENTENCA}	{ yylval.valor = yytext; yylval.tipo.base = "string"; return TK_STRING; }
.		{ return *yytext; }

%%

 
