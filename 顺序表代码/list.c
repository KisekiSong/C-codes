#include "list.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//头文件只在.c文件里使用，就只包含在.c文件，不用都写到.h文件
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
    //申请一个顺序表
    SeqList* list = calloc(1, sizeof(SeqList));
    //创建个数为1，单个大小为sizeof(SeqList)个字节
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
    //习惯先检查错误情况，如果用else可能会导致更多嵌套
    if (list->size == list->capacity && !inc(list))
    {
        printf("list is full, push back failed\n");
        return;
    }
    //插入到有效元素的下一个位置
    list->arr[list->size] = val;
    //让有效元素个数++
    list->size++;
}

void push_front(SeqList* list, DATA val)
{
    if (list->size == list->capacity)
    {
        printf("list is full, push_front failed\n");
        return;
    }
    //插入到下标为0的位置
    //先移动元素腾位置
    for (int i = list->size; i > 0; i--)
    {
        list->arr[i] = list->arr[i - 1];
    }
    //覆盖到第一个位置
    list->arr[0] = val;
    list->size++;
}

void insert(SeqList* list, int pos, DATA val)
{
    //先检验是否还有空间
    if (list->size == list->capacity)
    {
        printf("list is full, insert failed\n");
        return;
    }
    //检验用户输入的下表是否合法
    if (pos < 0 || pos >= list->capacity)
    {
        printf("pos out of range\n");
        return;
    }
    //如果没有月结，但是插入的位置不在插入范围0，list->size
    //修正位置到尾部插入
    if (pos > list->size)
    {
        pos = list->size;
    }
    
    //插入过程
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
        printf("顺序表为空，无法删除\n");
        return;
    }
    removeIndex(list, list->size-1);
}

void removeIndex(SeqList* list, int pos)
{
    //判断pos是否合法
    if (pos < 0 || pos >= list->capacity)
    {
        return;
    }
    //合法，但是不在有效元素区域
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
    //先查找，再删除
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
    //先查找，再删除
    for (int i = 0; i < list->size; )
    {
        if (list->arr[i] == val)
        {
            removeIndex(list, i);
        }
        else
        {
            //只有在list->arr[i] != val时，才i++
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
    //冒泡排序
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


