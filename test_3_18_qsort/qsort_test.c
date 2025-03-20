#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp_int(const void* p1, const void* p2)
{
	int a = *(int*)p1;
	int b = *(int*)p2;
	//���Ӻܶ�ɶ���
	return ( a > b ) ? 1 : (a < b) ? -1 : 0;
	// if p1������ > p2������ ---> return -1
	// if p1������ < p������ ---> return 1
	// else return 0
}
int cmp_char(const void* p1, const void* p2)
{
	//�ַ����ıȽ���Ҫ�õ�strcmp����
	//��Ϊstring.h�µĿ⺯��, strcmp����λ��Ӧ�Ƚ�ASCII��Ĵ�С
	//һ���ֳ���С, ��ֱ�ӽ����Ƚ�, ����
	//���ص�ֵ��qsortҪ��ķ���ֵ��ͬ,ǰ < �� ���ظ���, ǰ == �� ����0��ǰ > �� ��������
	return strcmp((char*)p1,(char*)p2);
	//������Ҫ�ѽṹ��������֣������������У����������ָ��ǿ��ת������Ϊstruct Stu*���ͣ����ṹ��ָ������
	//�ṹ��ָ�����ͽ����õ����ַ�ʽ��
	// 1.ֱ���� ָ����->��Ա��
	// 2.�����ã�*ָ����.��Ա��
}
int compar_uestc_grade(const void* g1, const void* g2)
{
	//return ((struct Stu*)g1)->grade - ((struct Stu*)g2) ->grade;
	//����ֱ�ӷ��أ��ȽϵĽ����׼
	//���Ҫ�� �ṹ��ָ�� -> ��Ա�� �ķ�ʽ��ȡ��Ա��ֵ������Ҫȷ����ͷ����ǽṹ��ָ��
	//������Ҫ�Ƚ���ǿ��ת���������� -> ��Ϸ��ʳ�Ա��ֵ����Ҫ����С����
	//float grade1 = ((struct Stu*)g1)->grade;
	//float grade2 = ((struct Stu*)g2)->grade;
	//return (grade1 > grade2) ? 1 : (grade1 < grade2) ? -1 : 0;
	//������Ŀ���������ϸ���compar�ķ�������int���з��أ��õ��Ľ����ȷ
	//���ǿ��ʹ��(int)��������඼��С����������ֱ��Ϊ0������������������û�仯
}

void Swap(char* p1, char* p2, size_t width, int mode)
{
	//char����ֻ��һ���ֽڣ����ֻҪ֪����Ŀ��Ԫ�صĿ��
	//�����б�char�ڴ��ϸ��̵������ˣ�������ǽ���char����
	// �Ϳ��Զ���ÿһ���ֽڽ��и�ֵ�뽻��

	int i = 0;
	char tmp = 0;
	if (mode == 1)
	{
		for (i = 0; i < width; i++)
		//�����width��ÿ��Ԫ�صĿ��width
		//ͨ��p1++��p2++���ƶ�����ʵ�ֽ���
		{
			tmp = *p1;
			*p1 = *p2;
			*p2 = tmp;

			p1++;
			p2++;
		}
	}

}

//����ð������ʵ��qsort����---���������������͵�����
void bubble_qsort(void* base, size_t sz, size_t width, int(*cmp)(const void*, const void*))
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (cmp((char*)base+j*width, (char*)base+(j+1)*width) > 0)
			//����ȽϺ����Ľ������0����ִ������Ԫ�ؽ���
			//��Ȼcmp���β�����Ϊconst void*������ʵ�δ���ȥ����char*
			//����C��������ָ�����ʽת�������Ӿ�������ָ��ת����void*���������ǵ���дת�����
			//��֮������Ǵ�void*ת�����������ͣ�����Ҫдת�����
			//������Ǵ�char*��ʽת����consts void*����
			//�ܽ᣺���������β�����Ϊ const void*�кܶ�ô�
			//1. const��֤�˸�ָ���ָ�򲻻ᱻ�޸ģ���ǿrobustness
			//2. void*���ͱ�֤��ָ���޷��������û��������
			//3. ������Ҫ���в��������԰��վ������ͽ���ת�����и��ߵ������
			{
				//�����Ĵ���
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
	//ע��strcmp��Ҫ����ָ���ַ����ĵ�һ���ַ���ָ��

	return 0;
}