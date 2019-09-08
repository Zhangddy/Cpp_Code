#include <iostream>
#include <cstdlib>
using namespace std;
//	1、	这个类里需要原价和数量，
//		原价从一个数组中读出即可（自行定义数组），数量需要初始化。
//	2、	老板会不定期调整价格，调整的方式是通过调整一个价格系数，
//		这个系数乘以原价即为最终价格，这个折扣会影响到所有产品。

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