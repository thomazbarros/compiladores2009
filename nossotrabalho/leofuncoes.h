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
map<string, unsigned int> contador;

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
void gera_funcao(atributos_compilador &esquerda, atributos_compilador &primeiro, atributos_compilador &segundo, atributos_compilador &quarto)
{
    esquerda.valor = segundo.valor;
    esquerda.codigo = primeiro.codigo;
    esquerda.tipo = primeiro.tipo;
    esquerda.tipo.modifica_valores(primeiro.tipo.base,segundo.tipo.n_dim,segundo.tipo.d[0],segundo.tipo.d[1]);
    
    if(esquerda.n_dim > 0)
    {
    	esquerda.codigo += "*";
    }
    //esquerda.codigo += " " + adiciona_func_global(segundo.valor, esquerda.tipo) + "(" + quarto.codigo + ")\n{\n";
    if(esquerda.tipo.n_dim == 0)
    {
//        esquerda.codigo += esquerda.tipo.base + " _ret = " + valor_padrao(esquerda.tipo.base + ";\n";
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
  /*  for(atributos_compiladores *temp = &quarto; temp != NULL; temp = temp->prox){
	(func_global[esquerda.valor]->param).push_back(temp->tipo);
	adiciona_var(temp->valor, temp->tipo);
    }*/
}


inttostr(int n)
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

void gera_if(atribuos_compilador n, atributos_compilador n2, atributos_compilador n3)
{
	n.valor = "";
	n.tipo.modifica_valores("");
	string inicio;
	inicio = label("INICIO"); 
	n.codigo = inicio + ":;\n" + "if( " + n2.valor + " ) goto " + n3.valor + ";\n";
}

void gera_if_else(atribuos_compilador n, atributos_compilador n2, atributos_compilador n3, atributos_compilador n4)
{
	n.valor = "";
	n.tipo.modifica_valores("");
	string inicio;
	inicio = label("INICIO"); 
	n.codigo = inicio + ":;\n" + "if( " + n2.valor + " ) goto " + n3.valor + ";\n";
	n.codigo = inicio + ":;\n" + "if( " + n2.valor + " ) goto " + n4.valor + ";\n";
}

void gera_while(atribuos_compilador n, atributos_compilador n2, atributos_compilador n3)
{
	n.valor = "";
	n.tipo.modifica_valores("");
	string inicio, fim;
	inicio = label("INICIO");
	fim = label("FIM");
	n.codigo = inicio + ":\n" + n2.codigo + "if( !" + n2.valor + " ) goto " + fim + ";\n";
	n.codigo += n3.codigo + "goto " + inicio + ";\n" + fim + ":;\n";
}

void gera_do_while(atribuos_compilador n, atributos_compilador n2, atributos_compilador n3)
{
	n.valor = "";
	n.tipo.modifica_valores("");
	string inicio;
	inicio = label("INICIO"); 
	n.codigo = inicio + ":;\n" + n2.codigo + n3.codigo + "if( " + n3.valor + " ) goto " + inicio + ";\n";
}

void gera_for(atribuos_compilador n, atributos_compilador n2, atributos_compilador n3, atributos-compilador, n4,
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

	string ini = "A funcao " + nome + " ja foi declarada.";

	yyerror(ini);
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

void gera_n(string n, atributos_compilador n2, atributos_compilador n3, atributos_compilador n4)
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