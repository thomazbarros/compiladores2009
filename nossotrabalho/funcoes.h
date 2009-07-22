#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <map>
using namespace std;

#define YYSTYPE atributos_compilador
#define SOMA 0
#define SUBTR 1
#define MULT 2
#define DIV 3
#define MOD 4
#define NUM_TIPOS 5
#define INTEIRO 1
#define REAL 2
#define CARACTER 3
#define STRING 4
#define BOOLEANO 5

/*
ordem das operacoes : SOMA,SUBTRACAO,MULTIPLICACAO,DIVISAO,MODULO
ordem dos tipos : int, double, char, string, bool
vazio = ERRO 
*/
struct Tipo{
    string base;
    int n_dim,dim1,dim2;
    
    Tipo(string base, int ndim = 0, int dim1 = 1, int dim2 = 1) : base(base),n_dim(ndim), dim1(dim1), dim2(dim2) {}
    void modifica_valores(string nova_base, int novo_n_dim = 0, int d0 = 1, int d1 =1)
    {
	base = nova_base;
	n_dim = novo_n_dim;
	dim1 = d0;
	dim2 = d1;
    }
}; 

struct atributos_compilador{
    Tipo tipo;
    string valor,codigo;
    atributos_compilador() : valor(""), tipo(""), codigo(""){}
}; 

struct variavel
{
	string nome;
	Tipo tipo;
	variavel(string nome, string base, int ndim=0, int dim1=1, int dim2=1) : nome(nome), tipo(base, ndim, dim1, dim2) {}
};

struct funcao
{
	string nome;
	Tipo tipo;
	vector<Tipo> param;
	funcao(string nome, string base, int ndim=0, int dim1=1, int dim2=1) : nome(nome), tipo(base, ndim, dim1, dim2) {}
};

deque<map <string, variavel*> > var;
map<string, funcao*> func_global;
int nlinha = 1;
vector<int> nivel;
int total_niveis = 0;
int numLinha = 1;
map<string, unsigned int> contador;
//string variaveis = "";
string lista_de_variaveis;

string tabela_operacoes [][NUM_TIPOS][NUM_TIPOS] = {
	{
		{"int","double","char","",""},
		{"double","double","","",""},
		{"","char","char","string",""},
		{"","","","","bool"},
		{"","","string","string",""},
	},
	{
                {"int","double","","",""},
                {"double","double","","",""},
                {"","","","",""},
                {"","","","",""},
                {"","","","",""},
        },
	{
                {"int","double","","",""},
                {"double","double","","",""},
                {"","","","",""},
                {"","","","","bool"},
                {"","","","",""},
        },
	{
                {"int","double","","",""},
                {"double","double","","",""},
                {"","","","",""},
                {"","","","",""},
                {"","","","",""},
        },
	{
                {"int","","","",""},
                {"","","","",""},
                {"","","","",""},
                {"","","","",""},
                {"","","","",""},
        }
};
		
void yyerror(string erro)
{
    cout << erro << "Linha :" << numLinha << ";" << endl;
    exit(1);
}

string inttostr(int n) 
{
	char buf[20];
	sprintf(buf,"%d",n);
	return buf;
}

int strtoint(string st) 
{
	int n;
	sscanf(st.c_str(),"%d",&n);
	return n;
}

string tipo_resultado(int tipo, Tipo &primeiro, Tipo &segundo)
{
    int i,j;
    
    if(primeiro.base == "int"){
	i = INTEIRO;
    }
    else
    {
	if(primeiro.base == "double")
	{
	    i = REAL;
	}
	else
	{
	    if(primeiro.base == "char")
	    {
		i = CARACTER;
	    }
	    else
	    {
		if(primeiro.base == "string")
		{
		    i = STRING;
		}
	   	else
		{
		    if(primeiro.base == "bool")
		    {
			i = BOOLEANO;
		    }
		    else
		    {
			yyerror("Tipo "+primeiro.base+" inexistente");
    		    }
		}
	    }
	}
    }

    if(segundo.base == "int"){
	j = INTEIRO;
    }
    else
    {
	if(segundo.base == "double")
	{
	    j = REAL;
	}
	else
	{
	    if(segundo.base == "char")
	    {
		j = CARACTER;
	    }
	    else
	    {
		if(segundo.base == "string")
		{
		    j = STRING;
		}
	   	else
		{
		    if(segundo.base == "bool")
		    {
			j = BOOLEANO;
		    }
		    else
		    {
			yyerror("Tipo"+segundo.base+"inexistente");
    		    }
		}
	    }
	}
    }
    if(tabela_operacoes[tipo][i][j] == "")
    {
	yyerror("Operacao invalida entre "+primeiro.base+" e "+segundo.base);
    }
    return tabela_operacoes[tipo][i][j];

}

