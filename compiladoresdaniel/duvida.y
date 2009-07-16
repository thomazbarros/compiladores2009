%{
	#include <cstdio>
	#include <cstdlib>
	#include <iostream>
	#include <map>
	#include <vector>
	#include <deque>
	#include <stack>

	#define TOTAL_TIPO 7

	#define SOMA 0
	#define SUBTR 1
	#define MULT 2
	#define DIV 3
	#define EXP 4
	#define MOD 5
	#define TOTAL_OP 6

	using namespace std;

	struct Tipo
	{
		string base;
		bool constante;
		int ndim;
		int dim1;
		int dim2;

		Tipo(string base, int ndim = 0, int dim1 = 1, int dim2 = 1, bool constante = false) : base(base),
		ndim(ndim), dim1(dim1), dim2(dim2), constante(constante) {}
		void ajuste(string base, int ndim = 0, int dim1 = 1, int dim2 = 1)
		{
			this->base = base;
			this->ndim = ndim;
			this->dim1 = dim1;
			this->dim2 = dim2;
		}
		bool operator==(const Tipo &t)
		{
			if(this->base != t.base)
				return false;

			if(this->ndim != t.ndim)
				return false;

			if(this->ndim > 0)
			{
				if(this->dim1 != t.dim1) //conserto!
				 return false;

				if(this->ndim > 1) //conserto!
					if(this->dim2 != t.dim2)
						return false;
			}
			return true;
		}
		bool operator!=(const Tipo &t)
		{
			return !(*this == t);
		}
	};

	struct atributo
	{
		string valor, codigo;
		Tipo tipo;
		atributo *prox; // Cambalhota para fazer switch!
		atributo() : valor(""), tipo(""), codigo(""), prox(NULL) {}
	};

	struct Variavel
	{
		string nome;
		Tipo tipo;

	Variavel(string nome, string base, int ndim=0, int dim1=1, int dim2=1, bool constante=false) : nome(nome), tipo(base, ndim, dim1, dim2, constante) {}
	};

	struct Funcao
	{
		string nome;
		Tipo tipo;
		vector<Tipo> param;

	Funcao(string nome, string base, int ndim=0, int dim1=1, int dim2=1) : nome(nome), tipo(base, ndim, dim1, dim2) {}
	};

	#ifndef YYSTYPE
	#define YYSTYPE atributo
	#endif

	void yyerror(const string &);
	int yylex(void);
	string cria_temp_var(const string &tipo);
	int str_to_int(const string &str);
	string valor_padrao(string &tipo);
	string int_to_str(int n);
	string adiciona_func_global(const string &nome, const string &base, int ndim, int dim1, int dim2);
	string adiciona_func_global(const string &nome, const Tipo &tipo);
	void adiciona_var(const string &nome, const string &base, int ndim, int dim1,int dim2l, bool constante);
	void adiciona_var(const string &nome, const Tipo &tipo);
	string tipo_operacao(int operador, const string &tipo1, const string &tipo2);
	void operacao(int operador, atributo &left, atributo &primeiro, atributo &seguinte);
	void comparacao(string opr, atributo &left, atributo &primeiro, atributo &seguinte);
	void logico(string opr, atributo &left, atributo &primeiro, atributo &seguinte);
	string declaracao_de_temp(void);
	string gera_placa(const char *instr);
	void gera_caso(string opr, atributo &lista, atributo &caso, atributo *seguinte = NULL);
	bool inteiro_valido(atributo &num);
	void existe_var(atributo &atr);
	void ve_se_existe_func(atributo &atr);
	void sobe_nivel();
	void desce_nivel();

	deque<map <string, Variavel*> > var;
	map<string, Funcao*> func_global;
	map<string, unsigned int> conta_temp_var;
	int nivel = 0;
	vector<int> nivel_ctrl;
	string lista_de_variaveis;
	int nlinha = 1;

	string tab_tipo[][TOTAL_TIPO][TOTAL_TIPO] = {
	//a ordem dos tipos eh: int, double, char, bool, string
			{//SOMA
				{ "int",	"double",	"char",		"",		""},
				{ "double",	"double",	"",			"",		""},
				{ "char", 	"",			"",	"", 	"string"},
				{ "", 		"", 		"",			"bool", ""},
				{ "", 		"", 		"string", 	"", 	"string"}
			},
			{//SUBTR
				{ "int", 	"double",	"", "", ""},
				{ "double", "double",	"", "", ""},
				{ "", 		"", 		"", "", ""},
				{ "", 		"", 		"", "", ""},
				{ "", 		"", 		"", "", ""}
			},
			{//MULT
				{ "int", 	"double",	"", "",		""},
				{ "double", "double",	"", "",		""},
				{ "", 		"", 		"", "",		""},
				{ "", 		"", 		"", "bool", ""},
				{ "", 		"", 		"", "",		""}
			},
			{//DIV
				{ "int", 	"double",	"", "", ""},
				{ "double", "double",	"", "", ""},
				{ "", 		"", 		"", "", ""},
				{ "", 		"", 		"", "", ""},
				{ "", 		"", 		"", "", ""}
			},
			{//EXP
				{ "double",	"double",	"", "", ""},
				{ "double", "double",	"", "", ""},
				{ "", 		"", 		"", "", ""},
				{ "", 		"", 		"", "", ""},
				{ "", 		"", 		"", "", ""}
			},
			{//MOD
				{ "int", "",	"", "", ""},
				{ "", 	"",	"", "", ""},
				{ "", 	"",	"", "", ""},
				{ "", 	"",	"", "", ""},
				{ "", 	"",	"", "", ""}
			}
		};
			
%}

