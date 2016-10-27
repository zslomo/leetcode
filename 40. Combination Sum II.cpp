#include<vector>
#include<algorithm>
using namespace std;
class Solution {
	vector<vector<int>> ret;
	vector<int> curr;
public:
	void search(vector<int>& candidates, int target, int i) {
		if (target == 0) {
			ret.push_back(curr);
			return;
		}
		if (i >= candidates.size() || candidates[i] > target)
			return;
		curr.push_back(candidates[i]);
		search(candidates, target - candidates[i], i + 1);
		curr.pop_back();
		while (i < candidates.size() - 1 && candidates[i] == candidates[i + 1])
			i++;
		search(candidates, target, i + 1);

	}
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		if (candidates.empty() || target == 0) return ret;
		sort(candidates.begin(), candidates.end());
		search(candidates, target, 0);
		return ret;
	}
};