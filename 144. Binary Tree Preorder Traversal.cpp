#include"Inc.h"
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> ret;
		if (!root) return ret;
		TreeNode* p = root;
		stack<TreeNode*> s;
		while (p||!s.empty()) {
			if (p) {
				ret.push_back(p->val);
				s.push(p);
				p = p->left;
			}
			else {
				p = s.top();
				s.pop();
				p = p->right;
			}
		}
		return ret;	
	}
};