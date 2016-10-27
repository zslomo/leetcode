#include<vector>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
	vector<vector<int>> ret;
	vector<int> curr;
public:
	void backtrack(vector<int>& candidates, int target, int i,int sum) {	
		if (i < 0 || i >= candidates.size() || sum > target) return;
		if (sum == target) {
			ret.push_back(curr);
			return;
		}
		for (; i < candidates.size(); i++) {
			curr.push_back(candidates[i]);
			backtrack(candidates, target, i, sum + candidates[i]);
			curr.pop_back();
		}
	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		if (candidates.empty() || target == 0)
			return ret;
		sort(candidates.begin(), candidates.end());
		backtrack(candidates, target, 0, 0);
		return ret;
	}
};