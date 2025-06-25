//#define _CRT_SECURE_NO_WARNINGS
////找单身狗1
////在一个整型数组中，只有一个数字出现一次，其他数组都是成对出现的，请找出那个只出现一次的数字。
////例如：
////数组中有：1 2 3 4 5 1 2 3 4，只有5出现一次，其他数字都出现2次，找出5
////整个数组组内异或，最后就剩下只出现1次的数字
////异或：相同为0，与0异或的数后结果为其本身
//#include<stdio.h>
//int find_single_num(int* arr, int len)
//{
//	int ret = 0;
//	for (int i = 0; i < len; i++)
//	{
//		ret ^= arr[i];
//	}
//	return ret;
//}
//int main()
//{
//	int arr[9] = { 1,2,3,4,5,1,2,3,4 };
//	printf("The single number is: %d", find_single_num(arr,sizeof(arr)/sizeof(int)));
//	return 0;
//}


////交换两个变量，但不创建临时变量
////使用位操作：异或
//#include<stdio.h>
//int main()
//{
//	//使用异或交换变量
//	int a = 114;
//	int b = 514;
//	printf("Before a = %d, b = %d\n", a, b);
//	a = a ^ b;
//	b = a ^ b;//b = a^b^b = a ^ 0 = a
//	a = a ^ b;//a = a^b^a = b ^ 0 = b
//	printf("Switched a = %d, b = %d", a, b);
//}



//统计二进制中1的个数
//输出该数32位二进制表示中1的个数，其中负数用补码表示
//位运算：无符号右移法
//int NumberOf1(int n) {
//    int flag = 0x0001;
//    int i = 0;
//    int iNum = 0;
//    for (i = 0; i < 32; i++)
//    {
//        iNum += (n & flag);
//        n = n >> 1;
//    }
//    return iNum;
//}
////-1自相与法：消掉1
//
//int NumberOf1(int n) {
//    int iNum = 0;
//    while (n)
//    {
//        iNum++;
//        n = n & (n - 1);
//    }
//    return iNum;
//}
//
//打印整数二进制的奇数位和偶数位
//使用右移，假设负数用补码表示，这样直接使用右移就可以了
//对于偶数位，从第0位开始，，每次向右移2个位，与1，如果为真，则打印1，反之打印0
//对于奇数位，先右移1位，与1，然后向右移2个位，与1，同上
//#include<stdio.h>
//int print_binary_digits(const int num)
//{
//	int ret = num;
//	int andNum = 0x0001;
//	int count = 0;
//	//判断奇数还是偶数
//
//	//打印奇数，先右移一位
//	ret = ret >> 1;
//	printf("Print odd digits:\n");
//	for (int i = 0; i < 16; i++)
//	{
//		printf("%d", ret & andNum);
//		ret = ret >> 2;
//	}
//	//打印偶数
//	ret = num;
//	printf("\nPrint even digits:\n");
//	for (int i = 0; i < 16; i++)
//	{
//		printf("%d", ret & andNum);
//		ret = ret >> 2;
//	}
//	return 0;
//}
//
//int main()
//{
//	int testNum = 14;
//	print_binary_digits(testNum);
//	return 0;
//}

//2个数二进制中不同位的个数
//for循环，每次看最后一位，不同则给count+1
//#include<stdio.h>
//int diff_digits_count(int x, int y)
//{
//	int count = 0;
//	int TNUM = 1;
//	for (int i = 0; i < 32; i++)
//	{
//		if ((x & TNUM) ^ (y & TNUM)) 
//		{
//			count++;
//		}
//		x = x >> 1;
//		y = y >> 1;
//	}
//	return count;
//}
//int main()
//{
//	int num1 = 1999;
//	int num2 = 2299;
//	printf("The inputs are: %d %d\n", num1, num2);
//	printf("The number of different digits is: %d", diff_digits_count(num1, num2));
//}

//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以喝多少汽水（编程实现）。
//#include<stdio.h>
//int bottle_and_bottlecap(int money)
//{
//	int bottle_num = money;
//	int new_bottle_num = money;
//	int bottlecap_num = 0;
//	while (new_bottle_num != 0)
//	{
//		//瓶盖数量=瓶子数量
//		bottlecap_num = new_bottle_num;
//		//现在瓶盖 = 瓶子 = 20
//		bottle_num += bottlecap_num / 2;
//		//瓶子 = 20+20/2 = 30
//		new_bottle_num = bottlecap_num /2;
//	}
//	return bottle_num;
//}
//
//int main()
//{
//	int money = 20;
//	printf("With %d$, we can have %d bottles of coke", money, bottle_and_bottlecap(money));
//}

//输出菱形图案：第一行1个*，第二行3个*，第7行13个*，第8行9个*，...，最后一行1个*
//#include<stdio.h>
//void print_pattern(int ttl_len, int n)
//{
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		printf(" ");
//	}
//	for (i = 0; i < ttl_len - 2 * n; i++)
//	{
//		printf("*");
//	}
//	for (i = 0; i < n; i++)
//	{
//		printf(" ");
//	}
//	printf("\n");
//}
//int main()
//{
//	int ttl_len = 13;
//	int count = 0;
//	for (int i = 6; i >= 0;i--)
//	{
//		print_pattern(13, i);
//	}
//	for (int i = 1; i <=6 ; i++)
//	{
//		print_pattern(13, i);
//	}
//	return 0;
//}

