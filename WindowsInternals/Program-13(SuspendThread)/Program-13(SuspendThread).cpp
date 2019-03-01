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
	HANDLE threadHandle = CreateThread(NULL, 0, Fnc, &threadVar, CREATE_SUSPENDED, NULL);
	if (NULL == threadHandle)
	{
		cout << "Error in Creating Thread : " << GetLastError() << "\n";
	}
	Sleep(5000);

	//resume thread

	DWORD resume = ResumeThread(threadHandle);

	system("pause");
	return 0;
}

