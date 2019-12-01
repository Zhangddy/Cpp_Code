#include <iostream>
#include <vector>
using namespace std;
class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		// write code here
		int count = 1;
		int index = gifts[0];
		for (size_t i = 1; i < n; i++)
		{
			if (index != gifts[i])
			{
				count--;
				if (count == 0)
				{
					index = gifts[i];
					count = 1;
				}
			}
			else
			{
				count++;
			}
		}
		count = 0;
		for (size_t i = 0; i < n; i++)
		{
			if (index == gifts[i])
			{
				count++;
			}
		}
		if (count >= n / 2)
		{
			return index;
		}
		else
		{
			return 0;
		}
		
	}
};

int main()
{
	Gift g;
	vector<int> v = { 1, 2, 3, 2, 2, 5, 2 };
	cout << g.getValue(v, v.size()) << endl;

	return 0;
}