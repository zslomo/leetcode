#include"Inc.h"
class Solution {
public:
	int minDepth(TreeNode* root) {
		if (!root) return 0;
		if (!root->left) return minDepth(root->right) + 1;
		else if (!root->right) return minDepth(root->left) + 1;
		else {
			int left = minDepth(root->left);
			int right = minDepth(root->right);
			return (left < right ? left : right) + 1;
		}
	}
};