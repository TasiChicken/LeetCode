#include <iostream>
#include <cstdint>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n){
            if(n & 1) ans++;
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

        cout << solution.hammingWeight(n) << endl;
    }
    
    return 0;
}