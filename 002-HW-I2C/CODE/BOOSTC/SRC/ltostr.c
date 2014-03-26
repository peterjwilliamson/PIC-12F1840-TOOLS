#include "INC\ltostr.h"

void ltostr(long num,char max_chars,char dp,char* string)
{
char i;

	for (i = 0;i < max_chars;i++)
		{
		string[i] = '0';
		}
			
	string[0] = '+';	
	if (num < 0)
		{
        num = -num;
        string[0] = '-';
		}
	dp = (max_chars - (dp+2)) ;
	string[dp] = '.';
    string[--max_chars] = '\0';
    for (max_chars--; (max_chars > 0) && (num!=0); max_chars --)
		{
        if (max_chars == dp) max_chars--;
			{
            string[max_chars] = ((char)(num % 10)) + '0';
            //string[max_chars] = ((char)(num % 10));
            }
            num /= 10;
		}
}

