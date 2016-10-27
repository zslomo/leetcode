#include<math.h>
using namespace std;
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;
		if (x == 0) return true;
		int length = 0;
		int number = x;
		int xR = 0;
		while (number) {
			number = number / 10;
			length++;
		}
		number = x;
		for (int i = 0, l = length - 1; i < length; i++, l--) {
			xR = xR + (number % 10)*pow(10, l);
			number = number / 10;
		}
		for (int i = 0; i < length; i++) {
			int x_n = x % 10;
			int xR_n = xR % 10;
			if (x_n != xR_n) return false;
			x = x / 10;
			xR = xR / 10;
		}
		return true;
	}
};