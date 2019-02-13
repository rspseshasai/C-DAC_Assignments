
#include "pch.h"
#include <iostream>
#include<string>
using namespace std;

class Arithametic
{
public:
	int a, b;
	Arithametic(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	int sum, diff, mod, prod, div;
	void add();
	void sub();
	void mul();
	void divide();
	void modulus();
	void print()
	{
		cout << "Addition: " << sum << "\n";
		cout << "Subtraction: " << diff << "\n";
		cout << "Multiply: " << prod << "\n";
		cout << "Division: " << div << "\n";
		cout << "Modulus: " << mod << "\n";
	}
};

inline void Arithametic :: add()
{
	sum = a + b;
}
inline void Arithametic::sub()
{
	diff = a - b;
}
inline void Arithametic::mul()
{
	prod = a * b;
}
inline void Arithametic::divide()
{
	div = a / b;
}
inline void Arithametic::modulus()
{
	mod = a % b;
}
int main()
{
	int a, b;
	cout << "Enter 2 numbers\n";
	cin >> a >> b;
	Arithametic obj(a, b);
	obj.add();
	obj.sub();
	obj.mul();
	obj.divide();
	obj.modulus();
	obj.print();
	system("pause");
}
