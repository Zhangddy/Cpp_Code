#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

//2��ʹ�÷�Χfor��ͨ������Ϊһ�����鸳ֵ
//3�������½ṹ��
//
//struct student {
//	char name[32];
//	int age;
//	int class;
//	bool sex;
//};
//
//д���������ú������صķ�ʽ��д����ͳ�Ƴ�һ���������ṹΪ��׼�Ľṹ�������У�
//1������ΪX�ĳ����˶��ٴ�
//2������ΪX�ĳ����˶��ٴ�
//3���༶ΪX�ĳ����˶��ٴ�
//4���Ա��X�ĳ����˶��ٴ�
//
//���磺����ΪX�Ŀ�����������������
//int countName(student * src, int n, char * name);
//tip:���Կ�����ȱʡ�����ķ�ʽ�����߻ص������ķ�ʽʵ�֡�




struct student {
	char name[32];
	int age;
	int classid;
	bool sex;
};
bool cmpEql(student a, student b)
{
	return a.age == b.age;
}
bool cmpEqlname(student a, student b)
{
	return strcmp(a.name, b.name) ? false : true;
}
bool cmpEqlSex(student a, student b)
{
	return !(a.sex ^ b.sex);
}
int countS(student *st, int n, student value, bool(*cmp)(student,student))
{
	int i, count = 0;
	for (i = 0; i < n; i++)
	{
		if (cmp(st[i], value))
		{
			count++;
		}
	}
	return count;
}
int main()
{
	/*int arr[5];
	for (auto& i : arr)
	{
		cin >> i;
	}

	for (auto& i : arr)
	{
		cout << i <<" ";
	}*/
	

	//student st[] = { "caixukun", 18, 1, true,
	//				 "qiaobiluo", 18, 1,false,
	//				 "wuyifan", 20, 2, true,
	//				 "lubenwei", 22,2, true,
	//				 "caixukun", 18, 1, true,
	//				 "yangchaoyue", 20,1,false
	//				};
	//student test = { "caixukun", 18, 1, true };
	//cout << countS(st, 6, test, cmpEqlname);
	//
	system("pause");
	return 0;
}



