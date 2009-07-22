#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <stack>

using namespace std;

void erro (string msg, int kill=0)
{
	cout << msg << "\n";
	if (kill)
	{ 
		exit(0);
	}
}
