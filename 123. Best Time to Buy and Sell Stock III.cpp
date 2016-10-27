#include<vector>
using namespace std;
using std::numeric_limits;
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		//�շ���0
		if (prices.empty()) return 0;
		//�½���������0-i������������
		vector<int> profit(prices.size());
		int minprofit = 0, maxprofit = 0;
		//sum�ǵڶ��μ���i-n-1��������������0-i��������ĺ�
		int sum = numeric_limits<int>::min(), min = prices[0];
		//retΪ����ֵ
		int ret = 0;
		//��һ�α�������0-i�����������
		for (int i = 1; i < prices.size(); i++) {
			//�������ڻ�����С������ʱ��
			min = min < prices[i - 1] ? min : prices[i - 1];
			//����0-i�����������
			profit[i] = profit[i - 1]> prices[i] - min ? profit[i - 1] : prices[i] - min;
		}
		//��ʼ�����ֵΪ���һ��Ԫ��
		maxprofit = prices[prices.size() - 1];
		//�Ӻ���ǰ����i-n-1������������
		for (int i = prices.size() - 2; i >= 0; i--) {
			//���������������ʱ��
			maxprofit = maxprofit > prices[i + 1] ? maxprofit : prices[i + 1];
			//sum�����Ǳ������������
			sum = sum > maxprofit - prices[i] ? sum : maxprofit - prices[i];
			//�����������������µĺ����������������
			if (sum >= 0) {
				//����profit[i]�ŵ���0-i��i-n-1������������֮��
				profit[i] = sum + profit[i];
				//���·���ֵ������ֵ����ǰ�����������������֮�ͣ�
				ret = ret > profit[i] ? ret : profit[i];
			}
		}
		return ret;
	}
};