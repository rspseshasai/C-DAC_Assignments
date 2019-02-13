// StringRotations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

int any(char *s1, char*s2)
{
	int n1, n2;
	n1 = strlen(s1);
	n2 = strlen(s2);
	int flag = -1, c=0;
	if (n1 < n2)
		return -1;
	for (int i = 0; i <= n1-n2; i++)
	{
		flag = -1;
		c = 0;
		for (int j = 0; j < n2; j++)
		{
			if (s1[i+j] == s2[j])
			{
				c++;
			}
		}
		if (c == n2)
		{
			flag = i;
			break;
		}
	}
	if (flag != -1)
		return flag;
	return -1;
}

int main()
{
	char s1[10], s2[100];
	cout << "Enter a string: ";
	scanf(" %[^\n]s", s1);
	cout << "Enter string 2: ";
	scanf(" %[^\n]s ", s2);
	int n = any(s1, s2);
	if (n == -1)
		cout << "No Match Found\n";
	else
		cout << "Found at index : " << n << "\n";
	system("pause");
}

