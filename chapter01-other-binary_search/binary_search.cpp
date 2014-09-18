# include <stdio.h>
# include <iostream>


int binary_search(int* A, int n, int target);
int binary_search_half_open_interval(int * A, int n, int target);
int binary_search_lowesti(int* A, int n, int target);
int binary_search_highesti(int* A, int n, int target);

int main()
{

	int a[] = { 1, 2, 5, 7, 32, 33, 45, 45, 47, 47,47,47,47 };
	int token1 = binary_search(a, 13, 7);
	int token2 = binary_search_half_open_interval(a, 13, 7);
	int lowesttoken = binary_search_lowesti(a, 13, 45);
	int highesttoken = binary_search_highesti(a, 13, 45);
	printf("location：%d.......%d.......%d.......%d", token1, token2, lowesttoken, highesttoken);

}
//全闭区间
//A[0......n-1]
int binary_search(int* A, int n, int target)
{
	//边界条件迭代、循环终止条件设定以及中位数计算
	int low = 0, high = n - 1, middle = 0;

	_ASSERT(A != NULL && n >= 0);

	while (low <= high)
	{
		middle = low + (high - low) / 2;

		if (A[middle] == target)
			return middle;
		else if (A[middle] < target)
			low = middle+1;
		else
			high = middle-1;
	}
	return -1;

}

//半开区间
//A[0 ....n）
int binary_search_half_open_interval(int * A, int n, int target)
{
	int low = 0, high = n, middle = 0;
	_ASSERT(A != NULL && n >= 0);
	while (low<high)
	{
		middle = low + (high - low) / 2;
		if (A[middle] == target)
			return middle;
		else if (A[middle]>target)
			high = middle;
		else
			low = middle+1;

	}
	return -1;
}

//改进型，数组非降序，求最小的i,使得A[i] = target;

int binary_search_lowesti(int* A, int n, int target)
{
	int low = 0, high = n, middle = 0;
	_ASSERT(A != NULL && n >= 0);
	while (low<high)
	{
		middle = low + (high - low) / 2;
		if (A[middle] < target)
			low = middle + 1;
		else
			high = middle;
	}

	if (low > n || A[low] != target)
	{
		return -low - 1;
	}
	return low;
}

//改进型，数组非降序，求最大的i,使得A[i] = target;

int binary_search_highesti(int* A, int n, int target)
{
	int low = -1, high = n - 1, middel = 0;
	_ASSERT(A != NULL && n>=0);
	while (low <high)
	{
		middel = high - (high - low) / 2;
		if (A[middel] > target)
			high = middel - 1;
		else	
			low = middel;
	}
	if (high < 0 || A[high] != target)
		return -high - 2;
	else
		return high;
}
