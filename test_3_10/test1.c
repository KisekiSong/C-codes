#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//练习：求出一个数字的原码有多少个1
// 方法一：针对二进制的特性，对数字持续性地进行/2运算，如果为1说明该位为1
//int bit_count(unsigned int n)//这里要考虑到负数的补码在计算机中的存储
//{
//	int count = 0;
//	while (n)
//	{
//		if (n % 2 == 1)
//		{
//			count++;
//			
//		}
//		n = n / 2;
//
//	}
//	return count;
//}

//方法二：使用移位操作符，与1进行与运算
// 会统计每一位，效率偏低
//int bit_count(int n)
//{
//	int i = 0;
//	int count = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if ((n >> i) & 1 == 1)//每次将n右移i位，与1进行与运算，如果为1说明该位为1，count++
//		{
//			count++;
//		}
//	}
//	return count;
//}

//方法三：Brain Kernighan算法
//int bit_count(int n)
//{
//	int count = 0;
//	while (n)
//	{
//		n = n & (n - 1);//每次减一，会消除掉二进制最右边的1，执行到最后就会变成0，
//		                //统计了次数，就能得到总共的1的个数
//		count++;
//	}
//
//
//}

//int main()
//{
//	int num = 0;
//	int count = 0;
//	printf("Please input a number: ");
//	scanf("%d", &num);
//	count = bit_count(num);
//	printf("The '1's in that number is: %d", count);
//	return 0;
//}



//练习二：利用位操作，将整数13二进制序列的第5位修改为1，然后再改成0
int main()
{
	int a = 13;
	int n = 0;
	printf("Please type in the position you wish to change: ");
	scanf("%d", &n);
	//00000000000000000000000000001101
	//00000000000000000000000000010000 把第五位设置成1，其他都为0，然后和13的补码进行或运算，第5位就变成1
	a = a | (1 << (n - 1));
	printf("Now a = %d\n", a);

	//变回来：
	//00000000000000000000000000011101
	//11111111111111111111111111101111 用一个除了第五位都是1的序列，和变化后的数字进行与预算，只改动了第五位
	//该序列由00000000000000000000000000010000取反得到，取反由操作符 ~ 表示
	a &= ~(a << (n - 1));
	printf("Now a = %d\n", a);

	return 0;
}