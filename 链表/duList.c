#include"duList.h"
#include<malloc.h>
#include<assert.h>
#include<stdio.h>
DuList* createDuList()
{
	//������һ��ͷ�ڵ� Dummy List
	//�ýڵ㲻�洢���ݣ�������3��ָ���һ��������size
	DuList* list = calloc(1, sizeof(DuList));
	assert(list != NULL);
	//����ͷ�ڵ�
	list->front = calloc(1, sizeof(Node));
	assert(list->front != NULL);
	list->tail = list->front; 		//ͷ��βָ�붼ָ��head�ڵ�
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

	//list�е�tail������β���ĵ�ַ����ʱ���������ַ��Ӧ�Ľڵ��е�next
	//�����丳ֵ��newNodeָ��ĵ�ַ��nextָ�룬��ʱnewNode��Ϊ���һ��
	newNode->next = list->tail->next;
	//��ʱtail��ָ��Ľڵ����˵����ڶ���
	newNode->prev = list->tail;
	//list->tail��ָ��ԭβ���ڵ��ָ�룬��ԭ����β���ڵ����ӵ��½ڵ�
	list->tail->next = newNode;
	//list->tail������Ҫָ���µ�β���ڵ�
	list->tail = newNode;
	list->size++;
}

void push_front(DuList* list, Data data)
{
	Node* newNode = createNode(data);
	//�½ڵ�Ҳָ��ԭ����ͷ����һ���ڵ�
	newNode->next = list->front->next;
	//list->frontָ�����head�ڵ㣬�䲻�洢����Ҳ���ƶ�λ��
	//����ͷ���ǲ�����head�ڵ�֮��
	newNode->prev = list->front;

	list->front->next = newNode;
	newNode->next->prev = newNode;
	list->size++;

}

void push_insert(DuList* list, Data data)
{

}
//β��ɾ��
void pop_back(DuList* list)
{
	if (empty(list))
		return;
	//��βָ����ǰ��һλ
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
	//ͷ�ڵ�ָ��ڶ����ڵ�
	list->front->next = delNode->next;
	//�жϽڵ��Ƿ�ֻ��һ�������ֻ��һ������Ҫ��β�ڵ����⴦��
	if (delNode->next != NULL)
	{
		delNode->next->prev = list->front;
	}
	else
	{
		//���ֻ��һ����β�ڵ�ָ����ͷ�ڵ�ָ�붼ָ��head�ڵ�
		list->tail = list->front;
	}
	//�õڶ����ڵ��prevָ��ͷ�ڵ�
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
	//�ӵ�һ���ڵ㿪ʼ
	Node* curNode = list->front->next;
	//û�ߵ����һ����һֱ��
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
	//�ڵ�˳��prevNode      newNode      iterator
//        prev   next   prev   next  prev     next
	Node* newNode = createNode(data);
	Node* iterator = find(list, pos_data);
	Node* prevNode = iterator->prev;	//����Ҫ����λ�õ���һ���ڵ�

	newNode->next = iterator;
	newNode->prev = prevNode;
	//ǰ��Ľڵ�
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





