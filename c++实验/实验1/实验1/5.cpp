#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>

using namespace std;
    
// 1.����һ���ļ����������ͨ�����캯��ָ�������ļ�����
// 2.ͨ���ļ����������д�����������֡� 
// 3.�ر��ļ����������Ȼ��۲�����ļ����ݡ� 
// 4.����open���������ļ����������ѡ���ʵ����ļ�������ʽ��
// 5.��ԭ���ݵĺ���׷�������������ݡ� 

int main5()
{
	// 1
	ofstream fout("D:\\CppExp.txt");
	// 2, 3
	fout << "�´������ղ���,";
	fout << "Ϊ����������.";

	fout.close();
	// 4
	FILE* pFile;
	pFile = fopen("D:\\CppExp.txt", "r+");
	char a[1024];
	if (pFile != NULL)
	{
		fscanf(pFile, "%s", a);
	}
	puts(a);
	// 5
	fprintf(pFile, "---��.����");

	fclose(pFile);
	return 0;
}