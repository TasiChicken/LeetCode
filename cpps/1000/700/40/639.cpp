#include <bits/stdc++.h>

using namespace std;

class Solution {
    #define MOD ((int)(1e9+7))
    #define ll long long
    int _1(const string& s, int idx){
        if(idx >= s.size() - 1 || (s[idx] != '*' && s[idx] != '1')) return 0;
        return (s[idx + 1] == '*') ? 9 : 1;
    }
    int _2(const string& s, int idx){
        if(idx >= s.size() - 1 || (s[idx] != '*' && s[idx] != '2')) return 0;
        if(s[idx + 1] == '*') return 6;
        if(s[idx + 1] >= '7') return 0;
        return 1;
    }

    ll dfs(vector<ll>& dp, const string& s, int idx){
        if(idx >= s.size()) return 1;
        if(s[idx] == '0') return 0;
        if(dp[idx] != -1) return dp[idx];

        return dp[idx] = 
            ((s[idx] == '*' ? 9 : 1) * dfs(dp, s, idx + 1) + 
            (_1(s, idx) + _2(s, idx)) * dfs(dp, s, idx + 2)) % MOD;
    }
public:
    int numDecodings(const string& s) {
        vector<ll> dp(s.size(), -1);
        return dfs(dp, s, 0);
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cin >> s;
        s = s.substr(1, s.size() - 2);

        cout << solution.numDecodings(s) << endl;
    }
    
    return 0;
}