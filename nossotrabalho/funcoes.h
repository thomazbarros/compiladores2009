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
int numLinha = 1;
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
    //esquerda.valor = ?????
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

void gera_funcao(atributos_compilador &esquerda, atributos_compilador &primeiro, atributos_compilador &segundo, atributos_compilador &quarto,map<string, funcao*> &func_global,deque<map <string, variavel*> > &var)
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
    for(atributos_compilador *temp = &quarto; temp != NULL; temp = temp->prox){
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

void gera_if(atributos_compilador n, atributos_compilador n2, atributos_compilador n3)
{
	n.valor = "";
	n.tipo.modifica_valores("");
	string inicio;
	inicio = label("INICIO"); 
	n.codigo = inicio + ":;\n" + "if( " + n2.valor + " ) goto " + n3.valor + ";\n";
}

void gera_if_else(atributos_compilador n, atributos_compilador n2, atributos_compilador n3, atributos_compilador n4)
{
	n.valor = "";
	n.tipo.modifica_valores("");
	string inicio;
	inicio = label("INICIO"); 
	n.codigo = inicio + ":;\n" + "if( " + n2.valor + " ) goto " + n3.valor + ";\n";
	n.codigo = inicio + ":;\n" + "if( " + n2.valor + " ) goto " + n4.valor + ";\n";
}

void gera_while(atributos_compilador n, atributos_compilador n2, atributos_compilador n3)
{
	n.valor = "";
	n.tipo.modifica_valores("");
	string inicio, fim;
	inicio = label("INICIO");
	fim = label("FIM");
	n.codigo = inicio + ":\n" + n2.codigo + "if( !" + n2.valor + " ) goto " + fim + ";\n";
	n.codigo += n3.codigo + "goto " + inicio + ";\n" + fim + ":;\n";
}

void gera_do_while(atributos_compilador n, atributos_compilador n2, atributos_compilador n3)
{
	n.valor = "";
	n.tipo.modifica_valores("");
	string inicio;
	inicio = label("INICIO"); 
	n.codigo = inicio + ":;\n" + n2.codigo + n3.codigo + "if( " + n3.valor + " ) goto " + inicio + ";\n";
}

void gera_for(atributos_compilador n, atributos_compilador n2, atributos_compilador n3, atributos-compilador, n4,
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

string adiciona_func_global(const string &nome, const string &base, int ndim, int dim1, int dim2,map<string, funcao*> &func_global)
{
	if(func_global.find(nome) == func_global.end())
	{
		func_global[nome] = new Funcao(nome, base, ndim, dim1, dim2);
		return nome;
	}

	yyerror("Ja existe uma funcao com o nome " + nome);
	return "";
}

void adiciona_var(const string &nome, const string &base, int ndim, int dim1, int dim2, deque<map <string, variavel*> > &var)
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
	if(atr.tipo.base == "real")
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

void chama_funcao(atributos_compilador &esquerda,atributos_compilador &primeiro, atributos_compilador &terceiro, map<string, funcao*> &func_global)
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

bool verifica_existencia_funcao(atributos_compilador &atr, map<string, funcao*> &func_global)
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
