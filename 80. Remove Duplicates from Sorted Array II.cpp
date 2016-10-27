#include<vector>
using namespace std;
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() <= 1) return nums.size();
		int i, j = 0, amount = 1;
		for (i = 1; i < nums.size(); i++) {
			if (nums[i] == nums[j]) {
				amount++;
				if (amount <= 2) nums[++j] = nums[i];
			}
			else {
				nums[++j] = nums[i];
				amount = 1;
			}
		}
		return j + 1;
	}
};