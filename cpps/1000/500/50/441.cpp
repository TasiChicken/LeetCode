#include <iostream>

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        int l = 1, r = n;
        while(l <= r){
            long long mid = l + r >> 1;
            if((mid + mid * mid) / 2 == n)
                return mid;
            else if((mid + mid * mid) / 2 > n)
                r = mid - 1;
            else l = mid + 1;
        }
        return r;
    }
};

int main() {
    while(true) {
        Solution solution;
        int n;
        cout << "n = ";
        cin >> n;

        cout << solution.arrangeCoins(n) << endl;
    }
    
    return 0;
}