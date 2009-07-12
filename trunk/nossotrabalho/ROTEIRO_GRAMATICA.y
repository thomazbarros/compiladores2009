%{
#include <string>
#include <iostream>

using namespace std;

typedef struct {
	string valor,codigo;
	char tipo;
}atributos_compilador; 

#define YYSTYPE atributos_compilador

int yyparse();
void yyerror( const char* st );
int yylex();

%}

%token TK_ID TK_INTEIRO TK_MAIS TK_STRING TK_FUNC TK_CARACTER TK_REAL

%%
S : VG S
  | funcao S
  | main	
  ;

VG : tipo LID;
  ;

tipo : TK_ID     	{$$.codigo = $$.valor;} 
  | TK_INTEIRO 	{$$.codigo = $$.valor;}
  | TK_STRING	{$$.codigo = $$.valor;}
  | TK_REAL 	{$$.codigo = $$.valor;}
  | TK_CARACTER	{$$.codigo = $$.valor;}
  | '(' E ')' { $$.codigo = $2.codigo; }  
  ;

LID : V,LID
  | V
  ; 

V : id
  | id [num]
  | id [num][num]
  ;

funcao : TF id (LParam) corpo
  | TF id (LParam);
  ;

TF : void
   | tipo

LParam :  
  | Params
  ; 

Params : Param , Params
  | Param
  ;

Param : tipo id
  | tipo * id
  ;

main : int main() corpo
  ;

corpo : { VL CMDS}
  ;

VL : tipo LID; VL
  |
  ;

CMD : CMD_ATRIB
  | CMD_IF
  | CMD_FOR
  | CMD_WHILE
  | CMD_DO_WHILE
  | CMD_SWITCH
  | CMD_FUNC
  | CMD_ENTRADA
  | CMD_SAIDA
  | CMD_RETURN
  | ;
  | BLOCO
  ;

CMDS : CMD CMDS
  |
  ;

BLOCO : {CMDS}

CMD_ATRIB : VA = E;
  | VA += E;
  | VA =- E
  ;

VA : id
  | id [E]
  | id [E][E]
  ;
 
CMD_IF : if (E) CMD
  | if (E) CMD else CMD
  ;

CMD_FOR : for(E;E;E) CMD
  ;

CMD_WHILE : while(E) CMD
  ;

CMD_DO_WHILE : do CMD while(E);
  ;

CMD_SWITCH : switch (E) {LABELS DEFAULT}
  ;

LABELS : LABEL LABELS
  | CMD LABELS
  | break LABELS
  | 
  ;

LABEL : num :
  ;

DEFAULT : default : CMDS
  ;
 
CMD_FUNC : id(L_ARGS);

L_ARGS : 
  | ARGS
  ;

ARGS : E.ARGS
  | E
  ;

CMD_ENTRADA : cin >> id;
  | cin >> id [E];
  | cin >> id [E][E];
  ;

CMD_SAIDA : cout << E
  | cout << endl
  | cout << E << endl
  ;

E : E + T
  | E - T
  | T
  ;

T : T * F
  | T / F
  | F
  ;

F : +F
  | -F
  | !F
  | id
  | num
  | (E)
  | id(E)
  | id[E]
  | id[E][E]
  | funcao
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




