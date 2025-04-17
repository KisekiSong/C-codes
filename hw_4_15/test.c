#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<ctype.h>
//1. 实现strlen函数
//size_t my_strlen(const char* str)
//{
//    assert(str != NULL);
//    const char* start = str;
//    //增加一层保险，如果ptr为空指针，则报错
//    while (*start != '\0')//检验start是否遇到了'\0'
//    {
//        start++;//start不断移动，最后与开头的str相减，得到长度（这么做的前提是char类型占1个字节）
//    }
//    return start - str;
//}
//
//int main()
//{
//    char arr[] = "abcdef";
//    size_t len = my_strlen(arr);
//    printf("%zd\n", len);
//
//    return 0;
//}

//strlen的递归实现：
//size_t my_strlen(const char* str)
//{
//	if (*str != '\0')
//		return 1 + my_strlen(str + 1);
//	//一直查找到\0，然后再一层一层往上加回来，好处是实现简单，坏处是字符串很大时，内存消耗太大
//	else
//		return 0;
//}

//2. 实现strcpy
//char* my_strcpy(char* dest, const char* src)
//{
//	assert(dest && src);
//	//检验deste和src是否为空指针
//	char* ret = dest;
//	while(*dest++ = *src++)
//	{ }
//	//++的优先级高于*，但是由于后置，所以是先完成赋值，再完成地址+1
//	//赋值完了地址+1，实现滑动
//	//同时因为先赋值，所以滑动到 '\0'之后会先经过判断，直接跳出循环
//	return ret;
//}
//int main()
//{
//    char arr1[] = "abcdef";
//    char arr2[20] = { 0 };
//    char* pstr = my_strcpy(arr2, arr1);
//
//    printf("%s\n", arr2);
//    printf("%s\n", pstr);
//    printf("%s\n", my_strcpy(arr2, arr1));
//
//    return 0;
//}
// 实现strcmp函数
//char* my_strcmp(const char* str1, const char* str2)
//{
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//			return 0;
//		str1++;
//		str2++;
//	}
//	if (*str1 > *str2)
//		return 1;//str1 > str2时，返回大于0的数
//	else
//		return -1;//str1 < str2时，返回小于0的数
//}
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "abcdefg";
//	int count = my_strcmp(arr1, arr2);
//	if (count > 0)
//		printf("str1 > str2");
//	else if (count < 0)
//		printf("str1 < str2");
//	else
//		printf("str1 = str2");
//
//	return 0;
//}

//4. strcat的模拟实现
//strcat的功能是：将source指针指向的字符串，追加到dest指针指向的字符串后，并返回追加后字符串的首地址
//char* my_strcat(char* dest, char* src)
//{
//	char* ret = dest;
//	while (*dest)//先将指针移动到'\0'位置处
//	{
//		dest++;
//	}
//	while (*dest++ = *src++)//后续赋值和strcpy一样
//		;
//	return ret;
//}
//
//int main()
//{
//	char arr1[30] = "I am ";
//	char arr2[] = "your father";
//	printf("%s", my_strcat(arr1, arr2));
//
//	return 0;
//}
// 5. 实现strstr函数：在字符串1里面找是否有字符串2
//char* my_strstr(const char* str1, const char* str2)
//{
//	int flag = 0;
//	char* ret_str2 = str2;
//	char* ret = NULL;
//	int sz_str2 = strlen(str2);
//	while (str1 != NULL)
//	{
//		//一直比较到str1字符串的末尾'\0'
//		if (*str1 == *str2)
//		{
//			//for循环的继续条件是：*str1 == *str2，每次记录相等的字符的个数，ret这时保存str1字符串的起始地址
//			for (ret = str1; *str1 == *str2; flag++)
//			{
//				str1++;
//				str2++;
//				//更新str1和str2指向的地址
//			}
//		}
//		if ((flag == sz_str2) && (*ret == *(str1 - sz_str2)))
//			//如果记录的相等字符长度等于sz_str2；并且str1指向的地址减去sz_str2之后等于str1开始匹配之前的地址
//			//说明在str1里面找到了str2
//		{
//			return ret;
//		}
//		else
//		{
//			flag = 0;//清零计数器方便下次使用
//			ret = NULL;//防止野指针
//			str2 = ret_str2;//str2指针重新指向str2字符串的首地址
//		}
//		str1++;//继续向后找
//	}
//	return ret;
//}
//考虑到多次匹配的情况
const char* my_strstr(const char* str1, const char* str2)
{
	assert(str1 && str2);
	const char* s1 = NULL;
	const char* s2 = NULL;
	const char* cur = str1;//使用cur这个指针表示指针指向被查找字符串的第几个位置
	//都用const，防止指针操作时修改字符串内的值
	//如果str2指向的是空字符串，直接返回str1
	if (*str2 == '\0')
	{
		return str1;
	}
	while (*cur)//仅当不指向str1末尾的\0时进行匹配
	{
		s1 = cur;//更新s1
		s2 = str2;//更新s2
		while (s1 && s2 && *s1 == *s2)//如果*s1 == *s2，尝试开始匹配，
		{
			s1++;//s1指针滑动
			s2++;//s2指针滑动
		}
		if (*s2 == '\0')//如果s2滑动到了str2的末尾
		{
			return cur;//说明匹配成功，返回匹配开始时候的位置，即cur指针指向的地址
		}
		cur++;//没有满足*s1 == *s2，cur滑动，继续尝试
	}
	return NULL;//返回NULL表示没找到

}

