%{

#include <string>
#include <iostream>
#include "simbolos.cpp"

using namespace std;

#define YYSTYPE atributo

atributo vazio={"","",""};

%}

%token TK_ID TK_NUM TK_REAL TK_CHAR TK_STRING TK_BOOL
%token TK_VAR_INT TK_VAR_REAL TK_VAR_CHAR TK_VAR_STRING TK_VAR_BOOL TK_VAR_VOID
%token TK_OP_SOMA TK_OP_SUB TK_OP_MULT TK_OP_DIV TK_OP_REST TK_OP_DIVINT
%token TK_AT_IGUAL
%token TK_CMP_IGUAL TK_CMP_DIF TK_CMP_MAIOR TK_CMP_MAIORIG TK_CMP_MENOR TK_CMP_MENORIG
%token TK_LOG_E TK_LOG_OU TK_LOG_NOT
%token TK_FUNC_PRINC TK_FUNC_IF TK_FUNC_ELSE TK_FUNC_FOR TK_FUNC_START TK_FUNC_END TK_FUNC_WHILE TK_FUNC_FUNC TK_FUNC_PROT TK_FUNC_RETURN TK_FUNC_ENT TK_FUNC_SAIDA

%%
PROGRAMA
: AUX_PROGRAMA VAR_GLOBAL FUNCOES PRINCIPAL
{
	$$.c=$2.c+TEMP_CODIGO+$3.c+$4.c;
	cout << $$.c;
}
;

AUX_PROGRAMA
:
{
	ID_NOVO.func="";
}
;

VAR_GLOBAL
: VAR ';' VAR_GLOBAL	{$$.c=$1.c+$3.c;}
|			{$$.c="";}
;

VAR
: TIPO LISTA_ID		{$$.c=$2.c;}
;

TIPO
: TIPO_SIMPLES
{
	ID_NOVO.tipo=$1.v;
	ID_NOVO.n_dim=0;
	ID_NOVO.xsize=0;
	ID_NOVO.ysize=0;
}
| VETOR
| MATRIZ
;

TIPO_SIMPLES
: TK_VAR_INT	{$$=$1;}
| TK_VAR_REAL 	{$$=$1;}
| TK_VAR_CHAR	{$$=$1;}
| TK_VAR_STRING	{$$=$1;}
| TK_VAR_BOOL	{$$=$1;}
;

VETOR
: TIPO_SIMPLES'['TK_NUM']'
{
	ID_NOVO.tipo=$1.v;
	ID_NOVO.n_dim=1;
	ID_NOVO.xsize=strtoint($3.v);
	ID_NOVO.ysize=0;
}
;

MATRIZ
: TIPO_SIMPLES'['TK_NUM']''['TK_NUM']'
{
	ID_NOVO.tipo=$1.v;
	ID_NOVO.n_dim=2;
	ID_NOVO.xsize=strtoint($3.v);
	ID_NOVO.ysize=strtoint($6.v);
}
;

LISTA_ID
: AUX_LISTA_ID AT ',' LISTA_ID
{
	string temp;
	insere_tipo_dimX ($1.v,ID_NOVO.tipo,ID_NOVO.n_dim,ID_NOVO.xsize,ID_NOVO.ysize,ID_NOVO.func);
	if (ID_NOVO.n_dim==0) temp=gera_codigo("VAR",ID_NOVO.tipo,$1.v);
	else if (ID_NOVO.n_dim==1) temp=gera_codigo("VAR",ID_NOVO.tipo+"[]",$1.v,inttostr(ID_NOVO.xsize));
	else if (ID_NOVO.n_dim==2) temp=gera_codigo("VAR",ID_NOVO.tipo+"[]",$1.v,inttostr(ID_NOVO.xsize*ID_NOVO.ysize));
	$$.c=temp+$2.c+$4.c;
}
| AUX_LISTA_ID AT
{
	string temp;
	insere_tipo_dimX ($1.v,ID_NOVO.tipo,ID_NOVO.n_dim,ID_NOVO.xsize,ID_NOVO.ysize,ID_NOVO.func);
	if (ID_NOVO.n_dim==0) temp=gera_codigo("VAR",ID_NOVO.tipo,$1.v);
	else if (ID_NOVO.n_dim==1) temp=gera_codigo("VAR",ID_NOVO.tipo+"[]",$1.v,inttostr(ID_NOVO.xsize));
	else if (ID_NOVO.n_dim==2) temp=gera_codigo("VAR",ID_NOVO.tipo+"[]",$1.v,inttostr(ID_NOVO.xsize*ID_NOVO.ysize));
	$$.c=temp+$2.c;
}
;

