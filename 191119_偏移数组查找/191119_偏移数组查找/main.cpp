#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main()
{
	// test 1: vector<int> v = { 8, 9, 1, 2, 3 ,4, 5, 6, 7};
	vector<int> v = { 4, 5, 6, 7, 8, 9, 1, 2, 3 };

	// 先找最小的数, 及偏移后的起始位置
	int left = 0, right = v.size() - 1;
	int mid = right / 2;

	while (left < right)
	{
		if (v[mid] < v[mid - 1])
		{
			break;
		}
		
		if (v[mid] < v[left])
		{
			// 在左边
			right = mid - 1;
		} 
		else 
		{
			// 在右边
			left = mid + 1;
		}
		mid = (right + left) / 2 ;

	}
	// 得到的 mid 就是新的起点
	
	int val;
	cin >> val;

	// 之后可以 mid 为起点, size + mid 为结束
	// 在上面这个区间进行查找
	// 查找会越界, 则取余 size 即可
	
	left = mid;
	right = v.size() + mid - 1;

	while (left <= right)
	{
		mid = (right + left) / 2;

		if (val == v[mid  % v.size()])
		{
			break;
		}
		if (val > v[mid % v.size()])
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	mid %= v.size();
	if (v[mid] != val)
	{
		cout << "can't find \n" << endl;
		system("pause");
		return 0;
	}
	cout << "the position is: "<< mid << endl;
	system("pause");
	return 0;
}