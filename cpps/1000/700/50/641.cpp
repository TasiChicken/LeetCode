#include <bits/stdc++.h>

using namespace std;

class MyCircularDeque {
    vector<int> v;
    int p_begin, p_end, size;
public:
    MyCircularDeque(int k) {
        v = vector<int>(k);
        p_begin = p_end = size = 0;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        
        p_begin = (p_begin - 1 + v.size()) % v.size();
        v[p_begin] = value;
        
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;

        v[p_end] = value;
        p_end = (p_end + 1) % v.size();

        size++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;

        p_begin = (p_begin + 1) % v.size();

        size--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;

        p_end = (p_end - 1 + v.size()) % v.size();

        size--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return v[p_begin];
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return v[(p_end - 1 + v.size()) % v.size()];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == v.size();
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */