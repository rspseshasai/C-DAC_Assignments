// SortStrings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	int n;
	cout << "Enter No. of Strings: ";
	cin >> n;
	char **str=NULL;
	str = (char **)malloc(n * sizeof(char *));

	char name[50];
	for (int i = 0; i < n; i++)
	{
		cout << "Enter string " << i + 1 << " : ";
		scanf("%s", name);
		int l = strlen(name);
		str[i] = (char *)malloc((l+1) * sizeof(char *));
		strcpy(str[i], name);
	}
	cout << "\nBefore Sorting\n";
	for (int i = 0; i < n; i++)
		cout << str[i] << "\n";
	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n-i-1 ; j++)
		{
			if (strcmp(str[j], str[j + 1]) > 0) 
			{
				char *temp;
				temp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = temp;
			}
		}
	}
	cout << "\nAfter Sorting\n";
	for (int i = 0; i < n; i++)
		cout << str[i] << "\n";

	system("pause");
}
