#include <iostream>

using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        long long digits = 1, mask = 1;
        while(n > 9 * digits * mask){
            n -= 9 * digits * mask;
            digits++;
            mask *= 10;
        }

        int num = mask + --n / digits;
        for(int i = 0; i < n % digits; i++)
            mask /= 10;
        return num / mask % 10;
    }
};

int main() {
    while(true) {
        Solution solution;
        int n;
        cout << "n = ";
        cin >> n;

        cout << solution.findNthDigit(n) << endl;
    }
    
    return 0;
}