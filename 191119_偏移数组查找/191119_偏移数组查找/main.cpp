#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main()
{
	// vector<int> v = { 8, 9, 1, 2, 3 ,4, 5, 6, 7};
	vector<int> v = { 4, 5, 6, 7, 8, 9, 1, 2, 3 };

	// 先找最小的数
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
	int val;
	cin >> val;

	
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
	
	cout << v[mid] << endl;
	system("pause");
	return 0;
}