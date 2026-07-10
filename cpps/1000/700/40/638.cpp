#include <bits/stdc++.h>

using namespace std;

class Solution {
    #define MAXNEED 11
    int hash(vector<int>& needs){
        int h = 0;
        for(int i = 0; i < needs.size(); i++)
            h = h * MAXNEED + needs[i];

        return h;
    }
    int dfs(unordered_map<int, int>& dp, vector<int>& price, vector<vector<int>>& special, vector<int>& pos, vector<int>& needs){
        int h = hash(needs);
        
        if(dp.find(h) != dp.end()) 
            return dp[h];

        int ori = 0;
        for(int i = 0 ; i < price.size(); i++)
            ori += price[i] * needs[i];
        dp[h] = ori;

        for(int p : pos){
            bool ok = true;
            for(int i = 0; i < needs.size(); i++){
                if(needs[i] < special[p][i]){
                    for(int j = 0; j < i; j++)
                        needs[j] += special[p][j];

                    ok = false;
                    break;
                }

                needs[i] -= special[p][i];
            }
            if(!ok) continue;

            dp[h] = min(dp[h], special[p].back() + dfs(dp, price, special, pos, needs));

            for(int i = 0; i < needs.size(); i++)
                needs[i] += special[p][i];
        }

        return dp[h];
    }
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        vector<int> pos;

        for(int i = 0; i < special.size(); i++){
            int ori = 0;
            for(int j = 0 ; j < price.size(); j++)
                ori += price[j] * special[i][j];
            
            if(ori > special[i].back())
                pos.emplace_back(i);
        }

        unordered_map<int, int> dp;

        return dfs(dp, price, special, pos, needs);
    }
};

int main() {
    while(true) {
        Solution solution;
        //code here
    }
    
    return 0;
}