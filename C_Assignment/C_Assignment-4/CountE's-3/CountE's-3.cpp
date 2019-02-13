
#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	const char * s[] = { 
	"we will teach youhow to" , 
	"Move a mountain ", 
	"Level a building ", 
	"Erase the past ", 
	"Make a million " };

	//cout << sizeof(s)/sizeof(char *) << " " << strlen(s[2]);
	int n = sizeof(s) / sizeof(char *);
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < strlen(s[i]); j++)
		{
			if (s[i][j] == 'e')
				count++;
		}
	}
	cout << "No. of E's are: " << count << "\n";
	system("pause");
}
