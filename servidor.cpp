#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main()
{
	unsigned int n,p=0;
	cin >> n;
	for (int i = 2; i < n; i++)
	{
		if(n%i==0)
			p++;
	}
	if(p==0)
		cout << "Es primo" << endl;
	else
		cout << "No es primo" << endl;
}