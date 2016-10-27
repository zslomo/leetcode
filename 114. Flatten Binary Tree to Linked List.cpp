#include"Inc.h"
class Solution {
public:
	void flatten(TreeNode* root) {
		while (root) {
			if (root->left) {
				TreeNode* p = root->left;
				while (p->right)
					p = p->right;
				p->right = root->right;
				root->right = root->left;
				root->left = NULL;
			}
			root = root->right;
		}
	}
};