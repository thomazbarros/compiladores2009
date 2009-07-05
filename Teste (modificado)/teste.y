%{
#include <string>
#include <iostream>

using namespace std;
int yyparse();
void yyerror( const char* st );
int yylex();

#define YYSTYPE string
%}

%token TK_ID TK_INTEIRO TK_MAIS TK_STRING TK_FUNC

%%
S : E { cout << $$ << endl; }
  ;

E : E '+' T { $$ = $1 + $3 + "+"; }
  | E '-' T { $$ = $1 + $3 + "-"; }
  | T
  ;

T : T '*' F  { $$ = $1 + $3 + "*"; }
  | T '/' F  { $$ = $1 + $3 + "/"; }
  | F
  ;

F : TK_ID      
  | TK_INTEIRO 
  | TK_STRING
  | '(' E ')' { $$ = $2; }  
  ;

%%
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




