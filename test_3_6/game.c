#define _CRT_SECURE_NO_WARNINGS

#include"game.h"
#include<stdio.h>

void InitBoard(char Board[ROWS][COLS], int row, int col, char CHA)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			Board[i][j] = CHA;
		}
	}
}
void DemoBoard(char Board[ROWS][COLS], int row, int col)
{
	//���һ���к��еı�Ź���
	int i = 0;

	for (i = 0; i <= col; i++) {
		printf("%d  ", i);
		//�Ȱѵ�һ�еı�Ŵ�ӡ�ˣ��ٴ�ӡʣ�µ�
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d  ", i);
		//��һ��Ҳȫ����ӡ��ţ��ڴ�ӡʣ�µ���
		int j = 0;
		for (j = 1; j <= col; j++)
		{
			printf("%c  ", Board[i][j]);
		}
		printf("\n");

	}
}

void SetBoom(char Board[ROWS][COLS], int row, int col)
{
	//��9*9�ĸ����������ѡ��һ�����꣬�ȼ��������Ƿ�Ϊ0�����Ϊ0��ֵΪ1��Ϊ��
	//����Ѿ���Ϊ0�������¿�ʼѡ�����
	//ʹ��time(NULL)��rand�������Լ�srand��ʵ�����
	int x = 0;
	int y = 0;
	int input = Boom_Num;
	do {
		x = rand() % ROW + 1;
		y = rand() % COL + 1;
		if (Board[x][y] != '1') {
			Board[x][y] = '1';
			input--;
		}
	} while (input);
}

int CountBoom(char Board[ROWS][COLS], int x, int y)
{
	//�ֶ����㣬�����ַ��ļӼ����ַ�--->����
	//return Board[x - 1][y] + Board[x - 1][y - 1] +
	//	Board[x][y - 1] + Board[x + 1][y - 1] +
	//	Board[x + 1][y] + Board[x + 1][y + 1] +
	//	Board[x][y + 1] + Board[x - 1][y + 1] - 8 * '0';
	//ѭ�����㣺
	int i = 0;
	int count = 0;
	for (i = -1; i <= 1; i++)
	{
		int j = 0;
		for (j = -1; j <= 1; j++)
		{
			count += (Board[x + i][y + i] - '0');
		}


	}
}

void FindBoom(char Board[ROWS][COLS], char show[ROWS][COLS], int row, int col)
//�������������0��1��ɵ�cal����
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < ROW*COL - Boom_Num)
	{
		printf("Please type in a coordinate: ");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= COL && y>=1 && y <= ROW)
		{
			printf("�����ж�ѭ��\n");
			printf("���������Ϊ(%d,%d)\n", x, y);
			//����ĵط�ǡ������
			if (Board[x][y] == '1') 
			{
				printf("You Died\n");
				DemoBoard(Board, ROW, COL);
				break;
			}
			else//������
			{
				int count = CountBoom(Board, x, y);
				printf("��λ�ø�������%d ����", count);
				show[x][y] = count + '0';
				//�ַ��������ֺ���ASCII���оͻ��ɶ�Ӧ��ŵ��ַ�
				DemoBoard(show, ROW, COL); 
				win++;
			}
		}
		else
		{
			printf("Error in coordinate! x and y should be in (1~9)");
		}

	}
	if (win == ROW * COL - Boom_Num)
	{
		printf("Congratulations! You win!\n");
		DemoBoard(Board, ROW, COL);
	}
}

