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
//            //�����ǰ4λ
//            arr[j][1] = i % base;
//            //��������һλ
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
//    //�û�ָ������
//    scanf("%d", &len);
//    //����ռ�
//    int* p = (int*)malloc(sizeof(int) * len);
//    int* tmp1 = p;
//    //��������
//    for (int i = 0; i < len; i++)
//    {
//        scanf("%d", tmp1);
//        tmp1++;
//    }
//    //�û�ָ��ɾ������
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

//leetcode 1929 ���鴮��
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
//ͨ���棺ֻд�˺���
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

// ʹ��malloc����ģ�⿪��һ����ά����
// ʹ��malloc����ģ�⿪��һ�� 3*5 �����Ͷ�ά���飬���ٺú�ʹ�ö�ά������±������ʽ�����ʿռ�

//int main()
//{
//	//�ȷ�����ָ��
//	//��Ϊÿһ�з�����
//
//	//����ָ��arr��ָ����һ�γ���Ϊ3��int*�Ŀռ�
//	int** arr = (int**)malloc(sizeof(int*) * 3);
//	//��ָ���ÿһ��int�ռ����д�룬д���������һ����ַ,ÿ����ַ��ָ��һ�γ���Ϊ5��int�Ŀռ�
//	if (arr == NULL)
//	{
//		printf("�ڴ����ʧ��");
//		return 1;
//	}
//	for (int i = 0; i < 3; i++)
//	{
//		arr[i] = (int*)malloc(sizeof(int) * 5);
//		if (arr[i] == NULL)
//		{
//			printf("�ڴ����ʧ�ܣ��޷�Ϊ�� %d �з�����\n", i);
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

//ʹ�������壬дһ�������жϵ�ǰ�����洢�Ǵ�˻���С��
//����Ǵ���򷵻�0��С���򷵻�1
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
		printf("С�˴洢����λ�ڵ͵�ַ");
		return 0;
	}
		
	else
	{
		printf("��˴洢����λ���ڵ͵�ַ");
		return 1;
	}
		
}
int main()
{
	test();
}