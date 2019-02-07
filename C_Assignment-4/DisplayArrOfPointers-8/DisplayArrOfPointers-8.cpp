
#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	char **p = NULL;
	int n;
	cout << "Enter n: ";
	cin >> n;
	p = (char **)malloc(n * sizeof(char *));
	for (int i = 0; i < n; i++)
	{
		char val[50];
		//cout << "1\n";
		cin >> val;
		//cout << "2\n";
		int len = strlen(val);
		p[i] = (char *)malloc((len + 1) * sizeof(char));
		strcpy(p[i], val);
	}

	for (int i = 0; i < n; i++)
	{
		cout << p[i]<<"\n";
	}
	free(p);
	system("pause");
}
