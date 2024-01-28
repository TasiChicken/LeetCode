#include <iostream>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int dp[n + 1];
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            dp[i] = INT_MAX;
            for(int j = 1; i >= j * j; j++)
                dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
        return dp[n];
    }
};

int main() {
    while(true) {
        Solution solution;
        int n;
        cout << "n = ";
        cin >> n;

        cout << solution.numSquares(n) << endl;
    }
    
    return 0;
}