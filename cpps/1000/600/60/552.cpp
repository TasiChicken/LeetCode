#include <bits/stdc++.h>

using namespace std;

#define mod (1000000007)

// n - 1, a, cl
int dp[100000][2][3], maxn = 0;

class Solution {
public:
    int checkRecord(int n) {
        n--;
        
        if(maxn == 0){
            dp[0][0][0] = 1;
            dp[0][0][1] = 1;
            dp[0][1][0] = 1;
        }

        while(maxn < n){
            for(int i = 0; i < 2; i++)
                for(int j = 1; j < 3; j++)
                    dp[maxn + 1][i][j] = dp[maxn][i][j - 1];
            
            for(int i = 0; i < 3; i++)
                dp[maxn + 1][0][0] = (dp[maxn + 1][0][0] + dp[maxn][0][i]) % mod;

            for(int i = 0; i < 2; i++)
                for(int j = 0; j < 3; j++)
                    dp[maxn + 1][1][0] = (dp[maxn + 1][1][0] + dp[maxn][i][j]) % mod;

            maxn++;
        }

        int num = 0;
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 3; j++)
                num = (num + dp[n][i][j]) % mod;
        return num;
    }
};

int main() {
    while(true) {
        Solution solution;
        int n;
        cout << "n = ";
        cin >> n;

        cout << solution.checkRecord(n) << endl;
    }
    
    return 0;
}