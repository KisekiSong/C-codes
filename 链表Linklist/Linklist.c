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
    //初始化为NULL
    //head->data = 0;
    //head->next = NULL;
    //把一个Node大小的内容全部设置为0
    memset(head, 0, sizeof(Node));

    return head;
}

void push_front(Node* list, Data val)
{
    Node* newNode = createNode(val);
    //1. 先让新节点连接上首元节点
    newNode->next = list->next;
    //2. 头节点连接上新节点 
    list->next = newNode;
}

void push_back(Node* list, Data val)
{
    //1.找到最后一个节点
    Node* curNode = list;
    while (curNode->next != NULL)
    {
        curNode = curNode->next;
    }
    //2.创建新节点(创建时赋值)并连接
    Node* newNode = createNode(val);
    //2.1 让尾节点指向新节点
    curNode->next = newNode;
    //2.2 让新的尾节点指针指向NULL(创建节点时默认完成)

}

void insert_pos(Node* list, int pos, Data val)
{
    //先找到pos之前的节点，此时curNode->next指向pos位置的节点
    Node* curNode = list;
    //防止走到超过尾部
    for (int i = 0; i < pos && curNode; i++)
    {
        curNode = curNode->next;
    }
    //2.0 创建并赋值，然后连接
    Node* newNode = createNode(val);
    //2.1 先让新节点连上后一个节点
    newNode->next = curNode->next;
    //2.2 让前一个节点连上新节点
    curNode->next = newNode;
}

void insert_item(Node* list,Node* item, Data val)
{
    Node* newNode = createNode(val);
    //1. 新节点连接上后面的节点
    newNode->next = item->next;
    //2. 原来的节点item连接到新节点newNode
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
    //让head指向第二个节点，即list->next = Node1->next;
    Node* delNode = list->next;
    list->next = delNode->next;
    free(delNode);
}

void pop_back(Node* list)
{ 
    Node* curNode = list;
    if (empty(list))
        return;
    //要确保除了head还有元素，否则两个next会界外访问
    while (curNode->next->next)
    {

        curNode = curNode->next;
    }
    //curNode是倒数第二个节点
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
        //保存前一个节点的地址信息，方便后面更改next指向的地址
        preNode = curNode;
        curNode = curNode->next;
    }
    //删除curNode指向的节点，preNode指向curNode下一个节点
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
            //要删除节点前的节点指向要删除节点之后的节点
            //就算删掉了末尾节点也不怕，此时preNode->next == NULL;
            //成为新的末尾节点
            preNode->next = curNode->next;
            delNode = curNode;
            curNode = curNode->next;
        }
        else 
        {
            //如果不删除，则preNode不用变，否则删除了preNode变成野指针了
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
    //冒泡排序
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
    //链表的方向是靠地址的存放表示的
    //如果能让地址的存放交换，那么就可以实现逆序
    //逆序后head旧指向原来的末尾节点
    Node* preNode = NULL;
    //preNode初始化为NULL，解决了首元节点需要指向NULL的问题
    Node* curNode = list->next;
    Node* nextNode = NULL;
    if (empty(curNode))
        return;

    while (curNode)
    {
        //先记录下一个节点的地址
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
    //清空链表
    clear(*list);
    free(*list);
    (*list) = NULL;
}



void show_list(Node* list)
{
    //不要首元节点的0
    if (list == NULL)
        return;
    Node* curNode = list->next;
    while (curNode != NULL)
    {
        printf("%d\n", curNode->data);
        curNode = curNode->next;
        //push_front 的结果为0 4 3 2 1，第一个0是head，由于是头插
        //最后插入的在最前面

        //push_back 的结果为0 1 2 3 4，第一个0是head，尾插，4在最后
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