#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>



int main()
{
	char str1[] = "Sample string";
	char str2[100];//�ռ��㹻�� 
	char str3[] = "Second Copy";
	strcpy(str2, str1);//��str1�����ݣ�������str2��
	strcpy(str2, str3);//�Ѻ����copy successful������str3��
	printf("str1: %s\nstr2: %s\n", str1, str2);
	return 0;



	return 0;
}
