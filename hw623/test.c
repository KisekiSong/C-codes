//#define _CRT_SECURE_NO_WARNINGS
////�ҵ���1
////��һ�����������У�ֻ��һ�����ֳ���һ�Σ��������鶼�ǳɶԳ��ֵģ����ҳ��Ǹ�ֻ����һ�ε����֡�
////���磺
////�������У�1 2 3 4 5 1 2 3 4��ֻ��5����һ�Σ��������ֶ�����2�Σ��ҳ�5
////�������������������ʣ��ֻ����1�ε�����
////�����ͬΪ0����0����������Ϊ�䱾��
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


////������������������������ʱ����
////ʹ��λ���������
//#include<stdio.h>
//int main()
//{
//	//ʹ����򽻻�����
//	int a = 114;
//	int b = 514;
//	printf("Before a = %d, b = %d\n", a, b);
//	a = a ^ b;
//	b = a ^ b;//b = a^b^b = a ^ 0 = a
//	a = a ^ b;//a = a^b^a = b ^ 0 = b
//	printf("Switched a = %d, b = %d", a, b);
//}



//ͳ�ƶ�������1�ĸ���
//�������32λ�����Ʊ�ʾ��1�ĸ��������и����ò����ʾ
//λ���㣺�޷������Ʒ�
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
////-1�����뷨������1
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
//��ӡ���������Ƶ�����λ��ż��λ
//ʹ�����ƣ����踺���ò����ʾ������ֱ��ʹ�����ƾͿ�����
//����ż��λ���ӵ�0λ��ʼ����ÿ��������2��λ����1�����Ϊ�棬���ӡ1����֮��ӡ0
//��������λ��������1λ����1��Ȼ��������2��λ����1��ͬ��
//#include<stdio.h>
//int print_binary_digits(const int num)
//{
//	int ret = num;
//	int andNum = 0x0001;
//	int count = 0;
//	//�ж���������ż��
//
//	//��ӡ������������һλ
//	ret = ret >> 1;
//	printf("Print odd digits:\n");
//	for (int i = 0; i < 16; i++)
//	{
//		printf("%d", ret & andNum);
//		ret = ret >> 2;
//	}
//	//��ӡż��
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

//2�����������в�ͬλ�ĸ���
//forѭ����ÿ�ο����һλ����ͬ���count+1
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

//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Ժȶ�����ˮ�����ʵ�֣���
//#include<stdio.h>
//int bottle_and_bottlecap(int money)
//{
//	int bottle_num = money;
//	int new_bottle_num = money;
//	int bottlecap_num = 0;
//	while (new_bottle_num != 0)
//	{
//		//ƿ������=ƿ������
//		bottlecap_num = new_bottle_num;
//		//����ƿ�� = ƿ�� = 20
//		bottle_num += bottlecap_num / 2;
//		//ƿ�� = 20+20/2 = 30
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

//�������ͼ������һ��1��*���ڶ���3��*����7��13��*����8��9��*��...�����һ��1��*
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

////�ҵ�ˮ�ɻ���
//#include<stdio.h>
//int cal_dfdnum(int num)
//{
//	int count = 0;
//	int digits[10] = { 0 };
//	int ret = 0;
//	int tmp = 0;
//	//��10����
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

//��Sn=a+aa+aaa+aaaa+aaaaa��ǰ5��֮�ͣ�����a��һ�����֣�
// ���磺2 + 22 + 222 + 2222 + 22222

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

////�����������в���ָ����ֵ���ҵ��˾ͷ����±꣬�Ҳ�������-1
//#include <stdio.h>
//int bin_search(int arr[], int left, int right, int key)
//{
//	//�ж������Ա���������Ϊ�������������leftƫ��(right - left)/2�����бȽ�
//	//���Ϊż�����������leftƫ��(right - left + 1)/2�����бȽϣ�ͬʱ����right��left
//
//	int mid = 0;
//	
//	while (left <= right)
//	{
//		mid = left + (right - left) / 2;
//		if (arr[mid] > key)
//		{
//			//˵��key��������ߣ��䶯right���
//			right = mid - 1;
//		}
//		else if (arr[mid] < key)
//		{
//			//˵��key�������ұߣ��䶯left���
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

////��ӡ�˷��ھ���
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

//�ж�����
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

////�ж�����
//#include<stdio.h>
//#include<stdbool.h>
//#include<math.h>
//bool is_prime(int num) {
//    if (num <= 1) return false;   // 1 ��������
//    if (num == 2) return true;    // 2 ������
//    if (num % 2 == 0) return false; // ����ż��
//
//    // ֻ���鵽 sqrt(num)��������ż��
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

//ʵ�ֺ���init() ��ʼ������Ϊȫ0
// ʵ��print()  ��ӡ�����ÿ��Ԫ��
// ʵ��reverse()  �����������Ԫ�ص�����
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