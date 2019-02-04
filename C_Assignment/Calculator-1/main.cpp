#include<iostream>

using namespace std;
int result = 0;
int add1(int, int);
int sub(int, int);

int main()
{
	int a, b;
	cout << "Enter two numbers\n";
	cin >> a >> b;
	int ch;
	cout << "1-addition\t2-subtraction\n";
	cin >> ch;
	switch (ch)
	{
	case 1: result = add1(a, b);
		cout << "Addition = " << result << "\n";
			break;
	case 2: result = sub(a, b);
		cout << "Subtraction = " << result << "\n";
			break;
	}
	system("pause");
	return 0;
}