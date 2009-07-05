all: teste entrada
	./teste < entrada

lex.yy.c: teste.lex
	lex teste.lex

y.tab.c: teste.y
	yacc teste.y

teste: lex.yy.c y.tab.c
	g++ -o teste y.tab.c -lfl
