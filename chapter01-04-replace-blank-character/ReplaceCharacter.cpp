#include <iostream>
using namespace std;

// Write a method to replace all spaces in a string with '%20'.You
// may assume that the string has sufficient space at the end of the 
// string to hold the additional characters,and that you are given the 
// "true" length of the string .(Note :if implementing in Java,Please 
// use character array so that you can perform this operation in place

void replaceSpaces(char chArray[], int length);

int main()
{
	char chAarry[256] = "baidu user ffl swing hu ";

	replaceSpaces(chAarry,strlen(chAarry));

	cout << "Replace the blank character with '%20'"<<endl;
	cout << "the repalce String is :";
	cout << chAarry << endl;
}

void replaceSpaces(char chArray[], int length)
{
	int spaceCount = 0;
	int newLength = 0;

	for (int i = 0; i < length; i++)
	{
		if (chArray[i] == ' ')
		{ 
			spaceCount++;
		}
	}

	newLength = length + 2 * spaceCount;

	chArray[newLength] = '\0';

	for (int i = length - 1; i > 0; i--)
	{
		if (chArray[i] == ' ')
		{
			chArray[newLength - 1] = '0';
			chArray[newLength - 2] = '2';
			chArray[newLength - 3] = '%';
			newLength = newLength - 3;
		}
		else
		{
			chArray[newLength - 1] = chArray[i];
			newLength = newLength--;
		}
	}
}