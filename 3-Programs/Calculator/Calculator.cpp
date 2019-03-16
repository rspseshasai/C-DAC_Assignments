
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


int isBalanced(string str)
{
	stack<char>s;
	int flag = 0;
	//cout << str<<"\n";
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
				//cout << "--)--\n";
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
	if (s.empty() && flag == 0)
	{
		//cout << "1\n";
		return 1;
	}
	else
	{
		//cout << "-o-\n";
		return 0;
	}
}

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
		ans = div1(var1, var2);
		return ans;
	}
}

// - 2 * 6

int ExpressionEval(string str)
{
	stack<int >vars;
	stack<char >opers;

	for (int i = 0; i < str.length(); i++)
	{

		if (str[i] == ' ')
			continue;
		//push to vars stack if we encounter a digit
		else if (str[i] == '-')
		{
			//cout << "sta = " << str[i] << "\n";
			if (i == 1)
			{
				int n = 0;
				i += 2;
				while (i < str.length() &&
					isdigit(str[i]))
				{
					//cout << str[i] << " ";
					n = n * 10 + (str[i] - '0');
					i++;
				}
				//cout<<n << "\n";
				n = n * (-1);
				//cout << "st = " << n << "\n";
				vars.push(n);
			}
			else if (i < 3)
			{
				//opers.push('-');

				//if (str[i - 3] == '+' || str[i - 3] == '-' || str[i - 3] == '*' || str[i - 3] == '/')
				//{
				//	int n = 0;
				//	i += 2;
				//	while (i < str.length() &&
				//		isdigit(str[i]))
				//	{
				//		//cout << str[i] << " ";
				//		n = n * 10 + (str[i] - '0');
				//		i++;
				//	}
				//	//cout<<n << "\n";
				//	n = n * (-1);
				//	cout << "st = " << n << "\n";
				//	vars.push(n);
				//}
				//else
				//{
					//------------------------------
					while (!opers.empty() && precedence(opers.top()) >= precedence(str[i]))
					{
						int var1 = vars.top();
						vars.pop();

						int var2 = vars.top();
						vars.pop();

						char oper = opers.top();
						opers.pop();

						vars.push(operation(var2, var1, oper));
					}
					opers.push(str[i]);
					//------------------------------
				/*}*/
			}
			else
			{
				//opers.push(str[i - 3]);
				if (str[i - 3] == '+' || str[i - 3] == '-' || str[i - 3] == '*' || str[i - 3] == '/' || str[i - 3] == '(')
				{
					if (str[i + 2] == '+' || str[i + 2] == '-' || str[i + 2] == '*' || str[i + 2] == '/')
					{
						cout << "Invalid Expression\n";
						return -1;
					}
					else
					{
						//cout << "Hii\n";
						int n = 0;
						i += 2;
						while (i < str.length() &&
							isdigit(str[i]))
						{
							//cout << str[i] << " ";
							n = n * 10 + (str[i] - '0');
							i++;
						}
						//cout<<n << "\n";
						n = n * (-1);
						//cout << n <<"\n";
						//cout << "St = " << n << "\n";
						vars.push(n);
					}
				}
				else
				{
					while (!opers.empty() && precedence(opers.top()) >= precedence(str[i]))
					{
						int var1 = vars.top();
						vars.pop();

						int var2 = vars.top();
						vars.pop();

						char oper = opers.top();
						opers.pop();

						vars.push(operation(var2, var1, oper));
					}
					opers.push(str[i]);
				}

			}

		}
		else if (isdigit(str[i]))
		{
			int n = 0;
			while (i < str.length() &&
				isdigit(str[i]))
			{
				n = n * 10 + (str[i] - '0');
				i++;
			}
			//cout<<n << "\n";
			vars.push(n);
		}
		//push to opers stack if we encounter open brace
		else if(str[i]=='(')
		{
			opers.push(str[i]);
		}


		//closing brace
		else if (str[i] == ')')
		{
			while (opers.top() != '(' && !opers.empty())
			{
				int var1 = vars.top();
				vars.pop();

				int var2 = vars.top();
				vars.pop();

				char oper = opers.top();
				opers.pop();

				vars.push(operation(var2, var1, oper));
			}
			opers.pop(); //to Pop open brace;
		}

		else
		{
			while (!opers.empty() && precedence(opers.top()) >= precedence(str[i]))
			{
				int var1 = vars.top();
				vars.pop();

				int var2 = vars.top();
				vars.pop();

				char oper = opers.top();
				opers.pop();

				vars.push(operation(var2, var1, oper));
			}
			opers.push(str[i]);
		}
	}

	//perform operation for remaining elements in stack
	while (!opers.empty())
	{
		int var1 = vars.top();
		vars.pop();

		int var2 = vars.top();
		vars.pop();

		char oper = opers.top();
		opers.pop();

		vars.push(operation(var2, var1, oper));
	}

	return vars.top();
}

