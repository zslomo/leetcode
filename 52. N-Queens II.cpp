#include<math.h>
#include<vector>
using namespace std;

class Solution {
private:
	vector<int> queen;
	int count = 0;
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
			count++;
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
	int totalNQueens(int n) {
		queen.reserve(n);
		PlaceQueen(0, n);
		return count;
	}
};