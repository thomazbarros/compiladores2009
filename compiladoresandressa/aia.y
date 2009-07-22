/*
* Trabalho de Compiladores 2008.02
* Professor Zimbrão
*
* Grupo: Andressa de Jesus Pedrosa da Silva   - DRE: 107363052
*	 Igor de Moraes Ferreira	      - DRE: 107362226
*	 Alice de Azeredo Tomaz		      - DRE: 107413807
*/

%{
#include <iostream>
#include <string>

#define MAX_VAR 1024
#define MAX_OPERADORES 81
#define MAX_FUNCOES 1024
#define MAX_PARAM 1024

using namespace std;

typedef struct _tipo
{
	string tipo_base;
	int ndim;
	struct
	{
		int inicio, fim;
	} dim[2];
} tipo;

typedef struct _atributos
{
	string v, c;
	tipo t;
	string p;
} atributos;

typedef struct _tipo_oper
{
	string operador, op1, op2, resultado;
} tipo_oper;

typedef struct _simbolo_var
{
	string nome;
	tipo t;
} simbolo_var;

typedef struct _param
{
	string nome;
	bool referencia;
	tipo t;
} param;

typedef struct _simbolo_funcao
{
	string nome;
	tipo retorno;
	int nparam;
	param parametro[MAX_PARAM];
	string lista_parametros;
} simbolo_funcao;

struct _ntemp
{
	int i, r, c, s, b;
} ntemp = {0, 0, 0, 0, 0};

struct _ntemp_global
{
	int i, r, c, s, b;
} ntemp_global = {0, 0, 0, 0, 0};


simbolo_var TS_varlocal[MAX_VAR];
simbolo_var TS_varglobal[MAX_VAR];
simbolo_funcao TS_funcao[MAX_FUNCOES];

int nrotulos = 0;
int nvarlocal = 0;
int nvarglobal = 0;
int nparams = 0;
int nfuncao = 0;
int ir = 0;

string inic;
atributos variavelSwitch;

tipo_oper tipo_operador[MAX_OPERADORES] = {	{"+", "I", "I", "I"},
						{"+", "I", "R", "R"},
						{"+", "R", "R", "R"},
						{"+", "R", "I", "R"},
						{"+", "C", "C", "S"},
						{"+", "S", "C", "S"},
						{"+", "S", "S", "S"},
						{"+", "C", "I", "C"},

						{"-", "I", "I", "I"},
						{"-", "I", "R", "R"},
						{"-", "R", "R", "R"},
						{"-", "R", "I", "R"},

						{"*", "I", "I", "I"},
						{"*", "I", "R", "R"},
						{"*", "R", "I", "R"},
						{"*", "R", "R", "R"},

						{"/", "I", "I", "I"},
						{"/", "I", "R", "R"},
						{"/", "R", "I", "R"},
						{"/", "R", "R", "R"},

						{"==", "I", "I", "B"},
						{"==", "I", "R", "B"},
						{"==", "R", "I", "B"},
						{"==", "R", "R", "B"},
						{"==", "C", "C", "B"},
						{"==", "C", "S", "B"},
						{"==", "S", "C", "B"},
						{"==", "S", "S", "B"},
						{"==", "S", "S", "B"},

						{"!=", "I", "I", "B"},
						{"!=", "I", "R", "B"},
						{"!=", "R", "I", "B"},
						{"!=", "R", "R", "B"},
						{"!=", "C", "C", "B"},
						{"!=", "C", "S", "B"},
						{"!=", "S", "C", "B"},
						{"!=", "S", "S", "B"},
						{"!=", "S", "S", "B"},

						{">", "I", "I", "B"},
						{">", "I", "R", "B"},
						{">", "R", "I", "B"},
						{">", "R", "R", "B"},
						{">", "C", "C", "B"},
						{">", "C", "S", "B"},
						{">", "S", "C", "B"},
						{">", "S", "S", "B"},
						{">", "S", "S", "B"},

						{"<", "I", "I", "B"},
						{"<", "I", "R", "B"},
						{"<", "R", "I", "B"},
						{"<", "R", "R", "B"},
						{"<", "C", "C", "B"},
						{"<", "C", "S", "B"},
						{"<", "S", "C", "B"},
						{"<", "S", "S", "B"},
						{"<", "S", "S", "B"},

						{">=", "I", "I", "B"},
						{">=", "I", "R", "B"},
						{">=", "R", "I", "B"},
						{">=", "R", "R", "B"},
						{">=", "C", "C", "B"},
						{">=", "C", "S", "B"},
						{">=", "S", "C", "B"},
						{">=", "S", "S", "B"},
						{">=", "S", "S", "B"},

						{"<=", "I", "I", "B"},
						{"<=", "I", "R", "B"},
						{"<=", "R", "I", "B"},
						{"<=", "R", "R", "B"},
						{"<=", "C", "C", "B"},
						{"<=", "C", "S", "B"},
						{"<=", "S", "C", "B"},
						{"<=", "S", "S", "B"},
						{"<=", "S", "S", "B"},

						{"=", "I", "I", "I"},
						{"=", "R", "I", "R"},
						{"=", "R", "R", "R"},
						{"=", "C", "C", "C"},
						{"=", "S", "C", "S"},
						{"=", "S", "S", "S"},
						{"=", "B", "B", "B"}
					  };


void yyerror(const char*);
int yylex();
int yyparse();

bool existe_funcao(string nome);
void inclui_funcao(string nome, tipo retorno, string lista_parametros);
bool existe_param(string nome);
void inclui_param(string nome, bool referencia, tipo t);
bool busca_funcao(string nome, tipo *tr);
bool compara_parametros(string nome, string parametros);
bool compara_resultado(string resultado);
void erro(string msg);
string inttostr(int n);
int strtoint(string s);
void tipo_resultado(string operador, atributos op1, atributos op2, atributos &resultado);
string gera_temp(string tipo);
string gera_rotulo();
void gera_codigo_operador(atributos &ss, atributos &s1, atributos &s2, atributos &s3);
bool busca_varglobal (string nome, tipo *t);
bool pode_inserir_varglobal (string nome);
string gera_decl_temp(string tipo, string tipo_base, int &n);
string gera_varglobal_temp();
string gera_varlocal_temp();
string parte_vetor(tipo t);
string quebra_codigo_lista(string vetorid, string lsttemp , string lstcodtemp);
string quebra_codigo_parametro(string nometemp, string vetorid, string lsttemp, string lstcodtemp, string tiporet);
void insere_varglobal (string nome, tipo t);
bool busca_varlocal (string nome, tipo *t);
bool busca_varparam(string nome, tipo *t);
bool pode_inserir_varlocal (string nome);
void insere_varlocal (string nome, tipo t);

#define YYSTYPE atributos

%}

