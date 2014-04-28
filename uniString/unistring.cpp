/*
 *判断一个字符串所有字符是否唯一
 *不使用其他数据结构
*/

#include<stdio.h>
#include<string>
bool unique_string(char* src_str, size_t len);

int main()
{
	char* teststr = "adbseriumxyz";
	//size_t len = sizeof(teststr);//len = 4
	size_t len = strlen(teststr);
	bool res = unique_string(teststr, len);
	if (true == res)
	{
		printf("the string is unique\n");
	}
	else
	{
		printf("the string is not unique\n");
	}
	return 0;
}

bool unique_string(char* src_str,size_t len)
{
	if (src_str == NULL)
		return false;

	bool test[256];
	for (int i = 0; i < 256; i++){
		test[i] = false;
 	}
	char dupStr = NULL;
	for (size_t i = 0; i < len; i++)
	{
		if (test[src_str[i]]==true)
		{			
			dupStr = src_str[i];
			printf("the duplicate string is %c\n", dupStr);
			return false;
		}
		else
		{
			test[src_str[i]] = true;
		}
	}
	return true;
}