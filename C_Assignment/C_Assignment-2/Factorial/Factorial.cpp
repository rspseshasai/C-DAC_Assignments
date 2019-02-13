

#include "pch.h"
#include <iostream>
using namespace std;

long int fact(int n)
{
	if (n == 0)
		return 1;
	else
		return n * fact(n - 1);
}

int main()
{
	int n;
	cout << "Enter a Number\n";
	cin >> n;
	cout<<"Factorial is : " << fact(n)<<"\n";
	system("pause");
}

