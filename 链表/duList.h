#pragma once
#include<stdbool.h>
typedef int Data;

typedef struct _Node
{
	Data data;
	struct _Node* next;		//后继指针
	struct _Node* prev;		//前驱指针
}Node;						//节点类型

//管理节点的链表
typedef struct DoubleList
{
	int size;
	Node* front;			//指向头节点的指针
	Node* tail;				//指向尾节点的指针

}DuList;					//双向链表

//创建一个双向链表
DuList* createDuList();


void push_back(DuList* list, Data data);
void push_front(DuList* list, Data data);
void push_insert(DuList* list, Data data);

//删除
void pop_back(DuList* list);
void pop_front(DuList* list);
void erase_val(DuList* llist, Data data);
//输出节点数据
void show_list(DuList* list);

//查找指定元素，找到后返回节点所在的地址，没找到返回NULL
Node* find(DuList* list, Data data);
//判断链表是否为空
bool empty(DuList* list);
void insert(DuList* list, Data data);
void sort(DuList* list);
void clear(DuList* list);
void destory(DuList** list);

void reverse(DuList* list);

//判断是否为空链表
bool is_empty(DuList* list);
