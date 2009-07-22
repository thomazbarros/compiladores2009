/*
* Trabalho de Compiladores 2008.02
* Professor Zimbrão
*
* Grupo: Andressa de Jesus Pedrosa da Silva   - DRE: 107363052
*	 Igor de Moraes Ferreira	      - DRE: 107362226
*	 Alice de Azeredo Tomaz		      - DRE: 107413807
*/

DELIM			[ \t\n]
NUMERO			[0-9]
LETRA			[A-Za-z_]

ID			{LETRA}({LETRA}|{NUMERO})*

CONST_INTEIRO		{NUMERO}+
CONST_REAL		{NUMERO}+("."{NUMERO}+)?
CONST_BOOL_V		"verdadeiro"
CONST_BOOL_F		"falso"
CONST_CARACTER		"\'"."\'"
CONST_STRING		"\"".*"\""

COMENTARIO		"<?".*"?>\n"


%%

{DELIM}			{ }
{COMENTARIO}		{ }

{CONST_INTEIRO}		{ yylval.v = yytext; return TK_CONST_INTEIRO; }
{CONST_REAL}		{ yylval.v = yytext; return TK_CONST_REAL; }
{CONST_BOOL_V}		{ yylval.v = yytext; return TK_CONST_BOOL_V; }
{CONST_BOOL_F}		{ yylval.v = yytext; return TK_CONST_BOOL_F; }
{CONST_CARACTER}	{ yylval.v = yytext; return TK_CONST_CARACTER; }
{CONST_STRING}		{ yylval.v = yytext; return TK_CONST_STRING; }

"inteiro"		{ yylval.v = yytext; return TK_INTEIRO; }
"string"		{ yylval.v = yytext; return TK_STRING; }
"real"			{ yylval.v = yytext; return TK_REAL; }
"boolean"		{ yylval.v = yytext; return TK_BOOLEAN; }
"caracter"		{ yylval.v = yytext; return TK_CARACTER; }
"vazio"			{ yylval.v = yytext; return TK_VAZIO; }

"="			{ yylval.v = yytext; return TK_ATRIBUICAO; }
"{"			{ yylval.v = yytext; return TK_INICIO_BLOCO; }
"}"			{ yylval.v = yytext; return TK_FIM_BLOCO; }

"principal"		{ yylval.v = yytext; return TK_PRINCIPAL; }
"switch"		{ yylval.v = yytext; return TK_SWITCH; }
"padrao"		{ yylval.v = yytext; return TK_PADRAO; }
"caso"			{ yylval.v = yytext; return TK_CASO; }
"se"			{ yylval.v = yytext; return TK_SE; }
"senao"			{ yylval.v = yytext; return TK_SENAO; }
"para"			{ yylval.v = yytext; return TK_PARA; }
"ate"			{ yylval.v = yytext; return TK_ATE; }
"faca"			{ yylval.v = yytext; return TK_FACA; }
"enquanto"		{ yylval.v = yytext; return TK_ENQUANTO; }
"retorno"		{ yylval.v = yytext; return TK_RETORNO; }
"entrada"		{ yylval.v = yytext; return TK_ENTRADA; }
"saida"			{ yylval.v = yytext; return TK_SAIDA; }
"||"			{ yylval.v = yytext; return TK_OU; }
"&&"			{ yylval.v = yytext; return TK_E; }

">"			{ yylval.v = yytext; return TK_CMP_MAIOR; }
"<"			{ yylval.v = yytext; return TK_CMP_MENOR; }
">="			{ yylval.v = yytext; return TK_CMP_MAIOR_IGUAL; }
"<="			{ yylval.v = yytext; return TK_CMP_MENOR_IGUAL; }
"=="			{ yylval.v = yytext; return TK_CMP_IGUALDADE; }
"!="			{ yylval.v = yytext; return TK_CMP_DIFERENCA; }

"+"			{ yylval.v = yytext; return TK_MAIS; }
"-"			{ yylval.v = yytext; return TK_MENOS; }
"*"			{ yylval.v = yytext; return TK_VEZES; }
"/"			{ yylval.v = yytext; return TK_DIV; }
"!"			{ yylval.v = yytext; return TK_NEGACAO; }

"$"			{ yylval.v = yytext; return TK_POR_VALOR; }
"&"			{ yylval.v = yytext; return TK_POR_REFERENCIA; }

"prototipo"		{ yylval.v = yytext; return TK_PROTOTIPO; }

{ID}			{ yylval.v = yytext; return TK_ID; }

.			{ return *yytext; }

%%
