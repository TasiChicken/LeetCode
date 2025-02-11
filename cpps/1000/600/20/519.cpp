#include <bits/stdc++.h>

using namespace std;

class Solution {
    int m, n, total;
    unordered_map<int, int> mp;
    public:
        Solution(int m, int n) {
            this->m = m, this->n = n;
            reset();
        }
        
        vector<int> flip() {
            int r = rand() % total;
            int ans = mp.find(r) == mp.end() ? r : mp[r];
            
            --total;
            mp[r] = mp.find(total) == mp.end() ? total : mp[total];
            return {ans / m, ans % m};
        }
        
        void reset() {
            total = m * n;
            mp.clear();
        }
};
    