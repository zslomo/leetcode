#include"Inc.h"
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		if (!root) return true;
		if (!root->left&&!root->right) return true;
		stack<TreeNode*> s;
		TreeNode* p = root;
		bool Isfirst = true;
		int min = 0;
		while (p || !s.empty()) {
			if (p) {
				s.push(p);
				p = p->left;
			}
			else {
				p = s.top();
				if (Isfirst) {
					min = p->val;
					Isfirst = false;
				}
				else {
					if (min >= p->val) return false;
					else min = p->val;
				}
				s.pop();
				p = p->right;
			}
		}
		return true;
	}
};