#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        if(n >= m) return s == t;
        m -= n - 1;

        vector<unsigned int> dp(m, 1);

        for(int i = 0; i < n; i++){
            dp[0] = dp[0] && s[i] == t[i];
            for(int j = 1; j < m; j++)
                dp[j] = dp[j - 1] + (s[i + j] == t[i] ? dp[j] : 0);
        }
        return dp[m - 1];
    }
};

int main() {
    while(true) {
        Solution solution;
        string s, t;
        cout << "s = ";
        cin >> s;
        cout << "t = ";
        cin >> t;

        cout << solution.numDistinct(s, t) << endl;
    }
    
    return 0;
}