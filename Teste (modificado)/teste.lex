extern atributos_compilador yylval;


DELIM   [\t\n ]
NUMERO  [0-9]
LETRA   [A-Za-z_]
INTEIRO {NUMERO}+("."{NUMERO}*)?
ID      {LETRA}({LETRA}|{NUMERO})*
STRING  "'".*"'" 
CARACTER "(".*")"
REAL {NUMERO}+"."{NUMERO}+
%%

{DELIM}   {}
{ID}      	{ yylval.codigo = ""; yylval.valor = yytext; yylval.tipo = '?'; return TK_ID; }
{INTEIRO} 	{ yylval.codigo = ""; yylval.valor = yytext; yylval.tipo = 'i'; return TK_INTEIRO; }
{STRING}  	{ yylval.codigo = ""; yylval.valor = yytext; yylval.tipo = 's'; return TK_STRING; }
{CARACTER}	{ yylval.codigo = ""; yylval.valor = yytext; yylval.tipo = 'c'; return TK_CARACTER;}
{REAL}		{ yylval.codigo = ""; yylval.valor = yytext; yylval.tipo = 'f'; return TK_REAL;}
.         { return *yytext; }

%%

 


