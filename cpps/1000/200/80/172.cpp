#include <iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        while(n) ans += n /= 5;
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        int n;
        cout << "n = ";
        cin >> n;

        cout << solution.trailingZeroes(n) << endl;
    }
    
    return 0;
}