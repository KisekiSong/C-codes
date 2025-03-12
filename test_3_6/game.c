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
	//添加一个行和列的标号功能
	int i = 0;

	for (i = 0; i <= col; i++) {
		printf("%d  ", i);
		//先把第一行的标号打印了，再打印剩下的
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d  ", i);
		//第一列也全部打印标号，在打印剩下的列
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
	//在9*9的格子里面随机选择一个坐标，先检测该坐标是否为0，如果为0则赋值为1作为雷
	//如果已经不为0，则重新开始选随机数
	//使用time(NULL)和rand函数，以及srand来实现随机
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
	//手动计算，利用字符的加减从字符--->整型
	//return Board[x - 1][y] + Board[x - 1][y - 1] +
	//	Board[x][y - 1] + Board[x + 1][y - 1] +
	//	Board[x + 1][y] + Board[x + 1][y + 1] +
	//	Board[x][y + 1] + Board[x - 1][y + 1] - 8 * '0';
	//循环计算：
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
//输入进来的是由0和1组成的cal数组
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
			printf("进入判断循环\n");
			printf("输入的坐标为(%d,%d)\n", x, y);
			//输入的地方恰好是雷
			if (Board[x][y] == '1') 
			{
				printf("You Died\n");
				DemoBoard(Board, ROW, COL);
				break;
			}
			else//不是雷
			{
				int count = CountBoom(Board, x, y);
				printf("该位置附近共有%d 个雷", count);
				show[x][y] = count + '0';
				//字符加上数字后在ASCII码中就会变成对应编号的字符
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

