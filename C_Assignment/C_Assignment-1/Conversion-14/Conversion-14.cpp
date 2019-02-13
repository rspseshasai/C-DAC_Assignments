
#include "pch.h"
#include<vector>
#include <iostream>
using namespace std;

void itob(int n)
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
	cout<< n << " in Binary is: ";
	for (int i = 0; i < bin.size(); i++)
		cout << bin[i];
	cout << "\n";
}

void itoh(int n)
{
	cout << "coming soon...\n";
}


int main()
{
	int n;
	cout << "Enter decimal number\n";
	cin >> n;
	int ch;
	cout << "1 - Convert to binary\t2 - Convert to HexaDecimal\n";
	cin >> ch;
	switch (ch)
	{
	case 1:	itob(n);
			break;
	case 2:	itoh(n);
			break;
	}
	system("pause");
}

