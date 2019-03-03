#include "pch.h"
#include<iostream>
#define MAX 20
using namespace std;


void Swap(int &a, int &b) 
{ 
    int temp = a; 
    a = b; 
    b = temp; 
} 

int QuickSort (int a[], int low, int high) 
{ 
    int pivot = a[high];   
    int i = (low - 1);  
  
    for (int j = low; j <= high- 1; j++) 
    { 
        if (a[j] <= pivot) 
        { 
            i++; 
            Swap(a[i], a[j]); 
        } 
    } 
    Swap(a[i + 1], a[high]); 
    return (i + 1); 
} 
  
void Sort(int a[], int low, int high) 
{ 
    if (low < high) 
    { 
        int temp = QuickSort(a, low, high); 
        Sort(a, low, temp - 1); 
        Sort(a, temp + 1, high); 
    } 
} 
   

int main() 
{ 
	int a[MAX];
	int n;
	cout << "Enter no. of Elements: ";
	cin >> n;
	cout << "Enter elements : ";
	for (int i = 0; i < n; i++)
		cin >> a[i];
    Sort(a, 0, n-1); 
	cout << "After Sorting Elements are: ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << "\n";
	system("pause");
} 