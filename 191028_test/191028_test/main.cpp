#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {

		int i = numbers[0], num = 1;
		for (int j = 1; j < numbers.size(); ++j)
		{
			if (i != numbers[j])
			{
				if (num == 1)
				{
					i = numbers[j];
				}
				else
				{
					num--;
				}
			}
			else
			{
				num++;
			}
		}
		int x = 0;
		for (int j = 0; j < numbers.size(); ++j)
		{
			if (numbers[j] == i)
			{
				x++;
			}
		}
		if (x * 2 > numbers.size())
			return i;
		else
		{
			return 0;
		}
	}
};

int main()
{
	Solution s;
	vector<int> v = { 1,2,3,5,4,2,2,2,3};
	cout << s.MoreThanHalfNum_Solution(v);

	system("pause");
	return 0;
}