string transforma_variavel(const string &n)
{
	if(contador.find(n) == contador.end())
	{
		contador[n] = 0;
	}
	else
	{
		++contador[n];
	}

	string n2 = "t_" + n + inttostr(contador[n]);

	return n2;
}

void realizar_operacao(int tipo, atributos_compilador &esquerda, atributos_compilador &primeiro, atributos_compilador &segundo)
{
    string operador;
    esquerda.tipo = tipo_resultado(tipo,primeiro.tipo,segundo.tipo);
    switch(tipo)
    {
	case SOMA : 
	    operador = " + ";
	    break;
	case SUBTR :
	    operador = " - ";
	    break;
	case MULT :
	    operador = " * ";
	    break;
	case DIV :
	    operador = " / ";
            break;
	case MOD :
	    operador = " % ";
	    break;
	default :
	    yyerror("Operador invalido : " + inttostr(tipo));	    
    }
    esquerda.valor = transforma_variavel(esquerda.tipo.base);
    esquerda.codigo = primeiro.codigo + segundo.codigo + esquerda.valor + " = " + primeiro.valor + operador + segundo.valor + ";\n";
}

string adiciona_func_global(const string &nome, const string &base, int ndim, int dim1, int dim2)
{
	if(func_global.find(nome) == func_global.end())
	{
		func_global[nome] = new funcao(nome, base, ndim, dim1, dim2);
		return nome;
	}

	yyerror("Ja existe uma funcao com o nome " + nome);
	return "";
}

string adiciona_func_global(const string &nome, const Tipo &tipo)
{
	return adiciona_func_global(nome, tipo.base, tipo.n_dim, tipo.dim1, tipo.dim2);
}

void adiciona_var(const string &nome, const string &base, int ndim, int dim1, int dim2)
{
	string str;

	str = nome;

	if(var.back().find(nome) == var.back().end())
	{
		var.back().insert( make_pair(nome, new variavel(nome, base, ndim, dim1, dim2)));
		return;
	}

	yyerror("Ja existe uma variavel com o nome " + nome);

}

void adiciona_var(const string &nome, const Tipo &tipo) 
{
	adiciona_var(nome, tipo.base, tipo.n_dim, tipo.dim1, tipo.dim2);
}

string valor_inicial_padrao(atributos_compilador atr)
{
	if(atr.tipo.base == "int")
	{
		return "0";
	}
	if(atr.tipo.base == "double")
	{
		return "0.0";
	}
	if(atr.tipo.base == "char")
	{
		return "'\0'";
	}
	if(atr.tipo.base == "string")
	{
		return "\"\"";
	}
	if(atr.tipo.base == "bool")
	{
		return "false";
	}
	yyerror("Tipo desconhecido : "+  atr.tipo.base);
}

