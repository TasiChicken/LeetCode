#include <iostream>
#include <vector>

using namespace std;

class NumArray {
    vector<int> n, nums;

    int sum(int x){
        int ans = 0;
        for(; x; x -= x & -x)
            ans += n[x - 1];
        return ans;
    }
public:
    NumArray(vector<int>& nums){
        this->n = this->nums = nums;

        for(int i = 2; i <= n.size(); i++)
            n[i - 1] += sum(i - 1) - sum(i - (i & -i));
    }

    void update(int i, int val) {
        int delta = val - nums[i];
        nums[i] += delta;

        for(i++; i <= n.size(); i += i & -i)
            n[i - 1] += delta;
    }
    
    int sumRange(int left, int right) {
        return sum(right + 1) - sum(left);
    }
};