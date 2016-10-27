#include"Inc.h"
class Solution {
public:
	TreeNode* build(vector<int>& nums, int low, int high) {
		if (low > high) return NULL;
		int mid = (low + high) / 2;
		TreeNode* node = new TreeNode(nums[mid]);
		node->left = build(nums, low, mid - 1);
		node->right = build(nums, mid + 1, high);
		return node;
	}
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (!nums.size()) return NULL;
		return build(nums, 0, nums.size() - 1);
	}
};