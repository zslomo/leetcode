#include<vector>
#include<algorithm>
using namespace std;
class Solution {
private:
	vector<vector<int>> ret;
	vector<int> curr;
public:
	void backtraking(vector<int>& nums, int pos) {
		for (int i = pos; i < nums.size(); i++) {
			if (i > pos&&nums[i] == nums[i - 1]) continue;
			curr.push_back(nums[i]);
			ret.push_back(curr);
			backtraking(nums, i + 1);
			curr.pop_back();
		}
	}
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		if (nums.size() == 0) return ret;
		sort(nums.begin(), nums.end());
		ret.push_back(curr);
		backtraking(nums, 0);
		return ret;
	}
};