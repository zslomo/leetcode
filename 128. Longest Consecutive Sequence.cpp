#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		int n = nums.size();
		if (n == 0) return 0;
		unordered_set<int> m;
		int ret = 0;
		for (int i = 0; i < n; i++) {
			m.insert(nums[i]);
		}
		int temp = 0;
		while (!m.empty()) {
			int len = 1;
			int curr = *m.begin();
			m.erase(curr);
			temp = curr;
			while (m.find(temp + 1) != m.end()) {
				len++;
				m.erase(temp + 1);
				temp++;
			}
			temp = curr;
			while (m.find(temp - 1) != m.end()) {
				len++;
				m.erase(temp - 1);
				temp--;
			}
			ret = max(len, ret);
		}
		return ret;
	}
};