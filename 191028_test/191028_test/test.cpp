#include <iostream>
#include <cstdlib>

using namespace std;
class UnusualAdd {
public:
	int addAB(int A, int B) {
		// write code here

		int sum, carry;

		do
		{
			sum = A ^ B;
			carry = (A & B) << 1;

			A = sum;
			B = carry;
		} while (B != 0);
		
		return sum;
	}
};
int main1()
{
	UnusualAdd ua;
	cout << ua.addAB(1, 2);
	system("pause");
	return 0;
}