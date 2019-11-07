#include <iostream>
#include <queue>
using namespace std;

class MyStack {
	queue<int> q1;
	queue<int> q2;
public:
	/** Initialize your data structure here. */
	MyStack() {
	}

	/** Push element x onto stack. */
	void push(int x) {
		q1.push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		for (int i = 0; i < q1.size() - 1; ++i)
		{
			q2.push(q1.front());
			q1.pop();
		}
		int r = q1.front();
		q1.pop();
		for (int i = 0; i < q2.size(); ++i)
		{
			q1.push(q2.front());
			q2.pop();
		}
		return r;
	}

	/** Get the top element. */
	int top() {
		return q1.back();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return !q1.size();
	}
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main()
{
	MyStack s;
	s.push(1);
	s.push(2);
	s.push(3);
	cout << s.pop() << endl;
	cout << s.pop();
	int i;
}