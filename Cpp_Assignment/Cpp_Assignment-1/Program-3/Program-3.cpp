
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

//-------------------------------------Validate Input
bool input_valid(string s)
{
	int i, length_s;
	bool is_valid = true;

	length_s = s.length();

	if (length_s == 0)
		is_valid = false;
	else
	{
		if (length_s == 1)
		{
			if (!isdigit(s[0]))
				is_valid = false;
		}
		else
		{
			if (s[0] == '+' || s[0] == '-' || isdigit(s[0]) != 0)
			{
				for (i = 1; i < length_s; i++)
				{
					if (!isdigit(s[i]))
					{
						if (s[i] != '.')
							is_valid = false;
					}
				}
			}
			else
				is_valid = false;
		}
	}
	return is_valid;
}



int get_input()
{
	int int_number, check_float = 0;
	string number;
	bool is_valid = true;

	do {
		getline(cin, number);
		cout << "\n";

		is_valid = input_valid(number);

		if (is_valid == false)
			cout << "Invalid Input...Enter again\n" << endl;
	} while (is_valid == false);

	int_number = stoi(number);

	return int_number;
}

//-------------------------------------------------------------------

int main()
{
	int real_1 = 0, real_2 = 0, img_1 = 0, img_2 = 0;
	cout << "Enter Real Part of Number 1 : ";
	real_1 = get_input();

	cout << "Enter Imaginary Part of Number 1 : ";

	img_1 = get_input();

	cout << "\nEnter Real Part of Number 2 : ";
	real_2 = get_input();

	cout << "Enter Imaginary Part of Number 2 : ";
	img_2 = get_input();

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