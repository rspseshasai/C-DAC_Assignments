
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
	void display(Complex c1, Complex c2)
	{
		if(c1.img>0)
			cout << "First Complex Number is : " << c1.real << "+" << c1.img << "i\n";
		else
			cout << "First Complex Number is : " << c1.real << c1.img << "i\n";

		if (c2.img > 0)
			cout << "First Complex Number is : " << c2.real << "+" << c2.img << "i\n";
		else
			cout << "First Complex Number is : " << c2.real << c2.img << "i\n";
	}

	friend void addComplex(Complex, Complex);
	friend void mulComplex(Complex, Complex);
};

void addComplex(Complex c1, Complex c2)
{
	if (c1.img + c2.img < 0)
		cout << "Addition of two complex numbers: " << c1.real + c2.real << c1.img + c2.img << "i\n";
	else
		cout << "Addition of two complex numbers: " << c1.real + c2.real << "+" << c1.img + c2.img << "i\n";
}


// (2+3i)*(5+7i)
// (2 * 5) + (2 * 7i) + (3i * 5) + (3i * 7i)
// 10 + 14i + 15i + 21(-1)
// 10-21 + 29i
// 29i - 11
// (3-6i)*(4-9i)

void mulComplex(Complex c1, Complex c2)
{
	if(((c1.real * c2.img) + (c1.img * c2.real)) < 0)
		cout << "Multiplication of two complex numbers: " << ((c1.real * c2.real) - (c1.img * c2.img)) << ((c1.real * c2.img) + (c1.img * c2.real)) << "i\n";

	else
		cout << "Multiplication of two complex numbers: " << ((c1.real * c2.real) - (c1.img * c2.img)) << "+" << ((c1.real * c2.img) + (c1.img * c2.real)) << "i\n";
}


//while (!cin)
//{
//	cout << "Invalid";
//	cin.clear();
//	cin.ignore();
//	cin >> num;
//}

int TestInput(int inp)
{
	while (1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input...Enter Again !!" << endl;
			cin >> inp;
		}
		if (!cin.fail())
			break;
	}
	return inp;
}

int main()
{
	int real_1 = 0, real_2 = 0, img_1 = 0, img_2 = 0;
	cout << "Enter Real Part of Number 1 : ";
	cin >> real_1;
	real_1 = TestInput(real_1);

	cout << "Enter Imaginary Part of Number 1 : ";
	cin >> img_1;
	img_1 = TestInput(img_1);

	cout << "\nEnter Real Part of Number 2 : ";
	cin >> real_2;
	real_2 = TestInput(real_2);

	cout << "Enter Imaginary Part of Number 1 : ";
	cin >> img_2;
	img_2 = TestInput(img_2);

	cout << "\n";
	Complex Object1(real_1, img_1);
	Complex Object2(real_2, img_2);
	Object1.display(Object1, Object2);
	cout << "\n";
	addComplex(Object1, Object2);
	mulComplex(Object1, Object2);
	cout << "\n";
	system("pause");
}