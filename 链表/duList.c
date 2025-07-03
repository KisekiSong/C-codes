#include"duList.h"
#include<malloc.h>
#include<assert.h>
#include<stdio.h>
DuList* createDuList()
{
	//创建了一个头节点 Dummy List
	//该节点不存储数据，包含了3个指针和一个计量器size
	DuList* list = calloc(1, sizeof(DuList));
	assert(list != NULL);
	//创建头节点
	list->front = calloc(1, sizeof(Node));
	assert(list->front != NULL);
	list->tail = list->front; 		//头和尾指针都指向head节点
	size_t size = 0;

	return list;
}

Node* createNode(Data data)
{
	Node* newNode = calloc(1, sizeof(Node));
	if (newNode == NULL)
		return NULL;
	newNode->data = data;
	return newNode;
}

void push_back(DuList* list, Data data)
{
	Node* newNode = createNode(data);

	//list中的tail是链表尾部的地址，这时访问这个地址对应的节点中的next
	//并将其赋值给newNode指向的地址的next指针，此时newNode成为最后一个
	newNode->next = list->tail->next;
	//此时tail所指向的节点变成了倒数第二个
	newNode->prev = list->tail;
	//list->tail是指向原尾部节点的指针，让原来的尾部节点连接到新节点
	list->tail->next = newNode;
	//list->tail现在需要指向新的尾部节点
	list->tail = newNode;
	list->size++;
}

void push_front(DuList* list, Data data)
{
	Node* newNode = createNode(data);
	//新节点也指向原来的头的下一个节点
	newNode->next = list->front->next;
	//list->front指向的是head节点，其不存储数据也不移动位置
	//所有头插是插入在head节点之后
	newNode->prev = list->front;

	list->front->next = newNode;
	newNode->next->prev = newNode;
	list->size++;

}

void push_insert(DuList* list, Data data)
{

}
//尾部删除
void pop_back(DuList* list)
{
	if (empty(list))
		return;
	//让尾指针往前移一位
	list->tail = list->tail->prev;
	free(list->tail->next);
	list->tail->next = NULL;
	list->size--;
}

void pop_front(DuList* list)
{
	if (empty(list))
		return;
	Node* delNode = list->front->next;
	//头节点指向第二个节点
	list->front->next = delNode->next;
	//判断节点是否只有一个，如果只有一个，需要对尾节点特殊处理
	if (delNode->next != NULL)
	{
		delNode->next->prev = list->front;
	}
	else
	{
		//如果只有一个，尾节点指针与头节点指针都指向head节点
		list->tail = list->front;
	}
	//让第二个节点的prev指向头节点
	free(delNode);
	list->size--;
}

void erase_val(DuList* list, Data data)
{
	Node* delNode = find(list, data);
	if (delNode == NULL)
		return;
	//   prevNode       delNode      delNode->next
	// prev    next    prev  next  prev      next
	Node* prevNode = delNode->prev;
	prevNode->next = delNode->next;
	delNode->next->prev = prevNode;
	free(delNode);
	list->size--;
}

void show_list(DuList* list)
{
	if (empty(list))
		return;
	Node* curNode = list->front->next;
	while (curNode != NULL)
	{
		printf("%d ", curNode->data);
		curNode = curNode->next;
	}
	printf("\n");
}


Node* find(DuList* list, Data data)
{
	if (empty(list))
		return NULL;
	//从第一个节点开始
	Node* curNode = list->front->next;
	//没走到最后一个就一直走
	while (curNode != NULL)
	{
		if (curNode->data == data)
		{
			return curNode;
		}
		curNode = curNode->next;
	}
	return NULL;
}

bool empty(DuList* list)
{
	return list->size == 0;
}
void insert(DuList* list, Data pos_data, Data data)
{
	//节点顺序：prevNode      newNode      iterator
//        prev   next   prev   next  prev     next
	Node* newNode = createNode(data);
	Node* iterator = find(list, pos_data);
	Node* prevNode = iterator->prev;	//保存要插入位置的上一个节点

	newNode->next = iterator;
	newNode->prev = prevNode;
	//前面的节点
	iterator->prev = newNode;
	prevNode->next = newNode;
	list->size++;
}
void sort(DuList* list) 
{
	if (empty(list))
		return;
	for (Node* i = list->front->next; i->next != NULL; i = i->next)
	{
		for (Node* k = list->front->next; k->next != NULL; k = k->next)
		{
			if (k->data > k->next->data)
			{
				Data t = k->data;
				k->data = k->next->data;
				k->next->data = t;
			}
		}
	}
}

void destory(DuList** list)
{
	clear(*list);
	free((*list)->front);
	free(*list);
	*list = NULL;
}

void reverse(DuList* list)
{
	if (list->size <= 1)
	{
		return;
	}
	Node* curNode = list->front->next;
	Node* prevNode = NULL;
	Node* nextNode = NULL;
	list->tail = curNode;
	//     prevNode         curNode          nextNode
	//  prev     next     prev    next      prev    next
	while (curNode != NULL)
	{
		nextNode = curNode->next;
		curNode->next = prevNode;
		curNode->prev = nextNode;
		
		prevNode = curNode;
		curNode = nextNode;
	}
	list->front->next = prevNode;
	prevNode->prev = list->front;

}

void clear(DuList* list)
{
	if (empty(list))
		return;
	while (list->front->next != NULL)
	{
		pop_front(list);
	}
	list->size = 0;
}





