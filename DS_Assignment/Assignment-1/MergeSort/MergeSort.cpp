
#include "pch.h"
#include <iostream>
using namespace std;

void merge(int arr[], int a, int mid, int b)
{

}

void mergesort(int arr[], int a, int b)
{
	if (a < b)
	{
		int mid = ((a + b) / 2);
		mergesort(arr, a, mid);
		mergesort(arr, mid+1, b);
		merge(arr, a, mid, b);
	}
}
int main()
{
	int arr[10];
	int n;
	cout << "Enter Size of Array: ";
	cin >> n;
	cout << "Enter Array Elements\n";
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	mergesort(arr, 0, n-1);
	system("pause");
}

