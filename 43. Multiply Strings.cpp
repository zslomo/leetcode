#include"Inc.h"
class Solution {
public:
	string multiply(string num1, string num2) {
		int n = num1.size();
		int m = num2.size();
		string ret(n + m, '0');
		vector<int> nums1(n);
		vector<int> nums2(m);
		vector<int> nums3(m + n, 0);;
		for (int i = 0; i < n; i++)nums1[i] = num1[n - i - 1] - '0';
		for (int i = 0; i < m; i++)nums2[i] = num2[m - i - 1] - '0';
		for (int i = 0; i < num1.size(); i++)
			for (int j = 0; j < num2.size(); j++) {
				nums3[i + j] += nums1[i] * nums2[j];
				nums3[i + j + 1] += nums3[i + j] / 10;
				nums3[i + j] %= 10;
			}
		for (int i = 0; i<n + m; i++) ret[i] += nums3[i];
		int index = ret.size();
		while (index>1 && ret[--index] == '0') ret.pop_back();
		reverse(ret.begin(), ret.end());

		return ret;
	}
};