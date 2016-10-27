class Solution {
public:
	bool isPowerOfTwo(int n) {
		if (n <= 0) return false;
		bool flag = false;
		bitset<32> nbit(n);
		for (int i = 0; i < 31; i++) {
			if (nbit.test(i)) {
				if (flag) return false;
				else flag = true;
			}
		}
		if (flag) return true;
		else return false;
	}
};