#include "pch.h"
#include <iostream>
#include<string>
using namespace std;
int nodes=0;
struct node
{
	int data;
	struct node *next;
}*first, *curr;

class LinkedList
{
public:
	LinkedList()
	{
		first = NULL;
	}

	void Insert(int, int);
	void InsertEnd(int);
	int DeleteBegin();
	int DeleteEnd();
	int Delete(int);
	void PrintForward();
	void PrintBackward();
	void ReverseList();
};

void LinkedList::Insert(int ele, int pos)
{
	if (pos == 0)
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
	else
	{
		curr = first;
	int flag = 0;
	while (curr->next!= NULL && pos-- > 0)
	{
		flag = 1;
		curr = curr->next;
	}
	cout << curr->data << "\n";
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
		cout << "Enter Valid Position\n";
	}
}

int LinkedList::DeleteBegin()
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


int LinkedList::DeleteEnd()
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

int LinkedList::Delete(int ele)
{
	curr = first;

	//---------------------------------------To check if Element is at Beginning
	if (curr == NULL)
		cout << "No Elements in List\n";
	else if (curr->data == ele)
		cout << "Deleted Element is : " << DeleteBegin();
	//--------------------------------------------------------------------------
	else
	{
		int flag = 0;
		struct node * temp = NULL;
		//-----------------------------------To check if Element is at End
		while (curr->next != NULL)
		{
			if (curr->data == ele)
			{
				flag = 1;
				break;
			}
			temp = curr;
			curr = curr->next;
		}
		if (curr->data == ele)
			return DeleteEnd();
		//-----------------------------------------------------------------

		int deletedEle;
		if (flag == 1)
		{
			deletedEle = curr->data;
			if (curr->next != NULL)
			{
				temp->next = curr->next;
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
			deletedEle = -1;
			cout << "Element Not Found\n";
		}
		return deletedEle;
	}
	return -1;
}

void LinkedList::PrintForward()
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

void LinkedList::PrintBackward()
{
	if (first != NULL)
		print(first);
	cout << "NULL\n";
}

void LinkedList::ReverseList()
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
void LinkedList::InsertEnd(int ele)
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

//--------------------------------------------To Validate Input
bool input_valid(string s)
{
	int i, length_s;
	bool is_valid = true;

	length_s = s.length();

	if (length_s == 0)
		is_valid = false;
	else
	{
		if (length_s == 1)
		{
			if (!isdigit(s[0]))
				is_valid = false;
		}
		else
		{
			if (s[0] == '+' || s[0] == '-' || isdigit(s[0]) != 0)
			{
				for (i = 1; i < length_s; i++)
				{
					if (!isdigit(s[i]))
					{
						if (s[i] != '.')
							is_valid = false;
					}
				}
			}
			else
				is_valid = false;
		}
	}
	return is_valid;
}



int get_input()
{
	int int_number, check_float = 0;
	string number;
	bool is_valid = true;

	do {
		getline(cin, number);
		cout << "\n";

		is_valid = input_valid(number);

		if (is_valid == false)
			cout << "Invalid Input...Enter again\n" << endl;
	} while (is_valid == false);

	int_number = stoi(number);

	return int_number;
}
//---------------------------------------------------------------------------------------

int main()
{
	LinkedList obj;
	while (1)
	{
		cout << "\n1 - Insert   2 - Delete   3 - Print   4 - Reverse   5 - Exit\n";
		int ch;
		ch = get_input();

		switch (ch)
		{
		case 1:
			cout << "Enter Position to Insert : ";
			int pos, ele;
			pos = get_input();
			cout << "Enter Data To Insert : ";
			ele = get_input();
			if (pos > nodes || pos<0)
			{
				cout << "Enter Valid Position\n";
				break;
			}
			else if (pos == nodes)
			{
				obj.InsertEnd(ele);
				nodes++;
				break;
			}
			obj.Insert(ele, pos);
			nodes++;
			break;
		case 2:
			cout << "Enter Element to Delete\n";
			int eleToDelete;
			eleToDelete = get_input();
			obj.Delete(eleToDelete);
			break;
		case 3:
			cout << "\n1 - Print Forward   2 - Print Backward\n";
			int ch_print;
			ch_print = get_input();
			switch (ch_print)
			{
			case 1:
				obj.PrintForward();
				break;
			case 2:
				obj.PrintBackward();
				break;
			default:
				cout << "Invalid Input ! Enter between 1-2\n";
			}
			break;
		case 4:
			obj.ReverseList();
			break;
		case 5:
			exit(0);
		default:
			cout << "Invalid Input ! Enter between 1-5\n";
		}
	}

	cout << "\n";
	system("pause");
}