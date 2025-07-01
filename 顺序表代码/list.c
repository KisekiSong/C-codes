#include "list.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//ͷ�ļ�ֻ��.c�ļ���ʹ�ã���ֻ������.c�ļ������ö�д��.h�ļ�
bool inc(SeqList* list)
{
    DATA* t = realloc(list ->arr, sizeof(DATA)*(list->capacity + 5));
    if (!t)
    {
        return false;
    }
    else
    {
        return true;
    }
}


SeqList* createSeqList()
{
    //����һ��˳���
    SeqList* list = calloc(1, sizeof(SeqList));
    //��������Ϊ1��������СΪsizeof(SeqList)���ֽ�
    if (!list)
    {
        printf("list creation failed");
        return NULL;
    }
    list->capacity = SEQLIST_INIT_SIZE;
    list->size = 0;
    list -> arr = calloc(list->capacity, sizeof(DATA));
    if (!list->arr)
    {
        printf("list->arr creation failed\n");
        free(list);
        return NULL;
    }
    return list;
}

void push_back(SeqList* list, DATA val)
{
    //ϰ���ȼ���������������else���ܻᵼ�¸���Ƕ��
    if (list->size == list->capacity && !inc(list))
    {
        printf("list is full, push back failed\n");
        return;
    }
    //���뵽��ЧԪ�ص���һ��λ��
    list->arr[list->size] = val;
    //����ЧԪ�ظ���++
    list->size++;
}

void push_front(SeqList* list, DATA val)
{
    if (list->size == list->capacity)
    {
        printf("list is full, push_front failed\n");
        return;
    }
    //���뵽�±�Ϊ0��λ��
    //���ƶ�Ԫ����λ��
    for (int i = list->size; i > 0; i--)
    {
        list->arr[i] = list->arr[i - 1];
    }
    //���ǵ���һ��λ��
    list->arr[0] = val;
    list->size++;
}

void insert(SeqList* list, int pos, DATA val)
{
    //�ȼ����Ƿ��пռ�
    if (list->size == list->capacity)
    {
        printf("list is full, insert failed\n");
        return;
    }
    //�����û�������±��Ƿ�Ϸ�
    if (pos < 0 || pos >= list->capacity)
    {
        printf("pos out of range\n");
        return;
    }
    //���û���½ᣬ���ǲ����λ�ò��ڲ��뷶Χ0��list->size
    //����λ�õ�β������
    if (pos > list->size)
    {
        pos = list->size;
    }
    
    //�������
    for (int i = list->size; i > pos; i--)
    {
        list->arr[i] = list->arr[i - 1];
    }
    list->arr[pos] = val;
    list->size++;
}

void show_list(SeqList* list)
{
    for (int i = 0; i < list->size; i++)
    {
        printf("%d\n", list->arr[i]);
    }
}

void pop_front(SeqList* list)
{
    removeIndex(list, 0);
}

void pop_back(SeqList* list)
{
    if (list->size == 0)
    {
        printf("˳���Ϊ�գ��޷�ɾ��\n");
        return;
    }
    removeIndex(list, list->size-1);
}

void removeIndex(SeqList* list, int pos)
{
    //�ж�pos�Ƿ�Ϸ�
    if (pos < 0 || pos >= list->capacity)
    {
        return;
    }
    //�Ϸ������ǲ�����ЧԪ������
    if (pos >= list->size)
    {
        return;
    }
    for (int i = pos; i < list->size - 1; i++)
    {
        list->arr[i] = list->arr[i + 1];
    }
    list->size--;
}

void removeOne(SeqList* list, DATA val)
{
    //�Ȳ��ң���ɾ��
    for (int i = 0; i < list->size; i++)
    {
        if (list->arr[i] == val)
        {
            removeIndex(list, i);
            break;
        }
    }
}

void removeAll(SeqList* list, DATA val)
{
    //�Ȳ��ң���ɾ��
    for (int i = 0; i < list->size; )
    {
        if (list->arr[i] == val)
        {
            removeIndex(list, i);
        }
        else
        {
            //ֻ����list->arr[i] != valʱ����i++
            i++;
        }
    }
}

int size(SeqList* list)
{
    return list->size;
}

void clear(SeqList* list)
{
    list->size = 0;
}

void sort(SeqList* list)
{
    //ð������
    for (int i = 0; i < list->size - 1; i++)
    {
        for (int k = 0; k < list->size - i - 1; k++)
        {
            if (list->arr[k] > list->arr[k + 1])
            {
                DATA t = list->arr[k];
                list->arr[k] = list->arr[k + 1];
                list->arr[k + 1] = t;
            }
        }
    }
}

void reverse(SeqList* list)
{
    for (int i = 0; i < list->size / 2; i++)
    {
        DATA t = list->arr[i];
        list->arr[i] = list->arr[list->size - i - 1];
        list->arr[list->size - i - 1] = t;
    }
}

int find(SeqList* list, int val)
{
    for (int i = 0; i < list->size; i++)
    {
        if (list->arr[i] == val)
        {
            return i;
        }
    }
    return -1;
}


