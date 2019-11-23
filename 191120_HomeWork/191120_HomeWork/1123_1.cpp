#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;



int main()
{
	size_t num;
while (cin >> num)
{
	int count = 0;
	for (size_t i = 1; i < num; i++)
	{
		int tmp = i;
		vector<int> v;

		for (size_t i = 1; i < tmp; i++)
		{
			if (tmp % i == 0)
			{
				v.push_back(i);
			}
		}
		long long sum = 0;
		for (auto& i : v)
		{
			sum += i;
		}
		if (sum == tmp)
		{
			count++;
		}
	}
	cout << count << endl;
}
	
	system("pause");
	return 0;
}