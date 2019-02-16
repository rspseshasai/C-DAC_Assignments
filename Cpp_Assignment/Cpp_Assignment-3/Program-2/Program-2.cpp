

#include "pch.h"
#include <iostream>
using namespace std;

template<class t>

class Stack
{
	t data[5];
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
		if (top == 4)
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


int main()
{
	//cout << "1-Int\n2-Float\n";
	//int ch;
	//cin >> ch;
	//switch (ch)
	//{
	//case 1:
		Stack<int >s;
		cout << "For Integer Stack\n\n";
		int flag = 0;
		while (flag!=1)
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
			}
		}

	//case 2:
		flag = 0;
		Stack<float >s1;
		cout << "For Float Stack\n\n";
		while (flag!=1)
		{
			cout << "1-push  2-pop  3-display 4-exit\n";
			int c1;
			cin >> c1;
			switch (c1)
			{
			case 1:
				s1.push();
				break;
			case 2:
				s1.pop();
				break;
			case 3:
				s1.display();
				break;
			case 4:
				flag = 1;
				exit(0);
			}
		}
	//}
	system("pause");
}

