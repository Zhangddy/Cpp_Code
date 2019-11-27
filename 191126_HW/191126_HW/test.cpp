#include <iostream>

using namespace std;

int func(int bottle)
{
	int drink = 0;
	if (bottle == 0)
		return 0;
	while (bottle > 2)
	{
		drink += bottle / 3;
		bottle = bottle / 3 + bottle % 3;
	}
	return drink;
}
int main()
{
	int num;

	while (cin >> num)
	{
		int drunk = 0;
		drunk = func(num);
		cout << drunk << endl;
	}
	system("pause");
	return 0;
}
