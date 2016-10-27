#include"Inc.h"
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> ret;
		if (!root) return ret;
		stack<TreeNode*> s;
		TreeNode* p = root;
		TreeNode* pre = NULL;
		while (p) {
			s.push(p);
			p = p->left;
		}
		while (!s.empty()) {
			p = s.top();
			s.pop();
			if (!p->right || p->right == pre) {
				ret.push_back(p->val);
				pre = p;
			}
			else {
				s.push(p);
				p = p->right;
				while (p) {
					s.push(p);
					p = p->left;
				}
			}
		}
	}
};