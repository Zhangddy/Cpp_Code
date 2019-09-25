#include <iostream>	
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;


string letterMap[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

class Solution
{
public:
	void combineStr(const string& digits, size_t index, vector<string>& strs, const string& str)
	{
		if (index == digits.size())
		{
			strs.push_back(str);
			return;
		}
		string letters = letterMap[digits[index] - '0'];

		for (size_t i = 0; i < letters.size(); i++)
		{
			combineStr(digits, index + 1, strs, str + letters[i]);
		}
	}

	vector<string> letterCombinations(string digits)
	{
		vector<string> strs;

		if (digits.empty())
		{
			return strs;
		}
		size_t index = 0;
		string str;
		combineStr(digits, index, strs, str);
		return strs;
	}
};

int main()
{
	string s = "939";
	Solution s1;
	vector<string> s3 = s1.letterCombinations(s);
	for (size_t i = 0; i < s3.size(); i++)
	{
		cout << s3[i] << endl;
	}
	system("pause");
	return 0;
}