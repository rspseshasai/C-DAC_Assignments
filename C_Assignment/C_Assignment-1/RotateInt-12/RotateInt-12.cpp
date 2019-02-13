#include "pch.h"
#include <iostream>
using namespace std;
int rotate_right(int n, int b)
{
	int l = 1 + floor(log(n) / log(10));
	if (b > l)
	{
		b = b % l;
	}
	int power = (int)pow(10, b);
	int f = n % power;
	//cout << f << " " << power << "\n";
	int temp = (int)pow(10, (l - b));
	f = (f * temp);
	f += (n / power);
	return f;
}

int main()
{
	int n, b;
	cout << "Enter number and no. of bits\n";
	cin >> n >> b;
	cout << "Rotated bits: " << rotate_right(n, b)<<endl;
	system("pause");
}

