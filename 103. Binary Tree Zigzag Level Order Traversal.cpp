#include"Inc.h"
class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> ret;
		vector<int> curr;
		if (!root) return ret;
		int front = -1, rear = -1;
		int last = 0, level = 0;
		TreeNode* Q[10000], *p;
		p = root;
		Q[++rear] = root;
		int flag = 0;
		while (front < rear) {
			p = Q[++front];
			if (p->left) Q[++rear] = p->left;
			if (p->right) Q[++rear] = p->right;
			if (front < last) {
				if (flag == 0) curr.push_back(p->val);
				else curr.insert(curr.begin(), p->val);
			}
			if (front == last) {
				if (flag == 0) {
					curr.push_back(p->val);
					flag = 1;
				}
				else {
					curr.insert(curr.begin(), p->val);
					flag = 0;
				}
				ret.push_back(curr);
				last = rear;
				curr.clear();
			}

		}
		return ret;
	}
};