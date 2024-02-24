#include <iostream>
#include <vector>

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

vector<vector<int>> parse(string s){
    vector<vector<int>> v;
    int last;
    for(int i = 1; i < s.length() - 1; i++)
        if(s[i] == '[') last = i;
        else if(s[i] == ']') v.push_back(parse_(s.substr(last, i - last + 1)));
    return v;
}

class Solution {
    int getLen(vector<vector<int>>& dp, vector<vector<int>>& matrix, int x, int y, int m, int n, int last = -1){
        if(x >= m || x < 0 || y >= n || y < 0 || last >= matrix[x][y]) return 0;
        if(dp[x][y]) return dp[x][y];

        dp[x][y] = max(dp[x][y], getLen(dp, matrix, x - 1, y, m, n, matrix[x][y]));
        dp[x][y] = max(dp[x][y], getLen(dp, matrix, x + 1, y, m, n, matrix[x][y]));
        dp[x][y] = max(dp[x][y], getLen(dp, matrix, x, y - 1, m, n, matrix[x][y]));
        dp[x][y] = max(dp[x][y], getLen(dp, matrix, x, y + 1, m, n, matrix[x][y]));

        return ++dp[x][y];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        int ans = 1;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                ans = max(ans, getLen(dp, matrix, i, j, m, n));
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "matrix = ";
        cin >> s;
        auto matrix = parse(s);

        cout << solution.longestIncreasingPath(matrix) << endl;
    }
    
    return 0;
}