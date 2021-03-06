#include "pch.h"
#include <iostream>
#define MAX 50
using namespace std;

class Queue
{
	int data[MAX], n;
	int rear, front;
public:
	Queue()
	{
		cout << "Enter Size: ";
		cin >> n;

		for (int i = 0; i < n; i++)
			data[i] = 0;
		rear = -1;
		front = -1;
	}
	void Enque();
	void Deque();
	void display();
};

void Queue::Enque()
{
	try
	{
		if (front == n-1)
			throw front;
		else
		{
			cout << "Enter Data: " << endl;
			int d;
			cin >> d;
			if (front == -1)
				rear=0;
			data[++front] = d;
		}
	}
	catch (int a)
	{
		cout << "Queue OverFlow\n";
	}
}

void Queue::Deque()
{
	try
	{
		if ((rear == -1 && front == -1) || (front+1 == rear))
			throw rear;
		else
		{
			cout << "Dequed Data is: " << data[rear] << "\n";
			rear++;
		}
	}
	catch (int a)
	{
		cout << "Queue UnderFlow\n";
	}
}


void Queue::display()
{
	try
	{
		if ((rear == -1 && front==-1) || (front + 1 == rear))
			throw rear;
		else
		{
			for (int i = front; i >=rear; i--)
				cout << data[i] << " ";
			cout << "\n";
		}
	}
	catch (int a)
	{
		cout << "Queue Empty\n";
	}
}


int main()
{

	Queue q;
	int flag = 0;
	while (flag != 1)
	{

		cout << "1-Enque  2-Deque  3-display 4-exit\n";
		int c;
		cin >> c;
		switch (c)
		{
		case 1:
			q.Enque();
			break;
		case 2:
			q.Deque();
			break;
		case 3:
			q.display();
			break;
		case 4:
			flag = 1;
			break;
		default:
			cout << "Enter Valid Input\n";
			break;
		}
	}
	system("pause");
}

