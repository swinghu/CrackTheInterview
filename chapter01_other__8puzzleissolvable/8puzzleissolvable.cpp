#include<iostream>
using namespace std;

//8 PUZZLE PROBLEM
//将3*3的二维数组转换成一维数组，如果逆序数为偶数可以解决的，
//为奇数，不可解决
/*
原理
How does this work?
The idea is based on the fact the parity of inversions remains same after a set of moves, i.e., 
if the inversion count is odd in initial stage, then it remain odd after any sequence of moves and 
if the inversion count is even, then it remains even after any sequence of moves. In the goal state, 
there are 0 inversions. So we can reach goal state only from a state which has even inversion count.

*/
int getInvCount(int arr[])
{
	int inv_count = 0;
	for (int i = 0; i < 9 - 1; i++)
		for (int j = i + 1; j < 9; j++)
		{
		    //DON'T COUNT THE NUMBER ZERO
			if (arr[j] && arr[i] && arr[i] > arr[j])
				inv_count++;
		}
	return inv_count;
}

bool isSolvable(int puzzle[3][3])
{
	//change the 2 dimension to one dimension array
	int invCount = getInvCount((int*)puzzle);
	return (invCount % 2 == 0);
}

int main(int argv, int ** args)
{
	/*
	//sovlable
	int puzzle[3][3] = {
			{1,8,2,},
			{0,4,3,},
			{7,6,5}
	};
	*/
	//not solvable
	int puzzle[3][3] = {
			{8,1,2},
			{0,4,3},
			{7,6,5}
	};
	isSolvable(puzzle) ? cout << "Solvable" :
		cout << "Not Solvable";
}