#pragma once
#include<stdbool.h>
//Abstract Data Type ������������
typedef int Data;

//����ڵ�����
typedef struct Node
{
	Data data;			//�����򣻴洢��������
	struct Node* next;  //ָ���򣬴洢������һ���ڵ�
}Node;

//��������
Node* createList();
//�����ڵ�
Node* createNode();
//ͷ����
void push_front(Node* list, Data val);
//β����
void push_back(Node* list, Data val);
//ָ��λ�ò���(���)
void insert_pos(Node* list, int pos,Data val);
//ָ��λ�ò��루ָ�룩
void insert_item(Node* list, Node* item, Data val);
//����Ԫ��
Node* find_item(Node* list, Data val);

//ͷɾ
void pop_front(Node* list);
//βɾ
void pop_back(Node* list);
//ָ��Ԫ��ɾ��
void removeOne(Node* list, Data val);
void removeAll(Node* list, Data val);


//����
void sort(Node* list);
//��ת
void reverse(Node* list);

//�������
void clear(Node* list);
//��������
void destory(Node** list);
//�����������
void show_list(Node* list);
//�ж������Ƿ�Ϊ��
bool empty(Node* list);