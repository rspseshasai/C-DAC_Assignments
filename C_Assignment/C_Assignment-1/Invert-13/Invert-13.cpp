// Invert-13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include<vector>
#include <iostream>
using namespace std;
void invert(int n, int p, int b)
{
	vector<int >bin;
	for (int i = 7; i >= 0; i--)
	{
		int k = n >> i;
		if (k & 1)
			bin.push_back(1);
		else
			bin.push_back(0);
	}
	cout << "Before Inverting: ";
	for (int i = 0; i < bin.size(); i++)
		cout << bin[i];
	cout << "\n";
	for (int i = p; i < b+i && i<bin.size(); i++)
	{
		if (bin[i] == 0)
			bin[i] = 1;
		else
			bin[i] = 0;
	}
	cout << "After Inverting:  ";
	for (int i = 0; i < bin.size(); i++)
		cout << bin[i];
}


int main()
{
	int n, p, b;
	cout << "Enter Number, Start Point to invert, number of bits to invert\n";
	cin >> n >> p >> b;
	invert(n, p, b);
	cout << "\n";
	system("pause");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
