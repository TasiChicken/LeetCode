#include <bits/stdc++.h>

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
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int n : nums) sum += n;

        // change target to the sum of nums
        target = sum - target;
        if(target < 0 || target % 2) return 0;
        target >>= 1;

        unordered_map<int, int> dp = {{0, 1}};
        vector<pair<int, int>> update;
        for(int n : nums){
            update.clear();
            for(auto p : dp)
                if(p.first + n <= target)
                    update.emplace_back(p.first + n, p.second);
            for(auto p : update)
                dp[p.first] += p.second;
        }

        return dp[target];
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "s = ";
        cin >> s;
        auto nums = parse_(s);
        int target;
        cout << "target = ";
        cin >> target;

        cout << solution.findTargetSumWays(nums, target) << endl;
    }
    
    return 0;
}