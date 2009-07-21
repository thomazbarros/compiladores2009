#define YYSTYPE atributos_compilador
#define SOMA 0
#define SUBTR 1
#define MULT 2
#define DIV 3
#define MOD 4
#define NUM_TIPOS = 5
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
int nlinha = 1;
int nivel = 1;
int total_niveis = 0;
int numLinha = 1;
map<string, unsigned int> contador;
string variaveis = "";

string[][NUM_TIPOS][NUM_TIPOS] tabela_operacoes = 
	{
		{"int","double","char","",""}
		{"double","double","","",""}
		{"","char","char","string",""}
		{"","","","","bool"}
		{"","","string","string",""}
	},
	{
                {"int","double","","",""}
                {"double","double","","",""}
                {"","","","",""}
                {"","","","",""}
                {"","","","",""}
        },
	{
                {"int","double","","",""}
                {"double","double","","",""}
                {"","","","",""}
                {"","","","","bool"}
                {"","","","",""}
        },
	{
                {"int","double","","",""}
                {"double","double","","",""}
                {"","","","",""}
                {"","","","",""}
                {"","","","",""}
        },
	{
                {"int","","","",""}
                {"","","","",""}
                {"","","","",""}
                {"","","","",""}
                {"","","","",""}
        };
		
void yyerror(string& erro)
{
    cout << s << "Linha :" << numLinha << ";" << endl;
    exit(1);
}

void realizar_operacao(int tipo, atributos_compilador &esquerda, atributos_compilador &primeiro, atributos_compilador &segundo)
{
    string operador;
    esquerda.tipo = tipo_resultado(tipo,primeiro.tipo,segundo.tipo)
    switch(tipo)
    {
	case SOMA : 
	    operador = " + ";
	    break;
	case SUBTR :
	    operador = " - ";
	    break;
	case MULT :
	    operador = " * ".
	    break;
	case DIV :
	    operador = " / ";
            break;
	case MOD :
	    operador = " % ";
	    break;
	default :
	    yyerror("Operador invalido : " + int_to_str(tipo));	    
    }
    esquerda.valor = cria_temp_var(esquerda.tipo.base);
    esquerda.codigo = primeiro.codigo + segundo.codigo + esquerda.valor + " = " + primeiro.valor + operador + segundo.valor + ";\n";
}

void tipo_resultado(int tipo, string &primeiro, string &segundo)
{
    int i,j;
    
    if(primeiro == "int"){
	i = INTEIRO;
    }
    else
    {
	if(primeiro == "double")
	{
	    i = REAL;
	}
	else
	{
	    if(primeiro == "char")
	    {
		i = CARACTER;
	    }
	    else
	    {
		if(primeiro == "string")
		{
		    i = STRING;
		}
	   	else
		{
		    if(primeiro == "bool")
		    {
			i = BOOLEANO;
		    }
		    else
		    {
			yyerror("Tipo"+primeiro+"inexistente")
    		    }
		}
	    }
	}
    }

    if(segundo == "int"){
	j = INTEIRO;
    }
    else
    {
	if(segundo == "double")
	{
	    j = REAL;
	}
	else
	{
	    if(segundo == "char")
	    {
		j = CARACTER;
	    }
	    else
	    {
		if(segundo == "string")
		{
		    j = STRING;
		}
	   	else
		{
		    if(segundo == "bool")
		    {
			j = BOOLEANO;
		    }
		    else
		    {
			yyerror("Tipo"+segundo+"inexistente")
    		    }
		}
	    }
	}
    }
    if(tabela_operacoes[tipo][i][j] == "")
    {
	yyerror("Operacao invalida entre "+primeiro+" e "+segundo);
    }
    return tabela_operacoes[tipo][i][j];

}

