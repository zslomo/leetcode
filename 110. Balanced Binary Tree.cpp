#include"Inc.h"
class Solution {
public:
	int CheckHeight(TreeNode* p) {
		if (!p) return 0;
		int leftHeight = CheckHeight(p->left);
		if (leftHeight == -1) return -1;
		int rightHeight = CheckHeight(p->right);
		if (rightHeight == -1) return -1;
		int heightDiff = abs(leftHeight - rightHeight);
		if (heightDiff > 1) return -1;
		else return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
	}
	bool isBalanced(TreeNode* root) {
		if (!root) return true;
		if (CheckHeight(root) == -1) return false;
		else return true;
		
	}
};