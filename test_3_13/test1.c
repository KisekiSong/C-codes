#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

size_t my_strlen(const char* p) {//�������һ��const��ʹ���޷�ͨ��*p�����ò����޸��ڴ��е�ֵ����ǿ�����³����
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
//	////int* p = &arr[n-1];//�����ӡ
//	//int* p = &arr[0];//�����ӡ
//	//int i = 0;
//	//for (i = 0; i < sz; i++)
//	//{
//	//	printf("%d\n", *p);
//	//	//p -= 1;//�����ӡ
//	//	p += 1;//�����ӡ
//	//}
//	//printf("%d", &arr[9] - p);
//	char arr[] = "abcdef";
//	size_t len = my_strlen(arr);//��������ʵ��������Ԫ�صĵ�ַ arr == arr[0]
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