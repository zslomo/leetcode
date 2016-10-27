#include<vector>
#include<algorithm>
using namespace std;
class Solution {
private:
	int dis[8][2] = { { -1,-1 },{ -1,0 } ,{ -1,1 },{ 0,1 },{ 1,1 },{ 1,0 },{ 1,-1 },{ 0,-1 } };
public:
	bool Islive(vector<vector<int>>& board, int i, int j) {
		if (i >= 0 && i < board.size() && j >= 0 && j < board[0].size() && board[i][j] % 10 == 1)
			return true;
		else return false;
	}
	void gameOfLife(vector<vector<int>>& board) {
		int n = board.size();
		int m = board[0].size();
		if (n == 0 || m == 0) return;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int count = 0;
				for (int k = 0; k < 8; k++) {
					if (Islive(board, i + dis[k][0], j + dis[k][1]))
						count++;
				}
				if (count == 3 || (board[i][j] == 1 && count == 2))
					board[i][j] += 10;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				board[i][j] /= 10;
			}
		}
	}
};