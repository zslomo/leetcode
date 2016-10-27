#include"Inc.h"
class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> ret;
		vector<vector<int>> ret2;
		vector<int> curr;
		if (!root) return ret2;
		int front = -1, rear = -1;
		int last = 0, level = 0;
		TreeNode* Q[10000], *p;
		p = root;
		Q[++rear] = root;
		while (front < rear) {
			p = Q[++front];
			if (p->left) Q[++rear] = p->left;
			if (p->right) Q[++rear] = p->right;
			if (front < last)
				curr.push_back(p->val);
			if (front == last) {
				curr.push_back(p->val);
				ret.push_back(curr);
				last = rear;
				curr.clear();
			}

		}
		for (int i = ret.size() - 1; i >= 0; i--)
			ret2.push_back(ret[i]);
		return ret2;
	}
};