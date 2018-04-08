#define _UNICODE

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "beeLib.h"

void OutWriteLastError(const WCHAR* Apiname)
{
	OutWriteFW(L"E-Win32API: Lasterror: %u, Api: %ls\n", GetLastError(), Apiname);
}

void OutWriteFW(const WCHAR* format, ...)
{
	WCHAR buffer[1024];

	va_list args;
	va_start(args, format);
	wvsprintfW(buffer, format, args);
	
	DWORD charsWritten;
	WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), buffer, lstrlenW(buffer), &charsWritten, NULL);

	va_end(args);
}
