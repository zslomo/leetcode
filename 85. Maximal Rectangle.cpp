#include<vector>
#include<stack>
#include<algorithm>
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

	int maximalRectangle(vector<vector<char>>& matrix) {
		if (!matrix.size() || !matrix[0].size()) return 0;
		int maximal = 0;
		int n = matrix.size();
		int m = matrix[0].size();
		vector<vector<int>> mat(n, vector<int>(m,0));
		for (int i = 0; i < m; i++) 
			if (matrix[0][i] != '0') mat[0][i] = 1;
		for (int i = 1; i < n; i++)
			for (int j = 0; j < m; j++) {
				if (matrix[i][j] != '0' && matrix[i - 1][j] != '0')
					mat[i][j] = mat[i - 1][j] + 1;
				else mat[i][j] = matrix[i][j] - 48;
			}
		for (int i = 0; i < n; i++)
			maximal = max(maximal, largestRectangleArea(mat[i]));
		return maximal;
	}
	
};