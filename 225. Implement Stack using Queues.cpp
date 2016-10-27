#include<queue>
using namespace std;
class Stack {
private:
	queue<int> q;
	queue<int> q2;
public:
	// Push element x onto stack.
	void push(int x) {
		q.push(x);
	}

	// Removes the element on top of the stack.
	void pop() {
		int n = q.size();
		int temp;
		while (n > 1) {
			temp = q.front();
			q.pop();
			q.push(temp);
			n--;
		}
		q.pop();
	}

	// Get the top element.
	int top() {
		q2 = q;
		int n = q2.size();
		while (n > 1) {
			q2.pop();
			n--;
		}
		return q2.front();
	}

	// Return whether the stack is empty.
	bool empty() {
		if (q.size() <= 0) return true;
		else return false;
	}

};