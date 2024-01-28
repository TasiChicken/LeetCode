#include <iostream>
#include <vector>

using namespace std;

class Iterator {
	struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};

class PeekingIterator : public Iterator {
    bool peeked;
    int num;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
        peeked = false;
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if(!peeked){
            peeked = true;
            num = Iterator::next();
        }

        return num;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if(!peeked) return Iterator::next();
        
        peeked = false;
        return num;
	}
	
	bool hasNext() const {
	    return peeked || Iterator::hasNext();
	}
};