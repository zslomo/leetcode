#include<queue>
using namespace std;
struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	void levelconnect(queue<TreeLinkNode *> Q) {
		if (Q.empty()) return;
		TreeLinkNode* p;
		while (!Q.empty()) {
			p = Q.front();
			Q.pop();
			if(!Q.empty())
				p->next = Q.front();
		}
	}
	void connect(TreeLinkNode *root) {
		if (!root) return;
		queue<TreeLinkNode *> Q;
		TreeLinkNode *p = NULL;
		TreeLinkNode *last = root;
		Q.push(root);
		while (!Q.empty()) {
			p = Q.front();
			Q.pop();
			if (p->left) Q.push(p->left);
			if (p->right) Q.push(p->right);
			if (last == p) {
				last->next = NULL;
				last = Q.back();
				levelconnect(Q);
			}
		}
	}
};