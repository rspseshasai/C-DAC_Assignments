
#include "pch.h"
#include <iostream>
using namespace std;

int dtob(int dec)
{
	int bin = 1;
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

int btod(long long int bin)
{
	int dec = 0, count = 0;
	while (bin > 0)
	{
		int r = bin % 10;
		dec = dec + (r*(int)pow(2, count++));
		bin /= 10;
	}
	return dec;
}
void btoh(long long int bin)
{
	
	char hex[1000];
	cout << "Hexadecimal for given Binary is : ";
	int dec = btod(bin);
	int i = 0;
	while (dec != 0)
	{
		hex[i] = dec % 16;
		dec /= 16;
		i++;
	}
	for (int j = i - 1; j >= 0; j--)
	{
		if (hex[j] > 9)
			cout << (char)(hex[j] + 55);
		else
			cout << hex[j];
	}
	cout << "\n";
}
void htob(char* hex)
{
	int i = 0;
	while (hex[i])
	{
		switch (hex[i])
		{
		case '0': cout << "0000";
			break;
		case '1': cout << "0001";
			break;
		case '2': cout << "0010";
			break;
		case '3': cout << "0011";
			break;
		case '4': cout << "0100";
			break;
		case '5': cout << "0101";
			break;
		case '6': cout << "0110";
			break;
		case '7': cout << "0111";
			break;
		case '8': cout << "1000";
			break;
		case '9': cout << "1001";
			break;
		case 'A': cout << "1010";
			break;
		case 'B': cout << "1011";
			break;
		case 'C': cout << "1100";
			break;
		case 'D': cout << "1101";
			break;
		case 'E': cout << "1110";
			break;
		case 'F': cout << "1111";
			break;
		case 'a': cout << "1010";
			break;
		case 'b': cout << "1011";
			break;
		case 'c': cout << "1100";
			break;
		case 'd': cout << "1101";
			break;
		case 'e': cout << "1110";
			break;
		case 'f': cout << "1111";
			break;
		default: cout << "\nInvalid hexadecimal digit " << hex[i];
		}
		i++;
	}
}
int main()
{
	int ch;
	cout << "1 - Decimal to Binary\n2 - Bianry to Decimal\n3 - Binary to Hexadecimal\n4 - Hexadecimal to Binary\n\n";
	cin >> ch;
	cout << "\n";
	int x;
	switch (ch)
	{

	case 1: cout << "Enter a Decimal number: ";
			int dec;
			cin >> dec;
			x = dtob(dec);
			if (x != 0)
				cout << x;
			break;
	case 2:	cout << "Enter a Binary number: ";
			int bin;
			cin >> bin;
			cout << "Decimal for given Binary is : " << btod(bin);
			break;
	case 3:	cout << "Enter a Binary number: ";
			long long int bin1;
			cin >> bin1;
			btoh(bin1);
			break;
	case 4:	cout << "Enter HexaDecimal number: ";
			char hex1[100];
			cin >> hex1;
			cout << "Binary for given Hexadecimal is : ";
			htob(hex1);
			break;
	}
	cout << "\n";
	system("pause");
}

