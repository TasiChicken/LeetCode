#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long sum = 0, g_sum = 0;
        for(int i = 0; i < k; i++)
            sum += nums[i];
        g_sum = sum;
        
        for(int i = k ; i < nums.size(); i++){
            sum = sum - nums[i - k] + nums[i];
            g_sum = max(g_sum, sum);
        }

        return (double)g_sum / k;
    }
};

int main() {
    while(true) {
        Solution solution;
        //code here
    }
    
    return 0;
}