#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int a[] = { 1,2,3,4 };
	printf("sizeof(a)=%d\n", sizeof(a));//4*4=16
	printf("sizeof(a+0)=%d\n", sizeof(a+0));//a 这里是地址 8
	printf("sizeof(*a)=%d\n", sizeof(*a));//a 这里是地址 8
	printf("sizeof(a+1)=%d\n", sizeof(a+1));//a 这里是地址 8
	printf("sizeof(a[1])=%d\n", sizeof(a[1]));//4 a这里是数组，a[1]是数组中的元素
	printf("sizeof(&a)=%d\n", sizeof(&a));//a 这里是地址
	printf("sizeof(*&a)=%d\n", sizeof(*&a));//a 这里是数组 16
	printf("sizeof(&a+1)=%d\n", sizeof(&a+1));//a 这里是地址
	printf("sizeof(&a[0])=%d\n", sizeof(&a[0]));//这里是地址 
	printf("sizeof(&a[0]+1=%d\n", sizeof(&a[0]+1));//same



	return 0;
}