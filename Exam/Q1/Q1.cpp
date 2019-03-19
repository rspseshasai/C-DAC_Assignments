
#include "pch.h"
#include <iostream>
using namespace std;

class myString
{
	char * name;
	int length;
public:
	myString()
	{
		cout << "Default Constructor\n";
		name = NULL;
		length = 0;
	}

	myString(char * inpName, int inpLength)
	{
		name = new char[inpLength + 1];
		strcpy(name, inpName);
	}

	myString(myString &ob)
	{
		length = ob.length;
		name = new char[length + 1];
		strcpy(name, ob.name);
		//name = ob.name;
	}

	friend istream& operator>>(istream &cin, myString &ob);
	friend ostream& operator<<(ostream &cout, myString ob);
	myString operator=(myString ob);
	void operator+(myString &ob);
	friend void ObjectsSort(myString arr[], int n);

	/*~myString()
	{
		cout << "Destructor\n";
		free(name);
	}*/
};

istream& operator>>(istream &cin, myString &ob)
{
	cout << "\tEnter Length : ";
	cin >> ob.length;
	ob.name = new char[ob.length + 1];

	char tempName[100];
	cout << "\tEnter Name : ";
	//scanf("%[^\n]s", tempName);
	cin >> tempName;

	strcpy(ob.name, tempName);
	return cin;
}

ostream& operator<<(ostream &cout, myString ob)
{
	cout << "\tName is " << ob.name;
	return cout;
}

myString myString :: operator=(myString ob)
{
	name = new char[ob.length +5];
	strcpy(name, ob.name);
	//name = ob.name;
	return *this;
}

void swap(myString &ob1, myString &ob2)
{
	myString tempObj;
	tempObj = ob1;
	ob1 = ob2;
	ob2 = tempObj;
}

void ObjectsSort(myString arr[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n-i-1; j++)
		{
			if (strcmp(arr[j].name, arr[j + 1].name) > 0)
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << arr[i]<<"\n";
	}
}
void myString ::operator+(myString &ob)
{
	myString newString;
	newString.length = ob.length + length;
	newString.name = new char[newString.length + 1];
	strcat(name, ob.name);
	strcpy(newString.name, name);
	//cout << newString;
	cout << "\nOverloading + (Concatenate) Operator => Obj3 + Obj2 = " << newString << "\n";
}

int main()
{
	myString obj1, obj2, obj4;

	cout << "\nEnter Obj-1 Values\n";
	cin >> obj1;
	cout << "\nEnter Obj-2 Values\n";
	cin >> obj2;

	cout << "\nEnter Obj-4 Values\n";
	cin >> obj4;

	cout << "\nDetails of Object-1 : \n" << obj1<<"\n";
	cout << "\nDetails of Object-2 :\n" << obj2<<"\n";

	myString obj3(obj1);

	cout << "\nAfter copying Obj-1 values, Obj-3 is\n" << obj3 << "\n\n";

	obj3 + obj2;
	   
	myString arrOfObjects[3] = {obj1, obj2, obj4};

	int n = 3;
	cout << "\nBefore Sort\n";
	for (int i = 0; i < n; i++)
	{
		cout << arrOfObjects[i] << "\n";
	}
	cout << "\nAfter Sort\n";

	ObjectsSort(arrOfObjects, n);

	cout << "\n";
	system("pause");
}

