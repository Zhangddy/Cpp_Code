#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

bool check(string& s1)
{
	string s2;
	for (int i = s1.size() - 1; i >= 0; --i)
	{
		s2 += s1[i];
	}
	if (s1 == s2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	string s1;
	string s2;
	getline(cin, s1);
	getline(cin, s2);
	int total = 0;

	for (size_t i = 0; i < s1.size() + 1; i++)
	{
		string tmp = s1;
		tmp.insert(i, s2);
		if (check(tmp))
		{
			total++;
		}
	}


	cout << total << endl;
	system("pause");
	return 0;
}