%token TK_INT TK_STRING TK_DOUBLE TK_BOOL TK_CHAR TK_ID
%token TK_TIPO_INT TK_TIPO_STRING TK_TIPO_DOUBLE TK_TIPO_BOOL TK_TIPO_CHAR
%token TK_ATRIBUICAO TK_ERR TK_MAIN TK_INI TK_FIM TK_LER TK_ESCREVER
%token TK_DESVIO TK_DESVIO_2 TK_LACO TK_LACO_2 TK_ACAO TK_DE TK_PARA TK_FACA
%token TK_CONST TK_RET TK_DIFF TK_L_OR_E TK_G_OR_E
%left '+' '-'
%left '*' '/'
%left '^' '%'

%%

TOTAL : PROG {
		#ifndef DEBUG
		cout << $1.codigo << endl;
		#endif
	}
	;

PROG : GLOBAL MAIN {
		#ifdef DEBUG
		cout << $1.codigo << $2.codigo;
		#else
		$$.codigo = "#include <iostream>\n#include <cstdlib>\n#include <math.h>\nusing namespace std;\n\n";
		$$.codigo += declaracao_de_temp() + lista_de_variaveis + $1.codigo + $2.codigo;
		#endif
	}
	;

MAIN : M2 BLOCO {
		$$.codigo = "int main(void)\n{\nint _ret = 0;\n" + $2.codigo + "return _ret;\n}\n";
		var.pop_back();
	}
	;

M2 : TK_MAIN {
		adiciona_var("_ret","int",0,1,1, false);
	}
;

RECP : ID {
		existe_var($1);
		$$.codigo = "";
		$$.valor = $1.valor;
		$$.tipo = $1.tipo;
	}
	| '[' E ']' ID {
		existe_var($4);
		if($4.tipo.ndim < 1) yyerror("Variavel " + $4.valor + "nao possui indice.");
		if($2.tipo.base != "int" || $2.tipo.ndim > 0) yyerror("Valor invalido para indice.");
		string temp1, temp3;
		temp1 = cria_temp_var("bool");
		temp3 = gera_placa("ELSE");
		$$.tipo = $4.tipo;
		$$.codigo = $2.codigo + temp1 + " = " + int_to_str($4.tipo.dim1) + " > " + $2.valor + ";\n";
		$$.codigo += "if( " + temp1 + " )\ngoto " + temp3 + ";\ncout <<\"Index fora do alcance da matriz.\" << endl;\nexit(1);\n" + temp3 + ":\n";
		$$.valor = $4.valor + "[" + $2.valor + "]";
		$$.tipo.ndim--;
		if($$.tipo.ndim == 1)
			yyerror("Sem manipulacoes de fatias.");
	}
	| '[' E ',' E ']' ID {
		existe_var($6);

		if($6.tipo.ndim < 2) yyerror("Variavel " + $6.valor + "nao possui indices.");
		if($2.tipo.base != "int" || $2.tipo.ndim > 0 || $4.tipo.base != "int" || $4.tipo.ndim > 0) yyerror("Valor invalido para indice."); 
		string temp1, temp2, temp3, temp4, temp5, temp6;
		temp1 = cria_temp_var("bool");
		temp2 = cria_temp_var("bool");
		temp3 = cria_temp_var("bool");
		temp4 = cria_temp_var("int");
		temp5 = gera_placa("ELSE");
		temp6 = cria_temp_var("int");
		$$.tipo = $6.tipo;
		$$.codigo = $2.codigo + $4.codigo + temp1 + " = " + int_to_str($6.tipo.dim1) + " > " + $2.valor + ";\n";
		$$.codigo += temp2 + " = " + int_to_str($6.tipo.dim2) + " > " + $4.valor + ";\n";
		$$.codigo += temp3 + " = " + temp1 + " && " + temp2 + ";\n";
		$$.codigo += temp4 + " = " + $2.valor + " * " + int_to_str($6.tipo.dim2) + ";\n";
		$$.codigo += temp6 + " = " + temp4 + " + "+ $4.valor + ";\n";
		$$.codigo += "if( " + temp3 + " )\ngoto " + temp5  + ";\ncout <<\"Index fora do alcance da matriz.\"\n << endl;\nexit(1);\n" + temp5 + ":\n";
		$$.valor = $6.valor + "[" + temp6 + "]";
		$$.tipo.ndim = 0;
	}
;

GAMBI : { sobe_nivel(); }
			;

CMD	: GAMBI CMD2 { $$ = $2; }
		;

BLOCO : '{' CMD '}' {
					$$ = $2;
					$$.valor = int_to_str(nivel_ctrl.back());
					desce_nivel();
				}
			;

