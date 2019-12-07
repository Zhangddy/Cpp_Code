class Solution {
public:
	int Add(int num1, int num2)
	{
		// 1. 记录进位
		int carry = (num1 & num2) << 1;
		// 2. 记录相加的结果, 不管进位
		int ret = num1 ^ num2;
		// 3. 将前两步的结果相加...
		while (carry)
		{
			int tmp = ret;
			ret = ret ^ carry;
			carry = (tmp & carry) << 1;
		}
		return ret;
	}
};