int main()
{
	string inpExpression;
	cout << "Enter an Expression\n";
	getline(cin, inpExpression);
	string exp;
	if (1 == isBalanced(inpExpression))
	{
		//----------------------------------------------------------
		// 2(2+3)

		for (int i = 0; i < inpExpression.length(); i++)
		{
			if (inpExpression[i] == '(')
			{
				if(i-1 >=0 )
					if (inpExpression[i - 1] != '+' && inpExpression[i - 1] != '-' && inpExpression[i - 1] != '*' && inpExpression[i - 1] != '/' && inpExpression[i - 1] != '(')
					{
						cout << "Invalid Expression-4\n";
						return 0;
					}
				//-2*(*6)
				if (i + 1 < inpExpression.length())
				{
					if (inpExpression[i + 1] == '+' || inpExpression[i + 1] == '*' || inpExpression[i + 1] == '/')
					{
						cout << "Invalid Expression-5\n";
						return 0;
					}
				}
			}
		}

		//----------------------------------------------------------
		int el = inpExpression.length() - 1;
		if (
			(inpExpression[0] == '/' || inpExpression[0] == '*' || inpExpression[0] == '+') ||
			(inpExpression[el] == '/' || inpExpression[el] == '*' || inpExpression[el] == '+' || inpExpression[el] == '-')
			)
		{
			if (inpExpression[0] != '-')
			{
				cout << "Invalid Expression-1 !!\n";
				return 0;
			}
		}

		string e;
		e += inpExpression[0];
		for (int i = 1; i < el; i++)
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

		for (int i = 0; i < inpExpression.length(); i++)
		{
			if (inpExpression[i] == '+' || inpExpression[i] == '-' || inpExpression[i] == '*' || inpExpression[i] == '/' || inpExpression[i] == '(' || inpExpression[i] == ')')
			{
				exp += ' ';
				exp += inpExpression[i];
				exp += ' ';
			}
			else if (isdigit(inpExpression[i]))
			{
				exp += inpExpression[i];
			}
			else
			{
				cout << "Expression Invalid-3 \n";
				exit(0);
			}
		}

		//  2 + 3 * - 6

		//for (int i = 0; i < exp.length(); i++)
		//{

		//	if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
		//	{
		//		if (exp[i + 2] == '-')
		//		{

		//		}
		//		else
		//			exp1 += exp[i];
		//	}
		//	else if (isdigit(exp[i]))
		//	{
		//		exp1 += exp[i];
		//	}
		//	else if (exp[i] == ' ')
		//	{
		//		exp1 += exp[i];
		//	}
		//	else
		//	{
		//		cout << "Expression Invalid \n";
		//		exit(0);
		//	}
		//}

		//cout << exp << "\n";
		cout << "Value after Evaluation is: ";
		ans = ExpressionEval(exp);
		cout << ans << "\n";
	}
	else
	{
		cout << "Expression is Not Balanced\n";
	}
	system("pause");
}
