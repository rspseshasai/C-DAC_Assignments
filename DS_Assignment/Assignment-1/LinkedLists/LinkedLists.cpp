
#include "pch.h"
#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
}*first, *curr;

class ll
{
public:
	ll()
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

void ll::InsertBegin(int ele)
{
	struct node *temp;
	temp = new node;

	temp->data=ele;
	temp->next = NULL;

	if (first == NULL)
	{
		first=temp;
		first->next = NULL;
	}
	else
	{
		temp->next = first;
		first = temp;
	}
	
}

void ll::InsertAfter(int ele, int e)
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

		temp->next = curr->next;
		curr->next = temp;
	}
	else
		cout << "Element Not Found\n";
}

void ll::InsertBefore(int ele, int e)
{
	curr = first;
	int flag = 0;
	while (curr!= NULL)
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

		temp->next = curr->next;
		curr->next = temp;
	}
	else
		cout << "Element Not Found\n";
}

void ll::InsertEnd(int ele)
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
		curr = first;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = temp;
		curr = temp;
	}
}

int ll::DeleteBegin()
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
		cout << "Empty List\n";
	return -1;
}


int ll::DeleteSpecific(int ele)
{
	curr = first;
	if (curr == NULL)
		cout << "Empty List\n";
	else if (curr->data == ele)
		cout << "Deleted Element is : " << DeleteBegin();
	else
	{
		int flag = 0;
		struct node * curr1 = NULL;
		while (curr->next != NULL)
		{
			if (curr->data == ele)
			{
				flag = 1;
				break;
			}
			curr1 = curr;
			curr = curr->next;
		}
		//cout << "curr data : " << curr->data << "\n";
		if (curr->data == ele)
			return DeleteEnd();
		int ret;
		if (flag == 1)
		{
			ret = curr->data;
			if (curr->next != NULL)
			{
				curr1->next = curr->next;
				curr->next = NULL;
				free(curr);
			}
			else if (curr == first)
			{
				curr = NULL;
				first = NULL;
				free(curr);
			}
			
		}
		else
		{
			ret = -1;
			cout << "Element Not Found\n";
		}
		return ret;
	}
	return -1;
}

int ll::DeleteEnd()
{
	if (first == NULL)
		return NULL;
	if (first->next == NULL)
	{
		delete first;
		return NULL;
	}
	struct node * temp = first;
	while (temp->next->next != NULL)
		temp = temp->next;
	int ret = temp->next->data;
	delete (temp->next);
	temp->next = NULL;

	return ret;
	return -1;
}

void ll::ReverseLL()
{
	if (first == NULL) 
		return;

	struct node *prev = NULL, *curr = NULL, *next = NULL;
	curr = first;
	while (curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	first = prev;

}

void ll::DisplayForward()
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
void ll::DisplayBack()
{
	if (first != NULL)
		print(first);
	cout << "NULL\n";
}

int main()
{
	ll obj;
	struct node * current = NULL;
	cout << "\n1-Insert  2-Delete  3-Display  4-Reverse  5-Exit: ";
	int ch;
	while ((cin >> ch))
	{
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
			default:
				cout << "Enter Valid Input\n";
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
			default:
				cout << "Enter Valid Input\n";
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
			current = first;
			while (current != NULL) {
				struct node * next = current->next;
				free(current);
				current = next;
			}
			exit(0);
		default:
			cout << "Enter Valid Input\n";
			break;
		}
		cout << "\n1-Insert  2-Delete  3-Display  4-Reverse  5-Exit: ";
	}
	system("pause");
}