//#include"Inc.h"
//class Solution {
//public:
//	int myAtoi(string str) {
//		if (str.empty()) return 0;
//		bool IsPos = true;
//		int i = 0;
//		int count = 0;
//		long ans = 0;
//		while (str[i] == ' ') i++;
//		if (str[i] > '9' || str[i] < '0') {
//			if (str[i] == '+') IsPos = true;
//			else if (str[i] == '-') IsPos = false;
//			else return 0;
//		}
//		else ans = str[i] - 48;
//		for (i++; i < str.size(); i++) {
//			count++;
//			if (count<12) {
//				if (str[i] > '9' || str[i] < '0') {
//					break;
//				}
//				else {
//					ans = ans * 10 + str[i] - 48;
//				}
//			}
//			else {
//				if (IsPos) return 2147483647;
//				else return -2147483648;
//			}
//		}
//		if (IsPos) {
//			if (ans < 2147483647) return ans;
//			else return 2147483647;
//		}
//		else {
//			ans = 0 - ans;
//			if (ans > -2147483648) return ans;
//			else return -2147483648;
//		}
//
//	}
//};