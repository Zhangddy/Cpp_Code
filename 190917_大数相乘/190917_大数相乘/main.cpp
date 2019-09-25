#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

#define CAPACITY 1024

using namespace std;

class Solution 
{	
public:
	string multiply(string num1, string num2)
	{
		string s;
		if (num1 == "0" || num2 == "0")
		{
			return "0";
		}

		size_t maxL = num1.size() + num2.size();
		int n1[CAPACITY], n2[CAPACITY], sum[CAPACITY];
		int L1 = num1.size(), L2 = num2.size();
		
		//»´÷√¡„
		memset(n1, 0, CAPACITY);
		memset(n2, 0, CAPACITY);
		memset(sum, 0, CAPACITY);

		for (int i = 0; i < L1; i++)
		{
			n1[i] = num1[L1 - i - 1] - '0';
		}
		for (int i = 0; i < L2; i++)
		{
			n2[i] = num2[L2 - i - 1] - '0';
		}

		for (int i = 0; i < L1; i++)
		{
			for (int j = 0; j < L2; j++)
			{
				sum[i + j] += n1[i] * n2[j];
			}
		}

		for (int i = 0; i < num1.size() + num2.size(); i++)
		{
			sum[i + 1] += sum[i] / 10;
			sum[i] %= 10;
		}
		s.reserve(num1.size() + num2.size());
		for (int i = 0; i < num1.size() + num2.size(); i++)
		{
			s += sum[i] + '0';
		}
		
		while (s[maxL - 1] == '0')
		{
			s.pop_back();
			maxL--;
		}
		reverse(s.begin(), s.end());
		return s;
	}
};

int main()
{/*
	string num1 = "123";
	string num2 = "456";
	Solution s1;
	cout << s1.multiply(num1, num2);
	*/
	Solution s;
	string s1;
	string s2;
	while (cin >> s1 >> s2) 
	{
		cout << s.multiply(s1, s2) << endl;
	}
	
	system("pause");
	return 0;
}