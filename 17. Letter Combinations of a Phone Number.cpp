#include<vector>
#include<string>
using namespace std;
class Solution {
private:
	vector<string> ret;
	string curr;
	string keybord[8] = { "abc","def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
public:
	void dfs(vector<string> strVec,int depth) {
		if (depth == strVec.size()) {
			ret.push_back(curr);
			return;
		}
		for (int i = 0; i < strVec[depth].size(); ++i) {
			curr.push_back(strVec[depth][i]);
			dfs(strVec, depth + 1);
			curr.pop_back();
		}
	}
	vector<string> letterCombinations(string digits) {
		vector<string> strVec;
		if (!digits.size()) return strVec;
		for (int i = 0; i < digits.size(); ++i) 
			strVec.push_back(keybord[digits[i] - '0' - 2]);
		dfs(strVec, 0);
		return ret;
	}
};