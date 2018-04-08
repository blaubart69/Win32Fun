#define _UNICODE
#define  UNICODE

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "beeLib.h"

LPTSTR* CommandLineToArgv2(LPCTSTR CmdLine, INT *argc);

void OutWriteLastError(const WCHAR* Apiname)
{
	const DWORD LastErr = GetLastError();

	LPWSTR lpWindowsErrorText = L"n/a";
	if ( FormatMessageW(
		    FORMAT_MESSAGE_ALLOCATE_BUFFER
		  | FORMAT_MESSAGE_FROM_SYSTEM
		, NULL
		, LastErr
		, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT)
		, (LPWSTR)&lpWindowsErrorText
		, 0
		, NULL) == 0) 
	{
		OutWriteFW(L"E-Win32API: Lasterror: %x, Api: %ls\n", GetLastError(), L"FormatMessage");
	}

	OutWriteFW(L"E-Win32API: Lasterror: 0x%X, Api: %ls, Msg: %ls\n", LastErr, Apiname, lpWindowsErrorText);

	LocalFree(lpWindowsErrorText);
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

void rawmain(void)
{
	int argc;
	LPTSTR* argv;
	argv = CommandLineToArgv2(GetCommandLineW(), &argc);

	int Exitcode = beeMain(argv, argc);

	HeapFree(GetProcessHeap(), 0, argv);

	ExitProcess(Exitcode);
}