#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include"game.h"


int main()
{
	srand((unsigned int)time(NULL));
	//�����������̣�һ�����������ף���һ������������Χ����
	char setboard[ROWS][COLS];
	char calboard[ROWS][COLS] ;

	//ʹ�ó�ʼ����������ʼ������������
	//���û��������̳�ʼ��Ϊȫ��*��
	//��һ�����γ�ʼ��Ϊȫ��0��
	InitBoard(setboard, ROWS, COLS, '*');
	InitBoard(calboard, ROWS, COLS, '0');


	//�û���Ҫ����9*9�ĸ��ӣ���ӡ����
	DemoBoard(setboard, ROW, COL);
	printf("-----------------------------------------\n");
	//calboard����Ҫ���û������������Լ�����ͺ�
	//DemoBoard(calboard, ROWS, COLS);
	//��calboard�������ף�����ӡ��õ���

	//������
	SetBoom(calboard, ROWS, COLS);
	DemoBoard(calboard, ROW, COL);

	//��ʼɨ��
		//�����û���������
	FindBoom(calboard, setboard, ROWS, COLS);

	return 0;
}