#pragma once
#include<stdbool.h>
typedef int Data;

typedef struct _Node
{
	Data data;
	struct _Node* next;		//���ָ��
	struct _Node* prev;		//ǰ��ָ��
}Node;						//�ڵ�����

//����ڵ������
typedef struct DoubleList
{
	int size;
	Node* front;			//ָ��ͷ�ڵ��ָ��
	Node* tail;				//ָ��β�ڵ��ָ��

}DuList;					//˫������

//����һ��˫������
DuList* createDuList();


void push_back(DuList* list, Data data);
void push_front(DuList* list, Data data);
void push_insert(DuList* list, Data data);

//ɾ��
void pop_back(DuList* list);
void pop_front(DuList* list);
void erase_val(DuList* llist, Data data);
//����ڵ�����
void show_list(DuList* list);

//����ָ��Ԫ�أ��ҵ��󷵻ؽڵ����ڵĵ�ַ��û�ҵ�����NULL
Node* find(DuList* list, Data data);
//�ж������Ƿ�Ϊ��
bool empty(DuList* list);
void insert(DuList* list, Data data);
void sort(DuList* list);
void clear(DuList* list);
void destory(DuList** list);

void reverse(DuList* list);

//�ж��Ƿ�Ϊ������
bool is_empty(DuList* list);
