#include<vector>
#include<utility>
#include<queue>
using namespace std;
class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<vector<int>> MatGraph;
		int *deg = new int[numCourses];
		for (int i = 0; i < numCourses; i++) {
			MatGraph.push_back({});
			deg[i] = 0;
		}
		for (auto &a : prerequisites) {
			int k = a.first;
			MatGraph[a.second].push_back(k);
			deg[k]++;
		}
		queue<int> q;
		int count = 0;
		for (int i = 0; i < numCourses; i++) {
			if (deg[i] == 0) {
				q.push(i);
				count++;
			}
		}
		while (!q.empty()) {
			int curr = q.front(); q.pop();
			for (auto &a : MatGraph[curr]) {
				if (--deg[a] == 0) {
					q.push(a);
					count++;
				}
			}
		}
		delete[]deg;
		if (count == numCourses) return true;
		else return false;
	}
};
