#define _UNICODE

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "../beeLib.h"

void RunThread(void);
int Resolve(const char* hostname);

void rawmain(void)
{
	//RunThread();
	Resolve("spindi.top");

	ExitProcess(0);
}

