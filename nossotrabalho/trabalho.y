%{
#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include "funcoes.h"
using namespace std;

#define YYSTYPE atributos_compilador

int yyparse();
void yyerror( const char* st );
int yylex();

%}

%token TK_VAR_INT TK_VAR_REAL TK_VAR_CHAR TK_VAR_STRING TK_VAR_BOOL TK_VAR_VOID
%token TK_OP_SOMA TK_OP_SUB TK_OP_MULT TK_OP_DIV TK_OP_REST TK_OP_DIVINT 
%token TK_AT_IGUAL
%token TK_CMP_IGUAL TK_CMP_DIF TK_CMP_MAIOR TK_CMP_MAIORIG TK_CMP_MENOR TK_CMP_MENORIG
%token TK_LOG_NOT TK_LOG_E TK_LOG_OU
%token TK_FUNC_PRINC TK_FUNC_IF TK_FUNC_ELSE TK_FUNC_FOR TK_FUNC_WHILE TK_FUNC_START TK_FUNC_END TK_FUNC_FUNC TK_FUNC_PROT TK_FUNC_RETURN TK_FUNC_ENT TK_FUNC_SAIDA TK_FUNC_SAIDA_PL
%token TK_BOOL TK_ID TK_NUM TK_REAL TK_CHAR TK_STRING   
%token TK_N TK_TEST
%left '+' '-'
%left '*' '/'
%left '%'
%right '+='
%nonassoc '<' '>'

%% 
S : VG main { gera_inicializacao($$,$1,$2); }
  ;

VG : tipo LID ';' VG { gera_codigo_VG($$,$1,$2,$3);}
  | funcao VG {gera_codigo_VG($$,$1,$2);}
  | {gera_codigo_VG_vazio($$);}
  ;

tipo :  TK_VAR_INT 	
  | TK_VAR_STRING	
  | TK_VAR_REAL	
  | TK_VAR_CHAR
  | TK_VAR_BOOL	
  ;

LID : V ',' LID { gera_codigo_LID($$,$1,$3);}
  | V { gera_codigo_LID($$,$1); }
  ; 

V : TK_ID {gera_variavel("", $$, $1);}
  | TK_ID '[' TK_NUM ']' {gera_vetor("", $$, $1, $3);}
  | TK_ID '[' TK_NUM ']' '[' TK_NUM ']' {gera_matriz("", $$, $1, $3, $5);}
  ;

funcao : nome_funcao corpo { gera_codigo_funcao($$,$1,$2); }
  ;

nome_funcao : tipo FUN_ID '(' LParam ')' { gera_nome_funcao($$,$1,$2,$4); }
  ;

FUN_ID : ID { gera_FUN_ID($$,$1); }
  | ID '[' TK_NUM ']' {gera_FUN_ID($$,$1,$3);}
  | ID '[' TK_NUM ']' '[' TK_NUM ']' {gera_FUN_ID($$,$1,$3,$5);}
  ;

ID : TK_ID { cria_id($$,$1)}
  ;

USA_FUNC : ID '(' L_PARAM4 ')' { chama_funcao($$,$1,$3); }
  ;

LParam :  
  | Params
  ; 

Params : Param ',' Params
  | Param
  ;

Param : tipo TK_ID {gera_variavel("", $$, $2);}
  | tipo '*' TK_ID {gera_variavel("*", $$, $2);} 
  ;

main : TK_FUNC_PRINC corpo {declara_main($$,$2);}
  ;

corpo : TK_FUNC_START VL CMDS TK_FUNC_END
  ;

VL : tipo LID ';' VL 
  |
  ;

N: TK_CMP_IGUAL
   |TK_CMP_DIF
   |TK_CMP_MAIOR
   |TK_CMP_MAIORIG
   |TK_CMP_MENOR
   |TK_CMP_MENORIG
   ;

TK_CMP_IGUAL : E "==" E {gera_n("==", $$, $1, $3);}
  ;

TK_CMP_DIF : E "!=" E {gera_n("!=", $$, $1, $3);}
  ;

TK_CMP_MAIOR : E ">" E {gera_n(">", $$, $1, $3);}
  ;

TK_CMP_MAIORIG : E ">=" E {gera_n(">=", $$, $1, $3);}
  ;