void gera_nome_funcao(atributos_compilador &esquerda, atributos_compilador &primeiro, atributos_compilador &segundo, atributos_compilador &quarto)
{
    esquerda.valor = segundo.valor;
    esquerda.codigo = primeiro.codigo;
    esquerda.tipo = primeiro.tipo;
    esquerda.tipo.modifica_valores(primeiro.tipo.base,segundo.tipo.n_dim,segundo.tipo.dim1,segundo.tipo.dim2);
    
    if(esquerda.tipo.n_dim > 0)
    {
    	esquerda.codigo += "*";
    }
    esquerda.codigo += " " + adiciona_func_global(segundo.valor, esquerda.tipo) + "(" + quarto.codigo + ")\n{\n";
    if(esquerda.tipo.n_dim == 0)
    {
        esquerda.codigo += esquerda.tipo.base + " _ret = " + valor_inicial_padrao(esquerda) + ";\n";
    }
    else
    {
    	esquerda.codigo += esquerda.tipo.base + "*";
	int temp = esquerda.tipo.dim1;
	if(esquerda.tipo.dim1 > 1)
	{
	    temp *= esquerda.tipo.dim2;
	}
        
	esquerda.codigo += " _ret;\n_ret = new " + esquerda.tipo.base + "[" +	inttostr(temp) + "];\n";
   
    }
    adiciona_var("_ret",esquerda.tipo);
    for(atributos_compilador *temp = &quarto; temp != NULL; temp = temp->prox)
    {
	(func_global[esquerda.valor]->param).push_back(temp->tipo);
	adiciona_var(temp->valor, temp->tipo);
    }
}

string label(const char *n)
{
	static int num = 1;
	return string("P_") + n + inttostr(num++);
}

void gera_if(atributos_compilador &n, atributos_compilador n2, atributos_compilador n3)
{
	n.valor = "";
	n.tipo.modifica_valores("");
	string inicio;
	inicio = label("INICIO"); 
	n.codigo = inicio + ":;\n" + "if( " + n2.valor + " ) goto " + n3.valor + ";\n";
}

void gera_if_else(atributos_compilador &n, atributos_compilador n2, atributos_compilador n3, atributos_compilador n4)
{
	n.valor = "";
	n.tipo.modifica_valores("");
	string inicio;
	inicio = label("INICIO"); 
	n.codigo = inicio + ":;\n" + "if( " + n2.valor + " ) goto " + n3.valor + ";\n";
	n.codigo = inicio + ":;\n" + "if( " + n2.valor + " ) goto " + n4.valor + ";\n";
}

void gera_while(atributos_compilador &n, atributos_compilador n2, atributos_compilador n3)
{
	n.valor = "";
	n.tipo.modifica_valores("");
	string inicio, fim;
	inicio = label("INICIO");
	fim = label("FIM");
	n.codigo = inicio + ":\n" + n2.codigo + "if( !" + n2.valor + " ) goto " + fim + ";\n";
	n.codigo += n3.codigo + "goto " + inicio + ";\n" + fim + ":;\n";
}

void gera_do_while(atributos_compilador &n, atributos_compilador n2, atributos_compilador n3)
{
	n.valor = "";
	n.tipo.modifica_valores("");
	string inicio;
	inicio = label("INICIO"); 
	n.codigo = inicio + ":;\n" + n2.codigo + n3.codigo + "if( " + n3.valor + " ) goto " + inicio + ";\n";
}

void gera_for(atributos_compilador &n, atributos_compilador n2, atributos_compilador n3, atributos_compilador n4,
atributos_compilador n5)
{
	n.valor = "";
	n.tipo.modifica_valores("");
	string inicio, fim;
	inicio = label("INICIO");
	fim = label("FIM");
	n.codigo = inicio + ":\n" + n2.codigo + "if( " + n3.valor + " ) goto " + fim + ";\n";
	n.codigo += n4.codigo + n5.codigo + "goto " + inicio + ";\n" + fim + ":;\n";
}


void gera_n(string n, atributos_compilador &n2, atributos_compilador n3, atributos_compilador n4)
{
	if(n3.tipo.base != n4.tipo.base){
		if(n3.tipo.base == "int"){
			if(n4.tipo.base != "double") yyerror("Não é possível resolver.");
				n4.valor = "(int) " + n4.valor;
			}
			else if(n3.tipo.base == "double"){
				if(n4.tipo.base != "int") yyerror("Não é possível resolver.");
				n4.valor = "(double) " + n4.valor;
			}
			else yyerror("Não é posível resolver.");
		}
		n2.tipo.base = "bool";
		n2.valor = transforma_variavel(n2.tipo.base);
		n2.codigo = n3.codigo + n4.codigo + n2.valor + " = " + n3.valor + n + n4.valor + ";\n";
}

