#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;



int main()
{
	int T;

	cin >> T;

	while (T--)
	{
		int n, k;
		cin >> n >> k; // 2n’≈, œ¥≈∆k¥Œ
		vector<int> v;
		for (size_t i = 0; i < 2 * n; i++)
		{
			int tmp;
			cin >> tmp;
			v.push_back(tmp);
		}

		vector<int> vTmp;
		while (k--)
		{

			for (int j = n,k = 1; j > 0; j--, k++)
			{
				vTmp.push_back(v[2 * n - k]);
				vTmp.push_back(v[n - k]);
			}
			v = vTmp;
			vTmp.clear();
			for (int i = v.size() - 1, j = 0; j < v.size() / 2; i--, j++)
			{
				swap(v[i], v[j]);
			}
		}
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}

	}
	cout << endl;
	system("pause");
	return 0;
}