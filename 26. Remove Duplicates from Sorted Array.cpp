#include<vector>
using namespace std;
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() <= 1) return nums.size();
		int i, j = 0;
		for (i = 1; i < nums.size(); i++) {
			if (nums[j] == nums[i]) continue;
			nums[j + 1] = nums[i];
			j++;
		}
		return j + 1;
	}
};