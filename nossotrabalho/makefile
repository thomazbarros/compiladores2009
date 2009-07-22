all: teste entrada
	./teste < entrada

lex.yy.c: trabalho.l
	lex trabalho.l

y.tab.c: trabalho.y
	yacc trabalho.y

teste: lex.yy.c y.tab.c
	g++ -o teste y.tab.c -lfl
