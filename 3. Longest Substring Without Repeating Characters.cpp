#include"Inc.h"
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		map<char, bool> m;
		int i = 0, j = 0;
		int len = 0;
		while (j < s.size()) {
			if (m.find(s[j]) != m.end()) {
				len = len > j - i ? len : j - i;
				while (s[i] != s[j]) {
					m.erase(m.find(s[i]));
					i++;
				}
				i++;
				j++;
			}
			else {
				m[s[j]] = true;
				j++;
			}
		}
		len = len > j - i ? len : j - i;
		return len;
	}
};