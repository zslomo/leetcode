#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
class Solution {
public:
	int trap(vector<int>& height) {
		if (height.empty()) return 0;
		vector<int> lefthighest = { 0 };
		int righthighest = 0;
		int ret = 0, curr;
		for (int i = 1; i < height.size(); i++) {
			lefthighest.push_back(max(height[i - 1], lefthighest[i - 1]));
		}
		for (int i = height.size() - 2; i >= 0; i--) {
			righthighest = max(height[i + 1], righthighest);
			curr = min(lefthighest[i], righthighest);
			if (curr > height[i]) ret += curr - height[i];
		}
		return ret;
	}
};