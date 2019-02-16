#include "pch.h"
#include <iostream>
using namespace std;


class Sample
{
public:
	int x;
protected:
	int y;
private:
	int z;
};

class Der : public Sample
{

public:
	void display()
	{
		cout << "\nX = " << x;
		cout << "\nY = " << y;
		cout << "\nZ = " << z;
		cout<< "\n\n";
	}
	// x is public
	// y is protected
	// z is not accessible from publicDerived
};

class protectedDerived : protected Sample
{

public:
	void display()
	{
		cout << "\nX = " << x;
		cout << "\nY = " << y;
		cout << "\nZ = " << z;
		cout << "\n\n";
	}
	// x is protected
	// y is protected
	// z is not accessible from protectedDerived
};

class privateDerived : private Sample
{

public:
	void display()
	{
		cout << "\nX = " << x;
		cout << "\nY = " << y;
		cout << "\nZ = " << z;
		cout << "\n\n";
	}
	// x is private
	// y is private
	// z is not accessible from privateDerived
};

int main()
{
	system("pause");
}