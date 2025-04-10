#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>



int main()
{
	char str1[] = "Sample string";
	char str2[100];//空间足够大 
	char str3[] = "Second Copy";
	strcpy(str2, str1);//把str1的内容，拷贝到str2中
	strcpy(str2, str3);//把后面的copy successful拷贝到str3中
	printf("str1: %s\nstr2: %s\n", str1, str2);
	return 0;



	return 0;
}
