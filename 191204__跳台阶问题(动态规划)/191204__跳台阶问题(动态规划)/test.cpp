class Solution {
public:
	int jumpFloorII(int number) {
		return func(number);
	}

	/*f(n) = f(n - 1) + f(n - 2) + ... + f(1)
	f(n - 1) = f(n - 2) + ...f(1)
	ตร:f(n) = 2 * f(n - 1)*/
	int func(int n)
	{
		if (n == 1 || n == 2)
		{
			return n;
		}

		return  func(n - 1) * 2;
	}
};

int main()
{
	Solution s;
	int a = s.jumpFloorII(1);

	return 0;
}