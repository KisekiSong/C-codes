#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//int main()
//{
//	//1. 打开文件
//	//2. 写文件
//	//关闭文件
//	FILE * pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//2. 写文件
//	fputs("I am your FATHER!\n", pf);
//	fputs("Are you OK? Hello, thank you, thank you very much~", pf);
//	//3. 关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}
//int main()
//{
//	//1. 打开文件，指定操作模式为只读
//	FILE* pf = fopen("test.txt", "r");
//	//检验是否打开成功
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//2. 设置一个数组，存放读取的内容
//	char arr[20] = "xxxxxxxxxxxxxxxx";
//
//	//3. 进行读取，指定存放的字符串，读取的长度，读取的文件指针
//	fgets(arr, 5, pf);
//	printf("%s\n", arr);
//	//4. 关闭文件
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
//	//1. 打开文件
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		perror(fopen);
//		return 1;
//	}
//	//2. 利用fprintf向文件写入
//	fprintf(pf, "%s %d %f", name, age, score);
//	//3. 关闭文件
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
//	//1. 打开文件，指定方式为读取，不能为写入，否则出问题
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		perror(fopen);
//		return 1;
//	}
//	//2. 利用fscanf从文件读取，将数据存放在结构体student内部
//	fscanf(pf, "%s %d %f", &(student.name), &(student.age), &(student.score));
//	//printf("%s %d %f", student.name, student.age, student.score);
//	fprintf(stdout, "%s %d %f", student.name, student.age, student.score);
//	//3. 关闭文件
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
//	//将格式化的信息储存到了字符串中
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
//	//将格式化的信息储存到了字符串中
//	//从字符串中读取格式化的信息
//
//	sscanf(arr, "%s %d %f", &(tmp.name), &(tmp.age), &(tmp.score));
//	printf("%s %d %f", tmp.name, tmp.age, tmp.score);
//	return 0;
//}

////fwrite写入：
//int main()
//{
//    struct S s = { "Niuzhuxi", 24, 98.8f };
//    //打开文件，以二进制的形式写入
//    FILE* pf = fopen("test.txt", "wb");
//    if (pf == NULL)
//    {
//        perror("fopen");
//        return 1;
//    }
//    //将ptr指针指向的地址下的内容，写到文件中，每个元素大小为struct S的大小，写入1个
//    fwrite(&s, sizeof(struct S), 1, pf);
//
//    //关闭文件
//    fclose(pf);
//    pf = NULL;
//    return 0;
//}

//fread读取文件，并放入一个ptr指针中
//int main()
//{
//    struct S s = { 0 };
//    //打开文件，以二进制的形式读取
//    FILE* pf = fopen("test.txt", "rb");
//    if (pf == NULL)
//    {
//        perror("fopen");
//        return 1;
//    }
//    //从文件中读取count个大小为size个字节的数据，存放在ptr指向的空间中
//    fread(&s, sizeof(struct S), 1, pf);
//    printf("%s %d %f", s.name, s.age, s.score);
//    //关闭文件
//    fclose(pf);
//    pf = NULL;
//    return 0;
//}

//文件复制程序（低效版）
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//    //1.打开文件，并分别指定模式
//    //2.复制并写入文件
//    //3.关闭文件
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
//    //关闭文件
//    fclose(pfread);
//    pfread = NULL;
//
//    fclose(pfwrite);
//    pfwrite = NULL;
//
//    return 0;
//}