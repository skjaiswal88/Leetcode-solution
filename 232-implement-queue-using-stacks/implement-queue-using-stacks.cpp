#include <bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;

    MyQueue() {
    }
    
    void push(int x) {
        // Move all elements from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Push the new element onto s1
        s1.push(x);

        // Move everything back to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int y = s1.top();
        s1.pop();
        return y;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
