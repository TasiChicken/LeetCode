#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long x_y = 0, x2_y2 = 0;

        for(int i = 0; i < nums.size(); i++){
            x_y += i + 1 - nums[i];
            x2_y2 += (i + 1) * (i + 1) - nums[i] * nums[i];
        }

        long long xplusy = x2_y2 / x_y;

        int x = (xplusy + x_y) / 2;
        int y = (xplusy - x_y) / 2;

        return {y, x};
    }
};

int main() {
    while(true) {
        Solution solution;
        //code here
    }
    
    return 0;
}