void gera_test(string n, atributos_compilador &n2, atributos_compilador  n3, atributos_compilador n4)
{
	if(n3.tipo.base != "bool" || n4.tipo.base != "bool" || n3.tipo.n_dim > 0 || n4.tipo.n_dim > 0)
		yyerror("Não é possível fazer o teste.");

	n2.valor = transforma_variavel("bool");
	n2.codigo = n3.codigo + n4.codigo + n2.valor + " = " + n3.valor + ' ' + n + ' ' + n4.valor + ";\n";
}

bool verifica_existencia_funcao(atributos_compilador &atr)
{
	string str;

	str = atr.valor.substr(0, atr.valor.find_first_of('['));

	if(func_global.find(str) == func_global.end())
	{
		return false;
	}	

	atr.tipo = func_global[str]->tipo;
	return true;
}

void chama_funcao(atributos_compilador &esquerda,atributos_compilador &primeiro, atributos_compilador &terceiro)
{
	bool existe = verifica_existencia_funcao(primeiro);
	if(existe)
	{
		esquerda.tipo = primeiro.tipo;
		esquerda.codigo = terceiro.codigo;
		if(esquerda.tipo.n_dim == 0)
		{
			esquerda.valor = transforma_variavel(esquerda.tipo.base);
		}
		else
		{
			esquerda.valor = transforma_variavel("matriz");
			esquerda.codigo += esquerda.tipo.base + " *";
		}
		esquerda.codigo += esquerda.valor;
		esquerda.codigo += " = " + primeiro.valor + "(" + terceiro.valor + ");\n";
		
		int i = 0;
		for(atributos_compilador *temp = &terceiro; temp != NULL ; temp = temp->prox){
			if(i >= ((func_global[primeiro.valor])->param).size()) yyerror("Numero de parametros incorreto: " + primeiro.valor);
			if(((func_global[primeiro.valor])->param).at(i).base != temp->tipo.base) yyerror("Tipo de parametro incorreto: " + primeiro.valor + "\n" + temp->tipo.base + " != " + ((func_global[primeiro.valor])->param).at(i).base);
			i++;
		}
	}
	yyerror("A funcao com nome "+primeiro.valor+" nao existe");
}

void cria_id(atributos_compilador &esquerda,atributos_compilador &primeiro)
{
	esquerda.valor =  "_" + primeiro.valor; 
	esquerda.codigo = "";
}

void negacao(string logica,atributos_compilador &esquerda, atributos_compilador &segundo)
{
	if(logica != "!")	
	{	
		yyerror("Simbolo desconhecido :"+logica);		
	}

	if(segundo.tipo.base != "bool" && segundo.tipo.n_dim < 1)
	{
		yyerror("Comparacao invalida.");
	}

	esquerda.valor = transforma_variavel("bool");
	esquerda.codigo = esquerda.valor + " = " + logica + segundo.codigo + ";\n";
}

/*void comparacao(string simbolo)
{
	if(simbolo == ">") 
	{
	
	}
	if(simbolo == "<")	
	{

	}	
	if(simbolo == ">=")
	{
	
	}	
	if(simbolo == "<=")	
	{
	
	}	
	if(simbolo == "==")
	{
	
	}
	
	yyerror("Simbolo desconhecido :"+simbolo);		
}

void expressoes_logicas(string logica,atributos_compilador &esquerda, atributos_compilador &primeiro = NULL, atributos_compilador &segundo = NULL, atributos_compilador &terceiro = NULL)
{
	esquerda.valor = transforma_variavel("bool");
	if(logica == "!")	
	{	
		if(segundo.tipo.base != "bool" && segundo.tipo.n_dim < 1)
		{
			yyerror("Comparacao invalida.");
		}
		esquerda.codigo = esquerda.valor + " = !" + segundo.codigo + ";\n";
		return; 		
	}
	
	if(primeiro == NULL || terceiro == NULL)
	{
		yyerror("Argumentos invalidos para uma expressao regular");
	}*(new map<string, Variavel*>)

	if(primeiro.tipo.base != "bool" || terceiro.tipo.base != "bool" || primeiro.tipo.ndim > 0 || seguinte.tipo.ndim > 0)
		yyerror("Tipos invalidos para operacoes logicas.");

	if(logica == "&&")
	{
		
		esquerda.codigo = primeiro.codigo + terceiro.codigo + esquerda.valor + " =" + primeiro.valor + "&&" + seguinte.valor + ";\n";
		return;
	}	
	if(logica == "||")
	{
		esquerda.codigo = primeiro.codigo + terceiro.codigo + esquerda.valor + " =" + primeiro.valor + "||" + seguinte.valor + ";\n";
		return;
	}	
	
	yyerror("Simbolo desconhecido :"+logica);
}*/

