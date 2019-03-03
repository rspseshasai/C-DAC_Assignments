
//Incomplete Program


#include "pch.h"
#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
}*first, *curr;


class SelfList
{
public:
	SelfList()
	{
		first = NULL;
	}
	void InsertBegin(int);

	void Search(int);

	int DeleteBegin();
	int DeleteSpecific(int);
	int DeleteEnd();

	void DisplayForward();
};

void SelfList::DisplayForward()
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

void SelfList::InsertBegin(int ele)
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

int SelfList::DeleteBegin()
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


int SelfList::DeleteSpecific(int ele)
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
		cout << "curr data : " << curr->data << "\n";
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

int SelfList::DeleteEnd()
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

void SelfList::Search(int ele)
{
	if (first == NULL)
		cout << "Element Not Found\n";
	else if (first->data == ele)
	{
		cout << "Element Found\n";
	}
	else
	{
		curr = first;
		while (curr != NULL)
		{
			if (curr->data == ele)
			{
				cout << "Element Found\n";
				DeleteSpecific(curr->data);
				InsertBegin(curr->data);
			}
				//cout << curr->data << "-->";
				curr = curr->next;
		}
	}
}

int main()
{
	SelfList obj;
	struct node * current = NULL;
	cout << "\n1-Insert  2-Search  3-Display  4-Exit: ";
	int ch;
	while ((cin >> ch))
	{
		switch (ch)
		{
		case 1:
			int ele;
			cout << "Enter Data To Insert: ";
			cin >> ele;
			obj.InsertBegin(ele);
			break;
		case 2:
			cout << "Enter Element to Search : ";
			int element;
			cin >> element;
			obj.Search(element);
			break;
		case 3:
			obj.DisplayForward();
			break;
		case 4:
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
		cout << "\n1-Insert  2-Search  3-Display  4-Exit: ";
	}
	system("pause");
}
