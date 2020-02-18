#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
	bool judgePoint24(vector<int>& nums) 
	{
		auto a = nums;
		sort(begin(a), end(a));
		do {
			auto a12 = cal(a[0], a[1]);
			// a12 op a34
			auto a34 = cal(a[2], a[3]);
			for (auto v1 : a12) {
				for (auto v2 : a34) {
					for (auto r : cal(v1, v2)) {
						if (is_ans(r)) return true;
					}
				}
			}
			// a123 op a4
			for (auto v12 : a12) {
				for (auto v123 : cal(v12, a[2])) {
					for (auto r : cal(v123, a[3]))
						if (is_ans(r)) return true;
				}
			}
		} 
		while (next_permutation(begin(a), end(a)));
		return false;
	}
	unordered_set<double> cal(double a, double b) 
	{
		unordered_set<double> ans = { a * b, a + b, a - b, b - a };
		if (b) ans.insert(a / b);
		if (a) ans.insert(b / a);
		return ans;
	}

	bool is_ans(double a) 
	{
		return abs(a - 24) < 1e-5;
	}
};
