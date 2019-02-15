
#include "stdafx.h"
#include<string>
#include<iostream>
using namespace std;
class Employee
{
	int sal, empno;
	string name;
public:
	Employee()
	{
	}
	Employee(Employee a[], int n)
	{
		for (int i = 0; i < n; i++)
			cin >> a[i];
	}
	friend ostream & operator<< (ostream &cout, Employee ob);
	friend istream & operator >> (istream &cin, Employee &ob);
	//friend void gen_results(Student[], int n);
	void display(Employee a[], int n)
	{
		for (int i = 0; i < n; i++)
			cout << a[i];
	}
};


ostream & operator<< (ostream &cout, Employee ob)
{
	cout << "\nEmp Num: ";
	cout << ob.empno << "\n";
	cout << "Name: ";
	cout << ob.name << "\n";
	cout << "Salary: ";
	cout << ob.sal<< "\n";
	return cout;
}

istream & operator >> (istream &cin, Employee &ob)
{
	cout << "\nEnter Emp Num: ";
	cin >> ob.empno;
	cout << "Enter Name: ";
	cin >> ob.name;
	cout << "Enter Salary: ";
	cin >> ob.sal;
	return cin;
}

int main()
{
	int n;
	cout << "Enter Num. of Employees: ";
	cin >> n;
	Employee a[5];
	Employee ob(a, n);
	//gen_results(a, n);
	ob.display(a, n);
	system("pause");
	return 0;

}

