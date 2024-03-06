#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class NestedInteger {
public:
    bool isInteger() const;
    int getInteger() const;
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
    vector<NestedInteger>* from;
    int idx = 0;
    NestedIterator* cur = nullptr;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        from = &nestedList;
    }
    
    int next() {
        return cur ? cur->next() : (*from)[idx++].getInteger();
    }
    
    bool hasNext() {
        if(cur){
            if(cur->hasNext()) return true;
            delete cur;
            cur = nullptr;
        }

        if(idx >= from->size()) return false;
        if((*from)[idx].isInteger()) return true;
        
        cur = new NestedIterator((*from)[idx++].getList());
        return hasNext();
    }
};