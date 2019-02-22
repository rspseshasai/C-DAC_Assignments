
#include "pch.h"
#include <iostream>
using namespace std;

struct node *root=NULL;

struct node
{
	int data;
	struct node *left, *right;
}*dummy;


class Bst
{
public:
	Bst()
	{
		dummy = NULL;
	}
	struct node * Insert(struct node *, int );

};


struct node * Bst::Insert(struct node * r, int e)
{
	struct node *temp;
	temp = new node;
	temp->data = e;

	if (r == NULL)
	{
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
	else
	{
		if (r->data > e)
			r->left = Insert(r->left, e);
		else if (r->data < e)
			r->right = Insert(r->right, e);
	}
}

int main()
{
	Bst ob;
	while (1)
	{
		cout << "1-Insert  2-Delete  3-Display  4-FindExtremes  5-FindHeight  6-No.ofLeafNodes  7-No.ofNonLeafNodes : ";
		int ch;
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "Enter Element to Insert: ";
			int ele;
			cin >> ele;
			struct node * temp = ob.Insert(root, ele);
		default:
			cout << "Enter Valid Chioce (1 to 7)\n";
		}
	}
	system("pause");
}

