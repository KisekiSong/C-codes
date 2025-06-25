#define _CRT_SECURE_NO_WARNINGS
////模拟实现strlen
////传入字符串首地址
////边移动指针边增加计数器并判断是否遇到了'\0'
////返回计数器的值
//#include<stdio.h>
//int my_strlen(const char* str)
//{
//	int len = 0;
//	char* start = str;
//	for (0; *start != '\0'; start++, len++)
//	{
//
//	}
//	return len;
//}
//
//int main()
//{
//	char* string1 = "Pinkman";
//	printf("The length is %d", my_strlen(string1));
//	//应该输出 The length is 7
//	return 0;
//}

//实现奇数偶数换顺序
//调整数组使奇数全部位于偶数前面
//偶数特点：二进制的最后一位必定为0
//奇数特点：二进制的最后一位必定为1
//思路：考虑用异或 ^ 最后一位来分辨奇数或偶数
//换顺序：新建2个动态内存空间，分别用strncpy进行拷贝
//最后将两个动态内存空间拼接
#include<stdio.h>
#include<stdlib.h>
int even_odd_grouping(int* ptr, int len)
{
	int* odd_tmp = (int*)calloc(len, sizeof(int));
	int* even_tmp = (int*)calloc(len, sizeof(int));
	int odd_idx = 0;
	int even_idx = 0;
	for (int i = 0; i < len; i++)
	{
		//如果和0异或得到1，说明值为奇数，填入奇数的动态内存
		if ((ptr[i] & 1) == 1)
		{
			odd_tmp[odd_idx++] = ptr[i];
		}
		else
		{
			even_tmp[even_idx++] = ptr[i];
		}
	}
	//归档完成之后，开始拼接
	//使用memmove将even_tmp的内容移动到odd_tmp中，len-count就是偶数的个数
	memcpy(odd_tmp+odd_idx, even_tmp, sizeof(int) * even_idx);
	//打印分好组的内容
	for (int i = 0; i < len; i++)
	{
		printf("%d", odd_tmp[i]);
	}

	//如果需要修改原数组，则在使用memcpy拷贝过去即可
}

int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	even_odd_grouping(arr,sizeof(arr)/sizeof(int));

}