#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//int Cal_FB(int num)
//{
//	int arr[3] = { 0,1,1 };
//	int tmp = 0;
//	for (int i = 0; i < num-1; i++)
//	{
//		arr[2] = arr[0] + arr[1];
//		arr[0] = arr[1];
//		arr[1] = arr[2];
//		//printf("%d\n", arr[2]);
//	}
//	return arr[2];
//}
//#include<stdio.h>
//#include<stdlib.h>
//int fibonacci_simple(int n)
//{
//	if (n <= 1)
//	{
//		return n;
//	}
//	//���ݶ����ֱ��д��
//	return fibonacci_simple(n - 1) + fibonacci_simple(n - 2);
//}
//
//int fibonacci_memo(int n, int* memo)
//{
//	if (memo[n] != -1)
//	{
//		return memo[n];
//	}
//	if (n <= 1)
//	{
//		memo[n] = n;
//		return n;
//	}
//	//�ݹ�ķ�ʽ�ظ������Լ���ֱ��n<=1��Ȼ������������
//	memo[n] = fibonacci_memo(n - 1, memo) + fibonacci_memo(n - 2, memo);
//	return memo[n];
//}
//
//int fibonacci(int n)
//{
//	//�㵽�ڼ������ʹ������Ŀռ䣬���������������㣬�����ظ���3ǰ������Ȼ��������õ�������
//	//����ֱ�Ӷ�ȡǰ��������Ӽ��ɵõ�������
//	int* memo = (int*)malloc((n + 1) * sizeof(int));
//	//��ʼ����������Ϊ-1����ʾ��δ���м���
//	for (int i = 0; i <= n; i++)
//	{
//		memo[i] = -1;
//	}
//	int result = fibonacci_memo(n, memo);
//	//���ü��㺯��������memo�����׵�ַ
//	free(memo);
//	//�ͷ��ڴ棬��ֹջ���
//	return result;
//}
//
//int main()
//{
//	int num1 = 5;
//	printf("The %dth FB number is %d\n", num1, fibonacci(num1));
//
//	int num2 = 10;
//	printf("The %dth FB number is %d\n", num2, fibonacci(num2));
//
//	int num3 = 2;
//	printf("The %dth FB number is %d\n", num3, fibonacci(num3));
//
//	return 0;
//}

//��дһ������ʵ��n��k�η���ʹ�õݹ�ʵ��
//#include<stdio.h>
//int cal_n_to_k(int n, int k)
//{
//	if (k <= 1)
//	{
//		return n;
//	}
//	else {
//		k--;
//	}
//	return n * cal_n_to_k(n, k);
//}
//int main()
//{
//	int num = 5;
//	int poly = 3;
//	printf("%d �� %d �η� = %d", num, poly, cal_n_to_k(num, poly));
//	return 0;
//}

//дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮��
//���磺����DigitSum(1729)����Ӧ�÷���1+7+2+9�����ĺ�Ϊ19
//int DigitSum(int n)
//{
//	if ((n / 10) == 0 && n < 10)
//	{
//		return n % 10;
//	}
//	else {
//		return (n % 10) + DigitSum(n / 10);
//	}
//}
//int main()
//{
//	int testnum = 1729;
//	printf("���룺%d   �����%d", testnum, DigitSum(testnum));
//
//	return 0;
//}

////�ݹ���׳�
//int factorail_rec(int n)
//{
//	if (n <= 1)
//	{
//		return 1;
//	}
//	else {
//		return n * factorail_rec(n - 1);
//	}
//}
//int factorial_nonrec(int n)
//{
//	int ret = 1;
//	for (int i = n; i > 0; i--)
//	{
//		ret *= i;
//	}
//	return ret;
//}
//#include<stdio.h>
//int main()
//{
//	int testnum = 5;
//	printf("the factorial of %d with recursive method is %d\n", testnum, factorail_rec(testnum));
//	printf("the factorial of %d with nonrecursive method is %d\n", testnum, factorial_nonrec(testnum));
//	return 0;
//}

//��ӡһ������ÿһλ---�ݹ�
//#include<stdio.h>
//int DigitPrint_Reverse(int n)
//{
//	if ((n / 10) == 0 && n < 10)
//	{
//		printf("%d\n", n);
//		return n % 10;
//	}
//	else {
//		printf("%d\n", n % 10);
//		return DigitPrint_Reverse(n / 10);
//	}
//}
//int DigitPrint_Order(int n)
//{
//	if (n < 10)
//	{
//		printf("%d\n", n);
//		return;
//	}
//	DigitPrint_Order(n / 10);
//	printf("%d\n", n % 10);
//}
//
//
//int main()
//{
//	int n = 1729;
//	DigitPrint_Order(n);
//	printf("---------------\n");
//	DigitPrint_Reverse(n);
//	return 0;
//}
