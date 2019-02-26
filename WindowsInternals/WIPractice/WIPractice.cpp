
#include "pch.h"
#include<windows.h>
#include <iostream>
using namespace std;

int main()
{
	//char ch = 'P';
	//wchar_t wch = L'S';

	/*char ar[] = "Normal Char";
	wchar_t war[] = L"Wide Char";

	
	wcout << ch << " " << wch << "\n";
	wcout << ar << " " << war << "\n"; // We should use wcout to print wide char data types
	*/
	/*printf("Char is : %c\n", ch);
	printf("Char in WideChar is : %c\n", wch);

	printf("String is : %s\n", ar);
	printf("String in WideChar is : %S\n", war); // also we can use %ws
	
	BOOL ret = IsTextUnicode(ar, strlen(ar)+1, NULL);
	BOOL wret = IsTextUnicode(war, wcslen(war)+1, NULL);

	//cout<<ret<<" "<<wret<<"\n";`
	cout << "\n";
	if (ret == 1)
		printf("%s is Unicode", ar);
	else
		printf("%s is Not Unicode", ar);

	cout << "\n";

	if (wret == 1)
		printf("%S is Unicode", war);
	else
		printf("%S is Not Unicode", war);

	cout << "\n\n";
	*/
	CHAR ar1[] = "Normal Char";
	WCHAR war1[] = L"Wide Char";

	printf("String with CHAR is : %s\n", ar1);
	printf("String WCHAR is : %ws\n", war1);

	BOOL ret1 = IsTextUnicode(ar1, strlen(ar1) + 1, NULL);
	BOOL wret1 = IsTextUnicode(war1, wcslen(war1) + 1, NULL);

	//cout<<ret<<" "<<wret<<"\n";
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


	/*wchar_t war2[] = TEXT("Wide Char");

	printf("String using TEXT api is : %ws\n", war1);

	BOOL wret2 = IsTextUnicode(war2, wcslen(war2) + 1, NULL);

	cout << "\n";

	if (wret2 == 1)
		printf("%S using TEXT api is Unicode", war2);
	else
		printf("%S using TEXT api is Not Unicode", war2);

	cout << "\n\n";
	*/
	system("pause");
}
