#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//int main()
//{
//	char arr[] = "hello world";
//	char* cptr = "hello world";
//
//	printf("%s", arr);
//	printf("\n");
//	printf("%s", cptr);
//	return 0;
//}
void Print(int(*p)[5], int r, int c)
{
    int i = 0;
    //传过来的参数arr是二维数组的首元素地址，即&arr[0]，也就是整个第一行的地址
    //int (*p)[5] = &arr[0] = arr
    //如果要访问第一个数组中的元素，我们可以写成：(*p)[j];其中 0 =< j < column
    //其中，[j]又可以表示为*((*p)+j)的方式
    //这样，我们就做到了只用p，j，*，完成对二维数组中元素的访问
    for (i = 0; i < r; i++)
    {
        int j = 0;
        for (j = 0; j < c; j++)
        {
            printf("%d", *(*(p+i) + j));
            //p指向的是arr[0]这整个数组，给p+1，指向的是下一个数组
            //这是因为二维数组在内存中的排序是连续的空间，一维数组都相邻排列
            //p[i]是第i行的数组名，数组名又表示数组首元素的地址，arr[i]表示是&arr[i][0]
            //由于地址连续，所以只要给地址+j，就可以访问到某一行的具体一个元素
        }
        printf("\n");
    }
}


//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5}, {2,3,4,5,6}, {3,4,5,6,7} };
//	Print(arr, 3, 5);
//
//	return 0;
//}