void gera_nome_funcao(atributos_compilador &esquerda, atributos_compilador &primeiro, atributos_compilador &segundo, atributos_compilador &quarto)
{
    esquerda.valor = segundo.valor;
    esquerda.codigo = primeiro.codigo;
    esquerda.tipo = primeiro.tipo;
    esquerda.tipo.modifica_valores(primeiro.tipo.base,segundo.tipo.n_dim,segundo.tipo.d[0],segundo.tipo.d[1]);
    
    if(esquerda.n_dim > 0)
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
	int temp = esquerda.tipo.d[0];
	if(esquerda.tipo.d[0] > 1)
	{
	    temp *= esquerda.tipo.d[1];
	}
        
	esquerda.codigo += " _ret;\n_ret = new " + esquerda.tipo.base + "[" +	int_to_str(temp) + "];\n";
   
    }
    adiciona_var("_ret",esquerda.tipo);
    for(atributos_compilador *temp = &quarto; temp != NULL; temp = temp->prox)
    {
	(func_global[esquerda.valor]->param).push_back(temp->tipo);
	adiciona_var(temp->valor, temp->tipo);
    }
}


string inttostr(int n)
{
	char buf[20];
	sprintf(buf,"%d",n);
	return buf;
}

int strtoint(String st)
{
	int n;
	sscanf(st.c_str(),"%d",&n);
	return n;
}

void gera_if(atribuos_compilador &n, atributos_compilador n2, atributos_compilador n3)
{
	n.valor = "";
	n.tipo.modifica_valores("");
	string inicio;
	inicio = label("INICIO"); 
	n.codigo = inicio + ":;\n" + "if( " + n2.valor + " ) goto " + n3.valor + ";\n";
}

void gera_if_else(atribuos_compilador &n, atributos_compilador n2, atributos_compilador n3, atributos_compilador n4)
{
	n.valor = "";
	n.tipo.modifica_valores("");
	string inicio;
	inicio = label("INICIO"); 
	n.codigo = inicio + ":;\n" + "if( " + n2.valor + " ) goto " + n3.valor + ";\n";
	n.codigo = inicio + ":;\n" + "if( " + n2.valor + " ) goto " + n4.valor + ";\n";
}

void gera_while(atribuos_compilador &n, atributos_compilador n2, atributos_compilador n3)
{
	n.valor = "";
	n.tipo.modifica_valores("");
	string inicio, fim;
	inicio = label("INICIO");
	fim = label("FIM");
	n.codigo = inicio + ":\n" + n2.codigo + "if( !" + n2.valor + " ) goto " + fim + ";\n";
	n.codigo += n3.codigo + "goto " + inicio + ";\n" + fim + ":;\n";
}

void gera_do_while(atribuos_compilador &n, atributos_compilador n2, atributos_compilador n3)
{
	n.valor = "";
	n.tipo.modifica_valores("");
	string inicio;
	inicio = label("INICIO"); 
	n.codigo = inicio + ":;\n" + n2.codigo + n3.codigo + "if( " + n3.valor + " ) goto " + inicio + ";\n";
}

