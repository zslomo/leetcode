#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		int n = nums.size();
		if (n == 0 || k <= 0) return;
		k = k % n;
		for (int i = 0; i < (n - k) / 2; i++) {
			int temp = nums[i];
			nums[i] = nums[n - k - 1 - i];
			nums[n - k - 1 - i] = temp;
		}
		for (int i = 0; i < k / 2; i++) {
			int temp = nums[i + n - k];
			nums[i + n - k] = nums[n - 1 - i];
			nums[n - 1 - i] = temp;
		}
		for (int i = 0; i < n / 2; i++) {
			int temp = nums[i];
			nums[i] = nums[n - 1 - i];
			nums[n - 1 - i] = temp;
		}
	}
};