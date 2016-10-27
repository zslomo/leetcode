#include"Inc.h"
class Solution {
public:
	int reverse(int x) {
		if (x == 0) return 0;
		int ret = 0;
		while (x) {
			int temp = ret * 10 + x % 10;//Ñ§Ï°¡£¡£¡£¡£
			if (temp / 10 != ret) return 0;//Òç³öÅÐ¶Ï
			else ret = temp;
			x /= 10;
		}
		return ret;
	}
};