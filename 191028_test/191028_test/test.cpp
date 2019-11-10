#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
	int StrToInt(string str)
	{
		if (str.size() == 0)
		{
			return 0;
		}
		if (str == "" || str == " ")
		{
			return 0;
		}
		int i = 0;
		int flag = 0;
		if (str[0] == '-')
		{
			i = 1;
			flag = -1;
		} 
		if (str[0] == '+')
		{
			i = 1;
			flag = 1;
		}
		for (; i < str.size(); i++)
		{
			if (str[i] == ' ')
			{
				return 0;
			}
			else if (str[i] < '0' || str[i] > '9')
			{
				return 0;
			}
		}
		int ret = 0;
		i = 0;
		if (flag == 1 || flag == -1)
		{
			i = 1;
		}
		for (; i < str.size(); ++i)
		{
			ret += str[i] - '0';
			ret *= 10;
		}
		ret /= 10;
		if (flag == -1)
		{
			ret *= flag;
		}
		return ret;
	}

};
int main()
{
	Solution s;
	string s1 = "-156232";
	cout << s.StrToInt(s1);
	system("pause");
	return 0;
}