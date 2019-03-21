
#include "pch.h"
#include<stack>
#include <iostream>
#include<string>
using namespace std;

int ans = 0;
int add1(int, int);
int sub1(int, int);
int mul1(int, int);
int div1(int, int);

//-----------------------------------To Check if given String has Balanced Paranthesis
int isBalanced(string str)
{
	stack<char>s;
	int flag = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
		{
			s.push(str[i]);
		}
		else
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
				}
			}

			else if (str[i] == '}')
			{
				if (!s.empty())
				{
					if (s.top() == '{')
						s.pop();
				}
				else
				{
					flag = 1;
				}
			}
		}
	}
	if (s.empty() && flag == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//------------------------------------------------------------------------------------

int precedence(char oper)
{
	if (oper == '+' || oper == '-')
		return 1;
	if (oper == '*' || oper == '/')
		return 2;
	return 0;
}


int operation(int var1, int var2, char oper)
{
	switch (oper) {
	case '+':
		ans = add1(var1, var2);
		return ans;
	case '-':
		ans = sub1(var1, var2);
		return ans;
	case '*':
		ans = mul1(var1, var2);
		return ans;
	case '/':
		if (var2 == 0)
		{
			cout << "Divide by zero not Possible\n";
			exit(0);
		}
		ans = div1(var1, var2);
		return ans;
	}
}

int ExpressionEval(string str)
{
	stack<int >variablesStack;
	stack<char >operatorsStack;
	//cout <<str<< "\n";
	for (int i = 0; i < str.length(); i++)
	{
		//cout << str << "\n";
		if (str[i] == ' ')
			continue;
		//----------------------------Push to variablesStack if we encounter a digit

		else if (str[i] == '-')
		{
			if (i == 1) //To check if - is unary
			{
				int n = 0;
				//cout << str[i + 3] << "\n";
				if (str[i + 3] == '+' || str[i + 3] == '*' || str[i + 3] == '/' || str[i + 3] == '(' || str[i + 3] == '-')
				{
					cout << "Invalid Expression-7\n";
					exit(0);
				}

				i += 2;
				while (i < str.length() &&
					isdigit(str[i]))
				{
					n = n * 10 + (str[i] - '0');
					i++;
				}
				n = n * (-1);
				variablesStack.push(n);
			}
			else if (i < 3) //i.e., i==2  =>  - is binary
			{
				while (!operatorsStack.empty() && precedence(operatorsStack.top()) >= precedence(str[i]))
				{
					int var1 = variablesStack.top();
					variablesStack.pop();

					int var2 = variablesStack.top();
					variablesStack.pop();

					char oper = operatorsStack.top();
					operatorsStack.pop();

					variablesStack.push(operation(var2, var1, oper));
				}
				operatorsStack.push(str[i]);
			}
			else // i >= 3
			{
				if (str[i - 3] == '+' || str[i - 3] == '-' || str[i - 3] == '*' || str[i - 3] == '/' || str[i - 3] == '(')
				{
					if (str[i + 2] == '+' || str[i + 2] == '-' || str[i + 2] == '*' || str[i + 2] == '/')
					{
						cout << "Invalid Expression - 6\n";
						return -1;
					}
					else // - is unary
					{
						int n = 0;
						i += 2;
						while (i < str.length() &&
							isdigit(str[i]))
						{
							n = n * 10 + (str[i] - '0');
							i++;
						}
						n = n * (-1);
						variablesStack.push(n);
					}
				}
				else // - is binary
				{
					while (!operatorsStack.empty() && precedence(operatorsStack.top()) >= precedence(str[i]))
					{
						int var1 = variablesStack.top();
						variablesStack.pop();

						int var2 = variablesStack.top();
						variablesStack.pop();

						char oper = operatorsStack.top();
						operatorsStack.pop();

						variablesStack.push(operation(var2, var1, oper));
					}
					operatorsStack.push(str[i]);
				}

			}

		}

		//-----------------------------------Push to variablesStack if we encounter a digit
		else if (isdigit(str[i]))
		{
			int n = 0;
			while (i < str.length() &&
				isdigit(str[i]))
			{
				n = n * 10 + (str[i] - '0');
				i++;
			}
			variablesStack.push(n);
		}
		//--------------------------------------------------------------------------------

		//-----------------------------------push to operatorsStack if we encounter open brace
		else if (str[i] == '(')
		{
			operatorsStack.push(str[i]);
		}
		//----------------------------------------------------------------------------------

		//----------------------------------------------Closing brace
		else if (str[i] == ')')
		{
			while (operatorsStack.top() != '(' && !operatorsStack.empty())
			{
				int var1 = variablesStack.top();
				variablesStack.pop();

				int var2 = variablesStack.top();
				variablesStack.pop();

				char oper = operatorsStack.top();
				operatorsStack.pop();

				variablesStack.push(operation(var2, var1, oper));
			}
			operatorsStack.pop(); //to Pop open brace;
		}

		//-----------------------------------------------Operators other than - occurs
		else
		{
			while (!operatorsStack.empty() && precedence(operatorsStack.top()) >= precedence(str[i]))
			{
				int var1 = variablesStack.top();
				variablesStack.pop();

				int var2 = variablesStack.top();
				variablesStack.pop();

				char oper = operatorsStack.top();
				operatorsStack.pop();

				variablesStack.push(operation(var2, var1, oper));
			}
			operatorsStack.push(str[i]);
		}
		//------------------------------------------------------------------------------
	}

	//---------------------------------------------Perform operation for remaining elements in stack
	while (!operatorsStack.empty())
	{
		int var1 = variablesStack.top();
		variablesStack.pop();

		int var2 = variablesStack.top();
		variablesStack.pop();

		char oper = operatorsStack.top();
		operatorsStack.pop();

		variablesStack.push(operation(var2, var1, oper));
	}
	//---------------------------------------------------------------------------------------------------
	return variablesStack.top();
}

int main()
{
	string inpExpression, modifiedExp;
	cout << "Enter an Expression\n";
	getline(cin, inpExpression);
	if (1 == isBalanced(inpExpression))
	{
		for (int i = 0; i < inpExpression.length(); i++)
		{
			//------------------------------To check that there is no Operator before brackets
			if (inpExpression[i] == '(')
			{
				if (i - 1 >= 0)
				{
					if (inpExpression[i - 1] != '+' && inpExpression[i - 1] != '-' && inpExpression[i - 1] != '*' && inpExpression[i - 1] != '/' && inpExpression[i - 1] != '(')
					{
						cout << "Invalid Expression-4\n";
						return 0;
					}
				}
				//---------------------------------------------------------------------------------

					//----------------------------------To check that there is no Operator after brackets
				if (i + 1 < inpExpression.length())
				{
					if (inpExpression[i + 1] == '+' || inpExpression[i + 1] == '*' || inpExpression[i + 1] == '/')
					{
						cout << "Invalid Expression-5\n";
						return 0;
					}
				}
				//-----------------------------------------------------------------------------------
			}
		}

		int expLength = inpExpression.length() - 1;
		//--------------------------------------To check if there is no operator at beginning or at the end
		if (
			(inpExpression[0] == '/' || inpExpression[0] == '*' || inpExpression[0] == '+') ||
			(inpExpression[expLength] == '/' || inpExpression[expLength] == '*' || inpExpression[expLength] == '+' || inpExpression[expLength] == '-')
			)
		{
			if (inpExpression[0] != '-')
			{
				cout << "Invalid Expression-1 !!\n";
				return 0;
			}
		}
		//-------------------------------------------------------------------------------------------------

		//---------------------------To check if there are not two Operators in consequent positions

		//string tempString;
		//tempString += inpExpression[0];

		for (int i = 1; i < expLength; i++)
		{
			if (inpExpression[i] == '+' || inpExpression[i] == '-' || inpExpression[i] == '*' || inpExpression[i] == '/')
			{
				if (inpExpression[i + 1] == '+' || inpExpression[i + 1] == '*' || inpExpression[i + 1] == '/')
				{
					cout << "Invalid Expression-2\n";
					return 0;
				}
			}
		}
		//--------------------------------------------------------------------------------------------

		for (int i = 0; i < inpExpression.length(); i++)
		{
			if (inpExpression[i] == '+' || inpExpression[i] == '-' || inpExpression[i] == '*' || inpExpression[i] == '/' || inpExpression[i] == '(' || inpExpression[i] == ')')
			{
				modifiedExp += ' ';
				modifiedExp += inpExpression[i];
				modifiedExp += ' ';
			}
			else if (isdigit(inpExpression[i]))
			{
				modifiedExp += inpExpression[i];
			}
			else
			{
				cout << "Expression Invalid-3 \n";
				exit(0);
			}
		}

		cout << "Value after Evaluation is: ";
		ans = ExpressionEval(modifiedExp);
		cout << ans << "\n";
	}
	else
	{
		cout << "Expression is Not Balanced\n";
	}
	system("pause");
}
