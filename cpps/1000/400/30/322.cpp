#include <iostream>
#include <vector>
#include <algorithm>

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
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(int coin : coins)
                if(i >= coin)
                    dp[i] = min(dp[i], dp[i - coin]);
            if(dp[i] != INT_MAX) dp[i]++;
        }

        if(dp[amount] != INT_MAX) return dp[amount];
        return -1;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "coins = ";
        cin >> s;
        auto coins = parse_(s);
        int amount;
        cout << "amount = ";
        cin >> amount;

        cout << solution.coinChange(coins, amount) << endl;
    }
    
    return 0;
}