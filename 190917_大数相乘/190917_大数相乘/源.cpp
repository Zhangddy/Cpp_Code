#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
using namespace std;
const int L = 110;
string mul(string a, string b)//�߾��ȳ˷�a,b,��Ϊ�Ǹ�����
{
	string s;
	int na[L], nb[L], nc[L], La = a.size(), Lb = b.size(); //na�洢��������nb�洢������nc�洢��
	fill(na, na + L, 0);
	fill(nb, nb + L, 0);
	fill(nc, nc + L, 0); //��na,nb,nc����Ϊ0

	for (int i = La - 1; i >= 0; i--) 
		na[La - i] = a[i] - '0';//���ַ�����ʾ�Ĵ�������ת��i���������ʾ�Ĵ�������
	for (int i = Lb - 1; i >= 0; i--) 
		nb[Lb - i] = b[i] - '0';

	for (int i = 1; i <= La; i++)
		for (int j = 1; j <= Lb; j++)
			nc[i + j - 1] += na[i] * nb[j]; //a�ĵ�iλ����b�ĵ�jλΪ���ĵ�i+j-1λ���Ȳ����ǽ�λ��

	for (int i = 1; i <= La + Lb; i++)
		nc[i + 1] += nc[i] / 10, nc[i] %= 10;//ͳһ�����λ

	if (nc[La + Lb]) 
		s += nc[La + Lb] + '0';//�жϵ�i+jλ�ϵ������ǲ���0

	for (int i = La + Lb - 1; i >= 1; i--)
		s += nc[i] + '0';//����������ת���ַ���
	return s;
}

int _main()
{
	string a, b;
	a = "123";
	b = "456";
	cout << mul(a, b) << endl;
	system("pause");
	return 0;
}