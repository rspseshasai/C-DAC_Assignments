
#include "pch.h"
#include<stack>
#include <iostream>
#include<string>
using namespace std;

int main()
{
	stack<char>s;
	string str;
	cout << "Enter Expression\n";
	getline(cin, str);
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
		{
			s.push(str[i]);
		}
		else if ((!s.empty()) && ((str[i] == ')' &&	s.top() == '(') || (str[i] == ']' && s.top() == '[') || (str[i] == '}' && s.top() == '{')))
		{
			s.pop();
		}
	}
	if (s.empty())
		cout << "Balanced\n";
	else
		cout << "Not Balanced\n";
	system("pause");
}
