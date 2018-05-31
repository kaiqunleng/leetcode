#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<deque>
#include<list>
using namespace std;


class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		if (p1.empty() && p2.empty()) {
			p1.push_back(x);
		}
		else if (p2.empty() && !p1.empty()) {
			p2.push_back(x);
			while (!p1.empty()) {
				int num = p1.front();
				p1.pop_front();
				p2.push_back(num);
			}
		}
		else {
			p1.push_back(x);
			while (!p2.empty()) {
				int num = p2.front();
				p2.pop_front();
				p1.push_back(num);
			}
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		if (!p1.empty()) {
			int num = p1.front();
			p1.pop_front();
			return num;
		}
		if (!p2.empty()) {
			int num = p2.front();
			p2.pop_front();
			return num;
		}
	}

	/** Get the top element. */
	int top() {
		if (!p1.empty()) {
			int num = p1.front();
			return num;
		}
		if (!p2.empty()) {
			int num = p2.front();
			return num;
		}
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		if (p1.empty() && p2.empty()) {
			return true;
		}
		else {
			return false;
		}
	}

	list<int> p1, p2;
};


int main(int argc, char *argv[])
{
	MyStack a;
	a.push(5);
	cout << a.top() << endl;
	a.push(6);
	cout << a.pop() << endl;
	a.pop();
	cout << a.empty();
	return 0;
}
