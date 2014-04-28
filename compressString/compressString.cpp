/*
	compress a string aabbcccdf to a2b2c3d1f1;
*/


#include <iostream>
#include<string>
using namespace std;

string compressStr(char* src_str);

int main()
{
	char src_str[] = "aabbcccdffffSSSSSSSsss";
	string dest = compressStr(src_str);
	cout << dest<<endl;
	printf("the dest is %c ", dest);
}

string compressStr(char* src_str)
{
	if (src_str == NULL)
	{
		return NULL;
	}
	char cur = *src_str;

	string last;
	last = last+ cur;
	int count = 1;

	for (int i = 1; i < strlen(src_str); i++)
	{
		if (src_str[i] == cur)
		{
			count++;
		}
		else
		{			
			char countStr[10];
			memset(countStr, 0, sizeof(countStr));
			_itoa_s(count,countStr,sizeof(count),10);
			last += countStr;
			last = last + src_str[i];
			cur = src_str[i];
			count = 1;
		}
	}
	char countStr[10];	
	memset(countStr, 0, sizeof(countStr));
	_itoa_s(count, countStr,sizeof(count), 10);
	last = last + countStr;
	return last;
}