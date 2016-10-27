#include<vector>
using namespace std;
class Solution {
	vector<vector<int>> ret;
	vector<int> curr;
public:
	void backtraking(int n, int k, int i) {
		if (k == 0) {
			ret.push_back(curr);
			return;
		}
		if (k < 0 || i>n) return;
		curr.push_back(i);
		backtraking(n, k - 1, i + 1);
		curr.pop_back();
		backtraking(n, k, i + 1);
	}
	vector<vector<int>> combine(int n, int k) {
		if (n == 0 || k == 0 || n < k) return ret;
		backtraking(n, k, 1);
		return ret;
	}
};