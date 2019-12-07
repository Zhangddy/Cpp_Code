#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	int N;
	while (cin >> N)
	{
		vector<int> v;
		for (int i = 0; i < N; i++)
		{
			int tmp;
			cin >> tmp;
			v.push_back(tmp);
		}

		int Max = v[0];
		int f = v[0];
		
		for (size_t i = 1; i < N; i++)
		{
			f = max(f + v[i], v[i]);
			if (f > Max)
			{
				Max = f;
			}
		}
		cout << Max << endl;
	}




	return 0;
}