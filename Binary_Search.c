#include <stdio.h>
//                 实际上上该地arr为指针（接收地址）
//int binary_search(int arr[], int k)//此时arr为4字节，所以sz计算出的值为1
int binary_search(int arr[], int k, int sz)
{
	//int sz = sizeof(arr) / sizeof(arr[0]);
	int left = 0;
	int right = sz - 1;
	
	while (left <= right)//一定为<=,否则有可能会找不到应找的的数字
	{
		int mid = (left + right) / 2;//中间元素下标
		if (arr[mid] < k)
		{
			left = mid + 1;
		}
		else if (arr[mid] > k)
		{
			left = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}
//二分查找
//找到了返回这个数的下标，没找到返回-1
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int k = 1;
	int sz = sizeof(arr) / sizeof(arr[0]);//←在自定义函数外部计算好函数个数
	//                     ↓此时该地传向自定义函数的是arr首元素的地址
	//int ret = binary_search(arr, k);//
	int ret = binary_search(arr, k, sz);
	if (ret == -1)
	{
		printf("找不到指定数字\n");
	}
	else
	{
		printf("查找成功，数字为;%d \n", ret);
	}
	return 0;
}