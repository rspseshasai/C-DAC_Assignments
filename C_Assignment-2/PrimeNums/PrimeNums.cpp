

#include "pch.h"
#include <iostream>
using namespace std;

int isPrime(int n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n%i == 0)
			return 0;
	}
	return 1;
}

int main()
{
	cout << "Enter Range\n";
	int a, b;
	cin >> a >> b;
	cout << "Primes in given interval : ";
	for (int i = a; i <= b; i++)
	{
		if (isPrime(i))
			cout << i << " ";
	}
	system("pause");
}