%token TK_ID TK_CONST_INTEIRO TK_CONST_REAL TK_CONST_BOOL_V TK_CONST_BOOL_F TK_CONST_CARACTER TK_CONST_STRING
%token TK_INTEIRO TK_STRING TK_REAL TK_BOOLEAN TK_CARACTER TK_VAZIO
%token TK_ATRIBUICAO TK_INICIO_BLOCO TK_FIM_BLOCO
%token TK_PRINCIPAL TK_SE TK_SENAO TK_PARA TK_ATE TK_FACA TK_ENQUANTO TK_RETORNO TK_ENTRADA TK_SAIDA TK_SWITCH TK_PADRAO TK_CASO
%token TK_OU TK_E TK_NEGACAO TK_CMP_MAIOR TK_CMP_MENOR TK_CMP_MAIOR_IGUAL
%token TK_CMP_MENOR_IGUAL TK_CMP_IGUALDADE TK_CMP_DIFERENCA TK_MAIS TK_MENOS TK_VEZES 
%token TK_DIV TK_POR_VALOR TK_POR_REFERENCIA TK_PROTOTIPO

%left TK_DIV TK_VEZES
%left TK_MAIS TK_MENOS


%start SL

%%

SL		: S
		{
			cout << "#include <string>\n#include <iostream>\n\nusing namespace std;\n\n" +  $1.c << endl;
		}
		;

S		: VARS_GLOBAIS PROTOTIPOS BLOCO_PRIN FUNCOES
		{
			$$.c = $1.c + $2.c + $3.c + $4.c;
		}
		;

PROTOTIPOS	:   PROTOTIPOS PROTOTIPO ';'
		{
			$$.c += $2.c;
		}
		|
		{
			$$.c = "";
		}
		;

PROTOTIPO	: TK_PROTOTIPO TIPORETORNO TK_ID '('  PARAMETROS ')'
		{
			if($2.c == "V"){
				$$.c = $2.c + " " + $3.v + "(" + $5.c+ ");\n";
				inclui_funcao($3.v,$2.t, $5.p);
				nfuncao++;
				nparams = 0;
			}
			else{
				$$.c =  "void " + $3.v + "(" + $5.c+ ", int &RI);\n";
				inclui_funcao($3.v,$2.t, $5.p);
				nfuncao++;
				nparams = 0;

			}
		}
		|
		;

PARAMETROS	: LISTAPARAMETROS
		{
			$$.p = "#" + $1.t.tipo_base;
			$$.c = $1.c;
		}
		|
		;

LISTAPARAMETROS	: LISTAPARAMETROS ',' PARAMETRO
		{
			$$.p += "#" + $3.t.tipo_base;
			$$.c = $1.c + "," + $3.c;
		}
		| PARAMETRO
		{
			$$.p = "#" + $1.t.tipo_base;
			$$.c = $1.c;
		}
		;

PARAMETRO	: TIPO TIPO_PASSAGEM TK_ID
		{
			nparams++;
			bool varbool;
			$$.t = $1.t;
			$$.c = $1.c + $2.c + $3.v;

			if ($2.v == "&")
			{
				varbool = true;
			}
			else
			{
				varbool = false;
			}

			inclui_param($3.v, varbool, $1.t);
			$$.p = "#" + $1.t.tipo_base;
		}
		;

VARS_GLOBAIS	: VAR_GLOBAL ';' VARS_GLOBAIS
		{
			$$.c = gera_varglobal_temp(); + "\n" + $3.c;
		}
		|
		{
			$$.c = "";
		}
		;

VAR_GLOBAL	: VAR_GLOBAL ',' TK_ID ARRAY
		{
			$$.t = $1.t;
			$3.t = $1.t;
			$1.t.ndim = $4.t.ndim;
			$1.t.dim[0].fim = $4.t.dim[0].fim;
			$1.t.dim[1].fim = $4.t.dim[1].fim;
			insere_varglobal($3.v , $1.t);
		}
		| TIPO TK_ID ARRAY
		{
			$$.t = $1.t;
			$2.t = $1.t;
			$1.t.ndim = $3.t.ndim;
			$1.t.dim[0].fim = $3.t.dim[0].fim;
			$1.t.dim[1].fim = $3.t.dim[1].fim;
			insere_varglobal($2.v , $1.t);
		}
		;

