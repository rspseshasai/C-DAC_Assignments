// StringRotations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*#include "pch.h"
#include <iostream>
using namespace std;



char * del(char * s1, char * s2)
{
	int count = 0,i ,j, k;
	int len = strlen(s1);
	int l2 = strlen(s2);
	for (i = 0; i < l2; i++)
	{
		k = 0;
		for (j = 0; j < len; j++)
		{
			if (s1[j] == s2[i])
			{
				continue;
			}
			s1[k++] = s1[j];
			
		}
		s1[k] = '\0';
		
	}
	//cout << s1 << "\n";
	return s1;
}

int main()
{
	char s1[100], s2[100];
	cout << "Enter 1st string: \n";
	scanf("%[^\n]s", s1);
	cout << "Enter 2nd string: \n";
	scanf(" %[^\n]s", s2);
	cout<<"\n"<<del(s1, s2)<<"\n";
	//cout << s1 << "\n";
	system("pause");
}

*/



// StringRotations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;



char * del(char * s1, char s2)
{
	int count = 0, i, j, k;
	int len = strlen(s1);
	for (i = 0; i < len - count; i++)
	{
		if (s1[i] == s2)
		{
			for (j = i + 1; j < len - count; j++)
			{
				s1[j - 1] = s1[j];
			}
			count++;
			s1[j - 1] = '\0';
		}

	}
	return s1;
}

int main()
{
	char s1[100], s2[100];
	cout << "Enter 1st string \n";
	scanf("%[^\n]s", s1);
	cout << "Enter 2nd string\n";
	cin >> s2;
	//cout << "After Deleting: ";
	char *temp=NULL;
	for (int i = 0; i < strlen(s2); i++)
	{
		temp = del(s1, s2[i]);
	}
	cout<<"After Deleting String is : "<< temp << "\n";
	system("pause");
}

