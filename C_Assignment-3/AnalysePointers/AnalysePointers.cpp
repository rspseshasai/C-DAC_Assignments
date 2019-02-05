// AnalysePointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int x[8] = { 10,20,30,40,50,60,70,80 };
	cout << "\nx      = " << x;
	cout << "\n(x+2)  = " << (x + 2);
	cout << "\n*x     = " << *x;
	cout << "\n(*x+2) = " << (*x + 2);
	cout << "\n*(x+2) = " << *(x + 2)<<"\n";
	system("pause");
}

