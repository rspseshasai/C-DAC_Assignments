// Palindrome.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;

//sample comment 

int main()
{
	vector <int > a;
    cout << "Enter a Number\n"; 
	int n;
	cin >> n;
	while (n > 0)
	{
		a.push_back((n % 10));
		n /= 10;
	}
	int flag = 0;
	for(int i = 0; i < (a.size() / 2); i++)
	{
		if (a[i] != a[a.size() - i - 1])
		{
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		cout << "Palindrome\n";
	else
		cout << "Not a Palindrome\n";
	system("pause");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//123454321
//12344321
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
