#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;
/*DP���̣�
sell[i] = max(sell[i - 1], buy[i - 1] + prices[i])
buy[i] = max(buy[i - 1], sell[i - 2] - prices[i])
sell[i]������������Ʊ���ۼ����������ǰһ��������ǰһ������
buy[i]���������Ʊ���ۼ����������ǰһ�����ˣ�����ǰһ��cooldownǰ��������
*/
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty()) return 0;
		vector<int> sell(prices.size());
		vector<int> buy(prices.size());
		buy[0] = -prices[0];
		sell[0] = 0;
		for (int i = 1; i < prices.size(); i++) {
			sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
			if (i >= 2) {
				buy[i] = max(buy[i - 1], sell[i - 2] - prices[i]);
			}
			else {
				buy[i] = max(buy[i - 1], -prices[i]);
			}
		}
		return sell[prices.size() - 1];
	}

};