// StringRotations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

void strcpy_p(char *s1, char *s2)
{
	//cout << s1 << "\n" << s2 << "\n";
	while ((*s2))
	{ 
		*s1 = *s2;
		s2++;
		s1++;
	}
	*s1 = '\0';
	//cout << s1 << "\n";
}

int main()
{
	int ch;
	cout << "1-strrev() \n2-strcpy() \n3-strcat() \n4-strcmp()\n";
	cin >> ch;
	switch (ch)
	{
	case 1:
		break;
	case 2:
		cout << "Enter string\n";
		char s1[100];
		char s2[100];
		scanf(" %[^\n]s", s1);
		//cin >> s1;
		//cin >> s2;
		//scanf(" %[^\n]s", s2);
		cout << "After copy first string is: " <<"\n";
		strcpy_p(s1, s2);
		cout << s1;
	}
	system("pause");
}

