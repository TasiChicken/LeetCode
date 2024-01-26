#include <iostream>

using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        if(n < 1) return false;

        for(int i = 5; i > 1; i--)
            while(!(n % i)) n /= i;
            
        return n == 1;
    }
};

int main() {
    while(true) {
        Solution solution;
        int n;
        cout << "n = ";
        cin >> n;
        cout << solution.isUgly(n) << endl;
    }
    
    return 0;
}