void sobe_nivel()
{
	total_niveis++;
	nivel.push_back(total_niveis);
	var.push_back(*(new map<string, variavel*>));
	
}
void desce_nivel()
{
	nivel.pop_back();
	var.pop_back();
}

string declarar_variaveis_temporarias()
{
	string resultado = "";

	if(contador.find("int") != contador.end())
	{
		resultado += "int ";
		for(int i = 0; i < contador["int"]; i++)
		{
			resultado += "_int"+inttostr(i)+"=0";
			if(i+1 != contador["int"])
			{
				resultado += ",";
			}
		}
		resultado += ";\n";
	}
	if(contador.find("bool") != contador.end())
	{
		resultado += "int ";
		for(int i = 0; i < contador["bool"]; i++)
		{
			resultado += "_bool"+inttostr(i);
			if(i+1 != contador["bool"])
			{
				resultado += ",";
			}
		}
		resultado += ";\n";
	}
	if(contador.find("char") != contador.end())
	{
		for(int i = 0; i < contador["char"]; i++)
		{
			resultado += "_char"+inttostr(i);
			if(i+1 != contador["char"])
			{
				resultado += ",";
			}
		}
		resultado += ";\n";	
	}
	if(contador.find("string") != contador.end())
	{
		for(int i = 0; i < contador["string"]; i++)
		{
			resultado += "_string"+inttostr(i);
			if(i+1 != contador["string"])
			{
				resultado += ",";
			}		
		}
		resultado += ";\n";		
	}
	if(contador.find("double") != contador.end())
	{
		for(int i = 0; i < contador["double"]; i++)
		{
			resultado += "_double"+inttostr(i);
			if(i+1 != contador["double"])
			{
				resultado += ",";
			}		
		}
		resultado += ";\n";		
	}

	return resultado;
}

void declara_main(atributos_compilador &esquerda, atributos_compilador &segundo){
	
	esquerda.codigo = "int main(void)\n{\nint _ret = 0;\n" + segundo.codigo + "return _ret;\n}\n";
	var.pop_back();
}

void gera_codigo_funcao(atributos_compilador &esquerda, atributos_compilador &primeiro, atributos_compilador &segundo){
	
	esquerda.codigo = segundo.codigo + "return _ret;\n}\n";
	esquerda.valor = primeiro.valor;
	esquerda.tipo = primeiro.tipo;
	desce_nivel();
}

void gera_variavel(string e, atributos_compilador &n, atributos_compilador &n2)
{
	n = n2;
	n.codigo = e + n2.valor + "_"  + inttostr(nivel.back()) + ";\n";
}

void gera_vetor(string e, atributos_compilador &n, atributos_compilador &n2, atributos_compilador &n3)
{
	n.tipo = n2.tipo;
	n.tipo.n_dim = 1;
	n.tipo.dim1 = strtoint(n3.valor); 
	n.codigo = e + n2.valor + "_" + inttostr(nivel.back()) + "[" + n3.valor + "]; \n";
}

void gera_matriz(string e, atributos_compilador &n, atributos_compilador &n2, atributos_compilador &n3, atributos_compilador &n4)
{
	n.tipo = n2.tipo;
	n.tipo.n_dim = 2;
	int n5 = strtoint(n3.valor) * strtoint(n4.valor);
	n.tipo.dim1 = strtoint(n3.valor);
	n.tipo.dim2 = strtoint(n4.valor);
	n.codigo = e + n2.valor + "_" + inttostr(nivel.back()) + "[" + inttostr(n5) + "]; \n";
}

