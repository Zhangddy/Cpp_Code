#include <iostream>

#define PAI 3.14
using namespace std;


int main()
{
	long double n;
	while (cin >> n)
	{
		long double r;
		cin >> r;
		r = 2 * r * PAI;
		if (r < n)
		{
			cout << "No" << endl;
		}
		else
		{
			cout << "Yes" << endl;
		}
	}



	return 0;
}