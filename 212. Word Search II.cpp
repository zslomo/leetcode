#include<vector>
using namespace std;
#define MAX 26
class TrieNode {
public:
	TrieNode *next[MAX];
	bool isWord;
	TrieNode() :isWord(false) {
		memset(next, NULL, sizeof(next));
	}
};
class TrieFunc {
	TrieNode *root;
public:
	TrieFunc() {
		root = new TrieNode();
	}
	TrieNode *GetRoot() {
		return root;
	}
	void insert(string word) {
		TrieNode *p = root;
		for (auto &a : word) {
			if (!p->next[a - 'a'])
				p->next[a - 'a'] = new TrieNode();
			p = p->next[a - 'a'];
		}
		p->isWord = true;
	}
};
class Solution {
	vector<string> ret;
public:
	void searchWord(vector<vector<char>>& board, string curr,TrieNode *root,int i,int j) {
		int m = board.size();
		int n = board[0].size();
		if (i < 0 || i >= m || j < 0 || j >= n || !root) return ;
		if (!root->next[board[i][j] - 'a']) return ;
		root = root->next[board[i][j] - 'a'];
		char temp = board[i][j];
		board[i][j] = '\0';
		curr.push_back(temp);
		if (root->isWord) {
			root->isWord = false;
			ret.push_back(curr);
		}
		searchWord(board, curr, root, i + 1, j);
		searchWord(board, curr, root, i - 1, j);
		searchWord(board, curr, root, i, j + 1);
		searchWord(board, curr, root, i, j - 1);
		board[i][j] = temp;
		curr.pop_back();
	}
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		string curr;
		if (board.empty()) return ret;
		TrieFunc trie;
		for (auto &a : words) {
			trie.insert(a);
		}
		TrieNode *root = trie.GetRoot();
		for (int i = 0; i < board.size(); i++)
			for (int j = 0; j < board[0].size(); j++) {
				searchWord(board, curr, root, i, j);
			}
		return ret;
	}
};