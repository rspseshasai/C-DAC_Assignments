
#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	float table[2][3] = { { 1.1,1.2,1.3},{2.1,2.2,2.3} };
	cout <<"*(table)	= "<< *(table) << endl;
	cout <<"(table+1)	= "<< (table+1) << endl;
	cout <<"*(table + 1) = "<< *(table + 1) << endl;
	cout <<"(*(table + 1) + 1)	= "<< (*(table + 1) + 1) << endl;
	cout <<"(*(table)+1)	 = " << (*(table)+1) << endl;
	cout <<"*(*(table + 1) + 1)	= "<< *(*(table + 1) + 1) << endl;
	cout <<"*(*(table)+1)	= "<< *(*(table)+1) << endl;
	//cout << *(*(table + 1) << endl;
	cout <<"*(*(table)+1) + 1 = "<< *(*(table)+1) + 1 << endl;


	const char *color[6] = { "red", "green", "blue", "white", "black", "yellow" };
	cout << "\n\ncolor = " << color << "\n";
	cout << "(color+2) = " << (color+2) << "\n";
	cout << "*color = " << *color << "\n";
	cout << "*(color+2) = " << *(color + 2) << "\n";
	cout <<"color[5] = "<<color[5]<<"\t"<< "*(color+5) = " << *(color + 5) << "\n";
	system("pause");
}