AUX_LISTA_ID
: TK_ID
{
	$$=$1;
	ID_NOVO.valor=$1.v;
}
;

AT
: TK_AT_IGUAL G
{
	$1.v=ID_NOVO.valor;
	$1.t=ID_NOVO.tipo;
	$$.c=$2.c+gera_atribuicao("=",$1,$2,vazio);
}
|	{$$.c="";}
;

FUNCOES
: FUNC FUNCOES		{$$.c=$1.c+$2.c;}
|			{$$.c="";}
;

FUNC
: TK_FUNC_FUNC CABECALHO_F TK_FUNC_START VAR_LOCAL COMANDOS TK_FUNC_END
{
	int i;
	$$.c=$2.c+$4.c+$5.c;
	$$.c+=gera_codigo("ENDFUNC");
	if (!ID_NOVO.retornou)
	{
		erro("A funcao \""+ID_NOVO.func+"\" NAO retorna valor algum.");
	}
}
;

CABECALHO_F
: AUX_CABECALHO '(' PARAMETROS_F ')'	{$$.c=$1.c + $3.c;}
| AUX_CABECALHO '(' ')'			{$$.c=$1.c;}
;

AUX_CABECALHO
: TIPO_SIMPLES TK_ID
{
	ID_NOVO.func=$2.v;
	ID_NOVO.func_tipo=$1.t;
	ID_NOVO.retornou=false;
	insere_funcao ($2.v,$1.v);
	PARAM_POSITION=1;
	$$.c=gera_codigo("FUNC",$1.v,$2.v);
}
| TK_VAR_VOID TK_ID
{
	ID_NOVO.func=$2.v;
	ID_NOVO.func_tipo=$1.t;
	ID_NOVO.retornou=true;
	insere_funcao ($2.v,$1.v);
	PARAM_POSITION=1;
	$$.c=gera_codigo("FUNC",$2.v);
}
;

PARAMETROS_F
: PARAM_F ',' PARAMETROS_F	{$$.c=$1.c+$3.c;}
| PARAM_F			{$$.c=$1.c;}
;

PARAM_F
: TIPO_SIMPLES REF TK_ID
{
	ID_NOVO.tipo=$1.v;
	ID_NOVO.n_dim=0;
	ID_NOVO.xsize=0;
	ID_NOVO.ysize=0;
	insere_param ($3.v,ID_NOVO.tipo,PARAM_POSITION);
	PARAM_POSITION++;
	insere_tipo_dimX ($3.v,ID_NOVO.tipo,ID_NOVO.n_dim,ID_NOVO.xsize,ID_NOVO.ysize,ID_NOVO.func);
	$$.c=gera_codigo("ARG"+$2.v,$1.v,$3.v);
}
;

REF
: '&'	{$$.v="&";}
|	{$$.v="";}
;

VAR_LOCAL
: VAR';' VAR_LOCAL	{$$.c=$1.c+$3.c;}
|			{$$.c="";}
;

COMANDOS
: CMD COMANDOS		{$$.c=$1.c+$2.c;}
|			{$$.c="";}
;

CMD
: CMD_ATRIB		{$$.c=$1.c;}
| CMD_IF		{$$.c=$1.c;}
| CMD_FOR		{$$.c=$1.c;}
| CMD_WHILE		{$$.c=$1.c;}
| CMD_RETURN		{$$.c=$1.c;}
| CMD_ENTRADA		{$$.c=$1.c;}
| CMD_SAIDA		{$$.c=$1.c;}
| CMD_FUNC ';'		{$$.c=$1.c;}
;

CMD_ENTRADA
: TK_FUNC_ENT TK_ID ';'
{
	$2.t=busca_tipo_dim0($2.v);
	$$.c=gera_codigo("CIN",$2.v);
}
;

CMD_SAIDA
: TK_FUNC_SAIDA E ';'
{
	$$.c=$2.c+gera_codigo("COUT",$2.v)+gera_codigo("ENDL");
}
;

CMD_FUNC
: AUX_CMD_FUNC '(' PARAMETROS_C ')'
{
	$$.c=$3.c+gera_codigo("CALL",FUNC_CHAMA.nome,FUNC_CHAMA.retorno);
	acabou_param (FUNC_CHAMA.nome,PARAM_POSITION);
}
| AUX_CMD_FUNC '(' ')'
{
	$$.c=gera_codigo("CALL",FUNC_CHAMA.nome,FUNC_CHAMA.retorno);
	acabou_param (FUNC_CHAMA.nome,PARAM_POSITION);
}
;

