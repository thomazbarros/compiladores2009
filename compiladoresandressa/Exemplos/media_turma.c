#include <string>
#include <iostream>

using namespace std;

int main ()
{
int i;
int alunos;
char nome[256];
int nota;
float soma;
int TI0;
float TR0;
float TR1;
float TR2;
int TB0;
int TB1;
int TB2;
int TB3;
i = 0;
soma = 0;
cout << "Quantidade de alunos:";
 cin >>alunos ;
ROT0: cout << "Digite um nome: ";
 cin >>nome ;
cout << "Digite a nota do aluno:";
 cin >>nota ;
TR0 = soma+nota;
soma = TR0;
TI0 = i+1;
i = TI0;
TB0 = i<alunos;
TB1 =TB0;
if (TB1 ) 
goto ROT0;
cout << "A media da turma é: ";
 TR1 = soma/alunos;
cout << TR1;
 cout << "\n";
 TR2 = soma/alunos;
TB2 = TR2>=7;
TB3 =  ! TB2 ;
if(TB3)
goto ROT1;
cout << "A turma está acima da média !!";
 goto ROT2;
ROT1: ;
cout << "A turma tá muito fraca";
 ROT2: ;
cout << "\n";
 
}

