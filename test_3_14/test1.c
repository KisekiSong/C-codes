#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
//��һ�棺��ʵ�ֹ��ܣ�����ָ��p�Ĺ���ƫ��
int pfm = 0;
void BBL(int* arr, int sz)
{
	//ð�����򣺴������һ��Ԫ�ؿ�ʼ������Ԫ�������Ƚϣ�����������Ҳ࣬����߽���λ��
	//ֱ������λ�ò�������ִ�У�˵��ִ�����
	//ʹ��һ��ָ��
	int i = 0;
	int mid = 0;
	while (pfm == 0) 
	{
		//��һ��ȫ�ֱ���pfm��Ϊ��־����whileѭ���ڣ�pfm�ȱ���1�����������λ�ý������Ͱ�pfm��Ϊ0��˵�������ڽ���
		//���������������������pfm��ֵû����0��������whileѭ�����������
		pfm = 1;
		for (i = 0; i < sz - 1; i++)
		{

			if (arr[i] > arr[i + 1])
			{
				//����λ��
				mid = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = mid;
				pfm = 0;
			}
		}
	}

}






int main()
{
	int arr[10] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	printf("Please type in a integar sery: ");
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		scanf("%d", &arr[i]);
	}
	//����ð���������������������������С
	BBL(arr, sz);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}