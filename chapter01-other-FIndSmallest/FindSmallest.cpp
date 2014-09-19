/*
Find the smallest positive integer value that cannot be represented as sum of
any subset of a given array Given a sorted array (sorted in non-decreasing order) 
of positive numbers, find the smallest positive integer value that cannot be
represented as sum of elements of any subset of given set. Expected time 
complexity is O(n).

Examples:

Input:  arr[] = {1, 3, 6, 10, 11, 15};
Output: 2

Input:  arr[] = {1, 1, 1, 1};
Output: 5

Input:  arr[] = {1, 1, 3, 4};
Output: 10

Input:  arr[] = {1, 2, 5, 10, 20, 40};
Output: 4

Input:  arr[] = {1, 2, 3, 4, 5, 6};
Output: 22
*/


#include <stdio.h>

int FindtheSmallest(int* arr, int n);

void main()
{
	//int arr[6] = {1,2,5,6,8,12};
	int arr[6] = { 1, 2, 3, 4, 5, 6 };
	int res = FindtheSmallest(arr, 6);
	printf("the smallest elme is+ %d ", res);
}

int FindtheSmallest(int* arr, int n)
{
	int res = 1;
	//when i =2,arr[2]= 5 > res=4;break the while loop
	for (int i = 0; i < n && arr[i] <= res; i++) 
	{
		res = res + arr[i];
	}
	return res;
}



