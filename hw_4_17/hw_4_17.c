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
//    //����ά���飬��Ȼ������20**20�Ŀռ䣬����ֻ����0~size�ķ�Χ�Ϳ�����
//    for (int i = 0; i < size; i++)
//    {
//        arr[i][loc] = '*';
//        arr[i][size - 1 - loc] = '*';
//        loc++;
//    }
//    //��ӡ�׶�
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
//    //��Ȼ˵�������size ��Χ����û��Ҫʹ�ö�̬�ڴ�
//    //��ʼ��arr���飬ȫ����ʼ��Ϊ" "
//    //��Ҫ�����ͼ���浽��ά�������棬�����ո�
//    //���ú�������ÿ�ε���֮�󣬼��Ͽո񣬷ָ�����ͬ��ͼ��
//    //��arr��ʼ��Ϊȫ�ո�Ȼ��ÿ�ε��ã�������һ�ݹ�ȥ
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
//    //����ά���飬��Ȼ������20**20�Ŀռ䣬����ֻ����0~size�ķ�Χ�Ϳ�����
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
//    //��ӡ�׶�
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
//    //ת��ǰ�ľ����С��m   *   n
//    int** row1 = (int**)calloc(arr[0], sizeof(int*));
//    for (int i = 0; i < arr[0]; i++)
//    {
//        //��rowָ��ĳ���Ϊm���ڴ棬���ָ�򳤶�Ϊn���ڴ�ĵ�ַ/ָ��
//        row1[i] = (int*)calloc(arr[1], sizeof(int));
//    }
//    //�������룺
//    for (int i = 0; i < arr[0]; i++)
//    {
//        for (int j = 0; j < arr[1]; j++)
//        {
//            scanf("%d", &row1[i][j]);
//        }
//    }
//    //����ת��
//    //����ת�ú�ľ���ռ䣺n * m
//    int** row2 = (int**)calloc(arr[1], sizeof(int*));
//    for (int i = 0; i < arr[1]; i++)
//    {
//        //��rowָ��ĳ���Ϊm���ڴ棬���ָ�򳤶�Ϊn���ڴ�ĵ�ַ/ָ��
//        row2[i] = (int*)calloc(arr[0], sizeof(int));
//        if (row2[i] == NULL) {
//            fprintf(stderr, "Memory allocation failed for row2\n");
//            return EXIT_FAILURE;
//        }
//    }
//    //��ת��ǰ�ľ���ֵ��ת�ú�ľ���
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
//    // �ͷŶ�̬������ڴ�
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
////ʹ��qsort��������
//int compare(const void* x, const void* y)
//{
//    return *(int*)x - *(int*)y;
//}
//int main() {
//    int size[2] = { 0 };
//    scanf("%d %d", &size[0], &size[1]);
//    //����ռ�
//    int* arr1 = (int*)calloc(size[0], sizeof(int));
//    int* arr2 = (int*)calloc(size[1], sizeof(int));
//    //д������
//    for (int i = 0; i < size[0]; i++)
//    {
//        scanf("%d", &arr1[i]);
//    }
//    for (int i = 0; i < size[1]; i++)
//    {
//        scanf("%d", &arr2[i]);
//    }
//    //ճ���ռ�
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

//��һ�����û������10������ƽ��ֵ
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

//������������
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