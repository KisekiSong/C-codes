#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//ð������һ��ֻ���һ������
//�����BBL_sortֻ�ܴ���������������򣬶�qsort���Դ����κ����͵�����
void BBL_sort(int *arr, int sz)//���������дarr[]��Ҳ����дint *arr
{
	//û�����÷���ֵ��ֱ����ָ��Ե�ַ�ϵ�ֵ�����޸�
	//������Ҫһ�������洢�м�ֵ
	int flag = 1;
	int i = 0;
	int temp = 0;
	//do {
	//	flag = 0;
	//	for (i = 0; i < sz -1; i++)
	//	{
	//		if (arr[i] > arr[i + 1])//�����������У���˳��ͰѲ��Ⱥŷ�һ��
	//		{
	//			temp = arr[i];
	//			arr[i] = arr[i + 1];
	//			arr[i + 1] = temp;
	//			flag = 1;
	//		}
	//	}
	//} while (flag);
	
	//ð������һ�ν��һ����������0~9����һ�˻��9�ᵽ���ұ�/�����
	//��ô���ұ�/����ߵ�����������ǾͿ��Բ�������
	//ֻ��Ҫ��ʣ�µ����ּ��ɣ�������ÿ�������һ��
	do {
		flag = 0;
		for (i = 0; i < sz - 1; i++)
		{
			int j = 0;
			for (j = 0; j < sz - 1; j++)
			{
				if (arr[j] > arr[j + 1])//�����������У���˳��ͰѲ��Ⱥŷ�һ��
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


//����ʹ��qsort����
//qsort��һ���⺯��������֪���͵�����£��ɶ��������ͽ�������
//�����4��������
//void qsort (void* base, size_t num, size_t size,
//				int (*compar)(const void*, const void*));
//cplusplus�����϶Ը��������Ľ������£�
//void* base: ָ�����������ĵ�һ��object
//size_t num: baseָ��ָ��������Ԫ�ظ�����size_t���޷�������
//size_t size: ������ÿ��Ԫ�ص�byte��
//compar����һ������ָ�룬ָ��ĺ�����������Ϊint���β�Ϊ2��const void* ���͵�ָ��
//const��ʾ�޷�����ָ��ָ���ַ�����ݣ�void��ʾ�޷���ָ����н����ò���
//ͬʱ��compar����Ҫ�����Լ�����ɵģ���Ҫ���ǣ�
// int compareMyType (const void * a, const void * b)
//{
//	if (*(MyType*)a < *(MyType*)b) return ����;
//	if (*(MyType*)a == *(MyType*)b) return 0;
//	if (*(MyType*)a > *(MyType*)b) return ����;
//}
//ǰ > �󣬷��ظ���
//ǰ == �󣬷���0
//ǰ < ��, ��������

//���ڲ�ͬ���͵����ȽϷ�����ͬ, ����Ҫ�и���������Ӧ��compar����:
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
//	//����ڶ���������ĳ���,����byte��
//	//compar_int����ֻ��Ҫ����Ϳ�����,����ָ��˭��˭�Ƚ�,qsort�ᷴ������compar_intֱ���������
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
	//����д����Ŀ�������ķ�ʽ��ͬ����飬���ҿ��Ըı�������
	int age1 = ((struct Stu*)p1)->age;
	int age2 = ((struct Stu*)p2)->age;
	return (age1 > age2) ? -1 : ((age1 < age2) ? 1 : 0);
	// if age1 > age2 ---> return -1
	// if age1 < age2 ---> return 1
	// else return 0
}
int compar_uestc_name(const void* p1, const void* p2)
{
	//�ַ����ıȽ���Ҫ�õ�strcmp����
	//��Ϊstring.h�µĿ⺯��, strcmp����λ��Ӧ�Ƚ�ASCII��Ĵ�С
	//һ���ֳ���С, ��ֱ�ӽ����Ƚ�, ����
	//���ص�ֵ��qsortҪ��ķ���ֵ��ͬ,ǰ < �� ���ظ���, ǰ == �� ����0��ǰ > �� ��������
	return strcmp(((struct Stu*)p1)->name, (*(struct Stu*)p2).name);
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
	float grade1 = ((struct Stu*)g1)->grade;
	float grade2 = ((struct Stu*)g2)->grade;
	return (grade1 > grade2) ? 1 : (grade1 < grade2) ? -1 : 0;
	//������Ŀ���������ϸ���compar�ķ�������int���з��أ��õ��Ľ����ȷ
	//���ǿ��ʹ��(int)��������඼��С����������ֱ��Ϊ0������������������û�仯
}


int main()
{
	struct Stu uestc[] = {{"Niuzhuxi", 114, 3.85}, {"Laozhao", 514, 3.94}, {"Laowang", 1919, 3.57},{"Kangkang", 810, 3.74}};
	//������������
	//qsort(uestc, sizeof(uestc) / sizeof(uestc[0]), sizeof(uestc[0]), compar_uestc_age);

	//�����ַ�������
	//qsort(uestc, sizeof(uestc) / sizeof(uestc[0]), sizeof(uestc[0]), compar_uestc_name);

	//���ճɼ�����
	qsort(uestc, sizeof(uestc) / sizeof(uestc[0]), sizeof(uestc[0]), compar_uestc_grade);


	return 0;
}
