#include "pch.h"
#include <iostream>
using namespace std;

void strcpy_p(char *s1, char *s2)
{
	while ((*s2 = *s1)!='\0')
	{
		s2++;
		s1++;
	}
	*s2 = '\0';
}

void strcat_p(char *s1, char *s2)
{
	while (*s1 != '\0')
	{
		s1++;
	}
	while ((*s1 = *s2) != '\0')
	{
		s1++;
		s2++;
	}
}

int strcmp_p(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return *(const unsigned char*)s1 - *(const unsigned char*)s2;

}

void strrev_p(char *s1, int l, int h)
{
	char ch;
	if (l >= h)
		return;

	ch = *(s1 + l);
	*(s1 + l) = *(s1 + h);
	*(s1 + h) = ch;

	strrev_p(s1, ++l, --h);
}

int main()
{
	int ch;
	while (1)
	{
		cout << "1-String Reverse   2-String Copy   3-String Concatenate   4-String Compare 5-Exit\n";
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "Enter a string\n";
			char s11[100];
			scanf(" %[^\n]s", s11);
			strrev_p(s11, 0, strlen(s11) - 1);
			cout << "Reversed String is : " << s11 << "\n";
			break;
		case 2:
			cout << "Enter two strings\n";
			char s21[100];
			char s22[100];
			scanf(" %[^\n]s", s21);
			scanf(" %[^\n]s", s22);
			cout << "Before copy String-1 is: " << s21 << "\n";
			cout << "Before copy String-2 is: " << s22 << "\n\n";
			strcpy_p(s21, s22);
			cout << "After copy String-1 is: " << s21 << "\n";
			cout << "After copy String-2 is: " << s22 << "\n";
			break;
		case 3:
			cout << "Enter two strings\n";
			char s31[100];
			char s32[100];
			scanf(" %[^\n]s", s31);
			scanf(" %[^\n]s", s32);
			cout << "Before Concatenate String-1 is: " << s31 << "\n";
			strcat_p(s31, s32);
			cout << "After Concatenate String-1 is: " << s31 << "\n";
			break;
		case 4:
			cout << "Enter two strings\n";
			char s41[100];
			char s42[100];
			scanf(" %[^\n]s", s41);
			scanf(" %[^\n]s", s42);
			int retVal;
			retVal = strcmp_p(s41, s42);
			if (retVal > 1)
				cout << "String-1 is Bigger\n";
			else if (retVal == 0)
				cout << "Strings are equal\n";
			else
				cout << "String-2 is Bigger\n";
			break;
		case 5:
			exit(0);
		default:
			cout << "Invalid Input\n";
			break;
		}
	}
	system("pause");
}

