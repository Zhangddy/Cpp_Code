#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root)
	{
		vector<int> v;
		stack<TreeNode*> s;
		TreeNode* cur = root;
		while (cur || !s.empty())
		{
			while (cur)
			{
				s.push(cur);
				cur = cur->left;
			}
			cur = s.top();
			v.push_back(cur->val);
			s.pop();
			cur = cur->right;
		}
		return v;
	}
};

  //        1
  //   2		 4
  //     3	       5

int main()
{/*
	TreeNode t1(1);
	TreeNode t2(2);
	TreeNode t3(3);
	TreeNode t4(4);
	TreeNode t5(5);
	t1.left = &t2;
	t2.right = &t3;
	t1.right = &t4;
	t4.right = &t5;*/

	char s[5] = "hehe";
	char s2[3][5] = { "hehe", "h", "hehe" };
	cout << s2[0] << endl;
	system("pause");
	return 0;
}