#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
	int largestRectangleArea(vector<int>& height) {
		stack<int> s;
		int LagestRect = 0;
		for (int i = 0; i < height.size(); i++) {
			if (s.empty() || s.top() < height[i])
				s.push(height[i]);
			else {
				int count = 0;
				while (!s.empty() && s.top() > height[i]) {
					LagestRect = LagestRect < s.top()*++count ? s.top()*count : LagestRect;
					s.pop();
				}
				while (count--) 
					s.push(height[i]);
				s.push(height[i]);
			}
		}
		int count = 0;
		while (!s.empty()) {
			LagestRect = LagestRect < s.top()*++count ? s.top()*count : LagestRect;
			s.pop();
		}
		return LagestRect;
	}
};