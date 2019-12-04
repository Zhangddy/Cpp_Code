#include <iostream>
#include <vector>

using namespace std;
/*
int func(int power)
{
	vector<vector<int>> v(2, vector<int>(2));
	v[0][0] = 1;
	v[0][1] = 1;
	v[1][0] = 1;
	v[1][1] = 0;
	vector<vector<int>> vTmp(v);
	for (size_t i = 1; i < power; i++)
	{
		vector<vector<int>> Tmp(vTmp);
		vTmp[0][0] = Tmp[0][0] * v[0][0] + Tmp[0][1] * v[1][0];
		vTmp[0][1] = Tmp[0][0] * v[0][1] + Tmp[0][1] * v[1][1];
		vTmp[1][0] = Tmp[1][0] * v[0][0] + Tmp[1][1] * v[1][0];
		vTmp[1][1] = Tmp[1][0] * v[0][1] + Tmp[1][1] * v[1][1];
		// cout << i << " test: "<< endl;
		// cout << vTmp[0][0] << ' ';
		// cout << vTmp[0][1] << endl;
		// cout << vTmp[1][0] << ' ';
		// cout << vTmp[1][1] << endl;
		vTmp[0][0] %= 10000;
		vTmp[0][1] %= 10000;
		vTmp[1][0] %= 10000;
		vTmp[1][1] %= 10000;
	}
	return vTmp[0][0];
}
*/
int func(int pow)
{
	int fib1 = 1;
	int fib2 = 2;
	int fib3 = 3;
	if (pow < 3)
	{
		return pow;
	}

	for (int i = 3; i <= pow; i++)
	{
		fib1 %= 10000;
		fib2 %= 10000;
		fib3 %= 10000;
		fib3 = fib1 + fib2;
		fib1 = fib2;
		fib2 = fib3;
		
	}
	return fib3;
}
int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> powerArray;
		int tmp;
		for (size_t i = 0; i < n; i++)
		{
			cin >> tmp;
			powerArray.push_back(tmp);
		}
		for (size_t i = 0; i < n; i++)
		{
			int longlong = func(powerArray[i]);
			longlong %= 10000;

			if (longlong / 10 == 0)
			{
				cout << "000";
			}
			else if (longlong / 100 == 0)
			{
				cout << "00";
			}
			else if (longlong / 1000 == 0)
			{
				cout << "0";
			}
			cout << longlong;
		}
		cout << endl;

	}
	return 0;
}