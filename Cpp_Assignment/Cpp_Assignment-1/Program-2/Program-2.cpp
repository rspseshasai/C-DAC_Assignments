
#include "pch.h"
#include <iostream>
#include<string>
using namespace std;

class Student
{
public:
	string nam, sec;
	int mr1, mr2, mr3;
};
class CollegeCourse 
{
	float avg;
	char grade;
public :
	Student s;
	void setData(string s1, char grd, int m1, int m2, int m3)
	{
		s.nam = s1;
		s.sec = grd;
		s.mr1 = m1;
		s.mr2 = m2;
		s.mr3 = m3;
	}
	void calculateAverage()
	{
		avg = (float)((s.mr1 + s.mr2 + s.mr3) / 3);
	}
	void computeGrade()
	{
		if (avg > 60)
			grade = 'A';
		else if (avg > 50 && avg < 60)
			grade = 'B';
		else if (avg > 40)
			grade = 'C';
		else
			grade = 'F';
	}
	void printDetails()
	{
		cout << "Student name : " << s.nam << "\n";
		cout << "Grade (Section ) : " << s.sec << "\n";
		cout << "Average : " << avg << "\n";
		cout << "Grade : " << grade << "\n";
	}
};

int main()
{
	string name;
	char grade;
	int m1, m2, m3;
	cout << "Enter Name\n";
	getline(cin, name);
	cout << "Enter grade(Section)\n";
	cin >> grade;
	cout<<"Enter 3 subjects Marks\n";
	cin>> m1 >> m2 >> m3;
	CollegeCourse c;
	c.setData(name, grade, m1, m2, m3);
	c.calculateAverage();
	c.computeGrade();
	c.printDetails();
	system("pause");
}