////找到水仙花数
//#include<stdio.h>
//int cal_dfdnum(int num)
//{
//	int count = 0;
//	int digits[10] = { 0 };
//	int ret = 0;
//	int tmp = 0;
//	//用10来除
//	while (num > 0)
//	{
//		digits[count] = num % 10;
//		num /= 10;
//		count++;
//	}
//	for (int i = 0; i < count; i++)
//	{
//		tmp = digits[i];
//		for (int j = 1; j < count; j++)
//		{
//			digits[i] *= tmp;
//		}
//		ret += digits[i];
//	}
//	return ret;
//}
//int find_dfdnum(int num)
//{
//	for (int i = 0; i <= num; i++)
//	{
//		if (i == cal_dfdnum(i))
//		{
//			printf("%d\n", i);
//		}
//	}
//	return 0;
//}
//int main()
//{
//	find_dfdnum(10000);
//	//printf("153 has the result of %d",cal_dfdnum(153));
//}

//求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字，
// 例如：2 + 22 + 222 + 2222 + 22222

//#include<stdio.h>
//int five_cal(int num)
//{
//	int ret = 0;
//	ret = num * 10000 + 2 * num * 1000 + 3 * num * 100 + 4 * num * 10 + 5 * num * 1;
//	return ret;
//}
//int main()
//{
//	printf("%d", five_cal(2));
//}

////在升序数组中查找指定数值，找到了就返回下标，找不到返回-1
//#include <stdio.h>
//int bin_search(int arr[], int left, int right, int key)
//{
//	//判断数组成员个数，如果为奇数个，则相对left偏移(right - left)/2个进行比较
//	//如果为偶数个，则相对left偏移(right - left + 1)/2个进行比较，同时更新right或left
//
//	int mid = 0;
//	
//	while (left <= right)
//	{
//		mid = left + (right - left) / 2;
//		if (arr[mid] > key)
//		{
//			//说明key在数组左边，变动right序号
//			right = mid - 1;
//		}
//		else if (arr[mid] < key)
//		{
//			//说明key在数组右边，变动left序号
//			left = mid + 1;
//		}
//		else {
//			return mid;
//		}
//	}
//	return -1;
//}
//
//int main() {
//	int arr[] = { 1, 3, 5, 7, 9, 11, 13 };
//	int n = sizeof(arr) / sizeof(arr[0]);
//	int key = 7;
//
//	int index = bin_search(arr, 0, n - 1, key);
//
//	if (index != -1) {
//		printf("Found at index: %d\n", index);
//	}
//	else {
//		printf("Not found\n");
//	}
//
//	return 0;
//}

////打印乘法口诀表
//#include<stdio.h>
//void row_table(int num)
//{
//	for (int i = 1; i <= num; i++)
//	{
//		printf("%d x %d = %d  ", i, num, i * num);
//	}
//}
//void full_table(int num)
//{
//	for (int i = 1; i <= num; i++)
//	{
//		row_table(i);
//		printf("\n");
//	}
//}
//int main()
//{
//	int len = 9;
//	full_table(len);
//}

//判断闰年
//#include<stdio.h>
//int leap_year(int year)
//{
//	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
//		return 1;
//	else
//		return -1;
//}
//
//int main()
//{
//	int year = 2025;
//	if (leap_year(year) > 0)
//	{
//		printf("%d is Leap year!", year);
//	}
//	else
//	{
//		printf("%d is Not leap year!", year);
//	}
//}

////判断素数
//#include<stdio.h>
//#include<stdbool.h>
//#include<math.h>
//bool is_prime(int num) {
//    if (num <= 1) return false;   // 1 不是素数
//    if (num == 2) return true;    // 2 是素数
//    if (num % 2 == 0) return false; // 跳过偶数
//
//    // 只需检查到 sqrt(num)，且跳过偶数
//    for (int divisor = 3; divisor <= sqrt(num); divisor += 2) {
//        if (num % divisor == 0) {
//            return false;
//        }
//    }
//    return true;
//}
//
//void print_primes(int left, int right) {
//    for (int num = left; num <= right; num++) {
//        if (is_prime(num)) {
//            printf("%d\n", num);
//        }
//    }
//}
//
//int main()
//{
//	print_primes(100, 200);
//    return 0;
//}

//实现函数init() 初始化数组为全0
// 实现print()  打印数组的每个元素
// 实现reverse()  函数完成数组元素的逆置
#include<stdio.h>
#include<stdlib.h>
int init(int arr[], int len)
{
	int* tmp_arr = (int*)calloc(sizeof(int), len);
	if (tmp_arr == NULL) {
		perror(calloc);
		return -1;
	}
	memmove(arr, tmp_arr, len * sizeof(int));
	free(tmp_arr);
	tmp_arr = NULL;
	return 0;
}
void print(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d\n", arr[i]);
	}
}
int reverse(int arr[], int len)
{
	int* tmp_arr = (int*)calloc(len, sizeof(int));
	memmove(tmp_arr, arr, len*sizeof(int));
	for (int i = 0; i < len; i++)
	{
		arr[i] = tmp_arr[len - i - 1];
	}
	return 0;
}

int main()
{
	int arr[5] = { 1,2,3,4,5 };
	int len = sizeof(arr) / sizeof(int);
	print(arr, len);
	printf("-----------\n");
	reverse(arr, len);
	print(arr, len);
	printf("-----------\n");
	init(arr, len);
	print(arr, len);
}