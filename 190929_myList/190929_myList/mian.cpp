#include <iostream>
#include <cstdlib>
#include "test.h"
#include <vector>
#include <deque>
using namespace std;



int main()
{
	
	int a[] = { 1, 2, 3, 4, 5 };
	deque<int> de(a, a + 5);
	cout << *de.begin() << endl;


	zdy::list<int> l1(a, a + 5);

	l1.erase(l1.begin());


	for (auto& i : l1)
	{
		cout << i << " ";
	}
	cout << l1.size() << endl;
	cout << l1.empty() << endl;
	l1.erase(l1.begin());
	l1.erase(l1.begin());
	l1.erase(l1.begin());
	l1.erase(l1.begin());

	cout << l1.empty() << endl;

	system("pause");
	return 0;
}