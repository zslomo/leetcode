#include"Inc.h"
class Solution {
public:
	bool isNumber(string s) {
		int pCount = 0;
		int pPosition = 0;
		int eCount = 0;
		int ePosition = s.size();
		int i = 0;
		while (s[i] == ' ') i++;
		if ((s[i] > '9' || s[i] < '0') && s[i] != '+'&&s[i] != '-'&&s[i] != '.')
			return false;
		else if (s[i] == '+' || s[i] == '-') i++;
		else if (s[i] == '.') {
			pPosition = i;
			pCount++;
			if (i + 1 < s.size())
				if (s[i + 1]<'0' || s[i + 1]>'9')
					return false;
			i++;

		}
		if (i >= s.size()) return false;
		for (; i < s.size(); i++) {
			if (s[i] <= '9'&&s[i] >= '0') continue;
			else if (s[i] == '.') {
				pPosition = i;
				if (pCount > 0 || ePosition < pPosition) return false;
				else {
					pCount++;
					if (s[i - 1]<'0' || s[i - 1]>'9') {
						if (i == s.size() - 1 || s[i + 1]<'0' || s[i + 1]>'9')
							return false;
					}
				}
			}
			else if (s[i] == 'e') {
				ePosition = i;
				if (eCount > 0 || ePosition < pPosition || i == s.size() - 1)
					return false;
				else {
					eCount++;
					if ((s[i + 1]<'0' || s[i + 1]>'9') && s[i + 1] != '+'&& s[i + 1] != '-') return false;
					if ((s[i - 1]<'0' || s[i - 1]>'9') && s[i - 1] != '.')
						return false;
				}
			}
			else if (s[i] == ' ') {
				for (int j = i + 1; j < s.size(); j++)
					if (s[j] != ' ') return false;
			}
			else if (s[i] == '+' || s[i] == '-') {
				if (s[i - 1] != 'e' || i == s.size() - 1 || (s[i + 1]<'0' || s[i + 1]>'9')) return false;
			}
			else return false;
		}
		return true;
	}
};