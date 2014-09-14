#include <stdio.h>
#include "Vector.h"

double read_and_sum(Vector &v, int s);

int main(){

	Vector v(5);
	for (int i = 0; i < 5; i++)
	{
		v[i] = i;
	}
	double dval = read_and_sum(v, 5);
	printf("the sum of Vector v is: %f", dval);
}

double read_and_sum( Vector &v ,int s)
{
	double  dval = 0;
	for (int i = 0; i < s; i++)
	{
		dval += v[i];
	}

	return dval;
}