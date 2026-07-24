#include <bits/stdc++.h>

using namespace std;

class Solution {
    int dfs(vector<int>& dp, int n, int num){
        if(dp[num - 1] != -1) return dp[num - 1];

        for(int i = num - 1; i > 0; i--){
            if(num % i) continue;

            if(dp[num - 1] == -1) dp[num - 1] = num / i + dfs(dp, n, i);
            else dp[num - 1] = min(dp[num - 1], num / i + dfs(dp, n, i));
        }

        return dp[num - 1];
    }
public:
    int minSteps(int n) {
        vector<int> dp(n, -1);
        dp[0] = 0;
        
        return dfs(dp, n, n);
    }
};

int main() {
    while(true) {
        Solution solution;
        int n;
        cin >> n;

        cout << solution.minSteps(n) << endl;
    }
    
    return 0;
}