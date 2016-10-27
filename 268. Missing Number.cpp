#include<vector>
using namespace std;
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		if (!nums.size()) return 0;
		int Xor = 0;
		for (int i = 0; i < nums.size() + 1; i++) Xor = Xor^i;
		for (auto i : nums) Xor = Xor^i;
		return Xor;
	}
};