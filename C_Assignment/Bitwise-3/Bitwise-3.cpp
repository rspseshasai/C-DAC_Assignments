
#include "pch.h"
#include <iostream>
using namespace std;

long long int dtob(int dec)
{
	long long int bin = 0;
	for (int i = 15; i >= 0; i--)
	{
		int k = dec >> i;
		if (k & 1)
			bin = bin * 10 + 1;
		else
			bin = bin * 10 + 0;
	}
		return bin;
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


int main()
{
	int val = 0xCAFE, k;
	long long int bin=1;
	long long int temp= 65535;
	temp = val & temp;//And with 65535 gives actual input(for retriving val)	
	bin = dtob(temp);
	long long int val1 = bin;

	//checking if 3 of last 4 bits are 1's

	cout<<"Input in Binary notation is: " << val1 << "\n\n"; 
	int c = 0, c1=1;
	while (val1>0 && c1<=4)
	{
		int r = val1 % 2;
		if (r == 1)
			c++;
		c1++;
		val1 /= 10;
	}
	if (c >= 3)
		cout << "3 of Last four bits are 1's\n\n";
	else
		cout << "3 of Last four bits are not 1's\n\n";

	int byte1;
	//reversing byte order and storing reversed byte ordered value in ans in binary format
	long long int ans=0, oBin= bin;
	while(bin>0)
	{
	    byte1 = bin % ((int)pow(10, 8));
		ans = (ans*(int)pow(10, 8)) + byte1;
		bin = bin/ ((int)pow(10, 8));
	}
	cout<<"After Inverting byte order:\n\tBinary value is: " << ans << "\n\t";

	//converting ans(from binary) to decimal
	int deci = btod(ans);
	cout<<"Decimal value is : " << deci << "\n\tHexadecimal value is : ";
	btoh(ans);
	
	//Rotate n bits
	int nb = 0;
	cout << "\n\nEnter no. of bits to rotate: ";
	cin >> nb;
	long long int rotatedNum = 1;
	long long int nbitVal = oBin % ((int)pow(10, nb));
	oBin /= ((int)pow(10, nb));
	rotatedNum = (nbitVal*(long long int)pow(10, (16- nb))) + oBin;

	cout<<"After rotating "<<nb<<" bits\n\tBinary value is : "<< rotatedNum << "\n\t";
	int deci1 = btod(rotatedNum);
	cout << "Decimal value is : " << deci1 << "\n\tHexadecimal value is : ";
	btoh(rotatedNum);
	cout << "\n\n";

	system("pause");
}

