#include"Inc.h"
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ret;
		if (!root) return ret;
		TreeNode* cur = root;
		TreeNode* pre = NULL;
		while (cur) {
			if (!cur->left) {
				ret.push_back(cur->val);
				cur = cur->right;
			}
			else {
				pre = cur->left;
				while (pre->right&&pre->right != cur)
					pre = pre->right;
				if (!pre->right) {
					pre->right = cur;
					cur = cur->left;
				}
				else {
					pre->right = NULL;
					ret.push_back(cur->val);
					cur = cur->right;
				}
			}
		}
		return ret;
	}
};