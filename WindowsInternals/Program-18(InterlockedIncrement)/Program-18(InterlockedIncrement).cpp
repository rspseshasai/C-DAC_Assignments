#include "pch.h"
#include <iostream>
#include <Windows.h>

using namespace std;

//Declare Global as it can be shared
DWORD c = 0;

DWORD WINAPI thread1Fnc(LPVOID var)
{
	for (int i = 0; i < 10; i++)
	{
		//InterlockedIncrement(&c);
		cout << "Value of C in threadFnc1 is : " << InterlockedIncrement(&c) << "\n";
	}
	return 0;
}
DWORD WINAPI thread2Fnc(LPVOID var)
{
	for (int i = 0; i < 10; i++)
	{
		//Sleep(1000);
		//InterlockedIncrement(&c);
		cout << "Value of C in threadFnc2 is : " << InterlockedIncrement(&c) << "\n";
	}
	return 0;
}

int main()
{
	DWORD varThread;

	HANDLE threadHandler1 = CreateThread(NULL, 0, thread1Fnc, &varThread, 0, NULL);

	if (NULL == threadHandler1)
	{
		cout << "Thread1 not Created, Error is : " << GetLastError() << "\n";
	}

	DWORD ThreadVariable1;

	HANDLE threadHandler2 = CreateThread(NULL, 0, thread2Fnc, &varThread, 0, NULL);

	if (NULL == threadHandler2)
	{
		cout << "Thread2 not Created, Error is : " << GetLastError() << "\n";
	}
	cout << "Value of C in Main is : " << c << "\n";

	system("pause");
	return 0;
}
