#define _UNICODE

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

void RunThread(void);

void rawmain(void)
{
	RunThread();
	ExitProcess(0);
}

