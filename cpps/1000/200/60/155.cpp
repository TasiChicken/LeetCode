#include <iostream>
#include <stack>

using namespace std;

class MinStack {
    stack<pair<int, int>> s;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s.push({val, min(s.size() ? s.top().second : INT_MAX, val)});
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};
