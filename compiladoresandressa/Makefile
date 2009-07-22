all: aia exemplos

lex.yy.c: aia.l
	flex aia.l

y.tab.c: aia.y
	yacc -y aia.y

aia: lex.yy.c y.tab.c
	g++ -o aia y.tab.c -lfl

exemplos: aia
	./Exemplos/criarExemplos.sh


