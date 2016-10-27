#include"Inc.h"
class Solution {
public:
	bool CheckPath(stack<TreeNode*> s, int sum) {
		if (s.empty() && sum != 0) return true;
		int path = 0;
		while (!s.empty()) {
			path += s.top()->val;
			s.pop();
		}
		if (path == sum) return true;
		else return false;
	}
	bool hasPathSum(TreeNode* root, int sum) {
		stack<TreeNode*> poststack;
		TreeNode* p, *pre;
		p = root;
		pre = NULL;
		while (p) {
			poststack.push(p);
			p = p->left;
		}
		while (!poststack.empty()) {
			p = poststack.top();
			if (!p->right || p->right == pre) {
				if (!p->left&&!p->right) {
					if (CheckPath(poststack, sum))
						return true;
				}
				pre = p;
				poststack.pop();
			}
			else {
				p = p->right;
				while (p) {
					poststack.push(p);
					p = p->left;
				}
			}
		}
		return false;
	}
};

