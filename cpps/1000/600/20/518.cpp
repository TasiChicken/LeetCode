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
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1);
        dp[0] = 1;
        
        for(int coin : coins)
            for(int i = coin; i <= amount; i++)
                dp[i] += dp[i - coin];
        return dp[amount];
    }
};

int main() {
    while(true) {
        Solution solution;
        int amount;
        cout << "amount = ";
        cin >> amount;
        string s;
        cout << "coins = ";
        cin >> s;
        auto coins = parse_(s);

        cout << solution.change(amount, coins) << endl;
    }
    
    return 0;
}