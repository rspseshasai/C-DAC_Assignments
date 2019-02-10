
#include "pch.h"
#include <iostream>
using namespace std;

void u2l(char *s)
{
	cout << "\nLower case String: ";
	for (int i = 0; i < strlen(s); i++)
	{
		int n = s[i];
		if (n >= 65 && n <= 90)
			cout<< (char)(n + 32);
		else
			cout<< s[i];
	}
	cout << "\n";
}

void l2u(char *s)
{
	cout << "\nUpper case String: ";
	for (int i = 0; i < strlen(s); i++)
	{
		int n = s[i];
		if (n >= 97 && n <= 122)
			cout << (char)(n - 32);
		else
			cout << s[i];
	}
	cout << "\n";
}



int main()
{
	int ch;
	char s[100];
	cout << "Enter a String: ";
	scanf_s("%[^\n]", s, 100);
	cout << "1 - Upper to Lower\t2 - Lower to Upper\n";
	cin >> ch;
	char *s1, *s2;
	switch (ch)
	{
	case 1: u2l(s);
		//cout << "\nLower case String: " << s1<<"\n";
		break;
	case 2:	l2u(s);
		//cout << "\nUpper case String: " << s2<<"\n";
		break;
	}
	//cout << s<<"\n";
	system("pause");
}
