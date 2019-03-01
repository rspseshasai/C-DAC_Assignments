#include "pch.h"
#include<Windows.h>
#include <iostream>
using namespace std;

DWORD WINAPI Fnc(LPVOID var)
{
	cout << "Hello Thread\n";
	return 0;
}

int main(int argc, TCHAR *argv[])
{
	DWORD threadVar = 0;
	HANDLE threadHandle = CreateThread(NULL, 0, Fnc, &threadVar, 0, NULL);
	if (NULL == threadHandle)
	{
		cout << "Error in Creating Thread : " << GetLastError() << "\n";
	}
	WaitForSingleObject(threadHandle, INFINITE);
	cout << "CurrentProcessId is : " << GetCurrentProcessId() << "\n";
	cout << "CurrentThreadId is : " << GetCurrentThreadId() << "\n";
	cout << "ProcessId is : " << GetProcessId << "\n";
	cout << "ThreadId is : " << GetThreadId << "\n";
	cout << "ProcessIdOfThread  is : " << GetProcessIdOfThread<< "\n";

	system("pause");
	return 0;
}

