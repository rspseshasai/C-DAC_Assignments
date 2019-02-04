// PositiveInput-7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;

int main()
{
	cout << "Enter Numbers\n";
	int n;
	int count = 0, max = 0, min = INT16_MAX, sum=0;
	while (1)
	{
		cin >> n;
		if (n > 0)
		{
			count++;
			sum += n;
			if (n >= max)
				max = n;
			if (n <= min)
				min = n;
		}
		else if (n <= 0)
			break;
	}
	float avg;
	avg = (float)(sum / count);
	cout << "Number of numbers Entered : " << count << "\nMax Number: " << max << "\nMin Number: " << min << "\nAverage: "<<avg<<"\n";
	system("pause");
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
