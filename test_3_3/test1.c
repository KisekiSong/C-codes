#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<time.h>
int main()
{
	//int num = 0;
	//printf("Please input a number:\n");
	//scanf("%d", &num);
	//switch (num)
	//{
	//case 1:
	//	printf("Today is Monday");
	//	break;
	//case 2:
	//	printf("Today is Tuesday");
	//	break;
	//case 3:
	//	printf("Today is Wendesday");
	//	break;
	//case 4:
	//	printf("Today is Thursday");
	//	break;
	//case 5:
	//	printf("Today is Friday");
	//	break;
	//case 6:
	//	printf("Today is Saturday");
	//	break;
	//case 7:
	//	printf("Today is Sunday");
	//	break;
	//default:
	//	printf("Number Error, please try again\n");
	//	break;
	//}

	//int num = 0;
	//int norm = 0;
	//printf("Please input a number:\n");
	//scanf("%d", &num);
	//while (num)
	//{
	//	norm = num % 10;
	//	num = num / 10;
	//	printf("%d\n", norm);
		
	//}
		//int i = 0;
		//int j = 1;
		//for (i = 100; i <= 200; i++) {
		//	while ( j <= i ) {
		//		j++;//��2��ʼ����ȡ����
		//		if (i % j == 0)//�����������˵����������
		//			break;
		//	}
		//	if (j == i )//���һֱ�Գ���i == j��˵��������
		//		printf(" %d", i);
		//	j = 1;
		//}
	//srand((unsigned int)time(NULL));
	//printf("%d\n", rand());
	//printf("%d\n", rand());
	//printf("%d\n", rand());
	//printf("%d\n", rand());
	//printf("%d\n", rand());
	//printf("%d\n", rand());

	//��ͨ�汾��ch2���ȸ���ch1���ȣ�
	//int right = 0;
	//int left = 0;
	//int length = 0;
	//char ch1[] = "Oiiai Oiiai Oiiai";//�����ʼ��ʱ������ĩβ����һ��'\0'��ʵ��ռ��18�ֽ�
	//length = strlen(ch1);//����strlen���ַ������ȣ������ַ������Ȳ�������β��'0'
	////printf("%d", length);
	//char ch2[sizeof(ch1)] = {0};/*����sizeof�����ķ���ֵ�ǳ�������Ϊch2�Ĵ�С��
	//								�����˲����ñ����涨�����С������*/
	//int i = 0;
	//for (i; i <= length - 1; i++) 
	//{
	//	ch2[i] = '*';
	//	if (length - 1 == i)
	//		ch2[i + 1] = '\0';//�ֶ���ӽ�β��\0ռλ������ֹ����
	//}
	//right = length - 1;
	//while (left <= right)
	//{
	//	ch2[left] = ch1[left];
	//	ch2[right] = ch1[right];
	//	left++;
	//	right--;
	//	printf("%s\n", ch2);
	//}

	//����&sleep�汾
	//int right = 0;
	//int left = 0;
	//int length = 0;
	//char ch1[] = "Ciallo Ciallo Ciallo";//�����ʼ��ʱ������ĩβ����һ��'\0'��ʵ��ռ��18�ֽ�
	//length = strlen(ch1);//����strlen���ַ������ȣ������ַ������Ȳ�������β��'0'
	////printf("%d", length);
	//char ch2[sizeof(ch1)] = { 0 };/*����sizeof�����ķ���ֵ�ǳ�������Ϊch2�Ĵ�С��
	//								�����˲����ñ����涨�����С������*/
	//int i = 0;
	//for (i; i <= length - 1; i++)
	//{
	//	ch2[i] = '*';
	//	if (length - 1 == i)
	//		ch2[i + 1] = '\0';//�ֶ���ӽ�β��\0ռλ������ֹ����
	//}
	//right = length - 1;
	//while (left <= right)
	//{
	//	system("cls");//ʹ��windows.h�⺯���е�system������ʹ�ÿ� ������
	//	ch2[left] = ch1[left];
	//	ch2[right] = ch1[right];
	//	left++;
	//	right--;
	//	printf("%s\n", ch2);
	//	Sleep(1000);
	//}
	
	//���ֲ���---ǰ���������������
	//��һ������������в���ָ��������n
	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	//             0,1,2,3,4,5,6,7,8,9
	int left = 0;
	int right = sizeof(arr1)/4 - 1;//������int���飬ÿһ��Ԫ��ռ4��byte������char���͵���һ��β��ռλ��\0
	int guessnum = 0;
	printf("Please type in a number: ");
	scanf("%d", &guessnum);

	int halfval = 0;
	while (arr1[left] <= guessnum && arr1[right] >= guessnum)//ֻ�е��ڷ�Χ�ڵ�ʱ��Ž�������
	{
		//halfval = (right + left) / 2;//������ֵ������գ����õķ�����ʹ�ã�a+(b-a)/2
		halfval = left + (right - left) / 2;
		if (guessnum < arr1[halfval]){
			right = halfval;
		}
		else if (guessnum > arr1[halfval]) {
			left = halfval;
			if (halfval == right - 1)//��ֹ�������������/���޷���left�ߵ�rightʱ������
				left++;              //Ҳ�����ڸ��������±��ʱ��ʹ��halfval+1/halfval-1
		}
		else if (guessnum = arr1[halfval]) {
			printf("The guess number is %d\n", arr1[halfval]);
			printf("It is on position %d\n",halfval);
			break;
		}
	}
	if (guessnum != arr1[halfval])
		printf("The guess number is not in the data");

	return 0;
}