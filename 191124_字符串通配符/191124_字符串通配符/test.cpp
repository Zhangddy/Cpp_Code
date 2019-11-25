#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

bool func(const string s1, const string s2)
{
	string::const_iterator si1 = s1.begin();
	string::const_iterator si2 = s2.begin();
	string::const_iterator si1end = s1.end();
	si1end--;
	bool status = true;
	int flag = 0;
	while (si1 != s1.end())
	{
		if ((*si1 == '*' || *si1 == '?') && si1end != si1)
		{
			if (*si1 == '*')
			{
				
				while (*si1 == '*' || *si1 == '?')
				{
					si1++;
				}
				string::const_iterator sit = si2;
				sit++;
				while (*si2 != *si1 || *sit == *si1)
				{
					si2++;
					if (si2 == s2.end())
					{
						return false;
					}
					sit++;
				}
			}
			else
			{
				si1++;
				si2++;
			}
		}
		else if (*si1 == '*' && si1end == si1)
		{
			flag = 1;
			break;
		}
		else if (*si1 == '?' && si1end == si1)
		{
			si2++;
			if (si2	!= s2.end())
			{
				status = false;
			}
			flag = 1;
			break;
		}
		else
		{
			if (*si1 == *si2)
			{
				si1++;
				si2++;
			}
			else
			{
				status = false;
				break;
			}
		}
	}
	if (si2 != s2.end() && flag != 1)
	{
		status = false;
	}
	return status;
}

int main()
{
	string s1;
	string s2;
	while (cin >> s1 >> s2)
	{
		if (func(s1, s2))
		{
			cout << "true" << endl;
		} 
		else
		{
			cout << "false" << endl;
		}
	}
	
	system("pause");
	return 0;
}