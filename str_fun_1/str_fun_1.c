#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<assert.h>
char* my_strcpy(char* dest, const char* src)
{
    assert(dest && src);
    char* ret = dest;//strcpy���ص��Ǳ���ֵ�ַ������׵�ַ���������������ڲ�ͣ�ƶ���ֵ��������һ���µı�����������ֵ
    while (*dest++ = *src++)
        //++�����ȼ�����*�����������Ǻ���++�������ú͸�ֵ�������Ƚ��У�
        // ����ٽ���++���������㵽�� \0�� Ҳ����������ֵ��Ȼ������ѭ��
        // ע�⣺��ֵ���ʽ��������ֵ�ģ����︳ֵ��ɺ���Ǳ��ʽ��ֵ
    {

    }
    return ret;
}

char* my_strcat(char* dest, char* src)
{
    char* ret = dest;
    //1. ��Ŀ��ռ��\0
    while (*dest)
    {
        dest++;
    }
    //2. ��������,��strcpy��ͬ��д��
    while (*dest++ = *src++)
        ;
    return ret;
}

char* my_strcmp(const char* str1, const char* str2)
{
    while (*str1 == *str2)
    {
        if (*str1 == '\0')//��ȵ������һֱ�����str1=str2��str1='0'
        {
            return 0;
        }
        str1++;
        str2++;
    }
    if (*str1 > *str2)//���ڵ���������ش���0����
    {
        return 1;
    }
    else//С��0�����������С��0��������ȵ������whileѭ������
        return -1;
}
//�ǵ�Ҫ���Ƕ��ƥ������
//char* my_strstr(const char* str1, const char* str2)
//{
//    //������������Ƚϣ��������������������������
//    int flag = 0;
//    char* ret_str2 = str2;
//    char* ret = NULL;
//    int sz_str2 = strlen(str2);
//    while (*str1 != '\0')
//    {
//        if (*str1 == *str2)
//        {
//            //����retָ�����￪ʼ�ĵط�
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

    //������� - str2ָ���ʱ���ַ�����ֱ�ӷ���str1
    if (*str2 == '\0')
    {
        return str1;
    }
    //��Ŀǰָ���λ�ò�Ϊ'\0'ʱ
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
    //���Զ��߲��ǿ�ָ��
    for (i = 0; i < num; i++)
    {
        *(char*)dest = *(char*)src;
        //����char����֮ռ��1���ֽڣ����ڴ��ϱ�ʾ��1���ֽھ���һ����λ
        //�Ҳ������⾫ȷ�ȸ��ߵ������ˣ������char����
        //ÿ��+1������ǰŲ��1��char���͵��ڴ���
        dest = (char*)dest + 1;
        src = (char*)src + 1;
        //����ǿ������ת��������ʱ�ģ�++�޷���ת�������ʱָ�������ƶ�
        //��++(char*)dest;��д���ڲ�ͬ�������п��ܱ���������ôд
    }
    return ret;
}

void* my_memmove(void* dest, const void* src, size_t num)
{
    void* ret = dest;
    if (dest < src)//���ݵĴ���Ǵӵ͵�ַ���ߵ�ַ���ӵ�λ����λ
        //���src��dest���棬������ǰ��������Ϊ�����ص�Ҳ���ں����ص�������ط��������Ѿ���������
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
    //    //�������Ϊ�棬����д�Сдת������
    //    //char������ʵ����ASCII��ֵ����Сд��ĸ��ASCII��ֵ��ȥ32���͵õ��˴�д��ĸ��ASCII��ֵ
    //    {
    //        arr[i] -= 32;
    //    }
    //    i++;
    //}
    //printf("%s\n", arr);

    //char str1[] = "Sample string";
    //char str2[40];//�ռ��㹻��
    //char str3[40];//�ռ��㹻��
    //strcpy(str2, str1);//��str�����ݣ�������str2��
    //strcpy(str3, "copy successful");//�Ѻ����copy successful������str3��
    //printf("str1: %s\nstr2: %s\nstr3: %s\n", str1, str2, str3);

    //char arr1[] = "abcdef";
    //char arr2[20] = { 0 };
    //char* pstr = my_strcpy(arr2, arr1);

    //printf("%s\n", arr2);
    //printf("%s\n", pstr);
    //printf("%s\n", my_strcpy(arr2, arr1));

    //int a = 115;
    //int b = 514;

    //printf("%d\n", a = b);//��ӡ���Ϊ514����b��ֵ
    ////��˿��Է��֣���ֵ���ʽ��������ֵ�ģ���ֵ�������ո�������߱�����ֵ
    ////while(*dest++ = *src++)
    ////����Ҳ��ͬ����������\0���NULLֵ�ĸ�ֵ������whileѭ��

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
    //    printf("������\n");
    //else
    //    printf("%s\n", ret);

    int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
    my_memmove(arr1, arr1 + 3, 20);

    return 0;
}