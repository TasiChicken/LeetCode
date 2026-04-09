#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<vector<int>> dp;
    string word1;
    string word2;
    int b_search(vector<int>& arr, int equal_greater){
        if(arr.empty()) return -1;
        if(arr[0] >= equal_greater) return arr[0];
        if(arr.back() < equal_greater) return -1;

        int l = 1, r = arr.size() - 1;
        while(l < r){
            int mid = l + r >> 1;
            if(arr[mid] >= equal_greater) r = mid;
            else l = mid + 1;
        }
        return arr[l];
    }
    int dfs(int i1, int i2){
        if(i1 == word1.size()) return word2.size() - i2;
        if(i2 == word2.size()) return word1.size() - i1;

        if(dp[i1][i2] != -1) return dp[i1][i2];

        if(word1[i1] == word2[i2]) return dp[i1][i2] = dfs(i1 + 1, i2 + 1);
        return dp[i1][i2] = 1 + min(dfs(i1 + 1, i2), dfs(i1, i2 + 1));
    }
public:
    int minDistance(string word1, string word2) {
        dp = vector<vector<int>>(word1.size(), vector<int>(word2.size(), -1));

        this->word1 = word1;
        this->word2 = word2;

        return dfs(0, 0);
    }
};

int main() {
    while(true) {
        Solution solution;
        string word1;
        string word2;
        cin >> word1 >> word2;

        cout << solution.minDistance(word1, word2) << endl;
    }
    
    return 0;
}