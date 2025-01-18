#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        vector<int> sum(1);
        // dp[i][j] stands for idx i to j, the min score p2 can get
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size()));

        for(int i = 0; i < nums.size(); i++){
            sum.push_back(sum.back() + nums[i]);
            
            for(int j = i - 1; j >= 0; j--)
                dp[j][i] = sum[i + 1] - sum[j] - max(nums[j] + dp[j + 1][i], nums[i] + dp[j][i - 1]);
        }
        return dp[0][nums.size() - 1] * 2 <= sum.back();
    }
};

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

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "nums = ";
        cin >> s;
        auto nums = parse_(s);
        
        cout << solution.predictTheWinner(nums) << endl;
    }
    
    return 0;
}