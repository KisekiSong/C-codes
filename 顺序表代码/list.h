#ifndef _SEQLIST_H_
#define _SEQLIST_H_
#define SEQLIST_INIT_SIZE 8		//顺序表初始大小
typedef int DATA;

typedef struct SeqList
{
	DATA* arr;
	int capacity;
	int size;
}SeqList;
//定义SeqList这个类

//创建顺序表
SeqList* createSeqList();
//这是一个函数，返回类型为SeqList指针，不需要参数，函数名为createSeqList

//尾部插入
void push_back(SeqList* list, DATA val);

//头部插入
void push_front(SeqList* list, DATA val);

//指定位置插入
void insert(SeqList* list, DATA val);

//打印list
void show_list(SeqList* list);

//头删
void pop_front(SeqList* list);
//尾删
void pop_back(SeqList* list);
//指定位置删除
void removeIndex(SeqList* list, int pos);
//删除指定的值（只删除第一个）
void removeOne(SeqList* list, DATA val);
//删除指定的值（所有都删除）
void removeAll(SeqList* list, DATA val);

//获取大小
int size(SeqList* list);
//清空顺序表
void clear(SeqList* list);
//排序
void sort(SeqList* list);
//顺序反转
void reverse(SeqList* list);

//查找指定的元素
int find(SeqList* list, int val);

#endif