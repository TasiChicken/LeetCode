#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> ps;
public:
    Solution(vector<int>& w) {
        ps = w;
        for(int i = 1; i < w.size(); i++)
            ps[i] += ps[i - 1];
    }
    
    int pickIndex() {
        int num = rand() % ps.back();
        int l = 0, r = ps.size() - 1, mid;
        while(l < r){
            mid = l + r >> 1;
            if(num < ps[mid]) r = mid;
            else l = mid + 1;
        }
        return l;    
    }
};