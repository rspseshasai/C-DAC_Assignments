#include "pch.h"
#include<Windows.h>
#include <iostream>
#define MAX 100

using namespace std;

int main()
{
	HANDLE eventHandle = CreateEvent(NULL, TRUE, TRUE, TEXT("CustomEvent"));
	if (eventHandle == NULL)
	{
		printf("CreateEvent failed (%d)\n", GetLastError());
		return;
	}
	system("pause");
	return 0;
}

