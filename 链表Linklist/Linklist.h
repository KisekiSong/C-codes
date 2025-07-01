#pragma once
#include<stdbool.h>
//Abstract Data Type 抽象数据类型
typedef int Data;

//定义节点类型
typedef struct Node
{
	Data data;			//数据域；存储的是数据
	struct Node* next;  //指针域，存储的是下一个节点
}Node;

//创建链表
Node* createList();
//创建节点
Node* createNode();
//头插入
void push_front(Node* list, Data val);
//尾插入
void push_back(Node* list, Data val);
//指定位置插入(序号)
void insert_pos(Node* list, int pos,Data val);
//指定位置插入（指针）
void insert_item(Node* list, Node* item, Data val);
//查找元素
Node* find_item(Node* list, Data val);

//头删
void pop_front(Node* list);
//尾删
void pop_back(Node* list);
//指定元素删除
void removeOne(Node* list, Data val);
void removeAll(Node* list, Data val);


//排序
void sort(Node* list);
//反转
void reverse(Node* list);

//清空链表
void clear(Node* list);
//销毁链表
void destory(Node** list);
//遍历链表并输出
void show_list(Node* list);
//判断链表是否为空
bool empty(Node* list);