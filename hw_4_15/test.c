#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<ctype.h>
//1. ʵ��strlen����
//size_t my_strlen(const char* str)
//{
//    assert(str != NULL);
//    const char* start = str;
//    //����һ�㱣�գ����ptrΪ��ָ�룬�򱨴�
//    while (*start != '\0')//����start�Ƿ�������'\0'
//    {
//        start++;//start�����ƶ�������뿪ͷ��str������õ����ȣ���ô����ǰ����char����ռ1���ֽڣ�
//    }
//    return start - str;
//}
//
//int main()
//{
//    char arr[] = "abcdef";
//    size_t len = my_strlen(arr);
//    printf("%zd\n", len);
//
//    return 0;
//}

//strlen�ĵݹ�ʵ�֣�
//size_t my_strlen(const char* str)
//{
//	if (*str != '\0')
//		return 1 + my_strlen(str + 1);
//	//һֱ���ҵ�\0��Ȼ����һ��һ�����ϼӻ������ô���ʵ�ּ򵥣��������ַ����ܴ�ʱ���ڴ�����̫��
//	else
//		return 0;
//}

//2. ʵ��strcpy
//char* my_strcpy(char* dest, const char* src)
//{
//	assert(dest && src);
//	//����deste��src�Ƿ�Ϊ��ָ��
//	char* ret = dest;
//	while(*dest++ = *src++)
//	{ }
//	//++�����ȼ�����*���������ں��ã�����������ɸ�ֵ������ɵ�ַ+1
//	//��ֵ���˵�ַ+1��ʵ�ֻ���
//	//ͬʱ��Ϊ�ȸ�ֵ�����Ի����� '\0'֮����Ⱦ����жϣ�ֱ������ѭ��
//	return ret;
//}
//int main()
//{
//    char arr1[] = "abcdef";
//    char arr2[20] = { 0 };
//    char* pstr = my_strcpy(arr2, arr1);
//
//    printf("%s\n", arr2);
//    printf("%s\n", pstr);
//    printf("%s\n", my_strcpy(arr2, arr1));
//
//    return 0;
//}
// ʵ��strcmp����
//char* my_strcmp(const char* str1, const char* str2)
//{
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//			return 0;
//		str1++;
//		str2++;
//	}
//	if (*str1 > *str2)
//		return 1;//str1 > str2ʱ�����ش���0����
//	else
//		return -1;//str1 < str2ʱ������С��0����
//}
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "abcdefg";
//	int count = my_strcmp(arr1, arr2);
//	if (count > 0)
//		printf("str1 > str2");
//	else if (count < 0)
//		printf("str1 < str2");
//	else
//		printf("str1 = str2");
//
//	return 0;
//}

//4. strcat��ģ��ʵ��
//strcat�Ĺ����ǣ���sourceָ��ָ����ַ�����׷�ӵ�destָ��ָ����ַ����󣬲�����׷�Ӻ��ַ������׵�ַ
//char* my_strcat(char* dest, char* src)
//{
//	char* ret = dest;
//	while (*dest)//�Ƚ�ָ���ƶ���'\0'λ�ô�
//	{
//		dest++;
//	}
//	while (*dest++ = *src++)//������ֵ��strcpyһ��
//		;
//	return ret;
//}
//
//int main()
//{
//	char arr1[30] = "I am ";
//	char arr2[] = "your father";
//	printf("%s", my_strcat(arr1, arr2));
//
//	return 0;
//}
// 5. ʵ��strstr���������ַ���1�������Ƿ����ַ���2
//char* my_strstr(const char* str1, const char* str2)
//{
//	int flag = 0;
//	char* ret_str2 = str2;
//	char* ret = NULL;
//	int sz_str2 = strlen(str2);
//	while (str1 != NULL)
//	{
//		//һֱ�Ƚϵ�str1�ַ�����ĩβ'\0'
//		if (*str1 == *str2)
//		{
//			//forѭ���ļ��������ǣ�*str1 == *str2��ÿ�μ�¼��ȵ��ַ��ĸ�����ret��ʱ����str1�ַ�������ʼ��ַ
//			for (ret = str1; *str1 == *str2; flag++)
//			{
//				str1++;
//				str2++;
//				//����str1��str2ָ��ĵ�ַ
//			}
//		}
//		if ((flag == sz_str2) && (*ret == *(str1 - sz_str2)))
//			//�����¼������ַ����ȵ���sz_str2������str1ָ��ĵ�ַ��ȥsz_str2֮�����str1��ʼƥ��֮ǰ�ĵ�ַ
//			//˵����str1�����ҵ���str2
//		{
//			return ret;
//		}
//		else
//		{
//			flag = 0;//��������������´�ʹ��
//			ret = NULL;//��ֹҰָ��
//			str2 = ret_str2;//str2ָ������ָ��str2�ַ������׵�ַ
//		}
//		str1++;//���������
//	}
//	return ret;
//}
//���ǵ����ƥ������
const char* my_strstr(const char* str1, const char* str2)
{
	assert(str1 && str2);
	const char* s1 = NULL;
	const char* s2 = NULL;
	const char* cur = str1;//ʹ��cur���ָ���ʾָ��ָ�򱻲����ַ����ĵڼ���λ��
	//����const����ָֹ�����ʱ�޸��ַ����ڵ�ֵ
	//���str2ָ����ǿ��ַ�����ֱ�ӷ���str1
	if (*str2 == '\0')
	{
		return str1;
	}
	while (*cur)//������ָ��str1ĩβ��\0ʱ����ƥ��
	{
		s1 = cur;//����s1
		s2 = str2;//����s2
		while (s1 && s2 && *s1 == *s2)//���*s1 == *s2�����Կ�ʼƥ�䣬
		{
			s1++;//s1ָ�뻬��
			s2++;//s2ָ�뻬��
		}
		if (*s2 == '\0')//���s2��������str2��ĩβ
		{
			return cur;//˵��ƥ��ɹ�������ƥ�俪ʼʱ���λ�ã���curָ��ָ��ĵ�ַ
		}
		cur++;//û������*s1 == *s2��cur��������������
	}
	return NULL;//����NULL��ʾû�ҵ�

}

