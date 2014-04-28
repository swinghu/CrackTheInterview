
#include <stdio.h>
#include <stdlib.h>
#ifdef DEBUG
void _Assert(char* unsigned);

#define ASSERT(f)\
	if (f)\
	NULL;
	else\
		_Assert(__FILE__,__LINE__)
#else

#define ASSERT(f)NULL

#endif

void _Assert(char* strFile, unsigned uLine)
{
	fflush(stdout);
	fprintf(stderr, "\n Assertion Failed:%s,line %u\n", strFile, uLine);
	fflush(stdout);
	abort();
}