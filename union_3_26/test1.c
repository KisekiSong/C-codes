#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

struct gift_list
{
    int stock_num;
    double price;
    int item_type;


    union {
        struct
        {
            char title[20];//书名
            char author[20];//作者
            int num_pages;//页数
        }book;
        struct
        {
            char design[30];
        }mug;
        struct
        {
            char design[30];
            int colors;
            int sizes;
        }shirt;
    }item;//这个联合体的名字叫item，其包含了三个匿名结构体
    //三个结构体的名字分别为：book, mug,shirt
};
enum Cal
{
    Exit,//0
    Add,//1
    Sub,//2
    Mul,//3
    Div//4
};
//int mian()
//{
//    int n = 0;
//    scanf("%d", &n);
//    switch (n)
//    {
//        case Exit;
//            break;
//        case Add;
//            Add();
//            break;
//        case Sub;
//            Sub();
//            break;
//        case Mul;
//            Mul;
//            break;
//        case Div;
//            Div();
//            break;
//    }
//    return 0;
//}
union Un1
{
    char c[5];//大小为5个字节，不是4的整数倍，补长到8个字节
    int i;//大小为4个字节
};

union Un2
{
    short c[7];// 大小为7*2=14字节，不是4的整数倍，补长到16个字节
    int i;//大小为4个字节
};

//int main()
//{
//    printf("%d\n", sizeof(union Un1));//Un1的长度为8个字节
//    printf("%d\n", sizeof(union Un2));//Un2的长度为16个字节
//    return 0;
//}
union Un
{
    char c;
    int i;
};
int mian()
{
    union Un un1 = { 0 };
    un1.i = 1;
    if (un1.c == 1)
    {
        printf("小端存储\n");
    }
    else
    {
        printf("大端存储\n");
    }
    return 0;
}