TIPO		: TK_INTEIRO
		{
			$$.t.tipo_base = "I";
			$$.c = "int";
			$$.v = $1.v;
		}
		| TK_REAL
		{
			$$.t.tipo_base= "R";
			$$.c = "float";
			$$.v = $1.v;
		}
		| TK_BOOLEAN
		{
			$$.t.tipo_base= "B";
			$$.c = "int";
			$$.v = $1.v;
		}
		|
		TK_CARACTER
		{
			$$.t.tipo_base = "C";
			$$.c = "char";
			$$.v = $1.v;
		}
		| TK_STRING
		{
			$$.t.tipo_base= "S";
			$$.c = "char *";
			$$.v = $1.v;
		}
		;

ARRAY		: '[' TK_CONST_INTEIRO ']'
		{
			$$.t.ndim = 1;
			$$.t.dim[0].fim = atoi(($3.v).c_str());
			$$.t.dim[1].fim = 0;
		}
		| '[' TK_CONST_INTEIRO ']' '[' TK_CONST_INTEIRO ']'
		{
			$$.t.ndim = 2;
			$$.t.dim[0].fim = atoi(($3.v).c_str());
			$$.t.dim[1].fim = atoi(($5.v).c_str());
		}
		|
		{
			$$.t.ndim = 0;
			$$.t.dim[0].fim = 0;
			$$.t.dim[1].fim = 0;
		}
		;

BLOCO_PRIN	: TK_PRINCIPAL CORPO
		{
			$$.c = "int main ()\n" + $2.c;
		}
		;

CORPO		: TK_INICIO_BLOCO VARS_LOCAIS COMANDOS TK_FIM_BLOCO
		{
			$$.c = "{\n" + gera_varlocal_temp() +  $3.c + "\n}\n";
		}
		;

VARS_LOCAIS	: VAR_LOCAL ';' VARS_LOCAIS
		|
		;

VAR_LOCAL		: VAR_LOCAL ',' TK_ID ARRAY INICIO
		{
			$$.t = $1.t;
			$3.t = $1.t;
			$1.t.ndim = $4.t.ndim;
			$1.t.dim[0].fim = $4.t.dim[0].fim;
			$1.t.dim[1].fim = $4.t.dim[1].fim;
			insere_varlocal($3.v , $1.t);

			if($5.v != "")
			{
				inic +=$5.c + $3.v + "=" + $5.v + ";\n";
			}
		}
		| TIPO TK_ID ARRAY INICIO
		{
			$$.t = $1.t;
			$2.t = $1.t;
			$1.t.ndim = $3.t.ndim;
			$1.t.dim[0].fim = $3.t.dim[0].fim;
			$1.t.dim[1].fim = $3.t.dim[1].fim;

			insere_varlocal($2.v , $1.t);

			if ($4.v != "")
			{
				if (($4.v).c_str()[0] == '#')
				{
					inic += quebra_codigo_lista($2.v, $4.v , $4.c);
				}
				else
				{
					inic += $4.c;
					atributos ss, s1, s2, s3;
					s1 = $2;
					s2.v = "=";
					s3 = $4;
					gera_codigo_operador(ss, s1,s2 ,s3 );
					inic += ss.c;
				}
			}
		}
		;

INICIO		: TK_ATRIBUICAO E
		{
			$$.v = $2.v;
			$$.t = $2.t;
			$$.c = $2.c;
		}
		| TK_ATRIBUICAO  '{' LST_E '}'
		{
			$$.v = $3.v;
			$$.c = $3.c;
		}
		| TK_ATRIBUICAO  '{' LST_LST_E '}'
		|
		{
			$$.v = "";
			$$.c = "";
		}
		;

LST_LST_E	: LST_LST_E ',' '{' LST_E '}'
		| '{' LST_E '}'
		;

COMANDOS	: COMANDOS COMANDO
		{
			$$.c = $1.c + $2.c;
		}
		|
		{
			$$.c = "";
		}
		;

COMANDO		: CMD_E ';'
		| CMD_SWITCH
		| CMD_FOR
		| CMD_WHILE ';'
		| CMD_IF
		| CMD_RETURN ';'
		| CMD_READ ';'
		| CMD_WRITE ';'
		;

CMD_READ	: TK_ENTRADA '(' F ')'
		{
			$$.c = $3.c + "cin >>" + $3.v + " ;\n";
		}
		;

CMD_WRITE	: TK_SAIDA '(' E ')'
		{
			if (($3.t.ndim != 0) && ($3.t.tipo_base == "S"))
			{
				$$.c = $3.c + "cout << &" + $3.v  + ";\n ";
			}
			else
			{
				$$.c = $3.c + "cout << " + $3.v  + ";\n ";
			}
		}
		;

CMD_RETURN	: TK_RETORNO E
		{
			$$.c = $2.c + "RI = " + $2.v + ";\nreturn;\n";
			compara_resultado($2.t.tipo_base);
		}
		| TK_RETORNO  ';'
		;

CMD_WHILE	: TK_FACA BLOCO TK_ENQUANTO '(' E ')'
		{
			string rotulo = gera_rotulo();
			string teste = gera_temp("B");
			string codigo;
			codigo += rotulo + ": ";
			codigo += $2.c;
			codigo += $5.c;
			codigo += teste + " =" + $5.v + ";\n";
			codigo += "if (" + teste + " ) \n";
			codigo += "goto " + rotulo + ";\n";
			$$.c = codigo;
		}
		;



