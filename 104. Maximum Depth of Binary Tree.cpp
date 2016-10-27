#include"Inc.h"
class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (!root) return 0;
		else {
			int left = maxDepth(root->left);
			int right = maxDepth(root->right);
			return (left > right ? left : right) + 1;
		}
	}

};