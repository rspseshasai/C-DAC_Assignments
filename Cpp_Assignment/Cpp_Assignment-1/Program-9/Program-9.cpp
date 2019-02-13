
#include "pch.h"
#include <iostream>
#include<string>
using namespace std;

class Swap
{
public:
	void swap_val(int a, int b)
	{
		a = a + b;
		b = a - b;
		a = a - b;
	}
	void swap_ref(int &a, int &b)
	{
		a = a + b;
		b = a - b;
		a = a - b;
	}
};

int main()
{
	int n1, n2;
	cout << "Enter two Numbers\n";
	cin >> n1 >> n2;
	cout << "1 - Swap using Call by Value\n2 - Swap using Call by Reference\n";
	int ch;
	cin >> ch;
	Swap obj;
	switch (ch)
	{
	case 1:
		obj.swap_val(n1, n2);
		cout << "After swapping by value n1 = " << n1 << " n2 = " << n2 << "\n";
		break;
	case 2:
		obj.swap_ref(n1, n2);
		cout << "After swapping by reference n1 = " << n1 << " n2 = " << n2 << "\n";
		break;
	}
	system("pause");
}
