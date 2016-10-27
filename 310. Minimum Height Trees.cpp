#include<vector>
#include<string>
#include<unordered_set>
using namespace std;
/*思路为删除叶子节点，删到只剩1-2个，原理是最矮生成树的树根一定是最长路径上的中间节点
不看discuss完全没思路，图的题练太少，多练*/
class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		vector<int> del;
		if (edges.size() <= 0) return{ 0 };
		unordered_set<int> *adj = new unordered_set<int>[n]; // 邻接表
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