CMD2 : LVAR '?' CMD2 { /*$$.codigo = $1.codigo + ";\n" + $3.codigo;*/
					$$.codigo = $3.codigo;
					lista_de_variaveis += $1.codigo + ";\n";
				}
		 | LOGIC '?' CMD2 { $$.codigo = $1.codigo + $3.codigo; }
		 | LOGIC TK_ATRIBUICAO RECP '?' CMD2 {
		if($3.tipo.constante) yyerror("Constantes nao sao, variaveis nao vao.");
		int temp = $3.tipo.ndim;
		if($1.tipo != $3.tipo)
		{
			#ifdef DEBUG
			//cout << var.back().at($3.valor)->tipo.base << endl; //use apenas em caso
			//extremo
			#endif
			if(!($1.tipo.base == "int" && $3.tipo.base == "double" && $1.tipo.ndim == $3.tipo.ndim && ($1.tipo.ndim>2? $1.tipo.dim1 == $3.tipo.dim1 && ($1.tipo.ndim>1? $1.tipo.dim2 == $3.tipo.dim2:1):1)))
				yyerror("Atribuicao com tipos incompativeis. " + $1.valor + "|" + $1.tipo.base + "|" + int_to_str($1.tipo.ndim) + ", " + $3.valor + "|" + $3.tipo.base + "|" + int_to_str($3.tipo.ndim));
		}
		$$.codigo = $1.codigo + $3.codigo;
		switch($3.tipo.ndim)
		{
			case 0:
				$$.codigo += $3.valor + " = " + $1.valor  + ";\n";
			break;
			case 1:
				//$$.codigo += "for(int i=0; i<" + int_to_str($3.tipo.dim1) + "; ++i)\n";
				{
					string ini, fim, index, temp;
					temp = cria_temp_var("bool");
					index = cria_temp_var("int");
					ini = gera_placa("INI_IF");
					fim = gera_placa("FIM_IF");
					$$.codigo += index + " = 0;\n";
					$$.codigo += ini + ":\n" + temp + " = " + index + " >= " + int_to_str($$.tipo.dim1) + ";\n";
					$$.codigo += "if(" + temp + ")";
					$$.codigo += $3.valor + "[" + index + "] = " + $1.valor + "[" + index + "];\n";
					$$.codigo += "++" + index + ";\ngoto " + ini + ":;\n"; 
				}
			break;
			case 2:
				//$$.codigo += "for(int i=0; i<" + int_to_str($3.tipo.dim1) + "; ++i)\n";
				//$$.codigo += "for(int j=0; j<" + int_to_str($3.tipo.dim2) + "; ++j)\n";
				{
					string ini1, fim1, index1, temp1, inteiro1;
					string ini2, fim2, index2, temp2, inteiro2;
					temp1 = cria_temp_var("bool");
					index1 = cria_temp_var("int");
					ini1 = gera_placa("INI_IF");
					fim1 = gera_placa("FIM_IF");
					temp2 = cria_temp_var("bool");
					index2 = cria_temp_var("int");
					ini2 = gera_placa("INI_IF");
					fim2 = gera_placa("FIM_IF");
					inteiro1 = cria_temp_var("int");
					inteiro2 = cria_temp_var("int");
					$$.codigo += index1 + " = 0;\n";
					$$.codigo += ini1 + ":\n" + temp1 + " = " + index1 + " >= " + int_to_str($$.tipo.dim1) + ";\n";
					$$.codigo += "if(" + temp1 + ") goto " + fim1 + ";\n";
					$$.codigo += index2 + " = 0;\n";
					$$.codigo += inteiro1 + " = " + index1 + " * " + int_to_str($3.tipo.dim2) + ";\n";
					$$.codigo += ini2 + ":\n" + temp2 + " = " + index2 + " >= " + int_to_str($$.tipo.dim2) + ";\n";
					$$.codigo += "if(" + temp2 + ") goto " + fim2 + ";\n";
					$$.codigo += inteiro2 + " = " + inteiro1 + " + " + index2 + ";\n";
					$$.codigo += $3.valor + "[" + inteiro2 + "] = " + $1.valor + "[" + inteiro2 + "];\n";
					$$.codigo += "++" + index2 + ";\ngoto " + ini2 + ";\n" + fim2 + ":;\n"; 
					$$.codigo += "++" + index1 + ";\ngoto " + ini1 + ";\n" + fim1 + ":;\n"; 
				}
			break;
			default:
			yyerror("Variavel com quantidade anormal de dimensoes (avise os cientistas de plantao).");
		}
		$$.codigo += $5.codigo;
	}
	| TK_ESCREVER LOGIC '?' CMD2 { $$.codigo = $2.codigo + "cout << " + $2.valor + ";\n" + $4.codigo; }
	| TK_LER RECP '?' CMD2 { $$.codigo = "cin >> " + $2.valor + ";\n" + $4.codigo; }
	| BLOCO CMD2 { $$.codigo = $1.codigo + $2.codigo; }
	| LACO CMD2 { $$.codigo = $1.codigo + $2.codigo; }
	| DESVIO CMD2 { $$.codigo = $1.codigo + $2.codigo; }
	| { $$.codigo = ""; }
	| TK_ERR E '?' {
			if(!inteiro_valido($2))
				yyerror("Precisamos de um codigo de erro inteiro.");
			$$.codigo = "exit (" + $2.valor + ");\n";
		}
	| TK_RET '?'{
		$$.codigo = "return _ret;\n";
	}
;

