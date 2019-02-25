
#include "pch.h"
#include <iostream>
using namespace std;


struct node
{
	int data;
	struct node *left, *right;
}*dummy;
class Bst
{
public:
	int nodes;
	Bst()
	{
		nodes = 0;
		dummy = NULL;
	}
	struct node * Insert(struct node *, int );
	struct node * Delete(struct node *, int);
	void Inorder(struct node *);
	int FindMax(struct node *);
	int FindMin(struct node *);
	int Height(struct node *);
	int leafNodes(struct node *);
	int NonleafNodes(struct node *);
	struct node * smallest(struct node *);

};

struct node *create(int ele)
{
	struct node *temp = new node;
	temp->data = ele;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct node * Bst::Insert(struct node * r, int e)
{
	

	if (r == NULL)
	{
		return create(e);
	}
	if (r->data > e)
		r->left = Insert(r->left, e);
	else if (r->data < e)
		r->right = Insert(r->right, e);
	return r;
}

struct node * Bst::smallest(struct node * r)
{
	struct node* temp = r;
	while (temp->left != NULL)
		temp = temp->left;

	return temp;
}

struct node * Bst::Delete(struct node * r, int ele) 
{
	if (r == NULL)
	{
		//cout << "Tree is Empty\n";
		return r;
	}
	if (ele < r->data)
		r->left = Delete(r->left, ele);
	else if (ele > r->data)
		r->right = Delete(r->right, ele);

	else
	{
		//one child or no child
		if (r->left == NULL)
		{
			struct node * temp = r->right;
			free(r);
			nodes--;
			return temp;
		}
		else if (r->right == NULL)
		{
			struct node * temp = r->left;
			free(r);
			nodes--;
			return temp;
		}

		//2 children
		struct node * temp = smallest(r->right);
		r->data = temp->data;
		r->right = Delete(r->right, temp->data);
		nodes--;
	}

	return r;
}

void Bst::Inorder(struct node * r)
{
	if (r != NULL)
	{
		Inorder(r->left);
		cout << r->data << " - ";
		Inorder(r->right);
	}
}

int Bst::FindMax(struct node *r)
{
	if (r == NULL)
		return -1;
	while (r->right != NULL)
		r = r->right;
	return r->data;
}

int Bst::FindMin(struct node *r)
{
	if (r == NULL)
		return -1;
	while (r->left != NULL)
		r = r->left;
	return r->data;
}

int Bst::Height(struct node * r)
{
	if (r == NULL)
		return 0;
	int lh, rh;
	lh = Height(r->left);
	rh = Height(r->right);

	if (lh < rh)
		return (rh + 1);
	else return (lh + 1);
}

int Bst::leafNodes(struct node * r)
{
	if (r == NULL)
		return 0;
	if (r->left == NULL && r->right == NULL)
	{
		return 1;
	}
	else
		return (leafNodes(r->left) + leafNodes(r->right));
}

int Bst::NonleafNodes(struct node * r)
{
	return (nodes - (leafNodes(r)));
}

int main()
{
	Bst ob;
	struct node *root = NULL;
	//struct node * temp=NULL;
	while (1)
	{
		cout << "\n1-Insert  2-Delete  3-Display  4-FindExtremes  5-FindHeight  6-No.ofLeafNodes  7-No.ofNonLeafNodes  8-Exit: ";
		int ch;
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "Enter Element to Insert: ";
			int ele;
			cin >> ele;
			root = ob.Insert(root, ele);
			ob.nodes++;
			break;
		case 2:
			cout << "Enter Element to Delete: ";
			int ele1;
			cin >> ele1;
			root = ob.Delete(root, ele1);
			break;
		case 3:
			ob.Inorder(root);
			cout << "NULL\n";
			break;
		case 4:
			cout << "1-Max  2-Min: ";
			int c;
			cin >> c;
			if(c==1)
				cout<<"Max in Tree is: "<<ob.FindMax(root)<<"\n";
			else if(c==2)
				cout << "Min in Tree is: " << ob.FindMin(root) << "\n";
			break;
		case 5:
			cout << "Height of Tree is: " << ob.Height(root) << "\n";
			break;
		case 6:
			cout << "No. of Leaf Nodes are: "<<ob.leafNodes(root) << "\n";
			break;
		case 7:
			cout << "No. of Non Leaf Nodes: " << ob.NonleafNodes(root) << "\n";
			break;
		case 8:
			exit(0);
		default:
			cout << "Enter Valid Chioce (1 to 8)\n";
			break;
		}
	}
	system("pause");
}

