#include<map>
#include<vector>
using namespace std;
class Solution {
public:
	bool wordPattern(string pattern, string str) {
		map<char, string> hash_map;
		map<string, char> hash_mapR;
		vector<string> v;
		string word("");
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == ' ') {
				v.push_back(word);
				word = "";
			}else {
				word = word + str[i];
			}
			if (i == str.size() - 1)
				v.push_back(word);
		}
		if (pattern.size() != v.size()) return false;
		for (int i = 0; i < pattern.size(); i++) {
			if (hash_map.find(pattern[i]) == hash_map.end()&&hash_mapR.find(v[i])==hash_mapR.end()) {

				hash_map[pattern[i]] = v[i];
				hash_mapR[v[i]] = pattern[i];

			}
			else if (hash_map.find(pattern[i]) != hash_map.end() && hash_mapR.find(v[i]) != hash_mapR.end()) {
				if (hash_map[pattern[i]] != v[i])
					return false;
			}
			else
				return false;

		}
		return true;
	}
};