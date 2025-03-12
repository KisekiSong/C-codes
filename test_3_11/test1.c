#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

struct Student
{
	char name[20];
	int age;
	float score;
};//分号前，括号后可以在创建结构体的同时，声明一些结构体变量，例如：
//}s4, s5, s6;这样的结构体变量创建在main函数之外，因此是全局变量

struct point
{
	int x;
	int y;
};

struct Q
{
	char ch;
	struct point m;
	int arr[10];
	double d;
};

int main()
{
	struct Student s1 = {"John", 60, 114.5};
	struct Student s2 = { "旺财", 18, 191.9 };

	struct Q q = { 'Y', {4,5}, {1,2,3,4,5,6,7 }, 3.14 };//如果嵌套的有其他结构体，就用大括号括起来进行初始化
	
	printf("%c的", q.ch);
	printf("坐标是：%d %d\n", q.m.x, q.m.y);

	return 0;

}