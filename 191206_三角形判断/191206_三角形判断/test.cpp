#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

// �����αߵ�Ҫ��
// ����֮�ʹ��ڵ�����
// ����֮��С�ڵ�����

int main()
{
	int a, b, c;
	while (cin >> a >> b >> c)
	{
		multiset<int, greater<int>()> mset;
		mset.insert(a);
		mset.insert(b);
		mset.insert(c);
		auto mi = mset.begin();
		a = *mi;
		mset.erase(mi);
		mi = mset.begin();
		b = *mi;
		mset.erase(mi);
		mi = mset.begin();
		c = *mi;
		bool status = true;

		if (b + c <= a)
		{
			status = false;
		}
		if (status == true)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}


	return 0;
}