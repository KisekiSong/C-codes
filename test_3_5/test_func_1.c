#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//void set_arr(int arr[10], int sz, int set)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		arr[i] = set;
//	}
//	//û�з���ֵ
//}
////�����arr[10]����ʡ�ԣ���Ϊ�β�ʵ�ζ���һ������
////���Ƕ�ά���ά����ֻ��ʡ���У�����ʡ����
//void prt_arr(int arr[10], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d\n", arr[i]);
//	}
//	//û�з���ֵ
//}
//
//int main()
//{
//	int set = 114;
//	int arr1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	set_arr(arr1, sz, set);
//	prt_arr(arr1, sz);
//	//��������Ƶ�ʱ�򣬾������ܵ�һ
//	return 0;
//}

//int get_days_of_month(int year, int month)
//{
//	int days = 0;
//
	//switch (month) {
	//case 1:
	//case 3:
	//case 5:
	//case 7:
	//case 8:
	//case 10:
	//case 12://����֧�����ͬʱ��case��ǩ������д
	//	days = 31;
	//	break;//��ȷ��ֹ��ǰ��֧�����⡰�ᴩִ�С�
//	case 2:
//		if ((year % 4 == 0)&&(year % 100 !=0)||(year%400==0)) {
//			days = 29;
//			break;
//		}
//		else {
//			days = 28;
//			break;
//		}
//	case 4:
//	case 6:
//	case 9:
//	case 11:
//		days = 30;
//		break;
//	}
//	return days;
//}
//�������鴢�����Ϣ��ֱ��������ֻ��Ҫ��������2�µ��������
int get_days_of_month(int year, int month)
{
	int days[] = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };
	//ǰ��Ӹ�0ռλ��ʹ���ܹ�ֱ��ʹ���·ݵ�����������
	int day = days[month];
	if (is_leap_year(year) && month == 2)
	{
		day++;
	}
	return day;
}

//�����ж��Ƿ�ģ����Կ������ص���bool���ͣ�ʹ��bool����ʱ����Ҫ���
//<stdbool.h>
int is_leap_year(int year)
{
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {
		return 1;
	}
	else
		return 0;
}

int main()
{
	int year = 0;
	int month = 0;
	printf("Pleas type in year and month: ");
	scanf("%d %d", &year, &month);
	int day = get_days_of_month(year, month);
	printf("The number of days is: %d", day);
	return 0;
}

