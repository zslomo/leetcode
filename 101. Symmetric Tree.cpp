#include"Inc.h"
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (!root) return true;
		queue<TreeNode*> Q1;
		queue<TreeNode*> Q2;
		TreeNode* p, *q;
		Q1.push(root);
		Q2.push(root);
		while (!Q1.empty() && !Q2.empty()) {
			p = Q1.front(); Q1.pop();
			q = Q2.front(); Q2.pop();
			if (p&&q) {
				if (p->val != q->val) return false;
				else {
					Q1.push(p->left);
					Q1.push(p->right);
					Q2.push(q->right);
					Q2.push(q->left);
				}
			}
			if ((!p&&q) || (!q&&p)) return false;
		}
		return true;
	}
}; 