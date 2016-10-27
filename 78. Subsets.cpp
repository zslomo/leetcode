#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		int n = nums.size();
		vector<vector<int>> ret;
		vector<int> curr;
		if (n == 0) return ret;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < (1 << n); i++) {
			curr.clear();
			for (int j = 0; j < n; j++) {
				if (i&(1 << j)) curr.push_back(nums[j]);
			}
			ret.push_back(curr);
		}
		return ret;
	}
};