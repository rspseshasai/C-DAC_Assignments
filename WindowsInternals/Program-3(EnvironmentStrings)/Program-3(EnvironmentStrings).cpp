#include "pch.h"
#include<Windows.h>
#include <iostream>

using namespace std;

int main()
{
	LPCTSTR  enviVariable = TEXT("%TEMP%");
	TCHAR * buffer= new TCHAR[100];
	int size = ExpandEnvironmentStrings(enviVariable, buffer, 100);
	cout<<"Size of Buffer: " << size << "\n";
	printf("EnviVariable is : %S\nExpanded Variable is : %S\n", enviVariable, buffer);
	system("pause");
	return 0;
}
