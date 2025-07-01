#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include"Linklist.h"

int main()
{
	Node* list = createList();
	push_front(list, 1);
	push_front(list, 5);
	push_front(list, 1);
	push_front(list, 4);
	show_list(list);
	printf("---------------\n");
	destory(&list);
	show_list(list);
	return 0;
}

//int main()
//{
//	Node* list = createList();
//	push_front(list, 1);
//	push_front(list, 2);
//	push_front(list, 3);
//	//push_front(list, 4);
//	//push_back(list, 1);
//	//push_back(list, 2);
//	//push_back(list, 3);
//	//push_back(list, 4);
//	insert_pos(list,0, 3);
//	insert_pos(list, 3, 3);
//	push_back(list, 3);
//	show_list(list);
//
//	removeAll(list, 3);
//	printf("-------------------\n");
//	show_list(list);
//
//	return 0;
//}