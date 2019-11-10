#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


int main()
{
	while (1)
	{
		string s1;
		string s2;
		cin >> s1;
		s2 += s1[0];

		for (size_t i = 1; i < s1.size(); ++i)
		{
			int flag = 0;
			for (size_t j = 0; j < i; ++j)
			{
				if (s1[i] == s1[j])
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				s2 += s1[i];
			}
		}

		cout << s2 << endl;
	}


	system("pause");
	return 0;
}