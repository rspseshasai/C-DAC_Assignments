#include "pch.h"
#include<Windows.h>
#include <iostream>
#define MAX 100

using namespace std;

int main()
{
	CHAR * FileContent = new CHAR[MAX];
	DWORD dwBytesRead=0;

	HANDLE fileHandle = CreateFile(TEXT("D:\\file1.txt"), GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (fileHandle == INVALID_HANDLE_VALUE) {
		printf("Source file not opened. Error %u", GetLastError());
		return EXIT_FAILURE;
	}

	ZeroMemory(FileContent, MAX);

	bool ok = true;
	do 
	{
		// Check Error While Reading file
		if (!ReadFile(fileHandle, FileContent, MAX, &dwBytesRead, NULL)) 
		{
			printf("Source file not read from. Error %u", GetLastError());
			ok = false;
			break;
		}
		// Check for EOF
		if (dwBytesRead == 0) 
		{
			break;
		}
	} while (true);

	cout << FileContent<<"\n";
	system("pause");
	return 0;
}
