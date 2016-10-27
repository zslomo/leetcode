#include<vector>
using namespace std;
class Solution {
public:
	int binary_search(vector<int>& nums, int target, int first, int last) {
		int mid = -1;
		while (first <= last) {
			mid = (first + last) / 2;
			if (nums[mid] == target) return mid;
			if (nums[mid] < target) first = mid + 1;
			if (nums[mid] > target) last = mid - 1;
		}
		return -1;
	}
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> ret(2, -1);
		if (!nums.size()) return ret;
		int position = binary_search(nums, target, 0, nums.size() - 1);
		int first = position, last = position;
		int f = first, l = last;
		if (position == -1)return ret;
		else {
			while (first != -1 && first > 0) {
				first = binary_search(nums, target, 0, first - 1);
				if (first != -1) f = first;
			}
			while (last != -1 && last < nums.size() - 1) {
				last = binary_search(nums, target, last + 1, nums.size() - 1);
				if (last != -1) l = last;
			}
		}
		ret[0] = f;
		ret[1] = l;
		return ret;
	}
};