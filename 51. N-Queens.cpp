#include<vector>
#include<math.h>
using namespace std;
class solution {
private:
	vector<vector<string>> ret;
	vector<int> queen;
public:
	bool CheckPlace(int Checkline, int Checkrow) {
		for (int i = 0; i < Checkline; i++) {
			if (queen[i] == Checkrow || abs(Checkline - i) == abs(Checkrow - queen[i])) {
				return false;
			}
		}
		return true;
	}
	void PlaceQueen(int Checkline, int n) {
		if (Checkline == n) {
			vector<string> curr(n, string(n, '.'));
			for (int i = 0; i < queen.size(); i++) {
				curr[i][queen[i]] = 'Q';
			}
			ret.push_back(curr);
			return;
		}
		else {
			for (int i = 0; i < n; i++) {
				if (CheckPlace(Checkline, i)) {
					queen[Checkline] = i;
					PlaceQueen(Checkline + 1, n);
				}
			}
		}
	}
	vector<vector<string>> solveNQueens(int n) {
		queen.resize(n);
		PlaceQueen(0, n);
		return ret;
	}
};
