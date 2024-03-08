#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && !(n & n - 1) && n & 0x55555555;
    }
};

int main() {
    while(true) {
        Solution solution;
        int n;
        cin >> n;

        cout << solution.isPowerOfFour(n) << endl;
    }
    
    return 0;
}