void gera_entrada(atributos_compilador &esquerda, atributos_compilador &terceiro)
{
	esquerda.codigo = "cin >> "+ terceiro.valor +";\n";
}

void gera_saida(atributos_compilador &esquerda , atributos_compilador &terceiro)
{
	esquerda.codigo = "cout <<" + terceiro.valor + ";\n";  
}

void gera_saida_PL(atributos_compilador &esquerda)
{
	esquerda.codigo = "cout << endl;\n";
}

void gera_saida_PL_EXP(atributos_compilador &esquerda , atributos_compilador &terceiro)
{
	esquerda.codigo = "cout <<" + terceiro.valor + "<< endl;\n";	
}

void gera_inicializacao(atributos_compilador &esquerda, atributos_compilador &primeiro, atributos_compilador &segundo)
{
	esquerda.codigo = "#include <iostream>\n#include <cstdlib>\nusing namespace std;\n\n";
	esquerda.codigo += declarar_variaveis_temporarias() + lista_de_variaveis + primeiro.codigo + segundo.codigo;
}

void gera_codigo_VG_LID(atributos_compilador &esquerda, atributos_compilador &primeiro, atributos_compilador &segundo,atributos_compilador &terceiro)
{
	esquerda.codigo = segundo.codigo + terceiro.codigo; 
	segundo.tipo = primeiro.tipo;	
}

void gera_codigo_VG_funcao(atributos_compilador &esquerda, atributos_compilador &primeiro, atributos_compilador &segundo)
{
	esquerda.codigo = primeiro.codigo + segundo.codigo;
}

void gera_codigo_VG_vazio(atributos_compilador &esquerda)
{
	esquerda.codigo = "";
	esquerda.valor = "";
	esquerda.tipo.modifica_valores("");
}

void gera_codigo_LID_maisvar(atributos_compilador &esquerda, atributos_compilador &primeiro, atributos_compilador &terceiro)
{
	primeiro.tipo.base = esquerda.tipo.base;
	esquerda.codigo = terceiro.codigo + " ," + primeiro.codigo;
	adiciona_var(primeiro.valor,primeiro.tipo);
}

void gera_codigo_LID(atributos_compilador &esquerda, atributos_compilador &primeiro)
{
	primeiro.tipo.base = esquerda.tipo.base;
	esquerda.codigo = esquerda.tipo.base + " " + primeiro.codigo;
	adiciona_var(primeiro.valor,primeiro.tipo);
}

void gera_FUN_ID(atributos_compilador &esquerda,atributos_compilador &primeiro)
{
	sobe_nivel();
	esquerda.codigo = primeiro.codigo;
}

void gera_FUN_ID_vet(atributos_compilador &esquerda,atributos_compilador &primeiro,atributos_compilador &terceiro)
{
	sobe_nivel();
	esquerda.codigo = primeiro.codigo;
	esquerda.tipo.n_dim = 1;
	esquerda.tipo.dim1 = strtoint(terceiro.valor); 
}

void gera_FUN_ID_mat(atributos_compilador &esquerda,atributos_compilador &primeiro,atributos_compilador &terceiro,atributos_compilador &quinto)
{
	sobe_nivel();
	esquerda.codigo = primeiro.codigo;
	esquerda.tipo.n_dim = 2;
	esquerda.tipo.dim1 = strtoint(terceiro.valor); 
	esquerda.tipo.dim2 = strtoint(quinto.valor); 	
}

void gera_bloco(atributos_compilador &esquerda,atributos_compilador &segundo)
{
	esquerda = segundo;
	esquerda.valor = inttostr(nivel.back());
	desce_nivel();
}

void verifica_variavel(atributos_compilador &n)
{
	string n2 = n.valor;
	for(int i = nivel.size() - 1; i >= 0; --i)
	{
		if(var[i].find(n2) != var.at(i).end())
		{
			n.tipo = var.at(i)[n2]->tipo;
			if(n.valor != "_ret")
				n.valor += "_" + inttostr(nivel[i]);
			return;
		}
	}
	yyerror("Erro");
}