CMD_SWITCH 	: TK_SWITCH '(' TK_ID ')' TK_INICIO_BLOCO CASES TK_FIM_BLOCO
		{	
			//if (busca_varlocal ($3.v, &(variavelSwitch.t)));
			//else if (busca_varglobal ($3.v, &(variavelSwitch.t))) erro("nao variavel");
			//else erro("nao variavel");
			variavelSwitch = $3;
			variavelSwitch.t.tipo_base = "I";
			$$.c = $6.c;
		}
		;

CASES		: CASES CASE
		{
			$$.c = $1.c + $2.c;
		}
		|
		{
			$$.c = "";
		}
		;

CASE		:TK_CASO CTE BLOCO
		{
			string codigo;
			string rotulo = gera_rotulo();
			string teste = gera_temp("B");

			atributos vteste;
			vteste.v = teste;
			vteste.t.tipo_base = "B";

			atributos sinal;
			sinal.v = "==";
			gera_codigo_operador(vteste,variavelSwitch, sinal ,$2);
			codigo += vteste.c;
			codigo += teste +" =  ! " + teste + " ;\n";
			codigo += "if("  +  teste  +   ")\n";
			codigo += "goto " + rotulo + ";\n";
			codigo += $3.c;
			codigo += rotulo + ": ;\n";

			$$.c = codigo;

		}
		|TK_PADRAO BLOCO
		{	
			$$.c = $2.c;
		}
		;



CMD_FOR		: TK_PARA TK_CONST_INTEIRO TK_ATE TK_CONST_INTEIRO BLOCO
		{
			string inicio = gera_temp("I");
			string fim = gera_temp("I");
			string teste = gera_temp("I");
			string rotulo = gera_rotulo();
			string codigo;

			codigo = inicio + " = " + $2.v +";\n";
			codigo += fim + " = " + $4.v +";\n";
			codigo += rotulo + " : " + $5.c;
			codigo += inicio + " = " + inicio + " + 1" + ";\n";
			codigo += teste + " = "+ inicio + " <= " + fim +";\n";
			codigo += "if(" + teste +")\n";
			codigo += "goto " + rotulo + ";\n";

			$$.c = codigo;
		}
		;

CMD_IF		: TK_SE '(' E ')' BLOCO
		{
			string codigo;
			string rotulo = gera_rotulo();
			string teste = gera_temp("B");

			codigo += $3.c;
			codigo += teste +" =  ! " + $3.v + " ;\n";
			codigo += "if("  +  teste  +   ")\n";
			codigo += "goto " + rotulo + ";\n";
			codigo += $5.c;
			codigo += rotulo + ": ;\n";

			$$.c = codigo;
		}
		| TK_SE '(' E ')' BLOCO TK_SENAO BLOCO
		{
			string codigo;
			string rotulo = gera_rotulo();
			string teste = gera_temp("B");
			string rotulo2 = gera_rotulo();

			codigo += $3.c;
			codigo += teste +" =  ! " + $3.v + " ;\n";
			codigo += "if("  +  teste  +   ")\n";
			codigo += "goto " + rotulo + ";\n";
			codigo += $5.c;
			codigo += "goto " + rotulo2 + ";\n";
			codigo += rotulo + ": ;\n";
			codigo += $7.c;
			codigo += rotulo2 + ": ;\n";

			$$.c = codigo;
		}
		;

BLOCO		: TK_INICIO_BLOCO COMANDOS TK_FIM_BLOCO
		{
			$$.c = $2.c;
		}
		;

CMD_E		: E
		|
		;

E		: E TK_ATRIBUICAO E1
		{
			$$.c = $1.c;
			$2.v = "=";
			gera_codigo_operador($$,$1,$2,$3);
		}
		| E1
		;

E1		: E1 TK_OU E2
		{
			gera_codigo_operador($$,$1,$2,$3);
		}
		| E1 TK_E E2
		{
			gera_codigo_operador($$,$1,$2,$3);
		}
		| E2
		;

E2		: E2 TK_CMP_MAIOR E3
		{
			gera_codigo_operador($$,$1,$2,$3);
		}
		| E2 TK_CMP_MENOR E3
		{
			gera_codigo_operador($$,$1,$2,$3);
		}
		| E2 TK_CMP_MAIOR_IGUAL E3
		{
			gera_codigo_operador($$,$1,$2,$3);
		}
		| E2 TK_CMP_MENOR_IGUAL E3
		{
			gera_codigo_operador($$,$1,$2,$3);
		}
		| E2 TK_CMP_IGUALDADE E3
		{
			gera_codigo_operador($$,$1,$2,$3);
		}
		| E2 TK_CMP_DIFERENCA E3
		{
			gera_codigo_operador($$,$1,$2,$3);
		}
		| E3
		;

E3		: E3 TK_MAIS E4
		{
			gera_codigo_operador($$,$1,$2,$3);
		}
		| E3 TK_MENOS E4
		{
			gera_codigo_operador($$,$1,$2,$3);
		}
		| E4
		;

E4		: E4 TK_VEZES E5
		{
			gera_codigo_operador($$,$1,$2,$3);
		}
		| E4 TK_DIV E5
		{
			gera_codigo_operador($$,$1,$2,$3);
		}
		| E5
		;

E5		: TK_MAIS F
		| TK_MENOS F
		| TK_NEGACAO F
		| F
		;

