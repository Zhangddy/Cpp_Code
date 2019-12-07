class Solution {
public:
	int Add(int num1, int num2)
	{
		// 1. ��¼��λ
		int carry = (num1 & num2) << 1;
		// 2. ��¼��ӵĽ��, ���ܽ�λ
		int ret = num1 ^ num2;
		// 3. ��ǰ�����Ľ�����...
		while (carry)
		{
			int tmp = ret;
			ret = ret ^ carry;
			carry = (tmp & carry) << 1;
		}
		return ret;
	}
};