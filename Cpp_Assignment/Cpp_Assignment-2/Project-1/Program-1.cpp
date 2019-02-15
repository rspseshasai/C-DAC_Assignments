
#include "stdafx.h"
#include<string>
#include<iostream>
using namespace std;
class Polar
{
	int ang, rad;
	static int cnt;
public:
	Polar(int a, int r)
	{
		ang = a;
		rad = r;
	}
	static void display(Polar ob)
	{
		cnt++;
		cout << "Angle: " << ob.ang << "\nRadius: " << ob.rad << "\n";
		cout << "Count = " << cnt << endl;
	}
};

int Polar::cnt = 0;


int main()
{
	cout << "Enter angle and radius: ";
	int r, a;
	cin >> a >> r;
	Polar ob(a, r);
	ob.display(ob);
	Polar ob2(a, r);
	ob2.display(ob);
	system("pause");
	return 0;

}

