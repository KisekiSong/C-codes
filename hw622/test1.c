#define _CRT_SECURE_NO_WARNINGS
////ģ��ʵ��strlen
////�����ַ����׵�ַ
////���ƶ�ָ������Ӽ��������ж��Ƿ�������'\0'
////���ؼ�������ֵ
//#include<stdio.h>
//int my_strlen(const char* str)
//{
//	int len = 0;
//	char* start = str;
//	for (0; *start != '\0'; start++, len++)
//	{
//
//	}
//	return len;
//}
//
//int main()
//{
//	char* string1 = "Pinkman";
//	printf("The length is %d", my_strlen(string1));
//	//Ӧ����� The length is 7
//	return 0;
//}

//ʵ������ż����˳��
//��������ʹ����ȫ��λ��ż��ǰ��
//ż���ص㣺�����Ƶ����һλ�ض�Ϊ0
//�����ص㣺�����Ƶ����һλ�ض�Ϊ1
//˼·����������� ^ ���һλ���ֱ�������ż��
//��˳���½�2����̬�ڴ�ռ䣬�ֱ���strncpy���п���
//���������̬�ڴ�ռ�ƴ��
#include<stdio.h>
#include<stdlib.h>
int even_odd_grouping(int* ptr, int len)
{
	int* odd_tmp = (int*)calloc(len, sizeof(int));
	int* even_tmp = (int*)calloc(len, sizeof(int));
	int odd_idx = 0;
	int even_idx = 0;
	for (int i = 0; i < len; i++)
	{
		//�����0���õ�1��˵��ֵΪ���������������Ķ�̬�ڴ�
		if ((ptr[i] & 1) == 1)
		{
			odd_tmp[odd_idx++] = ptr[i];
		}
		else
		{
			even_tmp[even_idx++] = ptr[i];
		}
	}
	//�鵵���֮�󣬿�ʼƴ��
	//ʹ��memmove��even_tmp�������ƶ���odd_tmp�У�len-count����ż���ĸ���
	memcpy(odd_tmp+odd_idx, even_tmp, sizeof(int) * even_idx);
	//��ӡ�ֺ��������
	for (int i = 0; i < len; i++)
	{
		printf("%d", odd_tmp[i]);
	}

	//�����Ҫ�޸�ԭ���飬����ʹ��memcpy������ȥ����
}

int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	even_odd_grouping(arr,sizeof(arr)/sizeof(int));

}