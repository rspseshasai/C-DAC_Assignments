
#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	cout << "Enter length: ";
	cin >> n;
	int arr[100];
	cout << "\nEnter elements\n";
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int start=0;
	int sum;
	cout << "Enter Sum: ";
	cin >> sum;
	int temp=0, end=0;
	for (int i = 0; i <= n; i++)
	{
		while (temp > sum && start < i - 1)
		{
			temp -= arr[start];
			start++;
		}
		if (sum == temp)
		{
			end = i - 1;
			break;
		}
		if (i < n)
		{
			temp += arr[i];
		}
	}
	cout<<"Subarray found between " << start << " " << end << "\n";
	for (int i = start; i <= end; i++)
		cout << arr[i] << " ";
	cout << "\n";
	
}
