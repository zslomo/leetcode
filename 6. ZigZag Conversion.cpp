#include"Inc.h"
class Solution {
public:
	string convert(string s, int numRows) {
		string ret;
		if (s.empty()) return s;
		if (numRows == 1 || numRows == 0) return s;
		int diff = 2 * numRows - 2;
		for (int i = 0; i < numRows; i++) {
			for (int j = i; j < s.size(); j += diff) {
				ret += s[j];
				if (i % (numRows - 1) != 0 && (j + diff - 2 * i) < s.size()) {
					ret += s[j + diff - 2 * i];
				}
			}
		}
		return ret;

	}
};