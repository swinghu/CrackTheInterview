#include<stdio.h>

//Asume there are three array，all of them are in non-decrease order,
//How to find the common element of the three arrs.

void  CommonElementsOf3Array(int arr1[], int arr2[], int arr3[],int len1,int len2,int len3);

int main()
{
	int arr1[6] = {1,2,3,4,6,10};
	int arr2[5] = {3,4,5,10,11};
	int arr3[7] = {-12,3,4,10,11,12,34};
	CommonElementsOf3Array(arr1, arr2, arr3,6,5,7);
}
/*
	（1）常规思路，先求两个数组的公共元素 temp[]，然后将temp[]与第三个数组比较
	再求公共元素。O(n1+n2+n3),空间复杂度为 temp[];
	
	（2）本题的解法，无需开辟其他数组。
*/
void  CommonElementsOf3Array(int arr1[], int arr2[], int arr3[],int len1,int len2,int len3)
{
	int i = 0,j =0, k = 0;
	printf("the common element of the three arr is :");
	while (i<len1 && j<len2 && k<len3)
	{
		if (arr1[i]==arr2[j]&&arr1[i]==arr3[k])
		{
			printf("%d--",arr1[i]);
			i++; j++; k++;
		}else if (arr1[i] < arr2[j])
		{
			i++;
		} else if (arr2[j] < arr3[k])
		{
			j++;
		}else
		{
			k++;
		}
	}
}