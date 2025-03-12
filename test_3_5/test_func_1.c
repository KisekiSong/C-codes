#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//void set_arr(int arr[10], int sz, int set)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		arr[i] = set;
//	}
//	//没有返回值
//}
////这里的arr[10]可以省略，因为形参实参都是一个数组
////但是二维或多维数组只能省略行，不能省略列
//void prt_arr(int arr[10], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d\n", arr[i]);
//	}
//	//没有返回值
//}
//
//int main()
//{
//	int set = 114;
//	int arr1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	set_arr(arr1, sz, set);
//	prt_arr(arr1, sz);
//	//函数在设计的时候，尽量功能单一
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
	//case 12://当分支结果相同时，case标签连续书写
	//	days = 31;
	//	break;//明确终止当前分支，避免“贯穿执行”
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
//利用数组储存的信息，直接索引，只需要考虑闰年2月的特殊情况
int get_days_of_month(int year, int month)
{
	int days[] = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };
	//前面加个0占位，使得能够直接使用月份当作数组索引
	int day = days[month];
	if (is_leap_year(year) && month == 2)
	{
		day++;
	}
	return day;
}

//返回判断是否的，可以看作返回的是bool类型，使用bool类型时，需要添加
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

