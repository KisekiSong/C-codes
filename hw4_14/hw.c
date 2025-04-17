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
//	//输出
//	for (i = 0; i < 3; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}

//求10个整数中的最大值
//冒泡排序，然后比较它们的最大值，返回最大的
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
//	//输出
//	printf("Max Number = %d", arr[0]);
//
//	return 0;
//}

//分数求和
//判断奇偶
#define ODDOREVEN(x) ((x)%2)
//如果为0判断为偶，如果为1判断为奇
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
//可以使用一个循环实现，用一个sign变量表示符号，每次循环最后改变sign的正负
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

//编写程序数一下从 1 到 n 的整数中， 出现多少个数字9

//int count9(int n)
//{
//	int count = 0;
//	int base = 1;
//
//	while (base <= n)
//	{
//		//假设求259中的9的个数
//		//从最低位个位开始，分别计算每一位上的9的个数
//		//当base = 1 时，高位为十位，当前位为个位，没有低位
//		//higer这时代表了有多少组0~10，这时有25组0~9，总计25个9
//		//然后检验当前位是否为9，current = 259 % 10 = 9，所以count 再+1
//		//然后给base * 10，开始考虑十位
//		//对于十位，higher的值表示有多少组0~100，这里有2组0~100，也就是90~99，190~199，总计20个
//		//检查当前位是否为9，不是9，再给base*10，进入百位
//		//百位发现没有0~1000的组，说明没到1000，不用算了。1-259中9的个数为25+1+20=46个
//
//		int higher = n / (base * 10);
//		int current = (n / base) % 10;
//		int lower = n % base;
//
//		count += higher * base;
//		if (current == 9)
//		{
//			count += lower + 1;
//			//低位数字+1 表示高位为9时的9的个数，+1是要考虑到从0开始
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

//打印1000年到2000年之间的闰年
//闰年的规则：4年一闰，百年不闰，四百年再闰
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

//求2个数的最大公约数
//1.直接求值

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
//2. 辗转相除法：两个数的最大公约数等于其中较小的数和两数相除余数的最大公约数
//以24和18为例，这两数的最大公约数 = 18 与 （24 % 18）的最大公约数
//也就是说 = 18 与 6 的最大公约数
//18 与 6 的最大公约数 = 6 与 （18 % 6）的最大公约数，就是6
//所以24与18的最大公约数为6
//int main()
//{
//	int m = 0;
//	int n = 0;
//	int tmp = 0;
//	printf("请输入两个整数：");
//	scanf("%d %d", &m, &n);
//
//	while (tmp = m % n)//计算余数，如果余数不为0，则继续循环
//	{
//		//如果m < n也没问题，以m = 18 和 n = 24 为例
//		//第一步 tmp = m % n = 18 % 24 = 18
//		//m = n = 24, n = tmp = 18, 这样大小就颠倒过来了
//		m = n;//把较小的数赋值给m
//		n = tmp;//把余数赋值给n
//	}
//	printf("最大公约数为：%d\n", n);
//
//	return 0;
//}

//输出9*9乘法口诀表
//第一次输出1*1
//第二次输出1*2 2*2
//第三次输出1*3 2*3 3*3
//第四次输出1*4 2*4 3*4 4*4
//总共输出9行，每一行输出i个（第一行一个，第二行2个，第三行3个，第四行4个...)
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

//打印100~200之间的素数
int main()
{
	int i = 0;
	int j = 2;
	for (i = 101; i <= 200; i += 2)
	{
		while (j <= i)
		{
			j++;
			//i 不会是偶数，所以除数从3开始
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