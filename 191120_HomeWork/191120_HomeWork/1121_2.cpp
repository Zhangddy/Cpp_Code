#include <vector>
#include <iostream>
using namespace std;
class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		// write code here
		// 找左手最小
		int left_min = left[0] + 1;
		for (size_t i = 0; i < n; i++)
		{
			if ((left_min > left[i]) && (left[i] != 0))
			{
				left_min = left[i];
			}
		}


		int right_min = right[0] +1;
		int right_max = right[0];
		// 找右手最小及最大
		for (size_t i = 0; i < n; i++)
		{
			if ((right_min > right[i]) && (right[i] != 0))
			{
				right_min = right[i];
			}
		}
		for (size_t i = 0; i < n; i++)
		{
			if (right_max < right[i])
			{
				right_max = right[i];
			}
		}
		return left_min + right_max + right_min + 2;
	}
};

int main212()
{
	Gloves g;
	vector<int> v1 = { 0, 7, 1, 6 };

	vector<int> v2 = { 1, 5, 0, 6 };
	cout << g.findMinimum(4, v1, v2);
	return 0;
}