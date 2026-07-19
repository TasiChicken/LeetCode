#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const auto& pa, const auto& pb) {
            return pa[1] < pb[1];
        });

        int time = pairs[0][1];
        int res = 1;
        
        for(int i = 1; i < pairs.size(); i++)
            if(pairs[i][0] > time)
                time = pairs[i][1], res++;

        return res;
    }
};

int main() {
    while(true) {
        Solution solution;
        //code here
    }
    
    return 0;
}