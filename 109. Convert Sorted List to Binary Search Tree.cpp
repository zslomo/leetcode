#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	TreeNode* build(ListNode* begin, ListNode* end) {
		if (begin == end) return NULL;
		ListNode* fast = begin;
		ListNode* slow = begin;
		while (fast != end&&fast->next != end) {
			fast = fast->next->next;
			slow = slow->next;
		}
		TreeNode* root = new TreeNode(slow->val);
		root->left = build(begin, slow);
		root->right = build(slow->next, end);
		return root;
	}
	TreeNode* sortedListToBST(ListNode* head) {
		if (!head) return NULL;
		return build(head, NULL);
	}
};
