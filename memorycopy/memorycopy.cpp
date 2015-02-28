#include<stdio.h>
#include<string.h>


/*
The memcpy function is used to copy a block of data from a source 
address to a destination address.
Below is its prototype.
void * memcpy(void * destination, const void * source, size_t num);

How to implement your own memcpy()?
*/

/*
Why do we need a temp array?
The use of temp array is important to handle cases when source and 
destination addresses are overlapping.
*/
// correct version
void myMemoryCpy(void *dest, void *src, size_t n)
{
	//类型转换，转换成（char*）
	char *csrc = (char*)src;
	char *cdest = (char*)dest;

	char *temp = new char[n];
	for (size_t i = 0; i < n; i++)
		temp[i] = csrc[i];

	for (size_t i = 0; i < n; i++)
		cdest[i] = temp[i];

}

// uncorrect version,when dest and src address overlapping
void myMemoryCpy2(void *dest, void *src, size_t n)
{
	char *csrc = (char *)src;
	char *cdest = (char *)dest;
	for (size_t i = 0; i < n; i++)
	{
		cdest[i] = csrc[i];
	}

}
int main()
{
	char csrc[] = "hello world ,HanMeimei";
	char cdest[100];
	myMemoryCpy(cdest, csrc, strlen(csrc) + 1);
	printf("Copied string is %s", cdest);
}