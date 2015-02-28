#include<stdio.h>
#include<string.h>
/*
删除有序数组中的重复元素，并返回新的长度，不能使用新的数组和额外的空间

Given a sorted array, remove the duplicates in place such that each element appear only once
and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.
For example, Given input array A = [1,1,2],
Your function should return length = 2, and A is now [1,2].

*/

int removeDuplicates(int A[], int n)
{
	if (n == 0)
		return 0;
	int index = 0;
	for (int i = 1; i < n; i++)
	{
		if (A[index] != A[i])
			A[++index] = A[i];
	}
	return index + 1;
}
int main()
{
	int A[] = {1,2,3,3,4,4,5,6};
	int res = removeDuplicates(A, 8);
	printf("The new size of A: %d \n", res);
	for (int i = 0; i < res; i++)
	{
		printf("%d", A[i]);

	}
	return 0;
}