#include <iostream>

using namespace std;

class Solution {
    int c(int n, int r){
        int ans = 1, div = 2;
        if(n >> 1 > r) r = n - r;

        for(int i = n; i > r; i--){
            int mul = i;
            while(div < n - r && mul % div == 0) mul /= div++;
            ans *= mul;
            while(div < n - r && ans % div == 0) ans /= div++;
        }

        return ans;
    }
public:
    int climbStairs(int n) {
        int ans = 0;
        for(int i = 0; i <= n >> 1; i++) ans += c(n - i, i);
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        int n;
        cout << "n = ";
        cin >> n;
        cout << solution.climbStairs(n) << endl;
    }
    
    return 0;
}