#include <iostream>

using namespace std;

class Solution {
    int m_pow(int x, int y){
        if(!y) return 1;
        if(y == 1) return x;

        return m_pow(x * x, y >> 1) * (y & 1 ? x : 1);
    }
public:
    int largestPalindrome(int n) {
        if(n == 1) return 9;
        int maxi = m_pow(10, n) - 1;

        for(int j = maxi - 2; j >= 0; j--){
            long long num = j;
            for(int i = 0, shift = 1; i < n; i++, shift *= 10)
                num = num * 10 + (j / shift) % 10;

            for(int i = maxi; num / i <= i; i--)
                if(num % i == 0) return num % 1337;
        }

        return -1;
    }
};

int main() {
    while(true) {
        Solution solution;
        int n;
        cout << "n = ";
        cin >> n;
        cout << solution.largestPalindrome(n) << endl;
    }
    
    return 0;
}