%{
#include <string>
#include <iostream>

using namespace std;

#include "funcoes.h"
typedef struct {
	string valor,codigo;
	char tipo;
}atributos_compilador; 

#define YYSTYPE atributos_compilador
#define SOMA 0 
#define SUBTR 1
#define MULT 2
#define DIV 3
#define MOD 4

int yyparse();
void yyerror( const char* st );
int yylex();

%}

%token TK_ID TK_INTEIRO TK_MAIS TK_STRING TK_FUNC TK_CARACTER TK_REAL

%%
S : E { cout << $$.codigo << endl; }
  ;

E : E '+' T { realizar_operacao(SOMA,$$,$1,$3) ; }
  | E '-' T { realizar_operacao(SUBTR,$$,$1,$3) ; }
  | T
  ;

T : T '*' F  { realizar_operacao(MULT,$$,$1,$3)}
  | T '/' F  { realizar_operacao(DIV,$$,$1,$3); }
  | T '%' F   {realizar_operacao(MULT,$$,$1,$3)}
  | F
  ;

F : TK_ID     	 
  | TK_INTEIRO 	
  | TK_STRING	
  | TK_REAL 	
  | TK_CARACTER	
  | TK_BOOLEANO   
  ;

TIPO : TK_INTEIRO 	{ $$.codigo = $$.valor; }
  | TK_STRING	        { $$.codigo = $$.valor; }
  | TK_REAL 	        { $$.codigo = $$.valor; }
  | TK_CARACTER	        { $$.codigo = $$.valor; }
  | TK_BOOLEANO         { $$.codigo = $$.valor; }
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




