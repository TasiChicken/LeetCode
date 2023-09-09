#include <iostream>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length();
        if(m + n != s3.length()) return false;
        bool dp[n + 1];
        dp[0] = true;
        for(int i = 0; i < n; i++)
            dp[i + 1] = dp[i] && s2[i] == s3[i];

        for(int j = 0; j < m; j++){
            dp[0] = dp[0] && s1[j] == s3[j];
            for(int i = 0; i < n; i++)
                dp[i + 1] = dp[i] && s2[i] == s3[i + j + 1] || dp[i + 1] && s1[j] == s3[i + j + 1];
        }
        return dp[n];
    }
};

int main() {
    while(true) {
        Solution solution;
        string s1, s2, s3;
        cout << "s1 = ";
        cin >> s1;
        cout << "s2 = ";
        cin >> s2;
        cout << "s3 = ";
        cin >> s3;
        
        cout << solution.isInterleave(s1, s2, s3) << endl;
    }
    
    return 0;
}