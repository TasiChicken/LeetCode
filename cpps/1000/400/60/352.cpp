#include <iostream>
#include <vector>

using namespace std;

class SummaryRanges {
    vector<vector<int>> intervals;
    int search(int n){
        int l = 0, r = intervals.size() - 1, mid;
        while (l <= r){
            mid = l + r >> 1;
            if(intervals[mid][0] > n) r = mid - 1;
            else if((intervals[mid][1] < n)) l = mid + 1;
            else return -1;
        }
        return l;
    }
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        int idx = search(value);
        if(idx == -1) return;

        bool l = idx > 0 && intervals[idx - 1][1] == value - 1;
        bool r = idx < intervals.size() && intervals[idx][0] == value + 1;
        if(l && r) intervals[idx - 1][1] = intervals[idx][1], intervals.erase(intervals.begin() + idx);
        else if(l) intervals[idx - 1][1] = value;
        else if(r) intervals[idx][0] = value;
        else intervals.insert(intervals.begin() + idx, {value, value});
    }
    
    vector<vector<int>> getIntervals() {
        return intervals;
    }
};