

#include "pch.h"
#include <iostream>
#include <string>
#include <cctype>

#define SIZE 5
using namespace std;

template<class t>

class Stack
{
	t data[SIZE];
	int top;
public:
	Stack()
	{
		top = -1;
	}
	void push(t num);
	void pop();
	void display();
	t get_input();
};

template<class t>
void Stack<t>::push(t num)
{
	try
	{
		if (top == SIZE -1)
			throw top;
		else
		{
			//strcpy(data[++top], num);
'			data[++top] = num;
		}
	}
	catch (int a)
	{
		cout << "Stack OverFlow\n";
	}
}

template<class t>
void Stack<t>::pop()
{
	try
	{
		if (top == -1)
			throw top;
		else
		{
			cout << "Popped Data is: "<<data[top]<<"\n";
			top--;
		}
	}
	catch (int a)
	{
		cout << "Stack UnderFlow\n";
	}
}

template<class t>
void Stack<t>::display()
{
	try
	{
		if (top == -1)
			throw top;
		else
		{
			for (int i = top; i >= 0; i--)
				cout << data[i] << " ";
			cout << "\n";
		}
	}
	catch (int a)
	{
		cout << "Stack Empty\n";
	}
}

//----------------------------------To Validate Integer Input
bool input_valid(string s)
{
	int i, length_s;
	bool is_valid = true;

	length_s = s.length();

	if (length_s == 0)
		is_valid = false;
	else
	{
		if (length_s == 1)
		{
			if (!isdigit(s[0]))
				is_valid = false;
		}
		else
		{
			if (s[0] == '+' || s[0] == '-' || isdigit(s[0]) != 0)
			{
				for (i = 1; i < length_s; i++)
				{
					if (!isdigit(s[i]))
					{
						if(s[i]!='.')
							is_valid = false;
					}
				}
			}
			else
				is_valid = false;
		}
	}
	return is_valid;
}

template<class t>
t Stack<t> :: get_input()
{
	int int_number, check_float=0;
	float float_number;
	string number;
	bool is_valid=true;

	do {
		getline(cin, number);
		cout << "\n";

		is_valid = input_valid(number);

		if (is_valid == false)
			cout << "Invalid Input...Enter again\n" << endl;
	} while (is_valid == false);

	for (int i = 0; i < number.length(); i++)
	{
		if (number[i] == '.')
			check_float = 1;
	}
	if (check_float == 1)
	{
		float_number = stof(number);
		return float_number;
	}
	int_number = stoi(number);

	return int_number;
}

//-------------------------------------------------------------------------


int main()
{
	while (1)
	{
		cout << "1-Integer Stack   2-Float Stack  3-String Stack   4-Exit\n";
		Stack<int >Obj_Int;
		Stack<float >Obj_Float;
		Stack<string>Obj_Char;
		string inp_string;
		int dataType, flag = 0;
		dataType = Obj_Int.get_input();
		int operation;

		switch (dataType)
		{
		case 1:
			while (flag != 1)
			{

				cout << "1-Push  2-Pop  3-Display 4-Exit\n";
				operation = Obj_Int.get_input();
				switch (operation)
				{
				case 1:
					cout << "Enter Data: " << endl;
					int num;
					num = Obj_Int.get_input();
					Obj_Int.push(num);
					break;
				case 2:
					Obj_Int.pop();
					break;
				case 3:
					Obj_Int.display();
					break;
				case 4:
					flag = 1;
					break;
				default:
					cout << "Enter Valid Input between (1-4)\n\n";
				}
			}
			break;
		case 2:
			while (flag != 1)
			{
				cout << "1-Push  2-Pop  3-Display 4-Exit\n";
				operation = Obj_Int.get_input();
				switch (operation)
				{
				case 1:
					cout << "Enter Data: " << endl;
					float num;
					num = Obj_Float.get_input();
					Obj_Float.push(num);
					break;
				case 2:
					Obj_Float.pop();
					break;
				case 3:
					Obj_Float.display();
					break;
				case 4:
					flag = 1;
					break;
				default:
					cout << "Enter Valid Input between (1-4)\n\n";
				}
			}
			break;
		case 3:
			while (flag != 1)
			{
				cout << "1-Push  2-Pop  3-Display 4-Exit\n";
				operation = Obj_Int.get_input();
				switch (operation)
				{
				case 1:
					cout << "Enter Data: " << "\n";
					//scanf("%[^\n]s", inp_string);
					cin >> inp_string;
					//getline(cin, inp_string);
					cin.ignore();
					//cin.clear();
					//printf("%s\n", inp_string);
					//num = Obj_Int.get_input();
					Obj_Char.push(inp_string);
					break;
				case 2:
					Obj_Char.pop();
					break;
				case 3:
					Obj_Char.display();
					break;
				case 4:
					flag = 1;
					break;
				default:
					cout << "Enter Valid Input between (1-4)\n\n";
				}
			}
			break;
		case 4:
			exit(0);
		default:
			cout << "Enter Valid input between (1-3)\n\n";
			break;
		}
	}
	system("pause");
}