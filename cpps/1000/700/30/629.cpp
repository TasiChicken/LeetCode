#include <bits/stdc++.h>

using namespace std;

class Solution {
#define ll long long
#define mod ((ll)(1e9+7))
public:
    int kInversePairs(int n, int k) {
        int s = n*(n-1)/2;
        if(k > s) return 0;
        k = min(k, s - k);

        vector<ll> prev(k + 1), cur(k + 1);
        prev[0] = 1;
        for(int i = 1; i < n; i++){
            for(int j = 0; j <= k; j++){
                cur[j] = prev[j];

                if(j - 1 >= 0) cur[j] = (cur[j] + cur[j - 1]) % mod;
                if(j - i - 1 >= 0) cur[j] = (cur[j] - prev[j - i - 1]) % mod;
            }

            prev = cur;
        }
        
        return (prev[k] + mod) % mod;
    }
};

int main() {
    while(true) {
        Solution solution;
        int n, k;
        cin >> n >> k;

        cout << solution.kInversePairs(n, k) << endl;
    }
    
    return 0;
}