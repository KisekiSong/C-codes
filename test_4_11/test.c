#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//int main()
//{
//	//1. ���ļ�
//	//2. д�ļ�
//	//�ر��ļ�
//	FILE * pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//2. д�ļ�
//	fputs("I am your FATHER!\n", pf);
//	fputs("Are you OK? Hello, thank you, thank you very much~", pf);
//	//3. �ر��ļ�
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}
//int main()
//{
//	//1. ���ļ���ָ������ģʽΪֻ��
//	FILE* pf = fopen("test.txt", "r");
//	//�����Ƿ�򿪳ɹ�
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//2. ����һ�����飬��Ŷ�ȡ������
//	char arr[20] = "xxxxxxxxxxxxxxxx";
//
//	//3. ���ж�ȡ��ָ����ŵ��ַ�������ȡ�ĳ��ȣ���ȡ���ļ�ָ��
//	fgets(arr, 5, pf);
//	printf("%s\n", arr);
//	//4. �ر��ļ�
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}
//int main()
//{
//	char name[20] = "zhangsan";
//	int age = 20;
//	float score = 95.5f;
//
//	//1. ���ļ�
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		perror(fopen);
//		return 1;
//	}
//	//2. ����fprintf���ļ�д��
//	fprintf(pf, "%s %d %f", name, age, score);
//	//3. �ر��ļ�
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

struct S
{
	char name[20];
	int age;
	float score;
};
//int main()
//{
//	struct S student = { 0 };
//
//	//1. ���ļ���ָ����ʽΪ��ȡ������Ϊд�룬���������
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		perror(fopen);
//		return 1;
//	}
//	//2. ����fscanf���ļ���ȡ�������ݴ���ڽṹ��student�ڲ�
//	fscanf(pf, "%s %d %f", &(student.name), &(student.age), &(student.score));
//	//printf("%s %d %f", student.name, student.age, student.score);
//	fprintf(stdout, "%s %d %f", student.name, student.age, student.score);
//	//3. �ر��ļ�
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}
//int main()
//{
//	char arr[100] = { 0 };
//	struct S s = { "wangwu", 23, 66.6f };
//	sprintf(arr, "%s %d %f", s.name, s.age, s.score);
//	//����ʽ������Ϣ���浽���ַ�����
//	printf("%s\n", arr);
//
//	return 0;
//}
//int main()
//{
//	char arr[100] = { 0 };
//	struct S s = { "wangwu", 23, 66.6f };
//	struct S tmp = { 0 };
//	sprintf(arr, "%s %d %f", s.name, s.age, s.score);
//	//����ʽ������Ϣ���浽���ַ�����
//	//���ַ����ж�ȡ��ʽ������Ϣ
//
//	sscanf(arr, "%s %d %f", &(tmp.name), &(tmp.age), &(tmp.score));
//	printf("%s %d %f", tmp.name, tmp.age, tmp.score);
//	return 0;
//}

////fwriteд�룺
//int main()
//{
//    struct S s = { "Niuzhuxi", 24, 98.8f };
//    //���ļ����Զ����Ƶ���ʽд��
//    FILE* pf = fopen("test.txt", "wb");
//    if (pf == NULL)
//    {
//        perror("fopen");
//        return 1;
//    }
//    //��ptrָ��ָ��ĵ�ַ�µ����ݣ�д���ļ��У�ÿ��Ԫ�ش�СΪstruct S�Ĵ�С��д��1��
//    fwrite(&s, sizeof(struct S), 1, pf);
//
//    //�ر��ļ�
//    fclose(pf);
//    pf = NULL;
//    return 0;
//}

//fread��ȡ�ļ���������һ��ptrָ����
//int main()
//{
//    struct S s = { 0 };
//    //���ļ����Զ����Ƶ���ʽ��ȡ
//    FILE* pf = fopen("test.txt", "rb");
//    if (pf == NULL)
//    {
//        perror("fopen");
//        return 1;
//    }
//    //���ļ��ж�ȡcount����СΪsize���ֽڵ����ݣ������ptrָ��Ŀռ���
//    fread(&s, sizeof(struct S), 1, pf);
//    printf("%s %d %f", s.name, s.age, s.score);
//    //�ر��ļ�
//    fclose(pf);
//    pf = NULL;
//    return 0;
//}

//�ļ����Ƴ��򣨵�Ч�棩
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//    //1.���ļ������ֱ�ָ��ģʽ
//    //2.���Ʋ�д���ļ�
//    //3.�ر��ļ�
//    FILE* pfread = fopen("test.txt", "rb");
//    if (!pfread)
//    {
//        perror(fopen);
//        return 1;
//    }
//
//    FILE* pfwrite = fopen("test2.txt", "wb");
//    if (!pfwrite)
//    {
//        perror(fopen);
//        return 1;
//    }
//    int ch = 0;
//    while ((ch = fgetc(pfread)) != EOF)
//    {
//        fputc(ch, pfwrite);
//    }
//    //�ر��ļ�
//    fclose(pfread);
//    pfread = NULL;
//
//    fclose(pfwrite);
//    pfwrite = NULL;
//
//    return 0;
//}