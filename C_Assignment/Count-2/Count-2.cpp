// Count-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	char text[80];
	cout << "Enter String\n";
	scanf("%[^\n]", &text);
	int digits = 0, tabs = 0, alphas = 0, spaces = 0, spChars=0;
	//cout << strlen(text) << "\n";
	for (int i = 0; i < strlen(text); i++)
	{
		if (isdigit(text[i]))
			digits++;
		else if (isalpha(text[i]))
			alphas++;
		else if (text[i] == ' ')
			spaces++;
		else if (text[i] == '\t')
			tabs++;
		else
			spChars++;
	}
	cout << "Number of digits: " << digits << "\nNumber of Alphabets: " << alphas << "\nNumber of spaces: " << spaces << "\nNumber of tab spaces: " << tabs<<"\nNumber of Special Characters: "<<spChars<<"\n";
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
