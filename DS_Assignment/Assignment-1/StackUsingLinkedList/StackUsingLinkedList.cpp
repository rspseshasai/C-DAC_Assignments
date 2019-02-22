
#include "pch.h"
#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
}*first, *curr;

class Stack_ll
{
public:
	Stack_ll()
	{
		first = NULL;
	}
	void Push(int);
	int Pop();
	void Display();
};

void Stack_ll::Push(int ele)
{
	struct node *temp;
	temp = new node;

	temp->data = ele;
	temp->next = NULL;

	if (first == NULL)
	{
		first = temp;
		first->next = NULL;
	}
	else
	{
		temp->next = first;
		first = temp;
	}

}


int Stack_ll::Pop()
{
	curr = first;
	if (curr != NULL)
	{
		int ret = curr->data;
		first = curr->next;
		free(curr);
		return ret;
	}
	else
		cout << "Empty Stack\n";
	return -1;
}



void Stack_ll::Display()
{
	if (first == NULL)
		cout << "Empty Stack\n";
	else
	{
		curr = first;
		while (curr != NULL)
		{
			cout << curr->data<<" ";
			curr = curr->next;
		}
		//cout << "NULL\n";
	}
}


int main()
{
	Stack_ll obj;
	while (1)
	{
		cout << "\n1-Push  2-Pop  3-Display  4-Exit: ";
		int ch;
		cin >> ch;
		switch(ch)
		{
		case 1:
			int ele;
			cout << "Enter Element: ";
			cin >> ele;
			obj.Push(ele);
			break;
		case 2:
			int del;
			del = obj.Pop();
			cout << "Popped Element is: " << del << "\n";	
			break;
		case 3:
			obj.Display();
			break;
		case 4:
			exit(0);
		default:
			cout << "Enter Valid Input\n";
			break;
		}
	}
	system("pause");
}
