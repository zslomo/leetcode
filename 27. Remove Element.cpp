#include<vector>
using namespace std;
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		if (!nums.size()) return 0;
		int j = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == val) continue;
			nums[j] = nums[i];
			j++;
		}
		return j;
	}
};