void gera_for(atribuos_compilador &n, atributos_compilador n2, atributos_compilador n3, atributos_compilador n4,
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

string label(const char *n)
{
	static int num = 1;
	return string("P_") + n + int_to_src(num++);
}

string adiciona_func_global(const string &nome, const string &base, int ndim, int dim1, int dim2)
{
	if(func_global.find(nome) == func_global.end())
	{
		func_global[nome] = new Funcao(nome, base, ndim, dim1, dim2);
		return nome;
	}

	yyerror("Ja existe uma funcao com o nome " + nome);
	return "";
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

	string n2 = "t_" + n + int_to_str(contador n);

	return n2;
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
	if(n3.tipo.base != "bool" || n4.tipo.base != "bool" || n3.tipo.ndim > 0 || n4.tipo.ndim > 0)
		yyerror("Não é possível fazer o teste.");

	n2.valor = transforma_variavel("bool");
	n2.codigo = n3.codigo + n4.codigo + n2.valor + " = " + n3.valor + ' ' + n + ' ' + n4.valor + ";\n";
}

void gera_variavel(variavel &n, variavel n2)
{
	n = n2;
	n.codigo = n2.valor + "_"  + int_to_src(nivel--) + ";\n";
}

void gera_vetor(variavel &n, variavel n2, atributos_compilador n3)
{
	n.tipo = n2.tipo;
	n.ndim = 1;
	n.dim1 = n3.valor;
	n.codigo = n2.valor + "_" + int_to_src(nivel--) + "[" + n3.valor + "] \n;";
}

void gera_matriz(variavel &n, variavel n2, atributos_compilador n3, atributos_compilador n4)
{
	n.tipo = n2.tipo;
	n.ndim = 2;
	int n5 = n3.valor * n4.valor;
	n.dim1 = n3.valor;
	n.dim2 = n4.valor;
	n.codigo = n2.valor + "_" + int_to_src(nivel--) + "[" + n5 + "] \n;";
}

void adiciona_var(const string &nome, const string &base, int ndim, int dim1, int dim2)
{
	string str;

	str = nome;

	if(var.back().find(nome) == var.back().end())
	{
		var.back().insert( make_pair(nome, new Variavel(nome, base, ndim, dim1, dim2, constante)));
		return;
	}

	yyerror("Ja existe uma variavel com o nome " + nome);

}

string adiciona_func_global(const string &nome, const Tipo &tipo)
{
	return adiciona_func_global(nome, tipo.base, tipo.ndim, tipo.dim1, tipo.dim2);
}

void adiciona_var(const string &nome, const Tipo &tipo)
{
	adiciona_var(nome, tipo.base, tipo.ndim, tipo.dim1, tipo.dim2);
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

void chama_funcao(atributos_compilador &esquerda,atributos_compilador &primeiro, atributos_compilador &terceiro)
{
	bool existe = verifica_existencia_funcao(primeiro);
	if(existe)
	{
		esquerda.tipo = primeiro.tipo;
		esquerda.codigo = terceiro.codigo;
		if(esquerda.tipo.n_dim == 0)
		{
			esquerda.valor = cria_temp_var(esquerda.tipo.base);
		}
		else
		{
			esquerda.valor = cria_temp_var("matriz");
			esquerda.codigo += esquerda.tipo.base + " *";
		}
		esquerda.codigo += esquerda.valor;
		esquerda.codigo += " = " + primeiro.valor + "(" + terceiro.valor + ");\n";
		
		int i = 0;
		for(atributo *temp = &terceiro; temp != NULL ; temp = temp->prox){
			if(i >= ((func_global[primeiro.valor])->param).size()) yyerror("Numero de parametros incorreto: " + primeiro.valor);
			if(((func_global[primeiro.valor])->param).at(i).base != temp->tipo.base) yyerror("Tipo de parametro incorreto: " + primeiro.valor + "\n" + temp->tipo.base + " != " + ((func_global[primeiro.valor])->param).at(i).base);
			i++;
		}
	}
	yyerror("A funcao com nome "+ +" nao existe");
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

	esquerda.valor = cria_temp_var("bool");
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
	esquerda.valor = cria_temp_var("bool");
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
	nivel_atual = total_niveis;
	var.push_back(*(new map<string, variavel*>));
	
}
void desce_nivel()
{
	nivel_atual--;
	var.pop_back();
}

string declarar_variaveis_temporarias()
{
	string resultado = "";

	if(conta_temp_var.find("int") != conta_temp_var.end())
	{
		resultado += "int ";
		for(int i = 0; i < conta_temp_var["int"].size(); i++)
		{
			resultado += "_int"+inttostr(i)+"=0"
			if(i+1 != conta_temp_var["int"].size())
			{
				resultado += ","
			}
		}
		resultado += ";\n";
	}
	if(conta_temp_var.find("bool") != conta_temp_var.end())
	{
		resultado += "int ";
		for(int i = 0; i < conta_temp_var["bool"].size(); i++)
		{
			resultado += "_bool"+inttostr(i)
			if(i+1 != conta_temp_var["bool"].size())
			{
				resultado += ","
			}
		}
		resultado += ";\n";
	}
	if(conta_temp_var.find("char") != conta_temp_var.end())
	{
		for(int i = 0; i < conta_temp_var["char"].size(); i++)
		{
			resultado += "_char"+inttostr(i)
			if(i+1 != conta_temp_var["char"].size())
			{
				resultado += ","
			}
		}
		resultado += ";\n";	
	}
	if(conta_temp_var.find("string") != conta_temp_var.end())
	{
		for(int i = 0; i < conta_temp_var["string"].size(); i++)
		{
			resultado += "_string"+inttostr(i)
			if(i+1 != conta_temp_var["string"].size())
			{
				resultado += ","
			}		
		}
		resultado += ";\n";		
	}
	if(conta_temp_var.find("double") != conta_temp_var.end())
	{
		for(int i = 0; i < conta_temp_var["double"].size(); i++)
		{
			resultado += "_double"+inttostr(i)
			if(i+1 != conta_temp_var["double"].size())
			{
				resultado += ","
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

void gera_codigo_funcao(atributos_compilador &esquerda, atributos_compilador &segundo){
	
	esquerda.codigo = segundo.codigo + "return _ret;\n}\n";
	esquerda.valor = primeiro.valor;
	esquerda.tipo = primeiro.tipo;
	desce_nivel();
}

void gera_variavel(variavel &n, variavel n2)
{
	n = n2;
	n.codigo = n2.valor + "_"  + int_to_src(nivel--) + ";\n";
}

void gera_vetor(variavel &n, variavel n2, atributos_compilador n3)
{
	n.tipo = n2.tipo;
	n.ndim = 1;
	n.dim1 = n3.valor; 
	n.codigo = n2.valor + "_" + int_to_src(nivel--) + "[" + n3.valor + "]; \n";
}

void gera_matriz(variavel &n, variavel n2, atributos_compilador n3, atributos_compilador n4)
{
	n.tipo = n2.tipo;
	n.ndim = 2;
	int n5 = n3.valor * n4.valor;
	n.dim1 = n3.valor;
	n.dim2 = n4.valor;
	n.codigo = n2.valor + "_" + int_to_src(nivel--) + "[" + n5 + "]; \n";
}

void gera_entrada(atributos_compilador &esquerda, atributos_compilador &terceiro)
{
	esquerda.codigo = "cin >> "+ terceiro.valor +";\n"
}

void gera_saida(atributos_compilador &esquerda , atributos_compilador &terceiro = NULL, bool pulaLinha = false, bool vazio = false)
{
	if(pulaLinha == true && vazio == true)
	{
		esquerda.codigo = "cout << endl;\n";
	}
	else
	{
		if(terceiro == NULL)
		{
			yyerror("Erro na saida ");		
		}
		esquerda.codigo = "cout <<" + terceiro.valor + ";\n";  

		if(pulaLinha == true)
		{
			esquerda.codigo = "cout <<" + terceiro.valor + "<< endl;\n";	
		}
	}
}

void gera_inicializacao(atributos_compilador &esquerda, atributos_compilador &primeiro, atributos_compilador &segundo)
{
	esquerda.codigo = "#include <iostream>\n#include <cstdlib>\nusing namespace std;\n\n";
	esquerda.codigo += declaracao_de_temp() + variaveis + primeiro.codigo + segundo.codigo;
}

void gera_codigo_VG(atributos_compilador &esquerda, atributos_compilador &primeiro, atributos_compilador &segundo,atributos_compilador &terceiro = NULL)
{
	if(terceiro != NULL)
	{	
		esquerda.codigo = segundo.codigo + terceiro.codigo; 
		segundo.tipo = primeiro.tipo;	
	}
	else
	{
		esquerda.codigo = primeiro.codigo + segundo.codigo;
	}
}

void gera_codigo_VG_vazio(atributos_compiladores &esquerda)
{
	esquerda.codigo = "";
	esquerda.valor = "";
	esquerda.tipo.modifica_valores("");
}

void gera_codigo_LID(atributos_compilador &esquerda, atributos_compilador &primeiro, atributos_compilador &terceiro)
{
	if(terceiro != NULL)
	{
		
	}
	else
	{
		
	}

}
