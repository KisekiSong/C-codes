#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//���õ���ѭ����������׳�
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
//		Print(n / 10);//�ݹ���ã�������λ������
//	}
//
//	printf("%d ",n % 10);//ȡ���ֵ����һλ����ӡ
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

//����ѭ�����󣬰���ֵŲ��λ�ã�
int Fib(int n)
{
	int c = 0;
	int a = 1;//cosplayǰ����쳲�������
	int b = 1;

	while (n > 2)
	{
		c = a + b;
		//ͨ����ֵ��Ų�������ڱ����еĴ���ʵ��������ǰ��
		a = b;
		b = c;
		n--;//����n��ֵ
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

