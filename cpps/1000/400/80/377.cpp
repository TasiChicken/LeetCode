#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

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
    int get_combination(int target, vector<int>& dp, vector<int>& nums){
        if(target < 0) return 0;
        if(dp[target] >= 0) return dp[target];

        dp[target] = 0;
        for(int num : nums)
            dp[target] += get_combination(target - num, dp, nums);
        
        return dp[target];
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        dp[0] = 1;
        return get_combination(target, dp, nums);
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "nums = ";
        cin >> s;
        auto nums = parse_(s);
        int target;
        cout << "target = ";
        cin >> target;

        cout << solution.combinationSum4(nums, target) << endl;
    }
    
    return 0;
}