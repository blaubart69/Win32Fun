#include <Strsafe.h>

void RunThread(void);

int main(char* argv[], int argc)
{
	char dst[16];


	StringCbCat(dst, sizeof(dst), "berni");

	RunThread();
	return 0;
}