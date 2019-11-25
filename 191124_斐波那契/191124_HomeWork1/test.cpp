#include <iostream>
#include <cstdlib>

using namespace std;


int getTotal(int month)
{
	int a = 1, b = 1, c;
	if (month <= 2)
	{
		return 1;
	}
	for (size_t i = 2; i < month; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}

int main()
{
	int month;
	while (cin >> month)
	{
		cout << getTotal(month) << endl;
	}

	system("pause");
	return 0;
}