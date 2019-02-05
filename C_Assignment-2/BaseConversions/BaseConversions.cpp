
#include "pch.h"
#include <iostream>
using namespace std;

int dtob()
{
	cout << "Enter a Decimal number: ";
	int dec;
	int bin = 1;
	cin >> dec;
	cout << "Binary for given Decimal is : ";
	if (dec < 1024)
	{
		for (int i = 31; i >= 0; i--)
		{
			int k = dec >> i;
			if (k & 1)
				bin = bin * 10 + 1;
			else
				bin = bin * 10 + 0;
		}
		return bin;
	}
	else
	{
		for (int i = 31; i >= 0; i--)
		{
			int k = dec >> i;
			if (k & 1)
				cout << 1;
			else
				cout << 0;
		}
	}
	return 0;
}

int btod()
{
	cout << "Enter a Binary number: ";
	int dec=0, bin, count=0;
	cin >> bin;
	while (bin > 0)
	{
		int r = bin % 10;
		dec = dec + (r*pow(2, count++));
		bin /= 10;
	}
	return dec;
}
int btoh()
{
	cout << "Enter a Decimal number: ";
	int dec, bin = 1;
	cin >> dec;
	for (int i = 31; i >= 0; i--)
	{
		int k = dec >> i;
		if (k & 1)
			bin = bin * 10 + 1;
		else
			bin = bin * 10 + 0;
	}
	return bin;
}
int htob()
{
	cout << "Enter a Decimal number: ";
	int dec, bin = 1;
	cin >> dec;
	for (int i = 31; i >= 0; i--)
	{
		int k = dec >> i;
		if (k & 1)
			bin = bin * 10 + 1;
		else
			bin = bin * 10 + 0;
	}
	return bin;
}
int main()
{
	int ch;
	cout << "1 - Decimal to Binary\n2 - Bianry to Decimal\n3 - Binary to Hexadecimal\n4 - Hexadecimal to Binary\n";
	cin >> ch;
	int x;
	switch (ch)
	{

	case 1: x = dtob();
			if (x != 0)
				cout << x;
			break;
	case 2: cout << "Decimal for given Binary is : " << btod();
			break;
	case 3:	cout << "Hexadecimal for given Binary is : " << btoh();
			break;
	case 4:	cout << "Binary for given Hexadecimal is : " << htob();
			break;
	}
	cout << "\n";
	system("pause");
}