F		: TK_ID
		{
			busca_varglobal($1.v, & $1.t);
			busca_varlocal($1.v, & $1.t);
			busca_varparam($1.v, & $1.t);

			$$.t = $1.t;
		}
		| TK_ID '(' ')'
		{
			busca_funcao($1.v, & $1.t);
			$$ = $1;
			$$.v = gera_temp($1.t.tipo_base);
			$$.c = quebra_codigo_parametro($$.v, $1.v,  "" , "", $1.t.tipo_base);
			compara_parametros($1.v, "");
		}
		| TK_ID '(' LST_E ')'
		{

			busca_funcao($1.v, & $1.t);
			$$ = $1;

			if ($1.t.tipo_base =="V")
			{
				$$.v = "";
			}
			else
			{
				$$.v = gera_temp($1.t.tipo_base);
			}

			$$.c = quebra_codigo_parametro($$.v, $1.v,  $3.v , $3.c, $1.t.tipo_base);

			compara_parametros($1.v, $3.p);
		}
		| TK_ID '[' E ']'
		{
			busca_varglobal($1.v, & $1.t);
			busca_varlocal($1.v, & $1.t);

			$$.t = $1.t;

			$$.c = $3.c;

			string aux ="";

			if ($3.t.ndim !=0 )
			{
				$$.c += aux + " = " + $3.v + ";\n";
				$3.v = aux;
			}

			if ($1.t.tipo_base == "S")
			{
				$$.c += aux + " = " + $3.v + "* 256" + ";\n";
				$3.v = aux;

				$$.v =  $1.v + "[" + $3.v + "]";
			}
			else
			{
				$$.v =  $1.v + "[" + $3.v + "]";
			}
		}
		| TK_ID '[' E ']' '[' E ']'
		{
			busca_varglobal($1.v, & $1.t);
			busca_varlocal($1.v, & $1.t);
			$$.t = $1.t;

			string codigo;

			string i = gera_temp("I");
			codigo += i	+ " = " + $3.v + ";\n";
			codigo += i + " = " + i + " * " + inttostr($1.t.dim[1].fim ) + ";\n";

			atributos ss, s1, s2, s3;
			s1.v = i;
			s1.t.tipo_base = "I";
			s2.v = "+";
			s3 = $6;
			gera_codigo_operador(ss,s1,s2,s3);

			codigo += ss.c;

			$$.c = $3.c + $6.c + codigo; 

			string aux = gera_temp($3.t.tipo_base);

			if ($1.t.tipo_base == "S")
			{
				$$.c += aux + " = " + ss.v + "* 256" + ";\n";
				$3.v = aux;

				$$.v =  $1.v + "[" + aux + "]";
			}
			else
			{
				$$.v =  $1.v + "[" + ss.v + "]";
			}

		}
		| '(' E ')'
		{
			$$.t.tipo_base = $2.t.tipo_base;
			$$.v = $2.v;
			$$.c =  $2.c;
		}
		|CTE
		;

CTE		: TK_CONST_INTEIRO
		{
			$$.t.tipo_base = "I";
		}
		| TK_CONST_REAL
		{
			$$.t.tipo_base = "R";
		}
		| TK_CONST_BOOL_V
		{
			$$.v = inttostr(1);
			$$.t.tipo_base = "B";
		}
		| TK_CONST_BOOL_F
		{
			$$.v = inttostr(0);
			$$.t.tipo_base = "B";
		}
		| TK_CONST_CARACTER
		{
			$$.t.tipo_base = "C";
		}
		| TK_CONST_STRING
		{
			$$.t.tipo_base = "S";
		}
		;

LST_E		: LST_E ',' E
		{
			$$.v += "#" + $3.v;
			$$.c += "#" + $3.c;
			$$.p += "#" + $3.t.tipo_base;
		}
		| E
		{
			$$.v = "#" + $1.v;
			$$.c = "#" + $1.c;
			$$.p += "#" + $1.t.tipo_base;
		}
		;

FUNCOES		: FUNCOES FUNCAO
		{
			$$.c = $1.c + $2.c;
		}
		|
		{
			$$.c = "";
		}
		;

FUNCAO		: TIPORETORNO TK_ID '(' PARAMETROS ')' CORPO
		{
			string retorno;
			string aux;

			if (nparams >= 1)
			{
				if ($1.v == "vanus")
				{
					aux = "";
					$$.c = "void " + $2.v + "(" + $4.c + $1.c + aux + ")\n" + $6.c;
				}
				else
				{
					aux = " &RI";
					$$.c = "void " + $2.v + "(" + $4.c + "," + $1.c + aux + ")\n" + $6.c;
				}
				ir = ir + 1;
			}
			else
			{
				$$.c = "void " + $2.v + "(" + $1.c + aux  + ")\n" + $6.c;
				ir = ir + 1;
			}

			if(busca_funcao($2.v, &$2.t) == false)
			{
				inclui_funcao($2.v, $1.t, $4.p);
				nfuncao++;
				nparams = 0;
			}
		}
		;

TIPORETORNO	: TIPO
		{
			$$.t = $1.t;
			$$.c = $1.c;
		}
		| TK_VAZIO
		{
			$$.t.tipo_base = "V";
		}
		;

TIPO_PASSAGEM	: TK_POR_VALOR
		{
			$$.c = " ";
		}
		| TK_POR_REFERENCIA
		{
			$$.c = " &";
		}
		;

%%

#include "lex.yy.c"


int main(int argc, char* argv[])
{
	yyparse();
}

