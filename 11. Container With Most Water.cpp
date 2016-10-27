#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
class Solution {
public:
	int maxArea(vector<int>& height) {
		if (height.empty()) return 0;
		int i = 0, j = height.size() - 1;
		int ret = 0, curr = 0;
		while (i < j) {
			curr = min(height[i], height[j])*(j - i);
			ret = max(ret, curr);
			if (height[i] < height[j]) {
				int left = i;
				i++;
				while (height[i] < height[left]) i++;
			}
			else {
				int right = j;
				j--;
				while (height[j] < height[right]) j--;
			}
		}
		return ret;
	}
};