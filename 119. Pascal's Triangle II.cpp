#include<vector>
using namespace std;
class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> ret;
		ret.resize(rowIndex + 1, 1);
		if (!rowIndex) return ret;
		for (int i = 1; i <= rowIndex; i++)
			for (int j = i; j >= 0; j--)
				ret[j] = ((j == 0 ? 0 : ret[j - 1]) + (j == i ? 0 : ret[j]));
		return ret;
	}
};