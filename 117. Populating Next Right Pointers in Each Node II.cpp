#include<queue>
using namespace std;
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (!root) return;
		TreeLinkNode *p = root;
		TreeLinkNode *last = NULL;
		TreeLinkNode *first = NULL;
		while (p) {
			if (!first) {
				if (p->left) first = p->left;
				else if (p->right) first = p->right;
			}
			if (p->left) {
				if (last) last->next = p->left;
				last = p->left;
			}
			if (p->right) {
				if (last)last->next = p->right;
				last = p->right;
			}
			if (p->next) p = p->next;
			else {
				p = first;
				first = NULL;
				last = NULL;
			}
		}
	}
};