#include<stdint.h>
using namespace std;
class Solution {
public:
	int hammingWeight(uint32_t n) {
		int n1 = 0;
		for (int i = 0; i < 32; i++) {
			if (n & 1) n1++;
			n = n >> 1;
		}
		return n1;
	}
};