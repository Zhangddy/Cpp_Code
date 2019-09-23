#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

vector<vector<int>> generate(int numRows) 
{
	vector<vector<int>> data(numRows);
	if (numRows == 0)
	{
		return data;
	}

	data[0].push_back(1);

	for (int i = 1; i < data.size(); i++)
	{
		data[i].push_back(1);
		for (int j = 1; j < i; j++)
		{
			data[i].push_back(data[i - 1][j] + data[i - 1][j - 1]);
		}
		data[i].push_back(1);
	}
	return data;
}

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

int main()
{
	
	printArray(generate(6));


	system("pause");
	return 0;
}