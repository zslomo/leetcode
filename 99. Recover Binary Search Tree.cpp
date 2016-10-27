#include"Inc.h"
class Solution {
public:
	void recoverTree(TreeNode* root) {
		if (!root) return;
		TreeNode* p1 = NULL, *p2 = NULL;
		TreeNode* pre = NULL, *bef = NULL, *cur = root;
		bool found = false;
		while (cur) {
			if (!cur->left) {
				if (bef&&bef->val > cur->val) {
					if (!found) {
						p1 = bef;
						found = true;
					}
					p2 = cur;
				}
				bef = cur;
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
					if (bef->val > cur->val) {
						if (!found) {
							p1 = bef;
							found = true;
						}
						p2 = cur;
					}
					bef = cur;
					cur = cur->right;
				}
			}
		}
		if (p1&&p2) swap(p1->val, p2->val);
	}
};