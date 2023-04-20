#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void buble_array(int arr[], int x)
{
	int i = 0;

	for (i = 0; i < x - 1; i++)
	{
		int flag = 1;
		int j = 0;
		for (j = 0; j < x - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1]) 
			{
			    int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
}

int find_key(int arr[], int x, int y)
{
	int left = 0;
	int right = y - 1;
	int mid = (left + right) / 2;
	while (left <= right)
	{
		if (arr[mid] > arr[right])
		{
			right = mid - 1;
		}
		if (arr[mid] < arr[right])
		{
			left = mid + 1;
		}
		if (arr[mid] == x)
		{
			return 1;
		}
	}
	if (left > right)
	{
		return 0;
	}
}

int main()
{
	//冒泡排序法
	int arr1[] = { 6,5,1,10,7,9,3,4,2,8 };
	int i = 0;
	int key = 0;
	int set = 0;
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	buble_array(arr1,sz);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");
	printf("请输入要查找的数据>:\n");
	scanf("%d", &key);
	set=find_key(arr1,key,sz);
	if (set ==1)
	{
		printf("找到了，该数据是>:%d\n", key);
	}
	if(set==0)
	{
		printf("找不到该数据\n");
	}
	return 0;
}