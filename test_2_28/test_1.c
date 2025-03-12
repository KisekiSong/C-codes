 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main() {

	//char arr1[] = "abcdef";
	//printf("%d\n", strlen(arr1));
	//char arr2[] = { 'a','b','c','d','e','f' };
	//printf("%d\n", strlen(arr2));
	//printf("%9lf\n", 114.5141919810);
	//printf("%6lf\n", 114.5);
	//printf("%9lf\n", 1.145);
	//printf("%*.*lf\n", 6, 2, 114.5141919);

	//int score = 0;//初始化
	//printf("请输入成绩：");
	//scanf("%d", &score);
	//printf("输入的成绩为：%d", score);
	// 
	//int a = 0;
	//int b = 0;
	//float f = 0.0f;
	//int ret = scanf("%d %d %f", &a, &b, &f);
	//printf("a = %d, b = %d, f = %f\n", a, b, f);
	//printf("ret = %d\n", ret);
	int year = 0;
	int month = 0;
	int day = 0;
	scanf("%d%*c%d%*c%d", &year, &month, &day);
	printf("%d %d %d", year, month, day);
	return 0;
}