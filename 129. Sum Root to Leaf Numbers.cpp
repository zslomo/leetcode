#include"Inc.h"
class Solution {
public:
	int number(vector<TreeNode*> vec) {
		if (vec.empty()) return 0;
		int number = 0;
		for (int i = 0; i < vec.size(); i++) {
			number = number * 10 + vec[i]->val;
		}
		return number;
	}
	int sumNumbers(TreeNode* root) {
		if (!root) return 0;
		vector<TreeNode*> vec;
		TreeNode *pre = NULL, *p = root;
		int sum = 0;
		while (p) {
			vec.push_back(p);
			p = p->left;
		}
		while (!vec.empty()) {
			p = vec.back();
			if (!p->right || p->right == pre) {
				if (!p->right&&!p->left) {
					sum += number(vec);
				}
				vec.pop_back();
				pre = p;
			}
			else {
				p = p->right;
				while (p) {
					vec.push_back(p);
					p = p->left;
				}
			}
		}
		return sum;
	}
};