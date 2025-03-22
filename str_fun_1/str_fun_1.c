#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<assert.h>
char* my_strcpy(char* dest, const char* src)
{
    assert(dest && src);
    char* ret = dest;//strcpy返回的是被赋值字符串的首地址，但是由于我们在不停移动赋值，这里用一个新的变量来保存首值
    while (*dest++ = *src++)
        //++的优先级高于*，但是由于是后置++，解引用和赋值操作会先进行，
        // 最后再进行++，这样就算到了 \0， 也能先做到赋值，然后跳出循环
        // 注意：赋值表达式本身是有值的，这里赋值完成后就是表达式的值
    {

    }
    return ret;
}

char* my_strcat(char* dest, char* src)
{
    char* ret = dest;
    //1. 找目标空间的\0
    while (*dest)
    {
        dest++;
    }
    //2. 拷贝过来,与strcpy相同的写法
    while (*dest++ = *src++)
        ;
    return ret;
}

char* my_strcmp(const char* str1, const char* str2)
{
    while (*str1 == *str2)
    {
        if (*str1 == '\0')//相等的情况，一直到最后str1=str2且str1='0'
        {
            return 0;
        }
        str1++;
        str2++;
    }
    if (*str1 > *str2)//大于的情况，返回大于0的数
    {
        return 1;
    }
    else//小于0的情况，返回小于0的数，相等的情况在while循环里面
        return -1;
}
//记得要考虑多次匹配的情况
//char* my_strstr(const char* str1, const char* str2)
//{
//    //先让他们逐个比较，如果不相等则继续，如果连续相等
//    int flag = 0;
//    char* ret_str2 = str2;
//    char* ret = NULL;
//    int sz_str2 = strlen(str2);
//    while (*str1 != '\0')
//    {
//        if (*str1 == *str2)
//        {
//            //先让ret指向这里开始的地方
//            for (ret = str1; *str1 == *str2; flag++)
//            {
//                str1++;
//                str2++;
//            }
//        }
//        if ((flag == sz_str2) && (*ret == *(str1 - sz_str2)))
//        {
//            return ret;
//        }
//        else
//        {
//            flag = 0;
//            ret = NULL;
//            str2 = ret_str2;
//        }
//        str1++;
//    }
//    return 0;
//
//}

const char* my_strstr(const char* str1, const char* str2)
{
    assert(str1 && str2);
    const char* s1 = NULL;
    const char* s2 = NULL;
    const char* cur = str1;

    //特殊情况 - str2指向的时空字符串，直接返回str1
    if (*str2 == '\0')
    {
        return str1;
    }
    //当目前指向的位置不为'\0'时
    while (*cur)
    {
        s1 = cur;
        s2 = str2;
        while (s1 && s2 && *s1 == *s2)
        {
            s1++;
            s2++;
        }

        if (*s2 == '\0')
        {
            return cur;
        }
        cur++;
    }
    return NULL;
}

void* my_memcpy(void* dest, const void* src, size_t num)
{
    int i = 0;
    void* ret = dest;
    assert(dest && src);
    //断言二者不是空指针
    for (i = 0; i < num; i++)
    {
        *(char*)dest = *(char*)src;
        //由于char类型之占用1个字节，在内存上表示，1个字节就是一个单位
        //找不到比这精确度更高的类型了，因此用char类型
        //每次+1就是往前挪动1个char类型的内存宽度
        dest = (char*)dest + 1;
        src = (char*)src + 1;
        //由于强制类型转换后，是临时的，++无法让转换后的临时指针类型移动
        //而++(char*)dest;的写法在不同编译器中可能报错，不能这么写
    }
    return ret;
}

void* my_memmove(void* dest, const void* src, size_t num)
{
    void* ret = dest;
    if (dest < src)//数据的存放是从低地址到高地址，从低位到高位
        //如果src在dest后面，进行向前拷贝，因为就算重叠也是在后面重叠，这个地方的数据已经拷贝走了
    {
        while (num--)
        {
            *(char*)dest = *(char*)src;
            dest = (char*)dest + 1;
            src = (char*)src + 1;
        }
    }
    else
    {
        while (num--)
        {
            *((char*)dest + num) = *((char*)src + num);
        }
    }
    return ret;

}

int main()
{
    //char arr[] = "Ich bin Student";
    //int i = 0;
    //while (arr[i] != '\0')
    //{
    //    if (islower(arr[i]))
    //    //如果返回为真，则进行大小写转换操作
    //    //char类型其实就是ASCII码值，将小写字母的ASCII码值减去32，就得到了大写字母的ASCII码值
    //    {
    //        arr[i] -= 32;
    //    }
    //    i++;
    //}
    //printf("%s\n", arr);

    //char str1[] = "Sample string";
    //char str2[40];//空间足够大
    //char str3[40];//空间足够大
    //strcpy(str2, str1);//把str的内容，拷贝到str2中
    //strcpy(str3, "copy successful");//把后面的copy successful拷贝到str3中
    //printf("str1: %s\nstr2: %s\nstr3: %s\n", str1, str2, str3);

    //char arr1[] = "abcdef";
    //char arr2[20] = { 0 };
    //char* pstr = my_strcpy(arr2, arr1);

    //printf("%s\n", arr2);
    //printf("%s\n", pstr);
    //printf("%s\n", my_strcpy(arr2, arr1));

    //int a = 115;
    //int b = 514;

    //printf("%d\n", a = b);//打印结果为514，即b的值
    ////因此可以发现，赋值表达式本身是有值的，其值就是最终赋给最左边变量的值
    ////while(*dest++ = *src++)
    ////这里也是同理，当进行了\0这个NULL值的赋值后，跳出while循环

    //char arr1[20] = "hello ";
    //char arr2[] = "world";

    //mystrcat(arr1, arr2);
    //printf("%s\n", arr1);

    //char arr1[] = "ciallo~";
    //char arr2[] = "yarimasune";
    ////int ret = my_strcmp(arr1, arr2);
    ////printf("%d\n", ret);
    //strncpy(arr2, arr1, 8);

    //char* str1 = "So hello from the other side~ I must've called a thousand times~";
    //char* str2 = "fuck";

    //char* ret = my_strstr(str1, str2);
    //if (ret == NULL)
    //    printf("不存在\n");
    //else
    //    printf("%s\n", ret);

    int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
    my_memmove(arr1, arr1 + 3, 20);

    return 0;
}