LACO : TK_LACO '(' LOGIC ')' BLOCO {
		$$.valor = "";
		$$.tipo.ajuste("");
		string iniw, fimw;
		iniw = gera_placa("INI_W");
		fimw = gera_placa("FIM_W");
		$$.codigo = iniw + ":\n" + $3.codigo + "if( !" + $3.valor + " ) goto " + fimw + ";\n";
		$$.codigo += $5.codigo + "goto " + iniw + ";\n" + fimw + ":;\n";
	}
	| TK_ACAO BLOCO TK_LACO '(' LOGIC ')' {
		$$.valor = "";
		$$.tipo.ajuste("");
		string iniw;
		iniw = gera_placa("INI_W");
		$$.codigo = iniw + ":;\n" + $2.codigo + $5.codigo + "if( " + $5.valor + " ) goto " + iniw + ";\n";
	}
	| TK_LACO_2 '(' LOGIC ')' BLOCO {
		$$.valor = "";
		$$.tipo.ajuste("");
		string iniw, fimw;
		iniw = gera_placa("INI_W");
		fimw = gera_placa("FIM_W");
		$$.codigo = iniw + ":\n" + $3.codigo + "if( " + $3.valor + " ) goto " + fimw + ";\n";
		$$.codigo += $5.codigo + "goto " + iniw + ";\n" + fimw + ":;\n";
	}
	| TK_ACAO BLOCO TK_LACO_2 '(' LOGIC ')' {
		$$.valor = "";
		$$.tipo.ajuste("");
		string iniw;
		iniw = gera_placa("INI_W");
		$$.codigo = iniw + ":\n" + $2.codigo + $5.codigo + "if( !" + $5.valor + " ) goto " + iniw + ";\n";
	}
	| TK_PARA E TK_ATRIBUICAO FOR_ID TK_DE E TK_ACAO '{' CMD2 '}' {
			string fim = gera_placa("FIM_FOR");
			string inicio = gera_placa("INI_FOR");
			string temp = cria_temp_var("bool");
			lista_de_variaveis += "int " + $4.codigo + " = " + $2.valor + ";\n";
			$$.codigo = $4.codigo + " = " + $2.valor + ";\n";
			$$.codigo += inicio + ":\n";
			$$.codigo += temp + " = " + $4.codigo + " <= " + $6.valor + ";\n";
			$$.codigo += "if(" + temp + ") goto " + fim + ";\n";
			$$.codigo += $9.codigo;
			$$.codigo += "--" + $4.codigo + ";\n";
			$$.codigo += "goto " + inicio + ";\n" + fim + ":;\n";
			desce_nivel();
		}
	| TK_DE E TK_ATRIBUICAO FOR_ID TK_PARA E TK_ACAO '{' CMD2 '}' {
			string fim = gera_placa("FIM_FOR");
			string inicio = gera_placa("INI_FOR");
			string temp = cria_temp_var("bool");
			lista_de_variaveis += "int " + $4.codigo + " = " + $2.valor + ";\n";
			$$.codigo = $4.codigo + " = " + $2.valor + ";\n";
			$$.codigo += inicio + ":\n";
			$$.codigo += temp + " = " + $4.codigo + " >= " + $6.valor + ";\n";
			$$.codigo += "if(" + temp + ") goto " + fim + ";\n";
			$$.codigo += $9.codigo;
			$$.codigo += "++" + $4.codigo + ";\n";
			$$.codigo += "goto " + inicio + ";\n" +fim + ":;\n";
			desce_nivel();
		}
;

FOR_ID : ID {
					sobe_nivel();
					//if(var.back().find($1.valor) != var.back().end()) yyerror("Indice esta ocupado em outro lugar agora.");
 					$$ = $1;
					adiciona_var($1.valor, "int", 0, 1, 1, false);
					$$.codigo = $1.valor + "_" + int_to_str(nivel_ctrl.back());
				}
			 ;

DESVIO : TK_DESVIO '(' LOGIC ')' L_CASOS{
		$$.valor = "";
		$$.tipo.ajuste("");
		$$.codigo = "";
		for(atributo *temp = &$5; temp != NULL; temp = temp->prox){
			$$.codigo += temp->codigo + "if ( !(" + $3.valor + temp->valor;
		}
	}
	| TK_DESVIO '(' LOGIC ')' BLOCO {
		$$.valor = "";
		$$.tipo.ajuste("");
		string fimf;
		fimf = gera_placa("FIM_IF");
		$$.codigo = $3.codigo + "if ( !" + $3.valor + " ) goto " + fimf + ";\n" + $5.codigo + fimf + ":;\n";
	}
	| TK_DESVIO '(' LOGIC ')' BLOCO TK_DESVIO_2 BLOCO {
		$$.valor = "";
		$$.tipo.ajuste("");
		string els, fimf;
		els = gera_placa("ELSE");
		fimf = gera_placa("FIM_IF");
		$$.codigo = $3.codigo + "if ( !" + $3.valor + " ) goto " + els + ";\n" + $5.codigo + "goto " + fimf + ";\n";
		$$.codigo += els + ":\n" + $7.codigo + fimf + ":;\n";
	}
;

