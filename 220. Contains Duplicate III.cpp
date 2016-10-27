#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
struct state {
	long num;
	int indices;
	bool operator<(const state &rhs)const {
		if (num != rhs.num)  return num < rhs.num;
		return indices < rhs.num;
	}
};
class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		if (nums.size() <= 1 || k <= 0 || t < 0) return false;
		int n = nums.size();
		state *a = new state[n];
		for (int i = 0; i < n; i++) {
			a[i].num = (long)nums[i];
			a[i].indices = i;
		}
		sort(a, a + n);
		for (int i = 0; i < n - 1; i++) {
			int j = i + 1;
			while (a[j].num - a[i].num <= t&&j<n) {
				if (abs(a[j].indices - a[i].indices) <= k) {
					delete[]a;
					return true;
				}
				j++;
			}
		}
		delete[]a;
		return false;
	}
};