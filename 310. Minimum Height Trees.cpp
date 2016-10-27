#include<vector>
#include<string>
#include<unordered_set>
using namespace std;
/*˼·Ϊɾ��Ҷ�ӽڵ㣬ɾ��ֻʣ1-2����ԭ�����������������һ�����·���ϵ��м�ڵ�
����discuss��ȫû˼·��ͼ������̫�٣�����*/
class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		vector<int> del;
		if (edges.size() <= 0) return{ 0 };
		unordered_set<int> *adj = new unordered_set<int>[n]; // �ڽӱ�
		for (auto &a : edges) {
			adj[a.first].insert(a.second);
			adj[a.second].insert(a.first);
		}
		for (int i = 0; i < n; i++) {
			if (adj[i].size() == 1) del.push_back(i);
		}

		while (n > 2) {
			vector<int> next;
			for (auto &a : del) {
				int x = *adj[a].begin();
				adj[x].erase(a);
				if (adj[x].size() == 1) next.push_back(x);
			}
			n -= del.size();
			del.swap(next);
		}
		return del;
	}
};