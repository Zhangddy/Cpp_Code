#include <iostream>
#include <cstdlib>

using namespace std;



int test1()
{

	int year, month, day;
	while (cin >> year >> month >> day)
	{
		int ret = 0;
		// �ж��ǲ�������
		int date[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		bool status = false;
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			status = true;
			date[1]++;
		}

		// ��day������
		ret += day;
		// ��month������
		for (size_t i = 0; i < month - 1; i++)
		{
			ret += date[i];
		}
		cout << ret << endl;
	}
	system("pause");
	return 0;
}