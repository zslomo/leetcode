#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> ret;
		int n = nums.size();
		if (n == 0) return ret;
		int start = 0;
		for (int i = 0; i < n; i++) {
			if (i == n - 1 || nums[i] + 1 != nums[i + 1]) {
				string s = to_string(nums[start]);
				if (start != i) s += "->" + to_string(nums[i]);
				ret.push_back(s);
				start = i + 1;
			}
		}
		return ret;
	}
};