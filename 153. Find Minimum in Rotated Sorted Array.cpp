#include<vector>
using namespace std;
class Solution {
public:
	int findMin(vector<int>& nums) {
		if (!nums.size()) return 0;
		if (nums.size() == 1)return nums[0];
		return FindMin_Core(nums, 0, nums.size() - 1);
	}
	int FindMin_Core(vector<int>& nums, int first, int last) {
		if (nums[first] < nums[last]) return nums[first];
		if (first + 1 == last)
			return nums[last];
		int mid = (first + last) / 2;
		if (nums[mid] < nums[first])
			return FindMin_Core(nums, first, mid);
		if (nums[mid] > nums[first])
			return FindMin_Core(nums, mid, last);
	}
};
