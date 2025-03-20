#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp_int(const void* p1, const void* p2)
{
	int a = *(int*)p1;
	int b = *(int*)p2;
	//增加很多可读性
	return ( a > b ) ? 1 : (a < b) ? -1 : 0;
	// if p1的整数 > p2的整数 ---> return -1
	// if p1的整数 < p的整数 ---> return 1
	// else return 0
}
int cmp_char(const void* p1, const void* p2)
{
	//字符串的比较需要用到strcmp函数
	//作为string.h下的库函数, strcmp会诸位对应比较ASCII码的大小
	//一但分出大小, 就直接结束比较, 返回
	//返回的值与qsort要求的返回值相同,前 < 后 返回负数, 前 == 后 返回0，前 > 后 返回正数
	return strcmp((char*)p1,(char*)p2);
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
	//float grade1 = ((struct Stu*)g1)->grade;
	//float grade2 = ((struct Stu*)g2)->grade;
	//return (grade1 > grade2) ? 1 : (grade1 < grade2) ? -1 : 0;
	//利用三目操作符，严格按照compar的返回类型int进行返回，得到的结果正确
	//如果强行使用(int)，本来差距都很小，四舍五入直接为0，所以排序出来，结果没变化
}

void Swap(char* p1, char* p2, size_t width, int mode)
{
	//char类型只有一个字节，因此只要知道了目标元素的宽度
	//不会有比char内存上更短的类型了，因此我们借用char类型
	// 就可以对其每一个字节进行赋值与交换

	int i = 0;
	char tmp = 0;
	if (mode == 1)
	{
		for (i = 0; i < width; i++)
		//这里的width是每个元素的宽度width
		//通过p1++和p2++来移动，逐步实现交换
		{
			tmp = *p1;
			*p1 = *p2;
			*p2 = tmp;

			p1++;
			p2++;
		}
	}

}

//利用冒泡排序实现qsort功能---可以排列任意类型的数据
void bubble_qsort(void* base, size_t sz, size_t width, int(*cmp)(const void*, const void*))
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (cmp((char*)base+j*width, (char*)base+(j+1)*width) > 0)
			//如果比较函数的结果大于0，则执行相邻元素交换
			//虽然cmp的形参类型为const void*，这里实参传过去的是char*
			//但是C语言允许指针的隐式转换，即从具体类型指针转换到void*，不用我们单独写转换语句
			//反之，如果是从void*转换到具体类型，则需要写转换语句
			//这里就是从char*隐式转换到consts void*类型
			//总结：将函数的形参设置为 const void*有很多好处
			//1. const保证了该指针的指向不会被修改，增强robustness
			//2. void*类型保证了指针无法被解引用或进行运算
			//3. 如果真的要进行操作，可以按照具体类型进行转换，有更高的灵活性
			{
				//交换的代码
				Swap((char*)base+j*width,(char*)base+(j+1)*width, width, 1);
			}

		}
	}


}


int main()
{
	int arr1[] = { 0, 5, 2, 4, 3, 9, 7, 6, 8, 1 };
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	bubble_qsort(arr1, sz, sizeof(arr1[0]), cmp_int);

	char arr2[][15] = {{"Bitch"},{"Ass"}, {"MotherFxxker"}};
	int sz2 = sizeof(arr2) / sizeof(arr2[0]);
	bubble_qsort(arr2, sz2, sizeof(arr2[0]), cmp_char);
	//注意strcmp需要传入指向字符串的第一个字符的指针

	return 0;
}