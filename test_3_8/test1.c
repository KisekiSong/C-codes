#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//利用迭代循环多次相乘求阶乘
//int Fact(int n)
//{
//	int ret = 0;
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		ret *=  i;
//	}
//	return ret;
//}
//
//
//
//void Print(int n)
//{
//	if (n > 9)
//	{
//		Print(n / 10);//递归调用，让数字位数减少
//	}
//
//	printf("%d ",n % 10);//取数字的最后一位来打印
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	Print(n);
//
//	return 0;
//}
//int Fib(int n)
//{
//	int ret = 0;
//	if (n <= 2)
//	{
//		//printf("The Fib number is 1");
//		return 1;
//	}
//	else {
//		ret = Fib(n - 1) + Fib(n - 2);
//		return ret;
//	}
//}

//利用循环来求，把数值挪动位置：
int Fib(int n)
{
	int c = 0;
	int a = 1;//cosplay前两个斐波那契数
	int b = 1;

	while (n > 2)
	{
		c = a + b;
		//通过赋值，挪动数字在变量中的次序，实现依次向前走
		a = b;
		b = c;
		n--;//更新n的值
	}
	return c;
}

int main()
{
	int n = 0;
	int ret = 0;
	printf("Please type in an integar: ");
	scanf("%d", &n);
	ret = Fib(n);
	printf("The Fib number is %d", ret);
	return 0;
}

