CARACTER [a-zA-Z_]
IDENTIFICADOR  {CARACTER}({CARACTER}|{CARACTER})*

ALGARISMO [0-9]
NATURAL {ALGARISMO}+
REAL {ALGARISMO}+("."{ALGARISMO}*)?

ID {CARACTER}({CARACTER}|{ALGARISMO})*

IDENTACAO [\t\n ]

SENTENCA "'".*"'" 

BINARIO "falso" | "verdadeiro"
BOOLEANO {BINARIO}



%%

{DELIM}		{}

"int"		{ yylval.v = yytext; yylval.t = yytext; return TK_VAR_INT; }
"real"		{ yylval.v = yytext; yylval.t = yytext; return TK_VAR_REAL; }
"char"		{ yylval.v = yytext; yylval.t = yytext; return TK_VAR_CHAR; }
"string"	{ yylval.v = yytext; yylval.t = yytext; return TK_VAR_STRING; }
"bool"		{ yylval.v = yytext; yylval.t = yytext; return TK_VAR_BOOL; }
"void"		{ yylval.v = yytext; yylval.t = yytext; return TK_VAR_VOID; }

"+"		{ yylval.v = yytext; return TK_OP_SOMA; }
"-"		{ yylval.v = yytext; return TK_OP_SUB; }
"*"		{ yylval.v = yytext; return TK_OP_MULT; }
"/"		{ yylval.v = yytext; return TK_OP_DIV; }
"%"		{ yylval.v = yytext; return TK_OP_REST; }
"DIV"		{ yylval.v = yytext; return TK_OP_DIVINT; }

"="		{ yylval.v = yytext; return TK_AT_IGUAL; }

"=="		{ yylval.v = yytext; return TK_CMP_IGUAL; }
"!="		{ yylval.v = yytext; return TK_CMP_DIF; }
">"		{ yylval.v = yytext; return TK_CMP_MAIOR; }
">="		{ yylval.v = yytext; return TK_CMP_MAIORIG; }
"<"		{ yylval.v = yytext; return TK_CMP_MENOR; }
"<="		{ yylval.v = yytext; return TK_CMP_MENORIG; }

"!"		{ yylval.v = yytext; return TK_LOG_NOT; }
"&&"		{ yylval.v = yytext; return TK_LOG_E; }
"||"		{ yylval.v = yytext; return TK_LOG_OU; }

"showTime"	{ yylval.v = yytext; return TK_FUNC_PRINC; }
"facaSe"	{ yylval.v = yytext; return TK_FUNC_IF; }
"numDeu"	{ yylval.v = yytext; return TK_FUNC_ELSE; }
"facaPara"	{ yylval.v = yytext; return TK_FUNC_FOR; }
"facaEnq"	{ yylval.v = yytext; return TK_FUNC_WHILE; }
"{"		{ yylval.v = yytext; return TK_FUNC_START; }
"}"		{ yylval.v = yytext; return TK_FUNC_END; }
"func"		{ yylval.v = yytext; return TK_FUNC_FUNC; }
"prot"		{ yylval.v = yytext; return TK_FUNC_PROT; }
"voltaAew"	{ yylval.v = yytext; return TK_FUNC_RETURN; }
"le"		{ yylval.v = yytext; return TK_FUNC_ENT; }
"escreve"	{ yylval.v = yytext; return TK_FUNC_SAIDA; }

"true"		{ yylval.v = yytext; yylval.t = "bool"; return TK_BOOL; }
"false"		{ yylval.v = yytext; yylval.t = "bool"; return TK_BOOL; }

{ID}		{ yylval.v = yytext; return TK_ID; }
{NUM}		{ yylval.v = yytext; yylval.t = "int"; return TK_NUM; }
{REAL}		{ yylval.v = yytext; yylval.t = "real"; return TK_REAL; }
{CHAR}		{ yylval.v = yytext; yylval.t = "char"; return TK_CHAR; }
{STRING}	{ yylval.v = yytext; yylval.t = "string"; return TK_STRING; }

.		{ return *yytext; }

%%

 
