#include <iostream>
#include <vector>

using namespace std;

class NumArray {
    vector<int> sums;
public:
    NumArray(vector<int>& nums) {
        sums = nums;
        for(int i = 1; i < sums.size(); i++) sums[i] += sums[i - 1];
    }
    
    int sumRange(int left, int right) {
        return sums[right] - (left ? sums[left - 1] : 0);
    }
};