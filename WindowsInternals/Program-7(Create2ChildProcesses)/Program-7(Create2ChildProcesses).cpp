#include "pch.h"
#include<Windows.h>
#include <iostream>
#define MAX 100

using namespace std;
STARTUPINFO si1, si2;
PROCESS_INFORMATION pi1, pi2;



int main(int argc, TCHAR *argv[])
{
	ZeroMemory(&si1, sizeof(si1));
	si1.cb = sizeof(si1);
	ZeroMemory(&pi1, sizeof(pi1));

	ZeroMemory(&si2, sizeof(si2));
	si2.cb = sizeof(si2);
	ZeroMemory(&pi2, sizeof(pi2));

	if (!CreateProcess(TEXT("C:/Users/rspse/source/repos/rspseshasai/C-DAC_Assignments/C_Assignment/C_Assignment-1/Calculator-1/Calc.exe"),
		NULL,
		NULL,           
		NULL,           
		FALSE,          
		0,              
		NULL,           
		NULL,           
		&si1,            
		&pi1)           
		) {
		printf("CreateProcess failed (%d).\n", GetLastError());
		return 0;
	}

	if (!CreateProcess(TEXT("C:/Users/rspse/Downloads/Winobj.exe"),
		NULL,
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		&si2,
		&pi2)
		) {
		printf("CreateProcess failed (%d).\n", GetLastError());
		return 0;
	}

	DWORD Ids[2];

	Ids[0] = pi1.dwProcessId;
	Ids[1] = pi2.dwProcessId;

	for (int i = 0; i < 2; i++)
		cout << "Process "<<i<<" Id is : " << Ids[i]<<"\n";

	CloseHandle(pi1.hProcess);
	CloseHandle(pi1.hThread);

	CloseHandle(pi2.hProcess);
	CloseHandle(pi2.hThread);

	system("pause");
	return 0;
}

