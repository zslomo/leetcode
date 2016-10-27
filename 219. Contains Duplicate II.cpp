#include<vector>
#include<map>
using namespace std;
//ÅÅÐò¸ü¿ì
class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		if (nums.size() <= 1 || k <= 0) return false;
		map<int, int> hash;
		for (int i = 0; i < nums.size(); i++) {
			if (hash.find(nums[i]) == hash.end())
				hash[nums[i]] = i;
			else if (i - hash[nums[i]] <= k)
				return true;
			else hash[nums[i]] = i;
		}
		return false;

	}
};