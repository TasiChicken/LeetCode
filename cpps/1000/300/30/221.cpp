#include <iostream>
#include <vector>

using namespace std;

vector<char> parse_(string s){
    vector<char> v;
    int last = 1;
    for(int i = 2; i < s.length(); i++)
        if(s[i] == ',' || s[i] == ']') {
            v.push_back(s[last + 1]);
            last = i + 1;
        }
    return v;
}

vector<vector<char>> parse(string s){
    vector<vector<char>> v;
    int last;
    for(int i = 1; i < s.length() - 1; i++)
        if(s[i] == '[') last = i;
        else if(s[i] == ']') v.push_back(parse_(s.substr(last, i - last + 1)));
    return v;
}

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0, m = matrix.size();
        if(!m) return 0;
        int n = matrix[0].size(), last = 0;
        vector<int> dp(n);

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(matrix[i][j] == '0') dp[j] = 0;
                else if(!i || !j) last = dp[j], ans = max(ans, dp[j] = 1);
                else {
                    int temp  = min(min(last, dp[j - 1]), dp[j]) + 1;
                    last = dp[j];
                    ans = max(ans, dp[j] = temp);
                }
        return ans * ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "matrix = ";
        cin >> s;
        auto matrix = parse(s);
        cout << solution.maximalSquare(matrix) << endl;
    }
    
    return 0;
}