#include<vector>
using namespace std;
class Solution {
	vector<vector<int>> ret;
	vector<int> curr;
public:
	void search(int k, int n, int i) {
		if (n == 0 && k == 0) {
			ret.push_back(curr);
			return;
		}
		if (k < 0 || n < 0 || i > 9) return;
		if ((k == 0 && n != 0) || (n == 0 && k != 0)) return;
		curr.push_back(i);
		search(k - 1, n - i, i + 1);
		curr.pop_back();
		search(k, n, i + 1);

	}
	vector<vector<int>> combinationSum3(int k, int n) {
		if (k <= 0 || n <= 0 || k >= n) return ret;
		search(k, n, 1);
		return ret;
	}
};