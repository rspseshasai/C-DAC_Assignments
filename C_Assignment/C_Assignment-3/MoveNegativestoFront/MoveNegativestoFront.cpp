// MoveNegativestoFront.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	int n;
	cout << "Enter length: ";
	cin >> n;
	int arr[100];
	cout << "Enter Array elements\n";
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int x=0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < 0)
		{
			if (i != x)
			{
				swap(arr[i], arr[x]);
			}
			x++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n\n";
	system("pause");
}
