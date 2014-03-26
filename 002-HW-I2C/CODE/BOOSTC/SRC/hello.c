#include <system.h>

#ifndef _PIC12F683
#warning "_PIC12F683 not defined"
#define _PIC12F683
#endif



void interrupt(void)
{
	asm nop;
}

void main(void)
{
char a = 2;
char b =6;
char c = 0;  
while(1)
{
  
  c = a+ b;
  a++;
  b++;
  
}    
  
  
  
} 
