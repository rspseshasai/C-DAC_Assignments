
#include "pch.h"
#include <iostream>
using namespace std;
#define SIZE 50

int main()
{
	char s1[SIZE];
	char s2[SIZE] = "";
	cout << "Enter a string: ";
	scanf("%[^\n]s", s1);

	for (int i = 0; i < strlen(s1); i++)
	{
		if (s1[i] == '-')
		{
			if (i != 0 && i != strlen(s1) - 1)
			{
				int n1 = s1[i - 1], n2 = s1[i + 1];
				if (n1 >= 65 && n1 <= 90)
				{
					if (n2 >= 65 && n2 <= 90)
					{
						for (int j = n1 + 1; j < n2; j++)
						{
							cout << (char)j;
						}
					}
				}
				if (n1 >= 97 && n1 <= 122)
				{
					if (n2 >= 97 && n2 <= 122)
					{
						for (int j = n1 + 1; j < n2; j++)
						{
							cout << (char)j;
						}
					}
				}
				if (n1 >= 48 && n1 <= 57)
				{
					if (n2 >= 48 && n2 <= 57)
					{
						for (int j = n1 + 1; j < n2; j++)
						{
							cout << (char)j;
						}
					}
				}
			}
			else
			{
				cout << "\nInput Error\n";
			}
		}
		else
		{
			cout << s1[i];
		}
	}
	cout << "\n";
	system("pause");
}


