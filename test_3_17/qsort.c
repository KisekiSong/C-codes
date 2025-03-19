#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//冒泡排序：一次只解决一个数字
//这里的BBL_sort只能处理整型数组的排序，而qsort可以处理任何类型的数据
void BBL_sort(int *arr, int sz)//传数组可以写arr[]，也可以写int *arr
{
	//没有设置返回值，直接用指针对地址上的值进行修改
	//首先需要一个变量存储中间值
	int flag = 1;
	int i = 0;
	int temp = 0;
	//do {
	//	flag = 0;
	//	for (i = 0; i < sz -1; i++)
	//	{
	//		if (arr[i] > arr[i + 1])//按照升序排列，换顺序就把不等号反一下
	//		{
	//			temp = arr[i];
	//			arr[i] = arr[i + 1];
	//			arr[i + 1] = temp;
	//			flag = 1;
	//		}
	//	}
	//} while (flag);
	
	//冒泡排序一次解决一个数，比如0~9，第一趟会把9搬到最右边/最左边
	//那么最右边/最左边的这个数字我们就可以不考虑了
	//只需要看剩下的数字即可，不用再每个都检查一遍
	do {
		flag = 0;
		for (i = 0; i < sz - 1; i++)
		{
			int j = 0;
			for (j = 0; j < sz - 1; j++)
			{
				if (arr[j] > arr[j + 1])//按照升序排列，换顺序就把不等号反一下
				{
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
					flag = 1;
				}
			}
		}
	} while (flag);
}


//尝试使用qsort排序
//qsort是一个库函数，在已知类型的情况下，可对任意类型进行排序
//其包含4个参数：
//void qsort (void* base, size_t num, size_t size,
//				int (*compar)(const void*, const void*));
//cplusplus官网上对各个参数的解释如下：
//void* base: 指向待排序数组的第一个object
//size_t num: base指针指向的数组的元素个数，size_t是无符号整型
//size_t size: 数组中每个元素的byte数
//compar：是一个函数指针，指向的函数返回类型为int，形参为2个const void* 类型的指针
//const表示无法更改指针指向地址的内容；void表示无法对指针进行解引用操作
//同时，compar是需要我们自己来完成的，其要求是：
// int compareMyType (const void * a, const void * b)
//{
//	if (*(MyType*)a < *(MyType*)b) return 负数;
//	if (*(MyType*)a == *(MyType*)b) return 0;
//	if (*(MyType*)a > *(MyType*)b) return 正数;
//}
//前 > 后，返回负数
//前 == 后，返回0
//前 < 后, 返回正数

//由于不同类型的量比较方法不同, 所以要有各个变量对应的compar函数:
int compar_int(const void* p1, const void* p2)
{
	return *((int*)p1) - *((int*)p2);
}




//int main()
//{
//	int arr[] = { 3,1,7,9,4,2,6,5,8,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//BBL_sort(arr, sz);
//	qsort(arr, sizeof(arr)/sizeof(arr[0]), sizeof(arr[0]), compar_int);
//	//这里第二个是数组的长度,不是byte数
//	//compar_int这里只需要传入就可以了,不用指定谁和谁比较,qsort会反复调用compar_int直到排序完成
//	int i = 0;  
//	for (i = 0; i < sz; i++) {
//		printf("%d\n", arr[i]);
//	}
//
//
//	return 0;
//}
struct Stu {

	char name[20];
	int age;
	float grade;
};
int compar_uestc_age(const void* p1, const void* p2)
{
	//return (*(struct Stu*)p1).age - (*(struct Stu*)p2).age;
	//可以写成三目操作符的方式，同样简介，而且可以改变升降序
	int age1 = ((struct Stu*)p1)->age;
	int age2 = ((struct Stu*)p2)->age;
	return (age1 > age2) ? -1 : ((age1 < age2) ? 1 : 0);
	// if age1 > age2 ---> return -1
	// if age1 < age2 ---> return 1
	// else return 0
}
int compar_uestc_name(const void* p1, const void* p2)
{
	//字符串的比较需要用到strcmp函数
	//作为string.h下的库函数, strcmp会诸位对应比较ASCII码的大小
	//一但分出大小, 就直接结束比较, 返回
	//返回的值与qsort要求的返回值相同,前 < 后 返回负数, 前 == 后 返回0，前 > 后 返回正数
	return strcmp(((struct Stu*)p1)->name, (*(struct Stu*)p2).name);
	//这里是要把结构体根据名字，按照升序排列，所以这里的指针强制转换类型为struct Stu*类型，即结构体指针类型
	//结构体指针类型解引用的两种方式：
	// 1.直接用 指针名->成员名
	// 2.解引用：*指针名.成员名
}
int compar_uestc_grade(const void* g1, const void* g2)
{
	//return ((struct Stu*)g1)->grade - ((struct Stu*)g2) ->grade;
	//这样直接返回，比较的结果不准
	//如果要用 结构体指针 -> 成员名 的方式获取成员的值，必须要确保箭头左边是结构体指针
	//这里需要先进行强制转换，再来与 -> 结合访问成员的值，需要加上小括号
	float grade1 = ((struct Stu*)g1)->grade;
	float grade2 = ((struct Stu*)g2)->grade;
	return (grade1 > grade2) ? 1 : (grade1 < grade2) ? -1 : 0;
	//利用三目操作符，严格按照compar的返回类型int进行返回，得到的结果正确
	//如果强行使用(int)，本来差距都很小，四舍五入直接为0，所以排序出来，结果没变化
}


int main()
{
	struct Stu uestc[] = {{"Niuzhuxi", 114, 3.85}, {"Laozhao", 514, 3.94}, {"Laowang", 1919, 3.57},{"Kangkang", 810, 3.74}};
	//按照年龄排列
	//qsort(uestc, sizeof(uestc) / sizeof(uestc[0]), sizeof(uestc[0]), compar_uestc_age);

	//按照字符串排列
	//qsort(uestc, sizeof(uestc) / sizeof(uestc[0]), sizeof(uestc[0]), compar_uestc_name);

	//按照成绩排列
	qsort(uestc, sizeof(uestc) / sizeof(uestc[0]), sizeof(uestc[0]), compar_uestc_grade);


	return 0;
}
