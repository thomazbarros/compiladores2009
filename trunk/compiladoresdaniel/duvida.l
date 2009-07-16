%{
	#include <iostream>

	using namespace std;

	struct Tipo
	{
		string base;
		int ndim;
		int dim1;
		int dim2;
		
		Tipo(string base, int ndim = 0, int dim1 = 1, int dim2 = 1) : base(base), ndim(ndim), dim1(dim1), dim2(dim2) {}
		void ajuste(string base, int ndim = 0, int dim1 = 1, int dim2 = 1)
		{
			this->base = base;
			this->ndim = ndim;
			this->dim1 = dim1;
			this->dim2 = dim2;
		}
	};

	struct atributo
	{
		string valor, codigo;
		Tipo tipo;
		atributo() : valor(""), tipo(""), codigo("") {}
	};

	#define YYSTYPE atributo

	#include "y.tab.h"
	#include <stdlib.h>


	void yyerror(const string &);
	extern YYSTYPE yyval;
	extern int nlinha;
%}

DELIM		[\t ]
LINHA		[\n]
LETRA		[A-Za-z]
NUMERO	[0-9]
INTEIRO	{NUMERO}+
REAL		{NUMERO}+("."{NUMERO}*)?
ID			{LETRA}({LETRA}|{NUMERO})*
FRASE		\"[^\"]*\"
CARAC		'[^']'
L1			%\-
L2			\-%
COMENT	(;[^\n]*\n|{L1}[^{L2}]*{L2})

%%

{LINHA}			{
							#ifdef DEBUG
							cout << "ws--" << *yytext << endl;
							#endif
							nlinha++;
						}

{DELIM}			{
							#ifdef DEBUG
							cout << "ws--" << *yytext << endl;
							#endif
						}

inteiro		{
						yylval.valor = "int";
						yylval.codigo = "int";
						yylval.tipo.ajuste("int");
						#ifdef DEBUG
							cout << yytext << "--" << TK_TIPO_INT << endl;
						#endif
						return TK_TIPO_INT;
					}

real		{
					yylval.valor = "double";
					yylval.codigo = "double";
					yylval.tipo.ajuste("double"); 
					#ifdef DEBUG
						cout << yytext << "--" << TK_TIPO_DOUBLE << endl;
					#endif
					return TK_TIPO_DOUBLE;
				}

letra		{
					yylval.valor = "char";
					yylval.codigo = "char";
					yylval.tipo.ajuste("char");
					#ifdef DEBUG
						cout << yytext << "--" << TK_TIPO_CHAR << endl;
					#endif
					return TK_TIPO_CHAR;
				}

logico		{
						yylval.valor = "bool";
						yylval.codigo = "bool";
						yylval.tipo.ajuste("bool");
						#ifdef DEBUG
							cout << yytext << "--" << TK_TIPO_BOOL << endl;
						#endif
						return TK_TIPO_BOOL;
					}

frase		{
					yylval.valor = "string";
					yylval.codigo = "string";
					yylval.tipo.ajuste("string");
					#ifdef DEBUG
						cout << yytext << "--" << TK_TIPO_STRING << endl;
					#endif
					return TK_TIPO_STRING;
				}

ler		{
					#ifdef DEBUG
						cout << yytext << "--" << TK_LER << endl;
					#endif
					return TK_LER; 
				}

constante { return TK_CONST; }

escrever {
					#ifdef DEBUG
						cout << yytext << "--" << TK_ESCREVER << endl;
					#endif
					return TK_ESCREVER;
				}

certo		{
					yylval.valor = "true";
					yylval.codigo = "";
					yylval.tipo.ajuste("bool");
					#ifdef DEBUG
						cout << yytext << "--" << TK_BOOL << endl;
					#endif
					return TK_BOOL;
				}

errado		{
					yylval.valor = "false";
					yylval.codigo = "";
					yylval.tipo.ajuste("bool");
					#ifdef DEBUG
						cout << yytext << "--" << TK_BOOL << endl;
					#endif
					return TK_BOOL;
				}

\<=		{
				return TK_L_OR_E;
			}

\>=		{
				return TK_G_OR_E;
			}

!=		{
				return TK_DIFF;
			}

abortar {
					return TK_ERR;
				}

programa {
						return TK_MAIN;
					}

=>		{
				return TK_ATRIBUICAO;
			}

para {return TK_PARA; }

de {return TK_DE; }

abre { return TK_INI; }

fecha { return TK_FIM; }

se { return TK_DESVIO; }

senao { return TK_DESVIO_2; }

enquanto { return TK_LACO; }

ate { return TK_LACO_2; }

fazer { return TK_ACAO; }

{ID}				{
							yylval.valor = yytext;
							yylval.codigo = yytext;
							#ifdef DEBUG
								cout << yytext << "--" << TK_ID << endl;
							#endif
							return TK_ID;
						}

{INTEIRO}		{ 
							yylval.valor = yytext;
							yylval.codigo = "";
							yylval.tipo.ajuste("int");
							#ifdef DEBUG
								cout << yytext << "--" << TK_INT << endl;
							#endif
							return TK_INT;
						}

{REAL}			{ 
							yylval.valor = yytext;
							yylval.codigo = "";
							yylval.tipo.ajuste("double");
							#ifdef DEBUG
								cout << yytext << "--" << TK_DOUBLE << endl;
							#endif
							return TK_DOUBLE;
						}

{FRASE}			{ 
							yylval.valor = yytext;
							yylval.codigo = "";
							yylval.tipo.ajuste("string");
							#ifdef DEBUG
								cout << yytext << "--" << TK_STRING << endl;
							#endif
							return TK_STRING;
						}

{CARAC}			{ 
							yylval.valor = yytext;
							yylval.codigo = "";
							yylval.tipo.ajuste("char");
							#ifdef DEBUG
								cout << yytext << "--" << TK_CHAR << endl;
							#endif
							return TK_CHAR;
						}

{COMENT}			{
							#ifdef DEBUG
								cout << "cmt--" << *yytext << endl;
							#endif
						}

.					{
							#ifdef DEBUG
								cout << "--" << *yytext << endl;
							#endif
							return *yytext;
						}

%%

int yywrap(void)
{
    return 1;
}
