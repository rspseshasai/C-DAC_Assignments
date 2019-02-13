// StringRotations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

char * reverse(char *s)
{
	static int i = 0;
	static char r[100];
	if (*s)
	{
		reverse(s + 1);
		r[i++] = *s;
	}
	return r;
}

int main()
{
	char str[100];
	char *rev;
	cout << "Enter String: ";
	scanf("%[^\n]s", str);
	rev = reverse(str);
	cout << rev << "\n";
	system("pause");
}

