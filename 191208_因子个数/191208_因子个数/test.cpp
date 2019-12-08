#include <iostream>
#include<math.h>
using namespace std;
int main() {
	int n, count;
	while (cin >> n) {
		count = 0;
		for (int i = 2; i <= sqrt(n); i++)
		{
			if (n % i == 0)
			{
				while (n % i == 0)
				{
					n = n / i;
				}
				count++;
			}
		}
		if (n != 1)
		{
			count++;
		}
		cout << count << endl;
	}
	return 0;
}
