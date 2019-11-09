#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


int main()
{
	int n = 0;
	int sn;
	cin >> n >> sn;
	string s;
	int flag = 0;
	if (n == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	int i = n;
	if (i < 0)
	{
		flag = 1;
		i *= -1;
	}
	for (; i; i /= sn)
	{
		if (i % sn > 9)
		{
			s.push_back('A' + i % sn - 10);
		}
		else
		{
			s.push_back('0' + i % sn);
		}
	}
	for (size_t i = 0, j = s.size() - 1; i < s.size() / 2; ++i, --j)
	{
		swap(s[i], s[j]);
	}

	if (flag == 0)
		cout << s << endl;
	else
		cout << "-" + s << endl;
	system("pause");
	return 0;
}