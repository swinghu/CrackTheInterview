#include<iostream>
using namespace std;

//8 PUZZLE PROBLEM
//将3*3的二维数组转换成一维数组，如果逆序数为偶数可以解决的，
//为奇数，不可解决

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
	int puzzle[3][3] = {
			{1,8,2,},
			{0,4,3,},
			{7,6,5}
	};
	*/
	int puzzle[3][3] = {
			{8,1,2},
			{0,4,3},
			{7,6,5}
	};
	isSolvable(puzzle) ? cout << "Solvable" :
		cout << "Not Solvable";
}