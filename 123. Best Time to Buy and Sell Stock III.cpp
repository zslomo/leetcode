#include<vector>
using namespace std;
using std::numeric_limits;
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		//空返回0
		if (prices.empty()) return 0;
		//新建容器，放0-i区间的最大收益
		vector<int> profit(prices.size());
		int minprofit = 0, maxprofit = 0;
		//sum是第二次计算i-n-1区间最大收益后与0-i区间收益的和
		int sum = numeric_limits<int>::min(), min = prices[0];
		//ret为返回值
		int ret = 0;
		//第一次遍历计算0-i区间最大收益
		for (int i = 1; i < prices.size(); i++) {
			//找区间内花费最小的买入时间
			min = min < prices[i - 1] ? min : prices[i - 1];
			//保存0-i区间最大收益
			profit[i] = profit[i - 1]> prices[i] - min ? profit[i - 1] : prices[i] - min;
		}
		//初始化最大值为最后一个元素
		maxprofit = prices[prices.size() - 1];
		//从后往前计算i-n-1区间的最大收益
		for (int i = prices.size() - 2; i >= 0; i--) {
			//找区间内最大卖出时间
			maxprofit = maxprofit > prices[i + 1] ? maxprofit : prices[i + 1];
			//sum现在是保存最大收益数
			sum = sum > maxprofit - prices[i] ? sum : maxprofit - prices[i];
			//更新收益容器，将新的后半区间最大收益加入
			if (sum >= 0) {
				//现在profit[i]放的是0-i和i-n-1区间的最大收益之和
				profit[i] = sum + profit[i];
				//更新返回值（返回值就是前后两个区间最大收益之和）
				ret = ret > profit[i] ? ret : profit[i];
			}
		}
		return ret;
	}
};