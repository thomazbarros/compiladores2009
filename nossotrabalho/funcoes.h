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