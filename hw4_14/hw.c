#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//int pfm = 0;
//void BBL(int* arr, int sz)
//{
//	int i = 0;
//	int mid = 0;
//	while (pfm == 0)
//	{
//		pfm = 1;
//		for (i = 0; i < sz - 1; i++)
//		{
//			if (arr[i] < arr[i + 1])
//			{
//				mid = arr[i];
//				arr[i] = arr[i + 1];
//				arr[i + 1] = mid;
//				pfm = 0;
//			}
//		}
//	}
//}
//int main()
//{
//	int arr[3] = { 0 };
//	int ret = scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
//	int i = 0;
//	BBL(arr, 3);
//	//���
//	for (i = 0; i < 3; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}

//��10�������е����ֵ
//ð������Ȼ��Ƚ����ǵ����ֵ����������
//int pfm = 0;
//void BBL(int* arr, int sz)
//{
//	int i = 0;
//	int mid = 0;
//	int j = 0;
//	while (pfm == 0)
//	{
//		pfm = 1;
//		for (i = 0; i < sz - 1-j; i++)
//		{
//			if (arr[i] < arr[i + 1])
//			{
//				mid = arr[i];
//				arr[i] = arr[i + 1];
//				arr[i + 1] = mid;
//				pfm = 0;
//			}
//		}
//		j++;
//	}
//}
//int main()
//{
//	int arr[10] = { 0 };
//	int ret = scanf("%d %d %d %d %d %d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4], \
//								&arr[5], &arr[6], &arr[7], &arr[8], &arr[9]);
//	int i = 0;
//	BBL(arr, 10);
//	//���
//	printf("Max Number = %d", arr[0]);
//
//	return 0;
//}

//�������
//�ж���ż
#define ODDOREVEN(x) ((x)%2)
//���Ϊ0�ж�Ϊż�����Ϊ1�ж�Ϊ��
//#define DEBUG 1
//int main()
//{
//	int i = 0;
//	double sum = 0;
//	for (i = 2; i <= 100; i += 2)
//	{
//		sum -= 1.0 / i;
//#ifdef DEBUG
//		printf("- 1.0 / %d\n", i);
//#endif // 
//		
//	}
//	for (i = 1; i < 100; i += 2)
//	{
//		sum += 1.0 / i;
//#ifdef DEBUG
//		printf("+ 1.0f / %d\n", i);
//#endif // 
//	}
//	printf("The result equals to %.6f", sum);
//	return 0;
//}
// 
//����ʹ��һ��ѭ��ʵ�֣���һ��sign������ʾ���ţ�ÿ��ѭ�����ı�sign������
//int main()
//{
//	double sum = 0.0;
//	int sign = 1;
//
//	for (int i = 1; i <= 100; i++)
//	{
//		sum += sign * (1.0 / i);
//		sign *= -1;
//	}
//
//	printf("Result: %.6f\n", sum);
//	return 0;
//}

//��д������һ�´� 1 �� n �������У� ���ֶ��ٸ�����9

//int count9(int n)
//{
//	int count = 0;
//	int base = 1;
//
//	while (base <= n)
//	{
//		//������259�е�9�ĸ���
//		//�����λ��λ��ʼ���ֱ����ÿһλ�ϵ�9�ĸ���
//		//��base = 1 ʱ����λΪʮλ����ǰλΪ��λ��û�е�λ
//		//higer��ʱ�������ж�����0~10����ʱ��25��0~9���ܼ�25��9
//		//Ȼ����鵱ǰλ�Ƿ�Ϊ9��current = 259 % 10 = 9������count ��+1
//		//Ȼ���base * 10����ʼ����ʮλ
//		//����ʮλ��higher��ֵ��ʾ�ж�����0~100��������2��0~100��Ҳ����90~99��190~199���ܼ�20��
//		//��鵱ǰλ�Ƿ�Ϊ9������9���ٸ�base*10�������λ
//		//��λ����û��0~1000���飬˵��û��1000���������ˡ�1-259��9�ĸ���Ϊ25+1+20=46��
//
//		int higher = n / (base * 10);
//		int current = (n / base) % 10;
//		int lower = n % base;
//
//		count += higher * base;
//		if (current == 9)
//		{
//			count += lower + 1;
//			//��λ����+1 ��ʾ��λΪ9ʱ��9�ĸ�����+1��Ҫ���ǵ���0��ʼ
//		}
//		base *= 10;
//	}
//	return count;
//}
//int main()
//{
//	int num = 0;
//	int ret = scanf("%d", &num);
//	if (ret == 1)
//	{
//		printf("The number of 9s in %d is %d", num, count9(num));
//	}
//	else
//	{
//		printf("Please type in an integar number");
//	}
//	return 0;
//}

