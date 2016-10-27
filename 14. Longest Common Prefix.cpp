#include"Inc.h"
class Solution {
public:
	bool cmp(vector<string>& strs, string s) {
		for (int i = 1; i < strs.size(); i++) {
			unsigned int findIndex = strs[i].find(s);
			if (findIndex == string::npos || findIndex != 0)
				return false;
		}
		return true;
	}
	string longestCommonPrefix(vector<string>& strs) {
		string s, ret;
		if (!strs.size()) return ret;
		int l = INT_MAX;
		for (int i = 0; i < strs.size(); i++) 
			if (l > strs[i].size()) l = strs[i].size();
		while (l--) {
			s.push_back(*strs[0].begin());
			if (cmp(strs, s)) ret = s;
			strs[0].erase(strs[0].begin());
		}
		return ret;
	}
};

//int main(int argc, char **argv) {
//	Solution s;
//	vector<string> vec;
//	vec.push_back("aaaa");
//	vec.push_back("abaa");
//	vec.push_back("aaba");
//	cout << s.longestCommonPrefix(vec) << endl;
//	system("pause");
//	return 0;
//}