AUX_CMD_FUNC
: TK_ID
{
	FUNC_CHAMA.nome=$1.v;
	FUNC_CHAMA.tipo=busca_funcao($1.v);
	if (FUNC_CHAMA.tipo!="void") FUNC_CHAMA.retorno=gera_temp(FUNC_CHAMA.tipo);
	else FUNC_CHAMA.retorno="";
	PARAM_POSITION=1;
}
;

PARAMETROS_C
: PARAMETROS_C ',' E
{
	busca_param($3.t,FUNC_CHAMA.nome,PARAM_POSITION);
	PARAM_POSITION++;
	$$.c=$1.c;
	$$.c+=$3.c+gera_codigo("PARAM",$3.v);
}
| E
{
	busca_param($1.t,FUNC_CHAMA.nome,PARAM_POSITION);
	PARAM_POSITION++;
	$$.c=$1.c+gera_codigo("PARAM",$1.v);
}
;

CMD_RETURN
: TK_FUNC_RETURN E';'
{
	if (ID_NOVO.func_tipo!="void")
	{
		$$.c=$2.c+gera_codigo("RETURN",$2.v);
		if (busca_tipo_operacao("=",ID_NOVO.func_tipo,$2.t)=="")
		{
			erro("A funcao \""+ID_NOVO.func+"\" que retorna \""+ID_NOVO.func_tipo+"\" nao pode retornar \""+$2.t+"\".",1);
		}
		ID_NOVO.retornou=true;
	}
	else
	{
		erro("A funcao \""+ID_NOVO.func+"\" eh do tipo void e nao pode retornar um valor.",1);
	}
}
| TK_FUNC_RETURN ';'
{
	if (ID_NOVO.func_tipo=="void") $$.c=gera_codigo("RETURN");
	else
	{
		erro("A funcao \""+ID_NOVO.func+"\" precisa retornar algum valor (\""+ID_NOVO.func_tipo+"\" esperado).",1);
	}
}
;

CMD_ATRIB
: TK_ID TK_AT_IGUAL E';'
{
	$1.t=busca_tipo_dim0($1.v);
	$$.c=$3.c+gera_atribuicao("=",$1,$3,vazio);
}
| TK_ID'['E']' TK_AT_IGUAL E';'
{
	$1.t=busca_tipo_dim1($1.v);
	$$.c=$3.c+$6.c+gera_atribuicao("[]=",$1,$3,$6);
}
| TK_ID'['E']''['E']' TK_AT_IGUAL E';'
{
	int ysize;
	$1.t=busca_tipo_dim2($1.v,ysize);
	$2.v="*";
	$5.t="int";
	$5.v=inttostr(ysize);
	gera_operacao($4,$3,$2,$5);
	$2.v="+";
	gera_operacao($7,$4,$2,$6);
	$$.c=$7.c+$9.c+gera_atribuicao("[]=",$1,$7,$9);
}
;

CMD_IF
: TK_FUNC_IF '(' VERIFICA ')' TK_FUNC_START COMANDOS TK_FUNC_END
{
	string L1=gera_label("BEGINIF");
	string L2=gera_label("ENDIF");
	$$.c = $3.c + gera_codigo("IF",$3.v,L1) + gera_codigo("GOTO",L2) + gera_codigo("LABEL",L1) + $6.c + gera_codigo("LABEL",L2);
}
| TK_FUNC_IF '(' VERIFICA ')' TK_FUNC_START COMANDOS TK_FUNC_END TK_FUNC_ELSE TK_FUNC_START COMANDOS TK_FUNC_END
{
	string L1=gera_label("BEGINIF");
	string L2=gera_label("ENDIF");
	$$.c = $3.c + gera_codigo("IF",$3.v,L1) + $10.c + gera_codigo("GOTO",L2) + gera_codigo("LABEL",L1) + $6.c + gera_codigo("LABEL",L2);
}
;

CMD_FOR
: TK_FUNC_FOR '(' TK_ID TK_AT_IGUAL TK_NUM ':' TK_NUM ';' TK_NUM ')' TK_FUNC_START COMANDOS TK_FUNC_END
{
	string L1=gera_label("BEGINFOR");
	string L2=gera_label("ENDFOR");
	string valor = gera_temp("bool");
	
	$3.t=busca_tipo_dim0($3.v);
	
	if (strtoint($5.v) <= strtoint ($7.v)) $$.c = gera_atribuicao("=",$3,$5,vazio) + gera_codigo("LABEL",L1) + gera_codigo(">=",valor,$3.v,$7.v) + gera_codigo("IF",valor,L2) + $12.c + gera_codigo("+",$3.v,$3.v,$9.v) + gera_codigo("GOTO",L1) + gera_codigo("LABEL",L2);
	
	else $$.c = gera_atribuicao("=",$3,$5,vazio) + gera_codigo("LABEL",L1) + gera_codigo("<=",valor,$3.v,$7.v) + gera_codigo("IF",valor,L2) + $12.c + gera_codigo("-",$3.v,$3.v,$9.v) + gera_codigo("GOTO",L1) + gera_codigo("LABEL",L2);
}
;

