
#include "stdafx.h"
#include<string>
#include<iostream>
using namespace std;
class Complex
{
	int real, img;
public:
	Complex()
	{
		real = 0;
		img = 0;
	}
	Complex(int r, int i)
	{
		real = r;
		img = i;
	}
	Complex(Complex &ob)
	{
		real = ob.real;
		img = ob.img;
	}

	Complex operator+ (Complex c)
	{
		Complex temp;
		temp.real = real + c.real;
		temp.img = img + c.img;
		return temp;
	}

	Complex operator- (Complex c)
	{
		Complex temp;
		temp.real = real - c.real;
		temp.img = img - c.img;
		return temp;
	}

	Complex operator++ ()
	{
		Complex temp;
		temp.real = real++;
		temp.img = img++;
		return temp;
	}

	Complex operator- ()
	{
		Complex temp;
		temp.real = -real;
		temp.img = -img;
		return temp;
	}

	Complex operator++(int x)
	{
		Complex temp;
		temp.real = real++;
		temp.img = img++;
		return temp;
	}
	friend ostream & operator<< (ostream &cout, Complex ob);
};


ostream & operator<< (ostream &cout, Complex ob)
{
	cout <<"("<< ob.real << ")+(" << ob.img<<"i)\n";
	return cout;
}

istream & operator >> (istream &cin, Complex &ob)
{
	
	return cin;
}

int main()
{
	Complex ob();
	Complex ob1(2, 3);
	Complex ob2(ob1);
	cout<<"+ binary overload: " << ob1 + ob2;
	cout<<"- binary overload: " << ob1 - ob2;
	cout<<"- unary overload: " << -ob1;
	cout<<"prefix overload: "<< ++ob1;
	cout <<"postfix overload: "<< ob1++;
	system("pause");
	return 0;

}

