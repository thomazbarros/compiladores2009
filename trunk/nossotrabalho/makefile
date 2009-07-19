all: teste entrada
	./teste < entrada

lex.yy.c: trabalho.l
	lex trabalho.l

y.tab.c: test.y
	yacc test.y

teste: lex.yy.c y.tab.c
	g++ -o teste y.tab.c -lfl
