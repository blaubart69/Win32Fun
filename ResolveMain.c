#define  UNICODE
#define _UNICODE

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <winsock2.h>

#include "beeLib.h"

int Resolve(const WCHAR* hostname);

int beeMain(WCHAR* argv[], int argc)
{
	if (argc < 2 || argc > 2)
	{
		OutWriteFW(L"usage: resolve.exe {hostname}\n");
		return(1);
	}

	WCHAR* hostnameToResolve = argv[1];

	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		OutWriteLastError(L"WSAStartup");
		return 2;
	}

	int resolveRc = Resolve(hostnameToResolve);

	WSACleanup();

	return 0;
}