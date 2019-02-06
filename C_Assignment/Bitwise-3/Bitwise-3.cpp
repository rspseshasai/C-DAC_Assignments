
#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int val = 0xCAFE, k;
	long long int bin=1;
	long long int temp= 65535;
	temp = val & temp;//And with 65535 gives actual input(for retriving val)
	cout << temp<<"\n";
	//converting temp (from decimal) to binary and storing in bin
	for (int i = 16; i >= 0; i--)
	{
		int k = temp >> i;
		if (k & 1)
			bin = bin * 10 + 1;
		else
			bin = bin * 10 + 0;
	}
	//bin = dtob(temp);
	//cout << bin << "\n";
	//checking if 3 of last 4 bits are 1's
	val = bin;
	int c = 0, c1=1;
	while (val>0 && c1<=4)
	{
		int r = val % 2;
		if (r == 1)
			c++;
		c1++;
		val /= 10;
	}
	if (c >= 3)
		cout << "3 of Last four bits are 1's\n";
	else
		cout << "3 of Last four bits are not 1's\n";
	
	int nb = 2;
	int byte1;
	//reversing byte order and storing reversed byte ordered value in ans in binary format
	long long int ans=0;
	while(bin>0)
	{
		//ans = ans * ((int)pow(10, 8));
	    byte1 = bin % ((int)pow(10, 8));
		ans = (ans*(int)pow(10, 8)) + byte1;
		bin = bin/ ((int)pow(10, 8));
	}
	cout<<"After Inverting byte order: " << ans << "\n";

	//------------------------
	//converting ans(from binary) to deciamal
	//cout << "Decimal value of inverted byte ordered number: " << ans;
	//------------------------
	system("pause");
}

