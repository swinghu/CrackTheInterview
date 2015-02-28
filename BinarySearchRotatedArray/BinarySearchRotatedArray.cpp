/*!
 * \file BinarySearchRotatedArray.cpp
 *
 * \author swinghu@live.cn
 * \date 二月 2015
 *
 * 查找有序数组旋转后某个元素的索引
 */
////////////////////////////////////////////////
/*
Suppose a sorted array is rotated at some pivot
unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search.If found 
in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array
*/

/*
	时间复杂度 O(log n)，空间复杂度O(1)
*/

#include <stdio.h>
#include <string.h>

/*
	pivot search
*/
int search(int A[], int n, int target)
{
	int first = 0, last = n;
	while (first != last)
	{
		const int mid = first + (last - first) / 2;
		if (A[mid] == target)
			return mid;

		if (A[first] <= A[mid])
		{
			if (A[first] <= target && target < A[mid])		//区间递增
				last = mid;
			else
				first = mid + 1;
		}
		else
		{
			if (A[mid] < target && target <= A[last - 1])	//区间递增
				first = mid + 1;
			else
				last = mid;
		}
	}
	return -1;
}

// 普通二分查找

int binary_search(int* A, int n, int target)
{
	int first = 0, last = n;
	while (first != last)
	{
		const int mid = first + (last - first) / 2;
		if (A[mid] == target)
			return mid;
		if (A[mid] >= target)
		{	
			last = mid ;
		}
		else
		{
			first = mid + 1;
		}
	}
}

void main()
{
	int A[] = {4,5,6,7,8,9,0,1,2,3};
	int res = search(A, 10, 1);
	printf("Pivot Array 所在索引为：%d\n",res); //n = 10,res = 7


	int A2[] = { 0, 1, 2, 3, 4, 45, 56, 57, 78, 99 };
	res = binary_search(A2, 9, 56);
	printf("BinarySearch Array 所在索引为：%d\n", res);

}
