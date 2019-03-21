
#include "pch.h"
#include <iostream>
#include<string>

using namespace std;

class String
{
	char *myString;
	int length;
public:
	String() //Default Constructor
	{
		myString = NULL;
		length = 0;
	}
	String(char *str) //Parameterized Constructor
	{
		length = strlen(str);
		str = new char[length+1];
		strcpy(myString, str);
	}
	String(const String &obj) //Copy Constructor
	{
		myString = obj.myString;
		length = obj.length;
	}
	String operator=(String obj);
	char operator[](int position);
	String operator+(String obj);
	friend istream& operator>>(istream &cin, String &obj);
	friend ostream& operator<<(ostream &cout, String obj);
};

istream& operator>>(istream &cin, String &obj)
{
	char tempStr[50];
	cin >> tempStr;
	int len = strlen(tempStr) + 1;
	obj.myString = new char[len];
	strcpy(obj.myString, tempStr);
	return cin;
}

ostream& operator<<(ostream &cout, String obj)
{
	cout << obj.myString << "\n";
	return cout;
}

char String::operator[](int position)
{
	return this->myString[position];
}

String String::operator+(String obj)
{
	String concatenatedStr;
	concatenatedStr.length = obj.length + length;
	concatenatedStr.myString =new char[concatenatedStr.length + 1];
	strcat(myString, obj.myString);
	strcpy(concatenatedStr.myString, myString);
	return concatenatedStr;
}

String String::operator=(String obj)
{
	int len = strlen(obj.myString) + 1;
	myString = new char[len];
	strcpy(myString, obj.myString);
	return *this;
}



int main()
{
	String obj1, obj2;
	cout << "Enter First String\n";
	cin >> obj1;
	cout << "Enter Second String\n";
	cin >> obj2;

	cout <<"Obj-1 is : "<< obj1;
	cout <<"Obj-2 is : "<< obj2;

	String obj3(obj2);

	String obj4 = obj1;

	cout <<"Obj-3 (copied from Obj-2) is : "<< obj3;
	cout <<"Obj-4 (copied from Obj-1) is : "<< obj4;

	cout <<"Overloading [] Operator (Obj2[3]) is : "<< obj2[3] << "\n";
	String obj5 = obj1 + obj2;

	cout << "Overloading + Operator (Obj-1 + Obj-2) is : " << obj5;

	system("pause");
}