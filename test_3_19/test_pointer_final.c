#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int a[] = { 1,2,3,4 };
	printf("sizeof(a)=%d\n", sizeof(a));//4*4=16
	printf("sizeof(a+0)=%d\n", sizeof(a+0));//a �����ǵ�ַ 8
	printf("sizeof(*a)=%d\n", sizeof(*a));//a �����ǵ�ַ 8
	printf("sizeof(a+1)=%d\n", sizeof(a+1));//a �����ǵ�ַ 8
	printf("sizeof(a[1])=%d\n", sizeof(a[1]));//4 a���������飬a[1]�������е�Ԫ��
	printf("sizeof(&a)=%d\n", sizeof(&a));//a �����ǵ�ַ
	printf("sizeof(*&a)=%d\n", sizeof(*&a));//a ���������� 16
	printf("sizeof(&a+1)=%d\n", sizeof(&a+1));//a �����ǵ�ַ
	printf("sizeof(&a[0])=%d\n", sizeof(&a[0]));//�����ǵ�ַ 
	printf("sizeof(&a[0]+1=%d\n", sizeof(&a[0]+1));//same



	return 0;
}