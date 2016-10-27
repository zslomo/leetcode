#include"Inc.h"
class Solution {
public:
	bool CalculateAndStore(vector<vector<int>> &ret, vector<int> &curr, stack<TreeNode*> sta, int sum) {
		curr.clear();
		int target = 0;
		while (!sta.empty()) {
			target += sta.top()->val;
			curr.insert(curr.begin(), sta.top()->val);
			sta.pop();
		}
		if (target == sum) { 
			ret.push_back(curr);
			return true; 
		}
		else {
			curr.clear();
			return false;
		}

	}
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> ret;
		vector<int> curr;
		if (!root) return ret;
		stack<TreeNode*> sta;
		TreeNode* p = root;
		TreeNode* pre = NULL;
		while (p) {
			sta.push(p);
			p = p->left;
		}
		while (!sta.empty()) {
			p = sta.top();
			if (!p->right || p->right == pre) {
				if (!p->right&&!p->left) {
					CalculateAndStore(ret, curr, sta, sum);
				}
				pre = p;
				sta.pop();
			}
			else {
				p = p->right;
				while (p) {
					sta.push(p);
					p = p->left;
				}
			}
		}
		return ret;
	}
};