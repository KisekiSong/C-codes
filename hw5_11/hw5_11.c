#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stddef.h>  // size_t ���Ͷ���
#include<string.h>
//#define OFFSET_OF(type, member) ((size_t)&((type *)0)->member)
//�����滻֮�󣬱��ʽΪ��
//((size_t)&((struct TEST*)0)->member)
// ǿתsize_t   0תTESTָ��    ���ʳ�Ա
//&Ϊȡ��ַ
//��û�������ط����ڴ棬ֻ��д����������ʽ����ʹ�����������Ǽ���ƫ����
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
//	//�򿪵�ǰĿ¼�µ�data.txt�ļ���ģʽΪֻ��
//	FILE* pfread = fopen("data.txt", "r");
//	if (pfread == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//�򿪵�ǰĿ¼�µ�data_copy.txt�ļ���ģʽΪд�룬��������ڸ��ļ����򴴽�
//	FILE* pfwrite = fopen("data_copy.txt", "w");
//	if (pfwrite == NULL)
//	{
//		perror("foepn");
//		return 1;
//	}
//
//	//���ݸ���
//	char tmp = 0;
//	while ((tmp = fgetc(pfread)) != EOF)
//		//���֪����EOF��ȥ�����������EOF˵�������˸��ļ�
//	{
//		//fputc: ������д��һ���ַ�����������Զ��ƶ�һλ
//		fputc(tmp, pfwrite);
//		printf("%c", tmp);
//	}
//
//
//
//	//�ر��ļ�
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
////0xAA �Ķ�����Ϊ��10101010����ԭʼ������10101010�������㣬������ȡ������λ��������λ����1λ
////0x55 �Ķ�����Ϊ��01010101����ԭʼ������01010101�������㣬������ȡ��ż��λ����ż��λ����1λ
////Ȼ�������ƺ�������ɵ����������������㣬���ɵõ���������żλ����
//int main()
//{
//	unsigned num = 0b10100110;
//	unsigned result = SWAP_ODD_EVEN_BITS(num);
//	printf("ԭʼ���ݣ�%d\n", num);     //166 10100110
//	printf("���������ݣ�%d\n", result);//89 01011001
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
    
    //���ÿ⺯��strcmp��ֱ�ӽ��бȽϣ�strcmp�ķ���ֵ��qsortҪ������
}
int cmp_int(const void* p1, const void* p2)
{
    int a = *(int*)p1;
    int b = *(int*)p2;
    return (a > b) ? 1 : (a < b) ? -1 : 0;
    //��Ŀ������������a > b���������ʽ��ֵΪ1�����a < b���������ʽ��ֵΪ-1����������������򷵻�0
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

//qsortģ��ʵ��
//1. ��������
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