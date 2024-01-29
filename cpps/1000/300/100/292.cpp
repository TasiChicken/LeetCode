#include <iostream>

using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        return n % 4;
    }
};

int main() {
    while(true) {
        Solution solution;
        int n;
        cout << "n = ";
        cin >> n;

        cout << solution.canWinNim(n) << endl;
    }
    
    return 0;
}