#include<vector>
#include<algorithm>
#include<limits>
using namespace std;
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int n = nums.size();
		if (n <= 0) return 1;
		for (int i = 0; i < n; i++) {
			if (nums[i] <= 0) nums[i] = n + 2;
		}
		for (int i = 0; i < n; i++) {
			int val = abs(nums[i]);
			if (val - 1 <= n)
				nums[val - 1] = -abs(nums[val - 1]);
		}
		for (int i = 0; i < n; i++) {
			if (nums[i] > 0) return i + 1;
		}
		return n + 1;
	}
};