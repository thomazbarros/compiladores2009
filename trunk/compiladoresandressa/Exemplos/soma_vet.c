#include <string>
#include <iostream>

using namespace std;

int main ()
{
int vet_a[3];
int vet_b[3];
int vet_c[3];
int i;
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
i = 0;
cout << "Digite os valores de um vetor de tamanho 3:";
 TI1 = 1;
TI2 = 3;
ROT0 : cin >>vet_a[i] ;
TI0 = i+1;
i = TI0;
TI1 = TI1 + 1;
TI3 = TI1 <= TI2;
if(TI3)
goto ROT0;
i = 0;
cout << "Digite os valores de um vetor de tamanho 3:";
 TI5 = 1;
TI6 = 3;
ROT1 : cin >>vet_b[i] ;
TI4 = i+1;
i = TI4;
TI5 = TI5 + 1;
TI7 = TI5 <= TI6;
if(TI7)
goto ROT1;
i = 0;
cout << "A soma dos vetores A e B será:";
 TI13 = 1;
TI14 = 3;
ROT2 : TI9 = vet_a[i];
TI10 = vet_b[i];
TI8 = TI9+TI10;
TI11 = TI8;
vet_c[i] = TI11;
cout << vet_c[i];
 cout << "\n";
 TI12 = i+1;
i = TI12;
TI13 = TI13 + 1;
TI15 = TI13 <= TI14;
if(TI15)
goto ROT2;
cout << "\n";
 
}

