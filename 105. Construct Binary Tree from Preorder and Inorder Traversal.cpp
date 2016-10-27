#include"Inc.h"
class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (!preorder.size() || !inorder.size()) return NULL;
		return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);

	}
	TreeNode* build(vector<int>& preorder, vector<int>& inorder, int plow, int phigh, int ilow, int ihigh) {
		if (plow > phigh || ilow > ihigh) return NULL;
		TreeNode* root = new TreeNode(preorder[plow]);
		int i = ilow;
		for (; i <= ihigh&&inorder[i] != preorder[plow]; i++);
		root->left = build(preorder, inorder, plow + 1, plow + i - ilow, ilow, i - 1);
		root->right = build(preorder, inorder, plow + i - ilow + 1, phigh, i + 1, ihigh);
		return root;
	}
};