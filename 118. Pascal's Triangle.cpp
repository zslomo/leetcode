#include<vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ret;
		vector<int> curr;
		if (!numRows) return ret;
		curr.push_back(1);
		ret.push_back(curr);
		for (int i = 1; i < numRows; i++) {
			vector<int> curr;
			for (int j = 0; j <= i; j++) {
				curr.push_back((j == 0 ? 0 : ret[i - 1][j - 1]) + (j == i ? 0 : ret[i - 1][j]));
			}
			ret.push_back(curr);
		}
		return ret;
	}
};