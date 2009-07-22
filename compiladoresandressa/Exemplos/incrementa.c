#include <string>
#include <iostream>

using namespace std;

void incrementa(int a, int &RI);
int main ()
{
int a;
int TI0;
int TI1;
int TI2;
int TI3;
cout << "Digite um número:";
 cin >>a ;
TI1 = 1;
TI2 = 10;
ROT0 : incrementa(a, TI0);
a = TI0;
cout << a;
 TI1 = TI1 + 1;
TI3 = TI1 <= TI2;
if(TI3)
goto ROT0;

}
void incrementa(int a,int &RI)
{
int TI0;
TI0 = a+1;
RI = TI0;
return;

}

