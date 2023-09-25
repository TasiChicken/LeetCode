#include <iostream>
#include <cstdint>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for(int i = 31; i >= 0; i--){
            ans = ans << 1 | n & 1;
            n >>= 1;
        }
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "n = ";
        cin >> s;
        uint32_t n;
        for(char c : s)
            if(c < '0' || c > '1') break;
            else n = (n << 1) + c - '0';

        cout << solution.reverseBits(n) << endl;
    }
    
    return 0;
}