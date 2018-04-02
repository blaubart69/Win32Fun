#define _UNICODE

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

void rawmain(void)
{
	char* toPrint = "Hello Mr. Hanker";
	DWORD bytesWritten;

	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), toPrint, lstrlenA(toPrint), &bytesWritten, NULL);

	ExitProcess(0);
}