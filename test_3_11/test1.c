#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

struct Student
{
	char name[20];
	int age;
	float score;
};//�ֺ�ǰ�����ź�����ڴ����ṹ���ͬʱ������һЩ�ṹ����������磺
//}s4, s5, s6;�����Ľṹ�����������main����֮�⣬�����ȫ�ֱ���

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
	struct Student s2 = { "����", 18, 191.9 };

	struct Q q = { 'Y', {4,5}, {1,2,3,4,5,6,7 }, 3.14 };//���Ƕ�׵��������ṹ�壬���ô��������������г�ʼ��
	
	printf("%c��", q.ch);
	printf("�����ǣ�%d %d\n", q.m.x, q.m.y);

	return 0;

}