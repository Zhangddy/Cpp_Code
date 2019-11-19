#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;



int main()
{
	string s;
	int count = 0;
	vector<string> vs;
	getline(cin, s);
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] != ' ')
		{
			vs.resize(vs.size() + 1);
			vs[count] += s[i];
		}
		else
		{
			count++;
		}
	}
	vs.resize(count + 1);
	cout << count + 1 << endl;
	for (size_t i = 0; i < vs.size(); i++)
	{
		cout << vs[i] << endl;
	}

	system("pause");
	return 0;
}