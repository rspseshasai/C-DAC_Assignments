

#include "pch.h"
#include <iostream>
using namespace std;

class Shape
{
protected: 
	int a, b;
public:
	void set(int x, int y=1)
	{
		a = x;
		b = y;
	}
	virtual void Display_area()
	{
		cout << "Ntng!!\n";
	}
};

class Triangle : public Shape
{
public:
	void Display_area()
	{
		cout << "Area of Triangle: " << (a * b)/2<<"\n";
	}
};

class Rectangle : public Shape
{
public:
	void Display_area()
	{
		cout << "Area of Rectangle: " << (a * b)<<"\n";
	}
};

class Square : public Shape
{
public:
	void Display_area()
	{
		cout << "Area of Square: " << (a * a)<<"\n";
	}
};
int main()
{
	Shape *ob;
	Triangle t;
	Rectangle r;
	Square s;

	cout << "Enter Base and Height of Triangle\n";
	int b, h;
	cin >> b >> h;
	ob = &t;
	ob->set(b, h);
	ob->Display_area();

	cout << "Enter Side of Square\n";
	int side;
	cin >>side;
	ob = &s;
	ob->set(side);
	ob->Display_area();

	cout << "Enter Length and Breadth of Rectangle\n";
	int len, brt;
	cin >>len>>brt;
	ob = &r;
	ob->set(len, brt);
	ob->Display_area();

	system("pause");
}

