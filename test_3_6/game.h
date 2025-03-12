#pragma once
#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define Boom_Num 10
void InitBoard(char Board[ROWS][COLS], int row, int col, char CHA);

void DemoBoard(char Board[ROWS][COLS], int row, int col);

void SetBoom(char Board[ROWS][COLS], int row, int col);

int CountBoom(char Board[ROWS][COLS], int x, int y);
