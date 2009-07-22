#include <string>
#include <iostream>

using namespace std;

int main ()
{
int vet[5];
int nao_arrumado;
int i;
int aux;
int TI0;
int TI1;
int TI2;
int TI3;
int TI4;
int TI5;
int TI6;
int TI7;
int TI8;
int TI9;
int TI10;
int TI11;
int TI12;
int TI13;
int TI14;
int TI15;
int TI16;
int TI17;
int TI18;
int TB0;
int TB1;
int TB2;
nao_arrumado = 1;
vet[0] = 4;
vet[1] = 6;
vet[2] = 5;
vet[3] = 1;
vet[4] = 2;
cout << "Vetor não arrumado:";
 i = 0;
TI1 = 0;
TI2 = 4;
ROT0 : cout << "\n";
 cout << vet[i];
 TI0 = i+1;
i = TI0;
TI1 = TI1 + 1;
TI3 = TI1 <= TI2;
if(TI3)
goto ROT0;
ROT3: nao_arrumado = 0;
i = 0;
TI12 = 0;
TI13 = 3;
ROT2 : TI4 = i+1;
TI5 = vet[i];
TI6 = vet[TI4];
TB0 = TI5>TI6;
TB1 =  ! TB0 ;
if(TB1)
goto ROT1;
TI7 = vet[i];
aux = TI7;
TI8 = i+1;
TI9 = vet[TI8];
vet[i] = TI9;
TI10 = i+1;
vet[TI10] = aux;
nao_arrumado = 1;
ROT1: ;
TI11 = i+1;
i = TI11;
TI12 = TI12 + 1;
TI14 = TI12 <= TI13;
if(TI14)
goto ROT2;
TB2 =nao_arrumado;
if (TB2 ) 
goto ROT3;
cout << "\n";
 cout << "Vetor arrumado após o Bubble Sort:";
 i = 0;
TI16 = 0;
TI17 = 4;
ROT4 : cout << "\n";
 cout << vet[i];
 TI15 = i+1;
i = TI15;
TI16 = TI16 + 1;
TI18 = TI16 <= TI17;
if(TI18)
goto ROT4;
cout << "\n";
 
}

