#include <iostream>
#include <cstdlib>

using namespace std;



int main211()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		while (n)
		{
			if (n & 1 == 1)
			{
				count++;
			}
			n = n >> 1;
		}
		cout << count << endl;
	}

	system("pause");
	return 0;
}