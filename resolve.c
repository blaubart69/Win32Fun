#define UNICODE
#define _UNICODE

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <winsock2.h>
#include <Ws2tcpip.h>

#include "beeLib.h"

int Resolve(const WCHAR* hostname)
{
	ADDRINFOW *result;
	ADDRINFOW hints;

	ZeroMemory(&hints, sizeof(hints));
	int rc = GetAddrInfoW(hostname, NULL, &hints, &result);
	if (rc != 0)
	{
		OutWriteLastError(L"GetAddrInfo");
		return rc;
	}

	ADDRINFOW *i;
	for (i = result; i != NULL; i = i->ai_next)
	{
		WCHAR* proto;
		if (i->ai_family == AF_INET)
		{
			proto = L"IPv4";
		}
		else if (i->ai_family == AF_INET6 )
		{
			proto = L"IPv6";
		}
		else
		{
			proto = L"unknown";
		}

		WCHAR AddressString[128];
		DWORD AddressLength = sizeof(AddressString);
		int rcAddrToString = WSAAddressToStringW(i->ai_addr, i->ai_addrlen, NULL, AddressString, &AddressLength);
		if (rcAddrToString != 0)
		{
			OutWriteFW(L"Error converting address to string. WSALastError=%d\n", WSAGetLastError());
		}
		else
		{
			OutWriteFW(L"%s\t%s\n", proto, AddressString);
		}
	}

	return 0;
}
