#include<iostream>
#include<list>
using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        a.push_front(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        
        if(!a.empty()&&b.empty()){
            while (!a.empty()){
            int num = a.front();
			b.push_front(num);
			a.pop_front(); 
            }
            int num = b.front();
            b.pop_front();
            return num;
        }
        if(a.empty()&&!b.empty()){
            int num = b.front();
            b.pop_front();
            return num;
        }
        if(!a.empty()&&!b.empty()){
            int num = b.front();
            b.pop_front();
            if(!b.empty()){
                while(!b.empty()){
                    int nums = b.front();
                    b.pop_front();
                    a.push_front(nums);   
                }
                while(!a.empty()){
                    int nums = a.front();
                    a.pop_front();
                    b.push_front(nums);
                }
            }            
            return num;   
         }
    }
    
    /** Get the front element. */
    int peek() {
        
        if(!a.empty()&&b.empty()){
            while (!a.empty()){
            int num = a.front();
			b.push_front(num);
			a.pop_front(); 
            }
            int num = b.front();
            return num;
            
        }
        if(a.empty()&&!b.empty()){
            int num = b.front();
            return num;
        }
        if(!a.empty()&&!b.empty()){
                  
            int num = b.front();
            return num;   
         }
    }
    /** Returns whether the queue is empty. */
    bool empty() {
        return a.empty()&&b.empty();
    }
            list<int>a;
	    list<int>b;
};



int main(){
	
	MyQueue a;
	a.push(10);
	a.push(1);
	int c = a.peek();
	int d = a.pop();
	cout<<c<<endl;
	cout<<d<<endl;
	cout<<a.empty();
	
	
	
	
	return 0;
}
