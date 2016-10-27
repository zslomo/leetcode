#include<stack>
using namespace std;

class Queue {
private:
	stack<int> s;
public:
	// Push element x to the back of queue.
	void push(int x) {
		s.push(x);
	}

	// Removes the element from in front of queue.
	void pop(void) {
		stack<int> st;
		st = reverse(s);
		st.pop();
		s = reverse(st);
	}

	// Get the front element.
	int peek(void) {
		stack<int> st;
		st = reverse(s);
		int temp = st.top();
		s = reverse(st);
		return temp;
	}

	// Return whether the queue is empty.
	bool empty(void) {
		return s.empty();
	}
private:
	stack<int> reverse(stack<int> s) {
		stack<int> st;
		int temp;
		while (!s.empty()) {
			temp = s.top();
			s.pop();
			st.push(temp);
		}
		return st;
	}
};