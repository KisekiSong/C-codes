#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
//int findnum(int a[][3], int x, int y, int f)
////x为行，y为列，f为要找到的数字
//{
//    int i = 0;
//    int j = y - 1;
//    //从右上角开始遍历
//    while (j >= 0 && i < x)
//    {
//        if (a[i][j] < f)
//        {
//            //比该值大，看下一行
//            i++;
//        }
//        else if (a[i][j] > f)
//        {
//            //比右上角小，看左边一列
//            j--;
//        }
//        else
//            //等于说明找到了，返回1
//            return 1;
//    }
//    //否则离开循环，说明没找到，返回0
//    return 0;
//}
//int main()
//{
//    int a[][3] = { {1,3,5}, {2,4,6}, {3,5,7} };
//    if (findnum(a, 3, 3, 2)) {
//        printf("Number founded");
//    }
//    else
//    {
//        printf("Number not found");
//    }
//
//
//    return 0;
//}

//判断凶手
//A说不是我
//B说是C
//C说是D
//D说C说的不对
//考虑用二维数组，每个人轮流当假话，如果其他人没有假话，则说明是这个人
//利用ASCII码的顺序，来代表abcd
//#include<stdio.h>
//int main()
//{
//	int killer = 0;
//	for (killer = 'a'; killer <= 'd'; killer++)
//	{
//		//利用ASCII码值实现abcd的切换
//		if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer !='d') == 3)
//		{
//			printf("凶手是: %c", killer);
//		}
//	}
//	return 0;
//}
//#include<string.h>
//#include<stdio.h>
////逆序字符串：输出一个字符串，表示将输入字符串s反转后的结果
//
//int main()
//{
//	char str[10000] = { 0 };
//	gets(str);
//	int len = strlen(str);
//	for (int i = 0; i < len; i++)
//	{
//		printf("%c", str[len - i - 1]);
//	}
//	return 0;
//}

//字符串左旋
//实现一个函数，可以左旋字符串中的k个字符。
//例如：
//ABCD左旋一个字符得到BCDA
//
//ABCD左旋两个字符得到CDAB
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZEOF_CHAR 1
int left_rev(char* str, int k)
{
	//分配k个字符的空间时，记得多分配一个来装'\0'
	int len = strlen(str);
	if (len == 0 || k <= 0)
		return;
	else if (len == k)
	{
		for (int i = len - 1; i >= 0; i--)
		{
			printf("%c", str[i]);
		}
		return 0;
	}

	//分配临时空间存储前k个字符
	char* tmp = (char*)calloc(k+1, 1);
	if (tmp == NULL)
	{
		perror(calloc);
		return -1;
	}
	//保存前面k个字符
	strncpy(tmp, str, k);
	tmp[k] = '\0';

	//移动后面的字符到前面来
	memmove(str, str + k, len - k);
	//从str+k开始，把剩下的len-k个字符移动到左边去
	//memmove自动处理重叠问题

	//追加临时字符到末尾
	strncpy(str+len - k, tmp, k);
	free(tmp);
	printf("after rotating 1: %s\n", str);
}
int main()
{
	char sample[] = "ABCD";  // 修改为可变的字符数组
	printf("Original: %s\n", sample);
	left_rev(sample, 1);

	char sample2[] = "ABCD";  // 修改为可变的字符数组
	left_rev(sample2, 2);

	char sample3[] = "ABCD";  // 修改为可变的字符数组
	left_rev(sample3, 3);

	char sample4[] = "ABCD";  // 修改为可变的字符数组
	left_rev(sample4, 4);
	return 0;
}
