#include<vector>
using namespace std;
class MinStack {
private:
	vector <int> s;
	vector<int> mins;
public:
	void push(int x) {
		s.push_back(x);
		if (mins.empty()) mins.push_back(x);
		else {
			int temp = mins.back();
			if (x < temp) temp = x;
			mins.push_back(temp);
		}
	}

	void pop() {
		s.pop_back();
		mins.pop_back();
	}

	int top() {
		return s.back();
	}

	int getMin() {
		return mins.back();
	}
};