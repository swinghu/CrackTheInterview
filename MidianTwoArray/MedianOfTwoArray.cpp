/*!
 * \file MedianOfTwoArray.cpp
 *
 * \author swinghu-pc
 * \date 三月 2015
 *
 * 求两个有序数组的中间值median
 */

/*
	There are two sorted arrays A and B of size m and n respectively.
	Find the median of the two sorted arrays. The overall run time
	complexity should be O(log(m + n)).
*/
/*	分析
	假设A 和B 的元素个数都大于k/2，我们将A 的第k/2 个元素（即A[k/2-1]）和B 的第k/2
	个元素（即B[k/2-1]）进行比较，有以下三种情况（为了简化这里先假设k 为偶数，所得到的结论
	对于k 是奇数也是成立的）：
	• A[k/2-1] == B[k/2-1]
	• A[k/2-1] > B[k/2-1]
	• A[k/2-1] < B[k/2-1]
	如果A[k/2-1] < B[k/2-1]，意味着A[0] 到A[k/2-1 的肯定在A [ B 的top k 元素的范围
	内，换句话说，A[k/2-1 不可能大于A [ B 的第k 大元素。留给读者证明。
	因此，我们可以放心的删除A 数组的这k/2 个元素。同理，当A[k/2-1] > B[k/2-1] 时，可
	以删除B 数组的k/2 个元素。
	当A[k/2-1] == B[k/2-1] 时，说明找到了第k 大的元素，直接返回A[k/2-1] 或B[k/2-1]
	即可。

	因此，我们可以写一个递归函数。那么函数什么时候应该终止呢？
	• 当A 或B 是空时，直接返回B[k-1] 或A[k-1]；
	• 当k=1 是，返回min(A[0], B[0])；
	• 当A[k/2-1] == B[k/2-1] 时，返回A[k/2-1] 或B[k/2-1]

*/

/*
	时间复杂度 O(log(m + n))
*/

#include <stdio.h>
#include <string.h>

#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))

double findMedianSortedArrays(int A[], int m, int B[], int n)
{
	int total = m + n;
	if (total & 0x01) // 为奇数
		return find_kth(A, m, B, B, total / 2 + 1);
	else
		return (find_kth(A, m, B, total/2)+ find_kth(A, m, B, n, total / 2 + 1))/ 2;

}

//	查找第k大的元素
int find_kth(int A[], int m, int B[], int n, int k)
{
	if (m > n)
		return find_kth(B, n, A, m, k);

	if (m == 0)
		return B[k - 1];	// A 数组为空 

	if (k == 1) return min(A[0], B[0]);

	//	将k分成两部分
	int ia = min(k / 2, m); ib = k - ia;
	if (A[ia - 1] < B[ib - 1])
		return find_kth(A + ia, m - ia, B, n, k - ia);	// 去掉A 中的前ia项
	else if (A[ia - 1] > B[ib - 1])
		return find_kth(A, m, B + ib, n - ib, k - ib);  // 去掉B 中的前ib项
	else
		return A[ia - 1];  // 相等，找到
}

void main()
{

}












