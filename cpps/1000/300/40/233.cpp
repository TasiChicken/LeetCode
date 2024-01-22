#include <iostream>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        long long int mask = 1;
        int ans = 0;
        while(n >= mask){
            int digit = n % (mask * 10) / mask;
            int left = n / (mask * 10);

            if(digit == 0)
                ans += left * mask;
            else if(digit == 1)
                ans += left * mask + n % (mask) + 1;
            else
                ans += (left + 1) * mask;
            
            mask *= 10;
        }
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        int n;
        cout << "n = ";
        cin >> n;

        cout << solution.countDigitOne(n) << endl;
    }
    
    return 0;
}