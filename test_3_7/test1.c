#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//求1!+2!+3!+4!+...+10!的结果
//int main()
//{
//	int n = 0;
//	int i = 0;
//	int ret = 1 ;
//	int sum = 0;
//	for (n = 1; n <= 3; n++)
//	{
//		ret = ret * n;
//		sum += ret;
//	}
//	printf("%d", sum);
//
//
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	for (i = 0; i <= 12; i++)
//	{
// 		arr[i] = 0;
//		printf("hehe\n");
//	}
//
//	return 0;
//
//}
void Print(int n)
{
	if (n > 9)
	{
		Print(n / 10);
	}
	printf("%d", n);
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	Print(n);

	return 0;
}












