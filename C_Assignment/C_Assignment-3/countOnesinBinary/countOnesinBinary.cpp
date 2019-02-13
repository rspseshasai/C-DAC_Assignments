// MoveNegativestoFront.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	char bin[100];
	cout << "Enter binary number: ";
	cin >> bin;
	int c=0;
	for(int i=0;i<strlen(bin);i++)
	{
		if (bin[i]== '1')
			c++;
	}
	cout <<"Number of Ones: "<< c<<"\n";
	system("pause");
}
