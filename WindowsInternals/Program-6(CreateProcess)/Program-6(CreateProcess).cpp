#include "pch.h"
#include<Windows.h>
#include <iostream>
#define MAX 100

using namespace std;
STARTUPINFO startInfo;
PROCESS_INFORMATION processInfo;



int main()
{
	ZeroMemory(&startInfo, sizeof(startInfo));
	ZeroMemory(&processInfo, sizeof(processInfo));
	int retValue = CreateProcess(TEXT("C:/Users/rspse/Downloads/Winobj.exe"),
		NULL, NULL, NULL, TRUE, 0, NULL, NULL, &startInfo, &processInfo
		);

	if (0 == retValue)
		cout << "Process not Created "<<GetLastError()<<"\n";

	CloseHandle(processInfo.hProcess);
	CloseHandle(processInfo.hThread);
	system("pause");
	return 0;
}

