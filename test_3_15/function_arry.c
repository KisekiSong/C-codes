#define _CRT_SECURE_NO_WARNINGS
typedef int (*pf_t)(int, int);
#include<stdio.h>
int Add(int x, int y)
{
    return x + y;
}
int Sub(int x, int y)
{
    return x - y;
}
int Mul(int x, int y)
{
    return x * y;
}
int Div(int x, int y)
{
    return x / y;
}

int main()
{
    //����ָ�����͵����飺
    int (*pf_1[4])(int, int) = { Add, Sub, Mul, Div };
    pf_t pf_2[4] = { Add, Sub, Mul, Div };
    //������ͬ���͵ĺ���ָ�룬�����޷�����������

    int i = 0;
    for (i = 0; i < 4; i++)
    {
        int ret1 = pf_1[i](6, 2);
        int ret2 = pf_2[i](6, 2);
        printf("%d %d\n", ret1, ret2);

    }


    return 0;
}