#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
//int findnum(int a[][3], int x, int y, int f)
////xΪ�У�yΪ�У�fΪҪ�ҵ�������
//{
//    int i = 0;
//    int j = y - 1;
//    //�����Ͻǿ�ʼ����
//    while (j >= 0 && i < x)
//    {
//        if (a[i][j] < f)
//        {
//            //�ȸ�ֵ�󣬿���һ��
//            i++;
//        }
//        else if (a[i][j] > f)
//        {
//            //�����Ͻ�С�������һ��
//            j--;
//        }
//        else
//            //����˵���ҵ��ˣ�����1
//            return 1;
//    }
//    //�����뿪ѭ����˵��û�ҵ�������0
//    return 0;
//}
//int main()
//{
//    int a[][3] = { {1,3,5}, {2,4,6}, {3,5,7} };
//    if (findnum(a, 3, 3, 2)) {
//        printf("Number founded");
//    }
//    else
//    {
//        printf("Number not found");
//    }
//
//
//    return 0;
//}

//�ж�����
//A˵������
//B˵��C
//C˵��D
//D˵C˵�Ĳ���
//�����ö�ά���飬ÿ�����������ٻ������������û�мٻ�����˵���������
//����ASCII���˳��������abcd
//#include<stdio.h>
//int main()
//{
//	int killer = 0;
//	for (killer = 'a'; killer <= 'd'; killer++)
//	{
//		//����ASCII��ֵʵ��abcd���л�
//		if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer !='d') == 3)
//		{
//			printf("������: %c", killer);
//		}
//	}
//	return 0;
//}
//#include<string.h>
//#include<stdio.h>
////�����ַ��������һ���ַ�������ʾ�������ַ���s��ת��Ľ��
//
//int main()
//{
//	char str[10000] = { 0 };
//	gets(str);
//	int len = strlen(str);
//	for (int i = 0; i < len; i++)
//	{
//		printf("%c", str[len - i - 1]);
//	}
//	return 0;
//}

//�ַ�������
//ʵ��һ�����������������ַ����е�k���ַ���
//���磺
//ABCD����һ���ַ��õ�BCDA
//
//ABCD���������ַ��õ�CDAB
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZEOF_CHAR 1
int left_rev(char* str, int k)
{
	//����k���ַ��Ŀռ�ʱ���ǵö����һ����װ'\0'
	int len = strlen(str);
	if (len == 0 || k <= 0)
		return;
	else if (len == k)
	{
		for (int i = len - 1; i >= 0; i--)
		{
			printf("%c", str[i]);
		}
		return 0;
	}

	//������ʱ�ռ�洢ǰk���ַ�
	char* tmp = (char*)calloc(k+1, 1);
	if (tmp == NULL)
	{
		perror(calloc);
		return -1;
	}
	//����ǰ��k���ַ�
	strncpy(tmp, str, k);
	tmp[k] = '\0';

	//�ƶ�������ַ���ǰ����
	memmove(str, str + k, len - k);
	//��str+k��ʼ����ʣ�µ�len-k���ַ��ƶ������ȥ
	//memmove�Զ������ص�����

	//׷����ʱ�ַ���ĩβ
	strncpy(str+len - k, tmp, k);
	free(tmp);
	printf("after rotating 1: %s\n", str);
}
int main()
{
	char sample[] = "ABCD";  // �޸�Ϊ�ɱ���ַ�����
	printf("Original: %s\n", sample);
	left_rev(sample, 1);

	char sample2[] = "ABCD";  // �޸�Ϊ�ɱ���ַ�����
	left_rev(sample2, 2);

	char sample3[] = "ABCD";  // �޸�Ϊ�ɱ���ַ�����
	left_rev(sample3, 3);

	char sample4[] = "ABCD";  // �޸�Ϊ�ɱ���ַ�����
	left_rev(sample4, 4);
	return 0;
}
