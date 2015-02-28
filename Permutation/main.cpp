/*

全排列
ABC的全排列：ABC, ACB, BAC, BCA, CAB, CBA
*/

#include <stdio.h>

void swap(char *x, char *y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

/*
打印所有全排列
string
start index of the string
end index of the string
*/

void permute(char *a, int i, int n)
{
	int j;
	if (i == n)
	{
		printf("%s\n", a);
	}
	else
	{
		for (j = i; j <= n; j++)
		{
			swap((a + i), (a + j));
			permute(a, i + 1, n);
			swap((a + i), (a + j));
		}

	}
}

int main()
{
	char a[] = "ABCDE";
	permute(a, 1, 4);
	getchar();
	return 0;
}


