#include <iostream>
using namespace std;

//Give two strings ,write a method to
//decide if one is a permutation of the other.
//给定两个字符串
//判断其中某个是不是另外一个字符串的全排列

bool PermutationJudge(string str1,string str2);


int main()
{
	string str1 = "abc";
	string str2 = "acb";

	if (PermutationJudge(str1,str2))
	{
		cout << "Yelp ,str1 is a permutation of str2";
	}
	else
	{
		cout << "Sorry ,str1 is not a permutation of str2";
	}

}

bool PermutationJudge(string str1, string str2)
{
	if (str1.length() != str2.length())
	{
		return false;
	}

	int letters[256];//计数法，两个字符串互为一个全排列，肯定单词出现的次数一样。

	memset(letters, 0, 256*sizeof(int));

	for (int i = 0; i < str1.length(); i++)
	{
		letters[str1.at(i)]++;
	}

	for (int i = 0; i < str2.length(); i++)
	{
		int c = (int)str2.at(i);
		if (--letters[c]<0)
		{
			return false;
		}
	}

	return true;
}	

