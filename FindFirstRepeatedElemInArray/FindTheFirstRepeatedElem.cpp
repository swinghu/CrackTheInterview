
//Find the first repeating element in an array of integers

# include <stdio.h>

# include<malloc.h>

int FindFirstRepeatedElem(int arr[], int n);

int main()
{
	int arr[8] = {5,12,2,3,5,6,7,6};
	int result = FindFirstRepeatedElem(arr,8);
	printf("%d", arr[result]);
}

int FindFirstRepeatedElem(int arr[],int n)
{	
	int max = -1;
	for (int i = 0; i < n; i++)
	{
		if (arr[i]> max)
		{
			max = arr[i];
		}
	}

	int* token  = (int *)malloc((max+1) * sizeof(int));//×¢Òâmax+1

	for (int i = 0; i < max+1; i++){
		token[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		if (token[arr[i]] != 0)
		{
			return i;
		}
		else 
		{
			token[arr[i]]++;
		}
	}
	return -1;

}