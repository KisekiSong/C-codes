#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
//第一版：能实现功能，但是指针p的功能偏弱
int pfm = 0;
void BBL(int* arr, int sz)
{
	//冒泡排序：从数组第一个元素开始，相邻元素两两比较，如果左侧大于右侧，则二者交换位置
	//直到交换位置操作不再执行，说明执行完毕
	//使用一个指针
	int i = 0;
	int mid = 0;
	while (pfm == 0) 
	{
		//用一个全局变量pfm作为标志，在while循环内，pfm先被赋1，如果发生了位置交换，就把pfm置为0，说明排序还在进行
		//如果走完整个数组下来，pfm的值没被赋0，则跳出while循环，排序结束
		pfm = 1;
		for (i = 0; i < sz - 1; i++)
		{

			if (arr[i] > arr[i + 1])
			{
				//交换位置
				mid = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = mid;
				pfm = 0;
			}
		}
	}

}






int main()
{
	int arr[10] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	printf("Please type in a integar sery: ");
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		scanf("%d", &arr[i]);
	}
	//调用冒泡排序函数，传入数组名和数组大小
	BBL(arr, sz);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}