#include<vector>
using namespace std;
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if (!nums.size()) return 0;
		int first = 0, last = nums.size() - 1;
		while (first <= last) {
			int mid = (first + last) / 2;
			if (nums[mid] == target) return mid;
			if (nums[mid] < target) first = mid + 1;
			if (nums[mid] > target) last = mid - 1;
		}
		return first;
	}
};