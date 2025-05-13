#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//int JUDGE_HIGH_LOW_END()
//{
//	unsigned int a = 1;
//	char b = *(unsigned char*)&a;
//	return b;
//}
//int main()
//{
//	if (JUDGE_HIGH_LOW_END)
//		printf("小端存储");
//	else
//		printf("大端存储");
//	return 0;
//}
//#include <stdlib.h>
////int Fact(int j)
////{
////    if (j == 1)
////        return 1;
////    else
////        return 10 * Fact(j - 1);
////}
//int my_atoi(char* str, int num)
//{
//    unsigned long int tmp[256] = { 0 };
//    //一直找到第一个数字字符开始，
//    //每次检测到都进行转换
//    int rtvl = 0;
//    int j = 0;
//    for (int i = 0; i < num; i++)
//    {
//        while (str[i] <= 57 && str[i] >= 48)
//        {
//            tmp[j] = (unsigned long int)str[i]-48;
//            j++;
//            i++;
//        }
//        if (j > 0)
//            break;
//    }
//    int len = j;
//    while (j > 1)
//    {
//        tmp[len - j + 1] = tmp[len - j] * 10 + tmp[len - j + 1];
//        j--;
//    }
//    return tmp[len -1];
//}
//int main() {
//    char input[256];
//    printf("Enter a string that may contain a number: ");
//    fgets(input, sizeof(input), stdin);
//
//    unsigned long int number = my_atoi(input, sizeof(input));
//    printf("Original string: \"%s\"\n", input); // 注意字符串可能包含换行符
//    printf("Converted integer: %lu\n", number);
//
//    return 0;
//}


//转移表：把函数地址放到一个数组里面，随时根据情况选职责要执行的函数
#include<stdio.h>
typedef int (*pf_t)(int, int);
//定义一个缩写pf_t，其类型是int(*)(int,int)，是一个函数指针，指向的函数返回类型为int，形参为2个int
//int ADD(int x, int y)
//{
//	return x + y;
//}
//
//int SUB(int x, int y)
//{
//	return x - y;
//}
//
//int MUL(int x, int y)
//{
//	return x * y;
//}
//
//int DIV(int x, int y)
//{
//	return x / y;
//}
//
//int main()
//{
//	int x = 0;
//	int y = 0;
//	int input = 1;
//	int ret = 0;
//	pf_t Tf_t[] = { 0, ADD, SUB,MUL, DIV };
//	do
//	{
//		printf("*****************************\n");
//		printf("*********   计算器   ********\n");
//		printf("**********  0.Exit  *********\n");
//		printf("******  1.ADD     2.SUB  ****\n");
//		printf("******  3.MUL     4.DIV  ****\n");
//		printf("请选择计算模式:\n");
//		scanf("%d", &input);
//		if (input >= 1 && input <= 4) 
//		{
//			printf("请输入两个整数操作数：\n");
//			scanf("%d %d", &x, &y);
//			ret = Tf_t[input](x , y);
//			printf("计算结果为: %d\n", ret);
//		}
//		else if (input == 0)
//		{
//			printf("退出计算器");
//		}
//		else
//		{
//			printf("输入有误，请重新输入");
//		}
//
//
//	} while (input);
//
//	
//	return 0;
//
//}

//找单身狗，从一个数组里面找到只出现1次的数
//思路：给每个数进行计数，出现一次记一次
//使用二维数组进行计数，同时遇到一个数，将其与前面的所有数比较，看是否有过，有的话就在二维数组第二行对应位置+1
//最后看哪个数的出现次数为1，就找到了单身狗数
//#include<stdlib.h>
//#include<stdio.h>
//#define ROW 2
//void Find_Single_Num(const int* arr, int col)
//{
//	int tab_cur = 0;
//	int arr_cur = 0;
//	//动态分配内存，构建二维数组
//	int** table = (int**)malloc(ROW * sizeof(int*));
//
//	if (!table)
//		return 1;
//	for (int i = 0; i < ROW; i++)
//	{
//		table[i] = (int*)calloc(col , sizeof(int));
//		if (!table[i]) return 1;
//	}
//	//开始存储数字并记录出现次数
//	while (arr_cur <col)
//	{
//		int new = 1;
//		if (arr_cur != 0)
//		{
//			for (int i = 0; i <= tab_cur; i++)
//			{
//				if (table[0][i] == arr[arr_cur])
//				{
//					table[1][i] += 1;
//					new = 0;
//				}
//			}
//		}
//
//		//对比结束，如果发现没有出现过，则记录上，并标记出现1次
//		if (new == 1)
//		{
//			table[0][tab_cur] = arr[arr_cur];
//			table[1][tab_cur] = 1;
//			tab_cur++;
//		}
//			
//		arr_cur++;
//	}
//	//检查计数表，找出单身狗数
//	for (int i = 0; i < tab_cur; i++)
//	{
//		if (table[1][i] == 1)
//			printf("找到一个单身狗数，该数字为: %d\n", table[0][i]);
//	}
//	for (int i = 0; i < ROW; i++)
//	{
//		free(table[i]);
//	}
//	free(table);
//}
//int main()
//  {
//	int arr[10] = { 0,2,3,4,5,1,2,3,4,6 };
//	//传过去数组名（首元素地址），然后打印单身狗数字
//	Find_Single_Num(arr, sizeof(arr) / sizeof(arr[0]));
//	
//}
#include <stdio.h>
int month_to_days(int month)
{
    switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        return 28;
    }

}
int days_cal(int year, int month)
{
    int Leap_yr = 0;
    //开始判断是否为闰年
    if (year % 4 == 0 || (year % 100 != 0 || (year % 100 == 0 && year % 400 == 0)))
    {
        //是闰年
        Leap_yr = 1;
        //开始通过月份计算该月有多少天
        //调用一个函数，参数为月份
    }
    if (month == 2)
    {
        return (month_to_days(month) + Leap_yr);
    }
    else
    {
        return (month_to_days(month));
    }
}
int main() {
    int a, b;
    if (scanf("%d %d", &a, &b) != EOF) {
        printf("%d", days_cal(a, b));
    }
    return 0;
}