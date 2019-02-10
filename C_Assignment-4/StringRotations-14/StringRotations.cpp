// StringRotations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	char str[10];
	cout << "Enter a string: ";
	scanf("%[^\n]s", str);
	int count = 0, ptr=0;
	int n = strlen(str);
	cout << "n= " << n<<endl;
	for (int i = 0; i < n; i++)
	{
		cout << str[i];
		count = 0;
		ptr = i + 1;
		while (count < strlen(str) - 1)
		{
			//cout << ptr;
			cout << str[ptr%strlen(str)];
			count++;
			ptr++;
		}
		
		cout << "\n";
	}
	system("pause");
}

