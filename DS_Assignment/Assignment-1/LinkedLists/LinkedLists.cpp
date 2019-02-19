
#include "pch.h"
#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
}*first, *temp;

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

int main()
{
	ll obj;
	cout << "\n1-Insert  2-Delete  3-Display  4-Reverse : ";
	int ch;
	cin >> ch;
	while (1)
	{
		switch (ch)
		{
		case 1:
			cout << "\n1-AtBeginning  2-AfterAnElement  3-BeforeAnElement  4-AtEnd  5-Exit\n";
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
				int e;
				cin >> e;
				obj.InsertBefore(ele, e);
				break;
			case 4:
				obj.InsertEnd(ele);
				break;
			}
			break;
		case 2:
			cout << "\n1-DeleteAtBegin  2-DeleteSpecificElement  3-DeleteAtEnd : ";
			int c, e;
			cin >> c;
			switch (c)
			{
			case 1:
				int del = obj.DeleteBegin();
				cout << "Deleted Element is: " << del << "\n";
				break;
			case 2:
				int ele;
				cout << "Enter Element to delete: ";
				cin >> ele;
				int del = obj.DeleteSpecific(ele);
				cout << "Deleted Element is: " << del << "\n";
				break;
			case 3:
				int del = obj.DeleteEnd();
				cout << "Deleted Element is: " << del << "\n";
				break;
			}
			break;
		case 3:
			cout << "\n1-DisplayForward  2-DisplayBackward : ";
			int c;
			cin >> c;
			switch (c)
			{
			case 1:
				obj.DisplayForward();
				break;
			case 2:
				obj.DisplayBack();
				break;
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
