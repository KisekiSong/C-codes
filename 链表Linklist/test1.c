#include<stdio.h>

typedef int Data;

typedef struct Node
{
	Data data;		//������
	struct Node* next;	//ָ���򣬱�����һ���ڵ�ĵ�ַ
	//���ﲻ��ֱ��дNode*����Ϊִ����typedef����Node�������
}Node;


//
//int main()
//{
//	Node node1 = { 1,NULL };
//	Node node2 = { 2,NULL };
//	Node node3 = { 3,NULL };
//	Node node4 = { 4,NULL };
//	Node node5 = { 5,NULL };
//
//	//�ý������
//	node1.next = &node2;
//	node2.next = &node3;
//	node3.next = &node4;
//	node4.next = &node5;
//	node5.next = NULL;
//	//���һ��ָ��NULL����־�Ž���
//
//	//�鿴���нڵ�����
//	Node* curNode = &node1;
//	//printf("%d\n", curNode->data);
//	////ָ����һ��node�����е�ַ��ֵ
//	//curNode = node1.next;
//	//printf("%d\n", curNode->data);
//
//	//��ӡ���е�����
//	//���д��curNode->next != NULL �Ͳ���ӡ���һ��
//	while (curNode != NULL)
//	{
//		printf("%d\n", curNode->data);
//		curNode = curNode->next;
//	}
//
//	return 0;
//}