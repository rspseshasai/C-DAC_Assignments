// StringRotations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	char s1[100];
	char s2[100]="";
	cout << "Enter a string: ";
	scanf("%[^\n]s", s1);
	for (int i = 0; i < strlen(s1); i++)
	{
		if (s1[i] == '-')
		{
			if (i != 0 && i != strlen(s1) - 1)
			{
				int n1 = s1[i - 1], n2 = s1[i + 1];
				for (int j = n1+1; j < n2; j++)
				{
					//strcat(s2, (char *)j);
					cout << (char)j ;
				}
			 }
			else
			{
				cout << "Input Error\n";
			}
		}
		else
		{
			//strcat(s2, (char *)s1[i]);
			cout << s1[i];
		}
	}
	cout << "\n";
	system("pause");
}

