#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

string AddLongInteger(string addend, string augend)
{
	string ret;
	vector<int> v1;
	vector<int> v2;
	// v1.resize(addend.size() + 1);
	// v2.resize(augend.size() + 1);
	for (int i = addend.size() - 1; i >= 0; i--)
	{
		v1.push_back(addend[i] - '0');
	}
	for (int i = augend.size() - 1; i >= 0; i--)
	{
		v2.push_back(augend[i] - '0');
	}

	for (size_t i = 0; i < v2.size(); i++)
	{
		v1[i] += v2[i];
	}

	v1.resize(v1.size() + 1, 0);
	for (size_t i = 0; i < v1.size() - 1; i++)
	{
		v1[i + 1] += v1[i] / 10;
		v1[i] %= 10;
	}
	
	for (int i = v1.size() - 1; i >= 0; i--)
	{
		if (i == v1.size() - 1 && v1[v1.size() - 1] == 0)
		{
			continue;
		}
		ret.push_back(v1[i] + '0');
	}



	return ret;
}

int main()
{
	string addend, augend;
	while (cin >> addend >> augend)
	{
		if (addend.size() > augend.size())
		{
			cout << AddLongInteger(addend, augend) << endl;
		}
		else
		{
			cout << AddLongInteger(augend, addend) << endl;
		}
	}
	system("pause");
	return 0;
}