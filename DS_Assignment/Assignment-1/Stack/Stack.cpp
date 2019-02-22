#include "pch.h"
#include <iostream>
using namespace std;

class Stack
{
	int data[50], n;
	int top;
public:
	Stack()
	{
		cout << "Enter Size: ";
		cin >> n;
		top = -1;
	}
	void push();
	void pop();
	void display();
};

void Stack::push()
{
	try
	{
		if (top == n-1)
			throw top;
		else
		{
			cout << "Enter Data: " << endl;
			int d;
			cin >> d;
			data[++top] = d;
		}
	}
	catch (int a)
	{
		cout << "Stack OverFlow\n";
	}
}

void Stack::pop()
{
	try
	{
		if (top == -1)
			throw top;
		else
		{
			cout << "Popped Data is: " << data[top] << "\n";
			top--;
		}
	}
	catch (int a)
	{
		cout << "Stack UnderFlow\n";
	}
}


void Stack::display()
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


int main()
{

	Stack s;
	int flag = 0;
	while (flag != 1)
	{

		cout << "1-push  2-pop  3-display 4-exit\n";
		int c;
		cin >> c;
		switch (c)
		{
		case 1:
			s.push();
			break;
		case 2:
			s.pop();
			break;
		case 3:
			s.display();
			break;
		case 4:
			flag = 1;
			break;
		default:
			cout << "Enter Valid Input\n";
			break;
		}
	}
	system("pause");
}

