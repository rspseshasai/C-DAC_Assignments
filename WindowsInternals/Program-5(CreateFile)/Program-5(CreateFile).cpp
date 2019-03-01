#include "pch.h"
#include<Windows.h>
#include <iostream>
#define MAX 100

using namespace std;

int main()
{
	DWORD dwBytesRead = 0, dwBytesWrite=0;

	HANDLE fileHandle = CreateFile(TEXT("D:\\file2.txt"), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	// Check for error
	if (fileHandle == INVALID_HANDLE_VALUE) {
		printf("File not created. Error %u", GetLastError());
		CloseHandle(fileHandle);
		return EXIT_FAILURE;
	}

	//ZeroMemory(FileContent, MAX);
	char ContentToWrite[MAX] = "Hello This is File-2";
	// Check Error While Reading file
	if (!WriteFile(fileHandle, ContentToWrite, MAX, &dwBytesWrite, NULL))
	{
		printf("File Cannot be Written . Error %u", GetLastError());
	}
	CloseHandle(fileHandle);
	system("pause");
	return 0;
}

