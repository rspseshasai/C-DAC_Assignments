
#include "pch.h"
#include <iostream>
using namespace std;

int arr[50]; 

void print(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void merge(int arr[], int a, int mid, int b)
{
	int l[10], r[10], k=0;
	for (int i = a; i <= mid; i++)
	{
		l[k++] = arr[i];
	}
	int ln = k;
	k = 0;
	for (int i = mid + 1; i <= b; i++)
	{
		r[k++] = arr[i];
	}
	int rn = k;
	k = 0;

	/*for (int i = 0; i < ln; i++)
	{
		cout << l[i] << " ";
	}*/

	int ptr1 = 0, ptr2 = 0;
	k = a;
	while (ptr1 < ln && ptr2 < rn)
	{
		if (l[ptr1] > r[ptr2])
		{
			arr[k++] = r[ptr2];
			ptr2++;
		}
		else if(l[ptr1]< r[ptr2])
		{
			arr[k++] = l[ptr1];
			ptr1++;
		}
		else
		{
			arr[k++] = l[ptr1];
			ptr1++;
			//ptr2++;
		}
	}

	if (ptr1 < ln)
	{
		while (ptr1 < ln)
		{
			arr[k++] = l[ptr1];
			ptr1++;
		}
	}
	if (ptr2 < rn)
	{
		while (ptr2 < rn)
		{
			arr[k++] = r[ptr2];
			ptr2++;
		}
	}
}

void mergesort(int arr[], int a, int b)
{
	if (a < b)
	{
		int mid = ((a + (b-a)/2));
		mergesort(arr, a, mid);
		mergesort(arr, mid+1, b);
		merge(arr, a, mid, b);
	}
}
int main()
{
	int n;
	cout << "Enter Size of Array: ";
	cin >> n;
	cout << "Enter Array Elements\n";
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	mergesort(arr, 0, n-1);
	//merge(arr, 0, n / 2, n - 1);
	print(arr, n);
	system("pause");
}

