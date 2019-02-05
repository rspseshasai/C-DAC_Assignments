
#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Enter a number\n";
	cin >> n;
	int ans=0, t=1;
	while (n > 0)
	{
		ans = (ans * t) + (n % 10);
		//cout << ans << " \n";
		t = 10;
		n /= 10;
	}
	cout << ans << "\n";
	system("pause");
}
