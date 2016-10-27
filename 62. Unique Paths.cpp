/*	dp[i][j]为[0][0]到[i][j]路径数量
	dp[i][j]=dp[i-1][j]+dp[i][j-1]
*/
#include<vector>
using namespace std;
class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> path(m, vector<int>(n));
		for (int i = 0; i < m; i++)
			path[i][0] = 1;
		for (int i = 0; i < n; i++)
			path[0][i] = 1;
		for (int i = 1; i < m; i++)
			for (int j = 1; j < n; j++) 
				path[i][j] = path[i - 1][j] + path[i][j - 1];
		return path[m - 1][n - 1];
	}
};