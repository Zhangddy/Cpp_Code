#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
	long long StrToInt(string str)
	{
		if (str == "" || str == " ")
		{
			return 0;
		}
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == ' ')
			{
				return 0;
			}
			else if (str[i] < '0' || str[i] > '9')
			{
				for (size_t j = i; j < str.size() - 1; ++j)
				{
					str[j] = str[j + 1];
				}
				str.resize(str.size() - 1);
				--i;
			}
		}
		long long ret = 0;

		for (int i = 0; i < str.size(); ++i)
		{
			ret += str[i] - '0';
			ret *= 10;
		}
		ret /= 10;
		return ret;
	}

};
int main()
{
	Solution s;
	string s1 = "fdf11sfsd42d42452452424#%$f";
	cout << s.StrToInt(s1);
	system("pause");
	return 0;
}