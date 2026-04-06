#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<vector<vector<int>>> mp;
    const int mod = 1e9 + 7;
    int dp(int m, int n, int r, int c, int remainMove) {
        if(r < 0 || c < 0 || r >= m || c >= n || remainMove < 0) return 0;
        if(mp[r][c][remainMove] != -1) return mp[r][c][remainMove];

        if(remainMove == 0) 
            return mp[r][c][remainMove] = 
                (r == 0) + 
                (c == 0) + 
                (r == m - 1) + 
                (c == n - 1);

        mp[r][c][remainMove] = (((dp(m, n, r + 1, c, remainMove - 1) % mod + 
            dp(m, n, r - 1, c, remainMove - 1) % mod) % mod + 
            dp(m, n, r, c + 1, remainMove - 1) % mod) % mod + 
            dp(m, n, r, c - 1, remainMove - 1) % mod) % mod;

        return mp[r][c][remainMove]; 
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        mp = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(maxMove, -1)));

        int res = 0;
        for(int i = 0; i < maxMove; i++)
            res = (res + dp(m, n, startRow, startColumn, i)) % mod;
        return res;
    }
};

int main() {
    while(true) {
        Solution solution;
        int m;
        int n;
        int maxMove;
        int startRow;
        int startColumn;
        cin >> m >> n >> maxMove >> startRow >> startColumn;

        cout << solution.findPaths(m, n, maxMove, startRow, startColumn) << endl;
    }
    
    return 0;
}