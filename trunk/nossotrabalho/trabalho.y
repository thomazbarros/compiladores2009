%{
#include <string>
#include <iostream>

using namespace std;


typedef struct {
	string valor,codigo,tipo;
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

%token TK_ID TK_NUM TK_STRING TK_CHAR TK_BOOL TK_REAL

%%
S : E { cout << $$.codigo << endl; }
  ;

E : E '+' T 
  | E '-' T 
  | T
  ;

T : T '*' F    
  | T '/' F  
  | T '%' F  
  | F
  ;

F : TK_ID     	 
  | TK_NUM 	
  | TK_STRING	
  | TK_REAL 	
  | TK_CHAR	
  | TK_BOOL   
  ;

TIPO : TK_NUM 
  | TK_STRING	        
  | TK_REAL 	        
  | TK_CHAR      
  | TK_BOOL         
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




