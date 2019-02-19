
#include "pch.h"
#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
	struct node *prev;
}*first, *curr;

class dll
{
public:
	dll()
	{
		first = NULL;
	}
	void InsertBegin(int);
	void InsertAfter(int, int);
	void InsertBefore(int, int);
	void InsertEnd(int);

	int DeleteBegin();
	int DeleteSpecific(int);
	int DeleteEnd();

	void DisplayForward();
	void DisplayBack();

	void ReverseLL();
};

void dll::InsertBegin(int ele)
{
	struct node *temp;
	temp = new node;

	temp->data = ele;
	temp->next = NULL;
	temp->prev = NULL;

	if (first == NULL)
	{
		first = temp;
		first->next = NULL;
		first->prev = NULL;
	}
	else
	{
		temp->next = first;
		first = temp;
		temp->prev = NULL;
	}

}

void dll::InsertAfter(int ele, int e)
{
	curr = first;
	int flag = 0;
	while (curr != NULL)
	{
		if (curr->data == e)
		{
			flag = 1;
			break;
		}
		curr = curr->next;
	}
	if (flag == 1)
	{
		struct node *temp;
		temp = new node;
		temp->data = ele;
		temp->next = NULL;
		temp->prev = NULL;

		temp->next = curr->next;
		temp->prev = curr;
		curr->next->prev = temp;
		curr->next = temp;
	}
	else
		cout << "Element Not Found\n";
}

void dll::InsertBefore(int ele, int e)		//write code if only one element
{
	curr = first;
	int flag = 0;
	while (curr != NULL)
	{
		if (curr->next->data == e)
		{
			flag = 1;
			break;
		}
		curr = curr->next;
	}
	if (flag == 1)
	{
		struct node *temp;
		temp = new node;
		temp->data = ele;
		temp->next = NULL;
		temp->prev = NULL;

		temp->next = curr->next;
		temp->prev = curr;
		curr->next->prev = temp;
		curr->next = temp;
	}
	else
		cout << "Element Not Found\n";
}

void dll::InsertEnd(int ele)
{
	struct node *temp;
	temp = new node;
	temp->data = ele;
	temp->next = NULL;
	temp->prev = NULL;

	curr = first;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = temp;
	temp->prev = curr;
	temp->next = NULL;
	//curr = temp;
}

int dll::DeleteBegin()
{
	curr = first;
	int ret = curr->data;
	first = curr->next;
	return ret;
}

int dll::DeleteSpecific(int ele)
{
	curr = first;
	int flag = 0;
	struct node * curr1 = NULL;
	while (curr != NULL)
	{
		if (curr->data == ele)
		{
			flag = 1;
			break;
		}
		curr1 = curr;
		curr = curr->next;
	}
	int ret;
	if (flag == 1)
	{
		ret = curr->data;
		curr1->next = curr->next;
		curr->next = NULL;
	}
	else
	{
		ret = -1;
		cout << "Element Not Found\n";
	}
	return ret;
}

int dll::DeleteEnd()
{
	curr = first;
	int ret;
	while (curr->next->next != NULL)
	{
		curr = curr->next;
	}
	ret = curr->next->data;
	curr->next = NULL;
	return ret;
}

void dll::ReverseLL()
{

}

void dll::DisplayForward()
{
	if (first == NULL)
		cout << "Empty List\n";
	else
	{
		curr = first;
		while (curr != NULL)
		{
			cout << curr->data << "-->";
			curr = curr->next;
		}
		cout << "NULL\n";
	}
}

void print(struct node * curr)
{
	if (curr != NULL)
	{
		print(curr->next);
		cout << curr->data << "-->";
	}
}
void dll::DisplayBack()
{
	if (first != NULL)
		print(first);
	cout << "NULL\n";
}

int main()
{
	dll obj;
	while (1)
	{
		cout << "\n1-Insert  2-Delete  3-Display  4-Reverse  5-Exit: ";
		int ch;
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "\n1-AtBeginning  2-AfterAnElement  3-BeforeAnElement  4-AtEnd\n";
			int c, ele;
			cin >> c;
			cout << "Enter Data To Insert: ";
			cin >> ele;
			switch (c)
			{
			case 1:
				obj.InsertBegin(ele);
				break;
			case 2:
				cout << "Enter Element after which it has to be inserted: ";
				int e;
				cin >> e;
				obj.InsertAfter(ele, e);
				break;
			case 3:
				cout << "Enter Element before which it has to be inserted: ";
				int e1;
				cin >> e1;
				obj.InsertBefore(ele, e1);
				break;
			case 4:
				obj.InsertEnd(ele);
				break;
			}
			break;
		case 2:
			cout << "\n1-DeleteAtBegin  2-DeleteSpecificElement  3-DeleteAtEnd : ";
			int c1, e;
			cin >> c1;
			int del, del1, del2;
			switch (c1)
			{
			case 1:
				del = obj.DeleteBegin();
				cout << "Deleted Element is: " << del << "\n";
				break;
			case 2:
				int ele;
				cout << "Enter Element to delete: ";
				cin >> ele;
				del2 = obj.DeleteSpecific(ele);
				cout << "Deleted Element is: " << del2 << "\n";
				break;
			case 3:
				del1 = obj.DeleteEnd();
				cout << "Deleted Element is: " << del1 << "\n";
				break;
			}
			break;
		case 3:
			cout << "\n1-DisplayForward  2-DisplayBackward : ";
			int c2;
			cin >> c2;
			if (c2 == 1)
				obj.DisplayForward();
			else
			{
				obj.DisplayBack();
			}
			break;
		case 4:
			obj.ReverseLL();
			break;
		case 5:
			exit(0);
		}
	}
	system("pause");
}
