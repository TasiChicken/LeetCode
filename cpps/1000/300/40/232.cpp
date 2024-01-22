#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
    stack<int> inp, outp;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        inp.push(x);
    }
    
    int pop() {
        if(outp.empty())
            while(!inp.empty()){
                outp.push(inp.top());
                inp.pop();
            }

        int ans = outp.top();
        outp.pop();
        return ans;        
    }
    
    int peek() {
        if(outp.empty())
            while(!inp.empty()){
                outp.push(inp.top());
                inp.pop();
            }
        
        return outp.top();
    }
    
    bool empty() {
        return outp.empty() && inp.empty();
    }
};