#ifndef _SEQLIST_H_
#define _SEQLIST_H_
#define SEQLIST_INIT_SIZE 8		//˳����ʼ��С
typedef int DATA;

typedef struct SeqList
{
	DATA* arr;
	int capacity;
	int size;
}SeqList;
//����SeqList�����

//����˳���
SeqList* createSeqList();
//����һ����������������ΪSeqListָ�룬����Ҫ������������ΪcreateSeqList

//β������
void push_back(SeqList* list, DATA val);

//ͷ������
void push_front(SeqList* list, DATA val);

//ָ��λ�ò���
void insert(SeqList* list, DATA val);

//��ӡlist
void show_list(SeqList* list);

//ͷɾ
void pop_front(SeqList* list);
//βɾ
void pop_back(SeqList* list);
//ָ��λ��ɾ��
void removeIndex(SeqList* list, int pos);
//ɾ��ָ����ֵ��ֻɾ����һ����
void removeOne(SeqList* list, DATA val);
//ɾ��ָ����ֵ�����ж�ɾ����
void removeAll(SeqList* list, DATA val);

//��ȡ��С
int size(SeqList* list);
//���˳���
void clear(SeqList* list);
//����
void sort(SeqList* list);
//˳��ת
void reverse(SeqList* list);

//����ָ����Ԫ��
int find(SeqList* list, int val);

#endif