#include <iostream>
#include <string>
using namespace std;


int main()
{
	string s;
	while (getline(cin, s))
	{
		for (size_t i = 0; i < s.length(); i++)
		{
			if (s[i] != ' ')
			{
				char tmp;
				tmp = (s[i] - 5 - 'A' + 26) % 26 + 'A';
				s[i] = tmp;
			}
		}
		cout << s << endl;
	}
	return 0;
}