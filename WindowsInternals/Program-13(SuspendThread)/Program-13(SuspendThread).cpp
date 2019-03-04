#include "pch.h"
#include<Windows.h>
#include <iostream>
using namespace std;

DWORD WINAPI Fnc(LPVOID var)
{
	//cout << "Hello Thread\n";
	for (int i = 1; i <= 10; i++)
	{
		cout << i << "\n";
		Sleep(1000);
	}
	return 0;
}

int main(int argc, TCHAR *argv[])
{
	DWORD threadVar = 0;
	HANDLE threadHandle = CreateThread(NULL, 0, Fnc, &threadVar, CREATE_SUSPENDED, NULL);
	if (NULL == threadHandle)
	{
		cout << "Error in Creating Thread : " << GetLastError() << "\n";
	}
	Sleep(5000);

	//resume thread

	DWORD resume = ResumeThread(threadHandle);
	WaitForSingleObject(threadHandle, INFINITE);
	system("pause");
	return 0;
}

