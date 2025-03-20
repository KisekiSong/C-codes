#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//int main()
//{
//	char arr[] = "abcdef";
//	printf("strlen(arr) = %zd\n", strlen(arr));//正常使用，输出6
//	printf("strlen(arr + 0) = %zd\n", strlen(arr + 0));//正常使用，输出6
//	//printf("strlen(*arr) = %zd\n", strlen(*arr));//首元素地址解引用，把首元素传给了strlen，出错
//	//printf("strlen(arr[1]) = %zd\n", strlen(arr[1]));//同上，传入了第二个元素
//	printf("strlen(&arr) = %zd\n", strlen(&arr));//传入的是数组地址，恰好和数组首元素地址指向同一个位置的
//	//都是从第一个元素的位置，向后访问
//	//&arr是一个形如char (*p) [7]的数组指针，而strlen的形参是char* 类型，这里发生了隐式转换
//	//实参的内容拷贝给了形参，正好就是首元素的地址，可以正常求出长度
//	printf("strlen(&arr + 1) = %zd\n", strlen(&arr + 1));//跳过了当前数组地址，随机值
//	printf("strlen(&arr[0] + 1) = %zd\n", strlen(&arr[0] + 1));//传入了第二个元素的地址，输出5
//
//
//	return 0;
//}


//int main()
//{
//	char* p = "abcdef";
//	printf("sizeof(p) = %d\n", sizeof(p));
//	printf("sizeof(p+1) = %d\n", sizeof(p + 1));
//	printf("sizeof(*p) = %d\n", sizeof(*p));
//	printf("sizeof(p[0]) = %d\n", sizeof(p[0]));
//	printf("sizeof(&p) = %d\n", sizeof(&p));
//	printf("sizeof(&p+1) = %d\n", sizeof(&p + 1));
//	printf("sizeof(&p[0] + 1) = %d\n", sizeof(&p[0] + 1));
//
//
//
//	return 0;
//}

//int main()
//{
//	char* p = "abcdef";
//	printf("%d\n", strlen(p));//阴差阳错，反正首元素地址传给strlen了，输出为6
//	printf("%d\n", strlen(p + 1));//输出为5，因为从第二个开始数
//	//printf("%d\n", strlen(*p));//解引用p，即把a输入了，没有输入地址，err
//	//printf("%d\n", strlen(p[0]));//同上
//	printf("%d\n", strlen(&p));//输入的是p的地址，而非首元素地址，内存越界访问，随机值
//	printf("%d\n", strlen(&p + 1));//同上
//	printf("%d\n", strlen(&p[0] + 1));//从第二个元素开始数，输出为5
//
//	return 0;
//}


int main()
{
	//int a[3][4] = { 0 };
	//printf("%zd\n", sizeof(a));//首元素的地址，从a[0][0]开始，一直到最后结束，因为二维数组在内存上是连续存放的，12*4=48
	//printf("%zd\n", sizeof(a[0][0]));//指明了是一个元素，大小为4
	//printf("%zd\n", sizeof(a[0]));//a[0]是第一行这个一维数组的名，计算的是第一行的内存大小，4*4=16
	//printf("%zd\n", sizeof(a[0] + 1));//这里a[0]是第一行的数组名，但是已经退化为了地址，所以这里是求地址a[0][1]的大小，4/8
	//printf("%zd\n", sizeof(*(a[0] + 1)));//解引用，括号内部等价于&a[0][0]+1 = a[0][1]，解引用后大小为int类，4个bytes。
	//									//（这里一维数组名a[0]退化为首元素a[0][0]的地址）
	//printf("%zd\n", sizeof(a + 1));//a退化为a[0]这个一维数组的地址，+1表示a[1]这个一维数组的地址
	//printf("%zd\n", sizeof(*(a + 1)));//把a看作元素是一维数组的数组，a表示首元素地址，即第一个一维数组的地址，+1并解引用来到第二个
	//								//这时a[1]单独放在了sizeof内部，代表一个数组，因此大小为4*4=16
	//printf("%zd\n", sizeof(&a[0] + 1));//地址，4或8
	//printf("%zd\n", sizeof(*(&a[0] + 1)));//第二个一维数组的大小，4*4=16
	//printf("%zd\n", sizeof(*a));//第一个一维数组的大小，4*4=16
	//printf("%zd\n", sizeof(a[3]));//不会真实去访问a[3]，这里取的其实是一种类型，即int [4]这种类型，直接得到16 

	//int a[5] = { 1,2,3,4,5 };
	//int* ptr = (int*)(&a + 1);
	//printf("%d %d", *(a + 1), *(ptr - 1));

	//int a[3][2] = { (0,1), (1,2), (2,3) };
	//int* p;
	//p = a[0];//这里a[0]是第一个数组的数组名，现在退化成第一个数组的首元素地址
	////所以p = &a[0][0]
	//printf("%d", p[0]);

	//int a[5][5];
	//int(*p)[4];
	//p = a;//a的首元素地址赋值给了p，这里给p的是a的第一行那个1*5的一维数组的地址
	////但是p的类型是长度为4的一维数组指针，类型为int，但是现在要存一个1*5数组的地址
	////结果就是造成截断，虽然p拿到了数组地址，但是对p进行运算操作，比如p+1，只会移动4个int变量的长度，而不是5个
	//printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
	////下面的【】表示一个int类型的内存大小，二维数组在内存中也是连续存放的，总共25个，为了方便观察，每行用空格隔开
	//// 【】【】【】【】【】 【】【】【】【】【】 【】【】【】【】【】 【】【】【】【】【】 【】【】【】【】【】
	////  p
	////                 |                |               |                 |p+4                    a[4][2]
	////                 |                |               |                 |      p[4][2]          
	////所以&p[4][2] - a[4][2] = -4，因为隔了4个字节，在地址上就是相差4
	////%d打印就为-4，但是%p打印的时候，会认为这个-4是地址，会按照地址打印
	////又因为-4在计算机中储存的是补码，而不是原码，补码=原码除开第一位按位取反 再 + 1（针对负数，正数原反补相同）
	////10000000000000000000000000000100 --- 原码
	////11111111111111111111111111111011 --- 反码
	////11111111111111111111111111111100 --- 补码
	////将补码转化成16进制地址打印：
	////0xFF FF FF FC


	//int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//int* ptr1 = (int*)(&aa + 1);
	////指向了下一个二维数组，但是ptr1 int类型数组，加减只移动1个int单位

	//int* ptr2 = (int*)(*(aa + 1));
	////aa这时表示首元素地址，即a[0]这个数组的地址
	////&a[0]+1 = &a[1],然后强转int类型，加减只移动1个int单位
	//printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
	////*（ptr - 1) = 10, *(ptr2 - 1) = 5

	//char* a[] = { "work","at","alibaba" };
	////指针数组，一共3个，每个指向这些字符串的地址
	//char** pa = a;
	////有一个二级指针，指向了指针数组， pa存了数组首元素的地址，也就是work的地址
	////pa++即得到了"at"的地址，打印出at
	//pa++;
	//printf("%s\n", *pa);

	char* c[] = { "ENTER","NEW","POINT","FIRST" };

	char** cp[] = { c + 3,c + 2,c + 1,c };
	//cp[] = {"FIRST", "POINT", "NEW", "ENTER"};
	char*** cpp = cp;
	//cpp = &cp[0] = "FIRST"
	printf("%s\n", **++cpp);//POINT
	printf("%s\n", *-- * ++cpp + 3);//"ER"
	printf("%s\n", *cpp[-2] + 3);//"ST"
	printf("%s\n", cpp[-1][-1] + 1);//"EW"


	return 0;
}