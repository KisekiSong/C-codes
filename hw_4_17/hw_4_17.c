#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//void printX(int size)
//{
//    char arr[20][20] = { "0" };
//    int loc = 0;
//    for (int i = 0; i < 20; i++)
//    {
//        for (int j = 0; j < 20; j++)
//        {
//            arr[i][j] = ' ';
//        }
//    }
//
//    //填充二维数组，虽然申请了20**20的空间，但是只考虑0~size的范围就可以了
//    for (int i = 0; i < size; i++)
//    {
//        arr[i][loc] = '*';
//        arr[i][size - 1 - loc] = '*';
//        loc++;
//    }
//    //打印阶段
//    for (int i = 0; i < size; i++)
//    {
//        for (int j = 0; j < size; j++)
//        {
//            printf("%c", arr[i][j]);
//        }
//        printf("\n");
//    }
//}
//
//int main() {
//
//    int size[17] = { 0 };
//
//    printf("Please input a number in the range of 3~20: ");
//    for (int i = 0; scanf("%d", &size[i]) != EOF && i < 17; i++)
//    {
//        printf("Please input a number in the range of 3~20: ");
//    }
//
//    //既然说了输入的size 范围，就没必要使用动态内存
//    //初始化arr数组，全部初始化为" "
//    //把要输出的图案存到二维数组里面，包括空格
//    //调用函数并给每次调用之后，加上空格，分隔开不同的图案
//    //给arr初始化为全空格，然后每次调用，都复制一份过去
//
//    for (int i = 0; i < 17; i++)
//    {
//        printX(size[i]);
//        printf("\n");
//    }
//
//
//    return 0;
//}

//#define SIZE 128
//void printSquare(int size)
//{
//    char arr[SIZE][SIZE] = { "0" };
//    int loc = 0;
//    for (int i = 0; i < SIZE; i++)
//    {
//        for (int j = 0; j < SIZE; j++)
//        {
//            arr[i][j] = ' ';
//        }
//    }
//    //填充二维数组，虽然申请了20**20的空间，但是只考虑0~size的范围就可以了
//
//    for (int i = 0; i < size; i++)
//    {
//        loc = 0;
//        if (i == 0 || i == size - 1)
//        {
//            for (int j = 0; j < size; j++)
//            {
//                arr[i][loc] = '*';
//                loc += 2;
//            }
//            loc = 0;
//        }
//        else
//        {
//            arr[i][0] = '*';
//            arr[i][2 * size - 2] = '*';
//        }
//    }
//
//    //打印阶段
//
//    for (int i = 0; i < size; i++)
//    {
//        for (int j = 0; j < 2 * size - 1; j++)
//        {
//            printf("%c", arr[i][j]);
//        }
//        printf("\n");
//    }
//}
//
//int main() {
//    int size = 0;
//    //printf("Please input a number in the range of 3~20: ");
//    while (scanf("%d", &size) != EOF)
//    {
//        printSquare(size);
//    }
//    return 0;
//
//}
//#include<stdlib.h>
//#define __DEBUG__
//int main() {
//    int arr[2] = { 0 };
//    scanf("%d %d", &arr[0], &arr[1]);
//    //转置前的矩阵大小：m   *   n
//    int** row1 = (int**)calloc(arr[0], sizeof(int*));
//    for (int i = 0; i < arr[0]; i++)
//    {
//        //给row指向的长度为m的内存，存放指向长度为n的内存的地址/指针
//        row1[i] = (int*)calloc(arr[1], sizeof(int));
//    }
//    //接受输入：
//    for (int i = 0; i < arr[0]; i++)
//    {
//        for (int j = 0; j < arr[1]; j++)
//        {
//            scanf("%d", &row1[i][j]);
//        }
//    }
//    //进行转置
//    //分配转置后的矩阵空间：n * m
//    int** row2 = (int**)calloc(arr[1], sizeof(int*));
//    for (int i = 0; i < arr[1]; i++)
//    {
//        //给row指向的长度为m的内存，存放指向长度为n的内存的地址/指针
//        row2[i] = (int*)calloc(arr[0], sizeof(int));
//        if (row2[i] == NULL) {
//            fprintf(stderr, "Memory allocation failed for row2\n");
//            return EXIT_FAILURE;
//        }
//    }
//    //将转置前的矩阵赋值给转置后的矩阵
//    for (int i = 0; i < arr[0]; i++)
//    {
//        for (int j = 0; j < arr[1]; j++)
//        {
//            row2[j][i] = row1[i][j];
//        }
//    }
//
//#ifdef __DEBUG__
//        for (int i = 0; i < arr[1]; i++)
//        {
//            for (int j = 0; j < arr[0]; j++)
//            {
//                printf("%d ", row2[i][j]);
//            }
//            printf("\n");
//        }
//#endif
//    // 释放动态分配的内存
//    for (int i = 0; i < arr[0]; i++) {
//        free(row1[i]);
//    }
//    free(row1);
//    row1 = NULL;
//
//    for (int i = 0; i < arr[1]; i++) {
//        free(row2[i]);
//    }
//    free(row2);
//    row2 = NULL;
//    return 0;
//}

//#include <stdio.h>
//#include<stdlib.h>
////使用qsort快速排序：
//int compare(const void* x, const void* y)
//{
//    return *(int*)x - *(int*)y;
//}
//int main() {
//    int size[2] = { 0 };
//    scanf("%d %d", &size[0], &size[1]);
//    //分配空间
//    int* arr1 = (int*)calloc(size[0], sizeof(int));
//    int* arr2 = (int*)calloc(size[1], sizeof(int));
//    //写入数据
//    for (int i = 0; i < size[0]; i++)
//    {
//        scanf("%d", &arr1[i]);
//    }
//    for (int i = 0; i < size[1]; i++)
//    {
//        scanf("%d", &arr2[i]);
//    }
//    //粘贴空间
//    int* arr3 = (int*)calloc(size[0] + size[1], sizeof(int));
//    memcpy(arr3, arr1, sizeof(int) * size[0]);
//    memcpy(arr3 + size[0], arr2, sizeof(int) * size[1]);
//    qsort(arr3, size[0] + size[1], sizeof(int), compare);
//    for (int i = 0; i < size[0] + size[1]; i++)
//    {
//        printf("%d ", arr3[i]);
//    }
//
//    return 0;
//}

//求一组由用户输入的10个数的平均值
//#define LEN 10
//float avg(int* arr, int len)
//{	
//	int sum = 0;
//	for (int i = 0; i < len; i++)
//	{
//		sum += arr[i];
//	}
//	return (float)sum / len;
//}
//int main()
//{
//	int arr[10] = { 0 };
//	for (int i = 0; i < 10 && scanf("%d", &arr[i]) != EOF; i++)
//	{
//		;
//	}
//	printf("%f",avg(arr, LEN));
//
//	return 0;
//}

//交换数组内容
#include<stdlib.h>
void exarr(int* arr1, int* arr2, size_t len)
{
	int* tmp = (int*)calloc(len, sizeof(int));
	memcpy(tmp, arr1, len * sizeof(int));
	memcpy(arr1, arr2, len * sizeof(int));
	memcpy(arr2, tmp, len * sizeof(int));
	free(tmp);
	tmp = NULL;
}
int main()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 2,3,4,5,6 };
	size_t size = sizeof(arr1) / sizeof(int);
	printf("arr1 = {");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("}\n");
	printf("arr2 = {");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr2[i]);
	}
	printf("}\n");
	exarr(arr1, arr2, size);
	printf("arr1 = {");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("}\n");
	printf("arr2 = {");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr2[i]);
	}
	printf("}\n");
	return 0;
}