void gera_va(atributos_compilador &n, atributos_compilador &n2)
{
		verifica_variavel(n2);
		n.codigo = "";
		n.valor = n2.valor;
		n.tipo = n2.tipo;
}

void gera_va_vetor(atributos_compilador &n, atributos_compilador &n2, atributos_compilador &n3)
{
	verifica_variavel(n2);
	if(n2.tipo.n_dim < 1) yyerror("Erro");
	if(n3.tipo.base != "int" || n3.tipo.n_dim > 0) yyerror("Erro");
	string temp1, temp2;
	temp1 = transforma_variavel("bool");
	temp2 = label("ELSE");
	n.tipo = n2.tipo;
	n.codigo = n3.codigo + temp1 + " = " + inttostr(n2.tipo.dim1) + " > " + n3.valor + ";\n";
	n.codigo += "if( " + temp1 + " )\ngoto " + temp2 + ";\ncout <<\"Index fora do alcance da matriz.\" << endl;\nexit(1);\n" + temp2 + ":\n";
	n.valor = n2.valor + "[" + n3.valor + "]";
	n.tipo.n_dim--;
}

void gera_va_matriz(atributos_compilador &n, atributos_compilador &n2, atributos_compilador &n3, atributos_compilador &n4)
{
	verifica_variavel(n2);
	if(n2.tipo.n_dim < 2) yyerror("Erro");
	if(n4.tipo.base != "int" || n4.tipo.n_dim > 0 || n3.tipo.base != "int" || n3.tipo.n_dim > 0) yyerror("Erro");
	string temp1, temp2, temp3, temp4, temp5, temp6;
	temp1 = transforma_variavel("bool");
	temp2 = transforma_variavel("bool");
	temp3 = transforma_variavel("bool");
	temp4 = transforma_variavel("int");
	temp5 = label("ELSE");
	temp6 = transforma_variavel("int");
	n.tipo = n2.tipo;
	n.codigo = n4.codigo + n3.codigo + temp1 + " = " + inttostr(n.tipo.dim1) + " > " + n4.valor + ";\n";
	n.codigo += temp2 + " = " + inttostr(n4.tipo.dim2) + " > " + n3.valor + ";\n";
	n.codigo += temp3 + " = " + temp1 + " && " + temp2 + ";\n";
	n.codigo += temp4 + " = " + n4.valor + " * " + inttostr(n2.tipo.dim2) + ";\n";
	n.codigo += temp6 + " = " + temp4 + " + "+ n3.valor + ";\n";
	n.codigo += "if( " + temp3 + " )\ngoto " + temp5  + ";\n cout <<\"Index fora do alcance da matriz.\"\n << endl;\nexit(1);\n" + temp5 + ":\n";
	n.valor = n4.valor + "[" + temp6 + "]";
	n.tipo.n_dim = 0;
}

void gera_va2(int n, string n2, atributos_compilador &n3, atributos_compilador &n4)
{
	n3.tipo = tipo_resultado(n, n3.tipo, n4.tipo);
	n3.valor = transforma_variavel(n3.tipo.base);
	n3.codigo = n3.codigo + n4.codigo + n3.valor + " = " + n3.valor + n2 + n4.valor + "\n;";
}

void gera_vl(atributos_compilador &n, atributos_compilador &n2, atributos_compilador &n3, atributos_compilador &n4)
{
	n.codigo = n2.valor + " " + n4.codigo + ", " + n3.codigo;
	n.tipo.base = n2.tipo.base = n3.tipo.base = n4.tipo.base;
	adiciona_var(n3.valor, n3.tipo);
}

void gera_corpo(atributos_compilador &esquerda,atributos_compilador &segundo,atributos_compilador &terceiro)
{
	esquerda = terceiro;
	esquerda.valor = inttostr(nivel.back());
	desce_nivel();
	lista_de_variaveis += segundo.codigo + ";\n";
}
