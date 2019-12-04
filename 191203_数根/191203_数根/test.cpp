#include <iostream>
#include <string>
#include <sstream>

using namespace std;



int main()
{
	long long num;
	string s;
	while (cin >> num)
	{
		stringstream ss;
		ss << num;
		ss >> s;

		while (1)
		{
			num = s[0] - '0';
			for (size_t i = 1; i < s.length(); i++)
			{
				num += s[i] - '0';
			}
			if (num / 10 == 0)
			{
				break;
			}
			stringstream sss;
			sss << num;
			sss >> s;
		}
		cout << num << endl;
	}
	return 0;
}



