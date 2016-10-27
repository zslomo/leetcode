#include"Inc.h"
#include<sstream>
#include<iostream>
class Solution {
public:
	string addvector( vector<TreeNode*> s) {
		if (s.empty()) return NULL;
		stringstream str;
		int temp;
		for (int i = 0; i < s.size() - 1; i++) {
			temp = s[i]->val;
			str << temp << "->";
		}
		temp = s[s.size() - 1]->val;
		str << temp;
		return str.str();
	}
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> ret;
		vector<TreeNode*> s;
		if (!root) return ret;
		TreeNode *p = root, *pre = NULL;
		while (p) {
			s.push_back(p);
			p = p->left;
		}
		while (!s.empty()) {
			p = s.back();
			if (!p->right || p->right == pre) {
				if (!p->right&&!p->left)
					ret.push_back(addvector(s));
				pre = p;
				s.pop_back();
			}
			else {
				p = p->right;
				while (p) {
					s.push_back(p);
					p = p->left;
				}
			}
		}
		return ret;
	}
};