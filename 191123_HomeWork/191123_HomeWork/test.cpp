#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

/*
0 0 1 0 0 0 0 0 0
0 0 1 1 1 0 0 0 0
0 0 1 2 3 2 1 0 0
0 0 1 3 6 7 6 3 1
*/
void printArray(vector<vector<int>> data)
{
	for (int i = 0; i < data.size(); i++)
	{
		for (int j = 0; j < data[i].size(); j++)
		{
			cout << data[i][j] << " ";
		}
		cout << '\n';
	}
}
int func(int rowNum)
{
	int ret = 0;
	vector<vector<int>> v(rowNum * 2 - 1 + 2);

	if (rowNum == 1)
	{
		return -1;
	}
	v[0].push_back(0);
	v[0].push_back(0);
	v[0].push_back(1);
	v[0].resize(rowNum * 2 - 1 + 2, 0);
	for (size_t _ = 1; _ < rowNum; _++)
	{
		v[_].push_back(0);
		v[_].push_back(0);
		v[_].resize(rowNum * 2 - 1 + 2, 0);
		for (size_t i = 2; i < _ * 2 + 3; i++)
		{
			v[_][i] = v[_ - 1][i - 2] + v[_ - 1][i - 1] + v[_ - 1][i];
		}
		
	}
	printArray(v);
	for (size_t i = 2; i < rowNum * 2 - 1 + 2; i++)
	{
		if (v[rowNum - 1][i] % 2 == 0)
		{
			return i - 1;
		}
	}
	return -1;
}

int main()
{
	cout << func(3) << endl;

	
	system("pause");
	return 0;
}