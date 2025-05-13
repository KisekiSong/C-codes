#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//void arr_print(const int* arr, int num)
//{
//	for (int i = 0; i < num; i++)
//	{
//		printf("%d\n", *(arr + i));
//	}
//}
//int main()
//{
//	int arr1[10] = { 1,1,4,5,1,4,1,9,1,9 };
//	arr_print(arr1, sizeof(arr1) / sizeof(arr1[0]));
//
//	return 0;
//}

//void bubble_SWAP(int* arr)
//{
//	char* ptr = (char*)arr;
//	char tmp = 0;
//	for (int i = 0; i < 4; i++)
//	{
//		tmp = *ptr;
//		*ptr = *(ptr + 4);
//		*(ptr + 4) = tmp;
//		ptr++;
//	}
//}
//
////冒泡排序
////分为比较和交换两个部分，交换使用char* 指针进行地址操作，逐步完成
////每次交换都要调用交换函数
//
//void bubble_sort(int* arr, int num)
//{
//	int* ptr = arr;
//	int cur = 0;
//	for (int i = 1; i < num; i++)
//	{
//		for (int j = 0; j < num - i; j++)
//		{
//			if (*ptr > *(ptr + 1))
//			{
//				bubble_SWAP(ptr);
//			}
//			ptr++;
//		}
//		ptr = arr;
//	}
//}
//
//int main()
//{
//	int arr1[10] = { 9,8,7,6,5,4,3,2,1,0 };
//	int num = sizeof(arr1) / sizeof(arr1[0]);
//	bubble_sort(arr1, num);
//	for (int i = 0; i < num; i++)
//	{
//		printf("%d\n", arr1[i]);
//	}
//	return 0;
//}

//#include<string.h>
//#include<stdlib.h>
//
//int is_rotated(const char* s1, const char* s2)
//{
//	//首先检测两个字符串的长度是否相等：
//	if (strlen(s1) != strlen(s2))
//	{
//		printf("不是旋转字符串关系");
//		return 0;
//	}
//	else
//	{
//		char* combined = (char*)malloc(2 * sizeof(char) + 1);
//		if (combined == NULL)
//		{
//			perror(malloc);
//			return 0;
//		}
//		strcpy(combined, s1);
//		strcat(combined, s1);
//
//		int result = (strstr(combined, s2) != NULL);
//		if (result)
//		{
//			printf("是字符串旋转关系");
//		}
//		return result;
//	}
//}
//
//int main()
//{
//	const char* s1 = "AABCD";
//	const char* s2 = "BCDAA";
//
//	is_rotated(s1, s2);
//
//	return 0;
//}

//杨氏矩阵
//矩阵从左到用递增，从上到下递增，编写程序在这样的矩阵中查找某个数字是否存在
