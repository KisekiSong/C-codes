#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
struct S3
{
	double d;
	int i;
};
struct S4
{
	double d;
	char c;
	int i;
};

int main()
{

	struct S3 s3;
	printf("%zd\n", sizeof(struct S3));
	struct S4 s4;
	printf("%zd\n", sizeof(struct S4));

	return 0;
}