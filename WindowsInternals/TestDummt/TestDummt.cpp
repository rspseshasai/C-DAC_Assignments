#include "pch.h"
#include<Windows.h>
#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	//	char cString[] = "normal string"; //MBC = 1 byte for each character
		//wchar_t wString[] = L"wide string"; //Unicode(UTF-16) = 2 bytes for each character

	//char cChar = 'A';
	//wchar_t wChar = 'A'; //no need of L for single character

	//user defined datatypes in "Windows.h" using "typedef"
	CHAR ar1[] = "normal windows string";
	WCHAR war1[] = L"wide windows string"; // it appends 'L' to the beginning === L"wide windows string"

	//print normal C string
//	cout << cChar << endl << cString << endl << cString1 << endl;
	//print wide string
//	wcout << wChar << endl << wString << endl << wString1 << endl;


	/* //printing using format specifiers
	printf("%s\n", cString);
	printf("%S", wString); //%Ls, %lls = prints first character;    %ws, %S = prints whole string    */

	//Testing if the text is Unicode or not
	//strlen() = normal string length;  wcslen() = wide string length

	BOOL ret1 = IsTextUnicode(ar1, strlen(ar1)+1, NULL); // returns "int" typedefined as BOOL
	BOOL wret1 = IsTextUnicode(war1, wcslen(war1)+1, NULL);

	cout << "\n";
	if (ret1 == 1)
		printf("%s with CHAR is Unicode", ar1);
	else
		printf("%s with CHAR is Not Unicode", ar1);

	cout << "\n";

	if (wret1 == 1)
		printf("%S with WCHAR is Unicode", war1);
	else
		printf("%S with WCHAR is Not Unicode", war1);

	cout << "\n\n";

	//MBC to Wide char(Unicode) conversion
	//int returnValue = MultiByteToWideChar(CP_UTF8, );


	_getch();
}