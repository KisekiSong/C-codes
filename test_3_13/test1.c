#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

size_t my_strlen(const char* p) {//这里加入一个const，使得无法通过*p解引用操作修改内存中的值，增强程序的鲁棒性
	char* start = p;
	char* end = p;
	while (*end != '\0')
	{
		end++;
	}
	return end - start;
}

//int main()
//{
//
//	//int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//	//int sz = sizeof(arr) / sizeof(arr[0]);
//	////int* p = &arr[n-1];//倒序打印
//	//int* p = &arr[0];//正序打印
//	//int i = 0;
//	//for (i = 0; i < sz; i++)
//	//{
//	//	printf("%d\n", *p);
//	//	//p -= 1;//倒序打印
//	//	p += 1;//正序打印
//	//}
//	//printf("%d", &arr[9] - p);
//	char arr[] = "abcdef";
//	size_t len = my_strlen(arr);//数组名其实是数组首元素的地址 arr == arr[0]
//	printf("%zd\n", len);
//
//	return 0;
//}
void Swarp2(int* pa, int* pb)
{
    int z = 0;
    z = *pa;
    *pa = *pb;
    *pb = z;

}
int main()
{
    int a = 3;
    int b = 5;
    printf("Before Swarp: a = %d, b = %d\n", a, b);
    Swarp2(&a, &b);
    printf("After Swarp: a = %d, b = %d", a, b);

    return 0;
}