#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stddef.h>  // size_t 类型定义
#include<string.h>
//#define OFFSET_OF(type, member) ((size_t)&((type *)0)->member)
//经过替换之后，表达式为：
//((size_t)&((struct TEST*)0)->member)
// 强转size_t   0转TEST指针    访问成员
//&为取地址
//并没有真正地访问内存，只是写成这样的形式，诱使编译器帮我们计算偏移量
//struct TEST {
//	int a;
//	char b;
//	double c;
//};
//int main()
//{
//	struct TEST test1 = { 0, 'c', 2.0f };
//	printf("The offset of the member a is %zd\n", OFFSET_OF(struct TEST, a));
//	printf("The offset of the member b is %zd\n", OFFSET_OF(struct TEST, b));
//	printf("The offset of the member c is %zd\n", OFFSET_OF(struct TEST, c));
//
//
//	return 0;
//}
//int main()
//{
//	//打开当前目录下的data.txt文件，模式为只读
//	FILE* pfread = fopen("data.txt", "r");
//	if (pfread == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//打开当前目录下的data_copy.txt文件，模式为写入，如果不存在该文件，则创建
//	FILE* pfwrite = fopen("data_copy.txt", "w");
//	if (pfwrite == NULL)
//	{
//		perror("foepn");
//		return 1;
//	}
//
//	//内容复制
//	char tmp = 0;
//	while ((tmp = fgetc(pfread)) != EOF)
//		//检查知否赋了EOF过去，如果遇到了EOF说明走完了该文件
//	{
//		//fputc: 向流中写入一个字符，并将光标自动移动一位
//		fputc(tmp, pfwrite);
//		printf("%c", tmp);
//	}
//
//
//
//	//关闭文件
//	fclose(pfread);
//	pfread = NULL;
//	fclose(pfwrite);
//	pfwrite = NULL;
//
//	return 0;
//}

//#define SWAP_ODD_EVEN_BITS(x)\
//	((((unsigned)(x) & 0xAAAAAAAAu) >> 1) | \
//		(((unsigned)(x) & 0x55555555u) << 1))
////0xAA 的二进制为：10101010，将原始数据与10101010做与运算，可以提取出奇数位，将奇数位右移1位
////0x55 的二进制为：01010101，将原始数据与01010101做与运算，可以提取出偶数位，将偶数位左移1位
////然后让左移和右移完成的两个数，做或运算，即可得到交换了奇偶位的数
//int main()
//{
//	unsigned num = 0b10100110;
//	unsigned result = SWAP_ODD_EVEN_BITS(num);
//	printf("原始数据：%d\n", num);     //166 10100110
//	printf("交换后数据：%d\n", result);//89 01011001
//
//	return 0;
//}
struct Student
{
    char name[20];
    int age;
    double gpa;
};
int cmp_char(const void* p1, const void* p2)
{
    int a = strcmp((char*)p1, (char*)p2);
    return (a > 0) ? 1 : (a < 0) ? -1 : 0;
    
    //调用库函数strcmp来直接进行比较，strcmp的返回值与qsort要求的相符
}
int cmp_int(const void* p1, const void* p2)
{
    int a = *(int*)p1;
    int b = *(int*)p2;
    return (a > b) ? 1 : (a < b) ? -1 : 0;
    //三目运算符：如果该a > b成立，表达式的值为1，如果a < b成立，表达式的值为-1，如果都不成立，则返回0
}
int cmp_float(const void* p1, const void* p2)
{
    float a = *(float*)p1;
    float b = *(float*)p2;
    return (a > b) ? 1 : (a < b) ? -1 : 0;
}
int cmp_stu_by_name(const void* e1, const void* e2)
{
    return (((struct Student*)e1)->age - ((struct Student*)e2)->age);
}
int cmp_stu_by_age(const void* e1, const void* e2)
{
    int a = ((struct Student*)e1)->age;
    int b = ((struct Student*)e2)->age;
    return (a > b) ? 1 : (a < b) ? -1 : 0;
}
int cmp_stu_by_gpa(const void* e1, const void* e2)
{
    double a = ((struct Student*)e1)->gpa;
    double b = ((struct Student*)e1)->gpa;
    return (a > b) ? 1 : (a < b) ? -1 : 0;
}
//int main()
//{
//    //int arr1[] = { 1,5,4,2,3,9,7,6,8,0 };
//    //char arr2[] = { 'a', 'c', 'b', 'f', 'd', 'h', 'g', 'j', 'h','i' };
//    //float arr3[] = { 1.0f,5.0f,4.0f,2.0f,3.0f,9.0f,7.0f,6.0f,8.0f,0.0f };
//    struct Student dorm423[] = { {"Niuzhuxi", 23, 3.8},{"Laowang", 23, 3.5}, {"Laozhao", 23, 3.9},{"Laokang", 24, 3.7}};
//    //size_t num = sizeof(arr1) / sizeof(arr1[0]);
//    //size_t num = sizeof(arr2) / sizeof(arr2[0]);
//    size_t num = sizeof(dorm423) / sizeof(dorm423[0]);
//    //qsort(arr1, num, sizeof(int), cmp_int);
//    qsort(dorm423, num, sizeof(struct Student), cmp_stu_by_gpa);
//
//    return 0;
//}

//qsort模拟实现
//1. 交换函数
void SWAP(char* p1, char* p2, size_t width, int mode)
{
    int i = 0;
    char tmp = 0;
    if (mode == 1)
    {
        for (i = 0; i < width; i++)
        {
            tmp = *p1;
            *p1 = *p2;
            *p2 = tmp;

            p1++;
            p2++;
        }

    }
}

void bubble_qsort(void* base, size_t num, size_t sz, int(*cmp)(const void*, const void*))
{
    int i = 0;
    for (i = 0; i < num - 1; i++)
    {
        int j = 0;
        for (j = 0; j < num - 1; j++)
        {
            if (cmp((char*)base + j * sz, (char*)base + (j + 1) * sz) > 0)
            {
                SWAP((char*)base + j * sz, (char*)base + (j + 1) * sz, sz, 1);
            }
        }
    }
}
int main()
{
    //int arr1[] = { 1,5,4,2,3,9,7,6,8,0 };
    char arr2[] = { 'a', 'c', 'b', 'f', 'd', 'h', 'g', 'j', 'h','i' };
    //float arr3[] = { 1.0f,5.0f,4.0f,2.0f,3.0f,9.0f,7.0f,6.0f,8.0f,0.0f };
    //struct Student dorm423[] = { {"Niuzhuxi", 23, 3.8},{"Laowang", 23, 3.5}, {"Laozhao", 23, 3.9},{"Laokang", 24, 3.7}};
    //size_t num = sizeof(arr1) / sizeof(arr1[0]);
    size_t num = sizeof(arr2) / sizeof(arr2[0]);
    //size_t num = sizeof(dorm423) / sizeof(dorm423[0]);
    //qsort(arr1, num, sizeof(int), cmp_int);
    bubble_qsort(arr2, num, sizeof(char), cmp_char);
    for (int i = 0; i < num; i++)
    {
        printf("arr2[%d] = %c\n", i, arr2[i]);
    }
    return 0;
}