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
//		printf("С�˴洢");
//	else
//		printf("��˴洢");
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
//    //һֱ�ҵ���һ�������ַ���ʼ��
//    //ÿ�μ�⵽������ת��
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
//    printf("Original string: \"%s\"\n", input); // ע���ַ������ܰ������з�
//    printf("Converted integer: %lu\n", number);
//
//    return 0;
//}


//ת�Ʊ��Ѻ�����ַ�ŵ�һ���������棬��ʱ�������ѡְ��Ҫִ�еĺ���
#include<stdio.h>
typedef int (*pf_t)(int, int);
//����һ����дpf_t����������int(*)(int,int)����һ������ָ�룬ָ��ĺ�����������Ϊint���β�Ϊ2��int
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
//		printf("*********   ������   ********\n");
//		printf("**********  0.Exit  *********\n");
//		printf("******  1.ADD     2.SUB  ****\n");
//		printf("******  3.MUL     4.DIV  ****\n");
//		printf("��ѡ�����ģʽ:\n");
//		scanf("%d", &input);
//		if (input >= 1 && input <= 4) 
//		{
//			printf("����������������������\n");
//			scanf("%d %d", &x, &y);
//			ret = Tf_t[input](x , y);
//			printf("������Ϊ: %d\n", ret);
//		}
//		else if (input == 0)
//		{
//			printf("�˳�������");
//		}
//		else
//		{
//			printf("������������������");
//		}
//
//
//	} while (input);
//
//	
//	return 0;
//
//}

//�ҵ�������һ�����������ҵ�ֻ����1�ε���
//˼·����ÿ�������м���������һ�μ�һ��
//ʹ�ö�ά������м�����ͬʱ����һ������������ǰ����������Ƚϣ����Ƿ��й����еĻ����ڶ�ά����ڶ��ж�Ӧλ��+1
//����ĸ����ĳ��ִ���Ϊ1�����ҵ��˵�����
//#include<stdlib.h>
//#include<stdio.h>
//#define ROW 2
//void Find_Single_Num(const int* arr, int col)
//{
//	int tab_cur = 0;
//	int arr_cur = 0;
//	//��̬�����ڴ棬������ά����
//	int** table = (int**)malloc(ROW * sizeof(int*));
//
//	if (!table)
//		return 1;
//	for (int i = 0; i < ROW; i++)
//	{
//		table[i] = (int*)calloc(col , sizeof(int));
//		if (!table[i]) return 1;
//	}
//	//��ʼ�洢���ֲ���¼���ִ���
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
//		//�ԱȽ������������û�г��ֹ������¼�ϣ�����ǳ���1��
//		if (new == 1)
//		{
//			table[0][tab_cur] = arr[arr_cur];
//			table[1][tab_cur] = 1;
//			tab_cur++;
//		}
//			
//		arr_cur++;
//	}
//	//���������ҳ�������
//	for (int i = 0; i < tab_cur; i++)
//	{
//		if (table[1][i] == 1)
//			printf("�ҵ�һ����������������Ϊ: %d\n", table[0][i]);
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
//	//����ȥ����������Ԫ�ص�ַ����Ȼ���ӡ��������
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
    //��ʼ�ж��Ƿ�Ϊ����
    if (year % 4 == 0 || (year % 100 != 0 || (year % 100 == 0 && year % 400 == 0)))
    {
        //������
        Leap_yr = 1;
        //��ʼͨ���·ݼ�������ж�����
        //����һ������������Ϊ�·�
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