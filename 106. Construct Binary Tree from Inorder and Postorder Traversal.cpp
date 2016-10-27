#include"Inc.h"
class Solution {
public:
	TreeNode* build(vector<int>& inorder, vector<int>& postorder, int ilow, int ihigh, int plow, int phigh) {
		if (ilow > ihigh || plow > phigh) return NULL;
		TreeNode* root = new TreeNode(postorder[phigh]);
		int i = ilow;
		for (i = ilow; i <= ihigh&&inorder[i] != postorder[phigh]; i++);
		int pi = i - ilow;
		root->left = build(inorder, postorder, ilow, i - 1, plow, plow + pi - 1);
		root->right = build(inorder, postorder, i + 1, ihigh, plow + pi, phigh - 1);
		return root;
	}
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (!inorder.size() || !postorder.size()) return NULL;
		int lenght = inorder.size();
		
		return build(inorder, postorder, 0, lenght - 1, 0, lenght - 1);

		
	}
};