int main()

{
	char line1[] = "Let the sky fall, When it crumbles, we will stand tall, Face it all together";
	char line2[] = "crumble";
	char* ptr = my_strstr(line1, line2);
	if (ptr != NULL)
	{
		printf("founded, the left string is at the %dth character", strlen(line1) - strlen(ptr)+1);
	}
	else
	{
		printf("404 Not Found");
	}

	return 0;
}

//6.ʵ��strncpy�����������Ƶ��ַ�������
// �����ƣ�ֻ����src��num���ַ���dest�У������Զ���'\0'��Ҫ�������پͿ��¶���
//char* my_strncpy(char* dest, const char* src, const size_t num)
//{
//	assert(dest && src);
//	//����deste��src�Ƿ�Ϊ��ָ��
//	size_t i = 0;
//	for (i = 0; i < num && src[i] != '\0'; i++)
//	{
//		dest[i] = src[i];
//	}
//	//�����i < num�������ж����ã�������Լ������
//	for (; i < num; i++)
//	{
//		dest[i] = '\0';
//	}
//	return dest;
//}
//int main()
//{
//	char arr1[100] = "Hello can you hear me";
//	char arr2[30] = "Yes I can";
//	printf("%s\n", my_strncpy(arr1, arr2, 9));
//	my_strncpy(arr1, "Hello can you hear me", 100);
//	printf("%s\n",my_strncpy(arr1, arr2, 30));
//	
//	return 0;
//}
//7. ģ��ʵ��strncat
//char* my_strncat(char* dest, const char* src, size_t dest_size, size_t num)
//{
//	size_t i = 0;
//	char* ret = dest;
//	size_t dest_len = strlen(dest);
//	if ( dest_len >= dest_size)
//	{
//		printf("�ռ��Ѿ�����");
//		return dest;
//	}
//	else{
//		//ֱ���ƶ���destĩβ
//		dest += dest_len;
//		for (i = 0; i < num && src != '\0'; i++)
//		{
//			*dest++ = *src++;
//		}
//		*dest = '\0';
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[100] = "Hello can you hear me. I'm in California dreaming...";
//	char arr2[10] = "Yes I can";
//	//���ԣ���arr2�е�9���ַ���������\0���ӵ�arr1ĩβ�����Զ�����'\0'
//	printf("%s\n", my_strncat(arr1, arr2, sizeof(arr1) / sizeof(arr1[0]), 9));
//
//	return 0;
//}

//8. ʵ��memcpy
//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//    int i = 0;
//    void* ret = dest;
//    assert(dest && src);
//    //���Զ��߲��ǿ�ָ��
//    for (i = 0; i < num; i++)
//        //д��while(num--)Ҳ����
//    {
//        *(char*)dest = *(char*)src;
//        //����char����֮ռ��1���ֽڣ����ڴ��ϱ�ʾ��1���ֽھ���һ����λ
//        //�Ҳ������⾫ȷ�ȸ��ߵ������ˣ������char����
//        //ÿ��+1������ǰŲ��1��char���͵��ڴ���
//        dest = (char*)dest + 1;
//        src = (char*)src + 1;
//        //����ǿ������ת��������ʱ�ģ�++�޷���ת�������ʱָ�������ƶ�
//        //��++(char*)dest;��д���ڲ�ͬ�������п��ܱ���������ôд
//    }
//    return ret;
//}
//int main()
//{
//    int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//    for (int i = 0; i < 10; i++)
//    {
//        printf("%d\n", arr1[i]);
//    }
//    int arr2[20] = { 0 };
//    //����1��Ŀ���ַ
//    //����2���ڴ�����Ԫ��ָ����Ϊ��������
//    //����3���������ֽڸ���
//    memcpy(arr2, arr1 + 2, 20);
//    for (int i = 0; i < 10; i++)
//    {
//        printf("%d\n", arr2[i]);
//    }
//    return 0;
//}

//9. ģ��ʵ��memmove
//void* my_memmove(void* dest, const void* src, size_t num)
//{
//    void* ret = dest;
//    if (dest < src)
//        //������������ص�����������
//        //���ݵĴ���Ǵӵ͵�ַ���ߵ�ַ���ӵ�λ����λ
//        //���dest��src��ߣ��ȿ���src��ߵģ���Ϊ�����ص�Ҳ����dest�ұߺ�src������ص�������ط��������Ѿ���������
//    {
//        while (num--)
//        {
//            *(char*)dest = *(char*)src;
//            dest = (char*)dest + 1;
//            src = (char*)src + 1;
//        }
//    }
//    else
//    {
//        while (num--)
//        {
//            *((char*)dest + num) = *((char*)src + num);
//        }
//    }
//    return ret;
//
//}
//int main()
//{
//    int arr1[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
//    int* ptr = my_memmove(arr1, arr1 + 3, 10);
//    for (int i = 0; i < 15; i++)
//    {
//        printf("%d\n", ptr[i]);
//    }
//
//    return 0;
//}