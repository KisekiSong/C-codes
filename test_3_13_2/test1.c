#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	printf("&arr[0]    = %p\n", &arr[0]);
//	printf("%&arr[0]+1  = %p\n", &arr[0] + 1);
//	printf("arr        = %p\n", arr);
//	printf("arr+1      = %p\n", arr + 1);
//	printf("arr        = %p\n", &arr);
//	printf("arr+1      = %p\n", &arr + 1);
//	return 0;
//}

//int main() {
//    int arr[10] = { 0 };
//    int* ptr = arr;//数组名表示数组的首元素地址，即&arr[0]
//    int sz = sizeof(arr) / sizeof(arr[0]);
//     int i = 0;
//    for (i = 0; i < sz; i++)
//    {
//        scanf("%d", ptr+i);
//    }
//    ptr = &arr[0];
//    for (i = 0; i < sz; i++)
//    {
//        printf("%d ", *(ptr+i));
//    }
//    return 0;
//}
void test(int arr[10])
{
	int sz2 = sizeof(arr) / sizeof(arr[0]);
	printf("sz2 = %d\n", sz2);
}


int main()
{
	int arr[10] = { 0 };
	int sz1 = sizeof(arr) / sizeof(arr[0]);
	printf("sz1 = %d\n", sz1);

	test(arr);

	return 0;
}


