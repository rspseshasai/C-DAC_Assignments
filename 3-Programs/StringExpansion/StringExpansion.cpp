// StringRotations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	char s1[100];
	char s2[100] = "";
	cout << "Enter a string: ";
	scanf("%[^\n]s", s1);

	/*for (int i = 0; i < strlen(s1); i++)
	{*/

	/*}*/

	for (int i = 0; i < strlen(s1); i++)
	{
		if (s1[i] == '-')
		{
			//if ((s1[i+1] >= 'a' && s1[i] <= 'z') || (s1[i+1] >= '0' && s1[i+1] <= '9') || (s1[i + 1] >= 'A' && s1[i] <= 'Z'))
			//{

			//}
			//else
			//{
			//	cout << "Invalid Input\n";
			//	exit(0);
			//}
			if (i != 0 && i != strlen(s1) - 1)
			{
				//----------------------------------
				//if (isalpha(s1[i - 1]))
				//{
				//	if (isalpha(s1[i + 1]))
				//	{

				//	}
				//	else
				//	{

				//	}
				//}
				//----------------------------------
				int n1 = s1[i - 1], n2 = s1[i + 1];
				if (n1 >= 65 && n1 <= 90)
				{
					if (n2 >= 65 && n2 <= 90)
					{
						//print char
						for (int j = n1 + 1; j < n2; j++)
						{
							//strcat(s2, (char *)j);
							cout << (char)j;
						}
					}
					else
					{
						//print normal
						//cout << s1[i - 1] << "-" << s1[i + 1];
					}
				}
				if (n1 >= 97 && n1 <= 122)
				{
					if (n2 >= 97 && n2 <= 122)
					{
						//print char
						for (int j = n1 + 1; j < n2; j++)
						{
							//strcat(s2, (char *)j);
							cout << (char)j;
						}
					}
					else
					{
						//print normal
						//cout << s1[i - 1] << "-" << s1[i + 1];
					}
				}
				if (n1 >= 48 && n1 <= 57)
				{
					if (n2 >= 48 && n2 <= 57)
					{
						//print char
						for (int j = n1 + 1; j < n2; j++)
						{
							//strcat(s2, (char *)j);
							cout << (char)j;
						}
					}
					else
					{
						//print normal
						//cout << s1[i - 1] << "-" << s1[i + 1];
					}
				}
			}
			else
			{
				cout << "\nInput Error\n";
			}
		}
		else
		{
			//strcat(s2, (char *)s1[i]);
			cout << s1[i];
		}
	}
	cout << "\n";
	system("pause");
}


