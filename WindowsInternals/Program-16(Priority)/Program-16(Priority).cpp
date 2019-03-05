#include "pch.h"
#include<Windows.h>
#include <iostream>
#define MAX 100

using namespace std;
STARTUPINFO startInfo;
PROCESS_INFORMATION processInfo;

DWORD WINAPI Fnc(LPVOID var)
{
	cout << "Thread Created Successfully\n";
	return 0;
}
int main()
{
	ZeroMemory(&startInfo, sizeof(startInfo));
	ZeroMemory(&processInfo, sizeof(processInfo));
	int retValue = CreateProcess(TEXT("C:/Users/rspse/Downloads/Winobj.exe"),
		NULL, NULL, NULL, TRUE, HIGH_PRIORITY_CLASS, NULL, NULL, &startInfo, &processInfo
	); //Create Process with HIGH Priority

	cout << "Process Created With High Priority"<<"\n";
	if (0 == retValue)
		cout << "Process not Created " << GetLastError() << "\n";

	//Change priority of the process
	BOOL ret = SetPriorityClass( processInfo.hProcess, BELOW_NORMAL_PRIORITY_CLASS );
	
	 if(0 == ret)
		cout << "Failed to change Priority , Error is : "<<GetLastError()<<"\n";

	 else
		 cout << "Process Priority changed to BelowNormal" << "\n";

	 DWORD threadVar = 0;
	 HANDLE threadHandle = CreateThread(NULL, 0, Fnc, &threadVar, 0, NULL);
	 if (NULL == threadHandle)
	 {
		 cout << "Error in Creating Thread : " << GetLastError() << "\n";
	 }
	WaitForSingleObject(threadHandle, INFINITE);

	BOOL ret1 = SetThreadPriority(threadHandle, THREAD_PRIORITY_LOWEST);

	if (0 == ret1)
		cout << "Failed to change Priority of thread , Error is : " << GetLastError() << "\n";

	else
		cout << "Thread Priority changed to Lowest" << "\n";

	CloseHandle(processInfo.hProcess);
	CloseHandle(processInfo.hThread);

	system("pause");
	return 0;
}

