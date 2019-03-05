#include "pch.h"
#include <iostream>
#include <Windows.h>

using namespace std;

STARTUPINFO startUpInfo;
PROCESS_INFORMATION pInfo;
SECURITY_ATTRIBUTES securityAttribute;

int main()
{

	ZeroMemory(&securityAttribute, sizeof(securityAttribute));

	securityAttribute.bInheritHandle = TRUE;

	HANDLE eventHandle = CreateEvent(&securityAttribute, FALSE, FALSE, TEXT("SampleEvent"));

	if (NULL == eventHandle)
	{
		cout << "Event is not created, Error code is: " << GetLastError()<<"\n";
	}

	ZeroMemory(&startUpInfo, sizeof(startUpInfo));
	ZeroMemory(&pInfo, sizeof(pInfo));

	BOOL processReturn = CreateProcess(TEXT("C:/Users/rspse/Downloads/Winobj.exe"), NULL, NULL, NULL, TRUE, 0, NULL, NULL, &startUpInfo, &pInfo);

	if (0 == processReturn)
	{
		cout << "Process cannot be created, Error code is: " << GetLastError() << "\n";
	}

	system("pause");
	return 0;
}

