#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Finder {
public:
	int findElement(vector<int> A, int n, int x) {
		// write code here
		if (A[0] < x)
		{
			// ╢ссрур
			for (size_t i = A.size(); i > 0; --i)
			{
				if (x == A[i])
				{
					return i;
				}
			}


		}
		else
		{
			for (size_t i = 0; i < A.size(); ++i)
			{
				if (x == A[i])
				{
					return i;
				}
			}
		}
	}
};

int main2()
{
	
	system("pause");
	return 0;
}