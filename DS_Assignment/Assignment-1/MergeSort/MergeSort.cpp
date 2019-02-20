
#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;

void mergesort(int arr[], int a, int b)
{

}
int main()
{
	vector<int >arr;
	int n;
	cout << "Enter Size of Array: ";
	cin >> n;
	cout << "Enter Array Elements\n";
	for (int i = 0; i < n; i++)
	{
		int ele;
		cin >> ele;
		arr.push_back(ele);
	}
	mergesort(arr, 0, n / 2);
	mergesort(arr, (n / 2 + 1), n - 1);
	system("pause");
}

