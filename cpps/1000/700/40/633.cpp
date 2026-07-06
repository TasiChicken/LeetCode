#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c < 2) return true;
        
        long long l = 0, r = sqrt(c);

        while(l < r){
            if(l * l + r * r == c) return true;
            if(l * l + r * r > c) r--;
            else l++;
        }
        
        return l * l + r * r == c;
    }
};

int main() {
    while(true) {
        Solution solution;
        int c;
        cin >> c;

        cout << solution.judgeSquareSum(c) << endl;
    }
    
    return 0;
}