L_CASOS : '=' CASO  L_CASOS {
		gera_caso(" == ", $$, $2, &$3);
	}
	| '>' CASO L_CASOS{
		gera_caso(" > ", $$, $2, &$3);
	}
	| '<' CASO L_CASOS{
		gera_caso(" < ", $$, $2, &$3);
	}
	| '>''=' CASO L_CASOS{
		gera_caso(" >= ", $$, $3, &$4);
	}
	| '<''=' CASO L_CASOS{
		gera_caso(" <= ", $$, $3, &$4);
	}
	| '!''=' CASO L_CASOS{
		gera_caso(" != ", $$, $3, &$4);
	}
	| '=' CASO {
		gera_caso(" == ", $$, $2);
	}
	| '>' CASO {
		gera_caso(" > ", $$, $2);
	}
	| '<' CASO {
		gera_caso(" < ", $$, $2);
	}
	| '>''=' CASO {
		gera_caso(" >= ", $$, $3);
	}
	| '<''=' CASO {
		gera_caso(" <= ", $$, $3);
	}
	| '!''=' CASO {
		gera_caso(" != ", $$, $3);
	}
;

CASO : LOGIC BLOCO {
		$$.valor = cria_temp_var($1.tipo.base);
		$$.tipo = $1.tipo;
		$$.codigo = $1.codigo + $$.valor + " = " + $1.valor + ";\n";
		string fimf;
		fimf = gera_placa("FIM_IF");
		$$.valor = $$.valor + ") ) goto " + fimf + ";\n" + $2.codigo + fimf + ":\n";
	}
;

GLOBAL : LVAR '?' GLOBAL { $$.codigo = $1.codigo + ";\n" + $3.codigo; }
		| L_FUNC '?' GLOBAL { $$.codigo = $1.codigo + ";\n" + $3.codigo; }
		| { 
			$$.codigo = "";
			$$.valor = "";
			$$.tipo.ajuste("");
		}
;

TIPO : TK_TIPO_INT
		| TK_TIPO_DOUBLE
		| TK_TIPO_CHAR
		| TK_TIPO_BOOL
		| TK_TIPO_STRING
;

ID : TK_ID {
		$$.valor =  "_" + $1.valor;
		$$.codigo = "";
	}
;

VAR : TK_CONST VAR2 {
				$$ = $2;
				$$.tipo.constante = true;
			}
		| VAR2
		;

VAR2 : ID { $$ = $1; $$.codigo = $1.valor + "_" + int_to_str(nivel_ctrl.back()); }
	| ID '[' TK_INT ']' {
		$$.tipo = $1.tipo;
		$$.tipo.ndim = 1;
		$$.tipo.dim1 = str_to_int($3.valor);
		$$.valor = $1.valor;
		$$.codigo = $1.valor + "_" + int_to_str(nivel_ctrl.back()) + "[" + $3.valor + "]";
	}
	| ID '[' TK_INT ',' TK_INT ']' {
		$$.tipo = $1.tipo;
			$$.tipo.ndim = 2;
		$$.tipo.dim1 = str_to_int($3.valor);
		$$.tipo.dim2 = str_to_int($5.valor);
		int temp = $$.tipo.dim1 * $$.tipo.dim2;
		$$.valor = $1.valor;
		$$.codigo = $1.valor + "_" + int_to_str(nivel_ctrl.back()) + "[" + int_to_str(temp) + "]";
	}
;

LVAR : VAR ',' LVAR {
	$$.codigo = $3.codigo + ", " + $1.codigo;
	$$.tipo.base = $1.tipo.base = $3.tipo.base;
	adiciona_var($1.valor, $1.tipo);
	var.back()[$1.valor]->tipo.constante = $1.tipo.constante;
	#ifdef DEBUG
	cout << $$.tipo.base << " + " << $1.valor << endl;
	#endif
	}
	| VAR ':' TIPO {
	$$.codigo = $3.valor + " " + $1.codigo;
	$$.tipo.base = $1.tipo.base = $3.tipo.base;
	adiciona_var($1.valor, $1.tipo);
	var.back()[$1.valor]->tipo.constante = $1.tipo.constante;
	#ifdef DEBUG
	cout << $$.tipo.base << " + " << $1.valor << endl;
	#endif
	}
;

L_FUNC : NOME_FUNC '{' CMD2 '}' {
		$$.valor = $2.valor;
		$$.tipo = $2.tipo;
		$$.codigo += $3.codigo + "return _ret;\n}\n";
		desce_nivel();
	}
;

NOME_FUNC : FUN_ID '(' L_PARAM3 ')' ':' TIPO {
		//sobe_nivel();
		$$.valor = $1.valor;
		$$.tipo = $6.tipo;
		$$.tipo.ndim = $1.tipo.ndim;
		$$.tipo.dim1 = $1.tipo.dim1;
		$$.tipo.dim2 = $1.tipo.dim2;
		$$.codigo = $6.codigo;
		if($$.tipo.ndim > 0)
			$$.codigo += "*";
		$$.codigo += " " + adiciona_func_global($1.valor, $$.tipo) + "(" + $3.codigo + ")\n{\n";
		if($$.tipo.ndim == 0)
			$$.codigo += $$.tipo.base + " _ret = " + valor_padrao($$.tipo.base) + ";\n";
		else
		{
			bool aster = $$.tipo.ndim == 1;
			$$.codigo += $$.tipo.base + "*";
			int temp = $$.tipo.dim1;
			if($$.tipo.dim1 > 1)
				temp *= $$.tipo.dim2;
			$$.codigo += " _ret;\n_ret = new " + $$.tipo.base + "[" +	int_to_str(temp) + "];\n";
		}

		adiciona_var("_ret",$$.tipo);
		for(atributo *temp = &$3; temp != NULL; temp = temp->prox){
			(func_global[$$.valor]->param).push_back(temp->tipo);
			adiciona_var(temp->valor, temp->tipo);
		}
	}
