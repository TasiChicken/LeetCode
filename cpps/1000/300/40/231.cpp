#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0) return false;
        if(n == INT_MIN) return true;

        n = abs(n);
        return !(n & (n - 1));
    }
};

int main() {
    while(true) {
        Solution solution;
        int n;
        cout << "n = ";
        cin >> n;

        cout << solution.isPowerOfTwo(n) << endl;
    }
    
    return 0;
}