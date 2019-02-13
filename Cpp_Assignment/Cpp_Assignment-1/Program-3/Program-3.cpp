
#include "pch.h"
#include <iostream>
#include<string>
using namespace std;

class Complex
{
	int real, img;
public:
	Complex()
	{
		real = 0, img = 0;
	}
	Complex(int val)
	{
		real = val;
		img = val;
	}
	Complex(int v1, int v2)
	{
		real = v1;
		img = v2;
	}
	friend void addComplex(Complex, Complex);
	friend void mulComplex(Complex, Complex);
};

void addComplex(Complex c1, Complex c2)
{
	cout << "Addition of two complex numbers: " << c1.real + c2.real << "+" << c1.img + c2.img << "i\n";
}


// (2+3i)*(5+7i)
// (2 * 5) + (2 * 7i) + (3i * 5) + (3i * 7i)
// 10 + 14i + 15i + 21(-1)
// 10-21 + 29i
// 29i - 11

void mulComplex(Complex c1, Complex c2)
{
	cout << "Multiplication of two complex numbers: " << ((c1.real * c2.real) - (c1.img * c2.img)) << "+" << ((c1.real * c2.img) + (c1.img * c2.real)) << "i\n";
}

int main()
{
	int r1, r2, i1, i2;
	cout << "Enter Real & Imaginary of Number 1: ";
	cin >> r1 >> i1;
	cout << "Enter Real & Imaginary of Number 2: ";
	cin >> r2 >> i2;
	Complex c1(r1, i1);
	Complex c2(r2, i2);
	addComplex(c1, c2);
	mulComplex(c1, c2);
	system("pause");
}


