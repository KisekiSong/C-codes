#include<stdio.h>

typedef int Data;

typedef struct Node
{
	Data data;		//数据域
	struct Node* next;	//指针域，保存下一个节点的地址
	//这里不能直接写Node*，因为执行完typedef才有Node这个别名
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
//	//让结点连接
//	node1.next = &node2;
//	node2.next = &node3;
//	node3.next = &node4;
//	node4.next = &node5;
//	node5.next = NULL;
//	//最后一个指向NULL，标志着结束
//
//	//查看所有节点数据
//	Node* curNode = &node1;
//	//printf("%d\n", curNode->data);
//	////指向下一个node，进行地址赋值
//	//curNode = node1.next;
//	//printf("%d\n", curNode->data);
//
//	//打印所有的数据
//	//如果写成curNode->next != NULL 就不打印最后一个
//	while (curNode != NULL)
//	{
//		printf("%d\n", curNode->data);
//		curNode = curNode->next;
//	}
//
//	return 0;
//}