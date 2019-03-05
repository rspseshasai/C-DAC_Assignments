#include "pch.h"
#include <iostream>
#include <Windows.h>

using namespace std;

//Declare Global as it can be shared
DWORD c = 0;
CRITICAL_SECTION lpCriticalSection ;


DWORD WINAPI thread1Fnc(LPVOID var)
{
	EnterCriticalSection(&lpCriticalSection);
	for (int i = 0; i < 10; i++)
	{
		cout << "Value of C in threadFnc1 is : " << c++ << "\n";
	}
	LeaveCriticalSection(&lpCriticalSection);
	return 0;
}
DWORD WINAPI thread2Fnc(LPVOID var)
{
	EnterCriticalSection(&lpCriticalSection);
	for (int i = 0; i < 10; i++)
	{
		cout << "Value of C in threadFnc2 is : " << c++ << "\n";
	}
	LeaveCriticalSection(&lpCriticalSection);

	return 0;
}

int main()
{
	DWORD varThread;

	InitializeCriticalSection(&lpCriticalSection);

	HANDLE threadHandler1 = CreateThread(NULL, 0, thread1Fnc, &varThread, 0, NULL);

	if (NULL == threadHandler1)
	{
		cout << "Thread1 not Created, Error is : " << GetLastError() << "\n";
	}


	WaitForSingleObject(threadHandler1, INFINITE);

	HANDLE threadHandler2 = CreateThread(NULL, 0, thread2Fnc, &varThread, 0, NULL);

	if (NULL == threadHandler2)
	{
		cout << "Thread2 not Created, Error is : " << GetLastError() << "\n";
	}
	cout << "Value of C in Main is : " << c << "\n";

	WaitForSingleObject(threadHandler2, INFINITE);

	DeleteCriticalSection(&lpCriticalSection);

	return 0;
}
