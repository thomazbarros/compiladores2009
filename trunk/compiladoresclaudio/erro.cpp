#include <iostream>

using namespace std;

void erro (string msg, int kill=0)
{
	cout << msg << "\n";
	if (kill) exit(0);
}
