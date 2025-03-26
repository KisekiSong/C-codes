#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void GetMemory(char** p, int num)
{
	*p = (char*)malloc(num);
}
void Test(void)
{
	char* str = NULL;
	GetMemory(&str, 100);
	strcpy(str, "hello");
	printf(str);
}

int main()
{
	Test();


	return 0;
}