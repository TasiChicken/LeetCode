#include <iostream>
#include <queue>

using namespace std;

class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> up;
    priority_queue<int, vector<int>, less<int>> down;
public:
    MedianFinder(){
    }
    
    void addNum(int num){
        if(down.empty()) return down.push(num);

        if(num < down.top()) down.push(num);
        else up.push(num);
        
        if(up.size() > down.size() + 1) 
            down.push(up.top()), up.pop();
        else if(down.size() > up.size() + 1) 
            up.push(down.top()), down.pop();
    }
    
    double findMedian(){
        int s_diff = up.size() - down.size();
        if(s_diff) return s_diff > 0 ? up.top() : down.top();
        return up.top() / 2.0 + down.top() / 2.0;
    }
};