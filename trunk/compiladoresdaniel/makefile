all: duvida entrada.duv
	./duvida < entrada.duv

y.tab: duvida.y
	yacc -d duvida.y

lex.yy.c: duvida.l y.tab
	lex duvida.l

y.tab.o: y.tab
	g++ -c y.tab.c

lex.yy.o: lex.yy.c
	g++ -c lex.yy.c

debug-y.tab.o: y.tab
	g++ -c y.tab.c -g -ggdb

debug-lex.yy.o: lex.yy.c
	g++ -c lex.yy.c -g -ggdb

duvida: lex.yy.o y.tab.o
	g++ y.tab.o lex.yy.o -o duvida

debug-duvida: debug-lex.yy.o debug-y.tab.o
	g++ y.tab.o lex.yy.o -o duvida -g -ggdb
	gdb duvida

clean:
	rm -f y.tab.c lex.yy.c y.tab.o lex.yy.o duvida

teste.cpp: duvida entrada.duv
	./duvida < entrada.duv > teste.cpp

compile: teste.cpp
	g++ teste.cpp -o teste -Wall

debug: teste.cpp
	g++ teste.cpp -o teste -Wall -g -ggdb
	gdb teste

exec: compile
	./teste

exemplo1: ex1
	./ex1

ex1: ex1.cpp
	g++ ex1.cpp -o ex1 -Wall

ex1.cpp: duvida ex1.duv
	./duvida < ex1.duv > ex1.cpp


