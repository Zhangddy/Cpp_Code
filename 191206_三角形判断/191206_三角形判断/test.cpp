#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

// 三角形边的要求
// 两边之和大于第三边
// 两边之差小于第三边

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