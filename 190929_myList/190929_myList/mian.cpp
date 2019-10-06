#include <iostream>
#include <cstdlib>
#include "List.h"
#include <vector>
using namespace std;



int main()
{
	
	int a[] = { 1, 2, 3, 4, 5 };
	vector<int> v(a, a + 5);
	
	zdy::List<int> l5();

	cout << endl;
	system("pause");
	return 0;
}