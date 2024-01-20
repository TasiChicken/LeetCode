#include <iostream>
#include <queue>

using namespace std;

class MyStack {
    queue<int> q;
    int t;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(t = x);
    }
    
    int pop() {
        for(int i = q.size(); i > 1; i--){
            this->push(q.front());
            q.pop();
        }

        int ans = q.front();
        q.pop();
        return ans;
    }
    
    int top() {
        return t;
    }
    
    bool empty() {
        return q.empty();
    }
};