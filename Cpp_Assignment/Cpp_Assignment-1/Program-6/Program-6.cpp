
#include "pch.h"
#include <iostream>
#include<string>
using namespace std;

class Point
{
	int x, y;
public:
	Point(int a, int b)
	{
		x = a;
		y = b;
	}
	friend void sum(Point, Point);
};
void sum(Point o1, Point o2)
{
	cout<<"Distance is: " << (sqrt((int)(pow((o2.x - o1.x), 2)) + (int)(pow((o2.y - o1.y), 2))))<<"\n";
}
int main()
{
	int a1, a2, b1, b2;
	cout << "Enter co-ordinates of point1: ";
	cin >> a1 >> b1;
	cout << "Enter co-ordinates of point2: ";
	cin >> a2 >> b2;
	Point o1(a1, b1);
	Point o2(a2, b2);
	sum(o1, o2);
	system("pause");
}