TK_CMP_MENOR : E "<" E {gera_n("<", $$, $1, $3);}
  ;

TK_CMP_MENORIG : E "<=" E {gera_n("<=", $$, $1, $3);}
  ;

TEST : N "&&" N {gera_test("&&", $$, $1, $3);}
	| N "||" N {gera_test("||", $$, $1, $3);}
       | N
       ;

CMD : CMD_ATRIB
  | CMD_IF
  | CMD_FOR
  | CMD_WHILE
  | CMD_DO_WHILE
  | CMD_ENTRADA
  | CMD_SAIDA
  | TK_FUNC_RETURN
  | ';'
  | BLOCO
  ;

CMDS : CMD CMDS
  |
  ;

BLOCO : TK_FUNC_START CMDS TK_FUNC_END { gera_bloco($$,$2); }

CMD_ATRIB : VA TK_AT_IGUAL E;
  | VA "+=" E
  | VA "-=" E
  ;

VA : TK_ID
  | TK_ID '[' E ']'
  | TK_ID '[' E ']' '[' E ']'
  ;
 
CMD_IF : TK_FUNC_IF '(' TEST ')' CMD {gera_if($$, $3, $5);}
  | TK_FUNC_IF '(' TEST ')' CMD TK_FUNC_ELSE CMD {gera_if_else($$, $3, $5, $7);}
  ;

CMD_FOR : TK_FUNC_FOR '(' CMD_ATRIB ';' TK_CMP_MAIOR ';' CMD_ATRIB ')' CMD {gera_for($$, $3, $5, $7, $9);}
	   |TK_FUNC_FOR '(' CMD_ATRIB ';' TK_CMP_MAIORIG ';' CMD_ATRIB ')' CMD {gera_for($$, $3, $5, $7, $9);}
          |TK_FUNC_FOR '(' CMD_ATRIB ';' TK_CMP_MENOR ';' CMD_ATRIB ')' CMD {gera_for($$, $3, $5, $7, $9);}
          |TK_FUNC_FOR '(' CMD_ATRIB ';' TK_COMP_MENORIG ';' CMD_ATRIB ')' CMD {gera_for($$, $3, $5, $7, $9);}
          ;

CMD_WHILE : TK_FUNC_WHILE '(' TEST ')' CMD {gera_while($$, $3, $5);}
  ;

CMD_DO_WHILE : "do" CMD "while" '(' TEST ')' ';' {gera_do_while($$, $2, $5);}
  ;
 
L_ARGS : 
  | ARGS
  ;

ARGS : E'.'ARGS
  | E
  ;

CMD_ENTRADA : TK_FUNC_ENT '(' F ')' ';' { gera_entrada($$,$3)}
  ;

CMD_SAIDA : TK_FUNC_SAIDA '(' E ')' ';' {gera_saida($$,$3);} 
  | TK_FUNC_SAIDA_PL '(' ')' ';' {gera_saida($$,true,true);}
  | TK_FUNC_SAIDA_PL '(' E ')' ';' {gera_saida($$,$3,true);}
  ;

E : E TK_OP_SOMA T {realizar_operacao(SOMA,$$,$1,$3);}
  | E TK_OP_SUB T {realizar_operacao(SUBTR,$$,$1,$3);}
  | T
  ;

T : T TK_OP_MULT F {realizar_operacao(MULT,$$,$1,$3);}
  | T TK_OP_DIV F {realizar_operacao(DIV,$$,$1,$3);}
  | T TK_OP_REST F {realizar_operacao(MOD,$$,$1,$3);}
  | T TK_OP_DIVINT F {realizar_operacao(DIV,$$,$1,$3);}
  | F
  ;

F : TK_LOG_NOT F
  | TK_ID
  | TK_NUM
  | '(' E ')'
  | TK_ID '(' E ')'
  | TK_ID '[' E ']'
  | TK_ID '[' E ']' '[' E ']'
  | USA_FUNC
  ;

%%
#include "lex.yy.c"

int yyparse();

void yyerror( const char* st )
{
  // puts( st );
	cout << st <<";" << endl;
      //  exit(1);

}

int main( int argc, char* argv[] )
{
  yyparse();
}




