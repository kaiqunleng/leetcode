#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<deque>
#include<list>
using namespace std;

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		stack.push_front(x);
		if (stack.size() == 1) {
			mmin.push_back(x);
			minx = x;
		}
		else {
			minx = min(x, minx);
			mmin.push_back(minx);
		}
	}

	void pop() {
		int num = stack.front();
		stack.pop_front();
		mmin.pop_back();
		minx = mmin.back();
	}

	int top() {
		int num = stack.front();
		return num;
	}

	int getMin() {
		return mmin.back();
	}
	deque<int>stack;
	vector<int>mmin;
	int minx = 0;
};
int main(int argc, char *argv[])
{
	MinStack a;
	a.push(-10);
	a.push(14);
	cout << a.getMin() << endl;
	cout << a.getMin() << endl;
	a.push(-20);
	cout << a.getMin() << endl;
	cout << a.getMin() << endl;
	cout << a.top() << endl;
	cout << a.getMin() << endl;
	a.pop();
	a.push(10);
	a.push(-7);
	cout << a.getMin() << endl;
	a.push(-7);
	a.pop();
	cout<<a.top()<<endl;
	cout<<a.getMin()<<endl;
	
     
	return 0;
}
