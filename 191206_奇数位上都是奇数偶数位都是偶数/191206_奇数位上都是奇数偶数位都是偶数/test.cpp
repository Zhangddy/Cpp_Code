#include <vector>
using namespace std;
class Solution {
public:
	/**
	 *  ����λ�϶�����������ż��λ�϶���ż��
	 *  ���룺����arr�����ȴ���2
	 *  len��arr�ĳ���
	 *  ��arr����������λ�϶�����������ż��λ�϶���ż��
	 *  ʱ�临�Ӷ�O(n), �ռ临�Ӷ�O(1)
	 */

	// ����������, �ֱ�ָ������λ��ż��λ, ��Ԫ��ֵ������һ�

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