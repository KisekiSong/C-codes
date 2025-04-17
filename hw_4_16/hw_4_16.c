#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
//int MuL_Sum(int arr[4][2])
//{
//    int sum = 0;
//    return arr[0][0] * arr[0][1] + arr[1][0] * arr[1][1] + arr[2][0] * arr[2][1] + \
//        arr[3][0] * arr[3][1];
//}
//int main() {
//    int arr[4][2] = { 0 };
//    int base = 1;
//    for (int i = 10000; i >= 10000 && i < 100000; i++)
//    {
//        for (int j = 0; j < 4; j++)
//        {
//            base *= 10;
//            arr[j][0] = i / base;
//            //拆出来前4位
//            arr[j][1] = i % base;
//            //拆出来最后一位
//        }
//        base = 1;
//        if (MuL_Sum(arr) == i)
//        {
//            printf("%d ", i);
//        }
//    }
//}

//#include<stdlib.h>
//int main() {
//    int len = 0;
//    //用户指定长度
//    scanf("%d", &len);
//    //分配空间
//    int* p = (int*)malloc(sizeof(int) * len);
//    int* tmp1 = p;
//    //存入数据
//    for (int i = 0; i < len; i++)
//    {
//        scanf("%d", tmp1);
//        tmp1++;
//    }
//    //用户指定删除内容
//    int del = 0;
//    int count = 0;
//    scanf("%d", &del);
//    for (int j = 0; j < len; j++)
//    {
//        if (p[j] == del)
//        { 
//            p[j] = 0;
//            count++;
//        }
//           
//    }
//    int* np = (int*)malloc(sizeof(int) * (len - count));
//    int* tmp2 = np;
//    for (int k = 0; k < len; k++)
//    {
//        if (p[k] != 0)
//        {
//            *tmp2 = p[k];
//            tmp2++;
//        }
//
//    }
//    for (int l = 0; l < len - count; l++)
//    {
//        printf("%d ", np[l]);
//    }
//	  free(np);
//	  np = NULL;
//    tmp2 = NULL;
//	  free(p);
//	  p = NULL;
//    tmp1 = NULL;
//    return 0;
//}

//leetcode 1929 数组串联
//#include<stdlib.h>
//int* get_Concatenation(int* nums, int* returnSize, int length)
//{
//
//	for (int i = 0; i < length; i++)
//	{
//		returnSize[i] = nums[i];
//		returnSize[length + i] = nums[i];
//	}
//	return returnSize;
//
//}
//int main()
//{
//	int len = 0;
//	printf("Please type in the array length: ");
//	scanf("%d", &len);
//	printf("nums = ");
//	int* p1 = (int*)malloc(sizeof(int) * len);
//	int* p2 = (int*)malloc(sizeof(int) * 2 * len);
//	//input array
//
//	for (int j = 0; j < len; j++)
//	{
//		scanf("%d", &p1[j]);
//	}
//
//	int* tmp = get_Concatenation(p1, p2, len);
//	//output
//	printf("ans = ");
//	for (int i = 0; i < 2 * len; i++)
//	{
//		printf("%d,", tmp[i]);
//
//	}
//
//	free(p1);
//	free(p2);
//	p1 = NULL;
//	p2 = NULL;
//	tmp = NULL;
//
//	return 0;
//
//}
//通过版：只写了函数
//int* getConcatenation(int* nums, int numsSize, int* returnSize) {
//    int* ret = (int*)malloc(sizeof(int) * 2 * numsSize);
//    memset(ret, 0, sizeof(int) * numsSize * 2);
//
//    memcpy(ret, nums, sizeof(int) * numsSize);
//    memcpy(ret + numsSize, nums, sizeof(int) * numsSize);
//
//    *returnSize = numsSize * 2;
//    return ret;
//}

// 使用malloc函数模拟开辟一个二维数组
// 使用malloc函数模拟开辟一个 3*5 的整型二维数组，开辟好后，使用二维数组的下标访问形式，访问空间

//int main()
//{
//	//先分配行指针
//	//再为每一行分配列
//
//	//二级指针arr，指向了一段长度为3个int*的空间
//	int** arr = (int**)malloc(sizeof(int*) * 3);
//	//对指向的每一个int空间进行写入，写入的内容是一个地址,每个地址都指向一段长度为5个int的空间
//	if (arr == NULL)
//	{
//		printf("内存分配失败");
//		return 1;
//	}
//	for (int i = 0; i < 3; i++)
//	{
//		arr[i] = (int*)malloc(sizeof(int) * 5);
//		if (arr[i] == NULL)
//		{
//			printf("内存分配失败！无法为第 %d 行分配列\n", i);
//			for (int j = 0; j < i; j++)
//			{
//				free(arr[j]);
//			}
//			free(arr);
//			return 1;
//		}
//	}
//
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			arr[i][j] = 114;
//		}
//	}
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	for (int i = 0; i < 3; i++)
//	{
//		free(arr[i]);
//	}
//
//	free(arr);
//	arr = NULL;
//
//	return 0;
//}

//使用联合体，写一个函数判断当前机器存储是大端还是小端
//如果是大端则返回0，小端则返回1
union Un1
{
	char c;
	int i;
};

int test()
{
	union Un1 s = { 0 };
	s.i = 1;
	if (s.c == 1)
	{
		printf("小端存储，低位在低地址");
		return 0;
	}
		
	else
	{
		printf("大端存储，低位不在低地址");
		return 1;
	}
		
}
int main()
{
	test();
}