#include <iostream>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if(n < 4) return n - 1;
        
        int ans = 1;
        while(n > 4)
            ans *= 3, n -= 3;
        return ans * n;
    }
};

int main() {
    while(true) {
        Solution solution;
        int n;
        cout << "n = ";
        cin >> n;

        cout << solution.integerBreak(n) << endl;
    }
    
    return 0;
}