string gera_temp(string tipo)
{
	char variavel[200];

	if (tipo == "I")
	{
		sprintf(variavel, "TI%d", ntemp.i++);
	}
	else if (tipo == "R")
	{
		sprintf(variavel, "TR%d", ntemp.r++);
	}
	else if (tipo == "C")
	{
		sprintf(variavel, "TC%d", ntemp.c++);
	}
	else if (tipo == "S")
	{
		sprintf(variavel, "TS%d", ntemp.s++);
	}
	else if (tipo == "B")
	{
		sprintf(variavel, "TB%d", ntemp.b++);
	}
	return variavel;
}

bool existe_funcao(string nome)
{
	int i;
	for (i = 0; i < nfuncao; i++)
	{
		if (TS_funcao[i].nome == nome)
		{
			return true;
		}

	}
	return false;

}
void inclui_funcao(string nome, tipo retorno, string lista_parametros)
{
	if(existe_funcao(nome))
	{
		erro("Funcao ja declarada.");
	}
	TS_funcao[nfuncao].nome = nome;
	TS_funcao[nfuncao].retorno = retorno;
	TS_funcao[nfuncao].lista_parametros = lista_parametros;

}

bool existe_param(string nome)
{
	int i;
	int j;

	for (i = 0; i < nfuncao; i++)
	{
		if (TS_funcao[i].nome == nome)
		{

			for (j = 0; j < TS_funcao[i].nparam; j++)
			{
				if (TS_funcao[i].parametro[j].nome == nome)
				{
					return true;
				}
			}

		}

	}
	return false;
}

void inclui_param(string nome, bool referencia, tipo t)
{
	int p;
	if(existe_param(nome))
	{
		erro("Parametro ja declarado.");
	}
	p = TS_funcao[nfuncao].nparam;
	TS_funcao[nfuncao].parametro[p].nome = nome;
	TS_funcao[nfuncao].parametro[p].referencia = referencia;
	TS_funcao[nfuncao].parametro[p].t = t;
	TS_funcao[nfuncao].nparam++;
}

bool busca_funcao(string nome, tipo *tr)
{
	int i;
	for(i = 0 ; i < nfuncao; i++)
	{
		if(TS_funcao[i].nome == nome)
		{
			if(tr != NULL)
			{
				*tr = TS_funcao[i].retorno;
			}
			
			return true;
		}
	}
	return false;
}

bool busca_varparam(string nome, tipo *t)
{
	if (nfuncao != 0)
	{
		int i, j;
		i = nfuncao - 1;
		for(j = 0 ; j < TS_funcao[i].nparam; j++)
		{
			if (TS_funcao[i].parametro[j].nome == nome )
			{
				if (t != NULL)
				{
					*t = TS_funcao[i].parametro[j].t;
				}
				return true;
			}
		}
		return false;
	}
}

bool pode_inserir_varlocal (string nome)
{
	if (nvarlocal > MAX_VAR)
	{
		erro("Numero de variaveis maximo atingido.");
	}
	if (busca_varlocal(nome, NULL) )
	{
		erro("Variavel ja definida.");
	}
	return true;
}

void insere_varlocal (string nome, tipo t)
{
	if (pode_inserir_varlocal(nome) )
	{
		TS_varlocal[nvarlocal].nome = nome;
		TS_varlocal[nvarlocal].t = t;
		nvarlocal++;
	}
	else
	{
		erro("Nao foi possivel declarar a variavel local" +  nome + ".");
	}
}

void yyerror (const char * st)
{
	printf("%s\n", st);
}

void erro(string msg)
{
	cout << msg << endl;
	exit(-1);
}

string inttostr(int n)
{
	char linha[20];
	sprintf(linha, "%d", n);
	return linha;
}

int strtoint(string s)
{
	int n;
	sscanf(s.c_str(), "%d", &n);
	return n;
}

void tipo_resultado(string operador, atributos op1, atributos op2, atributos &resultado)
{
	int i;
	for(i = 0; i < MAX_OPERADORES; i++)
	{
		if (tipo_operador[i].operador == operador && op1.t.tipo_base == tipo_operador[i].op1 && op2.t.tipo_base == tipo_operador[i].op2)
		{
					resultado.t.tipo_base = tipo_operador[i].resultado;
					return;
		}
	}
	resultado.t.tipo_base = "ERRO";
}

string gera_decl_temp(string tipo, string tipo_base, int &n)
{
	string c;
	int i;
	for (i = 0; i < n; i++)
	{
		if(tipo_base == "S")
		{
			c += tipo + " " + "T" + tipo_base +  inttostr(i) + "[256];\n";
		}
		else
		{
			c += tipo + " " + "T" + tipo_base +  inttostr(i) + ";\n";
		}
	}
	n = 0;
	return c;
}

string gera_varglobal_temp()
{
	int i, aux;
	string c;

	for (i = 0; i < nvarglobal; i++)
	{
		if (TS_varglobal[i].t.tipo_base == "B" || TS_varglobal[i].t.tipo_base == "I")
		{
			c += "int " + TS_varglobal[i].nome + parte_vetor(TS_varglobal[i].t) + ";\n";
		}
		else if (TS_varglobal[i].t.tipo_base == "S" )
		{
			c += "char " + TS_varglobal[i].nome + parte_vetor(TS_varglobal[i].t) + ";\n";
		}
		else if (TS_varglobal[i].t.tipo_base == "C" )
		{
			c+= "char " + TS_varglobal[i].nome +  parte_vetor(TS_varglobal[i].t) + ";\n";
		}
		else if (TS_varglobal[i].t.tipo_base == "R" )
		{
			c+= "float " + TS_varglobal[i].nome + parte_vetor(TS_varglobal[i].t) +";\n";
		}
		else
		{
			erro("Erro na gramatica");
		}
	}

	c += gera_decl_temp("int", "I", ntemp_global.i);
	c += gera_decl_temp("float", "R", ntemp_global.r);
	c += gera_decl_temp("int", "B", ntemp_global.b);

	aux = ntemp_global.s;
	c += gera_decl_temp("char", "S", ntemp_global.s);

	for (i = 0; i < aux; i++)
	{
		c += "TS" + inttostr(i) + "[255] = '\\0';\n";
	}
	
	return c;
}

