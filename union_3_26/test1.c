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
            char title[20];//����
            char author[20];//����
            int num_pages;//ҳ��
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
    }item;//�������������ֽ�item������������������ṹ��
    //�����ṹ������ֱַ�Ϊ��book, mug,shirt
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
    char c[5];//��СΪ5���ֽڣ�����4����������������8���ֽ�
    int i;//��СΪ4���ֽ�
};

union Un2
{
    short c[7];// ��СΪ7*2=14�ֽڣ�����4����������������16���ֽ�
    int i;//��СΪ4���ֽ�
};

//int main()
//{
//    printf("%d\n", sizeof(union Un1));//Un1�ĳ���Ϊ8���ֽ�
//    printf("%d\n", sizeof(union Un2));//Un2�ĳ���Ϊ16���ֽ�
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
        printf("С�˴洢\n");
    }
    else
    {
        printf("��˴洢\n");
    }
    return 0;
}

