
#include "pch.h"
#include <iostream>
using namespace std;

class Time
{
public:
	int h, m, s;
	Time()
	{
		h = 0;
		m = 0;
		s = 0;
	}
	Time(int h1, int m1, int s1)
	{
		h = h1;
		m = m1;
		s = s1;
	}
	void print(Time &t)
	{
		cout << t.h << ":" << t.m << ":" << t.s << "\n";
	}
	void SumTime(Time &t1, Time &t2, Time &t3)
	{
		t3.s = t1.s + t2.s;
		t3.m = t1.m + t2.m;
		//cout << t3.s << "\n ";
		if (t3.s > 60)
		{
			int rem = t3.s - 60;
			t3.m += 1;
			t3.s = rem;
		}
		t3.h = t1.h + t2.h;
		if (t3.m > 60)
		{
			int rem = t3.m - 60;
			t3.h += 1;
			t3.m = rem;
		}
	}
};

int main()
{
	int h1, m1, s1, h2, m2, s2;
	Time t;
	//t.print(t);
	cout << "Enter Time1: ";
	cin >> h1 >> m1 >> s1;
	cout << "Enter Time2: "; 
	cin>>h2 >> m2 >> s2;
	Time t1(h1, m1, s1);
	//t1.print(t1);
	Time t2(h2, m2, s2);
	//t2.print(t2);
	Time t3;
	t3.SumTime(t1, t2, t3);
	t3.print(t3);
	system("pause");
}
