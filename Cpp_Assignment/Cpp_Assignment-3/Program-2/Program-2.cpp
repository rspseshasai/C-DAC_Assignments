

#include "pch.h"
#include <iostream>
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
	void push();
	void pop();
	void display();
};

template<class t>
void Stack<t>::push()
{
	try
	{
		if (top == SIZE -1)
			throw top;
		else
		{
			cout << "Enter Data: " << endl;
			t d;
			cin >> d;
			data[++top] = d;
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

int TestInput(int inp)
{
	while (1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input...Enter Again !!" << endl;
			cin >> inp;
		}
		if (!cin.fail())
			break;
	}
	return inp;
}

int main()
{
	while (1)
	{
		cout << "1-Integer Stack   2-Float Stack   3-Exit\n";

		int dataType, flag = 0;
		cin >> dataType;
		dataType = TestInput(dataType);

		Stack<int >Obj_Int;
		Stack<float >Obj_Float;
		int operation;

		switch (dataType)
		{
		case 1:
			while (flag != 1)
			{

				cout << "1-Push  2-Pop  3-Display 4-Exit\n";
				cin >> operation;
				operation = TestInput(operation);
				switch (operation)
				{
				case 1:
					Obj_Int.push();
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
				cin >> operation;
				operation = TestInput(operation);
				switch (operation)
				{
				case 1:
					Obj_Float.push();
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
			exit(0);
		default:
			cout << "Enter Valid input between (1-3)\n\n";
			break;
		}
	}
	system("pause");
}

