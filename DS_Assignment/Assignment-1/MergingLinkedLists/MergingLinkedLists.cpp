
#include "pch.h"
#include <iostream>
using namespace std;
struct node * temp = NULL;
struct node
{
	int data;
	struct node *next;
}*first1=NULL, *first2=NULL, *curr;

struct node * InsertEnd(struct node *first, int ele)
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
	return first;
}

void DisplayForward(struct node * first)
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

struct node * Merge(struct node * first1, struct node * first2)
{

	while (first1 != NULL && first2 != NULL)
	{
		if (first1->data > first2->data)
		{
			temp = InsertEnd(temp, first2->data);
			first2 = first2->next;
		}
		else if (first1->data < first2->data)
		{
			temp = InsertEnd(temp, first1->data);
			first1 = first1->next;
		}
		else
		{
			temp = InsertEnd(temp, first1->data);
			first1 = first1->next;
			temp = InsertEnd(temp, first2->data);
			first2 = first2->next;
			
		}
	}

	if (first1 != NULL)
	{
		while (first1 != NULL)
		{
			InsertEnd(temp, first1->data);
			first1 = first1->next;
		}
	}

	if (first2 != NULL)
	{
		while (first2 != NULL)
		{
			InsertEnd(temp, first2->data);
			first2 = first2->next;
		}
	}
	return temp;
}

int main()
{
	cout << "Enter Length of First and Second List : ";
	int n1, n2;
	cin >> n1 >> n2;
	cout << "Enter Data For 1st List (in sorted order)\n";
	for (int i = 0; i < n1; i++)
	{
		int ele;
		cin >> ele;
		first1=InsertEnd(first1, ele);
	}

	cout << "Enter Data For 2nd List (in sorted order)\n";
	for (int i = 0; i < n2; i++)
	{
		int ele;
		cin >> ele;
		first2 = InsertEnd(first2, ele);
	}

	DisplayForward(first1);
	DisplayForward(first2);

	struct node * temp=NULL;
	temp=Merge(first1, first2);

	DisplayForward(temp);

	system("pause");
}

