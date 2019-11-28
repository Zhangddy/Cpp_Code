#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

string getLCS(string s1, string s2)
{
	vector<vector<int>> array(s1.length(), vector<int>(s2.length()));
	int maxLen = 0; // 记录最长长度
	int maxEnd = 0; // 记录最长长度的最后下标

	for (size_t i = 0; i < s1.length(); i++)
	{
		for (size_t j = 0; j < s2.length(); j++)
		{
			if (s1[i] == s2[j])
			{
				if (i == 0 || j == 0)
				{
					array[i][j] = 1;
				}
				else
				{
					array[i][j] = array[i - 1][j - 1] + 1;
				}
			}
			else
			{
				array[i][j] = 0;
			}
			if (maxLen < array[i][j])
			{
				maxLen = array[i][j];
				maxEnd = i;
			}
		}
	}
	return s1.substr(maxEnd - maxLen + 1, maxLen);
}

int main()
{
	string s1;
	string s2;
	while (cin >> s1 >> s2)
	{
		cout << getLCS(s1, s2).length() << endl;
	}
	
	system("pause");
	return 0;
}