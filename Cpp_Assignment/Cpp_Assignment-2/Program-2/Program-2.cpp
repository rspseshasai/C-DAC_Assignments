
#include "stdafx.h"
#include<string>
#include<iostream>
using namespace std;
class Student
{
	int roll, m1, m2, m3;
	string name;
	char grade;
public:
	friend ostream & operator<< (ostream &cout, Student ob);
	friend istream & operator>> (istream &cin, Student &ob);
	friend void gen_results(Student[], int n);
};

void gen_results(Student a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\nTotal Marks and Grade for Student " << i + 1 << " is \n";
		int avg = (a[i].m1 + a[i].m2 + a[i].m3) / 3;
		if (avg > 40)
			a[i].grade = 'P';
		else
			a[i].grade = 'F';
		cout << avg << " " << a[i].grade << "\n";
	}
}
ostream & operator<< (ostream &cout, Student ob)
{
	cout << "Roll Num: ";
	cout<< ob.roll<<"\n";
	cout << "Name: ";
	cout<<ob.name<<"\n";
	cout << "Marks of three Subjects: ";
	cout<<ob.m1 <<" "<<ob.m2 <<" "<< ob.m3<<"\n";
	return cout;
}

istream & operator>> (istream &cin, Student &ob)
{
	cout << "\nEnter Roll Num: ";
	cin >> ob.roll;
	cout << "Enter Name: ";
	cin >> ob.name;
	cout << "Enter Marks of three Subjects: ";
	cin >> ob.m1 >> ob.m2 >> ob.m3;
	return cin;
}

int main()
{
	int n;
	cout << "Enter Num. of Students: ";
	cin >> n;
	Student a[10];
	for (int i = 0; i < n; i++)
	{
		cout << "\nEnter Details of Student " << i + 1 << "\n\n";
		cin >> a[i];
	}
	
	for (int i = 0; i < n; i++)
	{
		cout << "\nDetails of Student " << i + 1 << "are \n\n";
		cout << a[i];
	}

	gen_results(a, n);
	system("pause");
    return 0;

}