;

FUN_ID : ID { sobe_nivel(); $$ = $1; }
			 | ID '[' TK_INT ']' {
						sobe_nivel();
						$$ = $1;
						$$.tipo.ndim = 1;
						$$.tipo.dim1 = str_to_int($3.valor);
					}
			 | ID '[' TK_INT ',' TK_INT ']' {
						sobe_nivel(); $$ = $1;
						$$.tipo.ndim = 2;
						$$.tipo.dim1 = str_to_int($3.valor);
						$$.tipo.dim2 = str_to_int($5.valor);
					}
			 ;

L_PARAM3 : L_PARAM{
		$$.codigo = $1.codigo;
		$$.valor = $1.valor;
		//$$.tipo = $1.tipo;
		$$.prox = $1.prox;
	}
	| {
		$$.codigo = "";
		$$.valor = "";
		$$.tipo.ajuste("");
		$$.prox = NULL;
	}
;

VAR4 : TK_CONST VAR3 {
				$$ = $2;
				$$.tipo.constante = true;
			}
		| VAR3
		;

VAR3 : '@' VAR2 { $$ = $2; $$.codigo = '&' + $2.codigo; }
		 | VAR2
		 ;

L_PARAM : VAR4 ':' TIPO ',' L_PARAM {
		$$.codigo = $3.valor + " " + $1.codigo + ", " + $5.codigo;
		$$.valor = $1.valor;
		$$.tipo = $1.tipo;
		$$.tipo.base = $1.tipo.base = $3.tipo.base;
		$$.prox = &$5;
	}
	| VAR4 ':' TIPO {
		$$.codigo = $3.valor + " " + $1.codigo;
		$$.valor = $1.valor;
		$$.tipo = $1.tipo;
		$$.tipo.base = $1.tipo.base = $3.tipo.base;
	}
;

FUNC : TK_ACAO ID '(' L_PARAM4 ')' {
		ve_se_existe_func($2);
		$$.tipo = $2.tipo;
		$$.codigo = $4.codigo;
		if($$.tipo.ndim == 0)
		{
			$$.valor = cria_temp_var($$.tipo.base);
		}
		else
		{
			$$.valor = cria_temp_var("matriz");
			$$.codigo += $$.tipo.base + " *";
		}
		$$.codigo += $$.valor;
		$$.codigo += " = " + $2.valor + "(" + $4.valor + ");\n";
		
		int i = 0;
		for(atributo *temp = &$4; temp != NULL ; temp = temp->prox){
			if(i >= ((func_global[$2.valor])->param).size()) yyerror("Numero de parametros incorreto: " + $2.valor);
			if(((func_global[$2.valor])->param).at(i).base != temp->tipo.base) yyerror("Tipo de parametro incorreto: " + $2.valor + "\n" + temp->tipo.base + " != " + ((func_global[$2.valor])->param).at(i).base);
			i++;
		}
	}
;

L_PARAM4 : L_PARAM2{
		$$.codigo = $1.codigo;
		$$.valor = $1.valor;
		$$.tipo = $1.tipo;
		$$.prox = $1.prox;
	}
	| {
		$$.codigo = "";
		$$.valor = "";
		$$.tipo.ajuste("");
		$$.prox = NULL;
	}
	;

L_PARAM2 : LOGIC ',' L_PARAM2 {
		$$.valor = $1.valor + ", " + $3.valor;
		$$.codigo = $1.codigo + $3.codigo;
		$$.tipo = $1.tipo;
		$$.prox = &$3;
	}
	| LOGIC{
		$$.valor = $1.valor;
		$$.codigo = $1.codigo;
		$$.tipo = $1.tipo;
		$$.prox = NULL;
	}
;

LOGIC : CMPR '&' CMPR { logico ("&", $$, $1, $3); }
			| CMPR '|' CMPR { logico ("|", $$, $1, $3); }
			| '#' CMPR {
					if($2.tipo.base != "bool" && $2.tipo.ndim < 1)
						yyerror("Negamos apenas a logica.");

					$$.valor = cria_temp_var("bool");
					$$.codigo = $$.valor + " = !" + $2.valor + ";\n";
				}
			| CMPR
			;

CMPR : E '=' E {
		comparacao(" == ", $$, $1, $3);
	}
	| E '>' E {
		comparacao(" > ", $$, $1, $3);
	}
	| E '<' E {
		comparacao(" < ", $$, $1, $3);
	}
	| E TK_G_OR_E E {
		comparacao(" >= ", $$, $1, $3);
	}
	| E TK_L_OR_E E {
		comparacao(" <= ", $$, $1, $3);
	}
	| E TK_DIFF E {
		comparacao(" != ", $$, $1, $3);
	}
	| E 
	;

E : E '+' T {
	operacao(SOMA, $$, $1, $3);
	}
	| E '-' T {
	operacao(SUBTR, $$, $1, $3);
	}
	| T { $$ = $1; }
;

T : T '*' P {
	operacao(MULT, $$, $1, $3);
	}
	| T '/' P {
	operacao(DIV, $$, $1, $3);
	}
	| T '%' P {
	operacao(MOD, $$, $1, $3);
	}
	| P { $$ = $1; }
;

P : P '^' F {
	operacao(EXP, $$, $1, $3);
	}
	| F { $$ = $1; }
