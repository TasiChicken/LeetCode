#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<vector<int>> dp;
    string s;
    int recursion(int l, int r){
        if(l == r) return 1;
        if(l > r) return 0;
        if(!dp[l][r])
            dp[l][r] = (s[l] == s[r]) ? (2 + recursion(l + 1, r - 1)) :
            max(recursion(l + 1, r), recursion(l, r - 1));
        return dp[l][r];
    }
public:
    int longestPalindromeSubseq(string s) {
        dp = vector<vector<int>>(s.size(), vector<int>(s.size()));
        this->s = s;
        return recursion(0, s.size() - 1);
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "s = ";
        cin >> s;
        
        cout << solution.longestPalindromeSubseq(s) << endl;
    }
    
    return 0;
}