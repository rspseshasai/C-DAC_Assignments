#include "pch.h"
#include <iostream>
using namespace std;


class Sample
{
public:
	virtual void display()
	{

	}
	Sample()
	{
		x = 2;
		y = 3;
		z = 4;
	}
	int x;
protected:
	int y;
private:
	int z;
};

class PubDer : public Sample
{

public:
	void display()
	{
		cout << "\nX = " << x;
		cout << "\nY = " << y;

		//-------Private member Cannot be accessed-----------//
		//cout << "\nZ = " << z;
		cout<< "\n\n";
	}
};

class proDer: protected Sample
{

public:
	void display()
	{

		//---------X and Y are Protected-----------//
		cout << "\nX = " << x;
		cout << "\nY = " << y;

		//-------Private member Cannot be accessed-----------//
		//cout << "\nZ = " << z;
		cout << "\n\n";
	}

};

class priDer : private Sample
{

public:
	void display()
	{

		//------------X and Y are Private------------------//
		cout << "\nX = " << x;
		cout << "\nY = " << y;

		//-------Private member Cannot be accessed-----------//
		//cout << "\nZ = " << z;
		cout << "\n\n";
	}
};

int main()
{
	Sample *ob;
	PubDer pu;
	priDer pri;
	proDer pro;

	ob = &pu;
	ob->display();

	//Classes Which are inherited as Private or Public cannot be accessed

	/*ob = &pri;           
	ob->display();

	ob = &pro;
	ob->display();*/

	system("pause");
}