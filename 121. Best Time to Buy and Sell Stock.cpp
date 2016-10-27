#include<vector>
using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() <= 0) return 0;
		int minPrice= prices[0];
		int profit = 0;
		for (int i = 0; i < prices.size(); i++) {
			minPrice = minPrice < prices[i] ? minPrice : prices[i];
			profit = profit > prices[i] - minPrice ? profit : prices[i] - minPrice;
		}
		return profit;
	}
};