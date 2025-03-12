#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include"game.h"


int main()
{
	srand((unsigned int)time(NULL));
	//生成两个棋盘，一个用来设置雷，另一个用来计算周围的雷
	char setboard[ROWS][COLS];
	char calboard[ROWS][COLS] ;

	//使用初始化函数来初始化这两个棋盘
	//给用户看的棋盘初始化为全“*”
	//另一个期盼初始化为全“0”
	InitBoard(setboard, ROWS, COLS, '*');
	InitBoard(calboard, ROWS, COLS, '0');


	//用户需要看到9*9的格子，打印棋盘
	DemoBoard(setboard, ROW, COL);
	printf("-----------------------------------------\n");
	//calboard不需要给用户看到，我们自己计算就好
	//DemoBoard(calboard, ROWS, COLS);
	//给calboard进行埋雷，并打印埋好的雷

	//设置雷
	SetBoom(calboard, ROWS, COLS);
	DemoBoard(calboard, ROW, COL);

	//开始扫雷
		//请求用户输入坐标
	FindBoom(calboard, setboard, ROWS, COLS);

	return 0;
}