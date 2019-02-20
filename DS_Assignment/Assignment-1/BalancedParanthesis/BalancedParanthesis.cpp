
#include "pch.h"
#include<stack>
#include <iostream>
#include<string>
using namespace std;

int main()
{
	stack<char>s;
	string str;
	int flag = 0;
	cout << "Enter Expression\n";
	getline(cin, str);
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
		{
			s.push(str[i]);
		}
		else //if ((!s.empty()) && ((str[i] == ')' &&	s.top() == '(') || (str[i] == ']' && s.top() == '[') || (str[i] == '}' && s.top() == '{')))
		{
			if (str[i] == ')')
			{
				if (!s.empty())
				{
					if (s.top() == '(')
						s.pop();
				}
				else
				{
					flag = 1;
					//cout << "Not Balanced\n";
				}
			}

			else if (str[i] == ']')
			{
				if (!s.empty())
				{
					if (s.top() == '[')
						s.pop();
				}
				else
				{
					flag = 1;
					//cout << "Not Balanced\n";
				}
			}

			if (str[i] == '}')
			{
				if (!s.empty())
				{
					if (s.top() == '{')
						s.pop();
				}
				else
				{
					flag = 1;
					//cout << "Not Balanced\n";
				}
			}
		}
	}
	if (s.empty() && flag==0)
		cout << "Balanced\n";
	else
		cout << "Not Balanced\n";
	system("pause");
}