CMD_WHILE
: TK_FUNC_WHILE '(' VERIFICA ')' TK_FUNC_START COMANDOS TK_FUNC_END
{
	string L1=gera_label("BEGINWHILE");
	string L2=gera_label("GOWHILE");
	string L3=gera_label("ENDWHILE");
	
	$$.c = $3.c + gera_codigo("LABEL", L1) + gera_codigo("IF",$3.v,L2) + gera_codigo("GOTO",L3) + gera_codigo("LABEL", L2) + $6.c + gera_codigo("GOTO", L1) + gera_codigo("LABEL", L3);
}
;

VERIFICA
: E
{
	if ($1.t!="bool")
	{
		erro("A condicao do IF | WHILE deve ser do tipo bool e nao \""+$1.t+"\".",1);
	}
	$$=$1;
}
;

CMP
: TK_CMP_IGUAL		{$$=$1;}
| TK_CMP_DIF		{$$=$1;}
| TK_CMP_MAIOR		{$$=$1;}
| TK_CMP_MAIORIG	{$$=$1;}
| TK_CMP_MENOR		{$$=$1;}
| TK_CMP_MENORIG	{$$=$1;}
;

PRINCIPAL
: TK_FUNC_PRINC TK_FUNC_START AUX_PRINCIPAL VAR_LOCAL COMANDOS TK_FUNC_END
{
	$$.c=$3.c+$4.c+$5.c;
	$$.c+=gera_codigo("RETURN","0")+gera_codigo("ENDFUNC");
}
;

AUX_PRINCIPAL
:
{
	ID_NOVO.func="showTime";
	$$.c=gera_codigo("FUNC","int","main");
}
;


E
: E TK_OP_SOMA T
{
	gera_operacao($$,$1,$2,$3);
}
| E TK_OP_SUB T
{
	gera_operacao($$,$1,$2,$3);
}
| T
{
	$$=$1;
}
;

T
: T TK_OP_MULT V
{
	gera_operacao($$,$1,$2,$3);
}
| T TK_OP_DIV V
{
	gera_operacao($$,$1,$2,$3);
}
| T TK_OP_REST V
{
	gera_operacao($$,$1,$2,$3);
}
| T TK_OP_DIVINT V
{
	gera_operacao($$,$1,$2,$3);
}
| V
{
	$$=$1;
}
;

V
: V TK_LOG_OU X
{
	gera_operacao($$,$1,$2,$3);
}
| V TK_LOG_E X
{
	gera_operacao($$,$1,$2,$3);
}
| TK_LOG_NOT X
{
	$$.t=busca_tipo_operacao($1.v,"",$2.t);
	$$.v=gera_temp($$.t);
	$$.c=$2.c+gera_codigo($1.v,$$.v,$2.v);
}
| X
{
	$$=$1;
}
;

X
: F CMP F
{
	gera_operacao($$,$1,$2,$3);
}
| F
{
	$$=$1;
}
;

F
: TK_ID
{
	$$.t=busca_tipo_dim0($1.v);
	$$.v=$1.v;
}
| TK_ID '['E']'
{
	$1.t=busca_tipo_dim1($1.v);
	$$.t=busca_tipo_dim1($1.v);
	$$.v=gera_temp($$.t);
	$$.c=$3.c+gera_atribuicao("=[]",$$,$1,$3);
}
| TK_ID '['E']' '['E']'
{
	int ysize;
	$1.t=busca_tipo_dim2($1.v,ysize);
	$$.t=busca_tipo_dim2($1.v,ysize);
	$$.v=gera_temp($$.t);
	$2.v="*";
	$5.t="int";
	$5.v=inttostr(ysize);
	gera_operacao($4,$3,$2,$5);
	$2.v="+";
	gera_operacao($7,$4,$2,$6);
	$$.c=$7.c+gera_atribuicao("=[]",$$,$1,$7);
}
| '(' E ')'
{
	$$=$2;
}
| CMD_FUNC
{
	$$.v=FUNC_CHAMA.retorno;
	$$.t=FUNC_CHAMA.tipo;
}
| G
{
	$$=$1;
}
;

G
: TK_REAL	{$$=$1;}
| TK_NUM	{$$=$1;}
| TK_BOOL	{$$=$1;}
| TK_CHAR	{$$=$1;}
| TK_STRING	{$$=$1;}
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




