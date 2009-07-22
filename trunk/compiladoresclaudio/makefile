all: teste entrada
	./trabalho < entrada

lex.yy.c: trabalho.lex
	flex trabalho.lex

y.tab.c: trabalho.y
	yacc trabalho.y

teste: lex.yy.c y.tab.c
	g++ -o trabalho y.tab.c -lfl