//��ӡ1000�굽2000��֮�������
//����Ĺ���4��һ�򣬰��겻���İ�������
//int main()
//{
//	int i = 0;
//	for (int i = 1000; i <= 2000; i++)
//	{
//		if ((i % 400 == 0) || ((i % 4 == 0) && (i % 100 != 0)))
//		{
//			printf("The year %d is a Leap year\n", i);
//		}
//	}
//
//
//	return 0;
//}

//��2���������Լ��
//1.ֱ����ֵ

//int static Max_common_devisor(int x, int y)
//{
//	int i = 0;
//	int j = 0;
//	if (x >= y)
//	{
//		for (i = y; i >= 1; i--)
//		{
//			if ((x % i == 0) && (y % i == 0))
//			{
//				printf("Greatest common divisor is %d", i);
//				return i;
//			}
//		}
//	}
//	else
//	{
//		for ( j = x; j >= 1; j--)
//		{
//			if ((x % j == 0) && (y % j == 0))
//			{
//				printf("Greatese common divisor is %d", j);
//				return j;
//			}
//		}
//	}
//}
//int main()
//{
//	int x = 0;
//	int y = 0;
//	int ret = scanf("%d %d", &x, &y);
//	if (ret == 2)
//	{
//		Max_common_devisor(x, y);
//	}
//	else {
//		perror("scanf");
//		printf("Please input appropriate integars and try again!");
//
//	}
//	return 0;
//}
//2. շת������������������Լ���������н�С����������������������Լ��
//��24��18Ϊ���������������Լ�� = 18 �� ��24 % 18�������Լ��
//Ҳ����˵ = 18 �� 6 �����Լ��
//18 �� 6 �����Լ�� = 6 �� ��18 % 6�������Լ��������6
//����24��18�����Լ��Ϊ6
//int main()
//{
//	int m = 0;
//	int n = 0;
//	int tmp = 0;
//	printf("����������������");
//	scanf("%d %d", &m, &n);
//
//	while (tmp = m % n)//�������������������Ϊ0�������ѭ��
//	{
//		//���m < nҲû���⣬��m = 18 �� n = 24 Ϊ��
//		//��һ�� tmp = m % n = 18 % 24 = 18
//		//m = n = 24, n = tmp = 18, ������С�͵ߵ�������
//		m = n;//�ѽ�С������ֵ��m
//		n = tmp;//��������ֵ��n
//	}
//	printf("���Լ��Ϊ��%d\n", n);
//
//	return 0;
//}

//���9*9�˷��ھ���
//��һ�����1*1
//�ڶ������1*2 2*2
//���������1*3 2*3 3*3
//���Ĵ����1*4 2*4 3*4 4*4
//�ܹ����9�У�ÿһ�����i������һ��һ�����ڶ���2����������3����������4��...)
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d ", j, i);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//��ӡ100~200֮�������
int main()
{
	int i = 0;
	int j = 2;
	for (i = 101; i <= 200; i += 2)
	{
		while (j <= i)
		{
			j++;
			//i ������ż�������Գ�����3��ʼ
			if ((i % j == 0) && (i != j))
			{
				j = 1;
				break;
			}
			if (j == i)
			{
				printf("%d ", i);
			}
		}

		j = 1;
	}


	return 0;
}