bool compara_parametros(string nome, string parametros)
{
	int i;
	for(i = 0; i < nfuncao; i++)
	{
		if (TS_funcao[i].nome == nome && TS_funcao[i].lista_parametros == parametros)
		{
			return true;
		}
	}
	
	erro("Parametros invalidos.");
	return false;
}

bool compara_resultado(string resultado)
{
	if (TS_funcao[nfuncao - 1].retorno.tipo_base == resultado)
	{
		return true;
	}
	else
	{
		erro("Valor retornado invalido");
		cout << nvarlocal << endl;
	}
}

void gera_codigo_operador(atributos &ss, atributos &s1, atributos &s2, atributos &s3)
{
	tipo_resultado(s2.v,s1,s3,ss);
	if (ss.t.tipo_base == "ERRO")
	{
		if(s1.t.tipo_base == "")
		{
			erro("'" + s1.v + "'" + " nao foi declarada.");
		}
		else if (s3.t.tipo_base == "")
		{
			erro("'" + s3.v + "'" + " nao foi declarada.");
		}
		else
		{
			erro("O operador " + s2.v + " nao se aplica a " + s1.t.tipo_base + " e " + s3.t.tipo_base + ".");
		}
	}
	else
	{
		if (s2.v == "=")
		{
			if (s3.t.ndim != 0)
			{
				string aux = gera_temp(s3.t.tipo_base);
				ss.c = s1.c + s3.c + aux + " = " + s3.v + ";\n"+  s1.v + " = " + aux + ";\n";

				if (s1.t.tipo_base == "S")
				{
				        string aux = gera_temp(s1.t.tipo_base);
					ss.c = s1.c + s3.c;
					if (s1.t.ndim != 0)
					{
						ss.c += "strncpy(" + aux + ", &" + s3.v + ", 256);\n";
						ss.c += "strncpy(&" + s1.v+", " + aux + ", 256);\n";
					}
					else
					{
						ss.c += "strncpy(" + aux + ", &" + s3.v + ", 256);\n";
						ss.c += "strncpy(" + s1.v + "," + aux + ", 256);\n";
					}
				}
			}
			else
			{
				if (s3.t.tipo_base == "S")
				{
					string aux = gera_temp(s3.t.tipo_base);
					ss.c = s1.c + s3.c + "strncpy(" + aux + "," + s3.v + ", 256);\n";
					if (s1.t.ndim != 0)
					{
						ss.c += "strncpy(&" + s1.v + ", " + aux + ", 256);\n";
					}
					else
					{
						ss.c += "strncpy(" + s1.v + ", " + aux + ", 256);\n";
					}
				}
				else
				{
					ss.c = s1.c + s3.c + s1.v + " = " + s3.v + ";\n";
				}
			}
		}
		else
		{
			if ((s1.t.ndim != 0) && (s3.t.ndim != 0))
			{
				ss.v = gera_temp(ss.t.tipo_base);
				string aux1 = gera_temp(s3.t.tipo_base);
				string aux2 = gera_temp(s3.t.tipo_base);
				ss.c = s1.c + s3.c + aux1 + " = " + s1.v + ";\n" + aux2 + " = " + s3.v + ";\n"+ ss.v + " = " + aux1 + s2.v + aux2 + ";\n"; 
			}
			else if (s1.t.ndim != 0)
			{
				ss.v = gera_temp(ss.t.tipo_base);
				string aux1 = gera_temp(s1.t.tipo_base);
				ss.c = s1.c + s3.c + aux1 + " = " + s1.v + ";\n" + ss.v + " = " + aux1 + s2.v + s3.v + ";\n";
			}
			else if (s3.t.ndim != 0)
			{
				ss.v = gera_temp(ss.t.tipo_base);
				string aux1 = gera_temp(s3.t.tipo_base);
				ss.c = s1.c + s3.c + aux1 + " = " + s3.v + ";\n" + ss.v + " = " + s1.v + s2.v + aux1 + ";\n";
			}
			else
			{
				if (( s1.t.tipo_base == "S") || ( s3.t.tipo_base == "S"))
				{
					if (s2.v == "+")
					{
						ss.v = gera_temp(ss.t.tipo_base);
						ss.c = s1.c + s3.c + "strncpy(" + ss.v + "," + s1.v + ",256);\n" + "strcat(" + ss.v + "," + s3.v + ");\n";
						ss.t.tipo_base = "S";
					}
				}
				else
				{
					ss.v = gera_temp(ss.t.tipo_base);
					ss.c = s1.c + s3.c + ss.v + " = " + s1.v + s2.v + s3.v + ";\n";
				}
			}
		}
	}
}

bool busca_varglobal (string nome, tipo *t)
{
	int i;
	for(i = 0; i < nvarglobal; i++)
	{
		if(TS_varglobal[i].nome == nome)
		{
			if (t != NULL)
			{
				*t = TS_varglobal[i].t;
			}
			return true;
		}
	}
	return false;
}

