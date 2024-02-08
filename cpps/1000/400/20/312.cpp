#include <iostream>
#include <vector>

using namespace std;

vector<int> parse_(string s){
    vector<int> v;
    int last = 1;
    for(int i = 2; i < s.length(); i++)
        if(s[i] == ',' || s[i] == ']') {
            v.push_back(stoi(s.substr(last, i - last)));
            last = i + 1;
        }
    return v;
}

class Solution {
    int recursion(vector<int>& nums, vector<vector<int>>& dp, int l, int r, int lval, int rval){
        if(l > r) return 0;
        if(dp[l][r] != -1) return dp[l][r];

        int ans = -1;
        for(int i = l; i <= r; i++)
            ans = max(ans, nums[i] * lval * rval + recursion(nums, dp, l, i - 1, lval, nums[i]) + recursion(nums, dp, i + 1, r, nums[i], rval));
        return dp[l][r] = ans;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return recursion(nums, dp, 0, n - 1, 1, 1);
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "nums = ";
        cin >> s;
        auto nums = parse_(s);

        cout << solution.maxCoins(nums) << endl;
    }
    
    return 0;
}