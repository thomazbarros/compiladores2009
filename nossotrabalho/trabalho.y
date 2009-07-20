%{
#include <string>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef struct {
    string base;
    int n_dim;
    int d[2];
    
    void modifica_valores(string nova_base, int novo_n_dim = 0, int d0 = 1, int d1 =1)
    {
	base = nova_base;
	n_dim = novo_n_dim;
	d[0] = d0;
	d[1] = d1;
    }
}estrutura_tipos; 

typedef struct {
    estrutura_tipos tipo;
    string valor,codigo;
}atributos_compilador; 

typedef struct 
{
	string nome;
	Tipo tipo;
	Variavel(string nome, string base, int ndim=0, int dim1=1, int dim2=1) : nome(nome), tipo(base, ndim, dim1, dim2) {}
}variavel;

typedef struct
{
	string nome;
	Tipo tipo;
	vector<Tipo> param;
	Funcao(string nome, string base, int ndim=0, int dim1=1, int dim2=1) : nome(nome), tipo(base, ndim, dim1, dim2) {}
}funcao;

deque<map <string, variavel*> > var;
map<string, funcao*> func_global;
//map<string, unsigned int> conta_temp_var;
int nlinha = 1;

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
%token TK_FUNC_PRINC TK_FUNC_IF TK_FUNC_ELSE TK_FUNC_FOR TK_FUNC_WHILE TK_FUNC_START TK_FUNC_END TK_FUNC_FUNC TK_FUNC_PROT TK_FUNC_RETURN TK_FUNC_ENT TK_FUNC_SAIDA
%token TK_BOOL TK_ID TK_NUM TK_REAL TK_CHAR TK_STRING   

%% 
S : VG S 
  | funcao S 
  | main 
  ;

VG : tipo LID;
  ;

tipo :  TK_VAR_INT 	
  | TK_VAR_STRING	
  | TK_VAR_REAL	
  | TK_VAR_CHAR
  | TK_VAR_BOOL	
  | '(' E ')'
  ;

LID : V ',' LID
  | V
  ; 

V : TK_ID
  | TK_ID '[' TK_NUM ']'
  | TK_ID '[' TK_NUM ']' '[' TK_NUM ']'
  ;

funcao : TF FUN_ID '(' LParam ')' corpo {}
  | TF FUN_ID '(' LParam ')' ';'
  ;

FUN_ID : ID
  | ID '[' TK_NUM ']'
  | ID '[' TK_NUM ']' '[' TK_NUM ']'
  ;

ID : TK_ID { cria_id($$,$1).valor =  "_" + $1.valor; $$.codigo = "";}
  ;

USA_FUNC : ID '(' L_PARAM4 ')' { chama_funcao($$,$1,$3); }
  ;

TF : TK_VAR_VOID
   | tipo

LParam :  
  | Params
  ; 

Params : Param ',' Params
  | Param
  ;

Param : tipo TK_ID
  | tipo '*' TK_ID
  ;

main : TK_VAR_INT TK_FUNC_PRINC corpo
  ;

corpo : TK_FUNC_START VL CMDS TK_FUNC_END
  ;

VL : tipo LID ';' VL 
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
  | TK_FUNC_RETURN
  | ';'
  | BLOCO
  ;

CMDS : CMD CMDS
  |
  ;

BLOCO : TK_FUNC_START CMDS TK_FUNC_END

CMD_ATRIB : VA TK_AT_IGUAL E;
  | VA "+=" E;
  | VA "=-" E
  ;

VA : TK_ID
  | TK_ID '[' E ']'
  | TK_ID '[' E ']' '[' E ']'
  ;
 
CMD_IF : TK_FUNC_IF '(' TEST ')' CMD{
		gera_if($$, $3, $5);
	  }
  | TK_FUNC_IF '(' TEST ')' CMD TK_FUNC_ELSE CMD{
		gera_if_else($$, $3, $5, $7);
    }
  ;

CMD_FOR : TK_FUNC_FOR '(' TEST ';' TEST ';' TEST ')' CMD{
			gera-for($$, $3, $5, $7, $9);
	   }
  ;

CMD_WHILE : TK_FUNC_WHILE '(' TEST ')' CMD{
			gera_while($$, $3, $5);
	     }
  ;

CMD_DO_WHILE : "do" CMD "while" '(' TEST ')' ';'{
			gera_do_while($$, $2, $5);
		 }
  ;

CMD_SWITCH : "switch" '(' E ')' '{' LABELS DEFAULT '}'
  ;

LABELS : LABEL LABELS
  | CMD LABELS
  | "break" LABELS
  | 
  ;

LABEL : TK_NUM ':'
  ;

DEFAULT : "default" ':' CMDS
  ;
 
CMD_FUNC : TK_ID '(' L_ARGS ')' ';'

L_ARGS : 
  | ARGS
  ;

ARGS : E'.'ARGS
  | E
  ;

CMD_ENTRADA : TK_FUNC_ENT ">>" TK_ID ';'
  | TK_FUNC_ENT ">>" TK_ID '[' E ']' ';'
  | TK_FUNC_ENT ">>" TK_ID '[' E ']' '[' E ']' ';'
  ;

CMD_SAIDA : TK_FUNC_SAIDA "<<" E
  | TK_FUNC_SAIDA "<<" "endl"
  | TK_FUNC_SAIDA "<<" E "<<" "endl"
  ;

E : E TK_OP_SOMA T
  | E TK_OP_SUB T
  | T
  ;

T : T TK_OP_MULT F
  | T TK_OP_DIV F
  | T TK_OP_REST F
  | T TK_OP_DIVINT F
  | F
  ;

F : TK_LOG_NOT F
  | TK_ID
  | TK_NUM
  | '(' E ')'
  | TK_ID '(' E ')'
  | TK_ID '[' E ']'
  | TK_ID '[' E ']' '[' E ']'
  | TK_FUNC_FUNC
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




