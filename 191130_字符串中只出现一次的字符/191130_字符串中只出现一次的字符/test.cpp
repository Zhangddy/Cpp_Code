
#include <iostream>
#include <string>
using namespace std;



int main()
{


	string s;
	while (cin >> s)
	{
	int map[26] = { 0 };
	for (auto& i : s)
	{
		map[i - 'a' ]++;
	}
	size_t i;
	for ( i = 0; i < s.length(); i++)
	{
		if (map[s[i] - 'a'] == 1)
		{
			char c = s[i];
			cout << c << endl;
			break;
		}
	}
	if (i == s.length())
	{
		cout << -1 << endl;
	}
	}

	return 0;
}