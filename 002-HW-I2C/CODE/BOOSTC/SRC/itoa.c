#include <system.h>

void itoa(int val, int base);

void itoa(int val, int base)
{
	
static char buf[32] = {0};
	
	int i = 30;
	
	for(; val && i ; --i; val /= base)
		{
		buf[i] = "0123456789ABCDEF"[val % base];
		}

}

