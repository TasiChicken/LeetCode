#include <iostream>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        unsigned int ans = 0, mask = 1 << 31;
        while(mask >>= 1)
            if(right & mask)
                if(left & mask) ans |= mask;
                else break;
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        int left, right;
        cout << "left = ";
        cin >> left;
        cout << "right = ";
        cin >> right;

        cout << solution.rangeBitwiseAnd(left, right) << endl;
    }
    
    return 0;
}