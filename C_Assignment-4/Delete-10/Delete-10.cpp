// StringRotations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;



char * del(char * s1, char s2)
{
	int count = 0, i, j, k;
	int len = strlen(s1);
	for (i = 0; i < len - count; i++)
	{
		if (s1[i] == s2)
		{
			for (j = i + 1; j < len - count; j++)
			{
				s1[j - 1] = s1[j];
			}
			count++;
			s1[j-1] = '\0';
		}

	}
	//cout << s1 << "\n";
	return s1;
}

int main()
{
	char s1[100], s2;
	cout << "Enter 1st string \n";
	scanf("%[^\n]s", s1);
	cout << "Enter Character to Delete\n";
	cin >> s2;
	cout << "After Deleting: ";
	cout << "\n" << del(s1, s2) << "\n";
	//cout << s1 << "\n";
	system("pause");
}

