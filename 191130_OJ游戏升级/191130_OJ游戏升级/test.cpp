#include <iostream>
#include <vector>
using namespace std;

int find(int a, int b)
{
	int ret = 0;

	for (int i = 1; i <= a; i++)
	{
		if (b % i == 0 && a % i == 0)
		{
			ret = i;
		}
	}
	return ret;
}

int main()
{
	int n, a;
	while (cin >> n >> a)
	{
		vector<int> v;
		for (size_t i = 0; i < n; i++)
		{
			int tmp;
			cin >> tmp;
			v.push_back(tmp);
		}
		for (size_t i = 0; i < n; i++)
		{
			if (a >= v[i])
			{
				a += v[i];
			}
			else
			{
				a += find(a, v[i]);
			}
		}
		cout << a << endl;
	}


	return 0;
}