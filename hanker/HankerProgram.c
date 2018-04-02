#define _UNICODE

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

void OutWrite(const char* text);
void OutWriteLine(const char* text);
void WriteLastError(const char* Apiname);
void RunThread(void);

DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
	OutWriteLine("Hello Mr. Hanker from your thread");
	Sleep(1000);
	return 0;
}

void RunThread(void)
{
	DWORD threadId;
	HANDLE hThread = CreateThread(NULL, 0, ThreadProc, NULL, 0, &threadId);
	if (hThread == NULL)
	{
		WriteLastError("CreateThread");
		return;
	}
	OutWriteLine("Thread started. Waiting for termination...");
	WaitForSingleObject(hThread, INFINITE);
	OutWriteLine("Thread terminated");

	CloseHandle(hThread);
}

void WriteLastError(const char* Apiname)
{
	char buffer[1024];
	wsprintf(buffer, "E-Win32API: Lasterror: %d, Api: %s", GetLastError(), Apiname);
	OutWriteLine(buffer);
}

void OutWriteLine(const char* text)
{
	OutWrite(text);
	OutWrite("\n");
}

void OutWrite(const char* text)
{
	DWORD bytesWritten;
	if (WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), text, lstrlenA(text), &bytesWritten, NULL) == FALSE)
	{
		WriteLastError("WriteFile");
	}
}
