#include <iostream>
#include <cstdlib>
#include <stack>
#include <queue>

using namespace std;

//两个队列实现一个堆栈
template <class T>
class queueStack
{
	queue<T> queue1;
	queue<T> queue2;

public:

	queueStack()
	{

	}

	void push(T val)
	{
		queue1.push(val);
	}

	void pop()
	{
		while (queue1.size() != 1)
		{
			queue2.push(queue1.front());
			queue1.pop();
		}
		queue1.pop();
		while (queue2.size())
		{
			queue1.push(queue2.front());
			queue2.pop();
		}
	}

	T& top()
	{
		T& re = queue1.back();
		return re;
	}

	size_t size()
	{
		return queue1.size();
	}

	bool empty()
	{
		return !queue1.size();
	}

};


//两个堆栈实现一个队列
template <class T>
class stackQueue
{
	stack<T> stack1;
	stack<T> stack2;

public:

	stackQueue()
	{

	}

	void push(T val)
	{
		stack1.push(val);
	}

	void pop()
	{
		while (stack1.size() != 1)
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
		stack1.pop();
		while (stack2.size())
		{
			stack1.push(stack2.top());
			stack2.pop();
		}
	}

	T& front()
	{
		while (stack1.size() != 1)
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
		T& re = stack1.top();
		while (stack2.size())
		{
			stack1.push(stack2.top());
			stack2.pop();
		}
		return re;
	}

	T& back()
	{
		return stack1.top();
	}

	size_t size()
	{
		return stack1.size();
	}

	bool empty()
	{
		return !stack1.size();
	}

};


int main()
{
#if 0
	stackQueue<int> sQ1;
	sQ1.push(1);
	sQ1.push(2);
	sQ1.push(3);
	sQ1.push(4);
	sQ1.push(5);
	cout << sQ1.front() << endl;
	sQ1.pop();	
	cout << sQ1.front() << endl;
	sQ1.pop();
	cout << sQ1.front() << endl;
	sQ1.pop();
	cout << sQ1.front() << endl;
	sQ1.pop();
	cout << sQ1.front() << endl;
	sQ1.pop();
#endif
	queueStack<int> qS1;
	qS1.push(1);
	qS1.push(2);
	qS1.push(3);
	qS1.push(4);
	qS1.push(5);
	qS1.top() = 9;
	cout << qS1.top() << endl;
	qS1.pop();
	cout << qS1.top() << endl;
	qS1.pop();
	cout << qS1.top() << endl;
	qS1.pop();
	cout << qS1.top() << endl;
	qS1.pop();
	cout << qS1.top() << endl;
	qS1.pop();

	system("pause");
	return 0;
}