#define _UNICODE

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <winsock2.h>

#include "beeLib.h"

int Resolve(const WCHAR* hostname);

void rawmain(void)
{
	OutWriteFW(L"starting WinSock\n");

	// Initialize Winsock
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		OutWriteLastError(L"WSAStartup");
		ExitProcess(1);
	}

	Resolve(L"git.spindi.top");

	WSACleanup();

	ExitProcess(0);
}