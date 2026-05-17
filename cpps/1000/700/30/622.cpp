#include <bits/stdc++.h>

using namespace std;

class MyCircularQueue {
    vector<int> q;
    int size;
    int ptr;
public:
    MyCircularQueue(int k) {
        q = vector<int>(k);
        size = 0;
        ptr = 0;
    }
    
    bool enQueue(int value) {
        if(size == q.size()) return false;

        q[ptr] = value;
        ptr = (ptr + 1) % q.size();
        size++;
        return true;
    }
    
    bool deQueue() {
        if(size == 0) return false;

        size--;
        return true;
    }
    
    int Front() {
        if(size == 0) return -1;
        

        return q[(q.size() + ptr - size) % q.size()];
    }
    
    int Rear() {
        if(size == 0) return -1;

        return q[(q.size() + ptr - 1) % q.size()];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == q.size();
    }
};