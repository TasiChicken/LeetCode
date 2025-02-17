#include <bits/stdc++.h>

using namespace std;

class Solution {
    int ans, used, n;
    void dfs(int idx = 1){
        if(idx > n){
            ans++;
            return;
        }

        for(int i = 1; i <= n; i++){
            if(i % idx && idx % i) continue;
            int mask = 1 << (i - 1);
            if(used & mask) continue;
            used ^= mask;
            dfs(idx + 1);
            used ^= mask;
        }
    }
public:
    int countArrangement(int n) {
        this->n = n;
        ans = used = 0;
        dfs();
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        int n;
        cout << "n = ";
        cin >> n;
        cout << solution.countArrangement(n) << endl;
    }
    
    return 0;
}