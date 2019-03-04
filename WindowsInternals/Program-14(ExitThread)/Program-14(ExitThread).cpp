#include "pch.h"
#include<Windows.h>
#include <iostream>
using namespace std;

DWORD WINAPI Fnc(LPVOID var)
{
	cout << "Hello Thread\n";
	DWORD dwExitCode=0;
	ExitThread(dwExitCode);
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
	DWORD lpExitCode = 0;

	//Sleep(2000);
	BOOL ExitStatus = GetExitCodeThread(threadHandle, &lpExitCode);

	//getchar();
	WaitForSingleObject(threadHandle, INFINITE);
	
	if (ExitStatus == 0)
		cout << "Thread's not terminated\n";
	else
		cout << "Thread Exited\nExit Code is : " << lpExitCode << "\n";
	system("pause");
	return 0;
}