;
	
F : RECP
	| TK_INT
	| TK_CHAR
	| TK_BOOL
	| TK_STRING {
		$$.valor = cria_temp_var("string");
		$$.tipo = $1.tipo;
		$$.codigo = $$.valor + " = " + $1.valor +";\n";
	}
	| TK_DOUBLE
	| '(' LOGIC ')' { $$ = $2; }
	| FUNC
;

%%

void yyerror(const string &s)
{
 // fprintf(stderr, "%s\n", s.c_str());
  cout << s << " Linha: " << nlinha << ";(sem comentarios)" << endl;
	exit(1);
}

string int_to_str(int n)
{
	char buf[20];

	sprintf(buf, "%d", n);
	return buf;
}

int str_to_int(const string &str)
{
	int n;

	sscanf(str.c_str(), "%d", &n);
	return n;
}

string valor_padrao(string &tipo){
	if(tipo == "int") return "0";
	if(tipo == "double") return "0.0";
	if(tipo == "string") return "\"\"";
	if(tipo == "bool") return "false";
	if(tipo == "char") return "'\0'";
	yyerror("Tipo irreconhecivel!");
}

void existe_var(atributo &atr)
{
	string str;

	str = atr.valor;
	//str = atr.valor.substr(0, atr.valor.find_first_of('['));

	for(int i = nivel_ctrl.size() - 1; i >= 0; --i)
	{
	#ifdef DEBUG
		cout << atr.valor << "|" << i << "|" << nivel_ctrl[i] << endl;
	#endif
		if(var[i].find(str) != var.at(i).end())
		{
			atr.tipo = var.at(i)[str]->tipo;
			if(atr.valor != "_ret")
				atr.valor += "_" + int_to_str(nivel_ctrl[i]);
			return;
		}
	}
	yyerror("Variavel desconhecida: " + str);
}

void ve_se_existe_func(atributo &atr)
{
	string str;

	str = atr.valor.substr(0, atr.valor.find_first_of('['));

	if(func_global.find(str) == func_global.end())
		yyerror("A funcao " + str + " nao existe.");

	atr.tipo = func_global[str]->tipo;
}

string cria_temp_var(const string &tipo)
{
	if(conta_temp_var.find(tipo) == conta_temp_var.end())
	{
		conta_temp_var[tipo] = 0;
	}
	else
	{
		++conta_temp_var[tipo];
	}

	string ini = "t_" + tipo + int_to_str(conta_temp_var[tipo]);

	return ini;
}

string adiciona_func_global(const string &nome, const string &base, int ndim, int dim1, int dim2)
{
	if(func_global.find(nome) == func_global.end())
	{
		func_global[nome] = new Funcao(nome, base, ndim, dim1, dim2);
		return nome;
	}

	string ini = "A funcao " + nome + " ja foi declarada.";

	yyerror(ini);
	return "";
}

void adiciona_var(const string &nome, const string &base, int ndim, int dim1, int dim2, bool constante)
{
	string str;

	#ifdef DEBUG
	cout << "inserindo: " << nome << "|" << constante << "|" << int_to_str(nivel_ctrl.back()) << endl;
	#endif

	//str = nome.substr(0, nome.find_first_of('['));
	str = nome;

	if(var.back().find(nome) == var.back().end())
	{
		var.back().insert( make_pair(nome, new Variavel(nome, base, ndim, dim1, dim2, constante)));
		return;
	}

	string ini = "A variavel " + nome + " ja foi declarada.";

	yyerror(ini);
}

string adiciona_func_global(const string &nome, const Tipo &tipo)
{
	return adiciona_func_global(nome, tipo.base, tipo.ndim, tipo.dim1, tipo.dim2);
}

void adiciona_var(const string &nome, const Tipo &tipo)
{
	adiciona_var(nome, tipo.base, tipo.ndim, tipo.dim1, tipo.dim2, tipo.constante);
}

string declaracao_de_temp(void)
{
	string res = "";
	int i;
	
	if(conta_temp_var.find("int") != conta_temp_var.end())
	{
		res += "int ";
		for(i = 0; i <= conta_temp_var["int"]; ++i)
		{
			if(i)
				res += ", ";
			res += "t_int" + int_to_str(i) + " = 0";
		}
		res += ";\n";
	}
	if(conta_temp_var.find("double") != conta_temp_var.end())
	{
		res += "double ";
		for(i = 0; i <= conta_temp_var["double"]; ++i)
		{
			if(i)
				res += ", ";
			res += "t_double" + int_to_str(i);
		}
		res += ";\n";
	}
	if(conta_temp_var.find("bool") != conta_temp_var.end())
	{
		res += "bool ";
		for(i = 0; i <= conta_temp_var["bool"]; ++i)
		{
			if(i)
				res += ", ";
			res += "t_bool" + int_to_str(i);
		}
		res += ";\n";
	}
	if(conta_temp_var.find("char") != conta_temp_var.end())
	{
		res += "char ";
		for(i = 0; i <= conta_temp_var["char"]; ++i)
		{
			if(i)
				res += ", ";
			res += "t_char" + int_to_str(i);
		}
		res += ";\n";
	}
	if(conta_temp_var.find("string") != conta_temp_var.end())
	{
		res += "string ";
		for(i = 0; i <= conta_temp_var["string"]; ++i)
		{
			if(i)
				res += ", ";
			res += "t_string" + int_to_str(i);
		}
		res += ";\n";
	}

	return res;
}

