#include<vector>
using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty()) return 0;
		int profit = 0;
		for (int i = 1; i < prices.size() - 1; i++) {
			if (prices[i + 1] > prices[i]) 
				profit += prices[i + 1] - prices[i];
		}
		return profit;
	}
};