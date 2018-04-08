#define _UNICODE

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "../beeLib.h"

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


