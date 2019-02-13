
#include "pch.h"
#include <iostream>
#include<string>
using namespace std;

class MatMul
{
	int a[10][10], v[10], ans[10] = {0}, m, n;
public:
	MatMul(int m, int n)
	{
		this->m = m;
		this->n = n;
		cout << "Enter Matrix\n";
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> a[i][j];
			}
		}
		cout << "Enter a Vector\n";
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
	}
	/*void print(MatMul &o)
	{
		for (int i = 0; i < m; i++)
		{
			cout << o.ans[i] << "\n";
		}
	}
	*/
	friend void Multiply(MatMul);
};

void Multiply(MatMul ob)
{
	cout << "\nAfter Multiplication \n";
	for (int i = 0; i < ob.m; i++)
	{
		for (int j = 0; j < ob.n; j++)
		{
			ob.ans[i] += ob.a[i][j] * ob.v[j];
			//cout << ob.ans[i] << " ";
		}
		cout << ob.ans[i] << "\n";
	}
}

int main()
{
	int m, n;
	cout << "Enter size of matrix: ";
	cin >> m >> n;
	MatMul ob(m, n);
	Multiply(ob);
	//ob.print(ob);
	system("pause");
}
