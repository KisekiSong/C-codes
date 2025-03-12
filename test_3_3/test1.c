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
		//		j++;//从2开始尝试取余数
		//		if (i % j == 0)//如果被整除，说明不是质数
		//			break;
		//	}
		//	if (j == i )//如果一直试除到i == j，说明是质数
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

	//普通版本（ch2长度跟随ch1长度）
	//int right = 0;
	//int left = 0;
	//int length = 0;
	//char ch1[] = "Oiiai Oiiai Oiiai";//数组初始化时，会在末尾增加一个'\0'，实际占用18字节
	//length = strlen(ch1);//利用strlen求字符串长度，这里字符串长度不会计算结尾的'0'
	////printf("%d", length);
	//char ch2[sizeof(ch1)] = {0};/*利用sizeof函数的返回值是常数来作为ch2的大小，
	//								避免了不能用变量规定数组大小的问题*/
	//int i = 0;
	//for (i; i <= length - 1; i++) 
	//{
	//	ch2[i] = '*';
	//	if (length - 1 == i)
	//		ch2[i + 1] = '\0';//手动添加结尾的\0占位符，防止乱码
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

	//清屏&sleep版本
	//int right = 0;
	//int left = 0;
	//int length = 0;
	//char ch1[] = "Ciallo Ciallo Ciallo";//数组初始化时，会在末尾增加一个'\0'，实际占用18字节
	//length = strlen(ch1);//利用strlen求字符串长度，这里字符串长度不会计算结尾的'0'
	////printf("%d", length);
	//char ch2[sizeof(ch1)] = { 0 };/*利用sizeof函数的返回值是常数来作为ch2的大小，
	//								避免了不能用变量规定数组大小的问题*/
	//int i = 0;
	//for (i; i <= length - 1; i++)
	//{
	//	ch2[i] = '*';
	//	if (length - 1 == i)
	//		ch2[i + 1] = '\0';//手动添加结尾的\0占位符，防止乱码
	//}
	//right = length - 1;
	//while (left <= right)
	//{
	//	system("cls");//使用windows.h库函数中的system函数，使得可 屏操作
	//	ch2[left] = ch1[left];
	//	ch2[right] = ch1[right];
	//	left++;
	//	right--;
	//	printf("%s\n", ch2);
	//	Sleep(1000);
	//}
	
	//二分查找---前提是数据是有序的
	//在一个升序的数组中查找指定的数字n
	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	//             0,1,2,3,4,5,6,7,8,9
	int left = 0;
	int right = sizeof(arr1)/4 - 1;//这里是int数组，每一个元素占4个byte，不像char类型的有一个尾部占位符\0
	int guessnum = 0;
	printf("Please type in a number: ");
	scanf("%d", &guessnum);

	int halfval = 0;
	while (arr1[left] <= guessnum && arr1[right] >= guessnum)//只有当在范围内的时候才进行搜索
	{
		//halfval = (right + left) / 2;//存在数值溢出风险，更好的方法是使用：a+(b-a)/2
		halfval = left + (right - left) / 2;
		if (guessnum < arr1[halfval]){
			right = halfval;
		}
		else if (guessnum > arr1[halfval]) {
			left = halfval;
			if (halfval == right - 1)//防止被查数据在最后，/号无法让left走到right时程序卡死
				left++;              //也可以在更新左右下标的时候，使用halfval+1/halfval-1
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