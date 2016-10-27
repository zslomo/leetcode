#include<vector>
using namespace std;
class Solution {
public:
	int findPeakElement(const vector<int> &num) {
		int n = num.size();
		if (n == 1) {
			return 0;
		}

		int start = 0;
		int end = n - 1;
		int mid = 0;

		while (start <= end) {
			mid = start + (end - start) / 2;
			if ((mid == 0 || num[mid] >= num[mid - 1]) &&
				(mid == n - 1 || num[mid] >= num[mid + 1])) {
				return mid;
			}
			else if (mid > 0 && num[mid - 1] > num[mid]) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
		return mid;
	}
};