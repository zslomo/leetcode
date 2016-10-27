#include<bitset>
using namespace std;
class Solution {
public:
	bool isPowerOfTwo(int n) {
		if (n < 0) return false;
		bool hasOne = false;
		while (n > 0) {
			if (n & 1) {
				if (hasOne) {
					return false;
				}
				else {
					hasOne = true;
				}
			}
			n >>= 1;
		}
		return hasOne;
	}
};