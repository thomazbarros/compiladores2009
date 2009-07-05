DELIM   [\t\n ]
NUMERO  [0-9]
LETRA   [A-Za-z_]
INTEIRO {NUMERO}+("."{NUMERO}*)?
ID      {LETRA}({LETRA}|{NUMERO})*
STRING  "'".*"'" 

%%

{DELIM}   {}
{ID}      { yylval = yytext; return TK_ID; }
{INTEIRO} { yylval = yytext; return TK_INTEIRO; }
{STRING}  { return TK_STRING; }
.         { return *yytext; }

%%

 


