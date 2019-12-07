#include <vector>
using namespace std;
class Solution {
public:
	/**
	 *  奇数位上都是奇数或者偶数位上都是偶数
	 *  输入：数组arr，长度大于2
	 *  len：arr的长度
	 *  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
	 *  时间复杂度O(n), 空间复杂度O(1)
	 */

	// 用两个索引, 分别指向奇数位和偶数位, 若元素值不符则兑换

	void oddInOddEvenInEven(vector<int>& arr, int len) 
	{
		size_t oddIndex = 1;
		size_t evenIndex = 0;

		while (oddIndex < arr.size() && evenIndex < arr.size())
		{
			if (arr[oddIndex] % 2 == 0 && arr[evenIndex] % 2 != 0)
			{
				swap(arr[oddIndex], arr[evenIndex]);
				
			}
			if (arr[oddIndex] % 2 != 0)
			{
				oddIndex += 2;
			}
			if (arr[evenIndex] % 2 == 0)
			{
				evenIndex += 2;
			}
		}
	}
};