string tipo_operacao(int operador, const Tipo &tipo1, const Tipo &tipo2)
{
	int a, b;

	if(tipo1.ndim > 0 || tipo2.ndim > 0)
		yyerror("Nao pode efetuar essa operacao com matrizes.");

	if(tipo1.base == "int") a = 0;
	else if(tipo1.base == "double") a = 1;
	else if(tipo1.base == "char") a = 2;
	else if(tipo1.base == "bool") a = 3;
	else if(tipo1.base == "string") a = 4;
	else yyerror("Tipo " + tipo1.base + " desconhecido.");

	if(tipo2.base == "int") b = 0;
	else if(tipo2.base == "double") b = 1;
	else if(tipo2.base == "char") b = 2;
	else if(tipo2.base == "bool") b = 3;
	else if(tipo2.base == "string") b = 4;
	else yyerror("Tipo " + tipo2.base + " desconhecido.");

	if(tab_tipo[operador][a][b] == "")
		yyerror ("Operacao entre tipos incompativeis: " + tipo1.base + ", " + tipo2.base);

	return tab_tipo[operador][a][b];
}

void operacao(int operador, atributo &left, atributo &primeiro, atributo &seguinte)
{
	string op;
	string err = "Operador desconhecido: " + int_to_str(operador);

	left.tipo = tipo_operacao(operador, primeiro.tipo, seguinte.tipo);
	switch (operador)
	{
		case SOMA:
			if(primeiro.tipo.base == "bool") op = " || ";
			else op = " + ";
			break;
		case SUBTR:
			op = " - ";
			break;
		case MULT:
			if(primeiro.tipo.base == "bool") op = " && ";
			else op = " * ";
			break;
		case DIV:
			op = " / ";
			break;
		case MOD:
			op = " % ";
			break;
		case EXP:
			left.valor = cria_temp_var("double");
			left.codigo = primeiro.codigo + seguinte.codigo + left.valor + " = pow( " + primeiro.valor + " , " + seguinte.valor + " )" + ";\n";
			return;
			break;
		default:
			yyerror(err);
	}
	left.valor = cria_temp_var(left.tipo.base);
	left.codigo = "";

	/*if(primeiro.codigo != primeiro.valor)
		left.codigo += primeiro.codigo;
	if(seguinte.codigo != seguinte.valor)
		left.codigo += seguinte.codigo;*/

	left.codigo = primeiro.codigo + seguinte.codigo + left.valor + " = " + primeiro.valor + op + seguinte.valor + ";\n"; 
}

void comparacao(string opr, atributo &left, atributo &primeiro, atributo &seguinte)
{
		#ifdef DEBUG
		cout << primeiro.tipo.base << " " << seguinte.tipo.base << endl;
		#endif
		if(primeiro.tipo.base != seguinte.tipo.base){
			if(primeiro.tipo.base == "int"){
				if(seguinte.tipo.base != "double") yyerror("Comparacao incompativel.");
				seguinte.valor = "(int) " + seguinte.valor;
			}
			else if(primeiro.tipo.base == "double"){
				if(seguinte.tipo.base != "int") yyerror("Comparacao incompativel.");
				seguinte.valor = "(double) " + seguinte.valor;
			}
			else yyerror("Comparacao incompativel.");
		}
		left.tipo.base = "bool";
		left.valor = cria_temp_var(left.tipo.base);
		left.codigo = primeiro.codigo + seguinte.codigo + left.valor + " = " + primeiro.valor + opr + seguinte.valor + ";\n";
}

void logico(string opr, atributo &left, atributo &primeiro, atributo &seguinte)
{
	if(primeiro.tipo.base != "bool" || seguinte.tipo.base != "bool" || primeiro.tipo.ndim > 0 || seguinte.tipo.ndim > 0)
		yyerror("Operacoes logicos precisam de valores logicos.");

	left.valor = cria_temp_var("bool");
	left.codigo = primeiro.codigo + seguinte.codigo + left.valor + " = " + primeiro.valor;

	if(opr == "&")
		left.codigo += " && ";
	else if(opr ==  "|")
	 left.codigo += " || ";

	left.codigo += seguinte.valor + ";\n";
}

string gera_placa(const char *instr)
{
	static int num = 1;
	return string("P_") + instr + int_to_str(num++);
}

void gera_caso(string opr, atributo &lista, atributo &caso, atributo *seguinte)
{
	lista.valor = opr + caso.valor;
	lista.tipo = caso.tipo;
	lista.codigo = caso.codigo;
	lista.prox = seguinte;
}

bool inteiro_valido(atributo &indice)
{
	if(indice.tipo.base != "int") return false;
	if(indice.tipo.ndim > 0) return false;
	
	return true;
}

void sobe_nivel()
{
	nivel++;
	nivel_ctrl.push_back(nivel);
	var.push_back(*(new map<string, Variavel*>));
}

void desce_nivel()
{
	nivel_ctrl.pop_back();
	var.pop_back();
	#ifdef DEBUG
	cout << nivel_ctrl.back() << endl;
	#endif
}

int main(void)
{
	lista_de_variaveis = "";
	nivel_ctrl.push_back(nivel);
	var.push_back(*(new map<string, Variavel*>));
  yyparse();
}
