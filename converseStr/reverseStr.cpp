#include <stdio.h>
#include <assert.h>
#include <string>
#include "sw_assert.h"
/***
	reverse the string 
*/

void reverse(char* str)
{

	ASSERT(str == NULL);

	int len = strlen(str);//strlen the result did not include the null

	char* dst = str + len-1;

	while (str < dst)
	{
		//swap the char
		char temp = *str;
		*str++ = *dst;
		*dst-- = temp;
	}
}

int main()
{
	char str[] = "abcdfesgssdfsdf";

	reverse(str);

	printf("the reverse string is: %s\n", str);
	
}