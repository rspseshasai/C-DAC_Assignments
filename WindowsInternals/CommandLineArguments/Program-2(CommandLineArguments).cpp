
#include "pch.h"
#include <iostream>
#include<windows.h>
using namespace std;

int main(int argc, LPSTR * argv)
{
	LPWSTR * str;
	str = CommandLineToArgvW(GetCommandLineW(), &argc);
	if (NULL == str)
	{
		cout << "Error Occurred : " << GetLastError()<<"\n";
	}
	printf("%ws\n", str[1]);
	system("pause");
	return 0;
}
