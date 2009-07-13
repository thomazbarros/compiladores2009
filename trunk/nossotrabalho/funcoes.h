#define YYSTYPE atributos_compilador
#define SOMA 0
#define SUBTR 1
#define MULT 2
#define DIV 3


void realizar_operacao(int tipo, atributos_compilador &esquerda, atributos_compilador &primeiro, atributos_compilador &segundo)
{
    string operador;
    //esquerda.tipo = tipo_resultado(tipo,primeiro.tipo,segundo.tipo)
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
	default :
	    yyerror("Operador invalido : " + int_to_str(tipo));	    
    }
    //esquerda.valor = ?????
    esquerda.codigo = primeiro.codigo + segundo.codigo + esquerda.valor + " = " + primeiro.valor + operador + segundo.valor + ";\n";
}

//definida em breve :P
/*void tipo_resultado(int tipo, string &primeiro, string &segundo)
{
    int a

}*/