int main()

{
	char line1[] = "Let the sky fall, When it crumbles, we will stand tall, Face it all together";
	char line2[] = "crumble";
	char* ptr = my_strstr(line1, line2);
	if (ptr != NULL)
	{
		printf("founded, the left string is at the %dth character", strlen(line1) - strlen(ptr)+1);
	}
	else
	{
		printf("404 Not Found");
	}

	return 0;
}

//6.实现strncpy：长度受限制的字符串函数
// 受限制：只拷贝src中num个字符到dest中，不会自动补'\0'，要拷贝多少就考呗多少
//char* my_strncpy(char* dest, const char* src, const size_t num)
//{
//	assert(dest && src);
//	//检验deste和src是否为空指针
//	size_t i = 0;
//	for (i = 0; i < num && src[i] != '\0'; i++)
//	{
//		dest[i] = src[i];
//	}
//	//这里的i < num既起到了判断作用，又起到了约束作用
//	for (; i < num; i++)
//	{
//		dest[i] = '\0';
//	}
//	return dest;
//}
//int main()
//{
//	char arr1[100] = "Hello can you hear me";
//	char arr2[30] = "Yes I can";
//	printf("%s\n", my_strncpy(arr1, arr2, 9));
//	my_strncpy(arr1, "Hello can you hear me", 100);
//	printf("%s\n",my_strncpy(arr1, arr2, 30));
//	
//	return 0;
//}
//7. 模拟实现strncat
//char* my_strncat(char* dest, const char* src, size_t dest_size, size_t num)
//{
//	size_t i = 0;
//	char* ret = dest;
//	size_t dest_len = strlen(dest);
//	if ( dest_len >= dest_size)
//	{
//		printf("空间已经不足");
//		return dest;
//	}
//	else{
//		//直接移动到dest末尾
//		dest += dest_len;
//		for (i = 0; i < num && src != '\0'; i++)
//		{
//			*dest++ = *src++;
//		}
//		*dest = '\0';
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[100] = "Hello can you hear me. I'm in California dreaming...";
//	char arr2[10] = "Yes I can";
//	//测试，将arr2中的9个字符，不包含\0，接到arr1末尾，会自动补充'\0'
//	printf("%s\n", my_strncat(arr1, arr2, sizeof(arr1) / sizeof(arr1[0]), 9));
//
//	return 0;
//}

//8. 实现memcpy
//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//    int i = 0;
//    void* ret = dest;
//    assert(dest && src);
//    //断言二者不是空指针
//    for (i = 0; i < num; i++)
//        //写成while(num--)也可以
//    {
//        *(char*)dest = *(char*)src;
//        //由于char类型之占用1个字节，在内存上表示，1个字节就是一个单位
//        //找不到比这精确度更高的类型了，因此用char类型
//        //每次+1就是往前挪动1个char类型的内存宽度
//        dest = (char*)dest + 1;
//        src = (char*)src + 1;
//        //由于强制类型转换后，是临时的，++无法让转换后的临时指针类型移动
//        //而++(char*)dest;的写法在不同编译器中可能报错，不能这么写
//    }
//    return ret;
//}
//int main()
//{
//    int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//    for (int i = 0; i < 10; i++)
//    {
//        printf("%d\n", arr1[i]);
//    }
//    int arr2[20] = { 0 };
//    //参数1：目标地址
//    //参数2：内存块的首元素指针作为参数传递
//    //参数3：拷贝的字节个数
//    memcpy(arr2, arr1 + 2, 20);
//    for (int i = 0; i < 10; i++)
//    {
//        printf("%d\n", arr2[i]);
//    }
//    return 0;
//}

//9. 模拟实现memmove
//void* my_memmove(void* dest, const void* src, size_t num)
//{
//    void* ret = dest;
//    if (dest < src)
//        //如果拷贝存在重叠，则分情况：
//        //数据的存放是从低地址到高地址，从低位到高位
//        //如果dest在src左边，先拷贝src左边的，因为就算重叠也是在dest右边和src的左边重叠，这个地方的数据已经拷贝走了
//    {
//        while (num--)
//        {
//            *(char*)dest = *(char*)src;
//            dest = (char*)dest + 1;
//            src = (char*)src + 1;
//        }
//    }
//    else
//    {
//        while (num--)
//        {
//            *((char*)dest + num) = *((char*)src + num);
//        }
//    }
//    return ret;
//
//}
//int main()
//{
//    int arr1[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
//    int* ptr = my_memmove(arr1, arr1 + 3, 10);
//    for (int i = 0; i < 15; i++)
//    {
//        printf("%d\n", ptr[i]);
//    }
//
//    return 0;
//}