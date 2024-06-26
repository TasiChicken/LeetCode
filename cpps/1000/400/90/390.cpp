#include <iostream>

using namespace std;

class Solution {
public:
    int lastRemaining(int n) {
        int head = 1, round = 0;
        while(n > 1){
            if(!(round & 1) || n & 1)
                head += 1 << round;
            n >>= 1;
            round++;
        }
        return head;
    }
};

int main() {
    while(true) {
        Solution solution;
        int n;
        cout << "n = ";
        cin >> n;

        cout << solution.lastRemaining(n) << endl;
    }
    
    return 0;
}