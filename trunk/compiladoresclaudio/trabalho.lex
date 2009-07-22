DELIM		[\t\n ]
NUMERO		[0-9]
LETRA		[A-Za-z_]
NUM		{NUMERO}{NUMERO}*
REAL		{NUM}"."{NUM}
ID		{LETRA}({LETRA}|{NUMERO})*
CHAR		(\'[ -�]\'|\\{NUMERO})
STRING		\"([^\"\n]|(\\\"))*\"




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
"MOD"		{ yylval.v = yytext; return TK_OP_REST; }
"DIV"		{ yylval.v = yytext; return TK_OP_DIVINT; }

"="		{ yylval.v = yytext; return TK_AT_IGUAL; }

"=="		{ yylval.v = yytext; return TK_CMP_IGUAL; }
"<>"		{ yylval.v = yytext; return TK_CMP_DIF; }
">"		{ yylval.v = yytext; return TK_CMP_MAIOR; }
">="		{ yylval.v = yytext; return TK_CMP_MAIORIG; }
"<"		{ yylval.v = yytext; return TK_CMP_MENOR; }
"<="		{ yylval.v = yytext; return TK_CMP_MENORIG; }

"NOT"		{ yylval.v = yytext; return TK_LOG_NOT; }
"AND"		{ yylval.v = yytext; return TK_LOG_E; }
"OR"		{ yylval.v = yytext; return TK_LOG_OU; }

"funcprincipal"	{ yylval.v = yytext; return TK_FUNC_PRINC; } 
"se"	{ yylval.v = yytext; return TK_FUNC_IF; } 
"tbmpode"	{ yylval.v = yytext; return TK_FUNC_ELSE; } 
"atehquandotiver"	{ yylval.v = yytext; return TK_FUNC_FOR; } 
"enquantotiver"	{ yylval.v = yytext; return TK_FUNC_WHILE; } 
"{"		{ yylval.v = yytext; return TK_FUNC_START; } 
"}"		{ yylval.v = yytext; return TK_FUNC_END; } 
"funcsecundaria"		{ yylval.v = yytext; return TK_FUNC_FUNC; } 
"prot"		{ yylval.v = yytext; return TK_FUNC_PROT; } 
"saidafunc"	{ yylval.v = yytext; return TK_FUNC_RETURN; } 
"ler"		{ yylval.v = yytext; return TK_FUNC_ENT; } 
"imprimir"	{ yylval.v = yytext; return TK_FUNC_SAIDA; } 

"verdade"		{ yylval.v = yytext; yylval.t = "bool"; return TK_BOOL; } 
"mentira"		{ yylval.v = yytext; yylval.t = "bool"; return TK_BOOL; } 

{ID}		{ yylval.v = yytext; return TK_ID; }
{NUM}		{ yylval.v = yytext; yylval.t = "int"; return TK_NUM; }
{REAL}		{ yylval.v = yytext; yylval.t = "real"; return TK_REAL; }
{CHAR}		{ yylval.v = yytext; yylval.t = "char"; return TK_CHAR; }
{STRING}	{ yylval.v = yytext; yylval.t = "string"; return TK_STRING; }

.		{ return *yytext; }

%%

 


