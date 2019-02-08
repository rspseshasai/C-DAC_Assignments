// StringRotations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
char * replace(char *s1)
{
	for (int i = 0; i < s1.length(); i++)
	{
		if (s1[i] == ' ')
			s[i] = '-';
	}
}
int main()
{
	const char *cat = "The cat sat";
	char *n = replace(cat);
	cout << n;
	system("pause");
}

