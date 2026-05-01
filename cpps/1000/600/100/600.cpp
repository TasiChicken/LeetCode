#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findIntegers(int n) {
        int lim0[32], lim1[32], unlim0[32], unlim1[32];
        lim1[0] = n & 1;
        lim0[0] = unlim0[0] = unlim1[0] = 1;

        for(int i = 1; i < 32; i++){
            if((1 << i) > n)
                return unlim0[i - 1] + lim1[i - 1];

            unlim1[i] = unlim0[i - 1];
            unlim0[i] = unlim0[i - 1] + unlim1[i - 1];

            if((1 << i) & n){
                lim1[i] = lim0[i - 1];
                lim0[i] = unlim0[i]; 
            }
            else{
                lim1[i] = 0;
                lim0[i] = lim0[i - 1];

                if((1 << i - 1) & n)
                    lim0[i] += lim1[i - 1]; 
            }
        }

        return unlim0[31] + lim1[31];
    }
};

int main() {
    while(true) {
        Solution solution;
        int n;
        cin >> n;

        cout << solution.findIntegers(n) << endl;
    }
    
    return 0;
}