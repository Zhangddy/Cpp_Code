class Solution {
public:
	// 这不是真正的全排列, 而是所有选择某个数的情况
	// 枚举法, 借用通过位运算
	vector<vector<int>> subsets(vector<int>& nums) {
	int size = nums.size();
	int n = 1 << size;
	vector<vector<int>> res;
	for (int i = 0; i < n; i++)
	{
		vector<int> tmp;
		for (int j = 0; j < size; j++)
		{
			if (i & (1 << j))
			{
				tmp.push_back(nums[j]);
			}
		}
		res.push_back(tmp);
	}
	return res;
	}
};