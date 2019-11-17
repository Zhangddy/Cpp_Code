#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
int func(int m, int n)
{
	if (n == 0 && m == 0)
	{
		return 0;
	}
	if (n == 1 && m == 0)
	{
		return 1;
	}
	if (m == 1 && n == 0)
	{
		return 1;
	}
	if (n == 0)
	{
		return func(m - 1, n);
	}
	if (m == 0)
	{
		return func(m, n - 1);
	}
	return func(m - 1, n) + func(n, m - 1);
}

int main3()
{
	cout << func(2, 2);
	system("pause");
	return 0;
}