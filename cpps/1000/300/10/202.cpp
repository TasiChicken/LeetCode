#include <iostream>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        if(n == 4) return false;
        if(n <= 1) return n;

        int next = 0;
        while(n) next += (n % 10) * (n % 10), n /= 10;
        return isHappy(next);
    }
};

int main() {
    while(true) {
        Solution solution;
        int n;
        cout << "n = ";
        cin >> n;

        cout << solution.isHappy(n) << endl;
    }
    
    return 0;
}