#define _CRT_SECURE_NO_WARNINGS
#include"duList.h"
#include<stdio.h>

void menu()
{
	printf("******************************\n");
	printf("*[1]push_back   [2]push_front*\n");
	printf("*[3]insert      [4]show_list *\n");
	printf("*[5]pop_back    [6]pop_front *\n");
	printf("*[7]removeIndex [8]removeOne *\n");
	printf("*[9]removeAll   [10]size     *\n");
	printf("*[11]sort       [12]clear    *\n");
	printf("*[13]quit       [14]cls      *\n");
	printf("*[15]reverse                 *\n");
	printf("******************************\n");
}

int main()
{
	DuList* list = createDuList();
	menu();
	Data val;

	while (true)
	{
		int op = -1;
		int pos = -1;
		printf("Input->");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
			printf("请输入数据>");
			scanf("%d", &val);
			push_back(list, val);
			break;
		case 2:
			printf("请输入数据>");
			scanf("%d", &val);
			push_front(list, val);
			break;
		case 3:
			printf("请输入插入位置后的数据和要插入的数据>");
			scanf("%d %d", &pos, &val);
			insert(list, pos, val);
			break;
		case 4:
			show_list(list);
			break;
		case 5:
			pop_back(list);
			break;
		case 6:
			pop_front(list);
			break;
		case 7:
			printf("请输入位置>\n");
			//removeIndex(list, pos);
			break;
		case 8:
			printf("请输入要删除的元素>\n");
			scanf("%d", &val);
			//removeOne(list, val);
			break;
		case 9:
			printf("请输入要删除的元素>\n");
			scanf("%d", &val);
			//removeAll(list, val);
			break;
		case 10:
			printf("size = %d\n", list->size);
			break;
		case 11:
			sort(list);
			break;
		case 12:
			//clear(list);
			break;
		case 13:
			return 0;
			break;
		case 14:
			//system("cls");
			break;
		case 15:
			reverse(list);
			break;
		default:
			printf("输入有误，请重新输入\n");
		}
	}

	return 0;

	return 0;
}