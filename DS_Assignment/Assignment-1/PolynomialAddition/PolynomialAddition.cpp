
#include "pch.h"
#include <iostream>
using namespace std;
struct node * temp = NULL;
struct node
{
	int power, coeff;
	struct node *next;
}*first1 = NULL, *first2 = NULL, *curr;

struct node * InsertEnd(struct node *first, int p, int c)
{
	struct node *temp;
	temp = new node;
	temp->power = p;
	temp->coeff = c;
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
			cout << curr->coeff <<"x^"<<curr->power<< " + ";
			curr = curr->next;
		}
		cout << "0\n";
	}
}

struct node * PolyAdd(struct node * first1, struct node * first2)
{
	while (first1 != NULL && first2 != NULL)
	{
		if (first1->power < first2->power)
		{
			temp = InsertEnd(temp, first2->power, first2->coeff);
			first2 = first2->next;
		}
		else if (first1->power > first2->power)
		{
			temp = InsertEnd(temp, first1->power, first2->coeff);
			first1 = first1->next;
		}
		else
		{
			temp = InsertEnd(temp, first1->power, first1->coeff+first2->coeff);
			first1 = first1->next;
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
	cout << "Enter Data For 1st List (in sorted order) (coeff-power)\n";
	for (int i = 0; i < n1; i++)
	{
		int ele, coef;
		cin >> coef>>ele;
		first1 = InsertEnd(first1, ele, coef);
	}

	cout << "Enter Data For 2nd List (in sorted order)(coeff-power)\n";
	for (int i = 0; i < n2; i++)
	{
		int ele, coef;
		cin >> coef>>ele;
		first2 = InsertEnd(first2, ele, coef);
	}

	cout << "Poly 1 is : ";
	DisplayForward(first1);
	cout << "Poly 2 is : ";
	DisplayForward(first2);

	cout << "After Addition : ";
	struct node * temp = NULL;
	temp = PolyAdd(first1, first2);

	DisplayForward(temp);

	system("pause");
}

