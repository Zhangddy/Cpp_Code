#include <iostream>
#include <cstdlib>
using namespace std;
//	1��	���������Ҫԭ�ۺ�������
//		ԭ�۴�һ�������ж������ɣ����ж������飩��������Ҫ��ʼ����
//	2��	�ϰ�᲻���ڵ����۸񣬵����ķ�ʽ��ͨ������һ���۸�ϵ����
//		���ϵ������ԭ�ۼ�Ϊ���ռ۸�����ۿۻ�Ӱ�쵽���в�Ʒ��

class goods
{
	float m_price;
	int m_num;
	static float  m_k;
	
public:
	void getinfo(int** p, int num)
	{
		m_price = (**p) * m_k;
		(*p)++;
		m_num = num;
	}
	void print()
	{
		cout << m_price << endl;
		cout << m_num << endl;
	}
};

float goods::m_k = 0.8;
int main1()
{
	int price_arr[4] = { 1, 2, 3, 4 };
	int* ptr = price_arr;
	goods g[10];
	
	g[0].getinfo(&ptr, 20);
	g[0].print();
	g[1].getinfo(&ptr, 15);
	g[1].print();
	system("pause");
	return 0;
}