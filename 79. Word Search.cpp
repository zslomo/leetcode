#include<vector>
using namespace std;
class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (board.size() == 0 || board[0].size() == 0)
			return true;

		for (int i = 0; i<board.size(); i++) {
			for (int j = 0; j<board[0].size(); j++) {
				if (board[i][j] == word[0])
					if (check(board, word.substr(1), i, j))
						return true;
			}
		}
		return false;
	}

	bool check(vector<vector<char>>& board, string word, int i, int j) {
		if (word.length() == 0)
			return true;
		if (i<0 || j<0 || i >= board.size() || j >= board[0].size())
			return false;
		if (word[0] == board[i][j]) {
			char c = word[0];
			board[i][j] = '\0';
			if (check(board, word.substr(1), i + 1, j) ||
				check(board, word.substr(1), i - 1, j) ||
				check(board, word.substr(1), i, j + 1) ||
				check(board, word.substr(1), i, j - 1))
				return true;
			board[i][j] = c;
		}
		return false;
	}
};