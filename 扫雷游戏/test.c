#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void menu()
{
	printf("**********************\n");
	printf("******** 1.play ******\n");
	printf("******** 0.exit ******\n");
}

void game()
{
	char mine[ROWS][COLS];//��Ų��úõ��׵�����
	char show[ROWS][COLS];//����Ų�����׵�����

	InitBoard(mine, ROWS, COLS, '0');//û���׵�ʱ����0
	InitBoard(show, ROWS, COLS, '*');//û�Ų��ʱ����1

	//��ӡ����
	DisplayBoard(show, ROW, COL);

	//������
	SetMine(mine, ROW, COL);

	//�Ų���
	FindMine(mine, show, ROW, COL);

}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ���������ѡ��\n");
			break;
		}

	} while (input);
	return 0;
}