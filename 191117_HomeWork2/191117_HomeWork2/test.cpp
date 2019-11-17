#include <iostream>
#include <cstdlib>

using namespace std;



int main()
{


	int num;
	int cur = 1;
	int lengthTmp = 0;
	int maxLength = 0;
	while (cin >> num)
	{
		while (num)
		{
			if (num & cur)
			{
				lengthTmp++;
			}
			else
			{
				lengthTmp = 0;
			}
			if (maxLength < lengthTmp)
			{
				maxLength = lengthTmp;
			}
			num = num >> 1;
		}
		cout << maxLength << endl;
	}
	system("pause");
	return 0;
}