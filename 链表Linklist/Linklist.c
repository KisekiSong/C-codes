#include "Linklist.h"
#include<stdio.h>
#include<malloc.h>
#include<string.h>
Node* createList()
{
    Node* head = malloc(sizeof(Node));
    if (!head)
    {
        printf("head malloc failed");
        return NULL;
    }
    //��ʼ��ΪNULL
    //head->data = 0;
    //head->next = NULL;
    //��һ��Node��С������ȫ������Ϊ0
    memset(head, 0, sizeof(Node));

    return head;
}

void push_front(Node* list, Data val)
{
    Node* newNode = createNode(val);
    //1. �����½ڵ���������Ԫ�ڵ�
    newNode->next = list->next;
    //2. ͷ�ڵ��������½ڵ� 
    list->next = newNode;
}

void push_back(Node* list, Data val)
{
    //1.�ҵ����һ���ڵ�
    Node* curNode = list;
    while (curNode->next != NULL)
    {
        curNode = curNode->next;
    }
    //2.�����½ڵ�(����ʱ��ֵ)������
    Node* newNode = createNode(val);
    //2.1 ��β�ڵ�ָ���½ڵ�
    curNode->next = newNode;
    //2.2 ���µ�β�ڵ�ָ��ָ��NULL(�����ڵ�ʱĬ�����)

}

void insert_pos(Node* list, int pos, Data val)
{
    //���ҵ�pos֮ǰ�Ľڵ㣬��ʱcurNode->nextָ��posλ�õĽڵ�
    Node* curNode = list;
    //��ֹ�ߵ�����β��
    for (int i = 0; i < pos && curNode; i++)
    {
        curNode = curNode->next;
    }
    //2.0 ��������ֵ��Ȼ������
    Node* newNode = createNode(val);
    //2.1 �����½ڵ����Ϻ�һ���ڵ�
    newNode->next = curNode->next;
    //2.2 ��ǰһ���ڵ������½ڵ�
    curNode->next = newNode;
}

void insert_item(Node* list,Node* item, Data val)
{
    Node* newNode = createNode(val);
    //1. �½ڵ������Ϻ���Ľڵ�
    newNode->next = item->next;
    //2. ԭ���Ľڵ�item���ӵ��½ڵ�newNode
    item->next = newNode;
}

Node* find_item(Node* list, Data val)
{
    Node* curNode = list;
    while (curNode)
    {
        if (curNode->data == val)
            return curNode;
        curNode = curNode->next;
    }
    return NULL;
}

void pop_front(Node* list)
{
    //��headָ��ڶ����ڵ㣬��list->next = Node1->next;
    Node* delNode = list->next;
    list->next = delNode->next;
    free(delNode);
}

void pop_back(Node* list)
{ 
    Node* curNode = list;
    if (empty(list))
        return;
    //Ҫȷ������head����Ԫ�أ���������next��������
    while (curNode->next->next)
    {

        curNode = curNode->next;
    }
    //curNode�ǵ����ڶ����ڵ�
    curNode->next = NULL;
    free(curNode);
}

void removeOne(Node* list, Data val)
{
    if (empty(list))
        return;
    Node* preNode = list;
    Node* curNode = list->next;
    while (curNode)
    {
        if (curNode->data == val)
        {
            break;
        }
        //����ǰһ���ڵ�ĵ�ַ��Ϣ������������nextָ��ĵ�ַ
        preNode = curNode;
        curNode = curNode->next;
    }
    //ɾ��curNodeָ��Ľڵ㣬preNodeָ��curNode��һ���ڵ�
    if (curNode)
    {
        preNode->next = curNode->next;
        free(curNode);
    }

}

void removeAll(Node* list, Data val)
{
    if (empty(list))
        return;

    Node* preNode = list;
    Node* curNode = list->next;
    Node* delNode = NULL;
    while (curNode)
    {
        if (curNode->data == val)
        {
            //Ҫɾ���ڵ�ǰ�Ľڵ�ָ��Ҫɾ���ڵ�֮��Ľڵ�
            //����ɾ����ĩβ�ڵ�Ҳ���£���ʱpreNode->next == NULL;
            //��Ϊ�µ�ĩβ�ڵ�
            preNode->next = curNode->next;
            delNode = curNode;
            curNode = curNode->next;
        }
        else 
        {
            //�����ɾ������preNode���ñ䣬����ɾ����preNode���Ұָ����
            preNode = curNode;
            curNode = curNode->next;
        }
        if (delNode)
        {
            free(delNode);
            delNode = NULL;
        }
    }
}

void sort(Node* list)
{
    if (empty(list))
        return;
    //ð������
    for (Node* i = list->next; i->next; i = i->next)
    {
        for (Node* curNode = list->next; curNode->next; curNode = curNode->next)
        {
            if (curNode->data > curNode->next->data)
            {
                Data v = curNode->data;
                curNode->data = curNode->next->data;
                curNode->next->data = v;
            }
        }
    }
}

void reverse(Node* list)
{
    //����ķ����ǿ���ַ�Ĵ�ű�ʾ��
    //������õ�ַ�Ĵ�Ž�������ô�Ϳ���ʵ������
    //�����head��ָ��ԭ����ĩβ�ڵ�
    Node* preNode = NULL;
    //preNode��ʼ��ΪNULL���������Ԫ�ڵ���Ҫָ��NULL������
    Node* curNode = list->next;
    Node* nextNode = NULL;
    if (empty(curNode))
        return;

    while (curNode)
    {
        //�ȼ�¼��һ���ڵ�ĵ�ַ
        nextNode = curNode->next;
        curNode->next = preNode;
        preNode = curNode;
        curNode = nextNode;
    }
    list->next = preNode;

}

void clear(Node* list)
{
    Node* curNode = list->next;
    Node* delNode = NULL;
    while (curNode)
    {
        delNode = curNode;
        curNode = curNode->next;
        free(delNode);
        delNode = NULL;
    }
    list->next = NULL;
}

void destory(Node** list)
{
    //�������
    clear(*list);
    free(*list);
    (*list) = NULL;
}



void show_list(Node* list)
{
    //��Ҫ��Ԫ�ڵ��0
    if (list == NULL)
        return;
    Node* curNode = list->next;
    while (curNode != NULL)
    {
        printf("%d\n", curNode->data);
        curNode = curNode->next;
        //push_front �Ľ��Ϊ0 4 3 2 1����һ��0��head��������ͷ��
        //�����������ǰ��

        //push_back �Ľ��Ϊ0 1 2 3 4����һ��0��head��β�壬4�����
    }
}

bool empty(Node* list)
{
    return list->next == NULL;
}

Node* createNode(Data val)
{
    Node* newNode = malloc(sizeof(Node));
    if (!newNode)
    {
        printf("newNode creation failed\n");
        return NULL;
    }
    newNode->data = val;
    newNode->next = NULL;

    return newNode;
}