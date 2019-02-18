
#include "pch.h"
#include<stack>
#include <iostream>
#include<string>
using namespace std;

stack<char>s;

int priority(char ch)
{
	switch (ch)
	{
	case '*':
		return 2;
	case '/':
		return 2;
	case '-':
		return 1;
	case '+':
		return 1;
	}
	return -1;
}

void InToPost(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (isalpha(str[i]))
			cout << str[i];
		else
		{
			
			if (str[i] == '[' || str[i] == '{' || str[i] == '(')
			{
				s.push(str[i]);
			}
			else
			{
				if (str[i] == ')')
				{
					while (s.top() != '(')
					{
						cout << s.top();
						s.pop();
					}
					s.pop();
				}
				else if (str[i] == ']')
				{
					while (s.top() != '[')
					{
						cout << s.top();
						s.pop();
					}
					s.pop();
				}
				else if (str[i] == '}')
				{
					while (s.top() != '{')
					{
						cout << s.top();
						s.pop();
					}
					s.pop();
				}
				else if (s.empty())
					s.push(str[i]);
				else if (priority(str[i]) > priority(s.top()))
				{
					s.push(str[i]);
				}
				else
				{
					int p = priority(str[i]);
					while (!s.empty() && priority(s.top()) >= p)
					{
						cout << s.top();
						s.pop();
					}
					s.push(str[i]);
				}
			}
		}
	}
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
}

int main()
{
	string str;
	cout << "Enter Infix Expression\n";
	getline(cin, str);
	cout << "PostFix Expression is: ";
	InToPost(str);
	cout << "\n";
	system("pause");
}