bool pode_inserir_varglobal (string nome)
{
	if (nvarglobal > MAX_VAR)
	{
		erro("Numero de variaveis globais maximo atingido.");
	}
	
	if (busca_varglobal(nome, NULL))
	{
		erro("Variavel global ja definida.");
	}

	return true;
}

void insere_varglobal (string nome, tipo t)
{
	if (pode_inserir_varglobal(nome))
	{
		TS_varglobal[nvarglobal].nome = nome;
		TS_varglobal[nvarglobal].t = t;
		nvarglobal++;
	}
	else
	{
		erro("Nao foi possivel declarar a variavel global" +  nome + ".");
	}
}

bool busca_varlocal (string nome, tipo *t)
{
	int i;
	for(i = 0 ; i < nvarlocal; i++)
	{
		if(TS_varlocal[i].nome == nome)
		{
			if (t != NULL)
			{
				*t = TS_varlocal[i].t;
			}
			return true;
		}
	}
	return false;
}

string gera_rotulo()
{
	char rotulo[200];

	sprintf(rotulo,"ROT%d", nrotulos++);

	return rotulo;
}

string gera_varlocal_temp()
{
	int i, aux;
	string c;

	for (i = 0; i < nvarlocal; i++)
	{

		if (TS_varlocal[i].t.tipo_base == "B" || TS_varlocal[i].t.tipo_base == "I")
		{
			c += "int " + TS_varlocal[i].nome + parte_vetor(TS_varlocal[i].t) + ";\n";
		}
		else if (TS_varlocal[i].t.tipo_base == "S" )
		{
			c += "char " + TS_varlocal[i].nome + parte_vetor(TS_varlocal[i].t) + ";\n";
		}
		else if (TS_varlocal[i].t.tipo_base == "C" )
		{
			c+= "char " + TS_varlocal[i].nome + parte_vetor(TS_varlocal[i].t) + ";\n";
		}
		else if (TS_varlocal[i].t.tipo_base == "R" )
		{
			c+= "float " + TS_varlocal[i].nome + parte_vetor(TS_varlocal[i].t) + ";\n";
		}
		else
		{
			erro("Erro na gramatica");
		}

	}

	c += gera_decl_temp("int", "I", ntemp.i);
	c += gera_decl_temp("float", "R", ntemp.r);
	c += gera_decl_temp("int", "B", ntemp.b);
	
	aux = ntemp.s;
	c += gera_decl_temp("char", "S", ntemp.s);
	
	for (i = 0; i < aux; i++)
	{
		c += "TS" + inttostr(i) + "[255] = '\\0';\n";
	}
	
	nvarlocal = 0;
	
	c+= inic;
	inic = "";
	
	return c;
}

string parte_vetor(tipo t)
{
	string codigo;

	int ehString = 1;

	if(t.tipo_base == "S")
	{
		ehString = 256;
	}

	if (t.ndim == 0)
	{
		if(ehString == 1)
		{
			codigo = "";
		}
		else
		{
			codigo = "[256]";
		}
	}
	else if (t.ndim == 1)
	{
		codigo = "[" + inttostr(t.dim[0].fim * ehString) + "]";

	}
	else if (t.ndim == 2)
	{
		codigo = "[" + inttostr(t.dim[0].fim * t.dim[1].fim * ehString ) + "]";
	}
	return codigo;
}

string quebra_codigo_lista(string vetorid, string lsttemp , string lstcodtemp)
{
	string saida;
	string a;
	string b;

	int i = 0;
	int j = 0;
	int contador = 0;
	
	getchar();
	
	while(1)
	{
		a = "";
		b = "";
		
		while(lsttemp[i] != '#' && lsttemp[i] != '\0')
		{
			a += lsttemp[i];
			i++;
		}
		
		while(lstcodtemp[j] != '#' && lstcodtemp[j] != '\0')
		{
			b += lstcodtemp[j];
			j++;
		}

		if (a[0] != '\0' || b[0] != '\0')
		{
			saida += b  + vetorid + "[" + inttostr(contador)+ "]" + "=" + a + ";\n";
			contador++;
		}

		if (lstcodtemp[j] == '\0')
		{
			break;
		}
		i++;
		j++;

	}
	return saida;
}

string quebra_codigo_parametro(string nometemp, string vetorid, string lsttemp, string lstcodtemp, string tiporet)
{
	string saida;
	string a;
	string b;
	string lista;
	string lista_completa;

	int i = 0, j = 0, contador = 0;

	getchar();

	while(1)
	{
		a = "";
		b = "";

		while (lsttemp[i] != '#' && lsttemp[i] != '\0')
		{
			a += lsttemp[i];
			i++;
		}

		while (lstcodtemp[j] != '#' && lstcodtemp[j] != '\0')
		{
			b += lstcodtemp[j];
			j++;
		}

		if(a[0] != '\0' || b[0] != '\0')
		{
			saida += b;
			if (a != "")
			{
				lista += a + ", ";
			}
			contador++;
		}

		if (lstcodtemp[j] == '\0')
		{
			break;
		}
		i++;
		j++;
	}
	

	if(tiporet != "V")
	{
		lista_completa = vetorid + "(" + lista + nometemp + ");\n";
		saida+= lista_completa;
		return saida;
	}
	else
	{

		int len = lista.length();
		lista[len - 2] = ' ';
		string saida = vetorid + "("+  lista + ");\n";
		return saida;
	}

}
